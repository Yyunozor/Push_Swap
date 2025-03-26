# Push_Swap Project Roadmap

## Overview

This roadmap provides a detailed, step-by-step guide to completing the Push_Swap project at 42 Lausanne within 10 days, dedicating 10 hours daily. The objective is to efficiently sort numbers using two stacks with minimal operations, adhering strictly to the 42 Norm.

---

## Project Requirements

- **Sorting Mechanism:** Utilize two stacks (A and B) to sort integers.
- **Allowed Operations:** `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.
- **Efficiency Goal:** Output the minimal sequence of sorting instructions.
- **Error Handling:** Properly manage errors such as non-integers, duplicates, and out-of-range values.
- **Code Standards:** Ensure compliance with the 42 Norm (no memory leaks, global variables, or segmentation faults).

---

## Daily Roadmap

### Day 1: Setup & Planning

- **Understand Project Scope:**
  - Thoroughly read the project subject to grasp rules and constraints.
- **Select Data Structures:**
  - Choose between arrays and linked lists for stack implementation. Arrays offer faster access times, while linked lists provide dynamic sizing.
- **Initialize Development Environment:**
  - Set up a Git repository with an appropriate `.gitignore` file.
  - Create a Makefile to compile the project with `-Wall -Wextra -Werror` flags.

### Day 2: Stack Operations Implementation

- **Develop Core Operations:**
  - Implement all stack operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`) ensuring they function correctly.
- **Edge Case Handling:**
  - Test operations with edge cases, such as empty stacks or stacks with a single element.

### Day 3: Input Parsing & Error Management

- **Argument Parsing:**
  - Handle command-line arguments, including cases where numbers are provided as a single string.
- **Validation:**
  - Detect and manage errors like invalid inputs, duplicates, and numbers outside the acceptable range.
- **Stack Initialization:**
  - Populate Stack A with validated input values.

### Day 4: Small Set Sorting (≤5 elements)

- **Implement Efficient Sorting:**
  - Develop optimal sorting algorithms for small datasets:
    - **3 Elements:** Sort using minimal moves (2-3 operations).
    - **4-5 Elements:** Extend logic to handle up to 5 elements efficiently (up to 12 operations).
- **Testing:**
  - Conduct extensive tests to ensure correctness and minimal operation count.

### Days 5–7: Large Set Sorting Strategies

#### Day 5: Radix Sort Implementation

- **Normalization:**
  - Map input numbers to a continuous range starting from zero to simplify sorting.
- **Bitwise Sorting:**
  - Implement Radix Sort using bitwise operations to process numbers digit by digit.
- **Initial Testing:**
  - Test the implementation with smaller datasets to verify correctness.

#### Day 6: Optimization Techniques

- **Operation Minimization:**
  - Combine operations where possible (e.g., use `rr` instead of separate `ra` and `rb`).
- **Efficient Rotations:**
  - Optimize rotations to reduce the total number of operations.
- **Benchmarking:**
  - Compare performance against known standards and refine the algorithm accordingly.

#### Day 7: Advanced Algorithm Integration

- **Turk Algorithm Exploration:**
  - Research and consider implementing the Turk Algorithm, which involves pushing elements to Stack B in a specific order to facilitate efficient sorting upon retrieval.
- **Chunking Method:**
  - Divide the stack into smaller segments or "chunks," sort each chunk individually, and then merge them. This technique can optimize sorting for larger datasets.
- **Testing and Validation:**
  - Apply these algorithms to various datasets to assess performance and correctness.

### Day 8: Bonus Features & Final Refinements

- **Checker Program:**
  - Develop a `checker` program to validate the correctness of the sorting sequence.
- **Memory Management:**
  - Use tools like Valgrind to ensure there are no memory leaks.
- **Code Review:**
  - Conduct a thorough review to ensure adherence to the 42 Norm and optimize code readability.

### Days 9–10: Final Testing & Evaluation Preparation

- **Comprehensive Testing:**
  - Test the program with a wide range of datasets, including edge cases.
- **Performance Analysis:**
  - Analyze the number of operations used and strive for further optimization.
- **Evaluation Readiness:**
  - Prepare for peer evaluation by documenting the code and being ready to explain the implemented algorithms and design choices.

---

## Algorithm Choices & Complexities

- **Small Datasets (≤5 elements):**
  - Utilize custom minimal-move logic tailored to the specific number of elements.
- **Large Datasets (100–500 elements):**
  - Implement Radix Sort for its efficiency and scalability.
  - Explore the Turk Algorithm and Chunking Method as alternative strategies to potentially reduce the number of operations.

| Algorithm      | Time Complexity    | Space Complexity | Usage               |
|----------------|--------------------|------------------|---------------------|
| Custom Logic   | O(1)               | O(1)             | ≤5 elements         |
| Radix Sort     | O(n * k)           | O(n + k)         | 100–500 elements    |
| Turk Algorithm | Varies             | Varies           | Alternative strategy|
| Chunking Method| Varies             | Varies           | Alternative strategy|

---

## Core Concepts

- **Stack Manipulation:**
  - Mastery of stack operations and their combinations is crucial for efficient sorting.
- **Memory Management:**
  - Ensure dynamic memory allocations are handled properly to prevent leaks.
- **Algorithm Optimization:**
  - Focus on reducing the total number of operations through strategic planning and implementation.

---

## Potential Challenges

- **Complex Input Handling:**
  - Managing various input formats and ensuring robust error detection.
- **Operation Sequencing:**
  - Determining the optimal sequence of operations to achieve sorting with minimal moves.
- **Algorithm Selection:**
  - Choosing the most suitable algorithm based on dataset size and characteristics.

**Debugging Tips:**

- **Unit Testing:**
  - Test individual functions and operations to isolate issues.
- **Memory Checks:**
  - Regularly use tools like Valgrind to detect and address memory leaks.
- **Visualization:**
  - Employ visualization tools to understand the behavior of your sorting algorithm.

---

## Useful Resources

- **Valgrind:**
  - Tool for detecting memory leaks and profiling memory usage.
- **Push_Swap Visualizers:**
  - Graphical tools to visualize stack operations and sorting processes.
- **Community Tutorials:**
  - Articles and tutorials on Radix Sort, Turk Algorithm, and other relevant strategies.

---

 
