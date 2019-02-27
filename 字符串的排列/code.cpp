class Solution {
public:
    /*************************************
    *思路一
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
    *****************************************/
    /****************************************
    *思路二
    vector<string> Permutation(string str) {
        vector<string> vs;
        if(!str.empty())
        {
            result(str, 0, vs);
            sort(vs.begin(),vs.end());
        }
        
        return vs;
    }
    
    void result(string str, int start, vector<string>& vs)
    {
        if(start == str.size()-1)
        {
            vs.push_back(str);
            return;
        }
        
        set<char> s;
        for(int i = start; i < str.size(); i++)
        {
            if(i == start || !s.count(str[i]))
            {
                s.insert(str[i]);
                swap(str, i, start);
                result(str, start+1, vs);
                swap(str, i, start);
            }
        }
    }
    
    void swap(string &str, int a, int b)
    {
        char temp = str[a];
        str[a] = str[b];
        str[b] = temp;
    }
    ****************************************/
    /****************************************
    *思路三
    *****************************************/
    vector<string> Permutation(string str) {
        vector<string> vs;
        if(!str.empty())
        {
            char* s = (char*)str.c_str();
            int len = strlen(s);
            sort(s, s+len);
            while(1)
            {
                vs.push_back(string(s));
                int from = len-1;
                while(from > 0 && s[from-1] >= s[from]) --from;
                if(!from) break;
                int max = from;
                while(max < len && s[max] > s[from-1]) ++max;
                int temp = s[from-1];
                s[from-1] = s[max-1];
                s[max-1] = temp;
                reverse(s, from, len-1);
            }       
        }
        return vs;
    }

    void reverse(char* str, int begin, int end)
    {
        if(begin >= end) return;
        
        int len = end-begin+1;
        for(int i = 0; i < len/2; i++)
        {
            int temp = str[begin+i];
            str[begin+i] = str[begin+len-1-i];
            str[begin+len-1-i] = temp;
        }
    }
    
};
