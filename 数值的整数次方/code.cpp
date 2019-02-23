class Solution {
public:
    double Power(double base, int exponent) {
        if(base == 0)
            return 0;
        
        if(exponent == 0)
            return 1;
        
        double res = 1;
        /*****************
        *思路一
        for(int i = 0; i < abs(exponent); i++)
                res *= base;
        ******************/
        /*****************
        *思路二
        ****************/
        int new_exp = abs(exponent);
        double cur = base;
        while(new_exp)
        {
            if(new_exp & 1)
                res *= cur;
            cur *= base;
            new_exp >>= 1;
        }
        return exponent > 0? res: 1.0/res;
    }
};
