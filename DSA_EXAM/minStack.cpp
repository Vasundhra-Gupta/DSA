//Design a stack that supports push(), pop(), and [min()(O(1))] without using additional stack.
class MinStack {
    public:
    stack <long long> st;
    long long min;
    MinStack() {
    }
    
    void push(long long val) {
        if(st.empty()){
            st.push(val);
            min = val;
        }else{
            if(min>val){
                st.push(2*val - min);
                min = val;
            }else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        long long x = st.top();
        if(x > min){
            st.pop();
        }else{
            long long prevMin = min;
            min = 2*prevMin - x;
            st.pop();
        }
    }
    
    long long top() {
        if(st.empty()) return -1;
        if(st.top()<min){
            return min;
        }else{
            return st.top();
        }
    }
    
    long long getMin() {
        if (st.empty()) return -1;
        return min;
    }
};