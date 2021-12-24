/**
 * 2. 在递减单链表中插入
 *      空间 => O(1)
 *      时间 => O(n)
 */

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(int argc, char const *argv[])
{
    //init
    Node* head = new Node({0, new Node({5, new Node({3, new Node({2, new Node({1, NULL})})})})});
    auto p = head->next;
    while(p)
        printf("%d ", p->data), p = p->next;
    puts("");
    
    //insert
    auto newNode = new Node({4, NULL});
    p = head;
    while(p->next->data > newNode->data)
        p = p->next;
    newNode->next = p->next;
    p->next = newNode;

    //check
    p = head->next;
    while(p)
        printf("%d ", p->data), p = p->next;
    return 0;
}
