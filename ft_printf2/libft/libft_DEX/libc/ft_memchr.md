# **ft_memchr**

---

### **Purpose**:

The `ft_memchr` function searches for the first occurrence of the byte `c` in the first `n` bytes of the memory area `s`.

### **Prototype**:

```c
void *ft_memchr(const void *s, int c, size_t n);

```

- **Input**:
    - `s`: The memory block to search.
    - `c`: The byte to search for.
    - `n`: The number of bytes to search.
- **Output**: Returns a pointer to the first occurrence of `c` in `s`, or `NULL` if `c` is not found within the first `n` bytes.

---

### **Code Implementation**:

```c
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *ptr = (const unsigned char *)s;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}

```

---

### **Explanation**:

- The function scans the first `n` bytes of the memory area pointed to by `s` to find the first occurrence of byte `c`.
- If the byte `c` is found, it returns a pointer to that byte in the memory area.
- If the byte is not found within the first `n` bytes, it returns `NULL`.

---

### **Visual Focus**

We are searching for the byte `'o'` (ASCII 111) in the first 8 bytes of the memory block `"Hello World!"`.

### **Before `ft_memchr` Execution**

- **Memory (`s`)**: `"Hello World!"`
- **Search byte (`c`)**: `'o'` (ASCII 111)
- **Number of bytes to search (`n`)**: `8`

Here’s the layout before the function runs:

```jsx
Memory:      [ H | e | l | l | o |   | W | o | r | l | d | !  ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11 ]

```

---

### **After `ft_memchr` Execution**

The function will search through the first `8` bytes and return a pointer to the first occurrence of `'o'` at index `4`.

```jsx
Memory:      [ H | e | l | l | o |   | W | o | r | l | d | !  ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11 ]
                               ^
                        Found 'o' at index 4

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

- The memory block contains the string `"Hello World!"`, and the first occurrence of `'o'` is found at index `4`.
- The function returns a pointer to `s[4]`.

---

### **Conclusion**

This optimized version of `ft_memchr`:

- **Efficiently searches** for the first occurrence of a byte in a memory block.
- **Returns a pointer** to the found byte or `NULL` if the byte is not found within the first `n` bytes.
- Avoids unnecessary operations by stopping once the target byte is found.

This version ensures both safety and efficiency when searching through memory blocks, following best practices for handling memory scanning.

---