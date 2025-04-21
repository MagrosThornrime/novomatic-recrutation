How to build:
```bash
conan install . --profile conan.conf --output-folder build --build missing
cmake -S . -B build
cmake --build build
```

How to run:
```bash
./build/collisions
```

TODO: make it usable also on windows, test it on both systems