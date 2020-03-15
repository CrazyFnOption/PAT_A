# 浙大甲级PAT考试 练习题总结

**大家有兴趣可以去考一考，比acm简单，但是不允许带任何代码书，算法书，原本的考试的意义就是为了让考生独立的编码，锻炼思维能力，一般浙大的本科书估计在70分到80分左右**

下面是本人在开始写题目的时候，记录的笔记，相对于本人而言的困难度，希望贴出来对大家有帮助，下次有时间更新顶级。


|题目编号 | 算法所涉及知识点 | 困难程度 | 易错点 | 备注|
-|-|-|-|-
|1001.A+B Format | 简单模拟，输入输出 | 1 | 基本上没问题 | 简单题|
|1002.A+B for Polynomials | 简单模拟，基于多项式 | 2 | 注意考虑0的边界情况，其次输入输出的问题 | 也是简单题，但是怕自己出错|
|1003 Emergency|涉及到图论dijkstra 算法|4|图论的板子需要好好的记住|板子题，但是还需要多练习|
|1004 Counting Leaves|dfs深搜|5|如何通过递归计算相应的值|自己完全没有想到的题目|
|1005 Spell It Right|map的运用，简单模拟|1|map的使用|简单题|
|1006 Sign In and Sign Out|简单模拟题|1|记住不仅可以用substr，还可以直接用scanf加上格式读取|简单题|
|1007 Maximum Subsequence Sum|最大连续子序列之和|3|dp的时候要dp代表的是什么，读懂题目意思|动态规划|
|1008 Elevator|简单模拟|1|简单题|无|
|1009 Product of Polynomials|标准模拟|2|考虑为0的情况|使用了set里面内部排序的方法|
|1010 Radix|二分查找、进制模拟|3|二分查找数的边界问题|用顺序查找总是过不了全部杨丽，这里就只能使用二分查找了|
|1011 World Cup Betting|简单模拟|1|读懂题目意思|无|
|1012 The Best Rank|标准模拟|3|存在并列排名的情况|重复代码请使用函数|
|1013 Battle Over Cities|dfs遍历，并查集|5|题目意思进行转换很重要|这里可以用两种方法分别实现以下|
|1014 Waiting in Line|困难模拟|5|逻辑问题，以及时间问题|比较时间可以设置一个初值，然后两者同时进行比较，这样省事|
|1015 Reversible Primes|进制转换，简单模拟|2|读懂题目意思，并且1和0不属于质数，卡了这个数据|无|
|1016 Phone Bills|标准模拟|3|代码量有点多，还是时间问题|设定一个初值去比较时间远比逻辑考虑轻松多了|
|1017 Queueing at Bank|标准模拟|4|主要就是模拟窗口问题|队列窗口，同时只处理一个计算时间，不需要完全模拟过程|
|1018 Public Bike Management|Dijkstra+Dfs|5|路径回溯，并且计算权值|dfs直接使用回溯在前面记录好的路径|
|1019 General Palindromic Number|进制转化，回文数|2|string 不能存储超过2位数的字符，所以要用vector|无|
|1020 Tree Traversals|二叉树的遍历方式|5|给出方式求另外几种遍历方式|注意递归的顺序|
|1021 Deepest Root|dfs+并查集|5|两种方法，并查集和联通图|题目要求是从每一个点去遍历，而不是按照样例给出的顺序|
|1022 Digital Library|stringstream、map映射|2|stringstream的清空方式|不要加最前面两行代码|
|1023 Have Fun with Numbers|java大数裸过|2|熟悉一下java的写法|无|
|1024 Palindromic Number|java大数中string的类别|3|string，stringbuild，stringbuffer，三种区别|无|
|1025 PAT Ranking|结构体排序|1|结构体排序|无|
|1026 Table Tennis|困难模拟|4|round up是四舍五入的意思|这里自己的代码还有一个样例没有过，28/30|
|1027 Colors in Mars|二分进制转换|2|二位进制转换，直接用string存入就行|答案方法很简单|
|1028 List Sorting|排序|1|排序|无|
|1029 Median|内存优化|6|边读入，边处理|第一次遇到这种题|
|1030 Travel Plan|Dijkstra+Dfs|3|与前面类似|无|
|1031 Hello World for U|找规律|1|找规律|无|
|1032 Sharing|一对一映射|3|直接映射读入即可|自己想复杂了，后面发现因为元素只有一个，映射起来就方便|
|1033 To Fill or Not to Fill|标准贪心|6|贪心策略的逻辑容易出错|有的变量一定要用double，很有意思的一道题，可以再做一遍|
|1034 Head of a Gang|dfs或并查集|3|我没有用题目要求的知识点，直接用set裸过的|记住 代码样式中的特殊情况|
|1035 Password|字符串的简单处理|2|注意pair类型|无|
|1036 Boys vs Girls|结构体排序|1|结构体输入|无|
|1037 Magic Coupon|简单排序|1|简单排序|无|
|1038 Recover the Smallest Number|神奇排序|4|完全没有想到排序的函数还可以这样写|无|
|1039 Course List for Student|哈希映射|4|使用map映射会超时|注意离散化的具体细节|
|1040 Longest Symmetric String|暴力判断|1|纯暴力判断回文数|本来以为有什么复杂的算法，没想到后面纯暴力|
|1041 Be Unique|简单计数|2|看错题导致错误|第一个独立的数字|
|1042 Shuffling Machine|简单枚举|1|无|无|
|1043 Is It a Binary Search Tree|建立二叉平衡树|5|两种办法，模拟和规律找节点|这两种方法都必须掌握|
|1044 Shopping in Mars|二分法|5|当数字大于1e5的时候，就不能开二维数组了|记住 upper_bound函数|
|1045 Favorite Color Stripe|LIS or LCS|4|两种办法，弄清楚状态转移方程|两种方法都写一遍|
|1046 Shortest Distance|简单环状距离|2|不要过于复杂的算法想这道题|无|
|1047 Student List for Course|离散化|3|类似于前面的离散化|无|
|1048 Find Coins|双指针，二分，哈希标记|3|很神奇的一道题，三种方法|无|
|1049 Counting Ones|左右分开计算，顶级模拟，找规律|5|觉得如果在写一遍可能写不出来|记住每一位的数量，找到规律|
|1050 String Subtraction|标记模拟|3|自己竟然去模拟删除过程，直接标记就行了|无|
|1051 Pop Sequence|栈的模拟|4|思路是清楚的，需要自己写一遍|栈的容量是有限制的|
|1052 Linked List Sorting|链表排序模拟|3|自己写一遍 免得忘记了|无|
|1053 Path of Equal Weight|dfs|4|全局变量与局部变量|看清楚题目要求|
|1054 The Dominant Color|简单模拟|1|简单模拟|无|
|1055 The World's Richest|简单排序|1|结构体简单排序|无|
|1056 Mice and Rice|分组排序|3|读懂题目后面排名的意思|无|
|1057 Stack|树状数组或线段树|5|树状数组的写法|lowbit的写法|
|1058 A+B in Hogwarts|简单的a+b与进位|1|垃圾题，题目意思表明不清楚|垃圾题|
|1059 Prime Factors|一个一个去判断，不需要去打表|3|打表的话 主要是数字太大了，存不下去。|可以打一部分表，然后通过表来进行判断是否质数|
|1060 Are They Equal|高级模拟|4|等清醒的时候在做一遍|注意各种特殊数据|
|1061 Dating|英文题？？？|2|神奇的题目考英文的阅读理解|无|
|1062 Talent and Virtue|简单排序|1|简单排序|无|
|1063 Set Similarity|STL的简单运用|2|水题|无|
|1064 Complete Binary Search Tree|完全二叉树|5|完全二叉树的性质，以及中序遍历与二叉树关系|无|
|1065 A+B and C (64bit)|大数裸过|2|java大数|无|
|1066 Root of AVL Tree|平衡二叉树(红黑树变换)|5|在于向左右旋转的操作|注意四种变换方式|
|"1067 Sort with Swap(0|i) "|贪心、简易版路径压缩|4|贪心策略，以及时间控制好|一定要记住，这类题要记得存点位置|
|1068 Find More Coins|01背包，记录序列|5|整体思路出错，完全没有想到是一道背包题，神奇|背包题目，也可以借用状态来进行回溯|
|1069 The Black Hole of Numbers|字符串处理，简单题|2|这道题有补上0的情况|边边角角的数据总是让你弄不到满分|
|1070 Mooncake|简单贪心|2|当时被背包魔障了，竟然想到多重背包去了|醉了|
|1071 Speech Patterns|字符串处理|3|两个函数要记住|要记住读题|
|1072 Gas Station|中规中矩的dijkstra题目|2|一次性过了|多种排列的相结合|
|1073 Scientific Notation|简单模拟|2|调试了有点长时间的bug|无|
|1074 Reversing Linked List|链表排序模拟|3|主要是看错题了，这种类型的题目掌握技巧|还是坐标记录位置|
|1075 PAT Judge|细节模拟，排序|2|有时间再去写，有点小复杂|无|
|1076 Forwards on Weibo|dfs或bfs|4|用dfs写的时候由于递归层数有点多，会超时，但是用bfs就不会|注意dfs里面细节，这里自己经常出错|
|1077 Kuchiguse|简单字符串替换|1|简单题|无|
|1078 Hashing|二次探测法 哈希|4|弄懂二次探测和线性探测|无|
|1079 Total Sales of Supply Chain|dfs或bfs|1|我用的是路径压缩，然后存取利息|无|
|1080 Graduate Admission|30分的水题，简单模拟排序|2|看清楚题意，主要有一个排序相等的过程处理|无|
|1081 Rational Sum|gcd或者lcm|3|到时候自己需要写一遍，免得搞忘|特别是gcd与lcm的公式勿忘|
|1082 Read Number in Chinese|标准字符串处理|4|有意思的字符串处理题目|注意0，10，100，1000这样标志位的处理|
|1083 List Grades|简单排序|1|这类题目就是英文题|无|
|1084 Broken Keyboard|简单标记|3|标记的方法|无|
|1085 Perfect Sequence|二分法，双指针法|4|记住upper_bound的用法|特别是自己会去实现|
|1086 Tree Traversals Again|根据 两种遍历写其他遍历|5|注意前序遍历与堆栈的关系|栈实现的 就是前序遍历 在这道题|
|1087 All Roads Lead to Rome|dijksra + dfs|4|就是条件有点多罢了，注意活用变量，并且注意dfs的顺序问题|无|
|1088 Rational Arithmetic|分数的四则运算，需要花点时间写一下|4|需要注意一下，gcd的问题|无|
|1089 Insert or Merge|插入排序和归并排序|4|有的时候可能会忘记代码怎么实现呢的|无|
|1090 Highest Price in Supply Chain|dfs|2|利用dfs计算层数|无|
|1091 Acute Stroke|三个维度的BFS|3|自己写一遍 印象应该会更深刻|无|
|1092 To Buy or Not to Buy|字符串哈希|2|记录字符位置|需要记住的是 记录字符的话 将数组开到256以上|
|1093 Count PAT's|字符串记录|5|使用左边的值乘以右边的值|字符位置的记录|
|1094 The Largest Generation|dfs或者bfs|4|dfs这个地方会超时，因为要运行所有的点，不像bfs到了就停止|无|
|1095 Cars on Campus|逻辑模拟|5|类似于前面的题目，需要重新理一下逻辑|无|
|1096 Consecutive Factors|计算连续相乘的质因数，暴力|3|弄清楚该怎么写|无|
|1097 Deduplication on a Linked List|链表模拟|3|不需要去弄清楚每一个节点的下一个值，直接用vector模拟即可|无|
|1098 Insertion or Heap Sort|堆排序|5|关于堆排序|堆排序的代码容易忘记，所以需要自己在写一遍|
|1099 Build A Binary Search Tree|建造一个二叉搜索树|4|因为做多了这一类的题目，所以这道题对于我来说是一道简单题|无|
|1100 Mars Numbers|字符串模拟简单题|2|无|无|
|1101 Quick Sort|快速排序的主元安排|4|注意题目中不仅有主元，还要考虑当前的最大值|无|
|1102 Invert a Binary Tree|二叉树|3|注意题目中and的问题|无|
|1103 Integer Factorization|dfs加上背包|5|完全没有想到这道题的做法，这道题就是一道好题|无|
|1104 Sum of Number Segments|计算个数，最后相乘得到结果|3|仅仅只是常规做法，那么一定会超时|无|
|1105 Spiral Matrix|输入输出特殊方阵|5|记住这里寻找方阵的长和宽的办法|根据依次平方相除来看|
|1106 Lowest Price in Supply Chain|简单dfs|4|这里跟你前面的一道题一样，只不过这里最好再写一遍|无|
|1107 Social Clusters|简单dfs|3|自己当时一发AC|无|
|1108 Finding Average|暴力|2|无|无|
|1109 Group Photo|模拟方阵|4|最怕这种复杂的逻辑类型|无|
|1110 Complete Binary Tree|完全二叉树的判断|2|注意查找根节点|无|
|1111 Online Map|dfs+dijkstra|5|模板题，最好是在写一遍|尽量还可以试试dfs放在dijkstra里面|
|1112 Stucked Keyboard|简单模拟|4|直接保证是整数倍即可，读懂题目意思|无|
|1113 Integer Set Partition|特别特别机智的模拟|2|无|无|
|1114 Family Property|模拟加上并查集|5|需要自己写一遍|无|
|1115 Counting Nodes in a BST|二叉树计算节点|3|仔细看一下题目意思，防止定义的地方出错|建树的方法不要出错|
|1116 Come on! Let's C|简单模拟 考验手速的时候到了|1|无|无|
|1117 Eddington Number|题目意思|2|这道题难就难在英语的阅读理解上了|无|
|1118 Birds in Forest|并查集 或者 set|2|简单题|无|
|1119 Pre- and Post-order Traversals|求解中序遍历是否唯一|5|好题，求解树的好题。|注意清楚中序遍历唯一的条件，并且看看自己尝试换一种写法|
|1120 Friend Numbers|低级模拟|1|水题|无|
|1121 Damn Single|STL的运用|2|stl的运用|无|
|1122 Hamiltonian Cycle|简单的循环图判断|3|刚开始写时候有慌了，但是后面看懂题意之后就不会这么觉得了|无|
|1123 Is It a Complete AVL Tree|构造avl树和判断完全树|5|模板题，需要再写一遍|注意向左转 向右转这两个函数该怎么写。|
|1124 Raffle for Weibo Followers|简单模拟|1|无|无|
|1125 Chain the Ropes|简单模拟|2|排序之后简单的模拟|round 四舍五入 cell向上取整 floor向下取整|
|1126 Eulerian Path|欧拉回路|5|欧拉回路的知识点|遍历图的方式 这道题 最好选用的是BFS|
|1127 ZigZagging on a Tree|二叉树 记录层数|4|利用二叉树记录层数的办法记下二叉树，然后再按照相应的办法去遍历|注意dfs的写法|
|1128 N Queens Puzzle|N皇后问题|3|可以再写一遍，因为有点不懂答案的意思|无|
|1129 Recommendation System|简单模拟 排序|2|逻辑构造|无|
|1130 Infix Expression|前缀表达式|5|注意有返回的（格式限制）的dfs（前序遍历）|记住在根节点这里有点特殊的地方|
|1131 Subway Map|复杂BFS|5|很多坑，有点复杂，建议自己去写一遍|无|
|1132 Cut Integer|简单模拟|1|无|无|
|1133 Splitting A Linked List|链表模拟|2|以前一模一样的问题|无|
|1134 Vertex Cover|两种做法 set和边标记|2|第二种做法可以作为写其他题目的思路|无|
|1135 Is It A Red-Black Tree|红黑树的性质检验|5|不要妄想出其他红黑树理想当然的性质|无|
|1136 A Delayed Palindrome|回文数判断|2|判断回文数的函数|无|
|1137 Final Grading|简单模拟|2|STL的简单运用|无|
|1138 Postorder Traversal|求解后序遍历|3|自从写多了之后，这道题就是一道简单题目了|需要注意超时问题，必须要退出递归才能不超时|
|1139 First Contact|复杂模拟|4|可以直接用vector<int>v[10000]去存 原本存不下的东西|无|
|1140 Look-and-say Sequence|简单模拟|1|字符串模拟|无|
|1141 PAT Ranking of Institutions|层次模拟|2|简单模拟|注意有的时候要使用 unordered_map|
|1142 Maximal Clique|图论中的简单模拟|3|无|无|
|1143 Lowest Common Ancestor|平衡二叉树中的LCA|4|利用平衡二叉树的性质|递归不要写错了|
|1144 The Missing Number|简单模拟|1|无|无|
|1145 Hashing - Average Search Time|哈希，求取平均查找时间|5|主要就是二次探测法|无|
|1146 Topological Order|拓扑排序|4|主要就是拓扑排序的知识点|无|
|1147 Heaps|模拟堆|3|注意在堆中 根与节点之间的关系|无|
|1148 Werewolf - Simple Version|难度模拟|5|狼人杀|无|
|1149 Dangerous Goods Packaging|暴力枚举|2|无|无|
|1150 Travelling Salesman Problem|复杂模拟 判断|4|注意各种情况之间的判断关系|无|
|1151 LCA in a Binary Tree|普通二叉树的LCA|5|两种方法，这两种方法都必须掌握|无|
|1152 Google Recruitment|简单模拟|2|质数 加上stl简单运用|无|
|1153 Decode Registration Card of PAT|排序 模拟|2|无|无|
|1154 Vertex Coloring|二分图的颜色匹配|5|无|无|
|1155 Heap Paths|堆模拟 加上路径打印|5|路径打印中递归的写法|自己就错在路径打印中|
