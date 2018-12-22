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

    利用C++中的二进制位操作

- **12.cpp  数值的整数次方**

    求幂的操作可以做最基础的连乘操作，算法复杂度为O(n)，n是幂。
    
    也可以用快速幂算法求幂，复杂度为O(log(n))。

    另外还需要注意幂为负时的情况。

- **13.cpp  调整数组顺序使奇数位于偶数之前**

    新开一个数组用于存储，遍历数组一次用于读取奇数，再遍历一遍读取偶数，最后用容器之间的复制操作将新数组内容返回。

- **14.cpp  链表倒数第k个结点**

    一般的链表结点遍历操作。需要注意链表为空，以及k大于链表长度的情况，这也是题目考察“代码鲁棒性”的用意。

- **15.cpp  翻转链表**

    粗暴直接的方法：遍历链表，将元素记录在一个数组中，倒序遍历数组，重建逆序链表。

    不用新建数组和链表的方法：将原本的链表从前向后打断，重新组合顺序。

- **16.cpp  合并两个排序链表**

    递归版本：在当前的两个（子）链表中选出较小的作为首结点并返回。递归调用函数，参数为被选中结点之后的链表和未被选中的链表。

    非递归版本：比较复杂。

- **17.cpp  判断树的子结构**

    采用递归方法：
        
    首先考虑树为NULL的边界条件，若两树任一为NULL，则返回false。

    然后从判断根节点的值是否相等入手：若相等，则比较以根节点为根的子树的情况；若不相等，则分别在左右子树中找子结构。

- **18.cpp  二叉树镜像**

    从根节点开始依次调换左右子树即可。递归方法，终止条件是节点为NULL。

- **19.cpp  顺时针旋转打印矩阵**

    用循环模拟打印过程：从左上角开始打印，打印完第一行后，上边界下移；然后打印最右侧列，打印结束后右边界左移；打印最下面的行，下边界上移；打印最右侧列，右边界左移。循环以上过程，直到有边界出现交替的情况。

- **20.cpp  包含min函数的栈类型**

    要求min函数的时间复杂度为O(1)。基于栈遍历的方法时间复杂度为O(n)。
    
    可以考虑以空间换取时间的策略：引入一个辅助栈，专门用于存储主栈的最小值，需要min时直接返回辅助栈的栈顶即可。

    压入元素时，判断新元素是否比当前栈顶小，若小则压入，否则不压入。

    弹出时，判断被弹出的主栈栈顶是否与当前栈顶相等，若相等，弹出当前栈顶。

- **21.cpp  栈压入、弹出序列的判断**

    在人工判断某序列是否可能是特定输入序列的栈弹出序列时，有以下过程：

    不断压入元素，直到压入的元素与弹出序列的第一个元素相等；

    从弹出序列的第一个元素开始，不断弹出元素，直到栈尾出现与待弹出元素不相等的元素；

    继续压入元素，直到压入序列到达尾部。

    **如果循环结束时栈恰好为空，则两序列相匹配；反之则不匹配。**

- **22.cpp  自顶向下打印二叉树**

    二叉树的BFS，借助队列就可实现。

    但注意判断二叉树为空的情况。

- **23.cpp  判断序列是否为搜索二叉树后序遍历**

    搜索二叉树的性质：若树不为空，则其左子树所有结点值不大于自身值，右子树所有结点值不小于自身值。

    后序遍历的组成应该是：左子树序列+右子树序列+根节点。

    所以可以取出位于序列末尾的根节点值，根据右子树结点不小于根节点值的原则，将序列划分为两部分。
    
    在找划分位置时已经遍历了右子树结点，所以接下来判断左子树序列是否都不大于根节点。若大于，返回false。若不大于，将左右子树序列分别作为新的序列传入函数。

    以递归的方式解决问题。

    终止条件：
        
        若序列为空，返回false，因为空序列代表一棵空树；
        若序列的左端点与右端点重合或超过右端点，说明该部分序列全部满足要求，返回true；
        判断的左子树序列中存在大于根节点的节点，返回false。

