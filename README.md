# 42_get_next_line

`get_next_line` is a C function that reads one line at a time from a file descriptor, including the trailing newline when present.

## Overview

This repository contains:
- A mandatory implementation (`get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`)
- A bonus implementation with per-file-descriptor state (`get_next_line_bonus.c`, `get_next_line_utils_bonus.c`, `get_next_line_bonus.h`)

Both expose the same API:

```c
char *get_next_line(int fd);
```

## Implemented Features

- Incremental reading using `read(2)` and configurable `BUFFER_SIZE`
- Internal buffering across calls through static storage
- Returns one heap-allocated line per call, including `\n` when available
- Returns `NULL` on EOF or read/allocation failure
- Bonus version keeps independent state per descriptor (`static char *cell[OPEN_MAX]`)

## Concepts & Technical Highlights

- POSIX file descriptor I/O (`read`, `open`, `close`)
- Dynamic memory management (`malloc`, `free`)
- Persistent static state between function calls
- Line extraction + remainder preservation workflow:
  - `ft_read` fills/extends buffered data until newline or EOF
  - `get_one_line` extracts the next line to return
  - `get_new_line` keeps unread remainder for the next call

## Tech Stack

- Language: C
- Standard/POSIX headers used in code: `unistd.h`, `fcntl.h`, `stdlib.h`, `stdio.h`
- Bonus-only header: `limits.h` (for `OPEN_MAX`)

## Project Structure

```text
.
├── get_next_line.c
├── get_next_line.h
├── get_next_line_utils.c
├── get_next_line_bonus.c
├── get_next_line_bonus.h
└── get_next_line_utils_bonus.c
```

## Prerequisites

- C compiler (`cc`)
- POSIX-like environment for file descriptor APIs

## Build

No `Makefile` is present in this repository. Compile by directly linking the source files with your own `main.c`.

Mandatory:

```bash
cc -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl_demo
```

Bonus:

```bash
cc -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus_demo
```

Note: on environments where `OPEN_MAX` is not defined by system headers, the bonus build may require an explicit definition (for example `-D OPEN_MAX=1024`).

## Usage Example

```c
int fd = open("input.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    /* use line */
    free(line);
}
close(fd);
```

## Manual Validation

Since no automated test framework is included, you can validate behavior manually:

1. Compile mandatory or bonus variant with a small `main.c`.
2. Read a file containing multiple lines and verify one line is returned per call.
3. Verify `NULL` is returned after the last line.
4. (Bonus) Alternate calls across multiple file descriptors and confirm each stream keeps its own reading position.

## Cleanup

If you built binaries/objects manually:

```bash
rm -f gnl_demo gnl_bonus_demo *.o
```

## Limitations

- No `Makefile` or automated tests are provided in this repository.
- The non-bonus version uses a single static buffer, so it does not preserve independent state for multiple descriptors.
- The bonus version indexes static storage by `fd` and does not explicitly guard `fd >= OPEN_MAX`.

## Status

Mandatory and bonus source sets are present and implemented in this repository.
