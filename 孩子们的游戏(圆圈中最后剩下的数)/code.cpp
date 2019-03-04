class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        /*************************************
        *思路一
        if(n <= 0 || m <= 0) return -1;
        if(n == 1) return 0;
        return (LastRemaining_Solution(n-1, m) + m)%n;
        *************************************/
        /*************************************
        *思路二
        *************************************/
        if(n <= 0 || m <= 0) return -1;
        int res = 0; //入口，n为1时的值
        for(int i = 2; i <= n; i++) res = (res+m)%i;
        return res;
    }
};
