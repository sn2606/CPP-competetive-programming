// C program to implement linked binary tree
// and traversal - inorder, preorder, postorder
// assuming that all insertions made in the tree are distinct

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>


struct treenode
{
    int data;
    struct treenode *right;
    struct treenode *left;
};

struct tree
{
    struct treenode *root;
};

struct treenode *create_node(int val);
struct tree *create_tree(struct tree *t);
int is_empty(struct tree *t);
struct treenode *search_val(struct treenode *n, int val);
struct treenode *search_parent(struct treenode *n, struct treenode *ptr);
void insert_node(struct tree *t);
void delete_node(struct tree *t);
void preorder(struct tree *t, struct treenode *n);
void inorder(struct tree *t, struct treenode *n);
void postorder(struct tree *t, struct treenode *n);

int main()
{
    struct tree *Tree = create_tree(Tree);
    int option, status;
    char c;

    printf("Select an operation from the tree:\n");
    printf("1. Insert a node in the tree\n");
    printf("2. Delete a node from the tree\n");
    printf("3. Display the tree: Preorder traversal\n");
    printf("4. Display the tree: Inorder traversal\n");
    printf("5. Display the tree: Postorder traversal\n");
    printf("\n");
    fflush(stdin);

    do{
        
        printf("Enter an option: ");
        status = scanf("%d", &option);
        fflush(stdin);

        while(status == 0 || option < 1 || option > 5)
        {
            printf("\nINVALID INPUT!\n");
            printf("Enter a valid option: ");
            status = scanf("%d", &option);
            fflush(stdin);
        }
        
        switch(option)
        {
            case 1:
            {
                insert_node(Tree);
                break;
            }
            case 2:
            {
                delete_node(Tree);
                break;
            }
            case 3:
            {
                preorder(Tree, Tree->root);
                break;
            }
            case 4:
            {
                inorder(Tree, Tree->root);
                break;
            }
            case 5:
            {
                postorder(Tree, Tree->root);
                break;
            }
            default:
                break;
        }
        printf("\nDo you want to continue?[y/n]: ");
        scanf("%c", &c);
        c = tolower(c);
        fflush(stdin);
    }while(c == 'y');

    return 0;
}

// Function to create a node in the tree
struct treenode *create_node(int val)
{
    struct treenode *new_node = (struct treenode *)malloc(sizeof(struct treenode));
    new_node->data = val;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}

// Function to initialize the tree
struct tree *create_tree(struct tree *t)
{
    t = (struct tree *)malloc(sizeof(struct tree));
    t->root = NULL;
    return t;
}

// Function to check if the tree is empty
int is_empty(struct tree *t)
{
    return t->root == NULL;
}

// Function to search a value in a node
struct treenode *search_val(struct treenode *n, int val)
{
    struct treenode *ptr = (struct treenode *)malloc(sizeof(struct treenode));
    ptr = n;

    if(ptr->data != val)
    {
        if(ptr->left != NULL)
        {
            search_val(ptr->left, val);
        }
        else
        {
            return NULL;
        }
        if(ptr->right != NULL)
        {
            search_val(ptr->right, val);
        }
        else
        {
            return NULL;
        }
        
    }
    else
    {
        return ptr;
    }        
}

// Function to search parent of a node
struct treenode *search_parent(struct treenode *n, struct treenode *ptr)
{
    struct treenode *parent = (struct treenode *)malloc(sizeof(struct treenode)),
    *ptr1 = (struct treenode *)malloc(sizeof(struct treenode)),
    *ptr2 = (struct treenode *)malloc(sizeof(struct treenode));
    parent = n;

    if(parent->left != ptr && parent->right != ptr)
    {
        ptr1 = parent->left;
        ptr2 = parent->right;

        if(ptr1 != NULL)
        {
            search_parent(ptr1, ptr);
        }
        else
        {
            parent = NULL;
        }       

        if(ptr2 != NULL)
        {
            search_parent(ptr2, ptr);
        } 
        else
        {
            parent = NULL;
        }      
    }

    return parent;
}


