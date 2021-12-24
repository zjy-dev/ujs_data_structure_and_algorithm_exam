/**
 * 7. 已知两个字符串 A 和 B，若要求使用最少的字符操作次数将 A 转换为 B，使用动态规划策略
 * 设计算法计算它们的最优编辑距离（即将 A 转换为 B 的最少字符操作次数）。可以执行的字符操
 * 作包括：（1）删除一个字符；（2）插入一个字符；（3）将一个字符替换另一个字符
 *      时间 => O(mn)
 *      空间 => O(mn)
 */

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    //init
    string s1 = "horse", s2 = "ros";
    int m = s1.size(), n = s2.size();
    s1 = " " + s1, s2 = " " + s2;//dp题目下标从1开始总是带给我惊喜

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    //边界
    for(int i = 0; i <= m; i++)
        dp[i][0] = i;
    for(int i = 0; i <= n; i++)
        dp[0][i] = i;
    
    //最值dp, 注意可重不可漏
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            //增和删
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;

            //改
            int t = (s1[i] == s2[j] ? 0 : 1);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + t);
        }
    
    printf("最小编辑距离为%d", dp[m][n]);
    return 0;
}