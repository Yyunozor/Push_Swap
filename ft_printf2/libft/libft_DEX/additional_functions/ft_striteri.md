# `ft_striteri`

---

### **Purpose**:

The `ft_striteri` function applies a given function `f` to each character of a string `s`, where the function modifies the character in place. The function `f` receives the current character's index and a pointer to the character.

---

### **Prototype**:

```c

void ft_striteri(char *s, void (*f)(unsigned int, char*));

```

- **Parameters**:
    - `s`: The string on which to iterate.
    - `f`: A function that takes the character's index and a pointer to the character, allowing for modification.
- **Return Value**:
    - This function does not return any value.

---

### **Code Implementation**:

```c
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

```

---

### **Explanation**:

1. **Parameter Validation**:
    - If either `s` or `f` is `NULL`, the function returns immediately without performing any operations to avoid undefined behavior.
2. **Iterating Over the String**:
    - The function iterates over each character of the string `s`.
    - For each character, it calls the function `f`, passing the current index (`i`) and the address of the character (`&s[i]`).
    - The character can be modified in place by the function `f`, allowing for direct changes to the original string.
3. **Use Cases**:
    - `ft_striteri` is particularly useful when a function needs to transform each character of a string based on its position, such as converting characters to uppercase, shifting ASCII values, or applying other custom transformations.

---

### **Edge Cases Handled**:

- **Empty String (`""`)**:
    - If the input string is empty, the function does nothing since the loop condition will immediately fail.
- **`NULL` Input Parameters**:
    - If `s` or `f` is `NULL`, the function will return without making any changes.

---

### **Vsual Focus**:

Let’s consider an example where the input string is `"abcd"` and the function `f` converts each character to uppercase if the index is even:

1. **Original String**:
    - `"abcd"`
2. **Function Application**:

| Step | Index | Character | Transformation |
| --- | --- | --- | --- |
| 1 | 0 | `a` | Converts to uppercase (`A`) |
| 2 | 1 | `b` | Remains lowercase (`b`) |
| 3 | 2 | `c` | Converts to uppercase (`C`) |
| 4 | 3 | `d` | Remains lowercase (`d`) |
1. **Resulting String**:
    - `"AbCd"`

---

### **Complexity Analysis**:

- **Time Complexity**: O(n), where `n` is the length of the string. The function iterates over each character once.
- **Space Complexity**: O(1), since the function modifies the string in place and does not require additional memory allocation.

---

### **Edge Case Handling**:

- **Empty Input String**:
    - If the input string is empty, the function exits immediately.
- **Handling `NULL` Parameters**:
    - If `s` or `f` is `NULL`, the function does not perform any operations.

---