- **24.cpp  二叉树中和为某一值的路径**

    **与二叉树相关的题目记得递归！**

    **与二叉树相关的题目记得递归！**

    **与二叉树相关的题目记得递归！**

    从根节点开始将当前结点值压入路径，并判断当前结点的值与剩余值是否相等。
    
    若相等且当前结点恰好为叶子结点（左右子树都为零），将当前结点加入路径，并返回这条路径所有结点。

    若上述条件不成立，则用同样的函数处理当前结点的左子树或右子树。

    注意：若搜索到叶子结点，仍未满足剩余值为零的条件，需回退一步，将当前结点弹出。

- **25.cpp  复杂链表的复制**

    第一步：将复制的结点插入在已有结点的后面，不更新复制结点random指针。

    第二步：更新复制结点random指针的指向。

    第三步：将链表拆成两条链表。

- **26.cpp  搜索二叉树转化为链表**

    二叉树相关题目用递归方法。

    搜索二叉树左子树所有结点都不大于根节点，右子树结点都不小于根节点。所以，可以分别得到左右结点组成的链表然后与根节点拼接。这是递归函数的核心内容。

    若左子树不空，调用递归函数传入左子树，得到左子树对应序列；右子树不空，调用函数得到右子树序列；
    左右子树同时为空，证明结点为叶子结点，返回结点本身即可。

    将根节点拼接在左右子序列的中间，再指针调整到序列的头部。
    
- **27.cpp  字符串的排列**

    将字符串中出现的元素所有可能的排列打印出来。

    考虑从头到尾生成字符串，即依次列举字符串第1位，第2位，直至最后一位的可能的情况。首先将字符串按字典顺序排序，保证会按字典顺序生成其排列。
    
    在确定第i位元素之后，可以将i依次与后边的元素互换，递归产生后边的元素。

    递归终止条件是所有字符串位处理结束。

- **28.cpp  数组中出现次数超过一半的数字**

    先对数组排序，使得相等元素相邻，然后引入一个计数器对元素边遍历边计数。

- **29.cpp  数组中最小的k个数**

    先排序，再取最小。

- **30.cpp  数组中最大子串和**

    F[i]表示截止第i个元素最大子串和，res表示全部数组的最大子串和。

    F[i] = max(F[i-1]+a[i], a[i])
        F[i-1]为负，则F[i]取a[i]，重置；
    
    res = max(res, F[i])    
        res被不断更新

    最后返回res的值

- **31.cpp 统计1的出现次数**

    分数位考虑，分别计算个位出现1的次数，十位出现1的次数，直至最高位出现1的次数。

    考虑一个数在百位上的1的个数。首先定义该数对100的商和余数： a=n/100; b=n%100;

    当该数百位数字大于1，即(a%10>1)，说明包含该数值之前的所有以1开头的全部三位数，n=(a/10)\*1000+(a%10)\*100+b，此时百位1的出现次数为100*（a/10+1）*100;

    当该数百位数字等于1，即(a%10==1)，说明包含了该数值之前的千数之前的所有以1开头的三位数以及部分千数之后以1开头的三位数，n=(a/10)\*1000+100+b，1的出现次数：100*(a/10)+(b+1);

    当该数百位数字等于0，即(a%10==0)，说明包含了该数值之前的千数之前的所有以1开头的三位数，n=(a/10)\*1000+b，1出现的次数：100*(a/10).

    其他各数位思路与此类似。

- **32.cpp 把数组排成最小的数**

    将数组按照组合后的字典顺序升序排列： 若A+B<B+A，则将A放在B的前边。

    按照这一顺序排列之后的数组元素组合起来将是最小数。

