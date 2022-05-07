# `libpkstream` - Peekable Streams

## Contents

### General Information

- [What is `libpkstream`?](#what-is-libpkstream)
- [How do I install `libpkstream`?](#how-do-i-install-libpkstream)
- [Project Manifest](#project-manifest)

---

## What is `libpkstream`?

`libpkstream` is a small C library that provides an implementation of a _peekable stream_ data structure. This structure is a character stream which supports look-ahead operations. I originally wrote this code in service of a lexer for an interpreter I am currently working on, but I decided it was highly reusable, and warrants its own GitHub project repository.

## How do I install `libpkstream`?

There are a couple of ways to use `libpkstream` in your own C project. The first--and easiest--way to include `libpkstream` in your project is simply to add `libpkstream.c` and `libpkstream.h` directly into your project.

If you would instead rather consume `libpkstream` through formal library files, you have a couple of options. You can build the library files yourself, using the included `Makefile` by running the following:

```console
foo@BAR:~/my_projects/libpkstream$ make libraries 
```

This will build both static and linked library files in the `build/lib` directory (it will create this directory if it doesn't already exist).

You can also have the `makefile` install the library files to your `usr/local` directory by running the following for a static library install:

```console
foo@BAR:~/my_projects/libpkstream$ make install-static
```
...or, for a shared library install:

```console
foo@BAR:~/my_projects/libpkstream$ make install-shared
```

You can also uninstall these libraries by running the following:

```console
foo@BAR:~/my_projects/libpkstream$ make uninstall
```

If you really need them, you can also find pre-build library files and header files included with every new release tag on the project's GitHub page.

## Project Manifest

This project consists of the following files and folders:

- `src`: This folder contains all source and header files in the `libpkstream` library.
    - `src/pkstream.c`: Contains the implementation of all public API members of the `libpkstream` library.
    - `src/pkstream.h`: The header file for the `libpkstream` library.
- `tests`: This folder contains test cases that are written in C and can be run using the `runtests.py` script.
    - `src/test_adv_and_iseos.c`: A test case for ensuring `ps_adv` and `is_eos` both work properly.
    - `src/test_getcol.c`: A test case for ensuring `ps_getcol` works correctly.
    - `src/test_getlen.c`: A test case for ensuring `ps_getlen` works correctly.
    - `src/test_getline.c`: A test case for ensuring `ps_getline` works correctly.
    - `src/test_getpos.c`: A test case for ensuring `ps_getpos` works correctly.
    - `src/test_new_and_del.c`: A test case for ensuring `ps_new` and `ps_del` both work properly.
    - `src/test_peek.c`: A test case for ensuring `ps_peek` works correctly.
    - `src/test_pop.c`: A test case for ensuring `ps_pop` works correctly.
    - `src/test_read.c`: A test case for ensuring `ps_read` works correctly.
- `.gitignore`: The project `.gitignore` file. Allows matching files and directories to be omitted from tracking by `git`. Used mostly for build output, configuration and enviroment files, etc.
- `LICENSE`: Contains the text of the license used by this project (MIT).
- `Makefile`: The project `Makefile` file. Defines instructions for building and installing `libpkstream`.
- `README.md`: This README file.
- `runtests.py`: A python script that acts like a test harness for running the tests defined in the `tests` folder.