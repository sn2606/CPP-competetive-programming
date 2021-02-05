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

struct visited_queue
{
  struct node *front;
  struct node *rear;
}*Visited;

struct node * create_node(int wt, int val);
struct graph * create_graph(int no_of_vertices);
void print_graph(struct graph *Graph);
void add_edge_undirected(struct graph *Graph, int src, int dest, int weit);
int *BFS(struct graph *Graph, int vertex, int n, int *vis);
int is_visited(int arr[N], int val, int n);
struct visited_queue *initial_queue(struct visited_queue *q_ptr);
int is_empty(struct visited_queue *q_ptr);
void enqueue(struct visited_queue *q_ptr, int val);
int dequeue(struct visited_queue *q_ptr);

int main()
{
    struct graph *Graph;
    int n = 4, *bfs, i;
    

    Graph = create_graph(n);
    bfs = (int *)malloc(N * sizeof(int));

    add_edge_undirected(Graph, 1, 2, 1);
    add_edge_undirected(Graph, 1, 3, 1);
    add_edge_undirected(Graph, 2, 4, 1);

    print_graph(Graph);

    BFS(Graph, 1, n, bfs);

    for(i = 0; i < n; i++)
    {
      printf("%d  ", bfs[i]);
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

int *BFS(struct graph *Graph, int vertex, int n, int *vis)
{
    int front_num, i = 0;
    struct node *ptr   = (struct node *)malloc(sizeof(struct node));
    struct node *start = (struct node *)malloc(sizeof(struct node));
    start = Graph->array[vertex].head;

    Visited = initial_queue(Visited);

    enqueue(Visited, start->vertex);


    while(is_empty(Visited) == 0)
    {
        front_num = dequeue(Visited);

        if(is_visited(vis, front_num, n) == 0)
        {
            vis[i] = front_num;
            i++;

            ptr = Graph->array[front_num].head;

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
                enqueue(Visited, ptr->vertex);
            }

        }
    }

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

// Initialize the queue
struct visited_queue *initial_queue(struct visited_queue *q_ptr)
{
    q_ptr = (struct visited_queue *)malloc(sizeof(struct visited_queue));
    q_ptr->front = NULL;
    q_ptr->rear  = NULL;

    return q_ptr;
}


// Function to check if the queue is empty
int is_empty(struct visited_queue *q_ptr)
{
    if(q_ptr->front == NULL || q_ptr->rear == NULL)
    {
        return 1;
    }
    return 0;
}

// Function to Enqueue an element
// Element will be added at the rear of the queue
void enqueue(struct visited_queue *q_ptr, int val)
{
    struct node *new_node = create_node(0, val);  
    
    if(is_empty(q_ptr))
    {
        q_ptr->front = q_ptr->rear = new_node;
    }
    else
    {
        q_ptr->rear->next = new_node;
        q_ptr->rear = new_node;
    }

}

// Function to Dequeue an element
// Element will be dequeued from the front of the queue
int dequeue(struct visited_queue *q_ptr)
{
    int ret;

    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    if(is_empty(q_ptr))
    {
        printf("\nQueue Underflow! No elements available to dequeue.\n\n");
    }
    else
    {
        temp =  q_ptr->front;
        q_ptr->front = q_ptr->front->next;
        ret = temp->vertex;
        free(temp);  
    }

    return ret;    
}