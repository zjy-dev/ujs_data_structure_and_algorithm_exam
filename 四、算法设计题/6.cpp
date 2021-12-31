/**
 * 6. 递增序列, 分治寻找最接近tar的数
 *      时间 => O(logn)
 *      空间 => O(1)
 */

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    //init
    vector<int> v{1, 2, 3, 4, 7, 9, 11};
    int tar = 5;
    int n = v.size();

    //找 <= tar 的第一个数
    int l = 0, r = n - 1, mid;
    while(l < r)
        if(v[mid = (l + r + 1) >> 1] > tar)
            r = mid - 1;
        else
            l = mid;

    auto t1 = l;

    //如果已经找到tar本身了, 直接返回(没有比tar更接近tar的数了)
    if(v[t1] == tar)
    {
        cout << v[t1];
        return;
    }

    //找 >= tar 的第一个数
    l = 0, r = n - 1;
    while(l < r)
        if(v[mid = (l + r) >> 1] >= tar)
            r = mid;
        else
            l = mid + 1;
    auto t2 = l;

    //比较并输出结果
    if(tar - v[t1] <= v[t2] - tar)
        cout << v[t1];
    else
        cout << v[t2];

    return 0;
}