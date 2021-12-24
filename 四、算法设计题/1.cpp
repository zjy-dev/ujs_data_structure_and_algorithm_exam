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
    unordered_set<int> hash;
    
    //unique
    int l = 0, r = 0;
    for(; r < n; r++)
        if(!hash.count(v[r]))
            v[l++] = v[r], hash.insert(v[r]);
    v.erase(v.begin() + l, v.end());

    //check
    for(const auto& val : v)
        printf("%d ", val);
    return 0;
}