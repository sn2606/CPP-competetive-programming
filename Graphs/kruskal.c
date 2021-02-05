// C program to show implementation of minimum spanning tree
// Using Kruskal's algorithm
// Using adjacency matrix as input

# include <stdio.h>
# include <stdlib.h>
# define N 30

// Structure to represent edge
struct edge
{
    int src;
    int dest;
    int weight;
};

// Structure to represent the graph as a set of edges
struct edge_list
{
    struct edge *data;
    int n;
};

// Prototyping the functions
struct edge_list *create_edge_list();
void add_edge(struct edge_list *elist, int src, int dest, int weit);
void sort(struct edge_list *elist);
void print_mst(struct edge_list *span_tree);
int locate(int *arr, int val);
void Union(int *arr, int src_val, int dest_val, int n);
struct edge_list *KRUSKAL(struct edge_list *elist, int no_of_vertices);

// MAIN FUNCTION
int main()
{
    struct edge_list *Edges, *Min_Span_Tree;
    int i, j, n, status, flag;
    int adjacency[N][N];

    printf("\nEnter the number of vertices in the graph: ");
    status = scanf("%d", &n);
    fflush(stdin);

    while (status == 0 || n > N)
    {
        printf("Invalid Input!\n");
        printf("\nEnter the number of vertices in the graph: ");
        status = scanf("%d", &n);
        fflush(stdin);
    }
    

    Edges = create_edge_list();
    Edges->n = 0;
    Min_Span_Tree = create_edge_list();
    Min_Span_Tree->n = 0;

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

    
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(adjacency[i-1][j-1] != 0)
            {
                //printf("%d %d %d\n", i, j,adjacency[i-1][j-1] );
                add_edge(Edges, i, j, adjacency[i-1][j-1]);
            }
        }
    }

    printf("\n---- KRUSKAL ----\n");
    Min_Span_Tree = KRUSKAL(Edges, n);
    print_mst(Min_Span_Tree);

    return 0;
}

struct edge_list *create_edge_list()
{
    struct edge_list *elist = (struct edge_list *)malloc(sizeof(struct edge_list));
    elist->data = (struct edge *)malloc((N*N)*sizeof(struct edge));

    elist->n = 0;

    return elist;
}

void add_edge(struct edge_list *elist, int src, int dest, int weit)
{
    //elist->n = 0;

    elist->data[elist->n + 1].src = src;
    elist->data[elist->n + 1].dest = dest;
    elist->data[elist->n + 1].weight = weit;
    elist->n = elist->n + 1;
}

void sort(struct edge_list *elist)
{
    struct edge temp;
    int i, j;

    for ( i = 1; i <= elist->n; i++)
    {
        for(j = i+1; j <= elist->n; j++)
        {
            if(elist->data[j].weight <= elist->data[i].weight)
            {
                temp = elist->data[i];
                elist->data[i] = elist->data[j];
                elist->data[j] = temp;
            }
        }
    }
}

void print_mst(struct edge_list *span_tree)
{
    int i, cost = 0;

    for(i = 0; i < span_tree->n; i++)
    {
        printf("\n%d -> %d | %d |", span_tree->data[i].src, span_tree->data[i].dest, span_tree->data[i].weight);
        cost = cost + span_tree->data[i].weight;
    }

    printf("\nThe total cost of traversal is %d.\n", cost);
}

int locate(int *arr, int val)
{
    return arr[val];
}

void Union(int *arr, int src_val, int dest_val, int n)
{
    int i;

    for(i = 1; i <= n; i++)
    {
        if(arr[i] == src_val)
        {
            arr[i] = dest_val;
        }
    }
}

struct edge_list *KRUSKAL(struct edge_list *elist, int no_of_vertices)
{
    int i, j;
    int src_val, dest_val, subset[N];

    struct edge_list *span_tree = create_edge_list();

    sort(elist);

    for (i = 1; i <= no_of_vertices; i++)
    {
        subset[i] = i;
    }

    span_tree->n = 0;

    for(i = 1; i <= elist->n; i++)
    {
        
        src_val = locate(subset, elist->data[i].src);
        dest_val = locate(subset, elist->data[i].dest);

        if(src_val != dest_val)
        {
            span_tree->data[span_tree->n] = elist->data[i];
            span_tree->n =  span_tree->n + 1;
            Union(subset, src_val, dest_val, no_of_vertices);
        }
    }
    return span_tree;

}
