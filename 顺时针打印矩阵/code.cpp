class Solution {
public:
    /*****************************************************
    *思路一
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if(matrix.empty())
            return vector<int>();
        
        return printMatrix(matrix, 0, matrix.size()-1, 0, matrix[0].size()-1);
    }
    
    vector<int> printMatrix(vector<vector<int> > matrix, 
                            int top, int bottom, int left, int right)
    {
        vector<int> v;
        if(top > bottom || left > right)
            return v;
        
        if(top == bottom)
        {
            for(int i = left; i <= right; i++)
                v.push_back(matrix[top][i]);
        }
        else if(left == right)
        {
            for(int i = top; i <= bottom; i++)
                v.push_back(matrix[i][left]);
        }
        else
        {
            for(int i = left; i <= right; i++)
                v.push_back(matrix[top][i]);
            for(int i = top+1; i <= bottom; i++)
                v.push_back(matrix[i][right]);
            for(int i = right-1; i >= left; i--)
                v.push_back(matrix[bottom][i]);
            for(int i = bottom-1; i >= top+1; i--)
                v.push_back(matrix[i][left]);
        }
        
        vector<int> sub = printMatrix(matrix, top+1, bottom-1, left+1, right-1);
        v.insert(v.end(), sub.begin(), sub.end());
        
        return v;
    }
    ********************************************/
    /******************************************
    *思路二
    ******************************************/
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> v;
        if(matrix.empty())
            return v;
        
        int top = 0, bottom = matrix.size()-1;
        int left = 0, right = matrix[0].size()-1;
        
        while(left <= right && top <= bottom)
        {
            for(int i = left; i <= right; i++) v.push_back(matrix[top][i]);
            for(int i = top+1; i <= bottom; i++) v.push_back(matrix[i][right]);
            if(top != bottom)
                for(int i = right-1; i >= left; i--)
                    v.push_back(matrix[bottom][i]);
            if(left != right)
                for(int i = bottom-1; i >= top+1; i--)
                    v.push_back(matrix[i][left]);
            
            left++, right--, top++, bottom--;
        }
        
        return v;
    }
};
