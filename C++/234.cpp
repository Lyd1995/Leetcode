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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        ListNode *fast = head, *slow = head;
        ListNode *re = NULL, *s = NULL;
        while(fast && fast->next){
            re = slow;
            fast = fast->next->next;
            slow = slow->next;
            re->next = s;
            s = re;
        }
        ListNode* back = slow;
        if(fast != NULL)   //  此时链表长度为奇数
            back = back->next;
        while(back){
            if(back->val != re->val)
                return false;
            back = back->next;
            re = re->next;
        }
        return true;
    }
};

int main(){

}