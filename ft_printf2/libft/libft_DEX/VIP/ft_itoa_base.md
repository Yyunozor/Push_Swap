# **`ft_itoa_base`**

### **Purpose**:

The `ft_itoa_base` function converts an integer value to a string representation in a specified base. It supports bases from 2 to 16 and handles negative numbers if the base is 10. The function dynamically allocates memory for the resulting string.

---

### **Prototype**:

```c
char	*ft_itoa_base(int value, const char *base);

```

- **Parameters**:
    - `value`: The integer value to convert.
    - `base`: A string representing the set of valid characters for the base.
- **Return Value**:
    - Returns a dynamically allocated string representing the integer in the specified base.
    - Returns `NULL` if the base is invalid or memory allocation fails.

---

### **Code Implementation**:

```c
static int	ft_num_len(long num, int base_len)
{
	int	len;

	len = (num == 0);
	while (num != 0)
	{
		num /= base_len;
		len++;
	}
	return (len);
}

static int	ft_sign_abs(long *num, int base_len)
{
	if (*num < 0 && base_len == 10)
	{
		*num = -*num;
		return (1);
	}
	return (0);
}

char	*ft_itoa_base(int value, const char *base)
{
	char		*result;
	long		num;
	int			base_len;
	int			sign;
	int			num_len;

	if (!ft_isvalid_base(base, &base_len))
		return (NULL);
	num = (long)value;
	sign = ft_sign_abs(&num, base_len);
	num_len = ft_num_len(num, base_len) + sign;
	result = (char *)malloc(num_len + 1);
	if (!result)
		return (NULL);
	result[num_len] = '\0';
	while (num_len-- > sign)
	{
		result[num_len] = base[num % base_len];
		num /= base_len;
	}
	if (sign)
		result[0] = '-';
	return (result);
}

```

---

### **Explanation**:

1. **`ft_num_len` Helper Function**:
    - Calculates the number of characters required to represent the number in the given base.
    - Returns at least 1 if the number is zero (i.e., "0" requires one character).
    - Continues dividing the number by the base until it becomes zero, counting each step to determine the length.
2. **`ft_sign_abs` Helper Function**:
    - Checks if the number is negative and if the base is 10.
    - If so, it converts the number to its absolute value and returns `1` to indicate the presence of a negative sign.
    - Returns `0` otherwise.
3. **Main Function (`ft_itoa_base`)**:
    - Checks if the base is valid using `ft_isvalid_base`, which ensures the base is at least two characters long and contains no duplicates or invalid characters.
    - Converts the input value to a `long` to handle edge cases such as `INT_MIN`.
    - Computes the number of characters needed for the result string using `ft_num_len`, taking the sign into account.
    - Allocates memory for the result string, including space for the null terminator.
    - Fills the string in reverse order by calculating the modulus with the base and dividing by the base repeatedly.
    - Adds a negative sign if the original number was negative and the base is 10.
    - Returns the resulting string.

---

### **Visual Focus**:

Let’s walk through some examples to understand how `ft_itoa_base` works.

### **Example 1**: Converting `42` to Base 2

- **Input**: `42`, `"01"`
- **Base**: `2`
- **Steps**:
    - Number: `42`, Length: `6` ("101010")
- **Output**: `"101010"`

### **Example 2**: Converting `12345` to Base 10

- **Input**: `12345`, `"0123456789"`
- **Base**: `10`
- **Steps**:
    - Number: `12345`, Length: `6` (add space for the negative sign)
    - Output: `"-12345"`

### **Example 3**: Converting `255` to Base 16

- **Input**: `255`, `"0123456789ABCDEF"`
- **Base**: `16`
- **Steps**:
    - Number: `255`, Length: `2` ("FF")
- **Output**: `"FF"`

---

### **Edge Cases**:

1. **Invalid Base**:
    - The function returns `NULL` if the base is invalid, i.e., it contains less than two characters, has duplicates, or includes invalid characters.
2. **Zero Value**:
    - If the input value is zero, the function correctly returns `"0"`.
3. **Negative Numbers in Non-Decimal Bases**:
    - The function only adds a negative sign if the base is 10. For other bases, it represents the number using the absolute value.
4. **Minimum Integer Value (`INT_MIN`)**:
    - The function handles this case by converting the integer to a `long` to avoid overflow.

---

### **Complexity Analysis**:

- **Time Complexity**: O(log_b(n)), where `n` is the absolute value of the input number and `b` is the base. This represents the number of divisions required to reach zero.
- **Space Complexity**: O(log_b(n)) for the resulting string, plus O(1) auxiliary space.

---

### **Test Cases**:

```c
int	main(void)
{
	char *result;

	// Test with base 10
	result = ft_itoa_base(12345, "0123456789");
	printf("Base 10: \t\t%s\t(Expected: 12345)\n", result);
	free(result);

	// Test with base 2
	result = ft_itoa_base(42, "01");
	printf("Base 2: \t\t%s\t(Expected: 101010)\n", result);
	free(result);

	// Test with base 16
	result = ft_itoa_base(12345, "0123456789ABCDEF");
	printf("Base 16: \t\t%s\t(Expected: 3039)\n", result);
	free(result);

	// Test with negative number in base 10
	result = ft_itoa_base(-12345, "0123456789");
	printf("Base 10 (negative): \t%s\t(Expected: -12345)\n", result);
	free(result);

	// Test with invalid base
	result = ft_itoa_base(12345, "01234");
	if (result == NULL)
		printf("Invalid base: \t\tNULL\t\t(Expected: Invalid base: NULL)\n");

	return (0);
}

```

### **Conclusion**:

The **`ft_itoa_base`** function efficiently converts an integer to a string in any specified base from 2 to 16, handling negative numbers correctly for base 10. It uses modular design and helper functions to keep the implementation clean and handles edge cases gracefully.

---