# **`ft_lstmap`**

### **Purpose**:

The `ft_lstmap` function generates a new list by applying a given function (`f`) to the content of each node in an existing list (`lst`). It returns a pointer to the new list. If any memory allocation fails during the process, it frees all allocated nodes to prevent memory leaks.

---

### **Prototype**:

```c
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

```

- **Parameters**:
    - `lst`: A pointer to the first node in the list to be transformed.
    - `f`: A function applied to the content of each node, returning a new transformed value.
    - `del`: A function to free the content of a node in case of an error.
- **Return Value**:
    - Returns a new list where each node’s content is the result of applying `f` to the corresponding node in the original list.
    - Returns `NULL` if any memory allocation fails.

---

### **Code Implementation**:

```c
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = NULL;
	while (lst && f)
	{
		new_content = f(lst->content);
		if (!new_content)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

```

---

### **Explanation**:

1. **Initialization**:
    - `new_list` is initialized to `NULL` to create an empty list. The function iterates through the input list (`lst`) and applies the function `f` to each element.
2. **Content Transformation**:
    - The function `f` is applied to the `content` of the current node (`lst->content`), producing `new_content`.
    - If `f` fails and returns `NULL`, the function immediately clears any nodes created in `new_list` using `ft_lstclear` and returns `NULL` to indicate failure.
3. **Node Creation**:
    - A new node is created using `ft_lstnew(new_content)`. If this fails (i.e., `new_node` is `NULL`), the content is freed using `del`, and the entire `new_list` is cleared with `ft_lstclear`.
4. **Adding New Node to the List**:
    - The newly created node is added to the end of `new_list` using `ft_lstadd_back`, maintaining the order of nodes from the original list.
5. **Returning the New List**:
    - If all nodes are processed successfully, the function returns `new_list`.
    - If any error occurs, it returns `NULL` after clearing `new_list`.

---

### **Edge Cases**:

1. **Empty List (`lst == NULL`)**:
    - The function returns `NULL` if the input list is empty, as there is nothing to map.
2. **Memory Allocation Failure**:
    - If any memory allocation fails (either while transforming content or creating a new node), the function ensures all allocated nodes in `new_list` are cleared to avoid memory leaks.
3. **Null Function (`f == NULL`)**:
    - If `f` is `NULL`, no transformation can occur, and the function returns `NULL`.

---

### **Complexity Analysis**:

- **Time Complexity**: O(n), where `n` is the number of nodes in the input list. Each node is processed once.
- **Space Complexity**: O(n) for the new list and O(1) for auxiliary space.

---

### **Testing the Implementation**:

To demonstrate the function's usage, here is a sample test case:

```c
#include "libft.h"#include <stdio.h>#include <stdlib.h>

void	*transform_content(void *content)
{
	char	*str = (char *)content;
	return (ft_strdup(str)); // Duplicates the string content
}

// Example function to delete content
void	delete_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*list = ft_lstnew(ft_strdup("Node 1"));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("Node 2")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("Node 3")));

	t_list	*new_list = ft_lstmap(list, transform_content, delete_content);
	if (!new_list)
		printf("Failed to map the list\n");
	else
	{
		t_list	*temp = new_list;
		while (temp)
		{
			printf("Content: %s\n", (char *)temp->content);
			temp = temp->next;
		}
	}

	ft_lstclear(&list, delete_content);
	ft_lstclear(&new_list, delete_content);
	return (0);
}

```

**Expected Output**:

```less
Content: Node 1
Content: Node 2
Content: Node 3

```

### **Conclusion**:

The **`ft_lstmap`** function provides a reliable way to apply transformations to each node in a linked list while ensuring memory is managed correctly, even if an error occurs. This function is highly flexible, allowing you to apply custom transformations and cleanup procedures for any linked list application.

---

# MORE!!!

# **`ft_lstmap`**

## **Purpose**

The `ft_lstmap` function is a powerful tool for creating a transformed linked list. It applies a specified transformation function (`f`) to each element of an existing list and returns a new list with the transformed nodes. The function carefully handles memory to prevent leaks if any transformation or allocation fails.

---

## **Prototype**

```c
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

```

- **Parameters:**
    - `lst`: A pointer to the first node of the original list.
    - `f`: A function applied to each node's content, returning a new transformed value.
    - `del`: A function used to free a node's content if memory allocation fails.
- **Return Value:**
    - Returns a pointer to the new list where each node's content has been transformed by `f`.
    - Returns `NULL` if memory allocation fails.

---

## **How It Works: Step-by-Step**

### 1. **Initialization**

At the beginning, the function initializes `new_list` to `NULL`, creating an empty list to hold the transformed nodes:

```c
t_list	*new_list = NULL;

```

### 2. **Looping Through the List**

The function uses a `while` loop to go through each node in the original list (`lst`). If either `lst` or `f` is `NULL`, the function immediately exits without processing any nodes.

```c
while (lst && f)

```

### 3. **Applying the Transformation Function `f`**

