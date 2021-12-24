/**
 * 14. 已知一个由 n 个整数构成的序列，采用分治法寻找其中的最大值和次大值，请写出递归模
 * 型，并计算时间复杂度
 *      时间 => logn
 */

#include<bits/stdc++.h>
using namespace std;

vector<int> v;

/**
 * @brief 分治寻找最大值和次大值
 * 
 * @param l 左边界
 * @param r 右边界
 * @return pair<int, int> first是最大值, second是次大值
 */
pair<int, int> find(int l, int r)
{
    //区间长度小于等于2是递归边界
    if(r - l <= 1)
        return {max(v[l], v[r]), min(v[l], v[r])};
    
    //拆成两个区间去分治
    int mid = (l + r) >> 1;
    auto ansL = find(l, mid), ansR = find(mid + 1, r);

    //整理得到的结果, 挑选出最大值和次大值
    int max1 = max(ansL.first, ansR.first);
    int max2 = max(min(ansL.first, ansR.first), max(ansL.second, ansR.second));
    
    return {max1, max2};
}

int main(int argc, char const *argv[])
{
    v = {3, 1, 2, 5, 6, 8, 0, 5};
    auto ans = find(0, v.size() - 1);
    printf("最大值 => %d\n次大值 => %d\n", ans.first, ans.second);
    return 0;
}