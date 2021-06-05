// Alice is a kindergarten teacher. She wants to give some candies to the children in her class.  
// All the children sit in a line and each of them has a rating score according to his or her 
// performance in the class.  Alice wants to give at least 1 candy to each child. 
// If two children sit next to each other, then the one with the higher rating must get more candies. 
// Alice wants to minimize the total number of candies she must buy.
// Example
// She gives the students candy in the following minimal amounts:
// She must buy a minimum of 10 candies.
// Function Description
// Complete the candies function in the editor below.
// candies has the following parameter(s):
// int n: the number of children in the class
// int arr[n]: the ratings of each student
// Returns
// int: the minimum number of candies Alice must buy


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'candies' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

long candies(int n, vector<int> arr) {
    long ans = 0;
    
    if(n == 1)
        return 1;
    
    vector<long long> c(n, 1);
    
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i-1]){
            c[i] = c[i-1]+1;
        }
    }
    
    for(int i = n-2; i >= 0; i--){
        if(arr[i] > arr[i+1]){
            c[i] = max(c[i], c[i+1]+1);
        }
    }
    
    for(int i = 0; i < n; i++){
        ans += c[i];
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
