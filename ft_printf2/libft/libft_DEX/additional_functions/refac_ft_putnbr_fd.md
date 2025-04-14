# Refactored `ft_putnbr_fd`

---

### **Purpose**:

The refactored `ft_putnbr_fd` function outputs an integer to a specified file descriptor using other `libft` functions (`ft_itoa` and `ft_putstr_fd`). This refactored version simplifies the code by utilizing the existing functionality for converting integers to strings and writing strings to a file descriptor.

---

### **Prototype**:

```c
void ft_putnbr_fd(int n, int fd);

```

- **Parameters**:
    - `n`: The integer to output.
    - `fd`: The file descriptor where the integer will be written.
- **Return Value**:
    - This function does not return a value.

---

### **Code Implementation**:

```c
void	ft_putnbr_fd(int n, int fd)
{
	char	*num_str;

	num_str = ft_itoa(n);
	if (!num_str)
		return;
	ft_putstr_fd(num_str, fd);
	free(num_str);
}

```

---

### **Explanation**:

1. **Conversion to String**:
    - The integer `n` is converted to a string using `ft_itoa`, which handles all cases (positive, negative, zero).
2. **Writing the String**:
    - The converted string is then output to the specified file descriptor using `ft_putstr_fd`.
3. **Memory Management**:
    - The memory allocated by `ft_itoa` is freed after use to avoid memory leaks.

---

### **Advantages of This Approach**:

1. **Code Reusability**:
    - By using `ft_itoa` and `ft_putstr_fd`, we avoid duplicating code for integer-to-string conversion and string output.
2. **Simplified Code**:
    - The function is concise and leverages existing functionality, making it easy to read and maintain.
3. **Edge Case Handling**:
    - Since `ft_itoa` handles all cases (e.g., negative numbers, zero), the function covers all scenarios.

---

### **Visual Focus**:

```c
ft_putnbr_fd(12345, 1); // Outputs "12345" to stdout
ft_putnbr_fd(-98765, 2); // Outputs "-98765" to stderr
ft_putnbr_fd(0, 1);     // Outputs "0" to stdout

```

---

### **Edge Cases Handled**:

1. **Zero (`0`)**:
    - Outputs `"0"` correctly.
2. **Negative Numbers**:
    - Outputs the negative sign followed by the absolute value of the number.
3. **Memory Allocation Failure**:
    - If `ft_itoa` fails, the function safely returns without further processing.

---

### **Complexity Analysis**:

- **Time Complexity**: O(log(n)), where `n` is the integer. This is due to the integer-to-string conversion in `ft_itoa`.
- **Space Complexity**: O(log(n)), for the dynamically allocated memory used to store the string representation of the integer.

---

### **Possible Improvements**:

1. **Error Handling for `write`**:
    - To make the function more robust, error checking can be added for the `write` operation in `ft_putstr_fd`.

---

### **Common Questions**:

1. **Why use `ft_itoa` instead of manually converting the integer?**
    - Using `ft_itoa` keeps the code clean and reuses existing functionality, making it easier to maintain.
2. **What happens if `ft_itoa` fails?**
    - If `ft_itoa` returns `NULL`, the function does nothing and safely exits.

---