#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"No of Pages: ";
    int p;
    cin>>p;
    cout<<"No of Memory Page Frame: ";
    int sz;
    cin>>sz;
    cout<<"No of Page References: ";
    int n;
    cin>>n;
    int ar[n];
    vector<int>v[p];
    int x,a,b;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        ar[i]=x;
        v[x].push_back(i);
    }
    vector<int>q;
    bool found[p];
    int cnt=0;
    memset(found,false,sizeof(found));
    for(int i=0;i<n;i++)
    {
        int x=ar[i];
        if(found[x]==false)
        {
            cnt++;
            if(q.size()<sz)
            {
                q.push_back(x);
            }
            else{
                int id;
                int c=INT_MIN;
                for(int j=0;j<q.size();j++)
                {
                    b=q[j];
                    if(v[b].size()>0){
                        a=v[b][0];
                        /*while(a<i){
                            v[b].erase(v[b].begin()+0);
                            a=v[b][0];
                        }*/
                    }
                    else a=INT_MAX;

                    if(a>c){
                        c=a;
                        id=j;
                    }
                }
                found[b]=false;
                q[id]=x;

            }
            found[x]=true;
            v[x].erase(v[x].begin()+0);
        }
        else v[x].erase(v[x].begin()+0);
        for(int k=0;k<q.size();k++)cout<<q[k]<<" ";
        cout<<endl<<endl;
    }
    cout<<"page fault : "<<cnt<<endl;
}
