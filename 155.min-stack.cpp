/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (36.77%)
 * Total Accepted:    295.3K
 * Total Submissions: 802.8K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * 
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * 
 * top() -- Get the top element.
 * 
 * 
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 * 
 * 
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(st_min.size() !=0 ){
            if(x <= st_min.top()){
                st_min.push(x);
            }
        }
        else{
            st_min.push(x);
        }
        st.push(x);
    }
    
    void pop() {
        if(st.size() != 0){
            if(st.top() == st_min.top()){
                st.pop();
                st_min.pop();
            }
            else{
                st.pop();
            }               
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st_min.top();
    }
private:
    stack<int> st,st_min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

