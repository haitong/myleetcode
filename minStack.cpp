/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
class MinStack {
public:
    stack<int> s[2];
    void push(int x) {
        if(s[0].empty()){
            s[0].push(x);
            s[1].push(x);
        }
        else{
            s[0].push(x);
            if(x > s[1].top()){
                s[1].push(s[1].top());
            }
            else s[1].push(x);
        }
    }

    void pop() {
        if(!s[0].empty()){
            s[0].pop();
            s[1].pop();
        }
    }

    int top() {
        return s[0].top();
    }

    int getMin() {
        return s[1].top();
    }
};
