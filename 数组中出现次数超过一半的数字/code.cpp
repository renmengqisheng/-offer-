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
    ************************************************/
    /***********************************************
    *思路三
    **********************************************/
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        if(len < 1) return 0;
        
        int mid = BFPRT(numbers, 0, len-1, (len+1)/2);
        int count = 0;
        for(auto n: numbers)
            if(n == mid) count++;
        
        if(count > len/2) return mid;
        else return 0;
    }
    
    int BFPRT(vector<int> &n, int l, int r, int k)
    {
        if(r-l+1 <= 5)
        {
            sort(n.begin()+l, n.begin()+r+1);
            return n[l+k-1];
        }
        
        int t = l-1;
        for(int st = l, ed; (ed = st+4) <= r; st += 5)
        {
            sort(n.begin()+st, n.begin()+ed+1);
            swap(n, l, ++t);
        }
        
        int mid = (l+t) >> 1;
        int pivot = BFPRT(n, l, t, mid-l+1);
        vector<int> index = partition(n, l, r, pivot);
        int m = l+k-1;
        if(index[0] <= m && m <= index[1]) return n[m];
        else if(index[0] > m) return BFPRT(n, l, index[0]-1, k);
        else return BFPRT(n, index[1]+1, r, m-index[1]);
    }
    
    vector<int> partition(vector<int> &n, int l, int r, int pivot)
    {
        int low = l-1;
        int high = r+1;
        int cur = l;
        while(cur < high)
        {
            if(n[cur] < pivot)
                swap(n, ++low, cur++);
            else if(n[cur] > pivot)
                swap(n, --high, cur);
            else cur++;
        }
        return vector<int>{low+1, high-1};
    }
    
    void swap(vector<int> &n, int a, int b)
    {
        int t = n[a];
        n[a] = n[b];
        n[b] = t;
    }
};
