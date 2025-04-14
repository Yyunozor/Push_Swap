# **ft_strlen**

---

### **Purpose**:

The `ft_strlen` function calculates the length of a string (number of characters before the null-terminator `\0`).

### **Prototype**:

```c
c
Copy code
size_t ft_strlen(const char *s);

```

- **Input**: A pointer to a null-terminated string `s`.
- **Output**: Returns the number of characters in the string, excluding the null-terminator.

---

### **Code Implementation**:

```c
c
Copy code
size_t	ft_strlen(const char *s)
{
	size_t len = 0;

	while (s[len])
		len++;
	return (len);
}

```

---

### **Visual Focus**

We are measuring the length of the string `"Hello World!"`.

### **String Representation**:

| H | e | l | l | o |  | W | o | r | l | d | ! |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |

We iterate over the string, counting each character until we reach the null-terminator (`\0`).

1. **Index 0**: `'H'` → Length = 1
2. **Index 1**: `'e'` → Length = 2
3. **Index 2**: `'l'` → Length = 3
4. **Index 3**: `'l'` → Length = 4
5. **Index 4**: `'o'` → Length = 5
6. **Index 5**: `(space)` → Length = 6
7. **Index 6**: `'W'` → Length = 7
8. **Index 7**: `'o'` → Length = 8
9. **Index 8**: `'r'` → Length = 9
10. **Index 9**: `'l'` → Length = 10
11. **Index 10**: `'d'` → Length = 11
12. **Index 11**: `'!'` → Length = 12

The function terminates at the null-terminator and returns the **length 12**.

### **Visual Representation**

```jsx
String: [ H | e | l | l | o |   | W | o | r | l | d | ! ]
Index : [ 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11]
                                                      ^
                            End of string after index 11

```

---