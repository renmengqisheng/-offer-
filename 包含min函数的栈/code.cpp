class Solution {
public:
    void push(int value) {
        if(s1.empty())
            s2.push(value);
        else if(value <= s2.top())
            s2.push(value);
        s1.push(value);
    }
    void pop() {
        if(s1.top() == s2.top())
            s2.pop();
        s1.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
private:
    stack<int> s1, s2;
};
