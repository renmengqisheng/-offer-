class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 0)
            return 0;
        else
            return pow(2, number-1);
        /**********************************
        int res = 1;
        for(int i = 0; i < number-1; i++)
            res *= 2;
        
        return res;
        ***********************************/
    }
};
