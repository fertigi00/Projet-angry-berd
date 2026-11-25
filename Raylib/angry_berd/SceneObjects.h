#pragma once
#include "pch.h"
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <utility>
#include <concepts>
#include <type_traits>

struct EntityId
{
    std::size_t index;
    std::uint64_t generation;

    bool operator==(const EntityId&) const = default;
};

class GameEntity
{
public:
    virtual ~GameEntity() = default;
    void draw();

};

template<typename T, std::size_t Capacity>
class ObjectPool
{
private:

    struct Slot
    {
        std::optional<T> object;
        std::uint64_t generation = 1;
    };

    std::array<Slot, Capacity> slots{};

    void increaseGeneration(Slot& slot)
    {
        ++slot.generation;

        if (slot.generation == 0)
            ++slot.generation;
    }

public:

    // CREATE
    template<typename... Args>
    T* create(Args&&... args)
    {
        for (std::size_t i = 0; i < Capacity; ++i)
        {
            Slot& slot = slots[i];

            if (!slot.object)
            {
                slot.object.emplace(
                    std::forward<Args>(args)...
                );

                return EntityId{ i, slot.generation };
            }
        }

        return std::nullopt;
    }

    // GET
    T* get(EntityId id)
    {
        if (id.generation == 0 || id.index >= Capacity)
            return nullptr;

        Slot& slot = slots[id.index];

        if (!slot.object)
            return nullptr;

        if (slot.generation != id.generation)
            return nullptr;

        return &(*slot.object);
    }

    // DESTROY
    bool destroy(EntityId id)
    {
        if (get(id) == nullptr)
            return false;

        Slot& slot = slots[id.index];

        slot.object.reset();
        increaseGeneration(slot);

        return true;
    }

    // FOREACH
    template<typename Function>
    void forEach(Function&& function)
    {
        for (std::size_t i = 0; i < Capacity; ++i)
        {
            Slot& slot = slots[i];

            if (slot.object)
            {
                function(
                    EntityId{ i, slot.generation },
                    *slot.object
                );
            }
        }
    }

    // CLEAR
    void clear()
    {
        for (Slot& slot : slots)
        {
            if (slot.object)
            {
                slot.object.reset();
                increaseGeneration(slot);
            }
        }
    }

    static constexpr std::size_t capacity()
    {
        return Capacity;
    }
};


