class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n != 0)
         {
             /********************
             *思路一
             if(n & 1)
                 count++;
             n = (unsigned)n >> 1;
             *********************/
             
             /**************
             *思路二
             *************/
             count++;
             n = n & (n-1);
         }
         return count;
     }
};
