// Given an array nums of n integers and an integer target, are there elements a, b, c, and d 
// in nums such that a + b + c + d = target? Find all unique quadruplets in the array 
// which gives the sum of target.

// Notice that the solution set must not contain duplicate quadruplets.

// Reduce K sum to K-1 sum
// 2-sum is done by 2-pointers

# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int n = arr.size();
        if(n < 4){
            return ans;
        }
        
        for(int i = 0; i < n-3; i++){
            
            if(i > 0 && arr[i] == arr[i-1]){
                continue;
            }
            
            if(arr[i] + arr[i+1] + arr[i+2] + arr[i+3] > target){
                break;
            }
            
            if(arr[i] + arr[n-1] + arr[n-2] + arr[n-3] < target){
                continue;
            }
            
            for(int j = i+1; j < n-2; j++){
                
                // if(arr[i]+arr[j] >= target){
                //     break;
                // }
                
                if(j > i+1 && arr[j] == arr[j-1]){
                    continue;
                }
                
                if(arr[i] + arr[j] + arr[j+1] + arr[j+2] > target){
                    break;
                }

                if(arr[i] + arr[n-1] + arr[n-2] + arr[j] < target){
                    continue;
                }
                
                int x = j+1;
                int y = n-1;
                
                while(x < y){
                    int sum = arr[i] + arr[j] + arr[x] + arr[y];
                    
                    if(sum > target){
                        y--;
                    }else if(sum < target){
                        x++;
                    }else{
                        ans.push_back(vector<int>{arr[i], arr[j], arr[x], arr[y]});
                        
                        do{
                            x++;
                        }while(x < y && arr[x] == arr[x-1]);
                        
                        do{
                            y--;
                        }while(x < y && arr[y] == arr[y+1]);
                        
                    }
                    
                }
                
            }            
        }
        
        return ans;        
    }
};