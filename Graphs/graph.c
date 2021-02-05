// C program for adjacency list representation of graphs
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

struct node * create_node(int wt, int val);
struct graph * create_graph(int no_of_vertices);
void add_edge(struct graph * Graph, int src, int dest, int weit);
void print_graph(struct graph *Graph);

int main()
{
    struct graph *Graph;
    int i, j, n, status, flag;
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

    printf("\n\n------- ADJACENCY MATRIX -------\n");

    // Taking input for matrix A + validation
    do {

        for(i = 0; i < n; i++)
        {
            printf("Enter row %d: ", i+1);
            flag = 1;

            for(j = 0; j < n; j++)
            {
                status = scanf("%d", &adjacency[i][j]);
                if(status == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
            {
                printf("Invalid entry!\n");
                fflush(stdin);
                break;
            }
        }

    }while(flag == 0);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d  ", adjacency[i][j]);
        }
        printf("\n");
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(adjacency[i-1][j-1] != 0)
            {
                printf("%d\n", adjacency[i-1][j-1]);
                add_edge(Graph, i, j, adjacency[i-1][j-1]);
            }
        }
    }

    print_graph(Graph);

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
    Graph->array    = (struct adj_list *)malloc((no_of_vertices+1) * sizeof(struct adj_list));

    for(i = 0; i <= no_of_vertices; i++)
    {
        Graph->array[i].head = NULL;
        Graph->array[i].tail = NULL;
    }

    return Graph;
}

void add_edge(struct graph * Graph, int src, int dest, int weit)
{
    struct node * newnode = create_node(weit, dest);

    if(Graph->array[src].head == NULL)
    {
        Graph->array[src].head = newnode;
        Graph->array[src].tail = newnode;
    }
    else
    {
        Graph->array[src].tail->next = newnode;
        newnode->next = NULL;
        Graph->array[src].tail = newnode;
    }
    printf("yay\n");
}

void print_graph(struct graph *Graph)
{
    int v;
    for (v = 1; v <= Graph->vertices; ++v) 
    { 
        struct node* pCrawl = Graph->array[v].head; 
        while (pCrawl) 
        { 
            printf("%d  ", pCrawl->vertex); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
    }
}