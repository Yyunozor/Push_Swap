# **ft_isdigit**

### **Purpose**:

The `ft_isdigit` function checks if a given character is a **digit** ('0' to '9').

### **Prototype**:

```c
int ft_isdigit(int c);

```

- **Input**: An integer `c` that represents a character.
- **Output**:
    - Returns `1` if the character is a digit ('0' to '9').
    - Returns `0` if it is not a digit.

### **How it works**:

- It checks if the character `c` is between `'0'` and `'9'` in the ASCII table.

### **Code Implementation**:

```c
int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

```

### **Explanation**:

- The condition `(c >= '0' && c <= '9')` checks if the character falls within the ASCII range for digits.
- If `c` is a digit, it returns `1`, otherwise `0`.
---