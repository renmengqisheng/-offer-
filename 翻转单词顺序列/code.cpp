class Solution {
public:
    string ReverseSentence(string str) {
        int len = str.size();
        if(len <= 1) return str;
        
        rotate(str, 0, len-1);
        int blank_next = 0, index = 0;
        while(index < len)
        {
            while(index < len && str[index] == ' ') index++;
            //if(index == len) break;
            blank_next = index;
            while(index < len && str[index] != ' ') index++;
            rotate(str, blank_next, index-1);
        }
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
