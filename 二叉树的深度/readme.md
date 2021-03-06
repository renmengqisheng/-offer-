题目描述

输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

思路一：（递归版）

递归得到左、右子树深度中的最大值，再加上本身的深度1，返回当前深度即可。

思路二：（迭代版）

用层序遍历求解，每遍历一层就加一。

经典的非递归层次遍历：利用辅助队列，先将头节点入队列，当队列不空时出队列的节点记为current，
当current左节点不空时入队列，其右节点不空时入队列，如此循环即可。

求深度：构造变量cur记录当前层访问到的节点数，width记录当前层的总个数，每当访问过一层层数deep++；
此种方法同时可以求最大宽度，访问第几层的第几个节点，是一种通用方法！
