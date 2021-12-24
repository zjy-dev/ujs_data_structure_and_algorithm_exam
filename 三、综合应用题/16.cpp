/**
 * 16. 有 4 个作业要在由两台机器 M1 和 M2 组成的流水线上完成加工，每个作业加工的顺序都是
 * 先在 M1 上加工，然后在 M2 上加工。在机器 M1 和 M2 加工作业 i 所需的时间分别为 ai 和 bi，
 * 且（a1，a2，a3，a4）=（4，5，12，10），（b1，b2，b3，b4）=（8，2，15，9），使用贪心法求 4
 * 个作业的最优调度方案，并计算最优值
 */

//JohnSon算法

#include<bits/stdc++.h>
using namespace std;

struct Work{
    int a, b;
    int id;
};

int main(int argc, char const *argv[])
{
    vector<Work> v = {{4, 8, 1}, {5, 2, 2}, {12, 15, 3}, {10, 9, 4}};
    vector<Work> v1, v2;

    for(int i = 0; i < 4; i++)
        if(v[i].a < v[i].b)
            v1.push_back(v[i]);
        else
            v2.push_back(v[i]);
            
    v.clear();
    
    sort(v1.begin(), v1.end(), [](const Work& w1, const Work& w2){
        return w1.a < w2.a;
    });

    sort(v2.begin(), v2.end(), [](const Work& w1, const Work& w2){
        return w1.b > w2.b;
    });

    for(const auto& val : v1)
        cout << val.id << " ";
    for(const auto& val : v2)
        cout << val.id << " ";
}