# **ft_isascii**

### **Purpose**:

The `ft_isascii` function checks if a given character is part of the **ASCII** character set (values between 0 and 127).

### **Prototype**:

```c
int ft_isascii(int c);

```

- **Input**: An integer `c`.
- **Output**:
    - Returns `1` if `c` is a valid ASCII character (0 <= c <= 127).
    - Returns `0` if it is outside this range.

### **How it works**:

- The function checks if `c` is between 0 and 127, which are the valid ASCII values.

### **Code Implementation**:

```c
int ft_isascii(int c)
{
    return (c >= 0 && c <= 127);
}

```

### **Explanation**:

- The condition checks if `c` is within the ASCII character set (0 through 127).
- If true, it returns `1`; otherwise, it returns `0`.
---