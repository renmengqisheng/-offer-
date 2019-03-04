class Solution {
public:
    int StrToInt(string str) {
        if(str.empty()) return 0;
        int sgn = (str[0] == '-')? -1: 1;
        long long sum = 0;
        for(int i = (str[0] == '+' || str[0] == '-')? 1: 0; i < str.size(); i++)
        {
            if(str[i] >= '0' && str[i] <= '9') 
                sum = (sum << 1) + (sum << 3) + (str[i] & 0xf);
            else return 0;
        }
        return sum*sgn;
    }
};
