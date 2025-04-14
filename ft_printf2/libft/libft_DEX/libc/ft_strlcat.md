# **ft_strlcat**

### **Purpose**:

The `ft_strlcat` function appends the `src` string to the `dst` string, ensuring that the resulting string is null-terminated and fits within the specified size (`dstsize`). It appends as much of `src` as possible to `dst` while ensuring `dst` is properly null-terminated.

### **Prototype**:

```c
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

```

- **Input**:
    - `dst`: The destination buffer (with its current content).
    - `src`: The source string to append.
    - `dstsize`: The total size of the destination buffer.
- **Output**: Returns the total length of the string it tried to create (initial length of `dst` plus the length of `src`).

---

### **Code Implementation**:

```c
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len = 0;
	size_t	src_len = 0;
	size_t	i = 0;

	// Calculate the length of the destination string
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;

	// Calculate the length of the source string
	while (src[src_len])
		src_len++;

	// If the destination buffer is too small, return the full length we tried to create
	if (dstsize == 0 || dst_len >= dstsize)
		return (dstsize + src_len);

	// Copy as much of src to dst as possible, leaving space for the null terminator
	while (src[i] && (dst_len + i) < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}

	// Null-terminate the destination string
	dst[dst_len + i] = '\0';

	// Return the total length of the string we tried to create
	return (dst_len + src_len);
}

```

---

### **Explanation**:

- The function appends the string `src` to `dst`, but will not append more than `dstsize - 1` characters to ensure space for the null-terminator.
- If `dstsize` is `0` or if `dst` is already larger than or equal to `dstsize`, the function returns the combined length of `dst`and `src`, but doesn't perform any appending.
- The function ensures the result is null-terminated, even if `src` is truncated to fit.

---

### **Visual Focus**

Let’s break down the process visually. We'll use an example where we append the string `"World!"` to `"Hello "` in a destination buffer of size `12`.

### **Before `ft_strlcat` Execution**

- **Source (`src`)**: `"World!"`
- **Destination (`dst`)**: `"Hello "` (initial content)

Here’s the layout before the function runs:

```jsx
Source:      [ W | o | r | l | d | ! | \0 ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6  ]

Destination: [ H | e | l | l | o |   | ? | ? | ? | ? | ? | \0  ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 ]

```

---

### **After `ft_strlcat` Execution**

The function will append characters from `src` to `dst` until `dstsize - 1` characters are reached (11 in this case, leaving 1 space for the null-terminator).

```jsx
Source:      [ W | o | r | l | d | ! | \0 ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6  ]

Destination: [ H | e | l | l | o |   | W | o | r | l | d | \0  ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 ]
                                                            ^
                                  Null-terminated after appending

```

---

### **Step-by-Step Breakdown**:

1. **Index 0**: `"Hello "` already occupies the first 6 slots of `dst` (from index `0` to `5`).
2. **Index 6**: Copy `'W'` from `src[0]` to `dst[6]`.
3. **Index 7**: Copy `'o'` from `src[1]` to `dst[7]`.
4. **Index 8**: Copy `'r'` from `src[2]` to `dst[8]`.
5. **Index 9**: Copy `'l'` from `src[3]` to `dst[9]`.
6. **Index 10**: Copy `'d'` from `src[4]` to `dst[10]`.
7. **Index 11**: Null-terminate the destination string at `dst[11]`.

---

### **Final State**:

- The destination buffer now contains `"Hello World"`, and it is properly null-terminated.
- The function returns the total length of the combined string (`11`).

---

### **Conclusion**

This optimized version of `ft_strlcat`:

- **Efficiently appends characters** from `src` to `dst` while ensuring `dst` is always null-terminated.
- **Returns the total length** of the string it tried to create, even if the string was truncated due to buffer size.
- Avoids unnecessary operations by properly managing the buffer size and appending only what can fit.

This version ensures both safety and efficiency when appending strings, following the best practices for handling buffer sizes and null-termination.

---
