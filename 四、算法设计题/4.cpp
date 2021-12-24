/**
 * 4. 中序遍历最后一个结点的指针
 *      时间 => O(logn)
 *      空间 => O(1)
 */

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* l, *r;
};

int main(int argc, char const *argv[])
{
    //init
    Node* root = new Node({0, NULL, NULL});
    root->l = new Node({1, new Node({2, NULL, NULL}), new Node({3, NULL, NULL})});
    root->r = new Node({4, new Node({5, NULL, NULL}), NULL});
    //0
    //1, 4
    //2, 3, 5

    //find
    auto p = root;    
    while(p->r)
        p = p->r;
    
    //check
    printf("%d", p->data);
    return 0;
}