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
    bool found[p];
    memset(found,false,sizeof(found));
    queue<int>q;
    int cnt=0;
    while(n--)
    {
        int x;
        cin>>x;
        if(found[x]==false){
            cnt++;
            if(q.size()<sz)
            {
                q.push(x);
            }
            else{
                found[q.front()]=false;
                q.pop();
                found[x]=true;
                q.push(x);
            }
        }
        vector<int>v;
        while(!q.empty()){
            v.push_back(q.front());
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl<<endl;
        for(int i=0;i<v.size();i++)q.push(v[i]);
    }
    cout<<cnt<<endl;
}
