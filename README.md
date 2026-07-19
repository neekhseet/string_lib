# String Library (C)

Educational implementation of a small string manipulation library written in pure C.

The goal of this project is not to replace the C Standard Library, but to deepen understanding of:

- pointers
- dynamic memory allocation
- string manipulation
- memory safety
- API design
- Test-Driven Development (TDD)

---

## Features

Implemented functions:

- string_len()
- string_copy()
- string_comp()
- string_find_char()
- string_find_char_index()
- string_substr()
- string_concat()
- string_reverse()
- string_starts_with()
- string_ends_with()

---

## Technologies

- C17
- CMake
- Google Test
- GCC / Clang
- Valgrind

---

## Build

```bash
mkdir build
cd build

cmake ..
make
```

---

## Run tests

```bash
ctest
```

or

```bash
./tests
```

---

## Example

```c
char *result = string_concat("Hello, ", "World!");

printf("%s\n", result);

free(result);
```

---

## Learning goals

This project was created to practice:

- manual memory management
- pointer arithmetic
- API design
- writing reusable C libraries
- unit testing
- clean project structure

---

## Future improvements

- string_split()
- string_trim()
- string_replace()
- string_to_upper()
- string_to_lower()
- string_insert()
- string_remove()
- UTF-8 support