- **33.cpp 丑数**

    第1到10个丑数：1,2,3,4,5,6,8,9,10,12

    后面的丑数将重复前面的丑数\*2，\*3，\*5的规律，第i位丑数是第一个大于i-1位丑数的2或3或5的倍数中的最小的那个。

    因为丑数序列是递增的，所以不用每次都从第一位开始遍历，可以引入三个标记，分别记录上一个\*2,\*3,\*5的数所在的位置。产生新的丑数时直接以记录位置处的数值乘以对应的数值即可，然后将位置向后移。

- **34.cpp 字符串中第一个仅出现一次的字符位置**

    早知道能用map，在这儿绕啥。。。

    凡是STL里边的都可以用？

- **35.cpp 数组中的逆序对**

    暴力搜索，遍历全部数对的复杂度为O(n^2)。可以采用类似于归并排序的思想来做。

    将整个数组逐级分解，从最底层开始统计逆序对的数目，并及时对子序列排序，最终得到整个数组逆序对的和。

- **36.cpp 两个链表的第一个公共节点**

    题目中给出的链表结构仅有一个后向指针，说明若两个链表交叉，则交叉点后两者的结点完全重合。
    且无论如何两链表都会在结尾处的NULL重合。

    所以，先比较链表的长度，然后先遍历较长链表的一部分，然后同步遍历两链表。

- **37.cpp 数字在排序数组中出现的次数**

    可以直接遍历整个数组计数，但没必要。

    因为数组有序，所以当元素值与数字的大小关系发生反转时就可以停止遍历了。

- **38.cpp 二叉树的深度**

    递归的方式，从叶子逐层返回当前结点到叶子的最大路径长度，最终得到的就是树的深度。

- **39.cpp 判定平衡二叉树**

    左右子树深度差小于等于1的二叉树称为平衡二叉树。

    空树是平衡二叉树。

    用38的代码分别计算左右子树的深度，再判断二者的差即可。

- **40.cpp 找出数组中仅出现一次的数字**

    先将数组排序，再比较相邻数字是否相等，记录与左右侧元素不相等的数字即可。

- **41.cpp 和为S的连续正数序列**

    解方程：假设从n开始的m个数(n, n+1, n+2...n+m-1)和为S，则有n\*m+m\*(n+m)/2=S；

    从2开始遍历m的取值，可以解出n的值。只有当n为正整数时才是有效解。

    遍历的上界是(2*S)^0.5

- **42.cpp 和为S的整数对**

    由于数组是递增的，所以可以从数组两段分别开始搜索，i=0，j=l-1

    若a[i]+a[j]==S, 则符合条件；
    
    若a[i]+a[j]<S,则i及其之前的所有元素都不符合条件，因为i之前的元素都小于第i个元素；

    若a[i]+a[j]>S,则j之后的元素都不符合条件，因为j之后的元素都大于第j个元素。

    至于多组结果满足条件，添加一个筛选条件即可。

- **43.cpp 左旋转字符串**

    不断清除字符串第一个元素，并将之拼接在末尾即可。

    当字符串为空，返回空字符串。当n大于字符串长度，应将n置为 n%l，因为是循环的，可以减少循环次数。

- **44.cpp 翻转单词序列**

    比较简单，根据空格位置分割单词即可。注意边界条件，最后一个词可能被忽略。

- **45.cpp 扑克牌顺子**

    观察顺子的规律：最大值与最小值差值小于5；非零值不能重复；长度必须为5.

- **46.cpp 孩子们的游戏**

    约瑟夫环问题。

- **47.cpp 1到n求和**

    不能使用循环运算，可以考虑使用递归，每次向下传递参数值n-1。

    需要判定递归返回条件：n==0。可以使用 逻辑运算 && 判断：若左半部分不成立，则不再计算右半部分；若左半部分成立，计算右半部分。

- **48.cpp 不用加减乘除的求和**

    不用四则运算，只能用位运算。

    以5+7为例，

    首先计算两个二进制串不带进位的和：101+111=010。是为两二进制串异或操作。

    然后计算进位值：101+111=101，表示在哪一位计算时产生了进位。是为二进制串的与操作。

    由上边两个如何得到最终和呢？将进位串左移一位101<<1=1010，与求和串相加：1010+010=1100.

    重复以上过程，知道左移后的进位串为0.

