class Solution {
public:
    /**********************
    *思路一
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty())
            return 0;
        
        int len = data.size();
        int l = len;
        int r = -1;
        for(int i = 0; i < len; i++)
            if(data[i] == k)
            {
                l = i;
                break;
            }
        for(int i = len-1; i >= 0; i--)
            if(data[i] == k)
            {
                r = i;
                break;
            }
        return r-l+1 <= 0?0: r-l+1;
    }
    ***************************/
    /**************************
    *思路二
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty())
            return 0;
        
        int len = data.size();
        int index = search(data, 0, len-1, k);
        if(index == -1) return 0;
        int left = index-1;
        int right = index+1;
        while(left >= 0 && data[left] == k) left--;
        while(right < len && data[right] == k) right++;
        return right-left-1;
    }
    
    int search(const vector<int> &data ,int l, int r, int k)
    {
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(data[mid] < k) l = mid+1;
            else if(data[mid] > k) r = mid-1;
            else return mid;
        }
        return -1;
    }
    *******************************/
    /*******************************
    *思路三
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty())
            return 0;
        
        int len = data.size();
        return searchright(data, 0, len-1, k)-searchleft(data, 0, len-1, k)+1;
    }
    
    int searchleft(const vector<int> &data, int l, int r, int k)
    {
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(data[mid] >= k) r = mid-1;
            else if(data[mid] < k) l = mid+1;
            //else if((mid > 0 && data[mid-1] != k) || mid == 0)
            //    return mid;
            //else
            //    r = mid-1;
        }
        return l;
    }
    
    int searchright(const vector<int> &data, int l, int r, int k)
    {
        int len = data.size();
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(data[mid] > k) r = mid-1;
            else if(data[mid] <= k) l = mid+1;
            //else if((mid+1 < len && data[mid+1] != k) || mid == len-1)
            //    return mid;
            //else l = mid+1;
        }
        return r;
    }
    ********************************/
    /*******************************
    *思路四
    *******************************/
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.empty())
            return 0;
        
        int len = data.size();
        return search(data, 0, len-1, k+0.5) - search(data, 0, len-1, k-0.5);
    }
    
    int search(const vector<int> &data, int l, int r, double k)
    {
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(data[mid] < k) l = mid+1;
            else if(data[mid] > k) r = mid-1;
        }
        return r;
    }
    
};
