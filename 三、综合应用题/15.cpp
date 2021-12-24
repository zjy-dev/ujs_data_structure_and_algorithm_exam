#include<bits/stdc++.h>
using namespace std;

// s是分隔点, 例如 s[i][j] = k 的意思是 令A(i)...A(j)做乘法次数最少的顺序中, 最后一个分隔点是k
vector<vector<int>> dp, s;
vector<int> p;
int n = 6;

void matrixChainMul()
{
    // 边界, 自己乘自己不需要乘, dp都要有边界的
    for(int i = 1; i <= n; i++)
        dp[i][i] = 0;
    
    // 从小到大枚举长度, 因为更长长度的dp(子问题)总是建立在更短长度的dp(子问题)之上(自底向上递推)
    for(int len = 2; len <= n; len++)
        for(int i = 1; i <= n - len + 1; i++) //枚举起点
        {
            // j是终点, 要减1是因为, 额, 自己模拟一下, 起点是1, 长度为2, 那么终点应该是1 + 2 - 1
            int j = i + len - 1;

            // dp[i][j]以 从i分开 为边界是没问题的, 当然初始化成INT_MAX也是完全OK的
            dp[i][j] = dp[i][i] + dp[i + 1][j] + p[i] * p[i + 1] * p[j + 1];

            // 前面也说了, 分隔点是i
            s[i][j] = i;

            // 枚举除了i之外的分隔点, 这里顺序无所谓, 因为更短的子问题我们
            for(int k = i + 1; k < j; k++)
            {
                //核心状态转移
                int t = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1]; 

                // 这个分隔点好使, 得到的乘法次数比当前最小值还小, 那就采用它
                if(t < dp[i][j])
                    dp[i][j] = t, s[i][j] = k;
            }
        }
}


int main()
{
    //init
    p = {0, 30, 35, 15, 5, 10, 20, 25};
    dp = vector<vector<int>>(n + 1, vector<int>(n + 1));
    s = vector<vector<int>>(n + 1, vector<int>(n + 1));
    
    //dp
    matrixChainMul();

    //check
    printf("        dp数组如下: \n");
    for(int i = 1; i <= n; i++, puts(""))
        for(int j = 1; j <= n; j++)
            if(i > j)
                printf("       ");
            else
                printf("%7d", dp[i][j]);
    
    puts("");
    printf("        分隔数组s如下: \n");
    for(int i = 1; i <= n; i++, puts(""))
        for(int j = 1; j <= n; j++)
            if(i > j)
                printf("       ");
            else
                printf("%7d", s[i][j]);
}