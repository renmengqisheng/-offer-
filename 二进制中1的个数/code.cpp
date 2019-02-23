class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         int flag = 1;
         while(n != 0)
         {
             /********************
             *思路一
             if(n & 1)
                 count++;
             n = (unsigned)n >> 1;
             *********************/
             
             /********************
             *思路二
             if(n & flag)
                 count++;
             flag <<= 1;
             if(flag == 0)
                 break;
             ********************/
             
             /**************
             *思路三,最优解
             **************/
             count++;
             n = n & (n-1);
             
         }
         return count;
     }
};
