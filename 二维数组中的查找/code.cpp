class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size() == 0)
            return false;
        
        int rows = array.size();
        int cols = array[0].size();
        
        /***********************************************************
        *解法一：对每一行使用二分查找，时间复杂度为O(rows*log（cols))
        ************************************************************/
        for(int row = 0; row < rows; row++)
        {
            if(target > array[row][cols-1])
                continue;
            
            int colleft = 0, colright = cols-1;
            while(colleft <= colright)
            {
                int middle = (colleft+colright)/2;
                if(target == array[row][middle])
                    return true;
                else if(target > array[row][middle])
                    colleft = middle+1;
                else
                    colright = middle-1;
            }
        }
        /*******************************************
        **解法二：从左下角出发，时间复杂度为O(rows+cols)
        int row = rows-1, col = 0;
        while(row >= 0 && col < cols)
        {
            if(array[row][col] == target)
                return true;
            else if(array[row][col] < target)
                col++;
            else
                row--;
        }
        ******************************************/
        return false;
    }
};
