# `ft_strmapi`

---

### **Purpose**:

The `ft_strmapi` function creates a new string by applying a given function `f` to each character of the input string `s`, where the function takes the character's index and the character itself as arguments.

---

### **Prototype**:

```c
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

```

- **Parameters**:
    - `s`: The input string on which to iterate.
    - `f`: A function that takes an index (`unsigned int`) and a character (`char`), and returns a modified character.
- **Return Value**:
    - A newly allocated string resulting from the successive applications of the function `f` on each character of the input string.
    - Returns `NULL` if the memory allocation fails.

---

### **Code Implementation**:

```c
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

```

---

### **Explanation**:

1. **Parameter Validation**:
    - If either `s` or `f` is `NULL`, the function immediately returns `NULL` to ensure safety.
2. **Memory Allocation**:
    - Allocates memory for a new string of the same length as `s`, plus one for the null terminator.
    - Returns `NULL` if the memory allocation fails.
3. **Character Mapping**:
    - Iterates over each character of the input string `s`, applying the function `f` to it. The function `f` receives the current character index and the character itself.
    - Stores the result in the corresponding position of the new string.
4. **Null Terminator**:
    - The new string is null-terminated after the loop to ensure proper string formatting.

---

### **Edge Cases Handled**:

- **Empty String**:
    - If the input string is empty, the function will return an empty string (`""`), as the memory allocation will still occur for one byte (the null terminator).
- **`NULL` Input**:
    - If either `s` or `f` is `NULL`, the function returns `NULL` without performing any operations.

---

### **Visual Focus**:

Let’s consider the input string `"Hello"` and a function `f` that converts characters to uppercase and adds their index as an offset:

1. **Original String**:
    - `"Hello"`
2. **Function Application**:
    - `f(0, 'H')` → 'H'
    - `f(1, 'e')` → 'F'
    - `f(2, 'l')` → 'N'
    - `f(3, 'l')` → 'O'
    - `f(4, 'o')` → 'T'
3. **Resulting String**:
    - `"HFNOT"`

---

### **Complexity Analysis**:

- **Time Complexity**: O(n), where `n` is the length of the input string. The function iterates over each character once.
- **Space Complexity**: O(n), where `n` is the length of the new string being allocated.

---

### **Edge Case Handling**:

- **Empty Input String**:
    - Returns a string with just the null terminator.
- **Function Pointer `f` Being `NULL`**:
    - Returns `NULL` without performing any operations.

---