题目描述

求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

思路一：

使用递归函数和逻辑与短路原理。

思路二：

直接利用位移写出一个乘法。原理就是，类似快速幂，俗称快速模乘。a * b可以这样算，把a拆成2的幂的和，a = 2^e0 + 2^e1 + 2^e2....

那么 a * b = (2^e0 + 2^e1 + 2^e2+...) * b = b * 2^e0 + b * 2^e1 + b * 2^e2 + ... = (b << e0) + (b << e1) + ....

先参考使用while的例子

res = 0

while(a){

    if(a & 1) res += b;
    
    a >>= 1;
    
    b <<= 1; 
    
}

再转换，用(a & 1) == 1和(a != 0)来代替判断语句。

思路三：

用构造函数来解。
