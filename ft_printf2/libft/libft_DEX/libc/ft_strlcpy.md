# **ft_strlcpy**

### **Purpose**:

The `ft_strlcpy` function copies up to `dstsize - 1` characters from the source string `src` to the destination string `dst`, ensuring the destination is null-terminated. It returns the length of `src` whether it was fully copied or not.

### **Prototype**:

```c
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

```

- **Input**:
    - `dst`: The destination buffer where the string is copied.
    - `src`: The source string to copy.
    - `dstsize`: The size of the destination buffer.
- **Output**: Returns the total length of `src` (the length of the string that would have been copied if there were enough space).

---

### **Code Implementation**:

```c
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*src_start = src;
	size_t		copy_len;

	// If destination size is greater than 0, perform copy
	if (dstsize)
	{
		copy_len = dstsize - 1;  // Copy up to dstsize - 1 chars to leave space for null terminator
		while (copy_len && *src)
		{
			*dst++ = *src++;
			copy_len--;
		}
		*dst = '\0';  // Always null-terminate the destination buffer
	}

	// Calculate and return the full length of src, regardless of whether it was truncated
	while (*src)
		src++;

	return (src - src_start);
}

```

---

### **Explanation**:

- The function copies up to `dstsize - 1` characters from `src` to `dst`, ensuring the last byte in `dst` is a null-terminator (if `dstsize` is greater than 0).
- After copying, the function calculates and returns the total length of `src`, even if the destination buffer (`dst`) wasn’t large enough to hold the full string.
- If `dstsize` is `0`, the function simply returns the length of `src` without performing any copying.

---

### **Visual Focus**

Let’s break down the process visually. We'll use an example where we copy the string `"Hello"` into a destination buffer of size `6` (leaving room for the null-terminator).

### **Before `ft_strlcpy` Execution**

- **Source (`src`)**: `"Hello"`
- **Destination (`dst`)**: A buffer with 6 slots.

Here’s the layout before the function runs:

```jsx
Source:      [ H | e | l | l | o | \0 ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5  ]

Destination: [ ? | ? | ? | ? | ? | \0 ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5  ]

```

---

### **After `ft_strlcpy` Execution**

The function will copy characters from `src` to `dst` until `dstsize - 1` characters are copied (5 in this case), and then append the null-terminator (`\0`).

```jsx
Source:      [ H | e | l | l | o | \0 ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5  ]

Destination: [ H | e | l | l | o | \0 ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5  ]
                                   ^
                       Copied and null-terminated

```

---

### **Step-by-Step Breakdown**:

1. **Index 0**: Copy `'H'` from `src[0]` to `dst[0]`.
2. **Index 1**: Copy `'e'` from `src[1]` to `dst[1]`.
3. **Index 2**: Copy `'l'` from `src[2]` to `dst[2]`.
4. **Index 3**: Copy `'l'` from `src[3]` to `dst[3]`.
5. **Index 4**: Copy `'o'` from `src[4]` to `dst[4]`.
6. **Index 5**: Null-terminate the destination string at `dst[5]`.

---

### **Final State**:

- The destination buffer contains `"Hello"`, and it is properly null-terminated.
- The function returns the length of the source string, which is `5` (excluding the null-terminator).

---

### **Conclusion**

This optimized version of `ft_strlcpy`:

- **Efficiently copies characters** from `src` to `dst` while ensuring `dst` is always null-terminated.
- **Returns the length** of the source string, regardless of whether the entire string was copied.
- Avoids unnecessary operations by combining copying and length calculation into one process.

This version ensures both safety and efficiency when copying strings, following the best practices for handling buffer sizes and null-termination.

---
