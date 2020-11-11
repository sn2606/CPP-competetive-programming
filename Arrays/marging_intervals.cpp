#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// bool compareIntervals(vector<int> i, vector<int> j);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    vector<vector <int>>intervals;
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        int r, s;
        vector <int> v;
        cin >> r >> s;
        
        v.push_back(r);
        v.push_back(s);
        
        intervals.push_back(v);
    }
    
    sort(intervals.begin(), intervals.end());
    
    vector< vector <int> >result;
    
    int i = 0, j = 0, count = 0;
    
    while(i < n && j < n)
    {
        vector<int> merged;
        
        if(count == 0)
        {
            merged.push_back(intervals[0][0]);
            merged.push_back(intervals[0][1]);
            
            result.push_back(merged);
            count++;
            i++;
            
            // cout << "hey" << result[count-1][0] << " " << result[count-1][1] << "\n";
        }
        else
        {
            if(intervals[i][0] <= intervals[j][1])
            {
                result[count-1][1] = (intervals[i][1] > intervals[j][1] ? intervals[i][1] : intervals[j][1]);
                
                //cout << result[count-1][0] << " " << result[count-1][1] << "\n";
            }
            else
            {
                merged.push_back(intervals[i][0]);
                merged.push_back(intervals[i][1]);
                result.push_back(merged);
                count++;
                
                //cout << result[count-1][0] << " " << result[count-1][1] << "\n";
            }
            i++;
            j++;
        }
        
    }
    
    for(i = 0; i < count; i++)
    {
        cout << result[i][0] << " " << result[i][1] << "\n";
    }    
    
    
    return 0;
}


// bool compareIntervals(vector<int> i, vector<int> j)
// {
//     return(i.begin() > j.begin());
// }
