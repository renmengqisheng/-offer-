class Solution {
public:
    /***************************************************
    *思路一
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold < 0 || rows <= 0 || cols <= 0) return 0;
        bool* visited = new bool[rows*cols]{false};
        int count = movingCount(threshold, rows, cols, 0, 0, visited);
        delete []visited;
        return count;
    }
    int movingCount(int threshold, int rows, int cols, 
                    int i, int j, bool* &visited)
    {
        if(i < 0 || i >= rows || j < 0 || j >= cols 
           || visited[i*cols+j] || getSum(i)+getSum(j) > threshold)
            return 0;
        visited[i*cols+j] = true;
        int count = 1 //+ movingCount(threshold, rows, cols, i-1, j, visited)
            + movingCount(threshold, rows, cols, i+1, j, visited)
            //+ movingCount(threshold, rows, cols, i, j-1, visited)
            + movingCount(threshold, rows, cols, i, j+1, visited);
        //visited[i*cols+j] = false;
        return count;
    }
    ****************************************************/
    /***************************************************
    *思路二
    ***************************************************/
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold < 0 || rows <= 0 || cols <= 0) return 0;
        bool *visited = new bool[rows*cols]{false};
        queue<int> q;
        int count = 0;
        q.push(0);
        visited[0] = true;
        while(!q.empty())
        {
            ++count;
            int t = q.front();
            q.pop();
            int i = t / cols, j = t % cols;
            if(check(rows, cols, i+1, j, threshold, visited))
            {
                int index = (i+1)*cols+j;
                q.push(index);
                visited[index] = true;
            }
            if(check(rows, cols, i, j+1, threshold, visited))
            {
                int index = i*cols+j+1;
                q.push(index);
                visited[index] = true;
            }
        }
        delete []visited;
        return count;
    }
    bool check(int rows, int cols, int i, int j, int threshold, bool *visited)
    {
        if(i < 0 || i >= rows || j < 0 || j >= cols || visited[i*cols+j] 
           || getSum(i)+getSum(j) > threshold)
            return false;
        return true;
    }
    int getSum(int num)
    {
        int sum = 0;
        while(num)
        {
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    
};
