# **ft_memset**

---

### **Purpose**:

The `ft_memset` function fills the first `n` bytes of the memory area pointed to by `b` with the constant byte `c`.

### **Prototype**:

```c
void *ft_memset(void *b, int c, size_t len);

```

- **Input**:
    - `b`: The memory area to fill.
    - `c`: The value to set (converted to `unsigned char`).
    - `len`: The number of bytes to fill.
- **Output**: Returns a pointer to the memory area `b`.

---

### **Code Implementation**:

```c
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr = (unsigned char *)b;

	while (len--)
		*ptr++ = (unsigned char)c;
	return (b);
}

```

---

### **Visual Focus**

We are filling the first `6` bytes of memory in the array with the value `'A'` (ASCII value 65).

### **Memory Representation**:

| ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? | ? |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |

We fill the first 6 bytes with `'A'`.

### **After `ft_memset`**:

| A | A | A | A | A | A | ? | ? | ? | ? | ? | ? |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |

### **Visual Representation with Arrows**:

```jsx
Memory:  [ A | A | A | A | A | A |  ?  |  ?  |  ?  |  ?  |  ?  |  ?  ]
Index :  [ 0 | 1 | 2 | 3 | 4 | 5 |  6  |  7  |  8  |  9  | 10  |  11 ]
                               ^
                               Last byte set to 'A'

```

---