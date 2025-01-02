class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) { // O(1)
        input.push(x);
    }

    int dequeue() { // O(n)
        int pop = -1;
        if(!output.empty()){
            pop = output.top();
        }else{
            // copy input --> output
            while(!input.empty()){
                int top = input.top();
                input.pop();
                output.push(top);
            }
            
            pop = output.top();
        }
        
        output.pop();
        return pop;
    }
};