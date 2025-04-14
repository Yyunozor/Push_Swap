# **ft_strncmp**

---

### **Purpose**:

The `ft_strncmp` function compares the first `n` bytes of two strings (`s1` and `s2`).

### **Prototype**:

```c
nt	ft_strncmp(const char *s1, const char *s2, size_t n);

```

- **Input**:
    - `s1`: The first string to compare.
    - `s2`: The second string to compare.
    - `n`: The maximum number of bytes to compare.
- **Output**: Returns an integer:
    - `0` if the first `n` characters are equal.
    - A positive or negative value if `s1` and `s2` differ.

---

### **Code Implementation**:

```c
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

```

---

### **Explanation**:

- The function compares the first `n` characters of the strings `s1` and `s2`.
- If the strings differ at any point, it returns the difference between the first differing characters.
- If the strings are equal up to `n` characters, it returns `0`.

---

### **Visual Focus**

We’ll compare the first 5 characters of the strings `"Hello"` (`s1`) and `"HellX"` (`s2`).

### **Before `ft_strncmp` Execution**

- **String 1 (`s1`)**: `"Hello"`
- **String 2 (`s2`)**: `"HellX"`
- **Number of characters to compare (`n`)**: `5`

Here’s the layout before the function runs:

```jsx
String 1:    [ H | e | l | l | o ]
String 2:    [ H | e | l | l | X ]
Index:       [ 0 | 1 | 2 | 3 | 4 ]
```

---

### **After `ft_strncmp` Execution**

The function will compare the first 5 characters and return the difference at index `4`, where `'o'` and `'X'` differ.

```jsx
String 1:    [ H | e | l | l | o ]
String 2:    [ H | e | l | l | X ]
Index:       [ 0 | 1 | 2 | 3 | 4 ]
                               ^
                  Difference found at index 4
```

---

### **Step-by-Step Breakdown**:

1. **Index 0**: `'H'` equals `'H'`.
2. **Index 1**: `'e'` equals `'e'`.
3. **Index 2**: `'l'` equals `'l'`.
4. **Index 3**: `'l'` equals `'l'`.
5. **Index 4**: **`'o'` differs from `'X'`**! → Return the difference between `'o'` and `'X'`.

---

### **Final State**:

- The function compares the first `5` characters and finds a difference at index `4`.
- The function returns the difference between `'o'` (ASCII 111) and `'X'` (ASCII 88), which is `111 - 88 = 23`.

---

### **Conclusion**

This optimized version of `ft_strncmp`:

- **Efficiently compares** the first `n` characters of two strings.
- **Returns a non-zero value** when a difference is found, or `0` if the strings are equal.
- Ensures safety and accuracy in string comparisons, useful for lexicographical comparisons.

---