// Function to insert a node in the tree
void insert_node(struct tree *t)
{
    int val, status1, status2, key, option;
    struct treenode *ptr = (struct treenode *)malloc(sizeof(struct treenode)), 
    *key_ptr = (struct treenode *)malloc(sizeof(struct treenode)),
    *r, *new;

    if(is_empty(t))
    {
        printf("\nEnter the number to be entered in root node: ");
        status1 = scanf("%d", &val);
        fflush(stdin);

        while(status1 == 0)
        {
            printf("Invalid input! Please enter a positive integer value: ");
            status1 = scanf("%d", val);
            fflush(stdin);
        }

        r = create_node(val);
        t->root = r;
        r->left = NULL;
        r->right = NULL;        
    }
    else
    {
        printf("\nPlease enter the node value where you want to insert the child: ");
        status1 = scanf("%d", &key);
        fflush(stdin);

        printf("Please enter a value to insert as child node (Disctinct from previous values): ");
        status2 = scanf("%d", &val);
        fflush(stdin);

        while(status1 == 0 || status2 == 0)
        {
            printf("Invalid input!\n");
            printf("Please enter the node value where you want to insert the child: ");
            status1 = scanf("%d", &key);
            fflush(stdin);

            printf("Please enter a value to insert as child node (Disctinct from previous values): ");
            status2 = scanf("%d", &val);
            fflush(stdin);
        }

        ptr = search_val(t->root, key);
        key_ptr = search_val(t->root, val);

        while(key_ptr != NULL || ptr == NULL)
        {
            printf("Invalid input!\n");
            printf("Either key node does not exist or the value you want to insert already exists\n");
            printf("Please enter the node value where you want to insert the child: ");
            status1 = scanf("%d", &key);
            fflush(stdin);

            printf("Please enter a value to insert as child node (Disctinct from previous values): ");
            status2 = scanf("%d", &val);
            fflush(stdin);

            while(status1 == 0 || status2 == 0)
            {
                printf("Invalid input!\n");
                printf("Please enter the node value where you want to insert the child: ");
                status1 = scanf("%d", &key);
                fflush(stdin);

                printf("Please enter a value to insert as child node (Disctinct from previous values): ");
                status2 = scanf("%d", &val);
                fflush(stdin);
            }

            ptr = search_val(t->root, key);
            key_ptr = search_val(t->root, val);
        }

        if(ptr->left == NULL || ptr->right == NULL)
        {
            printf("\nChoose the option:\n1. Insert as left child\n2. Insert as right child\n\n");
            printf("\nEnter the option: ");
            status1 = scanf("%d", &option);
            fflush(stdin);

            while(status1 == 0 || (option != 1 && option != 2))
            {
                printf("Invalid option!\nEnter a valid option: ");
                status1 = scanf("%d", &option);
                fflush(stdin);
            }

            switch(option)
            {
                case 1:
                {
                    if(ptr->left == NULL)
                    {
                        new = create_node(val);
                        ptr->left = new;
                    }
                    else
                    {
                        printf("\nInsertion not possible, node already has a left child.\n");
                    }
                    break;                    
                }
                case 2:
                {
                    if(ptr->right == NULL)
                    {
                        new = create_node(val);
                        ptr->right = new;
                    }
                    else
                    {
                        printf("\nInsertion not possible, node already has a right child.\n");
                    }   
                    break;
                }
                default:
                    break;
            }// Switch statement ends here
        }// If coldition ends here
        else
        {
            printf("\nInsertion not possible, node already has left and right children.\n");
        }// if-else ends here       

    }// Big if-else ends here
}

// Function to delete a node from a tree
void delete_node(struct tree *t)
{
    int val, status;
    struct treenode *ptr = (struct treenode *)malloc(sizeof(struct treenode)), 
    *val_ptr = (struct treenode *)malloc(sizeof(struct treenode)),
    *parent_ptr = (struct treenode *)malloc(sizeof(struct treenode));
    
    if(is_empty(t))
    {
        printf("\nDeletetion not possible as tree is empty.\n\n");
    }
    else
    {
        printf("\nEnter the value you want to delete: ");
        status = scanf("%d", &val);
        fflush(stdin);

        while(status == 0)
        {
            printf("\nInvalid input! Please enter an integer: ");
            status = scanf("%d", &val);
            fflush(stdin);
        }

        ptr = search_val(t->root, val);

        if(ptr == NULL)
        {
            printf("\nError! The value you want to delete does not exist in the tree!\n\n");
        }
        else
        {
            parent_ptr = search_parent(t->root, ptr);
            if(parent_ptr->left == ptr)
            {
                parent_ptr->left = NULL;
                free(ptr);
            }
            else if(parent_ptr->right == ptr)
            {
                parent_ptr->right = NULL;
                free(ptr);
            }
        }
    }
}

// Function to implement preorder traversal
void preorder(struct tree *t, struct treenode *n)
{
    struct treenode *ptr = (struct treenode *)malloc(sizeof(struct treenode));
    ptr = n;

    if(is_empty(t))
    {
        printf("\nTree is empty!\n");
    }
    else
    {
        if(ptr != NULL)
        {
            printf("%d  ", ptr->data);
            preorder(t, ptr->left);
            preorder(t, ptr->right);
        }
    }   
}

// Function to implement inorder traversal
void inorder(struct tree *t, struct treenode *n)
{
    struct treenode *ptr = (struct treenode *)malloc(sizeof(struct treenode));
    ptr = n;

    if(is_empty(t))
    {
        printf("\nTree is empty!\n");
    }
    else
    {
        if(ptr != NULL)
        {
            inorder(t, ptr->left);
            printf("%d  ", ptr->data);
            inorder(t, ptr->right);
        }
    }
}

// Function to implement postorder traversal
void postorder(struct tree *t, struct treenode *n)
{
    struct treenode *ptr = (struct treenode *)malloc(sizeof(struct treenode));
    ptr = n;

    if(is_empty(t))
    {
        printf("\nTree is empty!\n");
    }
    else
    {
        if(ptr != NULL)
        {
            postorder(t, ptr->left);
            postorder(t, ptr->right);
            printf("%d  ", ptr->data);
        }
    }
}