# Push_Swap: A Comprehensive Guide

This document provides an in-depth explanation of the algorithms, approaches, and implementation details of the Push_Swap project.

## Table of Contents

- [The Problem](#the-problem)
- [Understanding Stack Operations](#understanding-stack-operations)
- [Algorithmic Approaches](#algorithmic-approaches)
  - [Small Set Algorithm (≤5 elements)](#small-set-algorithm-5-elements)
  - [Medium Set Algorithm (6-100 elements)](#medium-set-algorithm-6-100-elements)
  - [Large Set Algorithm (>100 elements)](#large-set-algorithm-100-elements)
- [Data Structures](#data-structures)
- [Algorithm Implementation Details](#algorithm-implementation-details)
- [Edge Cases and Error Handling](#edge-cases-and-error-handling)
- [Optimization Techniques](#optimization-techniques)
- [Testing and Validation](#testing-and-validation)

## The Problem

Push_Swap is a sorting challenge with specific constraints:

1. You have two stacks: Stack A (initially containing all input integers) and Stack B (initially empty)
2. You can only use a limited set of operations:
   - `sa`: swap the top two elements of Stack A
   - `sb`: swap the top two elements of Stack B
   - `ss`: perform `sa` and `sb` simultaneously
   - `pa`: push the top element from Stack B to Stack A
   - `pb`: push the top element from Stack A to Stack B
   - `ra`: rotate Stack A (move the top element to the bottom)
   - `rb`: rotate Stack B (move the top element to the bottom)
   - `rr`: perform `ra` and `rb` simultaneously
   - `rra`: reverse rotate Stack A (move the bottom element to the top)
   - `rrb`: reverse rotate Stack B (move the bottom element to the top)
   - `rrr`: perform `rra` and `rrb` simultaneously

3. The goal is to sort all integers in Stack A in ascending order using the minimum possible number of operations.

## Understanding Stack Operations

To better understand the operations, let's look at their effects on a sample stack:

Given Stack A with elements [3, 2, 1] (top-to-bottom):

- `sa`: Stack A becomes [2, 3, 1]
- `pb`: Moves 3 to Stack B, Stack A becomes [2, 1], Stack B becomes [3]
- `ra`: Stack A becomes [1, 2]
- `rra`: Stack A becomes [2, 1] again

The key insight is that the available operations are deliberately limiting, making the sorting problem more challenging. This necessitates careful algorithm design to minimize the number of operations.

## Algorithmic Approaches

### Small Set Algorithm (≤5 elements)

For small sets, we use custom-tailored algorithms:

**For 2 elements:**
- If the elements are in the wrong order, perform `sa`

**For 3 elements:**
- There are only 6 possible arrangements of 3 elements
- Each arrangement has an optimal sequence of 0-2 moves
- We identify the arrangement and apply the corresponding sequence

Example logic for 3 elements:
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

**For 4-5 elements:**
1. Find the smallest element(s)
2. Push the smallest elements to Stack B
3. Sort the remaining elements in Stack A (using the 3-element algorithm)
4. Push elements from Stack B back to Stack A

### Medium Set Algorithm (6-100 elements)

For medium-sized sets, we use a chunking approach:

1. Divide the numbers into chunks (e.g., 15-20 chunks for 100 numbers)
2. Push elements chunk by chunk to Stack B (smallest chunks first)
3. Determine the optimal rotation direction for each element
4. Push elements back to Stack A in reverse order (largest first)

The key optimization here is calculating the shortest path for rotations. For each element:
1. Calculate the number of moves needed to bring the element to the top using `rb` vs `rrb`
2. Choose the operation that requires fewer moves

### Large Set Algorithm (>100 elements)

For large datasets, we implement a modified Radix Sort:

1. Normalize the values (map them to a continuous range starting from 0)
2. Sort by binary digits (bits) from least significant to most significant

For each bit position:
- If the bit is 0, push to Stack B
- If the bit is 1, keep in Stack A (rotate it to the bottom)
- After processing all elements for a bit position, push all elements from Stack B back to Stack A

This approach works well because:
- The number of operations scales as O(n log n)
- It doesn't require deep stack analysis
- It's relatively simple to implement

## Data Structures

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

## Algorithm Implementation Details

### Small Set Sorting

The small set algorithm is implemented in `sort_small.c` and includes specialized functions:
- `sort_2`: For sorting 2 elements
- `sort_3`: For sorting 3 elements
- `sort_4_5`: For sorting 4-5 elements

The key to small set sorting is to hardcode the optimal moves for each possible arrangement, significantly reducing the number of operations.

### Medium Set Sorting

Medium set sorting is implemented in `sort_medium.c` and follows these key steps:

1. **Chunk Calculation**: 
   - Determine the optimal chunk size based on input size
   - For 100 elements, around 5 chunks works well

2. **Pushing to Stack B**:
   - For each chunk, find all elements in the current chunk range
   - Calculate the shortest path to bring each element to the top of Stack A
   - Push the element to Stack B

3. **Pushing Back to Stack A**:
   - Find the largest element in Stack B
   - Calculate the shortest path to bring it to the top
   - Push it back to Stack A

### Large Set Sorting

Our Radix Sort implementation (in `sort_large.c`) follows these steps:

1. **Normalization**:
   - Find the minimum value in the stack
   - Subtract this value from all elements to ensure all numbers are non-negative
   - This simplifies the bitwise operations

2. **Bit-by-Bit Sorting**:
   - Calculate the maximum number of bits needed (log2 of the largest number)
   - For each bit position (starting from the least significant bit):
     - Examine each number's bit at the current position
     - If the bit is 0, push to Stack B
     - If the bit is 1, rotate to the bottom of Stack A
     - After processing all elements, push everything from Stack B back to Stack A
     - Move to the next bit position

3. **Optimization**:
   - Use counter variables to track stack sizes and reduce redundant checks
   - Combine operations where possible (e.g., use `rr` instead of separate `ra` and `rb`)

## Edge Cases and Error Handling

The program handles several edge cases:

1. **Empty Input**: Returns without performing any operations

2. **Single Element**: Already sorted, so no operations are needed

3. **Invalid Input**:
   - Non-integers
   - Numbers exceeding INT_MAX or INT_MIN
   - Duplicate numbers
   - In all these cases, the program outputs "Error" to stderr

4. **Already Sorted Stack**: The program detects this case and outputs no operations

## Optimization Techniques

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

## Testing and Validation

Testing is crucial for Push_Swap. Our approach includes:

1. **Randomized Testing**:
   - Generate random sets of integers
   - Test with various input sizes (3, 5, 100, 500)
   - Verify the operations produce a sorted stack

2. **Edge Case Testing**:
   - Test with already sorted inputs
   - Test with reverse-sorted inputs
   - Test with all identical values (which should trigger an error)

3. **Performance Benchmarking**:
   - Count the number of operations for different input sizes
   - Compare against the project requirements

The debug directory contains tools to facilitate testing, including stack visualization and test case generation.

---

This guide should help you understand the inner workings of the Push_Swap project. The algorithms described here represent a balance of simplicity, efficiency, and correctness, tailored to meet the specific constraints of the project.

© 2025 anpayot | 42 Lausanne