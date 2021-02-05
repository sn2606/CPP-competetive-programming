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
void print_graph(struct graph *Graph);
void add_edge_undirected(struct graph *Graph, int src, int dest, int weit);
int *DFS(struct graph *Graph, int vertex, int n, int *);
int is_visited(int arr[N], int val, int n);
struct node * push(struct node *top_ptr, int val);
int pop(struct visited_stack *visi);

int main()
{
    struct graph *Graph;
    int n = 4, *dfs, i;
    

    Graph = create_graph(n);
    dfs = (int *)malloc(N * sizeof(int));

    add_edge_undirected(Graph, 1, 2, 1);
    add_edge_undirected(Graph, 1, 3, 1);
    add_edge_undirected(Graph, 2, 4, 1);

    print_graph(Graph);

    DFS(Graph, 1, n, dfs);

    for(i = 0; i < n; i++)
    {
      printf("%d  ", dfs[i]);
    }

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
        printf("Top num = %d\n", top_num);
        // top_num = temp_top->vertex;
        //Visited->top = pop(Visited->top);

        if(is_visited(vis, top_num, n) == 0)
        {
            vis[i] = top_num;
            i++;
            ptr = Graph->array[top_num].head;

            printf("i = %d Visited %d\n", i, vis[i-1]);

            while (ptr->next != NULL)
            {
                printf("Next vertex : %d\n", ptr->next->vertex);
                ptr = ptr->next;
                Visited->top = push(Visited->top, ptr->vertex);                
            }
        }
    }

    printf("YAY");

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
