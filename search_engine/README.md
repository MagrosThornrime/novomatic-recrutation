# Search engine
You are the administrator of the search engine szukajka.pl in the year 1997. Your task is to implement a module that displays suggestions based on the user's input.

Basic requirements:

- Ability to add a new query

- The search engine should return the queries most similar to the given input (e.g., the longest prefix match)

Example usage scenario:
(lines starting with > were entered by the user)

```
> add: Kiedy jest nowy rok w Chinach?
> add: Kiedy jest nowy rok w Tajlandii?
> ask: Kiedy jest nowy rok
result: Kiedy jest nowy rok w Chinach?
result: Kiedy jest nowy rok w Tajlandii?
```

## My implementation:
This is a SFML + Dear ImGui Application that imitates a search engine. After each search,
the engine registers your prompt in its Trie structure. From then, when you are typing,
it may show you it as a suggestion (if it matches your current prompt). The engine doesn't care
if a character is in lower case or upper case. Also, you can clear the history.

Attention! The prompt can be only up to 64 characters' long and can't use polish letters.
(It's due to the Application's limitations, not to the Trie structure, e.g. there is a test that uses polish letters)

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

How to run visualizer:
```bash
./build/engine
```

How to run tests:
```bash
./build/tests
```