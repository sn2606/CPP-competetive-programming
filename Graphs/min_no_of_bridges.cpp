// There is a beautiful region named Codess Islands 
// where young and intelligent codessses code in peace. 
// It is a group of islands connected together via ancient bridges. 
// It's been 20 years since the frugal construction master Aarnav 
// had the bridges repaired. Some bridges have since collapsed and 
// the islands have become disconnected. He decides to construct 
// some bridges such that from any given island you can reach any other island. 
// Find the minimum number of bridges you need to build to connect the islands.



#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

vector <vector <int>>adj_list;
vector<bool>con;

void edge(int a, int b) 
{ 
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
}

void bfs(int start) 
{ 
    queue<int> q;
  
    q.push(start); 
    con[start] = true; 
  
    while (!q.empty()) { 
  
        int f = q.front(); 
        q.pop();
   
        for (auto i = adj_list[f].begin(); i != adj_list[f].end(); i++) { 
            if (!con[*i]) { 
                q.push(*i); 
                con[*i] = true; 
            } 
        } 
    } 
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int isl, bn, i, j = 0;
    
    cin >> isl;
    cin >> bn;
    
    vector<int>f(isl+1, 0);
    
    con.assign(isl+1, false);
    adj_list.assign(isl+1, vector<int>());
    
    int a, b, start;
    
    for(i = 0; i < bn; i++){
        cin >> a;
        cin >> b;
        edge(a, b);
        if(!f[a]) f[a]++;
        if(!f[b]) f[b]++;
    }
      
    start = 0; 
    
    for(i = 1; i <= isl; i++){
        start = f[i] > start ? f[i] : start;
        if(f[i] == 0){
            j++;            
        }
    }
    
    bfs(start);
    
    for(i = 1; i <= isl; i++){
        if(con[i] == 0 && f[i] > 0){
            j++;
            bfs(i);
        }
    }
    
    cout << j;
    
    return 0;
}