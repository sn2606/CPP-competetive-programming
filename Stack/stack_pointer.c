# include<stdio.h>
# include<malloc.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *top_ptr);
struct node *push(struct node *top_ptr);
struct node *pop(struct node *top_ptr);

int main()
{
    struct node *top = NULL;
    int status, option;

    printf("\n ------- ARRAY IMPLEMENTATION OF STACK ------- \n");
    printf("Select an option among the following to perform an operation on the stack: \n");
    printf("1. Push an element into the stack\n");
    printf("2. Pop an element off of the stack\n");
    printf("3. Display the stack\n");
    printf("4. Exit the program\n\n");

    do{    
        printf("Enter the option: ");
        fflush(stdin);
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
                {top = push(top);
                break;}
            case 2:
                {top = pop(top);
                break;}
            case 3:
                {display(top);
                break;}
            case 4:
                {printf("\n.... Exiting program\n");
                break;}
            default:         
                {break;}
        }
    }while(option != 4);

    return 0;
}


void display(struct node *top_ptr)
{
    printf("\n----- DISPLAYING THE STACK -----\n\n");
    printf("|");
    while(top_ptr != NULL)
    {
        printf(" %d |",top_ptr->data);
        top_ptr = top_ptr->next;
    }
    printf("\n\n");
}

struct node * push(struct node *top_ptr)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    
    printf("Input the value to be pushed the stack: ");
    scanf("%d", &new_node->data);

    new_node->next = top_ptr;
    top_ptr = new_node;

    printf("\n------- ELEMENT PUSHED -------\n\n");

    return(top_ptr);
}

struct node * pop(struct node *top_ptr)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    if(top_ptr == NULL)
    {
        printf("\nStack Underflow! Stack is empty\n");
    }
    else
    {
        temp = top_ptr->next;
        free(top_ptr);
        top_ptr = temp;
        
        printf("\nAfter pop operation the stack is as follows:\n");
        display(top_ptr);
        
        if(top_ptr  == NULL)
            printf("\n Stack is empty");
    }
    return(top_ptr);
}