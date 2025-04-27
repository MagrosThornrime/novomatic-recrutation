#pragma once

struct Value
{
    std::string value;

    static Value identity()
    {
        return Value("");
    }

    template<typename T>
    operator T() const
    {
        std::stringstream ss(value);
        T convertedValue;
        if ( ss >> convertedValue ) return convertedValue;
        throw std::runtime_error("conversion failed");
    }
};