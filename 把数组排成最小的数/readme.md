题目描述

输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

思路一：

先对整型数组进行排序，再用贪心法，对字符串a,b，如果ab > ba，按ba拼接，否则按ab拼接。时间复杂度O(nlogn)，空间复杂度O(1)。

思路二：

自定义比较器，对字符串a,b，如果ab <= ba，返回true，否则返回false。对原数组进行排序，最后转成string类型。
