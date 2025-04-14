# **ft_strrchr**

---

### **Purpose**:

The `ft_strrchr` function locates the last occurrence of the character `c` in the string `s`.

### **Prototype**:

```c
char *ft_strrchr(const char *s, int c);

```

- **Input**:
    - `s`: The string to search.
    - `c`: The character to find (converted to `char`).
- **Output**: Returns a pointer to the last occurrence of `c` in `s`, or `NULL` if `c` is not found.

---

### **Code Implementation**:

```c
char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

```

---

### **Explanation**:

- The function scans the string `s` and tracks the **last occurrence** of the character `c`.
- It returns a pointer to the **last** match, or `NULL` if no match is found.

---

### **Visual Focus**

We are searching for the **last** occurrence of the character `'o'` in the string `"Hello World!"`.

### **Before `ft_strrchr` Execution**

- **String (`s`)**: `"Hello World!"`
- **Character to search (`c`)**: `'o'`

Here’s the layout before the function runs:

```jsx
String:      [ H | e | l | l | o |   | W | o | r | l | d | !  ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11 ]

```

---

### **After `ft_strrchr` Execution**

The function will scan the string and return a pointer to the **last occurrence** of `'o'` at index `7`.

```jsx
String:      [ H | e | l | l | o |   | W | o | r | l | d | !  ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11 ]
                               ^           ^
                        first 'o'    Last 'o' at index 7

```

---

### **Step-by-Step Breakdown**:

1. **Index 0**: `'H'` does not match `'o'`.
2. **Index 1**: `'e'` does not match `'o'`.
3. **Index 2**: `'l'` does not match `'o'`.
4. **Index 3**: `'l'` does not match `'o'`.
5. **Index 4**: **`'o'` matches**! → Store the position as the last match (`last = 4`).
6. **Index 5**: Space does not match `'o'`.
7. **Index 6**: `'W'` does not match `'o'`.
8. **Index 7**: **`'o'` matches** again! → Update `last = 7`.
9. **Index 8** to **Index 11**: No more matches for `'o'`.

---

### **Final State**:

- The function returns a pointer to the **last occurrence** of `'o'` at index `7`.
- If no match is found, the function would return `NULL`.

---

### **Conclusion**

This optimized version of `ft_strrchr`:

- **Efficiently scans** for the last occurrence of a character in a string.
- **Returns a pointer** to the last occurrence of the character or `NULL` if the character is not found.
- Ensures efficiency in string searches when looking for the last match.

---