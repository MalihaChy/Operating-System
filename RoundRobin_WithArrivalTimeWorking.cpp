#include<bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int rem_cpu;
    int arrival;
    int cpu;
};

bool cmp(process a, process b)
{
    return a.arrival<b.arrival;
}

int main()
{
    int quantum;
    int n;
    int time=0;
    struct process p;
    cin>>n>>quantum;
    queue<process>q;
    process ar[n];

    for(int i=0; i<n; i++)
    {
        cin>>p.pid>>p.arrival>>p.cpu;
        p.rem_cpu=p.cpu;
        ar[i]=p;
    }
    sort(ar,ar+n,cmp);
    int waiting_time[n+1],turnaround_time[n+1];
    memset(waiting_time,0,sizeof(waiting_time));
    memset(turnaround_time,0,sizeof(turnaround_time));
    int temp=0;
    int cnt=1;
    q.push(ar[0]);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        if(p.rem_cpu>quantum)
        {
            time+=quantum;
            p.rem_cpu-=quantum;

            while(cnt<n&&ar[cnt].arrival<=time){
                q.push(ar[cnt]);
                cnt++;
            }

            q.push(p);
            cout<<temp<<"..."<<time<<"   Process "<<p.pid<<endl;
            temp=time;
        }
        else if(p.rem_cpu<=quantum)
        {
            time+=p.rem_cpu;
            waiting_time[p.pid]=time-p.cpu-p.arrival;
            turnaround_time[p.pid]=waiting_time[p.pid]+p.cpu;
            cout<<temp<<"..."<<time<<"   Process "<<p.pid<<endl;
            temp=time;
        }
    }
    double total_waiting_time=0,total_turnaround_time=0;
    for(int i=1; i<=n; i++)
    {
        total_waiting_time+=waiting_time[i];
        total_turnaround_time+=turnaround_time[i];
    }
    for(int i=1; i<=n; i++)
    {
        cout<<"Process "<<i<<" Waiting Time: "<<waiting_time[i]<<endl;
    }
    cout<<"Avg Waiting Time: "<<total_waiting_time/n<<endl;
    cout<<"Avg Turn Around Time: "<<total_turnaround_time/n<<endl;
}
