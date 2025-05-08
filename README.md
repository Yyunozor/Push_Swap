# Push_Swap

A highly efficient sorting program that arranges integers using two stacks with a limited set of operations.

![Push_Swap visualization](https://via.placeholder.com/800x400?text=Push_Swap+Visualization)

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Stack Operations](#stack-operations)
- [Algorithm Overview](#algorithm-overview)
  - [Small Set Sorting](#small-set-sorting)
  - [Medium Set Sorting](#medium-set-sorting)
  - [Large Set Sorting](#large-set-sorting)
- [Performance](#performance)
- [Debugging Tools](#debugging-tools)
- [Project Structure](#project-structure)

## Introduction

Push_Swap is a sorting algorithm project that uses two stacks (Stack A and Stack B) and a limited set of operations to sort a collection of integers. The goal is to sort the integers in Stack A in ascending order using the minimum number of operations.

This project demonstrates skills in:
- Algorithm design and optimization
- Data structure implementation
- Efficient memory management
- Problem-solving with constraints

## Installation

Clone the repository and compile the program:

```bash
git clone <repository-url>
cd push_swap
make
```

This will create the `push_swap` executable.

## Usage

### Basic Usage

```bash
./push_swap <integers>
```

Example:
```bash
./push_swap 5 2 3 1 4
```

Output will be a series of operations (like `ra`, `pb`, `sa`, etc.) that, when applied, will sort the given integers.

### Advanced Usage

You can count the number of operations with:

```bash
./push_swap 5 2 3 1 4 | wc -l
```

To verify that the operations correctly sort the stack:

```bash
./push_swap 5 2 3 1 4 | ./checker_Mac 5 2 3 1 4
```

The checker will output `OK` if the operations correctly sort the stack, and `KO` otherwise.

### Input Formats

The program accepts integers in various formats:
- As separate arguments: `./push_swap 5 2 3 1 4`
- As a string: `./push_swap "5 2 3 1 4"`
- Mixed format: `./push_swap 5 "2 3" 1 4`

## Stack Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of Stack A |
| `sb` | Swap the first two elements of Stack B |
| `ss` | Perform `sa` and `sb` simultaneously |
| `pa` | Push the top element from Stack B to Stack A |
| `pb` | Push the top element from Stack A to Stack B |
| `ra` | Rotate Stack A (move the top element to the bottom) |
| `rb` | Rotate Stack B (move the top element to the bottom) |
| `rr` | Perform `ra` and `rb` simultaneously |
| `rra` | Reverse rotate Stack A (move the bottom element to the top) |
| `rrb` | Reverse rotate Stack B (move the bottom element to the top) |
| `rrr` | Perform `rra` and `rrb` simultaneously |

## Algorithm Overview

The sorting approach varies based on the number of elements to be sorted:

### Small Set Sorting

For 2-5 elements, custom algorithms are used to minimize operations:

- **2 elements**: Simple swap if needed (1 operation)
- **3 elements**: Optimal fixed sequence based on the arrangement (2-3 operations)
- **5 elements**: Extract the minimum values to Stack B and then sort Stack A (up to 12 operations)

### Medium Set Sorting

For 6-100 elements, the algorithm employs a chunking strategy:

1. Divide the input range into chunks
2. Move elements from each chunk to Stack B in order
3. Move elements back to Stack A in the correct final position
4. Optimize by calculating the shortest path for rotations

### Large Set Sorting

For large datasets (100+ elements), the algorithm uses a modified Radix Sort approach:

1. Normalize the input values to start from 0
2. Sort by each bit position (binary radix sort)
3. For each bit position:
   - If the bit is 0, move to Stack B
   - If the bit is 1, keep in Stack A
4. Once all elements are processed for a bit position, move all elements back to Stack A
5. Repeat for each bit position

## Performance

| Input Size | Maximum Operations | Push_Swap Actual |
|------------|-------------------|-----------------|
| 3          | 3                 | 2-3             |
| 5          | 12                | 8-12            |
| 100        | 1500              | ~700            |
| 500        | 11500             | ~5500           |

## Debugging Tools

The project includes a debug directory with tools to help visualize and test the sorting process:

```bash
# Build debug tools
make debug

# Test specific algorithms
./debug/push_swap_debug sort_3
./debug/push_swap_debug sort_5
./debug/push_swap_debug sort_medium
./debug/push_swap_debug sort_large

# Generate random test cases
./debug/push_swap_debug generate
```

For more details on the debugging tools, see the [Debug Documentation](debug/Doc_debug.md).

## Project Structure

```
push_swap/
├── includes/
│   ├── push_swap.h      # Main header with declarations and structures
│   ├── func_comm.h      # Function documentation header
│   └── stack.h          # Stack data structure definitions
├── srcs/
│   ├── main.c           # Entry point, argument handling
│   ├── parsers/         # Input validation and parsing
│   ├── operators/       # Stack operations implementation
│   ├── algos/           # Sorting algorithms
│   └── utils/           # Utility functions
├── ft_printf2/          # Custom printf library
├── debug/               # Debugging and visualization tools
├── Makefile
└── README.md
```

---

© 2025 anpayot | 42 Lausanne
