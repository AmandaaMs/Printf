*This project has been created as part of the 42 curriculum by amoura-d <amoura-d@student.42.fr>*

# Custom C Library

## Description

ft_printf is one of the core projects in the 42 curriculum. The goal is to recreate the behavior of the standard C printf() function while gaining a deeper understanding of variadic functions, formatted output, and low-level memory management.

The project consists of implementing a custom version of printf called ft_printf, compiled as a static library named `libftprintf.a`.

Through this project, I learned how formatted output works internally, how variadic arguments are handled in C, and how to build modular and reusable code while respecting the 42 Norm.

## Function Prototype

`int ft_printf(const char *format, ...);`

## Project Structure
.
├── Makefile             # Build rules (all, clean, fclean, re)
├── ft_printf.h          # Core prototypes and static base macros
├── ft_printf.c          # Variadic wrapper and format dispatcher
└── ft_printf_utils.c    # I/O write handlers and recursive converters

### Supported Conversions

| Specifier | Output Type | Example Input | Example Output |
| :---: | :--- | :---: | :---: |
| `%c` | A single character | `'A'` | `A` |
| `%s` | A string of characters | `"42 São Paulo"` | `42 São Paulo` |
| `%p` | A `void *` pointer address in hex | `&var` | `0x7fff5fbff820` |
| `%d` | A decimal (base 10) integer | `-42` | `-42` |
| `%i` | An integer in base 10 | `42` | `42` |
| `%u` | An unsigned decimal integer | `4294967295` | `4294967295` |
| `%x` | A number in hex (base 16) lowercase | `255` | `ff` |
| `%X` | A number in hex (base 16) uppercase | `255` | `FF` |
| `%%` | A literal `%` character | `%%` | `%` |
---

## 🧠 Under the Hood

To keep the codebase lean and strictly compliant with the **42 Norm**, the logic avoids standard repetitive helper functions through two key concepts:

1. **Agnostic Base Engine (`ft_putnbr_base`):** Built to accept an `unsigned long` as its core parameter. This allows a single recursive logic block to safely handle 32-bit unsigned integers (`%u`, `%x`) and 64-bit memory addresses (`%p`) via **implicit upcasting**, eliminating the risk of pointer truncation.
2. **Zero Local Accumulators:** The dispatcher maps types via direct nested returns (`return (ft_char(...))`). The return values bubble up instantly to the main loop counter, keeping the stack frame exceptionally lightweight.

---

## Instructions

### Requirements

* GCC or Clang
* Make
* Linux or macOS

Include the header:

```c
#include "ft_printf.h"
```

Compile your project with the generated library:

```bash
gcc main.c libftprintf.a
```

or

```bash
gcc main.c -L. -lftprintf
```

## 🧪 Comprehensive Test Suite

To run a full diagnostic check on the library, compile the following `main.c`:

```c
#include "ft_printf.h"
#include <limits.h>

int main(void)
{
    int len;
    char *ptr = "42 São Paulo";

    ft_printf("\n==================================================\n");
    ft_printf("           FT_PRINTF - DIAGNOSTIC SUITE             \n");
    ft_printf("==================================================\n\n");

    ft_printf("[1] CHARACTERS & STRINGS:\n");
    ft_printf("    Char        : '%c'\n", 'A');
    ft_printf("    String      : \"%s\"\n", "Don't Panic.");
    ft_printf("    NULL String : \"%s\"\n\n", (char *)NULL);

    ft_printf("[2] INTEGERS (Signed):\n");
    ft_printf("    Positive    : %d\n", 42);
    ft_printf("    Negative    : %i\n", -42);
    ft_printf("    INT_MAX     : %d\n", INT_MAX);
    ft_printf("    INT_MIN     : %d\n\n", INT_MIN);

    ft_printf("[3] UNSIGNED INTEGERS:\n");
    ft_printf("    Zero        : %u\n", 0);
    ft_printf("    UINT_MAX    : %u\n\n", UINT_MAX);

    ft_printf("[4] HEXADECIMALS:\n");
    ft_printf("    Lower (255) : %x\n", 255);
    ft_printf("    Upper (255) : %X\n", 255);
    ft_printf("    Hex Max     : %x\n\n", UINT_MAX);

    ft_printf("[5] POINTERS:\n");
    ft_printf("    Valid Ptr   : %p\n", ptr);
    ft_printf("    NULL Ptr    : %p\n\n", (void *)NULL);

    ft_printf("[6] ESCAPE & RETURN CHECK:\n");
    len = ft_printf("    Evaluation  : 100%%\n");
    ft_printf("    -> [Contract check: the line above wrote %d bytes]\n", len);

    ft_printf("\n==================================================\n\n");
    return (0);
}
```

## Resources
### Documentation

* The C Programming Language — Brian W. Kernighan & Dennis M. Ritchie
* Linux Manual Pages (`man`)
* POSIX Documentation
* GNU C Documentation
* 42 Subject PDF

### References

* https://man7.org/linux/man-pages/
* https://cplusplus.com/
* https://developer.mozilla.org/

### AI Usage

Artificial Intelligence tools were used as learning assistants for:

* Concept clarification
* Documentation support
* Debugging guidance
* Understanding edge cases
* Code review suggestions

All implementations, testing, debugging, and final validation were completed manually by the author.

### 🛠️ Testers 

* Norminette
* PrintfTester - by Tripouille (git@github.com:Tripouille/printfTester.git)
---

## Author

Amanda Moura

42 Login: amoura-d

GitHub: https://github.com/AmandaaMs
