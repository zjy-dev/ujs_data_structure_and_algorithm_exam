/**
 * 8. 有 n 个人同时乘船过江，已知每个人的体重和船的载重量，若每条船的载重量相等，且至多
 * 只能乘坐 2 个人，使用贪心策略设计算法，求最少需要的船的数目
 *      时间 => O(nlogn)
 *      空间 => O(1)
 */

//经典排序双指针(一种贪心)

#include<bits/stdc++.h>
using namespace std;

const int CAP = 250;//每艘船载重量

int main(int argc, char const *argv[])
{
    //init
    vector<int> v{90, 70, 180, 160};
    int n = v.size();

    //greed(贪心)
    sort(v.begin(), v.end());
    int i = 0, j = n - 1, ans = 0;
    while(i < j)
    {
        //反正要开一艘船给最重的人坐
        ans++;

        //看看最轻的能不能挤上去
        if(v[i] + v[j] <= CAP)
            i++;
            
        j--;
    }

    if(i == j)
        ans++;

    //check
    printf("最少需要%d艘船", ans);
    return 0;
}