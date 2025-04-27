#pragma once
#include <concepts>
#include <thread>
#include <vector>
#include <future>

template <class T, class Op>
concept IsSupported = requires(T first, T second, Op operation)
{
    { operation(first, second) } -> std::convertible_to<T>;
    { T::identity() } -> std::convertible_to<T>;
};

template <class BinaryOp, class ValueType>
requires IsSupported<ValueType, BinaryOp>
ValueType calculateSequential(int n, ValueType value, const BinaryOp& f){
    ValueType result = ValueType::identity();
    for(int i = 0; i < n; i++){
        result = f(result, value);
    }
    return result;
}


template <class BinaryOp, class ValueType>
requires IsSupported<ValueType, BinaryOp>
ValueType calculate(int n, ValueType value, const BinaryOp& f){

    if(n <= 0){
        throw std::invalid_argument("n must be greater than zero");
    }

    int processor_count = std::thread::hardware_concurrency();
    std::vector<std::future<ValueType>> futures;

    int portionSize = n / processor_count;
    int remainder = n % processor_count;

    for (int i=0; i<processor_count; i++)
    {
        futures.emplace_back(
            std::async(
                std::launch::async,
                    calculateSequential<BinaryOp, ValueType>,
                    portionSize,
                    value,
                    f
            )
        );
    }

    ValueType result = ValueType::identity();
    if(remainder > 0){
       result = calculateSequential(remainder, value, f);
    }
    for (auto& future : futures)
    {
        auto currentValue = future.get();
        result = f(result, currentValue);
    }

    return result;
}