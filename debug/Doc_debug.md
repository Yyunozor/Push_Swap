# Push_swap Debug Tools

This directory contains debugging tools to help test and visualize the sorting algorithms for the push_swap project.

## How to Use

### Building the Debug Tools

You can build the debug tools in two ways:

1. **From the project root:**
   ```
   make debug
   ```

2. **From the debug directory:**
   ```
   cd debug
   make
   ```

### Running Tests

After building, you can run the debug executable to test specific sorting algorithms:

```
./push_swap_debug [test_name]
```

Where `test_name` can be:
- `sort_3` - Test the algorithm for sorting 3 elements
- `sort_5` - Test the algorithm for sorting 5 elements
- `sort_medium` - Test the algorithm for sorting medium sets (6-100 elements)
- `sort_large` - Test the algorithm for sorting large sets (100+ elements)
- `generate` - Generate random test cases

If you run the executable without arguments, it will run all tests:
```
./push_swap_debug
```

### Example Workflow

1. Build the debug tools:
   ```
   make debug
   ```

2. Test just the sort_3 algorithm:
   ```
   ./debug/push_swap_debug sort_3
   ```

3. Test all algorithms:
   ```
   ./debug/push_swap_debug
   ```

4. Generate random test cases:
   ```
   ./debug/push_swap_debug generate
   ```

## Features

- **Stack Visualization**: See the state of stacks before and after sorting
- **Algorithm Testing**: Test individual sorting algorithms with predefined inputs
- **Random Test Generation**: Generate random sets of numbers for testing
- **Validation**: Check if stacks are correctly sorted after operations

## Notes

- The debug tools are separate from the main push_swap program
- Debug builds don't affect the main program's performance
- Use these tools to verify that your sorting algorithms work correctly