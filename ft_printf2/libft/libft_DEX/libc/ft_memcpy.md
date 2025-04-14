# **ft_memcpy**

---

### **Purpose**:

The `ft_memcpy` function copies `n` bytes from a source memory area (`src`) to a destination memory area (`dst`). It does not handle overlapping memory areas; for overlapping cases, `ft_memmove` should be used.

### **Prototype**:

```c
void	*ft_memcpy(void *dst, const void *src, size_t n);

```

- **Input**:
    - `dst`: The destination memory area where the bytes will be copied.
    - `src`: The source memory area from which bytes will be copied.
    - `n`: The number of bytes to copy.
- **Output**: Returns a pointer to the destination memory (`dst`).

---

### **Code Implementation**:

```c
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*p_dst;
	const unsigned char	*p_src;

	p_dst = (unsigned char *)dst;
	p_src = (const unsigned char *)src;  // Source is read-only
	while (n--)
		*p_dst++ = *p_src++;
	return (dst);
}

```

---

### **Explanation**:

- The function copies `n` bytes from the source (`src`) to the destination (`dst`) byte by byte.
- If `n` is `0`, the function does nothing and immediately returns the original `dst` pointer.
- The function uses `unsigned char` pointers to ensure the copy is done byte by byte.

### **Why `const unsigned char` for `p_src`?**

- The use of `const` indicates that the source data will not be modified.
- `unsigned char` ensures a byte-by-byte copy, as it is the smallest addressable unit of memory in C.

---

### **Visual Focus**

Let’s illustrate an example where we copy `5` bytes from one memory area to another.

### **Before `ft_memcpy` Execution**

- **Source (`src`)**: `"Hello"`
- **Destination (`dst`)**: `"....."` (uninitialized memory for 5 bytes)

Here’s the layout before the function runs:

```jsx
Source:      [ H | e | l | l | o ]
Destination: [ . | . | . | . | . ]
Index:       [ 0 | 1 | 2 | 3 | 4 ]

```

---

### **After `ft_memcpy` Execution**

The function copies the content from `src` to `dst`:

```jsx
Source:      [ H | e | l | l | o ]
Destination: [ H | e | l | l | o ]
Index:       [ 0 | 1 | 2 | 3 | 4 ]

```

---

### **Step-by-Step Breakdown**:

1. **Step 1**: Copy `'H'` from `src[0]` to `dst[0]`.
2. **Step 2**: Copy `'e'` from `src[1]` to `dst[1]`.
3. **Step 3**: Copy `'l'` from `src[2]` to `dst[2]`.
4. **Step 4**: Copy `'l'` from `src[3]` to `dst[3]`.
5. **Step 5**: Copy `'o'` from `src[4]` to `dst[4]`.

After these steps, all `5` bytes are copied from `src` to `dst`.

---

### **Final State**:

- The destination memory now contains the copied data from the source.
- If the memory areas overlap, the behavior is undefined, and `ft_memmove` should be used instead.

---

### **Conclusion**

This implementation of `ft_memcpy`:

- **Efficiently copies bytes** from a source to a destination.
- **Does not handle overlapping memory**, making it suitable for non-overlapping cases.
- **Maintains const-correctness** for the source, indicating that the source data is not modified.

---

### **Final Visual Summary**

```jsx
Source:      [ H | e | l | l | o ]
Destination: [ H | e | l | l | o ]
Index:       [ 0 | 1 | 2 | 3 | 4 ]

```

---