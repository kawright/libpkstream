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