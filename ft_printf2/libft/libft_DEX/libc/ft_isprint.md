# **ft_isprint**

### **Purpose**:

The `ft_isprint` function checks if a given character is a **printable** character (ASCII values from 32 to 126).

### **Prototype**:

```c
int ft_isprint(int c);

```

- **Input**: An integer `c`.
- **Output**:
    - Returns `1` if `c` is a printable character (from 32 to 126 in the ASCII table).
    - Returns `0` otherwise.

### **How it works**:

- Printable characters include letters, digits, punctuation, and symbols. The ASCII range for printable characters is from 32 (space) to 126 (tilde).

### **Code Implementation**:

```c
int ft_isprint(int c)
{
    return (c >= 32 && c <= 126);
}

```

### **Explanation**:

- It checks if `c` is within the range of printable ASCII characters.
- If true, the function returns `1`, otherwise `0`.
---