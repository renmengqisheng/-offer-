class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(!matrix || !str || rows <= 0 || cols <= 0) return false;
        
        bool* flag = new bool[rows*cols]{false};
        bool res = false;
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(hasPath(matrix, rows, cols, str, i, j, flag))
                {
                    res = true;
                    break;
                }
        delete []flag;
        return res;
    }
    bool hasPath(char* matrix, int rows, int cols,
                 char* str, int i, int j, bool* &flag)
    {
        if(i < 0 || i >= rows || j < 0 || j >= cols || 
           flag[i*cols+j] || matrix[i*cols+j] != *str)
            return false;
        flag[i*cols+j] = true;
        if(*(str+1) == '\0') return true;
        bool res = hasPath(matrix, rows, cols, str+1, i-1, j, flag) || 
            hasPath(matrix, rows, cols, str+1, i+1, j, flag) || 
            hasPath(matrix, rows, cols, str+1, i, j-1, flag) ||
            hasPath(matrix, rows, cols, str+1, i, j+1, flag);
        flag[i*cols+j] = false;
        return res;
    }

};
