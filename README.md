# sample_project

A simple C++ project for the Software Engineering course.

## What the program does

The program takes two integer numbers from the command line and prints their sum.

```bash
./build/main 12 13
```

Output: `25`

If the arguments are wrong, the program prints an error and exits with code 1.

## Project structure

- `include/` — header of the `mymath` library
- `lib/` — code of the `mymath` library
- `src/` — the program (`main.cpp`)
- `tests/` — tests (GoogleTest)
- `bench/` — benchmark (Google Benchmark)
- `Doxyfile` — settings for the documentation (Doxygen)
- `.github/workflows/build.yaml` — CI

## Requirements

- CMake 3.16 or newer
- A C++17 compiler (g++ or clang++)
- Git (CMake downloads GoogleTest and Google Benchmark)
- Doxygen (only for the documentation)

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run tests

```bash
ctest --test-dir build --output-on-failure
```

## Run benchmark

```bash
./build/bench
```

## Build documentation

```bash
doxygen Doxyfile
```

The HTML files are in `build/docs/html`.

## CI

On every push, GitHub Actions does these steps:

1. Builds the project.
2. Runs the tests.
3. Runs the benchmark.
4. Runs the program.
5. Builds the documentation and publishes it to GitHub Pages (only for the `main` branch).
