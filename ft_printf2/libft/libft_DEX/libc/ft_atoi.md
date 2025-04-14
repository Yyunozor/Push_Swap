# **ft_atoi**

---

### **Purpose**:

The `ft_atoi` function converts a string to an integer.

### **Prototype**:

```c
int	ft_atoi(const char *str);

```

- **Input**:
    - `str`: The string to convert to an integer.
- **Output**: Returns the converted integer.

---

### **Code Implementation**:

```c
int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;

	// Skip whitespaces
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	// Handle sign
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	// Convert characters to int
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

```

---

### **Explanation**:

- The function skips any whitespace characters.
- If the string starts with a `+` or ``, it handles the sign appropriately.
- Then it converts the numeric part of the string into an integer, stopping when it encounters a non-numeric character.

---

### **Visual Focus**

We are converting the string `" -1234abc"` to the integer `-1234`.

### **Before `ft_atoi` Execution**

- **String (`str`)**: `" -1234abc"`

Here’s the layout before the function runs:

```jsx
String:      [ ' ' | ' ' | '-' | '1' | '2' | '3' | '4' | 'a' | 'b' | 'c' ]
Index:       [  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  ]

```

---

### **After `ft_atoi` Execution**

The function converts the string and stops at the first non-numeric character (`'a'`), returning `-1234`.

```jsx
String:      [ ' ' | ' ' | '-' | '1' | '2' | '3' | '4' | 'a' | 'b' | 'c' ]
Index:       [  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  ]
                            ^
                     Result is -1234

```

---

### **Step-by-Step Breakdown**:

1. **Step 1**: Skip whitespace (`' '`).
2. **Step 2**: Handle the sign (`'-'` → negative sign).
3. **Step 3**: Convert `'1'`, `'2'`, `'3'`, `'4'` to `1234`.
4. **Step 4**: Stop at `'a'`, return `1234`.

---

### **Final State**:

- The function converts the string `" -1234abc"` to the integer `1234`.
- The conversion stops at the first non-numeric character (`'a'`).

---

### **Conclusion**

This optimized version of `ft_atoi`:

- **Efficiently skips whitespace**, handles the sign, and converts numeric characters into an integer.
- **Stops conversion** at the first non-numeric character, making it safe for mixed-character strings.
- Ensures correct handling of both positive and negative numbers.

---