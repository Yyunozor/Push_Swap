# `ft_itoa`

---

### **Purpose**:

The `ft_itoa` function converts an integer to its string representation. It correctly handles positive and negative integers as well as zero.

---

### **Prototype**:

```c
char *ft_itoa(int n);

```

- **Parameters**:
    - `n`: The integer to convert to a string.
- **Return Value**:
    - A pointer to a newly allocated string representing the integer.
    - Returns `NULL` if the memory allocation fails.

---

### **Code Implementation**:

```c
static size_t	ft_numlen(int n)
{
	size_t	digits;

	digits = 0;
	if (n <= 0)
		digits = 1;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	nb;
	char	*str;

	nb = n;
	len = ft_numlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[--len] = '0';
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

```

---

### **Explanation**:

1. **Helper Function (`ft_numlen`)**:
    - `ft_numlen` calculates the number of digits in the integer, including space for a negative sign if needed.
    - The function starts with `digits = 1` if the number is less than or equal to zero, to account for a possible negative sign or the digit '0'.
2. **Main Function (`ft_itoa`)**:
    - Converts the integer `n` to a `long` (`nb`) to safely handle the edge case of `INT_MIN`.
    - Calculates the length of the resulting string, including space for the negative sign if needed.
    - Allocates memory for the string and sets the null terminator.
    - Handles negative numbers by setting the first character to `'-'` and converting the absolute value of `nb`.
    - If `n` is zero, directly sets the first character to `'0'`.
    - Converts the number to a string representation from the least significant digit to the most significant.

---

### **Edge Cases Handled**:

- **Zero (`0`)**:
    - If the input is zero, the function returns `"0"` as a string.
- **Negative Numbers**:
    - Correctly handles negative numbers by adding a `'-'` sign at the beginning of the string.
- **Minimum Integer Value (`INT_MIN`)**:
    - Safely handles the edge case using a `long` to avoid overflow.

---

### **Visual Focus**:

Let’s consider the input `-123`:

1. **Counting Digits**:
    - `ft_numlen(-123)` returns `4` (3 digits + 1 for the negative sign).
2. **Memory Allocation**:
    - Allocates space for `5` characters (`4` digits + null terminator).
3. **String Conversion**:

| Step | String State | Explanation |
| --- | --- | --- |
| Init | `_ _ _ _ \0` | Initial state after allocation. |
| Sign | `- _ _ _ \0` | Negative sign added. |
| 3 | `- _ _ 3 \0` | Last digit added. |
| 2 | `- _ 2 3 \0` | Next digit added. |
| 1 | `- 1 2 3 \0` | First digit added. |

The final result is `"-123"`.

---

### **Complexity Analysis**:

- **Time Complexity**: O(d), where `d` is the number of digits in the integer.
- **Space Complexity**: O(d), accounting for the string representation of the integer.

---

### **Edge Case Handling**:

- **Zero Input**:
    - If `n` is `0`, the function returns the string `"0"`.
- **Handling Negative Numbers**:
    - The function places a `'-'` at the start of the string if the number is negative.
- **Handling Integer Overflow**:
    - The use of a `long` ensures that the function correctly handles `INT_MIN`.

---
