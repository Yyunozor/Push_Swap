# **ft_strtrim**

---

### **Purpose**:

The `ft_strtrim` function trims characters from the beginning and end of a string. It removes any characters found in the specified set from both the start and the end of the string.

### **Prototype**:

```c
char	*ft_strtrim(char const *s1, char const *set);

```

- **Parameters**:
    - `s1`: The input string to be trimmed.
    - `set`: The reference set of characters to trim from `s1`.
- **Return Value**:
    - Returns the newly allocated trimmed string.
    - Returns `NULL` if the memory allocation fails or if the input parameters are invalid.

---

### **Optimized Code Implementation**:

```c
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;

	if (!s1 || !set)
		return (NULL);

	// Move the start pointer to the first character not in the set
	start = (char *)s1;
	while (*start && ft_strchr(set, *start))
		start++;

	// Move the end pointer to the last character not in the set
	end = (char *)s1 + ft_strlen(s1);
	while (end > start && ft_strchr(set, *(end - 1)))
		end--;

	// Allocate memory for the trimmed string
	return (ft_substr(start, 0, end - start));
```

---

### **Explanation**:

1. **Checking for Null Inputs**:
    - If `s1` or `set` is `NULL`, the function returns `NULL` to prevent errors.
2. **Adjusting the Start Pointer**:
    - The `start` pointer is moved forward, skipping over any characters at the beginning of `s1` that are present in `set`.
    - This ensures that the resulting trimmed string will not include leading characters from `set`.
3. **Adjusting the End Pointer**:
    - The `end` pointer is moved backward, skipping over any trailing characters that are present in `set`.
    - The loop stops when the `end` pointer reaches the `start` pointer, indicating that no more characters should be trimmed.
4. **Allocating the Trimmed String**:
    - The function uses `ft_substr` to create a substring starting from the `start` pointer and ending at the `end` pointer.
    - The length of the new string is calculated as `end - start`, ensuring correct memory allocation.
5. **Return the Trimmed String**:
    - The trimmed string is returned. If memory allocation fails, `NULL` is returned.

---

### **Visual Focus**

Let’s use the string `" Hello World! "` and the trim set `" "` (space) as an example.

### **Before Trimming**:

```c
Input String: "  Hello World!  "
Trim Set:     " "
```

### **After Trimming**:

```c
Trimmed String: "Hello World!"
```

- **Start Adjustment**: The first two spaces are skipped, moving the `start` pointer to `'H'`.
- **End Adjustment**: The trailing spaces are skipped, moving the `end` pointer to just after `'!'`.

### **Visual Representation with Pointer Arithmetic**:

```jsx
Original:     [ | | H | e | l | l | o |   | W | o | r | l |  d  | !  |    |    ]
Trim Set:     [ space characters: " " ]
Indexes:      [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 ]
Trimmed:      [ H | e | l | l | o |   | W | o | r | l | d  | !  ]
```

---

### **Conclusion**:

The optimized version of `ft_strtrim` uses pointer arithmetic for more efficient trimming, reducing unnecessary memory operations. It ensures that the trimmed string is correctly allocated and excludes the unwanted characters from both ends.

---