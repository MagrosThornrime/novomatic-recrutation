#pragma once
#include <StringValue.hpp>

struct StringConcatenate
{
    StringValue operator()(StringValue& left, StringValue& right) const
    {
        return StringValue(left.value + right.value);
    }
};