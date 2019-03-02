class Solution {
public:
    int Add(int num1, int num2)
    {
        while(num2)
        {
            int sum = num1 ^ num2;
            num2 = (num1 & num2) << 1;
            num1 = sum;
        }
        return num1;
    }
};
