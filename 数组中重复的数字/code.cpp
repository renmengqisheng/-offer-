class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    /************************************************************
    *思路一
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers == nullptr || length <= 0) return false;
        
        for(int i = 0; i < length; i++)
            if(numbers[i] < 0 || numbers[i] >= length)
                return false;
        
        unordered_map<int, int> m;
        for(int i = 0; i < length; i++) ++m[numbers[i]];
        for(int i = 0; i < length; i++)
            if(m[numbers[i]] > 1)
            {
                *duplication = numbers[i];
                return true;
            }
        return false;
    ************************************************************/
    /************************************************************
    *思路二
    ************************************************************/
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers == nullptr || length <= 0) return false;
        
        for(int i = 0; i < length; i++)
            if(numbers[i] < 0 || numbers[i] >= length)
                return false;
        
        for(int i = 0; i < length; i++)
            while(i != numbers[i])
            {
                if(numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }
                int t = numbers[i];
                numbers[i] = numbers[t];
                numbers[t] = t;
            }
        return false;
    }
};
