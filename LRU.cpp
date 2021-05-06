#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p;
    cin>>p;
    int sz;
    cin>>sz;
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    bool found[p];
    memset(found, false, sizeof(found));
    vector< pair<int,int> >v;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int x=ar[i];
        if(found[x]==false)
        {
            cnt++;
            if(v.size()<sz)
            {
                found[x]=true;
                v.push_back(make_pair(i,x));
            }
            else{
                sort(v.begin(),v.end());
                found[v[0].second]=false;
                found[x]=true;
                v[0]=make_pair(i,x);
            }
        }
        for(int j=0;j<v.size();j++)
        {
            if(v[j].second==x){
                v[j].first=i;
                break;
            }
        }
        for(int j=0;j<v.size();j++)
        {
            cout<<v[j].second<<" ";
        }
        cout<<endl<<endl;
    }
    cout<<cnt<<endl;
}
