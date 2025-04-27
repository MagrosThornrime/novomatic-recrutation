# Novomatic Recrutation

Each task has its own directory. The first one is in "search_engine", the second in "collisions" and the third in
"binary_operation". Each directory has its own CmakeLists.txt, conanfile.py and README.md files.

## Build requirements

- cmake >= 3.20
- python >= 3.12.3

Also, you should have "conan" python library installed. If you did it just now, firstly create default .conf file:

```bash
conan profile detect
```