class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty())
            return false;
        /************************************
        *思路一
        stack<int> s;
        int push = 0;
        int pop = 0;
        int len = pushV.size();
        while(pop < len)
        {
            if(push < len)
            {
                if( pushV[push] <= popV[pop])
                    s.push(pushV[push++]);
            }
            else
            {
                if(!s.empty() && s.top() != popV[pop])
                    return false;
            }
            if(!s.empty() && s.top() == popV[pop])
            {
                s.pop();
                pop++;
            }
        }
        
        return true;
        **********************************/
        /*********************************
        *思路二
        *********************************/
        stack<int> s;
        int index = 0;
        for(int i = 0; i < pushV.size(); i++)
        {
            s.push(pushV[i]);
            while(!s.empty() && s.top() == popV[index])
            {
                s.pop();
                index++;
            }
        }
        return s.empty();
    }
};
