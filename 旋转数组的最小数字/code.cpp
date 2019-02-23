class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;
        
        int left = 0, right = rotateArray.size()-1;
        /******************************************
        *思路一：
        *****************************************/
        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(rotateArray[mid] > rotateArray[right])
                left = mid + 1;
            else if(rotateArray[mid] < rotateArray[right])
                right = mid;
            else
                right--;
        }
        return rotateArray[left];
        
        /**********************************************
        *思路二：
        int mid = 0;
        while(rotateArray[left] >= rotateArray[right])
        {
            if(right-left == 1)
            {
                mid = right;
                break;
            }
            
            mid = left + (right - left)/2;
            if(rotateArray[left] == rotateArray[right] && 
               rotateArray[left] == rotateArray[mid])
            {
                int res = rotateArray[left];
                for(int i = left+1; i < right; i++)
                {
                    if(res > rotateArray[i])
                        res = rotateArray[i];
                }
                return res;
            }
            if(rotateArray[left] > rotateArray[mid])
                right = mid;
            else
                left = mid;
        }
        return rotateArray[mid];
        **********************************************/
    }
};
