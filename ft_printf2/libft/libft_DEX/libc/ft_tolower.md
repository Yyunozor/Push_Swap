# **ft_tolower**

### **Purpose**:

The `ft_tolower` function converts an uppercase letter to lowercase.

### **Prototype**:

```c
int ft_tolower(int c);

```

- **Input**: An integer `c` representing a character.
- **Output**: The lowercase version of the character if it’s uppercase; otherwise, returns `c` unchanged.

### **Code Implementation**:

```c
int ft_tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

```

### **Explanation**:

- If the input character `c` is an uppercase letter (between 'A' and 'Z'), it converts it to lowercase by adding 32 to its ASCII value.
- If `c` is not an uppercase letter, it returns `c` unchanged.
---