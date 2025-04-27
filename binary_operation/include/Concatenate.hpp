#pragma once
#include <Value.hpp>

struct Concatenate
{
    Value operator()(Value& left, Value& right) const
    {
        return Value(left.value + right.value);
    }
};