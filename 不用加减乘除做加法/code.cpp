class Solution {
public:
    /*************************
    *思路一
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
    **************************/
    /*************************
    *思路二
    *************************/
    int Add(int num1, int num2)
    {
        char *a = reinterpret_cast<char*>(num1);
        return reinterpret_cast<long>(&a[num2]);
    }
};
