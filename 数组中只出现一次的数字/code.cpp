class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2) return;
        
        int temp = 0;
        for(int i:data) temp ^= i;
        
        int index = 0;
        while(temp)
        {
            if(temp&1) break;
            index++;
            temp >>= 1;
        }
        
        for(int i:data)
        {
            if((i >> index)&1)
                *num1 ^= i;
            else *num2 ^= i;
        }
    }
};
