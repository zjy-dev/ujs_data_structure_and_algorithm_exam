/**
 * 3. 判断回文串(字符串以@结尾)
 *      双指针
 *      时间 => O(n)
 *      空间 => o(1)
 */

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    //init
    string s = "abcdcba@";
    //j = s.size() - 2 是为了忽略@
    int i = 0, j = s.size() - 2;

    //judge
    bool ans = true;
    while(i < j)
        if(s[i++] != s[j--])
        {
            ans = false;
            break;
        }
    
    //check
    cout << (ans ? s + " 是回文串" : s + " 不是回文串");
    return 0;
}