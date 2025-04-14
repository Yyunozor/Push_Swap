# **ft_strjoin**

---

### **Purpose**:

The `ft_strjoin` function concatenates two strings, creating a new string that consists of `s1` followed by `s2`.

### **Prototype**:

```c
char	*ft_strjoin(char const *s1, char const *s2);
```

### **Input**:

- `s1`: The first string.
- `s2`: The second string to concatenate to the first.

### **Output**:

- Returns a pointer to the newly allocated concatenated string.
- Returns `NULL` if memory allocation fails.

---

### **Code Implementation**:

```c
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!joined_str)
		return (NULL);
	i = 0;
	while (*s1)
		joined_str[i++] = *s1++;
	while (*s2)
		joined_str[i++] = *s2++;
	joined_str[i] = '\0';
	return (joined_str);
}
```

### **Explanation**:

- The function joins two strings, `s1` and `s2`, into a new string.
- It first checks if either input is `NULL` and returns `NULL` if so.
- The lengths of `s1` and `s2` are calculated to determine the required memory allocation for the new string.
- Memory is allocated for the new string, including space for the null-terminator.
- The function then copies each character from `s1` and `s2` into the new string.
- Finally, the new string is null-terminated, and the function returns a pointer to it.

---

### **Visual Focus**

We are joining the strings `"Hello"` and `" World!"` into a single new string `"Hello World!"`.

```jsx
s1:          [ H | e | l | l | o ]
s2:          [   | W | o | r | l | d | ! ]
Result:      [ H | e | l | l | o |   | W | o | r | l | d | ! | \0 ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12 ]
```

---

### **Final State**:

- The function successfully creates a new string `"Hello World!"` by concatenating `s1` and `s2`.
- The resulting string is a newly allocated block of memory, including the null-terminator.

---

### **Conclusion**:

This implementation of `ft_strjoin`:

- **Efficiently concatenates two strings** by calculating the required memory beforehand.
- **Handles memory allocation errors** by returning `NULL` if allocation fails.
- **Ensures the concatenated result is properly null-terminated**.

---