# **`ft_isvalid_base`**

### **Purpose**:

The `ft_isvalid_base` function checks if a given string can be used as a valid base for base conversion functions. It validates that the base string contains at least two characters, has no duplicate characters, and does not contain invalid symbols such as `+`, `-`, or whitespace characters.

---

### **Prototype**:

```c
size_t ft_isvalid_base(const char *base, int *base_len);

```

- **Parameters**:
    - `base`: The input string representing the base to be validated.
    - `base_len`: A pointer to an integer where the length of the base string will be stored.
- **Return Value**:
    - Returns `1` if the base is valid.
    - Returns `0` if the base is invalid (i.e., contains less than two characters, contains duplicates, or includes `+`, ``, or whitespace characters).

---

### **Code Implementation**:

```c
size_t	ft_isvalid_base(const char *base, int *base_len)
{
	const char	*ptr;

	*base_len = ft_strlen(base);
	if (*base_len < 2)
		return (0);
	ptr = base;
	while (*ptr)
	{
		if (*ptr == '+' || *ptr == '-' || ft_isspace(*ptr))
			return (0);
		if (ft_strchr(ptr + 1, *ptr))
			return (0);
		ptr++;
	}
	return (1);
}

```

---

### **Explanation**:

1. **Calculating Base Length**:
    - The function starts by calculating the length of the `base` string using `ft_strlen`. The length is stored in the variable pointed to by `base_len`.
    - If the length is less than 2, the function returns `0`, indicating that the base is invalid.
2. **Character Validation**:
    - The function iterates over each character in the `base` string using the pointer `ptr`.
    - It checks for invalid characters:
        - If the character is `+`, ``, or a whitespace (using `ft_isspace`), the base is deemed invalid.
        - If the character appears more than once in the `base` string (using `ft_strchr` to check for duplicates), the base is also invalid.
3. **Returning Validity**:
    - If the base passes all the checks, the function returns `1` to indicate that the base is valid.

---

### **Visual Focus**:

Let’s look at some example cases to understand how `ft_isvalid_base` works.

### **Example 1**: Valid Base

- **Input**: `"0123456789"`
- **Length**: `10`
- **Check**: All characters are unique, and there are no invalid symbols.
- **Result**: Returns `1` (valid).

### **Example 2**: Invalid Base (Contains `+`)

- **Input**: `"01234+6789"`
- **Length**: `10`
- **Check**: The character `+` is invalid.
- **Result**: Returns `0` (invalid).

### **Example 3**: Invalid Base (Duplicate Characters)

- **Input**: `"01234456789"`
- **Length**: `11`
- **Check**: The character `4` is repeated.
- **Result**: Returns `0` (invalid).

### **Example 4**: Invalid Base (Single Character)

- **Input**: `"0"`
- **Length**: `1`
- **Check**: The length is less than `2`.
- **Result**: Returns `0` (invalid).

---

### **Key Points**:

1. **Length Requirement**:
    - A valid base must contain at least two distinct characters.
2. **Character Validation**:
    - The function checks that each character in the base string is neither `+`, ``, nor a whitespace character.
    - It also ensures that each character appears only once.
3. **Efficient Checking Using `ft_strchr`**:
    - The function uses `ft_strchr` to check for duplicate characters by searching the rest of the string for the current character.

---

### **Edge Cases**:

- **Empty String (`""`)**:
    - The function will return `0` because the length is less than `2`.
- **Base with Whitespace Characters (`"01 23456789"`)**:
    - The function will return `0` because the base contains a whitespace character.
- **Base with Special Characters (`"+0123456789"`)**:
    - The function will return `0` because the base contains the `+` character.

---

### **Complexity Analysis**:

- **Time Complexity**: O(n^2), where `n` is the length of the base string. The nested use of `ft_strchr` results in a quadratic time complexity in the worst case.
- **Space Complexity**: O(1) – The function operates in constant space, using only a few variables for character checks.

---

### **Conclusion**:

The **`ft_isvalid_base`** function provides a reliable way to validate base strings for use in functions like `ft_atoi_base` or `ft_itoa_base`. It ensures the base adheres to required constraints, making it suitable for safe base conversions. This function handles various edge cases and uses a combination of *Libft* functions (`ft_strlen`, `ft_isspace`, and `ft_strchr`) to keep the implementation clean and modular.

---