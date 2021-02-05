// // C program for Kruskal's algorithm to find Minimum Spanning Tree 
// // of a given connected, undirected and weighted graph 
// #include <stdio.h> 
// #include <stdlib.h> 
// #include <string.h> 

// // a structure to represent a weighted edge in graph 
// struct Edge 
// { 
// 	int src, dest, weight; 
// }; 

// // a structure to represent a connected, undirected 
// // and weighted graph 
// struct Graph 
// { 
// 	// V-> Number of vertices, E-> Number of edges 
// 	int V, E; 

// 	// graph is represented as an array of edges. 
// 	// Since the graph is undirected, the edge 
// 	// from src to dest is also edge from dest 
// 	// to src. Both are counted as 1 edge here. 
// 	struct Edge* edge; 
// }; 

// // Creates a graph with V vertices and E edges 
// struct Graph* createGraph(int V, int E) 
// { 
// 	struct Graph* graph = new_Graph; 
// 	graph->V = V; 
// 	graph->E = E; 

// 	graph->edge = new Edge[E]; 

// 	return graph; 
// } 

// // A structure to represent a subset for union-find 
// struct subset 
// { 
// 	int parent; 
// 	int rank; 
// }; 

// // A utility function to find set of an element i 
// // (uses path compression technique) 
// int find(struct subset subsets[], int i) 
// { 
// 	// find root and make root as parent of i 
// 	// (path compression) 
// 	if (subsets[i].parent != i) 
// 		subsets[i].parent = find(subsets, subsets[i].parent); 

// 	return subsets[i].parent; 
// } 

// // A function that does union of two sets of x and y 
// // (uses union by rank) 
// void Union(struct subset subsets[], int x, int y) 
// { 
// 	int xroot = find(subsets, x); 
// 	int yroot = find(subsets, y); 

// 	// Attach smaller rank tree under root of high 
// 	// rank tree (Union by Rank) 
// 	if (subsets[xroot].rank < subsets[yroot].rank) 
// 		subsets[xroot].parent = yroot; 
// 	else if (subsets[xroot].rank > subsets[yroot].rank) 
// 		subsets[yroot].parent = xroot; 

// 	// If ranks are same, then make one as root and 
// 	// increment its rank by one 
// 	else
// 	{ 
// 		subsets[yroot].parent = xroot; 
// 		subsets[xroot].rank++; 
// 	} 
// } 

// // Compare two edges according to their weights. 
// // Used in qsort() for sorting an array of edges 
// int myComp(const void* a, const void* b) 
// { 
// 	struct Edge* a1 = (struct Edge*)a; 
// 	struct Edge* b1 = (struct Edge*)b; 
// 	return a1->weight > b1->weight; 
// } 

// // The main function to construct MST using Kruskal's algorithm 
// void KruskalMST(struct Graph* graph) 
// { 
// 	int V = graph->V; 
// 	struct Edge result[V]; // Tnis will store the resultant MST 
// 	int e = 0; // An index variable, used for result[] 
// 	int i = 0; // An index variable, used for sorted edges 

// 	// Step 1: Sort all the edges in non-decreasing 
// 	// order of their weight. If we are not allowed to 
// 	// change the given graph, we can create a copy of 
// 	// array of edges 
// 	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp); 

// 	// Allocate memory for creating V ssubsets 
// 	struct subset *subsets = 
// 		(struct subset*) malloc( V * sizeof(struct subset) ); 

// 	// Create V subsets with single elements 
// 	for (int v = 0; v < V; ++v) 
// 	{ 
// 		subsets[v].parent = v; 
// 		subsets[v].rank = 0; 
// 	} 

// 	// Number of edges to be taken is equal to V-1 
// 	while (e < V - 1 && i < graph->E) 
// 	{ 
// 		// Step 2: Pick the smallest edge. And increment 
// 		// the index for next iteration 
// 		struct Edge next_edge = graph->edge[i++]; 

// 		int x = find(subsets, next_edge.src); 
// 		int y = find(subsets, next_edge.dest); 

// 		// If including this edge does't cause cycle, 
// 		// include it in result and increment the index 
// 		// of result for next edge 
// 		if (x != y) 
// 		{ 
// 			result[e++] = next_edge; 
// 			Union(subsets, x, y); 
// 		} 
// 		// Else discard the next_edge 
// 	} 

// 	// print the contents of result[] to display the 
// 	// built MST 
// 	printf("Following are the edges in the constructed MST\n"); 
// 	for (i = 0; i < e; ++i) 
// 		printf("%d -- %d == %d\n", result[i].src, result[i].dest, 
// 												result[i].weight); 
// 	return; 
// } 

