# **ft_isalnum**

### **Purpose**:

The `ft_isalnum` function checks if a given character is either an **alphabetic letter** or a **digit**.

### **Prototype**:

```c
int ft_isalnum(int c);

```

- **Input**: An integer `c` representing a character.
- **Output**:
    - Returns `1` if the character is an alphabetic letter (checked by `ft_isalpha`) or a digit (checked by `ft_isdigit`).
    - Returns `0` otherwise.

### **How it works**:

- It combines the results of `ft_isalpha` and `ft_isdigit` to check if the character is either a letter or a digit.

### **Code Implementation**:

```c
int ft_isalnum(int c)
{
    return (ft_isalpha(c) || ft_isdigit(c));
}

```

### **Explanation**:

- If either `ft_isalpha(c)` or `ft_isdigit(c)` returns `1` (true), the function will return `1`.
- If neither returns true, it returns `0`.
---