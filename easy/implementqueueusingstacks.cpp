class MyQueue {
public:
    
    stack<int> stack_left; 
    stack<int> stack_right;
    
    MyQueue() {
    
    }
    
    void push(int x) {
    //if both stacks are empty push to right
    if (stack_right.empty() && stack_left.empty() ){
        stack_right.push(x);
    }
    //empty the right stack into the left, 
    //push new item to right 
    //move items from left back to right
    else {
        while(!stack_right.empty()){
            stack_left.push(stack_right.top());
            stack_right.pop();
        }
        stack_right.push(x);
        while(!stack_left.empty()){
            stack_right.push(stack_left.top());
            stack_left.pop();
        }
    }
    }
    
    int pop() {
        int item = stack_right.top();
        stack_right.pop();
        return item;
    }
    
    int peek() {
        return stack_right.top();
    }
    
    bool empty() {
        return stack_right.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
