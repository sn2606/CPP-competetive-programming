// Kadane's algorithm
// Given an array, the algorithm to find the maximum subarray sum is called Kadane's algorithm

# include <iostream>
# include <vector>
# include <limits>
using namespace std;

int maxSubarraySum(vector<int> v);

int main()
{
    int n, i;
    vector <int> v;

    cin >> n;
    for(i = 0; i < n; i++)
    {
        int r;
        cin >> r;
        v.push_back(r);
    }

    cout << "\n" << "Max subarray sum: " << maxSubarraySum(v) << endl;

    return 0;
}

int maxSubarraySum(vector<int> v)
{
    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    for(int i = 0; i < v.size(); i++)
    {
        max_ending_here += v[i];

        if(max_ending_here > max_so_far)
        {
            max_so_far = max_ending_here;
        }

        if(max_ending_here < 0)
        {
            max_ending_here = 0;
        }
    }

    return max_so_far;
}