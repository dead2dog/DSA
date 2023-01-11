// https://leetcode.cn/problems/implement-queue-using-stacks/

#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        if(stOut.empty())
        {
            while(!stIn.empty())
            {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }
    
    int peek() {
        int result = pop();
        stOut.push(result);
        return result;
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
private:
    stack<int> stIn;
    stack<int> stOut;
};