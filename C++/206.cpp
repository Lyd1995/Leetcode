#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummyhead = new ListNode(-1);
        // q 表示已经反转的链表的最后一个节点，一开始没有，假设一个
        ListNode* q = dummyhead;
        ListNode* p1 = NULL;
        while(head){
            ListNode* next = cut(head, 2);
            // 此时，head仅仅是一个长度为2的链表了
            ListNode* p2 = reverse2(head);
            q->next = p2;
            head->next = p1;
            p1 = p2;
            head = next;
        }
        return dummyhead->next;
    }
    // 取链表的前n个节点，返回后面的头节点
    ListNode* cut(ListNode* head, int n){
        ListNode* p = head;
        while(--n && p != NULL){
            p = p->next;
        }
        if(p == NULL)
            return NULL;
        ListNode* next = p->next;
        p->next = 0;
        return next;
    }
    // 将长度为2的链表进行反转，并返回反转后链表的头结点
    ListNode* reverse2(ListNode* head){
        ListNode* p = head->next;
        if(p){
            p->next = head;
            head->next = NULL;
            return p;
        }
        else
            return head;
    }
};