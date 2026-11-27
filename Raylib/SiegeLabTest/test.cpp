#include "pch.h"
#include "../angry_berd/SceneObjects.h"
#include <gtest/gtest.h>

TEST(PoolTests, CapacityLimit)
{
    // Arrange
    ObjectPool<int, 3> pool;

    // Act
    auto id1 = pool.create(10);
    auto id2 = pool.create(20);
    auto id3 = pool.create(30);
    auto id4 = pool.create(40);

    // Check: First three creations succeeded
    ASSERT_TRUE(id1.has_value());
    ASSERT_TRUE(id2.has_value());
    ASSERT_TRUE(id3.has_value());

    // Check: Fourth creation failed
    EXPECT_FALSE(id4.has_value());

    // Check: IDs are valid
    ASSERT_NE(pool.get(*id1), nullptr);
    ASSERT_NE(pool.get(*id2), nullptr);
    ASSERT_NE(pool.get(*id3), nullptr);

    // Check: Original values are unchanged
    EXPECT_EQ(*pool.get(*id1), 10);
    EXPECT_EQ(*pool.get(*id2), 20);
    EXPECT_EQ(*pool.get(*id3), 30);

    // Check: Exactly 3 live objects
    EXPECT_EQ(pool.liveCount(), 3);
}


TEST(PoolTests, RecycledSlotChangesGeneration)
{
    // Arrange: Create a pool with capacity 1
    ObjectPool<int, 1> pool;

    // Create object A
    auto idA = pool.create(7);

    ASSERT_TRUE(idA.has_value());

    // Save A's generation
    std::uint64_t generationA = idA->generation;

    // Act: Destroy A
    EXPECT_TRUE(pool.destroy(*idA));

    // Create object B
    auto idB = pool.create(42);

    ASSERT_TRUE(idB.has_value());

    // Check: B reuses the same slot
    EXPECT_EQ(idB->index, idA->index);

    // Check: Generation has changed
    EXPECT_NE(idB->generation, generationA);

    // Check: IDs are different
    EXPECT_NE(*idB, *idA);

    // Check: B contains the correct value
    ASSERT_NE(pool.get(*idB), nullptr);
    EXPECT_EQ(*pool.get(*idB), 42);

    // Check: Exactly one live object
    EXPECT_EQ(pool.liveCount(), 1);
}


TEST(PoolTests, StaleHandleRejected)
{
    // Arrange: Create a pool with capacity 1
    ObjectPool<int, 1> pool;

    // Create object A
    auto idA = pool.create(7);

    ASSERT_TRUE(idA.has_value());

    // Destroy object A
    ASSERT_TRUE(pool.destroy(*idA));

    // Create object B afterward
    auto idB = pool.create(42);

    ASSERT_TRUE(idB.has_value());

    // Act: Look up the old ID (A)
    int* oldObject = pool.get(*idA);

    // Check: Old ID must be rejected
    EXPECT_EQ(oldObject, nullptr);

    // Act: Look up the new ID (B)
    int* newObject = pool.get(*idB);

    // Check: New ID must be valid
    ASSERT_NE(newObject, nullptr);

    // Check: B contains 42, never 7
    EXPECT_EQ(*newObject, 42);
    EXPECT_NE(*newObject, 7);
}


TEST(PoolTests, LiveAddressStable)
{
    // Arrange: Create a pool with capacity 3
    ObjectPool<int, 3> pool;

    // Create object A
    auto idA = pool.create(10);

    ASSERT_TRUE(idA.has_value());

    // Record A's original memory address
    int* p = pool.get(*idA);

    ASSERT_NE(p, nullptr);

    // Create objects B and C
    auto idB = pool.create(20);
    auto idC = pool.create(30);

    ASSERT_TRUE(idB.has_value());
    ASSERT_TRUE(idC.has_value());

    // Act: Look up A again
    int* currentAddress = pool.get(*idA);

    ASSERT_NE(currentAddress, nullptr);

    // Check: A's address has not changed
    EXPECT_EQ(currentAddress, p);

    // Check: A's value is still 10
    EXPECT_EQ(*currentAddress, 10);
}


TEST(PoolTests, ClearInvalidatesHandles)
{
    // Arrange: Create a pool with capacity 2
    ObjectPool<int, 2> pool;

    // Create objects A and B
    auto idA = pool.create(10);
    auto idB = pool.create(20);

    ASSERT_TRUE(idA.has_value());
    ASSERT_TRUE(idB.has_value());

    // Act: Clear the pool
    pool.clear();

    // Check: Old IDs are invalid
    EXPECT_EQ(pool.get(*idA), nullptr);
    EXPECT_EQ(pool.get(*idB), nullptr);

    // Check: Pool is empty
    EXPECT_EQ(pool.liveCount(), 0);

    // Act: Create object C
    auto idC = pool.create(30);

    // Check: Creation succeeded
    ASSERT_TRUE(idC.has_value());

    // Check: C is valid
    ASSERT_NE(pool.get(*idC), nullptr);

    // Check: C contains 30
    EXPECT_EQ(*pool.get(*idC), 30);

    // Check: Exactly one live object
    EXPECT_EQ(pool.liveCount(), 1);
}
