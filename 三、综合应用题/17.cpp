/* 
 * 15. 剪枝函数有哪些?
 *      1 => 用 约束函数 剪去 不满足约束条件 的子树
 *      2 => 用 限界函数 剪去 得不到最优解 的子树
*/

#include<bits/stdc++.h>
using namespace std;

// 物品结构体
struct Obj
{
    int w, v;
    double p;
};

int n;                     // 共n件物品
int ans;                   // 答案, 最大价值
const int maxW;            // 背包最大承重
vector<Obj> arr(n + 1);    // 物品数组

/**
 * @brief           右剪枝用的限界函数, 求上界(最多能装多少价值, 基于贪心思想)
 * 
 * @param i         当前选择的物品下标(物品已经按照 单位重量的价值 降序排列了)
 * @param curW      当前背包中物品的总重量
 * @param curV      当前背包中物品的总价值
 * @return double
 */
double bound(int i, int curW, int curV)
{  
    // i号物品没有选, 所以从第 i + 1 个物品开始计算
    i++; 

    // 尽可能多装
    for(; i <= n and curW + arr[i].w <= maxW; i++)
        curW += arr[i].w, curV += arr[i].v;

    // 整的装不下, 拆成单位重量的小份继续装(反正是剪枝不用严谨, 大不了少剪几枝)
    if(i <= n)
        return curV + (maxW - curW) * arr[i].p;

    return curV;
}

// 回溯的搜索函数
void dfs(int i, int curW, int curV)
{
    // 叶子结点
    if(i > n)
    {
        // 更新答案
        ans = max(ans, curV);
        return;
    }

    // 非叶子结点

    // 选该物品
    // 左剪枝的约束条件, 超重不能选
    if(curW + arr[i].w <= maxW)
        dfs(i + 1, curW + arr[i].w, curV + arr[i].v);

    // 不选该物品
    // 用右剪枝的限界函数尝试剪掉得不到最优解的子树(看看不选该物品有没有前途)
    if(bound(i, curW, curV) > ans)
        dfs(i + 1, curW, curV);
}