Within each loop iteration, `f` is applied to the content of the current node (`lst->content`), producing `new_content`.

```c
new_content = f(lst->content);

```

### **Visual Example of Transformation Function `f`**

Let’s say `f` duplicates each string content. If our original list has `Node 1 -> Node 2 -> Node 3`, applying `f` would duplicate these strings for use in the new list.

| Original Node Content | Transformed Content (by `f`) |
| --- | --- |
| `"Node 1"` | `"Node 1"` (duplicate) |
| `"Node 2"` | `"Node 2"` (duplicate) |
| `"Node 3"` | `"Node 3"` (duplicate) |

### 4. **Handling Transformation Failures**

If `f` fails and `new_content` is `NULL`, the function calls `ft_lstclear` to free all previously allocated nodes in `new_list` and returns `NULL`, ensuring no memory leaks.

```c
if (!new_content)
{
	ft_lstclear(&new_list, del);
	return (NULL);
}

```

### 5. **Creating a New Node with `ft_lstnew`**

If `new_content` is valid, the function creates a new node using `ft_lstnew(new_content)`. This new node will hold the transformed content.

```c
new_node = ft_lstnew(new_content);

```

### **Visual Representation of Adding Nodes**

Here’s how nodes are added to `new_list` as `ft_lstmap` processes each original node:

```
Original list:   [Node 1] -> [Node 2] -> [Node 3]

```

| Step | Action | `new_list` Structure |
| --- | --- | --- |
| 1 | Add transformed `"Node 1"` | [Node 1 (dup)] |
| 2 | Add transformed `"Node 2"` | [Node 1 (dup)] -> [Node 2 (dup)] |
| 3 | Add transformed `"Node 3"` | [Node 1 (dup)] -> [Node 2 (dup)] -> [Node 3 (dup)] |

### 6. **Handling Node Creation Failures**

If `ft_lstnew` fails (returns `NULL`), it frees the new content with `del` and clears all nodes created so far in `new_list`.

```c
if (!new_node)
{
	del(new_content);
	ft_lstclear(&new_list, del);
	return (NULL);
}

```

This ensures that all allocated memory is freed if an error occurs.

### 7. **Adding the New Node to the New List**

If the new node is successfully created, it’s added to the end of `new_list` with `ft_lstadd_back`.

```c
ft_lstadd_back(&new_list, new_node);

```

### 8. **Moving to the Next Node**

The function then moves to the next node in the original list (`lst = lst->next`) and continues the process.

```c
lst = lst->next;

```

### **Final Output**

After processing all nodes, `ft_lstmap` returns the head of `new_list`. The original list remains unchanged, but we now have a new list where each node contains transformed content.

---

## **Complete Example**

Let’s say our original list is `[ "Node 1" -> "Node 2" -> "Node 3" ]` and the function `f` simply duplicates each string.

```c
t_list	*list = ft_lstnew(ft_strdup("Node 1"));
ft_lstadd_back(&list, ft_lstnew(ft_strdup("Node 2")));
ft_lstadd_back(&list, ft_lstnew(ft_strdup("Node 3")));

t_list	*new_list = ft_lstmap(list, &ft_strdup, &free);

```

- **Original List**: `[ "Node 1" -> "Node 2" -> "Node 3" ]`
- **Transformed List (New List)**: `[ "Node 1" (dup) -> "Node 2" (dup) -> "Node 3" (dup) ]`

If any memory allocation fails during the transformation, `ft_lstmap` ensures that all allocated memory is freed, and it returns `NULL`.

---

## **Edge Cases**

1. **Empty List (`lst == NULL`)**:
    - Returns `NULL` as there is no content to map.
2. **Null Transformation Function (`f == NULL`)**:
    - No transformations can be applied, so the function returns `NULL`.
3. **Memory Allocation Failure**:
    - If `f` or `ft_lstnew` fails at any point, the function clears all allocated nodes in `new_list` to avoid memory leaks.

---

## **Diagram Summary**

Here’s a step-by-step illustration:

```
Original list:       [ "Node 1" ] -> [ "Node 2" ] -> [ "Node 3" ]

1. Apply `f` to Node 1 -> Duplicate "Node 1" -> Add to `new_list`
   new_list:          [ "Node 1" (dup) ]

2. Apply `f` to Node 2 -> Duplicate "Node 2" -> Add to `new_list`
   new_list:          [ "Node 1" (dup) ] -> [ "Node 2" (dup) ]

3. Apply `f` to Node 3 -> Duplicate "Node 3" -> Add to `new_list`
   new_list:          [ "Node 1" (dup) ] -> [ "Node 2" (dup) ] -> [ "Node 3" (dup) ]

```

If any transformation or node creation fails, `ft_lstclear` frees all nodes in `new_list`, ensuring no memory is leaked.

---

### **Conclusion**

`ft_lstmap` is an efficient way to create a transformed copy of a linked list in C, with strong error-handling to manage memory properly. This function can be extended to perform various transformations by passing different functions for `f` and `del`, making it a versatile tool for list manipulation.

---