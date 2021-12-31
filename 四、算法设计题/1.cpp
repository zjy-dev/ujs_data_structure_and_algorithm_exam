/**
 * 1. 数组去重
 *      空间 => O(n)
 *      时间 => O(n)
 */

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    //init
    vector<int> v{1, 1, 5, 6, 6, 2, 1, 7, 8, 8, 7, 2};
    int n = v.size();

    //sort
    sort(v.begin(), v.end());
    
    //unique
    int l = 0, r = 0;
    for(; r < n; r++)
        if(v[r] != v[r - 1])
            v[l++] = v[r];
    n = l;

    //check
    for(int i = 0; i < n; i++)
        cout << v[i] << " ";
    return 0;
}