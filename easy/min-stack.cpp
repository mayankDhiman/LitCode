class MinStack {
public:
    /** initialize your data structure here. */    
    MinStack() {
        main_stack.clear();
        min.clear();
        min.push_back(INT_MAX);
    }
    
    void push(int x) {
        main_stack.push_back(x);
        if (x < min.back()){
            min.push_back(x);   
        }
        else{
            min.push_back(min.back());
        }        
    }
    
    void pop() {
        main_stack.pop_back();
        min.pop_back();
    }
    
    int top() {
        return main_stack.back();
    }
    
    int getMin() {
        return min.back();
    }
private:
    // "main_stack" & "min" can be thought of as stacks which grow together.
    // "main_stack" preserves the order
    // "min" preserves the current minimum at top
    vector <int> main_stack;
    vector <int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
