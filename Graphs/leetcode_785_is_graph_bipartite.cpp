// Given an undirected graph, return true if and only if it is bipartite.
// A graph is bipartite if we can split its set of nodes into two independent subsets A and B,
// such that every edge in the graph has one node in A and another node in B.
// The graph is given in the following form: graph[i] is a list of indexes j for which the edge
// between nodes i and j exists. Each node is an integer between 0 and graph.length - 1.
// There are no self edges or parallel edges: graph[i] does not contain i,
// and it doesn't contain any element twice.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {

        int n = graph.size();
        vector<int> nodes(n, 0);
        vector<bool> visited(n, false);

        int l = 0;
        int ind = 0;

        for (int i = 0; i < n; i++)
        {
            if (graph[i].size() > l)
            {
                l = graph[i].size();
                ind = i;
            }
        }

        queue<int> q;
        q.push(ind);
        nodes[ind] = -1;
        visited[ind] = true;

        while (!q.empty())
        {

            int f = q.front();
            q.pop();

            for (int i : graph[f])
            {

                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }

                if (nodes[i] == 0)
                {
                    if (nodes[f] == -1)
                    {
                        nodes[i] = n;
                    }
                    else if (nodes[f] == n)
                    {
                        nodes[i] = -1;
                    }
                }
                else if (nodes[i] != nodes[f])
                {
                    continue;
                }
                else if (nodes[i] == nodes[f])
                {
                    return false;
                }
            }
        }

        return true;
    }
};