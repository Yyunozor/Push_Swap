# **`ft_lstadd_front`**

### **Purpose**:

The `ft_lstadd_front` function adds a new node to the beginning of an existing linked list. This function is essential for efficient insertion of nodes at the start of the list, where the time complexity remains constant (O(1)).

---

### **Prototype**:

```c
void ft_lstadd_front(t_list **lst, t_list *new);

```

- **Parameters**:
    - `lst`: A pointer to the **first node** (head) of the list.
    - `new`: The new node to be added to the front of the list.
- **Return Value**:
    - None (void function).

---

### **Code Implementation**:

```c
#include "libft.h"void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (new == NULL)  // If the new node is NULL, there's nothing to add
        return;
    new->next = *lst;  // Set the new node's next pointer to the current head of the list
    *lst = new;        // Update the head to be the new node
}

```

---

### **Explanation**:

1. **Check for NULL**:
    - The function checks if the `new` node is `NULL`. If it is, the function does nothing (this prevents dereferencing a null pointer).
2. **Link the New Node**:
    - The `new` node’s `next` pointer is set to point to the current head of the list (`lst`). This effectively inserts the new node in front of the existing nodes.
3. **Update the Head**:
    - The pointer to the head of the list (`lst`) is updated to point to the new node, making it the new first node.

---

### **Visual Representation**:

Let’s say you have an existing list that looks like this:

```css
[21 | Next] -> [84 | NULL]

```

Now, you want to add a new node with content `42` to the **front** of the list.

After calling `ft_lstadd_front`, the result will be:

```css
[42 | Next] -> [21 | Next] -> [84 | NULL]

```

The new node with content `42` is now the head of the list, and it points to the previous head node (`21`).

---

### **Example Usage**:

Let’s see how you can use `ft_lstadd_front` to build a list.

```c
#include "libft.h"#include <stdio.h>int main()
{
    t_list *head = ft_lstnew((void *)21);  // Create the first node (21)
    t_list *node = ft_lstnew((void *)84);  // Create the second node (84)

    ft_lstadd_front(&head, node);  // Add node 84 at the front, making it the new head

    printf("First node content: %d\n", (int)head->content);  // Output: 84
    printf("Second node content: %d\n", (int)head->next->content);  // Output: 21

    return 0;
}

```

In this example:

- We start with a list of a single node (`21`).
- We then create another node (`84`) and use `ft_lstadd_front` to add it to the front.
- After calling the function, `84` becomes the new head of the list, and `21` is the second node.

---

### **Visual Walkthrough of Execution**:

1. **Before `ft_lstadd_front`**:

```arduino
[21 | NULL]

```

1. **After Creating a New Node (`84`)**:

```arduino
[84 | NULL]

```

1. **After Adding `84` to the Front** (via `ft_lstadd_front`):

```css
[84 | Next] -> [21 | NULL]

```

Now, the list starts with `84` and then points to `21`.

---

### **Common Questions**:

1. **What happens if the list is empty?**
    - If the list is empty (`lst == NULL`), the function still works. It simply sets `lst` to point to the new node, making the new node the only node in the list:
        
        ```arduino
        [42 | NULL]
        
        ```
        
2. **Can I add multiple nodes to the front?**
    - Yes! Each call to `ft_lstadd_front` adds a node to the front. For example, if you first add `42`, then `21`, then `84`, the list will look like:
        
        ```css
        [84 | Next] -> [21 | Next] -> [42 | NULL]
        
        ```
        
3. **What if the new node's `next` pointer is not `NULL`?**
    - The function doesn’t check or modify the `new` node’s `next` pointer if it is already set. This could cause the list to become corrupted if `new->next` points to something other than `NULL`. Therefore, you should ensure that any node added has a `NULL` `next` pointer unless you intend to merge two lists.

---

### **Edge Cases**:

- **Empty List**: If `lst` is `NULL` (i.e., the list is empty), the new node becomes the only node in the list.
- **NULL Node**: If the `new` node is `NULL`, the function does nothing.
- **Cyclic Lists**: If you're building a cyclic list (where nodes point back to earlier nodes), using `ft_lstadd_front` with careful control over the `next` pointers can allow you to create loops. However, for regular usage, ensure the `next`pointer is `NULL` or points to a valid node.

---

### **Complexity Analysis**:

- **Time Complexity**: O(1) – The function only modifies the head of the list and the `next` pointer of the new node, which takes constant time.
- **Space Complexity**: O(1) – No extra space is used, aside from the existing nodes.

---

### **Possible Improvements**:

- **Error Handling**:
    - The function does not explicitly check if `lst` is `NULL` (i.e., if the pointer to the list itself is invalid). In practice, you may want to add an additional check for `lst` to avoid potential segmentation faults.

---

### **Conclusion**:

`ft_lstadd_front` is a key function for linked lists in *Libft*. It allows you to efficiently add new nodes to the front of the list, with minimal overhead. This operation is especially useful in scenarios where order matters and you need to build a list from the front.

---