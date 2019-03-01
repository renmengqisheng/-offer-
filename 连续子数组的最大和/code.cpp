class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()) return 0;
        
        int sum = array[0];
        int res = sum;
        for(int i = 1; i < array.size(); i++)
        {
            res = max(res, sum = max(sum+array[i], array[i]));
        }
        return res;
    }
};
