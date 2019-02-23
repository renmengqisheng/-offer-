class Solution {
public:
    int Fibonacci(int n) {
        if(n < 0)
            return -1;
        
        int f = 0, g = 1;
        while(n-- > 0)
        {
            g += f;
            f = g - f;
        }
        return f;
        /**
        if(n < 0)
            return -1;
        if(n == 0)
            return 0;
        
        int llast = 0, last = 1;
        for(int i = 0; i < n-1; i++)
        {
            int now = last + llast;
            llast= last;
            last = now;
        }
        return last;
        **/
    }
};
