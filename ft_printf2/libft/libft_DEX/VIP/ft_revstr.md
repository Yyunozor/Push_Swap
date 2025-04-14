# **`ft_revstr`**

### **Purpose**:

The `ft_revstr` function reverses a string in place, swapping its characters from the front and the back until the entire string is reversed. This function is typically used when constructing strings in reverse order (like during number-to-string conversions) or for general string manipulation tasks.

---

### **Prototype**:

```c
char	*ft_revstr(char *str, size_t len);

```

- **Parameters**:
    - `str`: A pointer to the string that is to be reversed.
    - `len`: The length of the string (excluding the null terminator).
- **Return Value**:
    - Returns the pointer to the reversed string (`str`).

---

### **Code Implementation**:

```c
char	*ft_revstr(char *str, size_t len)
{
	size_t	i;
	char	tmp;

	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
		i++;
	}
	return (str);
}

```

---

### **Explanation**:

1. **Initialization**:
    - The function starts by initializing an index `i` to `0`. This will be used to traverse the string from the front, while the back of the string is accessed using `len - 1 - i`.
2. **Reversing the String**:
    - The `while` loop runs as long as `i` is less than half the length of the string (`len / 2`), ensuring that each character from the beginning is swapped with the corresponding character from the end.
    - A temporary variable `tmp` is used to hold the value of `str[i]` while the swap occurs, ensuring no data is lost during the swap.
3. **Returning the Reversed String**:
    - Once the entire string has been reversed, the function returns the original pointer to `str`, now containing the reversed string.

---

### **Visual Focus**:

Let’s walk through an example where `ft_revstr` is used to reverse a string.

### **Example**: Reversing the String `"Hello"`

- **Initial String**: `"Hello"`
- **Steps**:
    1. Swap `str[0]` (`'H'`) with `str[4]` (`'o'`), resulting in: `"oellH"`.
    2. Swap `str[1]` (`'e'`) with `str[3]` (`'l'`), resulting in: `"olleH"`.
- **Final Result**: The reversed string is `"olleH"`.

The `ft_revstr` function stops once it reaches the middle of the string (`len / 2`), ensuring that every character has been swapped appropriately.

---

### **Example Usage**:

```c
int main()
{
	char str1[] = "Hello, 42!";
	char str2[] = "ABCDE";

	printf("Original: %s\n", str1);
	ft_revstr(str1, ft_strlen(str1));
	printf("Reversed: %s\n", str1);  // Output: "!24 ,olleH"

	printf("Original: %s\n", str2);
	ft_revstr(str2, ft_strlen(str2));
	printf("Reversed: %s\n", str2);  // Output: "EDCBA"

	return 0;
}

```

In this example:

- **Input**: Two strings are reversed, one with an even length and one with an odd length.
- **Output**: The strings are correctly reversed in place, and the reversed versions are printed.

---

### **Key Points**:

1. **In-Place Reversal**:
    - The function modifies the original string directly, making it an in-place operation with no additional memory allocation.
2. **Use of Pointer Arithmetic**:
    - The function uses simple pointer arithmetic to traverse and swap characters at opposite ends of the string (`str[i]` and `str[len - 1 - i]`).
3. **Efficient**:
    - The function only processes half of the string (stopping at `len / 2`), making it efficient. The time complexity is linear in the length of the string (O(n)).

---

### **Common Questions**:

1. **What happens if the string is empty?**
    - If the string is empty (i.e., `len == 0`), the loop does not run, and the function immediately returns the string as it is.
2. **Does the function handle odd-length strings?**
    - Yes, for strings of odd length, the middle character remains in place, while the characters before and after it are swapped. This ensures a proper reversal.
3. **Is the null terminator included in the reversal?**
    - No, the null terminator (`'\0'`) is not included in the reversal process because the length `len` provided to the function does not account for the null terminator. The function only reverses the characters before the null terminator.

---

### **Edge Cases**:

- **Empty String**: The function handles empty strings gracefully by immediately returning without performing any swaps.
- **Single Character**: A string with only one character remains unchanged after the reversal since there are no other characters to swap.
- **Even and Odd Length Strings**: Both even and odd-length strings are correctly reversed, with odd-length strings leaving the middle character in place.

---

### **Complexity Analysis**:

- **Time Complexity**: O(n), where `n` is the length of the string. The function only processes half of the characters (since each swap affects two characters), but overall the time complexity remains linear.
- **Space Complexity**: O(1) – The function operates in constant space, using only a few variables (`i` and `tmp`), and reverses the string in place.

---

### **Conclusion**:

The **`ft_revstr`** function is an efficient and simple utility to reverse a string in place. It handles a wide range of edge cases (empty strings, odd/even lengths) and is a key tool in tasks like base conversion (where digits are often generated in reverse order). This function operates in linear time and uses constant space, making it a reliable choice for string manipulation.

---