class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        if(sum < 3) return vector<vector<int> >();
        
        int l = 1, r = 2;
        vector<vector<int> > res;
        while(l < r)
        {
            int t = ((l+r))*(r-l+1) >> 1;
            if(t < sum) r++;
            else if(t > sum) l++;
            else
            {
                vector<int> v;
                for(int i = l; i <= r; i++)
                    v.push_back(i);
                res.push_back(v);
                l++;
            }
        }
        return res;
    }
};
