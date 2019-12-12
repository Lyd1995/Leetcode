#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<math.h>
#include<sstream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node->next){
            node->val = node->next->val;
            ListNode* temp = node->next->next;
            delete node->next;
            node->next = temp;
        }
        else
            delete node;
    }
};