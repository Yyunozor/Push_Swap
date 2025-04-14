# **ft_substr**

---

### **Purpose**:

The `ft_substr` function extracts a substring from a given string, starting at a specified position and up to a given length.

### **Prototype**:

```c
char	*ft_substr(char const *s, unsigned int start, size_t len);

```

### **Input**:

- `s`: The source string.
- `start`: The starting position of the substring.
- `len`: The maximum length of the substring.

### **Output**:

- Returns a pointer to the newly allocated substring.
- Returns `NULL` if memory allocation fails.

---

### **Code Implementation**:

```c
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	char	*orig_substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	orig_substr = substr;
	while (len--)
		*substr++ = s[start++];
	*substr = '\0';
	return (orig_substr);
}

```

### **Explanation**:

- The function extracts a substring from the string `s` starting at the `start` position and up to `len` characters.
- If `start` is beyond the length of the original string, the function returns an empty string.
- If the length `len` exceeds the remaining length from the `start` position, it is adjusted to the remaining length.
- Memory is allocated for the substring, including space for the null-terminator. If allocation fails, the function returns `NULL`.
- The copying of characters is performed using pointer arithmetic for efficiency.

---

### **Visual Focus**

We are extracting the substring `"World"` from the string `"Hello World!"`, starting at index `6` and with a maximum length of `5`.

```jsx
Source:      [ H | e | l | l | o |   | W | o | r | l | d | !  ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11 ]
                                       ^
                                  Start at index 6

```

### **After `ft_substr` Execution**

The function extracts the substring `"World"`.

```jsx
Source:      [ H | e | l | l | o |   | W | o | r | l | d | !  ]
Substring:   [ W | o | r | l | d | \0 ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5  ]

```

---

### **Final State**:

- The function successfully extracts the substring `"World"` from the original string.
- The resulting string is a newly allocated memory block containing the substring, and it is null-terminated.

---

### **Conclusion**:

This optimized version of `ft_substr`:

- **Efficiently extracts substrings** by handling out-of-bound start positions.
- **Adjusts the length** based on the available remaining characters.
- **Uses pointer arithmetic** for optimal copying.
- **Ensures the result is properly null-terminated** and dynamically allocated.

---