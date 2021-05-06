#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h_cnt;
    cin>>h_cnt;
    int head;
    cin>>head;
    int r;
    cin>>r;
    int x,ans=0;
    while(r--)
    {
        cin>>x;
        ans+=abs(head-x);
        head=x;
    }
    cout<<ans;
}
