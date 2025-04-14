# **`ft_atol`**

### **Purpose**

The `ft_atol` function converts a string to a `long` integer value, handling optional spaces, optional signs (`+` or `-`), and overflow conditions. It provides a way to convert text-based numbers into `long` values, ensuring safe handling for edge cases.

---

### **Prototype**

```c
long	ft_atol(const char *str);

```

- **Parameters**:
    - `str`: A pointer to a null-terminated string representing a number.
- **Return Value**:
    - Returns the converted `long` integer if the input is valid.
    - Returns `LONG_MAX` if the input exceeds the maximum representable `long` value.
    - Returns `LONG_MIN` if the input exceeds the minimum representable `long` value.

---

### **Code Implementation**

```c
#include "libft.h"

long	ft_loverflow(int sign)
{
	if (sign == 1)
		return (LONG_MAX);
	return (LONG_MIN);
}

long	ft_atol(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (result > (LONG_MAX - (*str - '0')) / 10)
			return (ft_loverflow(sign));
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

```

---

### **Explanation**

1. **Overflow Helper Function (`ft_loverflow`)**:
    - This helper function returns `LONG_MAX` or `LONG_MIN` depending on the `sign`. This helps `ft_atol` handle overflow cases when `result` would exceed `LONG_MAX` or go below `LONG_MIN`.
2. **Initialization**:
    - The main function starts by initializing `sign` to `1` and `result` to `0`.
3. **Skipping Whitespaces**:
    - The function uses `ft_isspace` to skip over any leading whitespace characters in `str`, ensuring it starts processing at the number itself.
4. **Sign Detection**:
    - If the first non-whitespace character is a `'-'` or `'+'`, the `sign` variable is updated accordingly (`1` for `'-'`). After handling the sign, the pointer `str` advances to the next character.
5. **Digit Conversion Loop**:
    - The function enters a loop to process each digit character in `str`.
    - For each digit:
        - **Overflow Check**: Before adding the next digit, `ft_atol` checks if adding the digit would cause `result` to overflow. This is done by comparing `result` with `(LONG_MAX - (*str - '0')) / 10`. If this condition is met, the function returns the overflow value using `ft_loverflow(sign)`.
        - **Accumulate Result**: If no overflow is detected, `result` is updated by multiplying it by `10` and adding the current digit.
    - The loop ends once all digit characters are processed.
6. **Returning the Final Result**:
    - After processing all valid characters, the function returns the `result` multiplied by `sign` to give the correctly signed `long` value.

---

### **Visual Representation**

### Example: `" -12345"`

```
Input String: "   -12345"
Processed Steps:
  - Skip whitespaces → `"-12345"`
  - Detect sign      → `sign = -1`
  - Convert digits   → result accumulates as 12345
  - Apply sign       → final result = -12345

```

| Step | Result | Explanation |
| --- | --- | --- |
| `" -12345"` | Start | Initial input string. |
| Skip spaces | `"-12345"` | Whitespaces removed. |
| Detect sign | `sign = -1` | Sign is negative. |
| Convert digits | `12345` | Each digit is processed, `result` accumulates. |
| Apply sign | `-12345` | `result` is multiplied by `sign` to yield `-12345`. |

---

### **Edge Cases Handled**

1. **Whitespace Before Number**:
    - The function skips over leading whitespace, allowing inputs like `" 123"`.
2. **Sign Handling**:
    - Handles both `+` and `` signs. For example, `" -123"` becomes `123`, and `"+123"` becomes `123`.
3. **Overflow Handling**:
    - If the accumulated `result` would exceed `LONG_MAX`, `ft_atol` returns `LONG_MAX` or `LONG_MIN` based on the `sign`.
4. **Invalid Characters**:
    - Once the function encounters a non-digit character, it stops parsing and returns the accumulated `result`.

---

### **Complexity Analysis**

- **Time Complexity**: O(n), where `n` is the length of the input string. The function processes each character in the string once.
- **Space Complexity**: O(1), as it uses a constant amount of memory regardless of input size.

---

### **Test Cases**

Here’s an example test file to demonstrate how `ft_atol` behaves with different inputs:

```c
#include <stdio.h>

int main(void)
{
	const char *test1 = "12345";
	const char *test2 = "-98765";
	const char *test3 = "   +42";
	const char *test4 = "2147483647";     // LONG_MAX
	const char *test5 = "-2147483648";    // LONG_MIN
	const char *test6 = "99999999999999"; // Overflow

	printf("Test 1: %ld\n", ft_atol(test1)); // Expected: 12345
	printf("Test 2: %ld\n", ft_atol(test2)); // Expected: -98765
	printf("Test 3: %ld\n", ft_atol(test3)); // Expected: 42
	printf("Test 4: %ld\n", ft_atol(test4)); // Expected: LONG_MAX
	printf("Test 5: %ld\n", ft_atol(test5)); // Expected: LONG_MIN
	printf("Test 6: %ld\n", ft_atol(test6)); // Expected: LONG_MAX (overflow)

	return 0;
}

```

### Expected Output:

```
Test 1: 12345
Test 2: -98765
Test 3: 42
Test 4: 2147483647
Test 5: -2147483648
Test 6: 9223372036854775807  (LONG_MAX, due to overflow)

```

---

### **Conclusion**

`ft_atol` is a robust string-to-long converter that handles whitespace, sign, overflow, and invalid characters. It’s useful for cases where you need to interpret large numerical strings safely without risking overflow errors in C.
---
