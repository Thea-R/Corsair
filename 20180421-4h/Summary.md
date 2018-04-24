南航校赛，组队第二场，开题还行，写题不够流畅老出现小错误，还有不熟悉的专题比如A的斯坦纳树和I的网络流。

[Link](http://icpc.njust.edu.cn/Contest/5698/)



## Problem

| 标签   | 题目                                       | AC / Submit |
| ---- | ---------------------------------------- | ----------- |
| A    | [Repair the roads of capital](http://icpc.njust.edu.cn/Contest/6239/A/) | 1 / 3       |
| B    | [A problem of tree](http://icpc.njust.edu.cn/Contest/6239/B/) | 5 / 29      |
| C    | [Defense The World Tree](http://icpc.njust.edu.cn/Contest/6239/C/) | 2 / 8       |
| D    | [Coding Empire](http://icpc.njust.edu.cn/Contest/6239/D/) | 5 / 13      |
| E    | [Warning or not](http://icpc.njust.edu.cn/Contest/6239/E/) | 15 / 20     |
| F    | [Multiple problem](http://icpc.njust.edu.cn/Contest/6239/F/) | 1 / 4       |
| G    | [A problem of tree II](http://icpc.njust.edu.cn/Contest/6239/G/) | 0 / 0       |
| H    | [April is your lie](http://icpc.njust.edu.cn/Contest/6239/H/) | 0 / 1       |
| I    | [Beat Bug Empire](http://icpc.njust.edu.cn/Contest/6239/I/) | 2 / 6       |
| J    | [Fraction to Decimal](http://icpc.njust.edu.cn/Contest/6239/J/) | 9 / 86      |
| K    | [Coding Monkey and stock](http://icpc.njust.edu.cn/Contest/6239/K/) | 10 / 32     |
| L    | [Coding Monkey and stock II](http://icpc.njust.edu.cn/Contest/6239/L/) | 14 / 17     |



## Rank

| Rank | User                                     | Solved | Penalty | [A](http://icpc.njust.edu.cn/Contest/6239/A/) | [B](http://icpc.njust.edu.cn/Contest/6239/B/) | [C](http://icpc.njust.edu.cn/Contest/6239/C/) | [D](http://icpc.njust.edu.cn/Contest/6239/D/) | [E](http://icpc.njust.edu.cn/Contest/6239/E/) | [F](http://icpc.njust.edu.cn/Contest/6239/F/) | [G](http://icpc.njust.edu.cn/Contest/6239/G/) | [H](http://icpc.njust.edu.cn/Contest/6239/H/) | [I](http://icpc.njust.edu.cn/Contest/6239/I/) | [J](http://icpc.njust.edu.cn/Contest/6239/J/) | [K](http://icpc.njust.edu.cn/Contest/6239/K/) | [L](http://icpc.njust.edu.cn/Contest/6239/L/) |
| ---- | ---------------------------------------- | ------ | ------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
| 3    | [Corsair](http://icpc.njust.edu.cn/UserPage/Corsair/) | 7      | 774     |                                          | 56                                       | -2                                       | 161                                      | 15                                       | 147(-2)                                  |                                          |                                          |                                          | 132(-2)                                  | 144(-1)                                  | 19                                       |



## Solved

- [ ] A    Repair the roads of capital
- [x] B    A problem of tree（线段树）
- [x] C    **~~Defense The World Tree~~**
- [x] D    Coding Empire（生成树）
- [x] E    Warning or not
- [x] F    Multiple problem
- [ ] G    A problem of tree II
- [ ] H    April is your lie
- [ ] I    Beat Bug Empire
- [x] J    Fraction to Decimal（循环节，注意细节处理）
- [x] K    Coding Monkey and stock（水题，枚举中点找左右两边最大最小值差值）
- [x] L    Coding Monkey and stock II（水题，找连续上升区间取最大最小值差值）

（完成的题打勾，且**~~赛后补的题加粗+删除线~~**）



## Solutions



##### [C](http://icpc.njust.edu.cn/Contest/6239/C/)（dp+贪心）              by Steven

1.  x塔肯定在最后，所以只用y塔和z塔dp一下就好了，dp[i][j]:前i个位置有j个z塔伤害的最大值；
2.  dp[i][j]=max{dp[i-1][j-1]+(t+(j-1)*z)*y*(i-j) (第i个位置放z塔) ,dp[i-1][j]+(t+j*z)*y*(i-j-1) (第i个位置不放z塔)};
3.  加上后面(n-i)个x塔的伤害，ans=max{ans,dp[i][j]+(n-i)*x*(t+j*z)+(n-i)*(t+j*z)*(i-j)*y)}。



##### 
