# **ft_substr**

---

### **Purpose**:

The `ft_substr` function extracts a substring from a string starting at a given position and up to a specified length.

### **Prototype**:

```c
char	*ft_substr(char const *s, unsigned int start, size_t len);

```

- **Input**:
    - `s`: The source string.
    - `start`: The starting position of the substring.
    - `len`: The maximum length of the substring.
- **Output**: Returns a pointer to the substring, or `NULL` if memory allocation fails.

---

### **Code Implementation**:

```c
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
```

---

### **Explanation**:

- The function extracts a substring from the string `s` starting at `start` and continuing for `len` characters.
- If `start` is beyond the end of the string, it returns an empty string.
- If the requested length exceeds the remaining length of the string, it adjusts `len` to the remaining string length.

---

### **Visual Focus**

We are extracting the substring `"World"` from the string `"Hello World!"`, starting at index `6` and a maximum length of `5`.

### **Before `ft_substr` Execution**

- **Source String (`s`)**: `"Hello World!"`

Here’s the layout before the function runs:

```jsx
Source:      [ H | e | l | l | o |   | W | o | r | l | d | !  ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11 ]
                                       ^
                                  Start at index 6
```

---

### **After `ft_substr` Execution**

The function extracts the substring `"World"` from the source.

```jsx
Source:      [ H | e | l | l | o |    | W | o | r | l | d | ! ]
Substring:   [ W | o | r | l | d | \0 ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5  ]

```

---

### **Final State**:

- The function extracts the substring `"World"`.
- The result is a newly allocated string that contains the substring.

---

### **Conclusion**

This optimized version of `ft_substr`:

- **Safely extracts substrings** by handling out-of-bound start positions.
- **Adjusts length** based on the remaining string content.
- Ensures the substring is properly null-terminated and newly allocated.

---