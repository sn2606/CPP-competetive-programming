// C program to implement singly linked list

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Defining the skeleton of the node

struct node
{
    int data;
    struct node *next;
};

struct list
{
    struct node *head;
    struct node *tail;
};

struct node *new_node, *temp, *prev_node, *next_node, *ptr;

void Initial_list(struct list *list_ptr);
struct node * create_node(int val);
void Insert_front(struct list *list_ptr);
void Insert_end(struct list *list_ptr);
void Insert_at_pos(struct list *list_ptr);
void Remove_front(struct list *list_ptr);
void Remove_end(struct list *list_ptr);
void Remove_at_pos(struct list *list_ptr);
void Sort_linked_list(struct list *list_ptr);
void Update_list_val(struct list *list_ptr);
void Search_elem(struct list *list_ptr);
void Display_list(struct list *list_ptr);

int main()
{
    int option, status;
    char ch;
    struct list *lp;
    lp = (struct list*)malloc(sizeof(struct list));
    Initial_list(lp);

    printf("\n------ SELECT THE OPERATION TO PERFORM ON THE SINGLY LINKED LIST ------\n");
    printf(" 1. Insert an element at the beginning of the list\n");
    printf(" 2. Insert an element at the end of the list\n");
    printf(" 3. Insert an element at a position of your choice\n");
    printf(" 4. Delete the first element from the list\n");
    printf(" 5. Delete the last element from the list\n");
    printf(" 6. Delete an element at position of your choice");
    printf(" 7. Sort the linked list\n");
    printf(" 8. Update the linked list\n");
    printf(" 9. Search an element in the list\n");
    printf("10. Display the linked list\n");

    do
    {
        printf("\nEnter the option: ");
        fflush(stdin);
        status = scanf("%d", &option);

        while(status == 0 || option > 10 || option < 1)
        {
            printf("Invalid option! Please enter a valid option: ");
            fflush(stdin);
            status = scanf("%d", &option);
        }

        switch(option)
        {
        case 1:
            Insert_front(lp);
            break;
        case 2:
            Insert_end(lp);
            break;
        case 3:
            Insert_at_pos(lp);
            break;
        case 4:
            Remove_front(lp);
            break;
        case 5:
            Remove_end(lp);
            break;
        case 6:
            Remove_at_pos(lp);
            break;
        case 7:
            Sort_linked_list(lp);
            break;
        case 8:
            Update_list_val(lp);
            break;
        case 9:
            Search_elem(lp);
            break;
        case 10:
            Display_list(lp);
            break;
        default:
            printf("Invalid option!");
            break;
        }

        printf("Do you want to continue? (y/n): ");
        fflush(stdin);
        scanf("%c", &ch);

    }while(ch != 'n' || ch != 'N');

    return 0;
}

// Initializing the list
void Initial_list(struct list *list_ptr)
{
    list_ptr->head = NULL;
    list_ptr->tail = NULL;
}

// Function to create a node
struct node * create_node(int val)
{
    // First allocate memory for the node
    // It should have size of node skeleton
    // Type casted because should have same type as new_node
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("\nMEMORY WAS NOT ALLOCATED.");
        return 0;
    }
    // Else store val in data
    // Assign null pointer to next
    else
    {
        new_node->data = val;
        new_node->next = NULL;
        return new_node;
    }
};

// Function to insert node at the beginning of the list
void Insert_front(struct list *list_ptr)
{
    int val;

    printf("\nEnter the value you want to insert: ");
    scanf("%d", &val);

    new_node = create_node(val);

    // If there is only one element in the list
    if(list_ptr->head == list_ptr->tail && list_ptr->tail == NULL)
    {
        list_ptr->head = new_node;
        list_ptr->tail = new_node;
        list_ptr->head->next = NULL;
        list_ptr->tail->next = NULL;
    }
    else
    {
        temp = list_ptr->head;
        list_ptr->head = new_node;
        new_node->next = temp;
        list_ptr->tail->next = NULL;
    }
    printf("\n---- Inserted ----\n");
}

// Function to print node at the end of the list
void Insert_end(struct list *list_ptr)
{
    int val;

    printf("\nEnter the element you want to insert: ");
    scanf("%d", &val);

    new_node = create_node(val);

    // If there is only one element in the list
    if(list_ptr->head == list_ptr->tail && list_ptr->tail == NULL)
    {
        list_ptr->head = new_node;
        list_ptr->tail = new_node;
        list_ptr->head->next = NULL;
        list_ptr->tail->next = NULL;
    }
    else
    {
        list_ptr->tail->next = new_node;
        list_ptr->tail = new_node;
        list_ptr->tail->next = NULL;
    }
    printf("\n---- Inserted ----\n");
}

// Function to insert at a position
void Insert_at_pos(struct list *list_ptr)
{
    int val, pos, count = 0, elems = 0, flag;

    printf("\nEnter the value you want to insert: ");
    fflush(stdin);
    scanf("%d", &val);

    ptr = list_ptr->head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
        elems++;
    }


    do
    {
        printf("\nEnter the position you want to insert the element at: ");
        fflush(stdin);
        scanf("%d", &pos);

        if(pos == 1)
        {
            // If there is only one element in the list
            if(list_ptr->head == list_ptr->tail && list_ptr->tail == NULL)
            {
                list_ptr->head = new_node;
                list_ptr->tail = new_node;
                list_ptr->head->next = NULL;
                list_ptr->tail->next = NULL;
            }
            else
            {
                temp = list_ptr->head;
                list_ptr->head = new_node;
                new_node->next = temp;
                list_ptr->tail->next = NULL;
            }
            printf("\n---- Inserted ----\n");
            flag = 1;
        }
        else if(pos > 1 && pos <= elems)
        {
            count = 0;
            prev_node = list_ptr->head;
            while(count < pos)
            {
                // We get the address of the node previous to inserted node
                prev_node = prev_node->next;
                count++;
            }
            next_node = prev_node->next;

            prev_node->next = new_node;
            new_node->next = next_node;

            printf("\n---- Inserted ----\n");
            flag = 1;
        }
        else
        {
            printf("\nPosition not available! Please enter a valid position!");
            flag = 0;
        }
    }while(flag == 0);
}

