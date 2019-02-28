class Solution {
public:
    /************************************************
    *思路一
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(!numbers.empty())
        {
            map<int, int> m;
            int size = numbers.size();
            for(int i = 0; i < size; i++)
            {
                if(++m[numbers[i]] > size/2)
                    return numbers[i];
            }
        }
        return 0;
    }
    ************************************************/
    /***********************************************
    *思路二
    ************************************************/
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(!numbers.empty())
        {
            int res = numbers[0];
            int count = 1;
            for(int i = 1; i < numbers.size(); i++)
            {
                if(!count)
                {
                    res = numbers[i];
                    count = 1;
                }
                else
                {
                    if(res == numbers[i]) count++;
                    else count--;
                }
            }
            count = 0;
            for(int i: numbers) if(i == res) count++;
            if(count*2 > numbers.size()) return res;
        }
        return 0;
    }
};
