# **`ft_get_sign`**

### **Purpose**:

The `ft_get_sign` function is responsible for determining the sign of a number in a string. It skips over any leading whitespace characters, then checks for the presence of a `+` or `-` sign. If a `-` is found, the sign is set to negative (`-1`), and for a `+` or no sign, it defaults to positive (`+1`). The function also advances the string pointer accordingly.

---

### **Prototype**:

```c
int ft_get_sign(const char **str);

```

- **Parameters**:
    - `str`: A pointer to a string pointer. The function will modify this pointer to skip leading whitespace and the sign characters (`+`, ``).
- **Return Value**:
    - Returns `1` if the sign is positive.
    - Returns `1` if the sign is negative.

---

### **Code Implementation**:

```c
int	ft_get_sign(const char **str)
{
	int	sign;

	sign = 1;
	while (ft_isspace(**str))  // Skip leading whitespaces using ft_isspace
		(*str)++;
	if (**str == '-')  // Detect negative sign
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')  // Skip over positive sign
		(*str)++;
	return (sign);
}

```

---

### **Explanation**:

1. **Whitespace Skipping**:
    - The function uses `ft_isspace` from *Libft* to skip over any leading whitespace characters (such as spaces, tabs, or newlines) before looking for a sign character.
    - The pointer `str` is incremented while the current character is a whitespace.
2. **Detecting the Sign**:
    - Once past any leading whitespace, the function checks if the current character is a `'-'` (negative sign) or a `'+'` (positive sign).
    - If a `'-'` is found, the sign is set to `1` (negative) and the string pointer is incremented to move past the `'-'`character.
    - If a `'+'` is found, the string pointer is incremented, but the sign remains `+1` (positive).
3. **Returning the Sign**:
    - The function returns either `1` or `1` depending on whether the number was preceded by a `+` or `` sign (or no sign, which defaults to `+`).

---

### **Visual Focus**:

Let’s walk through an example where `ft_get_sign` is called on a string.

### **Example 1**: Input String `" -123"`

1. **Initial String**: `" -123"`
    - The function first skips over the leading spaces.
2. **String after Whitespace Removal**: `"-123"`
    - It detects the `'-'` sign and sets the `sign` to `1`.
3. **Final String Pointer**: `"123"`
    - The function advances the string pointer past the `'-'` character and returns `1`.

### **Example 2**: Input String `" +456"`

1. **Initial String**: `" +456"`
    - The function skips the leading spaces.
2. **String after Whitespace Removal**: `"+456"`
    - It detects the `'+'` sign and leaves the `sign` as `+1`.
3. **Final String Pointer**: `"456"`
    - The function advances the pointer and returns `+1`.

---

### **Example Usage**:

Here’s an example of how `ft_get_sign` can be used:

```c
int main()
{
	const char *str1 = "   -12345";
	const char *str2 = "   +6789";
	const char *str3 = "9876";  // No sign present

	int sign1 = ft_get_sign(&str1);  // Should return -1
	int sign2 = ft_get_sign(&str2);  // Should return 1
	int sign3 = ft_get_sign(&str3);  // Should return 1 (default positive)

	printf("Sign1: %d, Number: %s\n", sign1, str1);  // Output: Sign1: -1, Number: 12345
	printf("Sign2: %d, Number: %s\n", sign2, str2);  // Output: Sign2: 1, Number: 6789
	printf("Sign3: %d, Number: %s\n", sign3, str3);  // Output: Sign3: 1, Number: 9876

	return 0;
}

```

In this example:

- **Input**: The function processes strings with leading whitespace and optional signs.
- **Output**: The function returns the correct sign (`1` for negative and `1` for positive) and updates the pointer to the start of the number part of the string.

---

### **Optimizations and Improvements**:

1. **Pointer Arithmetic**:
    - The function uses pointer arithmetic to efficiently advance the string pointer. This minimizes unnecessary indexing operations and avoids creating a copy of the string.
    - By passing a pointer to a pointer, the function updates the string in place, ensuring that it remains efficient with minimal overhead.
2. **Integration with *Libft***:
    - The use of `ft_isspace` ensures consistent and clean handling of whitespace across the project. It leverages an existing *Libft* function rather than manually checking for every possible whitespace character.

---

### **Common Questions**:

1. **What if the string has no sign?**
    - If no sign (`+` or ``) is found, the function defaults to `1` (positive). This is the standard behavior for parsing numbers without a sign.
2. **What happens if the string only contains whitespace?**
    - If the string contains only whitespace, the function will skip all the spaces and stop at the end of the string, leaving the pointer at the terminating null character (`'\0'`).
3. **Can the function handle multiple signs (`++`, `-`)?**
    - The function does not support multiple consecutive signs. It processes only the first `+` or `` it encounters and advances the pointer accordingly.

---

### **Edge Cases**:

- **Empty String**: The function will return a positive sign (`1`) and leave the pointer at the beginning of the string if it's empty.
- **Whitespace Only**: If the string only contains whitespace, the function will skip over all the spaces and stop at the end of the string.
- **No Sign**: If no `+` or `` sign is present, the function defaults to returning a positive sign (`1`).

---

### **Complexity Analysis**:

- **Time Complexity**: O(n), where `n` is the number of leading whitespace characters and the sign. The function iterates over the whitespace and processes the sign in constant time.
- **Space Complexity**: O(1) – The function operates in constant space, only modifying the string pointer and returning an integer.

---

### **Conclusion**:

`ft_get_sign` is a utility function that simplifies the process of handling number signs in strings. By skipping whitespace and detecting a `+` or `-` sign, it ensures that subsequent functions (like `ft_atoi_base`) can accurately parse signed numbers. The use of *Libft* functions ensures consistency and code cleanliness, while pointer arithmetic enhances performance. The function is highly efficient, easy to use, and adaptable to a wide range of string parsing scenarios.

---