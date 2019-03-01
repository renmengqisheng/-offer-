class Solution {
public:
    /***************************************
    *思路一
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        for(int i = 1; i < n+1; i++)
        {
            int temp = i;
            while(temp)
            {
                if(temp % 10 == 1) count++;
                temp /= 10;
            }
        }
        return count;
    }
    ******************************************/
    /******************************************
    *思路二
    ******************************************/
    int NumberOf1Between1AndN_Solution(int n){
        int sum = 0;
        /*
        int base = 1;
        while(base <= n)
        {
            int a = n/base, b = n%base;
            sum += (a+8)/10*base + (a%10 == 1) * (b+1);
            base *= 10;
        }
        */
        for(int i = 1; i <= n; i *= 10)
            sum += ((n/i + 8)/10) * i + (n/i % 10 == 1)*(n%i + 1);
        return sum;
    }
};
