class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if(A.empty()) return vector<int>();
        
        vector<int> b(A.size());
        b[0] = 1;
        for(int i = 1; i < A.size(); i++)
            b[i] = b[i-1] * A[i-1];
        
        int t = 1;
        for(int i = A.size()-1; i >= 0; i--)
        {
            b[i] *= t;
            t *= A[i];
        }
        return b;
    }
};
