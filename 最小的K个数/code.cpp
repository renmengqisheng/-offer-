class Solution {
public:
    /*************************************
    *思路一
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k < 1 || k > input.size())
            return vector<int>();
        
        if(input.size() == 1)
            return input;
        
        priority_queue<int> p;
        for(int i = 0; i < input.size(); i++)
        {
            if(i < k)
                p.push(input[i]);
            else if(p.top() > input[i])
            {
                p.pop();
                p.push(input[i]);
            }
        }
        vector<int> v;
        while(!p.empty())
        {
            v.push_back(p.top());
            p.pop();
        }
        return v;
    }
    *************************************/
    /**************************************
    *思路二
    ******************************/
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        //vector<int> vs;
        
        if(k <= 0 || k > input.size())
            return vector<int>();
        
        if(input.size() == 1)
            return input;
        
        BFPRT(input, 0, input.size()-1, k);
        vector<int> vs(input.begin(), input.begin()+k);
        
        //int topk = BFPRT(input, 0, input.size()-1, k);
        //for(int i = 0; i < input.size(); i++)
        //{
        //    if(input[i] < topk)
        //        vs.push_back(input[i]);
        //}
        //while(vs.size() < k) vs.push_back(topk);
        
        return vs;
    }
    
    int BFPRT(vector<int> &input, int l, int r, int k)
    {
        if(r-l+1 <= 5)
        {
            sort(input.begin()+l, input.begin()+r+1);
            return input[l+k-1];
        }
        
        int t = l-1;
        for(int st = l, ed; (ed = st+4) <= r; st += 5)
        {
            sort(input.begin()+st, input.begin()+ed+1);
            swap(input, ++t, st+2);
        }
        int mid = (l+t) >> 1;
        int pivot = BFPRT(input, l, t, mid-l+1);
        vector<int> index = partition(input, l, r, pivot);
        int m = l+k-1;
        if(index[0] <= m && m <= index[1]) return input[m];
        else if(index[0] > m) return BFPRT(input, l, index[0]-1, k);
        else return BFPRT(input, index[1]+1, r, m-index[1]);
    }
    
    vector<int> partition(vector<int> &input, int l, int r, int pivot)
    {
        int low = l-1;
        int high = r+1;
        int cur = l;
        while(cur < high)
        {
            if(input[cur] < pivot)
                swap(input, ++low, cur++);
            else if(input[cur] > pivot)
                swap(input, --high, cur);
            else cur++;
        }
        return vector<int>{low+1, high-1};
    }
    
    void swap(vector<int> &input, int l, int r)
    {
        int t = input[l];
        input[l] = input[r];
        input[r] = t;
    }
    
};
