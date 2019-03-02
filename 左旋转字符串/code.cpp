class Solution {
public:
    string LeftRotateString(string str, int n) {
        /*******************
        *思路一、二、三：略
        *******************/
        /******************
        *思路四
        int len = str.size();
        if(len <= 1) return str;
        n = n%len;
        str += str.substr(0, n);
        return str.substr(n);
        ******************/
        /******************
        *思路五
        ******************/
        int len = str.size();
        if(len <= 1) return str;
        rotate(str, 0, n-1);
        rotate(str, n, len-1);
        rotate(str, 0, len-1);
        
        return str;
    }
    
    void rotate(string &str, int l, int r)
    {
        if(l >= r) return;
        
        while(l < r)
        {
            int t = str[l];
            str[l] = str[r];
            str[r] = t;
            l++;
            r--;
        }
    }
    
    
};
