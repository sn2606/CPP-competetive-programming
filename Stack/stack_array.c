// Implementation of stack using arrays

#include <stdio.h>
#include <stdlib.h>
#define N 10

int top = -1;

int Is_empty(int arr[]);
int Is_full(int arr[], int len);
void Push(int arr[], int len);
void Pop(int arr[]);
void Display(int arr[]);

int main()
{
    int stack[N], status, option;

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
                {Push(stack, N);
                break;}
            case 2:
                {Pop(stack);
                break;}
            case 3:
                {Display(stack);
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

// Function to check if stack is empty
int Is_empty(int arr[N])
{
    if(top == -1)
    {
        return 1;
    }
    return 0;    
}

// Function to check if stack is full
int Is_full(int arr[N], int len)
{
    if(top == len-1)
    {
        return 1;
    }
    return 0;
}

// Function to push an element onto the stack
void Push(int arr[N], int len)
{
    int n, flag = 0;

    if(Is_full(arr, len) == 1)
    {
        printf("Stack Overflow! Cannot push any more values!\n");
        return;
    }
    else
    {
        printf("Enter the element you want to push: ");
        fflush(stdin);
        scanf("%d", &n);

        top += 1;
        arr[top] = n;
        flag = 1;
    }
    if(flag == 1)
    {
        printf("\n---- %d PUSHED INTO STACK ----\n", n);
    }    
}

// Function to pop element off the stack
void Pop(int arr[N])
{
    int flag = 0, temp;

    if(Is_empty(arr) == 1)
    {
        printf("\nStack Underflow! No elements to pop off the stack!\n");
        return;
    }
    else
    {
        temp = arr[top];
        arr[top] = '\0';
        top -= 1;
        flag = 1;
    }
    if(flag == 1)
    {
        printf("\n---- %d IS POPPED OFF ----\n", temp);
    }    
}

// Function to diaplay the stack elements
void Display(int arr[N])
{
    int i;

    printf("\n ------ STACK ------ \n");
    printf("|");
    for(i = 0; i <= top; i++)
    {
        printf(" %d|", arr[i]);
    }
    printf("\n\n");

}

