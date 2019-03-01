class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.empty()) return 0;
        
        return get(data, 0, data.size()-1)%1000000007L;
    }
    
    long long get(vector<int> &data, int l, int r) //使用long long防止int溢出
    {
        if(l >= r) return 0;
        
        int mid = l + ((r-l)>>1);
        long long count = 0;
        count += get(data, l, mid);
        count += get(data, mid+1, r);
        count += merge(data, l, r);
        return count;
    }
    
    long long merge(vector<int> &data, int l, int r)
    {
        if(l >= r) return 0;
        int mid = l + ((r-l)>>1);
        int cur1 = l;
        int cur2 = mid+1;
        long long count = 0;
        vector<int> t;
        while(cur1 <= mid && cur2 <= r)
        {
            if(data[cur1] > data[cur2])
            {
                count += mid-cur1+1;
                t.push_back(data[cur2++]);
            }
            else
            {
                t.push_back(data[cur1++]);
            }
        }
        while(cur1 <= mid) t.push_back(data[cur1++]);
        while(cur2 <= r) t.push_back(data[cur2++]);
        for(int i = l; i <= r; i++) data[i] = t[i-l];
        return count;
    }
};
