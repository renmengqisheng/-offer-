class Solution {
public:
    /*************************************
    *思路一
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if(array.size() < 2) return vector<int>();
        
        for(int i = 0; i < array.size(); i++)
        {
            int t = find(array, i+1, array.size()-1, sum-array[i]);
            if(t != -1) return vector<int>{array[i], array[t]};
        }
        return vector<int>();
    }
    
    int find(vector<int> a, int l, int r, int v)
    {
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(a[mid] < v) l = mid+1;
            else if(a[mid] > v) r = mid-1;
            else return mid;
        }
        return -1;
    }
    *************************************/
    /*************************************
    *思路二
    *************************************/
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if(array.size() < 2) return vector<int>();
        
        int left = 0, right = array.size()-1;
        while(left < right)
        {
            int t = array[left] + array[right];
            if(t < sum) left++;
            else if(t > sum) right--;
            else return vector<int>{array[left], array[right]};
        }
        return vector<int>();
    }
    
};
