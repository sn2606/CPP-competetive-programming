// C program implementation of depth first search
# include <stdio.h>
# include <stdlib.h>
# define N 10

// Structure to represent adjacency list node
struct node
{
    int weight;
    int vertex;
    struct node * next;
};

// Structure to represent adjacency list
struct adj_list
{
    struct node *head;
    struct node *tail;
};

// Structure to represent graph
struct graph
{
    int vertices;
    struct adj_list *array;
};

struct visited_stack
{
    struct node *top;
}*Visited;

struct node * create_node(int wt, int val);
struct graph * create_graph(int no_of_vertices);
void add_edge_directed(struct graph * Graph, int src, int dest, int weit);
void print_graph(struct graph *Graph);
void add_edge_undirected(struct graph *Graph, int src, int dest, int weit);
void delete_edge_directed(struct graph *Graph, int src, int dest);
void delete_edge_undirected(struct graph *Graph, int src, int dest);
int *DFS(struct graph *Graph, int vertex, int n, int *);
int is_visited(int arr[N], int val, int n);
struct node * push(struct node *top_ptr, int val);
int pop(struct visited_stack *visi);

int main()
{
    struct graph *Graph;
    int i, j, n, status, flag, option, op, *dfs, start;
    int source, desti, wt;
    char ch;
    int adjacency[N][N];

    printf("\nEnter the number of vertices in the graph: ");
    status = scanf("%d", &n);
    fflush(stdin);

    while (status == 0 || N > 10)
    {
        printf("Invalid Input!\n");
        printf("\nEnter the number of vertices in the graph: ");
        status = scanf("%d", &n);
        fflush(stdin);
    }
    

    Graph = create_graph(n);
    dfs = (int *)malloc(N * sizeof(int));

    printf("\nIs the graph directed or undirected?\n1. Directed\n2. Undirected\n");

    printf("Enter the option: ");
    status = scanf("%d", &op);
    fflush(stdin);

    while(status == 0 || op > 2 || op < 1)
    {
        printf("Invalid entry!\n");
        printf("Enter the option: ");
        status = scanf("%d", &op);
        fflush(stdin);
    }


    printf("Choose an option:\n1. Add edge\n2. Delete Edge\n3. Display graph\n4. DFS\n5. Exit\n\n");

    
    do
    {
        printf("Enter the option: ");
        status = scanf("%d", &option);
        fflush(stdin);

        while(status == 0 || option > 5 || option < 1)
        {
            printf("Invalid entry!\n");
            printf("Enter the option: ");
            status = scanf("%d", &option);
            fflush(stdin);
        }
        
        switch (option)
        {
        case 1:
            printf("Enter the source node: ");
            status = scanf("%d", &source);
            fflush(stdin);
            while (status == 0 || source < 0 || source > N)
            {
                printf("Invalid! Enter the source node: ");
                status = scanf("%d", &source);
                fflush(stdin);
            }

            printf("Enter the distination node: ");
            status = scanf("%d", &desti);
            fflush(stdin);
            while (status == 0 || desti < 0 || desti > N || desti == source)
            {
                printf("Invalid! Enter the destination node: ");
                status = scanf("%d", &desti);
                fflush(stdin);
            }
            
            printf("Enter the weight: ");
            status = scanf("%d", &wt);
            fflush(stdin);
            while (status == 0 || wt < 0)
            {
                printf("Invalid! Enter the weight: ");
                status = scanf("%d", &wt);
                fflush(stdin);
            }

            if(op == 1)
                add_edge_directed(Graph, source, desti, wt);
            else if (op == 2)
            {
                add_edge_undirected(Graph, source, desti, wt);
            }           

            break;

        case 2:
            printf("Enter the source node: ");
            status = scanf("%d", &source);
            fflush(stdin);
            while (status == 0 || source < 0 || source > N)
            {
                printf("Invalid! Enter the source node: ");
                status = scanf("%d", &source);
                fflush(stdin);
            }

            printf("Enter the distination node: ");
            status = scanf("%d", &desti);
            fflush(stdin);
            while (status == 0 || desti < 0 || desti > N || desti == source)
            {
                printf("Invalid! Enter the destination node: ");
                status = scanf("%d", &desti);
                fflush(stdin);
            }
            
            if(op == 1)
                delete_edge_directed(Graph, source, desti);
            else if (op == 2)
            {
                delete_edge_undirected(Graph, source, desti);
            }
            break;

        case 3:
            print_graph(Graph);
            break;

        case 4:
            printf("Enter the starting vertex: ");
            status = scanf("%d", &start);
            fflush(stdin);

            while(status == 0 || start < 0 || start > n || Graph->array[start].head == NULL)
            {
                printf("Invalid! Enter the starting vertex: ");
                status = scanf("%d", &start);
                fflush(stdin);
            }

            dfs = DFS(Graph, start, n, dfs);

            for(i = 0; i < n; i++)
            {
                printf("%d  ", *(dfs + i));
            }

            printf("\n");

            break;

        case 5:
            exit(0);
        
        default:
            break;
        }

        printf("\nDo you want to continue? [y/n]: ");
        scanf("%c", &ch);

    } while (ch == 'y' || ch == 'Y');   


    return 0;

}

