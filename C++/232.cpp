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

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int ans = st2.top();
        st2.pop();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }
    
    /** Get the front element. */
    int peek() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int ans = st2.top();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty();
    }
private:
    stack<int> st1, st2;
};