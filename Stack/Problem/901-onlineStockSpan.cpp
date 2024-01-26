
// LeetCode 901 - Online Stack Span


/* /

 // Step 1 : create stack of pari (price,span)
    stack<pair<int,int>> st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span =1;
        while(!st.empty() && st.top().first <= price){
            span += st.top().second;
            st.pop();
        }
        st.push({price,span}); // yahapar galti hogi <<<<<<
        return span;
        
    }


 */