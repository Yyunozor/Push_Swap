# **ft_isalpha**

### **Purpose**:

The `ft_isalpha` function checks if a given character is an alphabetic letter, either uppercase or lowercase (i.e., between 'A' and 'Z' or 'a' and 'z').

### **Prototype**:

```c
int ft_isalpha(int c);

```

- **Input**: An integer `c` that represents a character.
- **Output**:
    - Returns `1` if the character is alphabetic (either uppercase or lowercase).
    - Returns `0` if it is not an alphabetic character.

### **How it works**:

- It simply checks if the character `c` is within the ASCII range for uppercase (`'A'` to `'Z'`) or lowercase (`'a'` to `'z'`).

### **Code Implementation**:

```c
int ft_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

```

### **Explanation**:

- The condition `(c >= 'A' && c <= 'Z')` checks if `c` is between 'A' and 'Z'.
- The condition `(c >= 'a' && c <= 'z')` checks if `c` is between 'a' and 'z'.
- If either condition is true, it returns `1`; otherwise, it returns `0`.
---