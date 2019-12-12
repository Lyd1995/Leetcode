#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(!q1.empty()){
            while(q1.size() != 1){
                q2.push(q1.front());
                q1.pop();
            }
            int temp = q1.front();
            q1.pop();
            return temp;
        }
        else if(!q2.empty()){
            while(q2.size() != 1){
                q1.push(q2.front());
                q2.pop();
            }
            int temp = q2.front();
            q2.pop();
            return temp;
        }
        else{
            return 0;
        }
    }
    
    /** Get the top element. */
    int top() {
        if(!q1.empty()){
            while(q1.size() != 1){
                q2.push(q1.front());
                q1.pop();
            }
            int temp = q1.front();
            q2.push(temp);
            q1.pop();
            return temp;
        }
        else if(!q2.empty()){
            while(q2.size() != 1){
                q1.push(q2.front());
                q2.pop();
            }
            int temp = q2.front();
            q1.push(temp);
            q2.pop();
            return temp;
        }
        else{
            return 0;
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q1.empty() && q2.empty())
            return true;
        return false;
    }
private:
    queue<int> q1, q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */