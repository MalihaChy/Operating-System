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
    vector<int>left,right;
    int x;
    for(int i=0;i<r;i++)
    {
        cin>>x;
        if(x>head)right.push_back(x);
        else if(x<head)left.push_back(x);
    }
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    for(int i=0;i<right.size();i++)cout<<right[i]<<" --> ";
    for(int i=0;i<left.size();i++)cout<<left[i]<<" --> ";
    int ans= (h_cnt-1-head)+(h_cnt-1)+left[left.size()-1];
    cout<<endl<<ans<<endl;
}
