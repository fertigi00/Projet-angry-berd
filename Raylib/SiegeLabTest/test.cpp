#include "pch.h"
#include "../angry_berd/SceneObjects.h"

//struct TestObject
//{
//    int value;
//
//    TestObject(int v) : value(v) {}
//};
//
//TEST(ObjectPoolTests, CreateAndGet)
//{
//    ObjectPool<TestObject, 5> pool;
//
//    auto id = pool.create(42);
//
//    ASSERT_TRUE(id.has_value());
//
//    TestObject* object = pool.get(*id);
//
//    ASSERT_NE(object, nullptr);
//    EXPECT_EQ(object->value, 42);
//}
//
//TEST(ObjectPoolTests, RejectStaleID)
//{
//    ObjectPool<TestObject, 5> pool;
//
//    auto oldId = pool.create(10);
//
//    ASSERT_TRUE(oldId.has_value());
//
//    EXPECT_TRUE(pool.destroy(*oldId));
//
//    auto newId = pool.create(20);
//
//    ASSERT_TRUE(newId.has_value());
//
//    EXPECT_EQ(oldId->index, newId->index);
//    EXPECT_NE(oldId->generation, newId->generation);
//
//    EXPECT_EQ(pool.get(*oldId), nullptr);
//    EXPECT_NE(pool.get(*newId), nullptr);
//}
//
//TEST(ObjectPoolTests, RejectWhenFull)
//{
//    ObjectPool<TestObject, 2> pool;
//
//    EXPECT_TRUE(pool.create(1).has_value());
//    EXPECT_TRUE(pool.create(2).has_value());
//    EXPECT_FALSE(pool.create(3).has_value());
//}