struct node * create_node(int wt, int val)
{
    struct node * newnode = (struct node *)malloc(sizeof(struct node));

    newnode->weight = wt;
    newnode->vertex = val;
    newnode->next   = NULL;

    return newnode;
}

struct graph * create_graph(int no_of_vertices)
{
    int i;
    struct graph * Graph = (struct graph *)malloc(sizeof(struct graph));

    Graph->vertices = no_of_vertices;
    Graph->array    = (struct adj_list *)malloc((N+1) * sizeof(struct adj_list));

    for(i = 0; i <= N; i++)
    {
        Graph->array[i].head = NULL;
        Graph->array[i].tail = NULL;
    }

    return Graph;
}


void add_edge_directed(struct graph * Graph, int src, int dest, int weit)
{
    struct node * newnode = create_node(weit, dest);
    struct node * srcnode = create_node(weit, src);

    if(Graph->array[src].head == NULL)
    {
        Graph->array[src].head = srcnode;
        srcnode->next          = newnode;
        Graph->array[src].tail = newnode;
    }
    else
    {
        Graph->array[src].tail->next = newnode;
        newnode->next = NULL;
        Graph->array[src].tail = newnode;
    }

    printf("\n---- INSERTED ----\n");
}

void print_graph(struct graph *Graph)
{
    int v;
    for (v = 1; v <= Graph->vertices; ++v) 
    { 
        struct node* pCrawl = Graph->array[v].head;
        //printf("%d  ", v);
        while (pCrawl) 
        { 
            printf("%d  ", pCrawl->vertex); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
    }
}


void add_edge_undirected(struct graph *Graph, int src, int dest, int weit)
{
    struct node * newnode = create_node(weit, dest);
    struct node * srcnode = create_node(weit, src);
    struct node * newnode1 = create_node(weit, src);
    struct node * destnode = create_node(weit, dest);

    if(Graph->array[src].head == NULL)
    {
        Graph->array[src].head = srcnode;
        srcnode->next          = newnode;
        Graph->array[src].tail = newnode;
    }
    else
    {
        Graph->array[src].tail->next = newnode;
        newnode->next = NULL;
        Graph->array[src].tail = newnode;
    }

    if(Graph->array[dest].head == NULL)
    {
        Graph->array[dest].head = destnode;
        destnode->next          = newnode1;
        Graph->array[dest].tail = newnode1;
    }
    else
    {
        Graph->array[dest].tail->next = newnode1;
        newnode1->next = NULL;
        Graph->array[dest].tail = newnode1;
    }

    printf("\n---- INSERTED ----\n");
    
}

void delete_edge_directed(struct graph *Graph, int src, int dest)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    for(ptr = Graph->array[src].head; ptr != NULL; ptr = ptr->next)
    {
        if(ptr->next->vertex == dest)
        {
            temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
        }
    }

    printf("\n---- DELETED ----\n");
}

void delete_edge_undirected(struct graph *Graph, int src, int dest)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    for(ptr = Graph->array[src].head; ptr != NULL; ptr = ptr->next)
    {
        if(ptr->next->vertex == dest)
        {
            temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
        }
    }

    for(ptr = Graph->array[dest].head; ptr != NULL; ptr = ptr->next)
    {
        if(ptr->next->vertex == src)
        {
            temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
        }
    }

    printf("\n---- DELETED ----\n");
}

int *DFS(struct graph *Graph, int vertex, int n, int *vis)
{
    int i = 0, top_num;
    struct node *current = (struct node *)malloc(sizeof(struct node));
    //struct node *temp_top = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    current = Graph->array[vertex].head;

    Visited = (struct visited_stack*)malloc(sizeof(struct visited_stack));
    Visited->top = NULL;

    Visited->top = push(Visited->top, current->vertex);

    while(Visited->top != NULL)
    {
        top_num = pop(Visited);
        // top_num = temp_top->vertex;
        //Visited->top = pop(Visited->top);

        if(is_visited(vis, top_num, n) == 0)
        {
            vis[i] = top_num;
            i++;
            ptr = Graph->array[top_num].head;

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
                Visited->top = push(Visited->top, ptr->vertex);                
            }
        }
    }

    //printf("YAY");

    return vis;

}

int is_visited(int arr[N], int val, int n)
{
    int i;

    for(i = 0; i <= n; i++)
    {
        if(arr[i] == val)
            return 1;
    }

    return 0;
}

struct node * push(struct node *top_ptr, int val)
{
    struct node *new_node = create_node(0, val);
    
    new_node->next = top_ptr;
    top_ptr = new_node;

    return top_ptr;
}

int pop(struct visited_stack *visi)
{
    struct node *temp;
    int item;
    //temp = (struct node *)malloc(sizeof(struct node));

    if(visi->top == NULL)
    {
        printf("\nStack Underflow! Stack is empty\n");
    }
    else
    {
        temp = visi->top;
        item = visi->top->vertex;
        visi->top = visi->top->next;
        free(temp);
        
    }
    return item;
}
