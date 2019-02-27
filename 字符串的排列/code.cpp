class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> vs;
        if(!str.empty())
        {
            set<string> s;  //使用set进行去重排序
            result(str, string(), s);
            vs.assign(s.begin(), s.end());
        }

        return vs;
    }
    
    
    void result(string str, string res, set<string>& s)
    {
        if(str.empty())
        {
            s.insert(res);
            return;
        }
        
        int len = str.size();
        for(int i = 0; i < len; i++)
        {
            res += str[i];
            result(str.substr(0, i) + str.substr(i+1), res, s);
            res = res.substr(0, res.size()-1);
        }
    }
};
