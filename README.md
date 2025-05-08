# Push_Swap

A highly efficient sorting program that arranges integers using two stacks with a limited set of operations.

<div align="center">
  <img src="https://raw.githubusercontent.com/ayogun/push_swap-visualizer/master/preview.gif" alt="Push_Swap visualization" width="800"/>
</div>

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Stack Operations](#stack-operations)
- [Stack Visualizations](#stack-visualizations)
- [Algorithm Overview](#algorithm-overview)
  - [Small Set Sorting (≤5 elements)](#small-set-sorting-5-elements)
  - [Medium Set Sorting (6-100 elements)](#medium-set-sorting-6-100-elements)
  - [Large Set Sorting (>100 elements)](#large-set-sorting-100-elements)
- [Implementation Details](#implementation-details)
  - [Data Structures](#data-structures)
  - [Algorithm Implementation](#algorithm-implementation)
  - [Edge Cases and Error Handling](#edge-cases-and-error-handling)
  - [Optimization Techniques](#optimization-techniques)
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

## Stack Visualizations

### Understanding Stack Operations Visually

To better understand how these operations work, let's visualize them:

<div align="center">
  <table>
    <tr>
      <th>Initial Stacks</th>
      <th>After Operation</th>
      <th>Operation</th>
    </tr>
    <tr>
      <td>
        <pre>
Stack A:    Stack B:
  3           -
  2           -
  1           -
        </pre>
      </td>
      <td>
        <pre>
Stack A:    Stack B:
  2           -
  3           -
  1           -
        </pre>
      </td>
      <td><code>sa</code> (swap top two elements of A)</td>
    </tr>
    <tr>
      <td>
        <pre>
Stack A:    Stack B:
  3           -
  2           -
  1           -
        </pre>
      </td>
      <td>
        <pre>
Stack A:    Stack B:
  2           3
  1           -
  -           -
        </pre>
      </td>
      <td><code>pb</code> (push from A to B)</td>
    </tr>
    <tr>
      <td>
        <pre>
Stack A:    Stack B:
  3           -
  2           -
  1           -
        </pre>
      </td>
      <td>
        <pre>
Stack A:    Stack B:
  2           -
  1           -
  3           -
        </pre>
      </td>
      <td><code>ra</code> (rotate A upward)</td>
    </tr>
    <tr>
      <td>
        <pre>
Stack A:    Stack B:
  3           -
  2           -
  1           -
        </pre>
      </td>
      <td>
        <pre>
Stack A:    Stack B:
  1           -
  3           -
  2           -
        </pre>
      </td>
      <td><code>rra</code> (rotate A downward)</td>
    </tr>
  </table>
</div>

## Algorithm Overview

### Small Set Sorting (≤5 elements)

For small sets, we use custom-tailored algorithms optimized for the minimum number of operations:

#### 2 Elements

If the elements are in the wrong order, perform a single `sa` operation.

#### 3 Elements

For three elements, there are only 6 possible arrangements, each with an optimal solution:

<div align="center">
  <img src="https://raw.githubusercontent.com/VBrazhnik/Push_swap/master/images/combinations_of_3_elements.png" alt="3 Elements Sorting" width="600"/>
</div>

Example logic:
```
if stack is already sorted:
    do nothing
else if elements are [3,2,1]:
    sa, rra
else if elements are [2,1,3]:
    sa
else if elements are [3,1,2]:
    ra
else if elements are [1,3,2]:
    sa, ra
else if elements are [2,3,1]:
    rra
```

#### 4-5 Elements

For 4-5 elements, we:
1. Find the smallest element(s)
2. Push them to Stack B
3. Sort the remaining elements in Stack A using the 3-element algorithm
4. Push everything back from B to A

<div align="center">
  <pre>
  Initial:             Find smallest:       Push to B:          Sort A (3):        Push back:
  +---+                +---+                +---+                +---+              +---+
  | 4 |                | 4 |                | 4 |                | 3 |              | 1 |
  | 2 |                | 2 |                | 3 |                | 4 |              | 2 |
  | 5 |   -------->    | 5 |   -------->    | 5 |   -------->    | 5 |  -------->   | 3 |
  | 3 |                | 3 |                | - |                | - |              | 4 |
  | 1 |                | 1 |                | - |                | - |              | 5 |
  +---+                +---+                +---+                +---+              +---+
  </pre>
</div>

### Medium Set Sorting (6-100 elements)

For medium-sized sets, we employ a chunking approach:

<div align="center">
  <img src="https://raw.githubusercontent.com/ayogun/push_swap-visualizer/master/chunks.png" alt="Chunking Algorithm" width="700"/>
</div>

1. **Divide numbers into chunks** (e.g., 5 chunks for 100 numbers)
2. **Push chunk by chunk to Stack B** (smallest chunks first)
   - Calculate the shortest rotation path for each element
   - Use either `ra` or `rra` based on which requires fewer operations
3. **Push elements back to Stack A** in descending order
   - Find the largest element in B
   - Calculate the shortest path to bring it to the top
   - Push it to A

<div align="center">
  <pre>
  Chunking Visualization (for 20 numbers split into 4 chunks):
  
  Stack A (Initial)       After pushing chunks to B       Final sorted Stack A
  +-------------+         +-------------+                 +-------------+
  |     12      |         |             |                 |      1      |
  |      3      |         |             |                 |      2      |
  |     16      |         |             |                 |      3      |
  |      8      |         |             |                 |      4      |
  |     19      |         |             |                 |      5      |
  |      4      |-------->|             |---------------->|      6      |
  |     11      |         |             |                 |      7      |
  |     20      |         |             |                 |      8      |
  |      7      |         |             |                 |      9      |
  |     14      |         |             |                 |     10      |
  |     ...     |         |             |                 |     ...     |
  +-------------+         +-------------+                 +-------------+
  
                          Stack B (After chunking)
                          +-------------+
                          |     18      |
                          |      9      |
                          |     15      |
                          |      5      |
                          |     17      |
                          |     13      |
                          |      2      |
                          |     10      |
                          |      6      |
                          |      1      |
                          |     ...     |
                          +-------------+
  </pre>
</div>

### Large Set Sorting (>100 elements)

For large datasets, we implement a modified Radix Sort:

<div align="center">
  <img src="https://raw.githubusercontent.com/ayogun/push_swap-visualizer/master/radix.gif" alt="Radix Sort Visualization" width="700"/>
</div>

1. **Normalize the values** (map them to a continuous range starting from 0)
2. **Sort by binary digits (bits)** from least significant to most significant:
   - For each bit position:
     - If the bit is 0, push to Stack B
     - If the bit is 1, keep in Stack A (rotate it to the bottom)
   - After processing all elements for a bit position, push all elements from Stack B back to Stack A
   - Move to the next bit position

<div align="center">
  <pre>
  Binary Radix Sort Process:
  
  Original numbers (normalized): [5, 2, 9, 1, 7, 3, 8, 6, 0, 4]
  Binary representation:
  5 = 0101
  2 = 0010
  9 = 1001
  ...
  
  Sort by LSB (bit 0):
  +--------------+    +--------------+
  |      5       |    |      2       |
  |      9       |    |      8       |
  |      1       |    |      0       |
  |      7       |    |      4       |
  |      3       |    |              |
  +--------------+    +--------------+
       Stack A             Stack B
  (numbers with 1)    (numbers with 0)
  
  After all bits processed, Stack A will be fully sorted.
  </pre>
</div>

## Implementation Details

### Data Structures

Our implementation uses an array-based stack:

```c
typedef struct s_stack
{
    int *data;  // Array to store stack elements
    int top;    // Index of the top element
    int capacity;  // Maximum capacity of the stack
} t_stack;
```

Key operations:
- `stack_init`: Allocates memory for the stack and initializes it
- `stack_push`: Adds an element to the top of the stack
- `stack_pop`: Removes and returns the top element
- `free_stack`: Frees the memory allocated for the stack

### Algorithm Implementation

#### Small Set Sorting

The small set algorithm is implemented in `sort_small.c` and includes specialized functions:
- `sort_2`: For sorting 2 elements
- `sort_3`: For sorting 3 elements
- `sort_4_5`: For sorting 4-5 elements

The key to small set sorting is to hardcode the optimal moves for each possible arrangement, significantly reducing the number of operations.

#### Medium Set Sorting

Medium set sorting is implemented in `sort_medium.c` and follows these key steps:

1. **Chunk Calculation**:
   ```c
   // Example of calculating chunk ranges
   int chunk_size = total_elements / 5;  // 5 chunks for 100 elements
   int min = chunk * chunk_size;
   int max = (chunk + 1) * chunk_size - 1;
   ```

2. **Finding Optimal Rotation Path**:
   ```c
   // Simplified example
   int ra_moves = position;
   int rra_moves = stack->top - position;
   if (ra_moves <= rra_moves)
       // Use ra operations
   else
       // Use rra operations
   ```

#### Large Set Sorting (Radix Sort)

Our Radix Sort implementation in `sort_large.c` follows these steps:

1. **Normalization**:
   ```c
   // Find min value and subtract from all elements
   int min = find_min(stack_a);
   for (int i = 0; i < stack_a->top; i++)
       stack_a->data[i] -= min;
   ```

2. **Bit-by-Bit Sorting**:
   ```c
   // For each bit position
   for (int bit = 0; bit < max_bits; bit++) {
       for (int i = 0; i < stack_a->top; i++) {
           // Check if bit is set
           if ((stack_a->data[0] >> bit) & 1)
               ra(stack_a);  // Keep in A
           else
               pb(stack_a, stack_b);  // Move to B
       }
       // Move everything back from B to A
       while (stack_b->top > 0)
           pa(stack_a, stack_b);
   }
   ```

### Edge Cases and Error Handling

The program handles several edge cases:

1. **Empty Input**: Returns without performing any operations
2. **Single Element**: Already sorted, so no operations are needed
3. **Invalid Input**:
   - Non-integers
   - Numbers exceeding INT_MAX or INT_MIN
   - Duplicate numbers
   - In all these cases, the program outputs "Error" to stderr
4. **Already Sorted Stack**: The program detects this case and outputs no operations

### Optimization Techniques

Several optimization techniques are employed:

1. **Operation Reduction**:
   - Combine operations where possible (e.g., use `ss` instead of `sa` followed by `sb`)
   - Calculate the shortest path for rotations (forward vs. reverse)

2. **Memory Optimization**:
   - Use arrays instead of linked lists for better cache performance
   - Minimize memory allocations/deallocations

3. **Algorithm Selection**:
   - Choose the optimal algorithm based on input size
   - For small sets, use hardcoded optimal sequences
   - For large sets, use Radix Sort for its efficiency

## Performance

| Input Size | Maximum Operations | Push_Swap Actual |
|------------|-------------------|-----------------|
| 3          | 3                 | 2-3             |
| 5          | 12                | 8-12            |
| 100        | 1500              | ~700            |
| 500        | 11500             | ~5500           |

<div align="center">
  <img src="https://raw.githubusercontent.com/ayogun/push_swap-visualizer/master/performance.png" alt="Performance Chart" width="600"/>
</div>

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

### Stack Visualizer

The `debug/stack_visualizer.c` file provides functions to visualize stacks during sorting:

```c
/**
 * @brief Visualizes both stacks side by side
 * 
 * @param stack_a Stack A
 * @param stack_b Stack B
 */
void visualize_stacks(t_stack *stack_a, t_stack *stack_b)
{
    print_stack(stack_a, 'A');
    print_stack(stack_b, 'B');
    printf("\n");
}
```

Example output:

```
----- Stack A -----
[0] 42 <- top
[1] 12
[2] 9
[3] 31
------------------

----- Stack B -----
[0] 7 <- top
[1] 2
[2] 1
------------------
```

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
