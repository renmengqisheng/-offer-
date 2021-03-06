题目描述

给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

思路一：

传统公式求解时间复杂度O(n)

思路二：

简单快速幂,时间复杂度O(logn):

1.全面考察指数的正负、底数是否为零等情况。

2.写出指数的二进制表达，例如13表达为二进制1101。

3.举例:10^1101 = 10^0001 * 10^0100 * 10^1000。

4.通过&1和>>1来逐位读取1101，为1时将该位代表的乘数累乘到最终结果。

注意：为什么要用long long? int类型abs(INT_MIN)会溢出并且依然是负数，abs(INT_MIN) = INT_MIN，负数右移操作会在最高位补1（比如-1右移永远是-1）就死循环了。


思路三：

剑指书中细节：

1.当底数为0且指数<0时，会出现对0求倒数的情况，需进行错误处理，设置一个全局变量；

2.判断底数是否等于0，由于base为double型，不能直接用==判断；

3.优化求幂函数

当n为偶数，a^n =（a^n/2）*（a^n/2）；

当n为奇数，a^n = a^[(n-1)/2] * a^[(n-1)/2] * a；

时间复杂度O(logn)
