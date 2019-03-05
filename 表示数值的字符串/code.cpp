class Solution {
public:
    bool isNumeric(char* str)
    {
        if(!str) return false;
        bool num = isSignedNum(str);
        if(*str == '.') num = isUnsignedNum(++str) || num; //注意str后移,短路原理
        if(*str == 'e' || *str == 'E') num = isSignedNum(++str) && num; //注意str后移
        return num && !*str; //注意判断str是否到达末尾
    }
    bool isUnsignedNum(char* &str)
    {
        char* temp = str;
        while(*str >= '0' && *str <= '9') ++str;
        return str > temp;
    }
    bool isSignedNum(char* &str)
    {
        if(*str == '+' || *str == '-') ++str;
        return isUnsignedNum(str);
    }

};
