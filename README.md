# DamnOffer_NK
牛客网《剑指offer》编程题集

此任务始于2018年11月12日中午


- **01.cpp  从尾到头打印链表**

    从头到尾遍历链表，将元素一次插入 vector 容器中.
    ```
    vec.insert(vec.begin(), node->val);
    ```
    注意链表遍历时的边界问题.
- **02.cpp  在二维数组中查找**

    直接暴力遍历搜索会超时.

    从左上向右下边判定边搜索，也会因为判定超时.

    从左下角元素开始搜索，在纵向向上递减，横向向右递增，所以判断情形简单：若大于目标值，向上；若小于目标值，向右.

    从右上角元素开始亦可。
- **03.cpp  替换空格**

    需要注意题干的真实含义：给出的是一个长度固定的字符数组和当前存储的字符串的长度。

    所以需要在原数组中拓展字符串，故存在替换后越界的问题。

    另外，从后向前填入新字符串可以减少交换次数。

- **04.cpp  重建二叉树**

    关键思路：

    前序遍历序列的第一个元素即为树的根节点；

    中序遍历序列的根节点在序列中心，将序列分为两部分：左子树部分和右子树部分；

    前序和中序遍历序列属于同一子树的元素是相连的。

    所以在每一步时将左右子树区分开来，用相同的规则递归处理即可。

    **需要注意的是，序列中边缘元素的序号**

- **05.cpp  两个栈实现队列**

    栈的性质：先入后出；队列的性质：先入先出。

    在两个栈直接互相存取元素即可完成元素位置的颠倒：一个栈专门用于入队操作；一个栈用于出队操作。将其中一个栈置空，则另一个栈得到倒置的元素序列。

- **06.cpp  旋转数组中的最小值**

    根据题干中对旋转数组的定义可知，数组的最小值是两个递减子数组的分界点，且左侧的子数组元素都大于等于右侧的子数组元素。

    故只需要比较相邻两个元素的值，第一次出现 i元素大于i+1元素的位置返回i+1元素即可。

    若未出现上述情况，说明数组元素全部相等，直接返回第一个元素即可。

- **07.cpp  斐波那契数列**

    用递归方式会超时。

    因为题干中指出了n的范围，所以可以初始化一个数组备查。比较方便也很取巧。

    还可以采用以循环代替递归的方式进行计算。

- **08.cpp  跳台阶**

    分析出问题的实质，解题就不复杂。

    考虑逆过程：如果青蛙要到达第n级台阶，那么只能从第n-1级或第n-2级起跳，因为它只能跳1级或2级。
    
    所以有f(n) = f(n-1)+f(n-2).斐波那契数列。

    另外有f(1)=1, f(2)=2.

- **09.cpp  变态跳台阶**

    与上一题类似，不同的是青蛙可以一次跳任意n级。所以对于到达第n级的青蛙，分段考虑其位置：它可能经过了第n-1级，然后又跳过1级；也可能跳过n-2级，再跳2级； ......

    所以有f(n) = (f(n-1)+f(1))+(f(n-2)+f(2))+...+(f(n-(n-1))+f(n-1))+f(n-n).
    
    代入n-1有：f(n-1) = (f(n-2)+f(1))+(f(n-3)+f(2))+...+f(n-n).

    可得：f(n)=f(n-1)*2.

    有f(0) = 0, f(1) = 1.

- **10.cpp  矩形覆盖**

    青蛙跳台阶问题的变体。小矩形有两种覆盖的方式：一种是横向，每次从n中覆盖的长度为2；一种是纵向，每次覆盖掉的长度为1.

    用08的代码即可。

- **11.cpp  二进制中1的个数**
