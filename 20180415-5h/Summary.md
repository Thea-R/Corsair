赛码“BestCoder”杯中国大学生程序设计，周末pk赛，组队第一场，打得不错。

[Link](http://icpc.njust.edu.cn/Contest/5696/)



## Problem

| 标签   | 题目                                       | AC / Submit |
| ---- | ---------------------------------------- | ----------- |
| A    | [Movie](http://icpc.njust.edu.cn/Contest/5696/A/) | 13 / 47     |
| B    | [Cycle](http://icpc.njust.edu.cn/Contest/5696/B/) | 3 / 22      |
| C    | [Segment](http://icpc.njust.edu.cn/Contest/5696/C/) | 6 / 17      |
| D    | [Brackets](http://icpc.njust.edu.cn/Contest/5696/D/) | 0 / 0       |
| E    | [Game](http://icpc.njust.edu.cn/Contest/5696/E/) | 8 / 9       |
| F    | [Repeating](http://icpc.njust.edu.cn/Contest/5696/F/) | 0 / 0       |
| G    | [GAL](http://icpc.njust.edu.cn/Contest/5696/G/) | 0 / 11      |
| H    | [Occupation](http://icpc.njust.edu.cn/Contest/5696/H/) | 0 / 0       |
| I    | [Exploration](http://icpc.njust.edu.cn/Contest/5696/I/) | 7 / 18      |
| J    | [GCD](http://icpc.njust.edu.cn/Contest/5696/J/) | 12 / 27     |



## Rank

| Rank | User                                     | Solved | Penalty | [A](http://icpc.njust.edu.cn/Contest/5696/A/) | [B](http://icpc.njust.edu.cn/Contest/5696/B/) | [C](http://icpc.njust.edu.cn/Contest/5696/C/) | [D](http://icpc.njust.edu.cn/Contest/5696/D/) | [E](http://icpc.njust.edu.cn/Contest/5696/E/) | [F](http://icpc.njust.edu.cn/Contest/5696/F/) | [G](http://icpc.njust.edu.cn/Contest/5696/G/) | [H](http://icpc.njust.edu.cn/Contest/5696/H/) | [I](http://icpc.njust.edu.cn/Contest/5696/I/) | [J](http://icpc.njust.edu.cn/Contest/5696/J/) |
| ---- | ---------------------------------------- | ------ | ------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
| 1    | [Corsair](http://icpc.njust.edu.cn/UserPage/Corsair/) | 6      | 662     | 50(-3)                                   | 122(-1)                                  | 62(-1)                                   |                                          | 102                                      |                                          | -3                                       |                                          | 176(-1)                                  | 30                                       |



## Solved

- [x] A	Movie（简单题）
- [x] B	Cycle（无向图找奇偶环）
- [x] C	Segment（猜结论）
- [x] D	**~~Brackets（线段树）~~**
- [x] E	Game（约瑟夫环）
- [ ] F	Repeating
- [x] G	**~~GAL（DP）~~**
- [ ] H	Occupation
- [x] I	Exploration（混合图找环）
- [x] J	GCD（构造、思维）

（完成的题打勾，且**~~赛后补的题加粗+删除线~~**）



## Solutions

##### [HDU 5215 Cycle](http://acm.hdu.edu.cn/showproblem.php?pid=5215)（无向图找奇偶环）              by Thea

1.  DFS标记深度（标记深度可以用染色代替），对于当前节点u，若子节点v已被访问过，当u和v的深度%2相等时两点之间路径为偶数边，否则为奇数边，加上当前边\<u, v>得到相应的奇环和偶环；
2.  坑点在于两个简单的奇环可以通过共享点或边得到”复合“偶环，所以每次在第一步中得到奇环时，判断该环上的点是否出现在其他奇环中，如果有则能得到符合偶环，用cnt数组标记即可；
3.  注意题目不保证图联通。



##### [HDU 5222 Exploration](http://acm.hdu.edu.cn/showproblem.php?pid=5222)（混合图找环）              by Thea

1.  先利用无向边建图找环，然后将现在的所有的连通图缩点；
2.  再根据有向边建图，若新边\<u, v>的两个顶点在第一步缩进了同一个点，得到环；
3.  新图BFS拓扑排序，若最后不能删除所有点，则得到环。（我也不知道为什么当时在这一步写了DFS… 大概是脑子瓦特了吧）



##### [HDU 5216 Segment](http://acm.hdu.edu.cn/showproblem.php?pid=5216)（猜结论）              by LucasZhao

1.  题目看上去有点像概率dp，不过猜了个结论：将array A和array B分别排序一下，这时对应的Ai和Bi是1~M的最优排列；
2.  这样，可以直接判不可能情况，再max（两边剩余长度、每个Bi+1-Ai的剩余长度）即可；



##### [HDU 5218 Game](http://acm.hdu.edu.cn/showproblem.php?pid=5218)（约瑟夫环）              by LucasZhao

1.  约瑟夫环，公式f[1]=0;  f[i]=(f[i-1]+m)%i; (i>1)，此题的m是集合中任意元素，因此直接遍历集合，每种都处理即可；
2.  令 dp\[i][j] 表示剩下i个人时，位置为j的人是否可能获胜。转移方程：if(dp\[i-1][j])dp\[i][(j+m[k])%i]=1;



##### [HDU 5223 GCD](http://acm.hdu.edu.cn/showproblem.php?pid=5223)（构造、思维）              by LucasZhao

1.  很cf的一题，明显构造，直接构造ans[i]为当前ans[i]和区间gcd的lcm即可，ans[i]初始化为1；
2.  由于有冲突要判断，因此再对构造后的结果查询一遍即可。



##### [HDU 5220 GAL](http://acm.hdu.edu.cn/showproblem.php?pid=5220)（dp）              by Steven

1.  先剪枝，在一个cha里面只有一个role的话，那么这个role就是必选的；
2.  接下来就是dp,把上一个状态用来求当前的状态。dp\[now][(s1|1LL<<to[],s2^k.magic)]+=dp\[pre][(s1,s2)]。k 遍历当前face里面的所有role，(s1,s2)为遍历前面所求的dp里面的所有状态，s1为cha的集合，s2为异或和。
3.  要用ll...


##### [HDU 5217 Brackets](http://acm.hdu.edu.cn/showproblem.php?pid=5217)（线段树）              by Thea

1.  性质一：最终匹配的序列是")))(("形式，则设置状态为每个节点中rs存当前区间匹配后剩余的左括号数，ls是右括号数；
2.  合并两个区间")(" + "))("：左区间的右括号和右区间的左括号取min值匹配，再更新对应的rs和ls；
3.  性质二：最终匹配的序列由多个子区间组成，对于这些区间，从左往右合并时右括号数是非递减的，从右往左合并时左括号数是非递减的；（很巧妙，比赛的时候就是忽略了这个性质，还是思考不够仔细）
4.  查询[l, r, k]：找出[l, r]中的所有子区间，若k<=[l, r].rs则寻找从左往右第k个括号的位置，否则寻找从右往左第[l, r].ls+[l, r].rs-k+1个括号的位置。