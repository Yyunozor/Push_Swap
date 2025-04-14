# **ft_memcmp**

---

### **Purpose**:

The `ft_memcmp` function compares the first `n` bytes of the memory areas `s1` and `s2`.

### **Prototype**:

```c
int ft_memcmp(const void *s1, const void *s2, size_t n);

```

- **Input**:
    - `s1`: The first memory area.
    - `s2`: The second memory area.
    - `n`: The number of bytes to compare.
- **Output**: Returns an integer:
    - `0` if the first `n` bytes of `s1` and `s2` are equal.
    - A value less than `0` if `s1` is less than `s2`.
    - A value greater than `0` if `s1` is greater than `s2`.

---

### **Code Implementation**:

```c
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	while(n--)
	{
		if (*p1++ != *p2++)
			return (*(p1 - 1) - *(p2 - 1));
	}
	return (0);
}

```

---

### **Explanation**:

- The function compares the first `n` bytes of `s1` and `s2`.
- If the bytes differ, it returns the difference between the first differing bytes.
- If the first `n` bytes are the same, it returns `0`.

---

### **Visual Focus**

We are comparing the memory areas `"Hello"` (`s1`) and `"HellX"` (`s2`) for the first 5 bytes.

### **Before `ft_memcmp` Execution**

- **Memory 1 (`s1`)**: `"Hello"`
- **Memory 2 (`s2`)**: `"HellX"`
- **Number of bytes to compare (`n`)**: `5`

Here’s the layout before the function runs:

```jsx
Memory 1:    [ H | e | l | l | o ]
Memory 2:    [ H | e | l | l | X ]
Index:       [ 0 | 1 | 2 | 3 | 4 ]

```

---

### **After `ft_memcmp` Execution**

The function will compare the first 5 bytes, and at index `4`, it will find that `'o'` (in `s1`) differs from `'X'` (in `s2`).

```jsx
Memory 1:    [ H | e | l | l | o ]
Memory 2:    [ H | e | l | l | X ]
Index:       [ 0 | 1 | 2 | 3 | 4 ]
                               ^
                  Difference found at index 4

```

---

### **Step-by-Step Breakdown**:

1. **Index 0**: `'H'` equals `'H'`.
2. **Index 1**: `'e'` equals `'e'`.
3. **Index 2**: `'l'` equals `'l'`.
4. **Index 3**: `'l'` equals `'l'`.
5. **Index 4**: **`'o'` is different from `'X'`**! → Return difference between `'o'` and `'X'`.

---

### **Final State**:

- The first memory area contains `"Hello"`, and the second memory area contains `"HellX"`.
- The first differing byte is found at index `4` where `'o'` (ASCII 111) and `'X'` (ASCII 88) differ, so the function returns `111 - 88 = 23`.

---

### **Conclusion**

This optimized version of `ft_memcmp`:

- **Efficiently compares** memory blocks byte by byte.
- **Returns a non-zero difference** when the first differing byte is found, or `0` if the first `n` bytes are equal.
- Ensures a clear and efficient comparison, making it useful for tasks like string and memory block comparison.

---