class Solution {
public:
    void reOrderArray(vector<int> &array) {
    /***********************
    *思路一，类似于归并排序，时间复杂度O(nlogn),空间复杂度O(n)
        if(array.size() < 2)
            return;
        
        reOrderArray(array, 0, array.size()-1);
    }
    
    void reOrderArray(vector<int> &array, int left, int right)
    {
        if(left >= right)
            return;
        
        int mid = left + (right-left)/2;
        reOrderArray(array, left, mid);
        reOrderArray(array, mid+1, right);
        int p1 = left;
        int p2 = mid+1;
        vector<int> temp;
        while(p1 <= mid && p2 <= right)
        {
            if(array[p1] & 1)
                temp.push_back(array[p1++]);
            else if(array[p2] & 1)
                temp.push_back(array[p2++]);
            else
                temp.push_back(array[p1++]);
        }
        while(p1 <= mid)
            temp.push_back(array[p1++]);
        while(p2 <= right)
            temp.push_back(array[p2++]);
        for(int i = left; i <= right; i++)
            array[i] = temp[i-left];
    }
    ***************************************/
    /*************************************
    *思路二
    void reOrderArray(vector<int> &array) {
        int len = array.size();
        if(len < 2)
            return;
        
        vector<int> temp;
        for(int i = 0; i < len; i++)
        {
            if(array[i] & 1)
                temp.push_back(array[i]);
        }
        for(int i = 0; i < len; i++)
        {
            if((array[i] & 1) == 0)
                temp.push_back(array[i]);
        }
        array = temp;
        ***************************/
        /***************************
        *思路三
        ***************************/
        int len = array.size();
        if(len < 2)
            return;

        for(int i = 0; i < len; i++)
        {
            if(array[i] & 1)
            {
                int temp = array[i];
                for(int j = i-1; j >= 0 && (array[j]&1) == 0; j--)
                {
                    int t = array[j+1];
                    array[j+1] = array[j];
                    array[j] = t;
                }
            }
        }
    }
};
