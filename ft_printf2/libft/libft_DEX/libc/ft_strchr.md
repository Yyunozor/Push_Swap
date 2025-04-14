# **ft_strchr**

---

### **Purpose**:

The `ft_strchr` function locates the first occurrence of the character `c` in the string `s`.

### **Prototype**:

```c
char *ft_strchr(const char *s, int c);

```

- **Input**:
    - `s`: The string to search.
    - `c`: The character to find (converted to `char`).
- **Output**: Returns a pointer to the first occurrence of `c` in `s`, or `NULL` if `c` is not found.

---

### **Code Implementation**:

```c
har	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s)
	{
		if (*s == uc)
			return ((char *)s);
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return (NULL);
}

```

---

### **Explanation**:

- The function scans the string `s` for the first occurrence of the character `c`.
- If the character is found, it returns a pointer to its location in the string.
- If `c` is not found, the function returns `NULL`.

---

### **Visual Focus**

We are searching for the character `'o'` in the string `"Hello World!"`.

### **Before `ft_strchr` Execution**

- **String (`s`)**: `"Hello World!"`
- **Character to search (`c`)**: `'o'`

Here’s the layout before the function runs:

```jsx
String:      [ H | e | l | l | o |   | W | o | r | l | d | !  ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11 ]

```

---

### **After `ft_strchr` Execution**

The function will scan the string and return a pointer to the first occurrence of `'o'` at index `4`.

```jsx
String:      [ H | e | l | l | o |   | W | o | r | l | d | !  ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11 ]
                               ^
                        First 'o' found at index 4

```

---

### **Step-by-Step Breakdown**:

1. **Index 0**: `'H'` does not match `'o'`.
2. **Index 1**: `'e'` does not match `'o'`.
3. **Index 2**: `'l'` does not match `'o'`.
4. **Index 3**: `'l'` does not match `'o'`.
5. **Index 4**: **`'o'` matches**! → Return pointer to `s[4]`.

---

### **Final State**:

- The function returns a pointer to the first occurrence of `'o'` at index `4`.
- If no match is found, the function would return `NULL`.

---

### **Conclusion**

This optimized version of `ft_strchr`:

- **Efficiently scans** for the first occurrence of a character in a string.
- **Returns a pointer** to the character in the string or `NULL` if the character is not found.
- Ensures safety and efficiency when searching strings for specific characters.

---