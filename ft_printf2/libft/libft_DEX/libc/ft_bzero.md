# **ft_bzero**

---

### **Purpose**:

The `ft_bzero` function writes `n` zeroed bytes to the string `s`.

### **Prototype**:

```c
void ft_bzero(void *s, size_t n);

```

- **Input**:
    - `s`: Pointer to the memory area.
    - `n`: The number of bytes to zero out.
- **Output**: None.

---

### **Code Implementation**:

```c
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

```

---

### **Visual Focus**

We are setting the first `6` bytes of memory in the string to zero (`0`).

### **Memory Representation (Before `ft_bzero`)**:

| H | e | l | l | o | W | ? | ? | ? | ? | ? | ? |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |

---

### **After `ft_bzero`**:

| 0 | 0 | 0 | 0 | 0 | 0 | ? | ? | ? | ? | ? | ? |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |

---

### **Visual Representation with Arrows**:

```jsx
Memory:  [ 0 | 0 | 0 | 0 | 0 | 0 | ? | ? | ? | ? | ? | ? ]
Index :  [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11]
                               ^
                               First 6 bytes set to 0

```

---