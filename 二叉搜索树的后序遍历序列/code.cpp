class Solution {
public:
    /***********************************************
    *思路一
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        
        vector<int> mid(sequence);
        sort(mid.begin(), mid.end());
        return reTree(sequence, mid);
    }
    
    bool reTree(vector<int> sequence, vector<int> mid)
    {
        int len = sequence.size();
        if(len < 1)
            return true;
        
        int root = sequence[len-1];
        int i = 0;
        while(i < len)
        {
            if(root == mid[i])
                break;
            i++;
        }
        if(i == len)
            return false;
        bool right = reTree(vector<int>(sequence.begin()+i, sequence.end()-1), 
                            vector<int>(mid.begin()+i+1, mid.end()));
        bool left = reTree(vector<int>(sequence.begin(), sequence.begin()+i), 
                           vector<int>(mid.begin(), mid.begin()+i));
        return right && left;
    }
    ***************************************************/
    /***************************************************
    *思路二
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        
        return judge(sequence, 0, sequence.size()-1);
    }
    
    bool judge(vector<int> sequence, int left, int right)
    {
        if(left >= right)
            return true;
        
        //***********************************
        //分别从左到右和从右到左找到左右边界，如果右边界与左边界不相邻，返回false
        //int index = left-1, back = right;
        //while(index < right-1 && sequence[index+1] < sequence[right]) index++;
        //while(back > left && sequence[back-1] > sequence[right]) back--;
        //if(back - index != 1)
        //    return false;
        //***********************************
        //***********************************
        //从左到右找到左边界，如果是合法的后序遍历，则位于左边界右边的数都比根结点的数要大
        //***********************************
        int index = left-1;
        while(index < right-1 && sequence[index+1] < sequence[right]) index++;
        for(int i = index+1; i < right; i++)
            if(sequence[i] < sequence[right]) return false;
        
        return judge(sequence, left, index) && judge(sequence, index+1, right-1);
    }
    ***************************************/
    /*************************************
    *思路三
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len = sequence.size();
        if(len < 1)
            return false;
        
        for(int i = 0; i < len; i++)
        {
            bool sgn = false;
            for(int j = 0; j < i; j++)
            {
                if(sequence[j] > sequence[i])
                    sgn = true;
                else if(sgn)
                    return false;
            }
        }
        return true;
    }
    ************************************/
    /*************************************
    *思路四
    *************************************/
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len = sequence.size();
        if(len < 1)
            return false;
        
        int i = 0;
        while(sequence[i] < sequence[len-1]) i++;
        while(sequence[i] > sequence[len-1]) i++;
        if(i != len-1) return false;
        return true;
    }
};
