class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(!str || !pattern) return false;
        if(!*pattern) return !*str;
        if(*(pattern+1) != '*')
        {
            if(*str == *pattern || *str && *pattern == '.')
                return match(str+1, pattern+1);
            return false;
        }
        else
        {
            if(*str == *pattern || *str && *pattern == '.')
                return match(str, pattern+2) || match(str+1, pattern);
            return match(str, pattern+2);
        }
    }
};
