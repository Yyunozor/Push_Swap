# **Linked Lists: Data Structures**

### **What is a Linked List?**

A **linked list** is a collection of nodes, where each node holds two things:

1. **Data**: The information you want to store.
2. **A Reference to the Next Node**: A pointer linking the node to the next one in the list.

In contrast to arrays, linked lists don’t store elements in contiguous memory locations. Instead, each element points to the next one, forming a chain, or list. This dynamic nature allows flexible memory management and efficient insertion and deletion operations.

---

### **How Linked Lists Work**

Each node in a linked list is connected via a pointer to the next node. If you want to move through a list, you begin at the *head* (the first node) and traverse each node using the pointer to reach the next one.

Here’s a basic visual of a **singly linked list** with three nodes:

```css
[Data | Next] -> [Data | Next] -> [Data | NULL]

```

- The **first node** points to the second.
- The **second node** points to the third.
- The **third node** points to `NULL` (signifying the end of the list).

---

### **Nodes in C: The Structure**

In C, we represent a node of a linked list as a `struct`. For *Libft*, we use the following structure:

```c
typedef struct s_list
{
    void *content;        // Data of the node
    struct s_list *next;  // Pointer to the next node
} t_list;

```

- **content** holds the data (void pointer to make it flexible).
- **next** is the pointer that links this node to the next one in the list.

---

### **Creating a Linked List Node**

Let’s create a function that initializes a new node. This node will contain some data and a `NULL` pointer (as it’s the only node initially).

```c
t_list *ft_lstnew(void *content)
{
    t_list *new_node;

    new_node = (t_list *)malloc(sizeof(t_list)); // Allocate memory for new node
    if (!new_node)
        return (NULL);  // Memory allocation failed
    new_node->content = content;  // Assign content
    new_node->next = NULL;        // This is the last node, so next points to NULL
    return (new_node);
}

```

### **Visual Representation of a Single Node**:

Let’s say you create a node with the content `42`:

```arduino
[42 | NULL]

```

This is a single node with `42` as its data and `NULL` as its next pointer, indicating it's the last in the list (or the only one for now).

---

### **Building a Chain of Nodes**

To create a linked list, you must link multiple nodes together. Let’s add nodes one by one to form a chain.

Here’s an example where we add three nodes with data `42`, `21`, and `84`.

```c
int main()
{
    t_list *head = ft_lstnew((void *)42);  // First node (head of the list)
    head->next = ft_lstnew((void *)21);    // Second node
    head->next->next = ft_lstnew((void *)84);  // Third node
}

```

### **Visual Representation**:

After adding three nodes, the list looks like this:

```css
[42 | Next] -> [21 | Next] -> [84 | NULL]

```

Each node contains data and points to the next one. The last node points to `NULL`, marking the end of the list.

---

### **Advantages of Linked Lists**

1. **Dynamic Memory Usage**: Linked lists do not require a fixed size, unlike arrays, which are allocated with a fixed amount of memory. Nodes can be created as needed.
2. **Efficient Insertions/Deletions**: You can insert or delete a node anywhere in the list without having to shift other elements around (as you would in an array).

---

### **Basic Linked List Operations**

Let’s cover the essential operations in a linked list: traversal, insertion, and deletion.

### **1. Traversing a Linked List**

To traverse a linked list, start at the head and move from node to node using the `next` pointer until you reach `NULL`.

```c
void print_list(t_list *head)
{
    t_list *current = head;
    while (current != NULL)
    {
        printf("%d -> ", (int)current->content);  // Casting content to int for simplicity
        current = current->next;  // Move to the next node
    }
    printf("NULL\n");
}

```

### **Visual Example**:

If the list contains `42 -> 21 -> 84`, the traversal output would look like:

```rust
42 -> 21 -> 84 -> NULL

```

---

### **2. Inserting into a Linked List**

Inserting at the **beginning** is particularly efficient, as no other nodes need to be modified.

```c
void ft_lstadd_front(t_list **head, t_list *new_node)
{
    new_node->next = *head;  // New node points to the current head
    *head = new_node;        // Head now becomes the new node
}

```

### **Example**:

If we insert `99` at the front of our list, the result will be:

```css
[99 | Next] -> [42 | Next] -> [21 | Next] -> [84 | NULL]

```

The new node with `99` becomes the head of the list, and it points to the previous first node.

---

### **3. Deleting a Node**

Let’s say you want to delete a node with a specific value (e.g., `21`). The key is to adjust the `next` pointer of the preceding node to skip the node you’re removing.

```c
void ft_lstdelone(t_list **head, void *value)
{
    t_list *temp = *head, *prev = NULL;

    while (temp != NULL && temp->content != value) {
        prev = temp;            // Store previous node
        temp = temp->next;      // Move to the next node
    }

    if (temp == NULL) return;  // Node not found

    if (prev == NULL) {
        *head = temp->next;     // Node to be deleted is the head
    } else {
        prev->next = temp->next;  // Skip the node to be deleted
    }

    free(temp);  // Free the memory
}

```

---

### **Comparison with Arrays**

| Feature | Linked List | Array |
| --- | --- | --- |
| **Memory Allocation** | Dynamic (grows/shrinks) | Static (fixed size) |
| **Insertion/Deletion** | Efficient (no shifting) | Expensive (requires shifting) |
| **Access Time** | O(n) (must traverse) | O(1) (random access) |
| **Flexibility** | High | Low |

---

### **Visual Summary**:

Here’s a quick visual summary of the core concepts:

```less
Creating a Linked List:

[Node 1] -> [Node 2] -> [Node 3] -> NULL
  42          21          84

Inserting at the Beginning:

[New Node] -> [Node 1] -> [Node 2] -> [Node 3] -> NULL
   99           42          21          84

```

---

### **Key Takeaways**:

- **Dynamic**: Linked lists grow and shrink as needed.
- **Efficient Modifications**: Insertion and deletion are faster than arrays, especially at the beginning or middle of the list.
- **Traversal Required**: Accessing an element requires starting from the head and following each node's pointer.

---
