# **`ft_split`**

### **Purpose**:

The `ft_split` function splits a given string (`s`) into an array of substrings, using a specified delimiter character (`c`). It allocates memory for each substring and returns a dynamically allocated array of these substrings, ending with a `NULL`pointer.

---

### **Prototype**:

```c
char **ft_split(char const *s, char c);

```

- **Parameters**:
    - `s`: The input string to be split.
    - `c`: The delimiter character used to split the string.
- **Return Value**:
    - Returns a dynamically allocated array of substrings obtained by splitting `s` using `c`.
    - The array ends with a `NULL` pointer.
    - Returns `NULL` if memory allocation fails or if the input string is `NULL`.

---

### **Code Implementation**:

```c
static void	ft_free(char **arr, char **ptr)
{
	while (ptr-- > arr)
		free(*ptr);
	free(arr);
}

static size_t	ft_counter(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (!s[1] || s[1] == c))
			count++;
		s++;
	}
	return (count);
}

static char	*ft_nxtwrd(const char **s, char c)
{
	const char	*start;

	while (**s && **s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	return (ft_substr(start, 0, *s - start));
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	**ptr;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_counter(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	ptr = res;
	while (words--)
	{
		*ptr = ft_nxtwrd(&s, c);
		if (!*ptr++)
			return (ft_free(res, ptr - 1), NULL);
	}
	*ptr = NULL;
	return (res);
}

```

---

### **Explanation**:

1. **`ft_free` Helper Function**:
    - This function frees all previously allocated memory if an allocation fails during the splitting process.
    - It starts from the last allocated memory slot and works backward to free each element in the array.
2. **`ft_counter` Helper Function**:
    - This function counts the number of words (substrings) in the input string `s`, based on the delimiter `c`.
    - It increments the count whenever a non-delimiter character is followed by either a delimiter or the end of the string.
3. **`ft_nxtwrd` Helper Function**:
    - This function finds the next word in the input string `s`, skipping over any leading delimiters.
    - It returns a substring using `ft_substr`, which contains the word found between the start and the next delimiter.
4. **`ft_split` Main Function**:
    - The main function first checks if the input string `s` is `NULL` and returns `NULL` if it is.
    - It calculates the number of words and allocates memory for an array of strings (`res`), including space for the `NULL` terminator.
    - It iterates through the words, using `ft_nxtwrd` to populate the array.
    - If memory allocation fails at any point, `ft_free` is called to release previously allocated resources.
    - The array is terminated with a `NULL` pointer.

---

### **Visual Focus**:

Let’s walk through an example where `ft_split` is used to split the string `"Hello 42 Network"` using the space character `' '` as the delimiter.

### **Original String**:

```c
Input: "Hello 42 Network"
Delimiter: ' '

```

### **Steps for Splitting**:

1. **Count the Words**:
    - The function identifies three words: `"Hello"`, `"42"`, and `"Network"`.
2. **Extract the Words Using `ft_nxtwrd`**:
    - The first call to `ft_nxtwrd` returns `"Hello"`.
    - After skipping over consecutive spaces, the next call returns `"42"`.
    - The final call extracts `"Network"`.

### **Memory Representation**:

```c
Result Array: [ "Hello", "42", "Network", NULL ]

```

---

### **Edge Cases**:

- **Empty String**:
    - If the input string is empty (`""`), the function returns an array with a single `NULL` element.
- **Consecutive Delimiters**:
    - The function skips over consecutive delimiters, ensuring that no empty strings are added to the result array.
- **Memory Allocation Failure**:
    - If memory allocation fails at any point, all previously allocated memory is freed, and the function returns `NULL`.
- **NULL Input String**:
    - If the input string `s` is `NULL`, the function returns `NULL`.

---

### **Complexity Analysis**:

- **Time Complexity**: O(n), where `n` is the length of the input string. The function processes each character in the string once.
- **Space Complexity**: O(w), where `w` is the number of words. This accounts for the memory needed to store the result array and the substrings.

---

### **Conclusion**:

The **`ft_split`** function provides an efficient way to split a string into an array of substrings using a specified delimiter. It handles various edge cases, including memory allocation failures, consecutive delimiters, and empty strings. With its use of helper functions, the code remains modular and easy to understand.

---