- **49.cpp 字符串转化为整数**

    判定条件考虑是否充分。
    
    第一位可能是+/-符号，可能是数字，也可能是其他违规字符，需要判别。

    当第一位是+/-时，如果字符串只有一位，则违规。

    然后就可以从第二位开始遍历字符串，一旦遇到违规字符（不在'0'到'9'之内的），直接返回0；否则res*=10, res+=(str[i]-'0')。

- **50.cpp 数组中的重复数字**    

    引入辅助数组或辅助关系容器。

- **51.cpp 构建乘积数组**

    首先定义数组b的元素：
    b[0] = 1;

    b[1] = b[0] * A[0];

    b[2] = b[1] * A[1] = A[0]*A[1];

    ......

    b[n+1] = b[n] * A[n] = A[0]*...*A[n].

    然后更新b中的元素，tmp=1;

    tmp *= A[n], b[n-1] *= tmp = A[0]\*...\* A[n] , 

    tmp *= A[n-1], b[n-2] *= tmp = A[0]\*...\* A[n-1]\*

- **52.cpp 正则匹配字符串**

    就记住吧，记清楚所有的条件与分支。

- **53.cpp 判断字符串是否表示数字**

    同上。

- **54.cpp 字符流中第一个不重复的字符**

    首先解释题目的含义：字符流是指不断的调用Insert函数向字符串插入字符，然后不断的调用FirstAppearingOnce()函数对当前字符串进行检索、判断。

    所以，需要在两函数外定义一个字符串变量用来保存字符流。还可以用一个辅助数组来记录每一个字符出现的次数，由于 默认字符类型最多包括256个字符，所以一个长度256的数组就足够了。

- **55.cpp 带环链表中环的入口节点**

    复杂度较高的方法：用一个数组记录出现过的节点的地址，逐一比对，返回第一个重复的地址对应的节点。

    也可以用快和慢两个指针，快指针每次走两步，慢指针每次走一步，显然两个指针相遇；而后快指针回归起点，两者以同样的速度继续走。当两者再次相遇，即为环的入口。可以画图列算式证明。

- **56.cpp 删除链表中的重复元素**

    用递归的方法做。

- **57.cpp 二叉树中序遍历的下一个元素**

    根据二叉树排序的规则：
    
    如果节点指针为空，返回NULL；

    如果节点右子树不空，返回从该右子树根节点的左孩子向下遍历，输出第一个叶子节点；

    如果右子树为空，该节点是其父节点的左子树，返回其父节点即可。否则，遍历父节点的父节点，直到找到根节点。

    如果节点为根节点，返回NULL。

- **58.cpp 对称的二叉树**

    递归函数接收两个变量：需要对比的两节点的指针

    若两指针同时为空，返回true；

    若一个为空，一个不空，返回false；

    若两指针的值不等，返回false，否则比较他们孩子的结构(p1->left, p2->right) && (p1->right, p2->left)

- **59.cpp 二叉树之字形打印**

    引入一个中间vector，存储每层的数据，需要翻转时就逆序遍历。

- **60.cpp 二叉树逐行打印**

    上一题的精简版。

- **61.cpp 二叉树序列化和反序列化**

    序列化是指以DFS的方式，将树节点的值拼合在一起，用,分割，NULL用#表示。

    反序列化是指根据字符串，将树重新建立，分割规则同上。
 
 - **62.cpp 搜索二叉树第k小的节点**
 
    搜索二叉树的中序遍历会得到一个升序排列的序列。所以中序遍历二叉树并计数，当达到k时返回该节点即可。
    
- **63.cpp 数据流中的中位数**

    按照正常计算即可。在插入时，可以通过直接排序增加计算效率。
