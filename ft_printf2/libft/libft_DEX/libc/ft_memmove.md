# **ft_memmove**

### **Purpose**:

The `ft_memmove` function copies `len` bytes from the source memory area (`src`) to the destination memory area (`dst`). It safely handles overlapping memory areas by copying in the appropriate direction.

### **Prototype**:

```c
void	*ft_memmove(void *dst, const void *src, size_t len);

```

- **Input**:
    - `dst`: The destination memory area where the bytes will be copied.
    - `src`: The source memory area from which bytes will be copied.
    - `len`: The number of bytes to copy.
- **Output**: Returns a pointer to the destination memory (`dst`).

---

### **Code Implementation**:

```c
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	return (dst);
}

```

---

### **Explanation**:

1. **Checking for Null Pointers**:
    - The function checks if both `dst` and `src` are `NULL` before proceeding to avoid undefined behavior.
2. **Handling Overlap**:
    - The function determines whether to copy forward or backward based on the relative positions of `dst` and `src`.
    - **Forward Copying (`dst < src`)**: If the destination is located before the source, copying proceeds from the beginning to the end.
    - **Backward Copying (`dst > src`)**: If the destination is after the source, copying starts from the end to avoid overwriting the source data.
3. **Using Pointers for Byte-by-Byte Copying**:
    - The pointers are adjusted based on the direction of the copying, either incremented or decremented within the loop.

---

### **Visual Focus**

Let’s illustrate an example where we move a memory block of 5 bytes with overlapping regions.

### **Before `ft_memmove` Execution**

We’ll move the string `"Hello"` within the same memory block but overlapping by 2 bytes.

- **Source (`src`)**: Starting at index `0`
- **Destination (`dst`)**: Overlapping, starting at index `2`

Here’s the layout before the function runs:

```jsx
Memory:      [ H | e | l | l | o | \0 | \0 | \0 ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5  | 6  | 7  ]
Src start:     ^
Dst start:             ^

```

---

### **After `ft_memmove` Execution**

The function will safely move `"Hello"` to the destination, taking care of the overlap.

```jsx
Memory:      [ H | e | H | e | l | l | o | \0 ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7  ]
Dst end:               ^
                       Safely moved, handling overlap

```

---

### **Step-by-Step Breakdown**:

1. **Step 1**: If `dst < src`, copy forward: `'H'`, `'e'`, `'l'`, `'l'`, `'o'`.
2. **Step 2**: If `dst > src`, copy backward: Start from the last byte and copy each byte in reverse order.
3. **Result**: The memory block is moved safely without any data corruption.

---

### **Final State**:

- The destination memory now contains the copied data from the source.
- The function handles overlapping memory areas correctly by copying in the appropriate direction.

---

### **Conclusion**

This optimized version of `ft_memmove`:

- **Efficiently handles overlapping memory areas** by copying forward or backward as needed.
- **Ensures safety** by checking for `NULL` pointers to prevent undefined behavior.
- **Uses byte-by-byte copying** to handle any memory block, regardless of alignment.