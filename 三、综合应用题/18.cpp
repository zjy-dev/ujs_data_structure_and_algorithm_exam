#include<bits/stdc++.h>
using namespace std;

const int n = 5; // 5台设备, 5个作业

vector<vector<int>> c;      // 各作业消耗的成本("c[i][j] = x" 的含义是 "i号设备 做 j号作业 成本为 x")
vector<int> bestX(n + 1);   // 消耗成本最少的任务方案 ("bestX[i] = j" 的含义是  "i号设备做j号作业")
int minCost = INT_MAX;      // 答案, 最小成本, 初始为正无穷后面逐渐缩小

struct NodeType
{ 
    int idx;			    // 当前已经为 idx号设备 分配过作业了
    vector<int> x;		    // x[i]为 i号设备 被分配的 作业编号(八股文就是解向量)
    vector<bool> vis;		// vis[i] 表示任务i已经分配
    int cost;			    // 已经分配的作业所需要的成本
    int lb;	        	    // 下界(lowerBound), 剪枝用

    // 用于优先队列排序, 每次优先选出下界最低的结点
    // (这样能多剪点枝, 其实这样把小于写成大于别扭, 但是小根堆版优先队列大家没学过还是算了)
    bool operator<(const NodeType &s) const
    {
        return lb > s.lb; 
    }

    // 构造函数
    NodeType()
    {
        x.resize(n + 1);
        vis.resize(n + 1);
        cost = lb = idx = 0;
    }
};

// 剪枝用的限界函数(基于贪心思想)
void bound(NodeType &node)
{  
    int t = 0;

    // 为每个还没作业的设备分配最轻的作业(当然, 这个作业不能有其他设备做)
    for(int i = node.idx + 1; i <= n; i++) 
    {  
        int minc = INT_MAX; //对这台设备来说成本最低的作业

        for(int j = 1; j <= n; j++)
            if(!node.vis[j] and c[i][j] < minc)
                minc = c[i][j];

        t += minc;
    }

    // 最低成本就是当前的cost + 为每个没作业的设备分配最轻的作业, 也就是下界 
    node.lb = node.cost + t;
}


void bfs()
{
    // bfs用的优先队列
    priority_queue<NodeType> q;

    // 根结点, idx设为0代表不分配任何任务
    NodeType root;
    bound(root);
    q.push(root);
    root.idx = 0;

    // 经典bfs
    while(!q.empty())
    {
        auto t = q.top();
        q.pop();

        // 最后一个设备也已经分配过作业了, 叶子结点
        if(t.idx == n)
        {
            // 尝试更新答案
            if(t.cost < minCost)
            {
                minCost = t.cost;
                for(int i = 1; i <= n; i++)
                    bestX[i] = t.x[i];
            }

            // 叶子结点不会产生任何孩子结点, 直接continue
            continue;
        }
        
        // 为下一台设备分配作业
        t.idx++;

        // 循环每一个作业, 将其分配给下一台设备
	    for(int i = 1; i <= n; i++)	
	    {  
            // 这个作业已经有设备做了, 直接continue
            if(t.vis[i]) 	
                continue;

            // 将 i号作业 分配给 idx号设备, 同时自然要更新vis和cost
            t.x[t.idx] = i;
            t.vis[i] = true;
            t.cost += c[t.idx][i];

            // 剪枝
            bound(t);
            if(t.lb <= minCost)
                q.push(t);

            // 下一种情况还要把t塞进队列, 所以要还原t之前的状态
            t.vis[i] = false;
            t.cost -= c[t.idx][i];
       }  
    }
}

int main(int argc, char const *argv[])
{
    // init
    c = {{}, {0, 10, 4, 8, 7, 5}, {0, 7, 5, 4, 8, 9}, 
    {0, 6, 9, 2, 9, 8}, {0, 8, 7, 10, 5, 6}, {0, 9, 10, 7, 5, 8}};

    // bfs
    bfs();

    // check
    for(int i = 1; i <= n; i++)
        printf("%d ", bestX[i]);
    puts("");
    printf("MinCost = %d\n", minCost);

    return 0;
}