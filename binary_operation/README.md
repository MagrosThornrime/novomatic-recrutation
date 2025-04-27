# Binary operation

Assuming that the binary operation f does not cause any "side effects,"
implement the function calculate so that its result corresponds to applying the function f to the argument value, n times.

```cpp
template <class T, class Op>
concept IsSupported = requires(T first, T second, Op operation)
{
    { operation(first, second) } -> std::convertible_to<T>;
    { T::identity() } -> std::convertible_to<T>;
};

template <class BinaryOp, class ValueType>
requires IsSupported<ValueType, BinaryOp>
ValueType calculate(int n, ValueType value, const BinaryOp& f)
```

For example, for variables `x`, `y`, and `z` (of class `T`) and a function `f`:

```
calculate(3, x, f)
```

should return the same result as calling:

```
f(f(x, x), x)
```

Additionally, we can assume that:

- `f(x, T::identity()) == f(T::identity(), x) == x`
- `f(f(x, y), z) == f(x, f(y, z))`
- f does not cause any "side effects."

## How to build on Linux:
```bash
conan install . --profile linux.conf --output-folder build --build missing
cmake -S . -B build
cmake --build build
```

## How to build on Windows:
```bash
conan install . --profile windows.conf --output-folder build --build missing
cmake -S . -B build
cmake --build build
```

## How to run tests:
```bash
./build/tests
```