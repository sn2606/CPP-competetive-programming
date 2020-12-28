#include <bits/stdc++.h>

using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
    // int i = 1, j = n;
    // int prev = -1;
        
    // while(j < 2*n - 1){
        // for(int x: nums){
        //     cout << x << " ";
        // }
        // cout << "\n";
        // cout << i << ":" << nums[i] << " " << j << ":" << nums[j] << "\n";
    //     swap(nums[i], nums[j]);
    //     i++;

    //     // for(int x: nums){
    //     //     cout << x << " ";
    //     // }

    //     // cout << "\n";

    //     prev = (prev == -1 || i + 1 == j || i == j) ? j : j - 1;
    //     // cout << i << ":" << nums[i] << " " << prev << ":" << nums[prev] << "\n";

    //     swap(nums[i], nums[prev]);
    //     i++;
    //     j++;
    // }

    vector<int> ans;
    int i = 0, j = n;
        
    for(; i < n; i++, j++){
        ans.push_back(nums[i]);
        ans.push_back(nums[j]);            
    }
        
    return ans;
        
    // return nums;        
}

int main()
{

    vector <int> arr;
    int n = 1;

    while(n < 11){
        arr.push_back(n++);
    }

    shuffle(arr, 5);

    for(int i: arr){
        cout << i << " ";
    }

    cout << "\n";

    return 0;
}