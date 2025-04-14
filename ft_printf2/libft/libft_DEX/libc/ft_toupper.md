# **ft_toupper**

### **Purpose**:

The `ft_toupper` function converts a lowercase letter to uppercase.

### **Prototype**:

```c
int ft_toupper(int c);

```

- **Input**: An integer `c` representing a character.
- **Output**: The uppercase version of the character if it’s lowercase; otherwise, returns `c` unchanged.

### **Code Implementation**:

```c
int ft_toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

```

### **Explanation**:

- If the input character `c` is a lowercase letter (between 'a' and 'z'), it converts it to uppercase by subtracting 32 from its ASCII value.
- If `c` is not a lowercase letter, it returns `c` unchanged.
---