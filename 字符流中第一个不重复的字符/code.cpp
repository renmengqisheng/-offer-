class Solution
{
public:
    /***********************************************
    *思路一
    Solution()
    {
        index = 0;
        for(int i = 0; i < 128; i++) hash[i] = -1;
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if(hash[ch] == -1) hash[ch] = index;
        else hash[ch] = -2;
        index++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char tmp = '#';
        int small = INT_MAX;
        for(int i = 0; i < 128; i++)
            if(hash[i] >= 0 && hash[i] < small)
            {
                small = hash[i];
                tmp = (char)i;
            }
        return tmp;
    }
    
private:
    int index;
    char hash[128];
    *****************************************/
    /****************************************
    *思路二
    ****************************************/
    Solution()
    {
        for(auto &i:a) i = 0;
    }
    //Insert one char from stringstream
    void Insert(char ch)
    {
        ++a[ch];
        if(a[ch] == 1) q.push(ch);
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!q.empty() && a[q.front()] > 1) q.pop();
        if(!q.empty()) return q.front();
        return '#';
    }
private:
    queue<int> q;
    char a[128];
};
