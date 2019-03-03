class Solution {
public:
    void Insert(int num)
    {
        if(max.empty() || num <= max.top()) max.push(num);
        else min.push(num);
        
        if(max.size() == min.size() + 2) //注意不要相减，可能会溢出
            min.push(max.top()), max.pop();
        if(min.size() == max.size() + 2)
            max.push(min.top()), min.pop();
    }

    double GetMedian()
    {
        if(max.size() > min.size()) return max.top();
        else if(max.size() < min.size()) return min.top();
        else return (max.top()+min.top())/2.0;
    }

    priority_queue<int, vector<int>, greater<int>> min;
    priority_queue<int> max;
};
