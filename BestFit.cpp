#include<bits/stdc++.h>
using namespace std;

int main()
{
    int hole;
    cout<<"No of Memory Holes: ";
    cin>>hole;
    cout<<"Memory Holes: \n";
    vector<int>memory;
    int x;
    for(int i=0; i<hole; i++)
    {
        cin>>x;
        memory.push_back(x);
    }
    int request;
    cout<<"No of Memory Requests: ";
    cin>>request;
    bool external_fragmentation=true;
    while(request--)
    {
        cout<<"\nMemory Request: ";
        cin>>x;
        external_fragmentation=true;
        vector< pair<int,int> >temp;
        for(int i=0; i<hole; i++)
        {
            if(memory[i]>=x)
            {
                temp.push_back(make_pair(memory[i],i));
                external_fragmentation=false;
            }
        }
        if(external_fragmentation==false)
        {
            sort(temp.begin(),temp.end());
            memory[temp[0].second]-=x;
        }
        int space=0;
        for(int i=0; i<hole; i++)
        {
            cout<<memory[i]<<" ";
            space+=memory[i];
        }
        cout<<endl<<endl;
        if(external_fragmentation)
        {
            cout<<"Memory Request "<<x<<" can not be allocated.\n";
            cout<<"External Fragmentation "<<space<<endl;;
            return 0;
        }
    }
    cout<<"\nNo External Fragmentation\n";
}

