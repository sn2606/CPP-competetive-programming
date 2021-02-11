// A linked list of length n is given such that each node contains an additional random pointer, 
// which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, 
// where each new node has its value set to the value of its corresponding original node. 
// Both the next and random pointer of the new nodes should point to new nodes in the copied list 
// such that the pointers in the original list and copied list represent the same list state. 
// None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, 
// then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// The linked list is represented in the input/output as a list of n nodes. 
// Each node is represented as a pair of [val, random_index] where:
//  - val: an integer representing Node.val
//  - random_index: the index of the node (range from 0 to n-1) that the random pointer points to, 
//    or null if it does not point to any node.
//  - Your code will only be given the head of the original linked list.

# include <iostream>
# include <vector>
# include <unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    // This is a constructor
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// O(n) time
// O(n) space
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(!head)
            return NULL;
        
        unordered_map <Node *, int> randInd;
        vector <Node *> copiedAdd;
        Node* copyH = new Node(0);
        Node* temp = head;
        Node* res = copyH;
        int i = 0;
        
        while(head){
            randInd[head] = i;
//             cout << head->val << " " << randInd[head];
//             if(head->random)
//                  cout << " " << head->random->val;
            
//             cout << "\n";
            Node* newNode = new Node(0);
            
            newNode->val = head->val;
            if(!i){
                copyH = newNode;
                res = copyH;
            }else{
                copyH->next = newNode;
                copyH = copyH->next;
            }            
            
            copiedAdd.push_back(newNode);
            head = head->next;
            i++;
        }
        
        copyH->next = NULL;
        copyH = res;
        
        while(temp){
            
            if(temp->random == NULL){
                copyH->random = NULL;
            }else{
                int ind = randInd[temp->random];
                // cout << temp->val << "$" << ind << "$" << copiedAdd[ind]->val << "\n";
                copyH->random = copiedAdd[ind]; 
            }           
            
            copyH = copyH->next;
            temp = temp->next;
        }
        
        return res;        
    }
};

// O(1) space
// O(n) time
/*
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * head_cp = nullptr, * cur = head, * cur_cp = nullptr;
        if (head == nullptr)
            return nullptr;
        while (cur != nullptr)
        {
            cur_cp = new Node(cur->val, cur->next, nullptr);
            cur->next = cur_cp;
            cur = cur_cp->next;
        }
        cur = head;
        while (cur != nullptr)
        {
            cur_cp = cur->next;
            if (cur->random)
                cur_cp->random = cur->random->next;
            cur = cur_cp ->next;
        }
        cur = head;
        head_cp = head->next;
        while (cur != nullptr)
        {
            cur_cp = cur->next;
            cur->next = cur_cp->next;
            cur = cur->next;
            if (cur)
                cur_cp->next = cur->next;
        }
        return head_cp;
    }
};
*/