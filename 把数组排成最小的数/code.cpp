class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string res;
        /*************************************
        *思路一
        sort(numbers.begin(), numbers.end());
        if(!numbers.empty())
        {
            for(int i = 0; i < numbers.size(); i++)
            {
                string t = to_string(numbers[i]);
                if(res+t <= t+res)
                    res += t;
                else res = t+res;
            }
        }
        *************************************/
        /*************************************
        *思路二
        *************************************/
        if(!numbers.empty())
        {
            sort(numbers.begin(), numbers.end(), cmp);
            for(auto n: numbers) res += to_string(n);
        }
        return res;
    }
    
    static bool cmp(int a, int b)
    {
        string m = to_string(a)+to_string(b);
        string n = to_string(b)+to_string(a);
        return (m <= n);
    }
};
