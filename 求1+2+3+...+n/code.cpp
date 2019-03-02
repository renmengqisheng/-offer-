class help{
public:
    help(){n++, sum += n;}
    static void reset(){n = 0, sum = 0;}
    static int getSum(){return sum;}
private:
    static int n, sum;
};

int help::n = 0;
int help::sum = 0;

class Solution {
public:
    /*************************
    *思路一
    int Sum_Solution(int n) {
        int res = 0;
        n > 0 && (res = n + Sum_Solution(n-1));
        return res;
    }
    *************************/
    /************************
    *思路二
    int Sum_Solution(int n) {
        return multi(n, n+1) >> 1;
    }
    
    int multi(int a, int b)
    {
        int res = 0;
        a&1 && (res += b);
        a >>= 1, b <<= 1;
        a && (res += multi(a, b));
        return res;
    }
    ************************/
    /************************
    *思路三
    ************************/
    int Sum_Solution(int n) {
        help::reset();
        help* t = new help[n];
        delete []t;
        t = nullptr;
        return help::getSum();
    }
};

