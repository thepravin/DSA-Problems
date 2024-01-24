// Queue using stack

/* 

 stack<int> s1, s2;

    void push(int x) { s1.push(x); }

    int pop() {
        int pop = -1;
        if (!s2.empty()) {
            pop = s2.top();
        } else {
            // copy s1 to s2
            while (!s1.empty()) {
                int top = s1.top();
                s1.pop();
                s2.push(top);
            }
            pop = s2.top();
        }

        s2.pop();
        return pop;
    }

    int peek() {
        int front = -1;
        if (!s2.empty()) {
           front= s2.top();
        } else {
            // copy s1 to s2
            while (!s1.empty()) {
                int top = s1.top();
                s1.pop();
                s2.push(top);
            }
          front=  s2.top();
        }
        return front;
    }

    bool empty() {
       return s1.empty()&&s2.empty();
    }












 */