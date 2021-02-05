// Implement stack with pointers (linked list implementation)

#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *new_node;

// The only thing we need to keep track of in the stack is the top node
// Top of stack will be the first node of the linked structure
struct stack
{
    struct node *top;
};

// Prototyping functions
struct node *create_node(int val);
void initial_stack(struct stack *stk_ptr);
int is_empty(struct stack *stk_ptr);
struct stack *push(struct stack *stk_ptr);
struct stack *pop(struct stack *stk_ptr);
void display(struct stack *stk_ptr);

// Main function
int main()
{
    int option, status;
    struct stack *S;
    S = (struct stack *)malloc(sizeof(struct stack));
    initial_stack(S);

    printf("\n ------- ARRAY IMPLEMENTATION OF STACK ------- \n");
    printf("Select an option among the following to perform an operation on the stack: \n");
    printf("1. Push an element into the stack\n");
    printf("2. Pop an element off of the stack\n");
    printf("3. Display the stack\n");
    printf("4. Exit the program\n\n");

    do{
        printf("Enter the option: ");
        status = scanf("%d", &option);

        while(status == 0 || option < 1 || option > 4)
        {
            printf("\nInvalid option! Please enter a valid option: ");
            fflush(stdin);
            status = scanf("%d", &option);
        }

        switch(option)
        {
        case 1:
            S = push(S);
            break;
        case 2:
            S = pop(S);
            break;
        case 3:
            display(S);
            break;
        case 4:
            printf("\n.... Exiting program\n");
            break;
        default:
            break;
        }
    }while(option != 4);

    return 0;
}

// Function to create a node
struct node *create_node(int val)
{
    new_node = (struct node*)malloc(sizeof(struct node));

    if(new_node == NULL)
    {
        printf("\nMemory Exhausted.\n");
    }
    else
    {
        new_node->data = val;
        new_node->next = NULL;
    }

    return new_node;
}

// Function to initialize stack
void initial_stack(struct stack *stk_ptr)
{
    stk_ptr->top = NULL;
};

// Push function
struct stack *push(struct stack *stk_ptr)
{
    int val;
    struct node *temp = NULL;
    temp = (struct node*)malloc(sizeof(struct node));

    fflush(stdin);
    printf("\nEnter the value you want to push into the stack: ");
    scanf("%d", &val);

    new_node = create_node(val);

    temp = stk_ptr->top;
    stk_ptr->top = new_node;
    new_node->next = temp;
    printf("\n ----- %d PUSHED INTO THE STACK ----- \n\n", val);
    return stk_ptr;
}

// Pop function
struct stack *pop(struct stack *stk_ptr)
{
    struct node *temp;

    if(stk_ptr->top == NULL)
    {
        printf("\nStack Underflow: No element to pop off!\n\n");
    }
    else
    {
        temp = stk_ptr->top;
        stk_ptr->top = stk_ptr->top->next;
        printf("\n----- %d POPPED OFF FROM THE STACK -----\n\n", temp->data);
        free(temp);
    }
    return stk_ptr;
}

// Display function
void display(struct stack *stk_ptr)
{
    struct node *ptr;

    if(stk_ptr->top == NULL)
    {
        printf("\nStack is empty! No elements to display!\n\n");
        return;
    }
    else
    {
        printf("|");
        for(ptr = stk_ptr->top; ptr != NULL; ptr = ptr->next)
        {
            printf(" %d|", ptr->data);
        }
        printf("\n\n");
    }

}
