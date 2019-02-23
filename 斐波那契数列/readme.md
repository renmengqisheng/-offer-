题目描述

大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39

思路：

这个题可以说是迭代（Iteration） VS 递归（Recursion），
f(n) = f(n-1) + f(n-2)，第一眼看就是递归啊，简直完美的递归环境，递归肯定很爽，这样想着关键代码两三行就搞定了，注意这题的n是从0开始的：

if(n<=1) return n;
else return Fibonacci(n-1)+Fibonacci(n-2);

然而并没有什么用，测试用例里肯定准备着一个超大的n来让Stack Overflow，为什么会溢出？因为重复计算，而且重复的情况还很严重，举个小点的例子，n=4，看看程序怎么跑的：
Fibonacci(4) = Fibonacci(3) + Fibonacci(2);

                    = Fibonacci(2) + Fibonacci(1) + Fibonacci(1) + Fibonacci(0);
                    
                    = Fibonacci(1) + Fibonacci(0) + Fibonacci(1) + Fibonacci(1) + Fibonacci(0);
                    
由于我们的代码并没有记录Fibonacci(1)和Fibonacci(0)的结果，对于程序来说它每次递归都是未知的，因此光是n=4时f(1)就重复计算了3次之多。

可以将暴力递归改成动态规划，以一定的空间代价避免代价更大的重复计算的栈空间浪费。

if(n<=1){

    return n;
    
}

int* record = new int[n+1];

record[0] = 0;

record[1] = 1;

for(int i=2;i<=n;i++){

    record[i] = record[i-1] + record[i-2];
    
}

return record[n];

  
再进一步优化，使用迭代法，用fn1和fn2保存计算过程中的结果，并复用起来。得到代码。