// // Driver program to test above functions 
// int main() 
// { 
// 	/* Let us create following weighted graph 
// 			10 
// 		0--------1 
// 		| \	 | 
// 	6| 5\ |15 
// 		|	 \ | 
// 		2--------3 
// 			4	 */
// 	int V = 4; // Number of vertices in graph 
// 	int E = 5; // Number of edges in graph 
// 	struct Graph* graph = createGraph(V, E); 


// 	// add edge 0-1 
// 	graph->edge[0].src = 0; 
// 	graph->edge[0].dest = 1; 
// 	graph->edge[0].weight = 10; 

// 	// add edge 0-2 
// 	graph->edge[1].src = 0; 
// 	graph->edge[1].dest = 2; 
// 	graph->edge[1].weight = 6; 

// 	// add edge 0-3 
// 	graph->edge[2].src = 0; 
// 	graph->edge[2].dest = 3; 
// 	graph->edge[2].weight = 5; 

// 	// add edge 1-3 
// 	graph->edge[3].src = 1; 
// 	graph->edge[3].dest = 3; 
// 	graph->edge[3].weight = 15; 

// 	// add edge 2-3 
// 	graph->edge[4].src = 2; 
// 	graph->edge[4].dest = 3; 
// 	graph->edge[4].weight = 4; 

// 	KruskalMST(graph); 

// 	return 0; 
// } 

// Kruskal's algorithm in C

#include <stdio.h>

#define MAX 30

typedef struct edge {
  int u, v, w;
} edge;

typedef struct edge_list {
  edge data[MAX];
  int n;
} edge_list;

edge_list elist;

int Graph[MAX][MAX], n;
edge_list spanlist;

void kruskalAlgo();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
void sort();
void print();

// Applying Krushkal Algo
void kruskalAlgo() {
  int belongs[MAX], i, j, cno1, cno2;
  elist.n = 0;

  for (i = 1; i < n; i++)
    for (j = 0; j < i; j++) {
      if (Graph[i][j] != 0) {
        elist.data[elist.n].u = i;
        elist.data[elist.n].v = j;
        elist.data[elist.n].w = Graph[i][j];
        elist.n++;
      }
    }

  sort();

  for (i = 0; i < n; i++)
    belongs[i] = i;

  spanlist.n = 0;

  for (i = 0; i < elist.n; i++) {
    cno1 = find(belongs, elist.data[i].u);
    cno2 = find(belongs, elist.data[i].v);

    if (cno1 != cno2) {
      spanlist.data[spanlist.n] = elist.data[i];
      spanlist.n = spanlist.n + 1;
      applyUnion(belongs, cno1, cno2);
    }
  }
}

int find(int belongs[], int vertexno) {
  return (belongs[vertexno]);
}

void applyUnion(int belongs[], int c1, int c2) {
  int i;

  for (i = 0; i < n; i++)
    if (belongs[i] == c2)
      belongs[i] = c1;
}

// Sorting algo
void sort() {
  int i, j;
  edge temp;

  for (i = 1; i < elist.n; i++)
    for (j = 0; j < elist.n - 1; j++)
      if (elist.data[j].w > elist.data[j + 1].w) {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
}

// Printing the result
void print() {
  int i, cost = 0;

  for (i = 0; i < spanlist.n; i++) {
    printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
    cost = cost + spanlist.data[i].w;
  }

  printf("\nSpanning tree cost: %d", cost);
}

int main() {
  int i, j, total_cost;

  n = 6;

  Graph[0][0] = 0;
  Graph[0][1] = 4;
  Graph[0][2] = 4;
  Graph[0][3] = 0;
  Graph[0][4] = 0;
  Graph[0][5] = 0;
  Graph[0][6] = 0;

  Graph[1][0] = 4;
  Graph[1][1] = 0;
  Graph[1][2] = 2;
  Graph[1][3] = 0;
  Graph[1][4] = 0;
  Graph[1][5] = 0;
  Graph[1][6] = 0;

  Graph[2][0] = 4;
  Graph[2][1] = 2;
  Graph[2][2] = 0;
  Graph[2][3] = 3;
  Graph[2][4] = 4;
  Graph[2][5] = 0;
  Graph[2][6] = 0;

  Graph[3][0] = 0;
  Graph[3][1] = 0;
  Graph[3][2] = 3;
  Graph[3][3] = 0;
  Graph[3][4] = 3;
  Graph[3][5] = 0;
  Graph[3][6] = 0;

  Graph[4][0] = 0;
  Graph[4][1] = 0;
  Graph[4][2] = 4;
  Graph[4][3] = 3;
  Graph[4][4] = 0;
  Graph[4][5] = 0;
  Graph[4][6] = 0;

  Graph[5][0] = 0;
  Graph[5][1] = 0;
  Graph[5][2] = 2;
  Graph[5][3] = 0;
  Graph[5][4] = 3;
  Graph[5][5] = 0;
  Graph[5][6] = 0;

  kruskalAlgo();
  print();
}