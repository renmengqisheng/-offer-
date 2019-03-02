class Solution {
public:
    /***************************************************
    *思路一
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
    ***************************************/
    /**************************************
    *思路二
    **************************************/
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        for(int n = (int)sqrt(2*sum); n >= 2; n--)
        {
            if(n&1 && sum%n == 0 || (sum%n)*2 == n)
            {
                vector<int> v;
                for(int i = 0, t = sum/n - (n-1)/2; i < n; i++, t++)
                    v.push_back(t);
                res.push_back(v);
            }
        }
        return res;
    }
};
