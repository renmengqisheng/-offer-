class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<int, int> m;

        for(auto i: str) m[i]++;
        for(int i = 0; i < str.size(); i++) 
            if(m[str[i]] == 1)
                return i;

        return -1;
    }
};