// Function to delete item at the beginning of the list
void Remove_front(struct list *list_ptr)
{
    if(list_ptr->head == NULL)
    {
        printf("\nList is Empty! No node to delete!");
    }
    else
    {
        temp = list_ptr->head;
        list_ptr->head = list_ptr->head->next;
        free(temp);
        printf("\n---- Deleted ----\n");
    }
}

// Function to delete item at the end of the list
void Remove_end(struct list *list_ptr)
{
    if(list_ptr->tail == NULL)
    {
        printf("\nList is Empty! No node to delete!");
    }
    else
    {
        prev_node = list_ptr->head;
        temp = list_ptr->tail;
        while(prev_node != list_ptr->tail)
        {
            prev_node = prev_node->next;
        }
        list_ptr->tail = prev_node;
        prev_node->next = NULL;
        free(temp);
        printf("\n ---- Deleted ----\n");
    }
}

// Function to remove at a given position
void Remove_at_pos(struct list *list_ptr)
{
    int count = 0, pos, elems = 0, flag;

    if(list_ptr->tail == NULL)
    {
        printf("\nList is Empty! No node to delete!");
        return 0;
    }

    ptr = list_ptr->head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
        elems++;
    }

    do
    {
        printf("\nEnter the position you want to delete elements from: ");
        fflush(stdin);
        scanf("%d", &pos);

        if(pos == 1)
        {
            temp = list_ptr->head;
            list_ptr->head = list_ptr->head->next;
            free(temp);
            printf("\n---- Deleted ----\n");
            flag = 1;
        }
        else if(pos > 1 && pos <= elems)
        {
            prev_node = list_ptr->head;
            for(count = 0; count < pos; count++)
            {
                prev_node = prev_node->next;
            }
            temp = prev_node->next;
            prev_node->next = temp->next;
            free(temp);
            printf("\n---- Deleted ----\n");
            flag = 1;
        }
        else
        {
            printf("\nPosition out of range! Please enter position between 1 and %d.", elems);
            flag = 0;
        }
    }while(flag == 0);
}

// Function to sort the linked list
void Sort_linked_list(struct list *list_ptr)
{
    struct node *atr;
    int t;

    if(list_ptr->tail == NULL)
    {
        printf("\nList is Empty! No nodes to sort!");
        return 0;
    }
    else
    {
        for(ptr = list_ptr->head; ptr != NULL; ptr = ptr->next)
        {
            for(atr = ptr->next; atr != NULL; atr = atr->next)
            {
                if(ptr->data > atr->data)
                {
                    t = ptr->data;
                    ptr->data = atr->data;
                    atr->data = t;
                }
            }
        }

        printf("\n------ SORTED LIST ------\n");
        for(ptr = list_ptr->head; ptr != NULL; ptr = ptr->next)
        {
            printf("| %d |", ptr->data);
        }
        printf("\n");
    }

}

// Updating nodes in a non-empty list
void Update_list_val(struct list *list_ptr)
{
    int old_value, new_value, flag;

    if(list_ptr->head == NULL)
    {
        printf("\nList is Empty! No values to update.\n");
        return 0;
    }
    else
    {
        printf("Enter the value you want to update: ");
        fflush(stdin);
        scanf("%d", &old_value);

        printf("Enter the value you want to update %d with: ", old_value);
        fflush(stdin);
        scanf("%d", &new_value);

        flag = 0;
        for(ptr = list_ptr->head; ptr != NULL; ptr = ptr->next)
        {
            if(ptr->data == old_value)
            {
                ptr->data = new_value;
                flag = 1;
            }
        }

        if(flag == 1)
        {
            printf("\nUpdated successfully!");
            printf("\n------ UPDATED LIST ------\n");
            for(ptr = list_ptr->head; ptr != NULL; ptr = ptr->next)
            {
                printf("| %d |", ptr->data);
            }
            printf("\n");
        }
        else
        {
            printf("\n%d not found in the list.", old_value);
        }
    }
}

// Function to search for element in a list
void Search_elem(struct list *list_ptr)
{
    int flag, pos = 1, key;

    if(list_ptr->head == NULL)
    {
        printf("\nList is Empty! No values to search for.\n");
        return 0;
    }
    else
    {
        printf("Enter the value you want to search: ");
        fflush(stdin);
        scanf("%d", &key);

        flag = 0;
        for(ptr = list_ptr->head; ptr != NULL; ptr = ptr->next, pos++)
        {
            if(ptr->data == key)
            {
                flag = 1;
            }
            if(flag == 1)
            {
                printf("\nElement %d found at position %d.", key, pos);
            }
        }

        if(flag == 0)
        {
            printf("\nElement not found!\n");
        }
    }
}

// Function to print list from beginning to end
void Display_list(struct list *list_ptr)
{
    if(list_ptr->head == NULL)
    {
        printf("\nList is Empty! No values to display.\n\n");
        return 0;
    }
    else
    {
        printf("\n------ DISPLAYING THE LIST ------\n");
        for(ptr = list_ptr->head; ptr != NULL; ptr = ptr->next)
        {
            printf("| %d |", ptr->data);
        }
        printf("\n\n");
    }
}
