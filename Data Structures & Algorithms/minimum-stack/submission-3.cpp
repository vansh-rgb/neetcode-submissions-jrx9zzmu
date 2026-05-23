class MinStack {
public:
    stack<pair<int,int>> s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()) {
            s.push(make_pair(val, val));
            return;
        }

        int minEle = s.top().second;

        if(minEle > val) s.push(make_pair(val, val));
        else s.push(make_pair(val,minEle));
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
