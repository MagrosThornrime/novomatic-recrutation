#pragma once

struct StringValue
{
    std::string value;

    static StringValue identity()
    {
        return StringValue("");
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