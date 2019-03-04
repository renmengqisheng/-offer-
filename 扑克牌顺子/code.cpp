class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        /******************************
        *思路一
        int len = numbers.size();
        if(len != 5) return false;
        sort(numbers.begin(), numbers.end());
        int zero = 0;
        int diff = 0;
        for(int i = 0; i < len-1; i++)
        {
            if(numbers[i] == 0)
            {
                zero++;
                continue;
            }
            if(numbers[i] == numbers[i+1]) return false;
            diff += numbers[i+1] - numbers[i] - 1;
        }
        if(diff <= zero) return true;
        return false;
        ********************************/
        /*******************************
        *思路二
        *******************************/
        if(numbers.size() != 5) return false;
        int min = 14, max = -1;
        int flag = 0;
        for(int i = 0; i < numbers.size(); i++)
        {
            if(numbers[i] == 0) continue;
            if((flag >> numbers[i])&1) return false;
            flag |= 1 << numbers[i];
            if(numbers[i] > max) max = numbers[i];
            if(numbers[i] < min) min = numbers[i];
            if(max - min > 4) return false;
        }
        return true;
    }
};
