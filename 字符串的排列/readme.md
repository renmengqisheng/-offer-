题目描述

输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。

输入描述:

输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

思路一：（类似带记忆的DFS，暴力搜索）

字符串中的每个字符均有可能出现在全排列的第一个位置，从头到尾从字符串中取出一个字符固定并记录，剩余的字符可以组成一个新字符串（即从原字符串中剔除取出的字符），对新字符串进行递归，直到新字符串长度为0，此时记录即为一种全排列，加入set中，set具有自动去重排序的功能。完成后将set中的元素赋值给vector并返回。

思路二：（递归版）

解析：http://www.cnblogs.com/cxjchen/p/3932949.html  (感谢该文作者！)

对于无重复值的情况

固定第一个字符，递归取得首位后面的各种字符串组合；

再把第一个字符与后面每一个字符交换，并同样递归获得首位后面的字符串组合；递归的出口，就是只剩一个字符的时候，递归的循环过程，就是从每个子串的第二个字符开始依次与第一个字符交换，然后继续处理子串。

假如有重复值呢？

由于全排列就是从第一个数字起，每个数分别与它后面的数字交换，我们先尝试加个这样的判断——如果一个数与后面的数字相同那么这两个数就不交换了。
 
 例如abb，第一个数与后面两个数交换得bab，bba。然后abb中第二个数和第三个数相同，就不用交换了。但是对bab，第二个数和第三个数不同，则需要交换，得到bba。由于这里的bba和开始第一个数与第三个数交换的结果相同了，因此这个方法不行。换种思维，对abb，第一个数a与第二个数b交换得到bab，然后考虑第一个数与第三个数交换，此时由于第三个数等于第二个数，所以第一个数就不再用与第三个数交换了。再考虑bab，它的第二个数与第三个数交换可以解决bba。此时全排列生成完毕！

思路三：（非递归版）

字典序排列算法

可参考解析： http://www.cnblogs.com/pmars/archive/2013/12/04/3458289.html  （感谢作者）

一个全排列可看做一个字符串，字符串可有前缀、后缀。

生成给定全排列的下一个排列.所谓一个的下一个就是这一个与下一个之间没有其他的。这就要求这一个与下一个有尽可能长的共同前缀，也即变化限制在尽可能短的后缀上。

例如：839647521是1--9的排列。1—9的排列最前面的是123456789，最后面的987654321，从右向左扫描若都是增的，就到了987654321，也就没有下一个了。否则找出第一次出现下降的位置。

【例】 如何得到346987521的下一个

1，从尾部往前找第一个P(i-1) < P(i)的位置

3 4 6 <- 9 <- 8 <- 7 <- 5 <- 2 <- 1

最终找到6是第一个变小的数字，记录下6的位置i-1

2，从i位置往后找到最后一个大于6的数

3 4 6 -> 9 -> 8 -> 7 5 2 1

最终找到7的位置，记录位置为m

3，交换位置i-1和m的值

3 4 7 9 8 6 5 2 1

4，倒序i位置后的所有数据

3 4 7 1 2 5 6 8 9

则347125689为346987521的下一个排列。
