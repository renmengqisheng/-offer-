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
        long long new_exp = abs((long long)exponent);
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


//思路三：
class Solution {
public:
    double power(double base, int exponent) {
        if (exponent == 0)
            return 1.0;
        
        long long n = abs((long long)exponent);
        double result = power(base, n >> 1);
        result *= result;
        if ((n & 1) == 1) // 如果指数n为奇数，则要再乘一次底数base
            result *= base;
         
        return exponent < 0? 1 / result: result;
    }
}
