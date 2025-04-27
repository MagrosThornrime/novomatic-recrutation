#include <iostream>

#include "calculate.hpp"
#include <string>
#include <sstream>

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

struct Concatenate
{
    Value operator()(Value& left, Value& right) const
    {
        return Value(left.value + right.value);
    }
};

int main() {
    std::string result = calculate<Concatenate, Value>(1000, Value("a"), Concatenate());
    std::cout << result << std::endl;
}