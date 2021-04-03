// Given weights and values of n items, put these items in a knapsack of capacity W 
// to get the maximum total value in the knapsack. In other words, given two integer 
// arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with 
// n items respectively. Also given an integer W which represents knapsack capacity, 
// find out the maximum value subset of val[] such that sum of the weights of this subset 
// is smaller than or equal to W. You cannot break an item, either pick the complete item 
// or don’t pick it (0-1 property).

# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

vector<int> knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    vector<vector<int>>DP (n+1, vector<int>(W+1, 0));

    for(i = 0; i <= n; i++){
        for(w = 0; w <= W; w++){
            if(i == 0 || w == 0){
                DP[i][w] = 0;
            }else if(wt[i-1] <= w){
                DP[i][w] = max(DP[i-1][w], DP[i-1][w - wt[i-1]] + val[i-1]);
            }else{
                DP[i][w] = DP[i-1][w];
            }
        }
    }

    int residue = DP[n][W];
    cout << "Max value possible in knapsack: " << residue << "\n";
    vector <int> ans(n, 0);
    i = n, w = W;

    while(i >= 0){
        if(residue == 0){
            break;
        }

        w = W;
        while(W >= 0){
            if(DP[i][w] == residue){
                break;
            }else{
                w--;
            }
        }

        while(DP[i][w] == residue){
            i--;
        }

        if(DP[i+1][w] == residue){
            ans[i] = 1;
            residue -= val[i];

        }
    }

    return ans;
}

int main() {

    int p[] = {1, 2, 5, 6};
    int w[] = {2, 3, 4, 5};

    vector <int> a = knapsack(8, w, p, 4);

    for(int i : a){
        cout << i << " ";
    }

    return 0;
}