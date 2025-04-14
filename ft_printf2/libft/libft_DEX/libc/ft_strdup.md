# **ft_strdup**

---

### **Purpose**:

The `ft_strdup` function allocates memory and duplicates a string.

### **Prototype**:

```c
char	*ft_strdup(const char *s1);
```

- **Input**:
    - `s1`: The string to duplicate.
- **Output**: Returns a pointer to the newly allocated string, or `NULL` if memory allocation fails.

---

### **Code Implementation**:

```c
char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
```

---

### **Explanation**:

- The function calculates the length of `s1` using `ft_strlen`.
- It then allocates memory for the duplicate string (`len + 1` to account for the null-terminator).
- Finally, it copies the characters from `s1` into the new memory space and returns the pointer to the duplicate.

---

### **Visual Focus**

We are duplicating the string `"Hello"`.

### **Before `ft_strdup` Execution**

- **Source String (`s1`)**: `"Hello"`

Here’s the layout before the function runs:

```jsx
Source:      [ H | e | l | l | o | \0 ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5  ]

```

---

### **After `ft_strdup` Execution**

The function allocates memory and duplicates the string `"Hello"`.

```jsx
Source:      [ H | e | l | l | o | \0 ]
Duplicate:   [ H | e | l | l | o | \0 ]
Index:       [ 0 | 1 | 2 | 3 | 4 | 5  ]

```

---

### **Step-by-Step Breakdown**:

1. **Step 1**: Calculate the length of the string (`5`).
2. **Step 2**: Allocate memory for the new string (`6` bytes).
3. **Step 3**: Copy each character from `s1` to the new string.
4. **Step 4**: Null-terminate the duplicate.

---

### **Final State**:

- The function duplicates the string `"Hello"`.
- The duplicate string is allocated in new memory, ensuring the original string is unchanged.

---

### **Conclusion**

This optimized version of `ft_strdup`:

- **Efficiently duplicates a string** by allocating memory and copying each character.
- **Handles memory allocation** safely, returning `NULL` if allocation fails.
- Ensures that the duplicated string is properly null-terminated.

---