// Given two arrays A and B of equal size, the advantage of A with respect to B is the 
// number of indices i for which A[i] > B[i].
// Return any permutation of A that maximizes its advantage with respect to B.

# include <iostream>
# include <set>
# include <iterator>
# include <vector>
using namespace std;

// O(NlogN)
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        
        multiset <int> m (A.begin(), A.end()); 
        multiset<int>::iterator itr;
        
        for(int i = 0; i < B.size(); i++) { // O(N)
            itr = m.upper_bound(B[i]); // O(logN)
            if(itr == m.end()){
                itr = m.begin();
            }
            
            A[i] = *itr;
            m.erase(itr);
        }
        
        return A;
    }
};

// ILT
// multiset -> associative, ordered, set, multiple values allowed
// erase operation -> O(1)
// upper_bound -> O(logN)
// multiset is class template
// multiset from vactors