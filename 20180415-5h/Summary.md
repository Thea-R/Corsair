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

- [x] A	Movie（简单脑洞）
- [x] B	Cycle（无向图找奇偶环）
- [x] C	Segment
- [ ] D	Brackets
- [x] E	Game
- [ ] F	Repeating
- [ ] G	GAL
- [ ] H	Occupation
- [x] I	Exploration（混合图找环）
- [x] J	GCD

（完成的题打勾，且**~~赛后补的题加粗+删除线~~**）



## Solutions

##### [HDU 5215 Cycle](http://acm.hdu.edu.cn/showproblem.php?pid=5215)（无向图找奇偶环）       by Thea

1.  DFS标记深度（标记深度可以用染色代替），对于当前节点u，若子节点v已被访问过，当u和v的深度%2相等时两点之间路径为偶数边，否则为奇数边，加上当前边\<u, v>得到相应的奇环和偶环；
2.  坑点在于两个简单的奇环可以通过共享点或边得到”复合“偶环，所以每次在第一步中得到奇环时，判断该环上的点是否出现在其他奇环中，如果有则能得到符合偶环，用cnt数组标记即可；
3.  注意题目不保证图联通。



##### [HDU 5222 Exploration](http://acm.hdu.edu.cn/showproblem.php?pid=5222)（混合图找环）       by Thea

1.  先利用无向边建图找环，然后将现在的所有的连通图缩点；
2.  再根据有向边建图，若新边\<u, v>的两个顶点在第一步缩进了同一个点，得到环；
3.  新图BFS拓扑排序，若最后不能删除所有点，则得到环。（我也不知道为什么当时在这一步写了DFS… 大概是脑子瓦特了吧）