#include<bits/stdc++.h>
using namespace std;

struct process{
    int pid;
    int arrival;
    int cpu;
    int rem_cpu;
};

bool cmp(process a, process b)
{
    return a.arrival<b.arrival;
}

int main()
{
    int n;
    cin>>n;

    process ar[n];
    struct process p;
    int total_time=0;

    for(int i=0;i<n;i++)
    {
        cin>>p.pid>>p.arrival>>p.cpu;
        p.rem_cpu=p.cpu;
        ar[i]=p;
        total_time+=p.cpu;
    }

    sort(ar,ar+n,cmp);

    int time;
    double tat=0,twt=0;
    for(time=0;time<=total_time;time++)
    {
        int remaining=INT_MAX;
        int id;
        for(int i=0;i<n;i++)
        {
            if(ar[i].arrival<=time&&ar[i].rem_cpu<remaining&&ar[i].rem_cpu>0)
            {
                remaining=ar[i].rem_cpu;
                id=i;
            }
        }
        ar[id].rem_cpu--;
        if(ar[id].rem_cpu==0)
        {
            int turn_around_time=time+1-ar[id].arrival;
            int waiting_time=turn_around_time-ar[id].cpu;

            cout<<"Process "<<ar[id].pid<<" W "<<waiting_time<<" T "<<turn_around_time<<endl;

            twt+=waiting_time;
            tat+=turn_around_time;
        }
    }
    cout<<twt/n<<" "<<tat/n<<endl;
}
