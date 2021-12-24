/**
 * 9. 已知 n 个活动组成的集合，每个活动都需要使用同一资源，而该资源在任何时刻只能被一个
 * 活动所占用。每个活动都有一个开始时间和结束时间，一旦某个活动开始执行，中间不能被打断，
 * 直到其执行完毕。若两个活动的时间安排没有冲突，则称这两个活动相容。使用回溯法设计算法，
 * 求一种最优活动安排方案，使得被安排的活动数量达到最多
 *      时间 => O(2^n)
 *      空间 => O(n)(递归栈)
 */

//这不让用贪心???????
//如果可以使用贪心, 就升序排序左端点, O(n)遍历
//回溯就全排列暴力求解吧

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

vector<PII> v;
int n, ans = INT_MIN;

int getNum()
{
    int ans = 0;
    unordered_set<int> hash;
    for(int i = 0; i < n; i++)
    {
        int l = v[i].first, r = v[i].second;

        //flag == true ? 能开这个活动 : 不能开这个活动
        bool flag = true;

        //从该活动开始到结束必须都没有活动和它重叠
        for(int j = l; j <= r; j++)
            if(hash.count(j))
            {
                flag = false;
                break;
            }

        //没有重叠就举办该活动
        if(flag)
        {
            for(int j = v[i].first; j <= v[i].second; j++)
                hash.insert(j);
            ans++;
        }
    }

    return ans;
}

void dfs(int x)
{
    if(x == n)
    {
        ans = max(ans, getNum());
        return;
    }
    
    //全排列
    for(int i = x; i < n; i++)
    {
        swap(v[x], v[i]);
        dfs(x + 1);
        swap(v[x], v[i]);
    }
}

int main(int argc, char const *argv[])
{   
    //init
    v = {{1, 4}, {2, 3}, {4, 5}};
    n = v.size();

    //全排列
    dfs(0);

    //check
    cout << ans << endl;
    return 0;
}