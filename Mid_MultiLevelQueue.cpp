
#include<bits/stdc++.h>
using namespace std;


struct process
{
    int pid;
    int arrival;
    int cpu;
    int rem_cpu;
} p;

process ar[6];
int n,quantam1,quantam2;

int Time=0;
queue<process>q1,q2,q3;
int cnt=1;


void queue_one()
{
    while(!q1.empty())
    {
        p=q1.front();
        q1.pop();
        if(p.rem_cpu>quantam1)
        {
            Time+=quantam1;
            p.rem_cpu-=quantam1;
            cout<<"p"<<p.pid<<"-----"<<Time<<"-----";
            while(cnt<n&&ar[cnt].arrival<=Time)
            {
                q1.push(ar[cnt]);
                cnt++;
            }
            q2.push(p);
        }
        else if(p.rem_cpu<=quantam1)
        {
            Time+=p.rem_cpu;
            while(cnt<n&&ar[cnt].arrival<=Time)
            {
                q1.push(ar[cnt]);
                cnt++;
            }
            cout<<"p"<<p.pid<<"-----"<<Time<<"-----";
        }
    }
}

void queue_two()
{
    while(!q2.empty())
    {
        p=q2.front();
        q2.pop();
        if(p.rem_cpu>quantam2)
        {
            Time+=quantam2;
            //cout<<"K?   p"<<p.rem_cpu<<endl;

            p.rem_cpu-=quantam2;
            cout<<"p"<<p.pid<<"-----"<<Time<<"-----";
            while(cnt<n&&ar[cnt].arrival<=Time)
            {
                q1.push(ar[cnt]);
                cnt++;
            }
            if(!q1.empty())queue_one();
            cout<<"K?   p"<<p.pid<<endl;
            q3.push(p);
        }
        else if(p.rem_cpu<=quantam2)
        {
            Time+=p.rem_cpu;
            while(cnt<n&&ar[cnt].arrival<=Time)
            {
                q1.push(ar[cnt]);
                cnt++;
            }
            cout<<"p"<<p.pid<<"-----"<<Time<<"-----";
            if(!q1.empty())queue_one();
        }
    }
}

bool cmp(process a,process b)
{
    return a.arrival<b.arrival;
}

int main()
{
    cin>>n>>quantam1>>quantam2;

    for(int i=0; i<n; i++)
    {
        cin>>p.pid>>p.arrival>>p.cpu;
        p.rem_cpu=p.cpu;
        ar[i]=p;
    }
    sort(ar,ar+n,cmp);
    //for(int i=0;i<n;i++)cout<<ar[i].pid<<endl;

    q1.push(ar[0]);

    queue_one();
    if(!q2.empty())queue_two();

    while(!q3.empty())
    {
        p=q3.front();
        q3.pop();
        Time+=p.rem_cpu;
        cout<<"??p"<<p.pid<<"-----"<<Time<<"-----";
    }
}


/*
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

            while(cnt<n&&ar[cnt].arrival<=time){
                q.push(ar[cnt]);
                cnt++;
            }

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
*/

/*
for(int i=0; i<n; i++)
    {
        if(ar[i].rem_cpu>quantam1)
        {
            ar[i].rem_cpu-=quantam1;
            time+=quantam1;
            q1.push(ar[i]);
            cout<<"p"<<ar[i].pid<<"-----"<<time<<"-----";
        }
        else if(ar[i].rem_cpu<=quantam1)
        {
            time+=ar[i].rem_cpu;
            cout<<"p"<<ar[i].pid<<"-----"<<time<<"-----";
        }
    }

    while(!q1.empty())
    {
        p=q1.front();
        q1.pop();
        if(p.rem_cpu>quantam2)
        {
            p.rem_cpu-=quantam2;
            time+=quantam2;
            q2.push(p);
            cout<<"p"<<p.pid<<"-----"<<time<<"-----";
        }
        else if(p.rem_cpu<=quantam2)
        {
            time+=p.rem_cpu;
            cout<<"p"<<p.pid<<"-----"<<time<<"-----";
        }
    }

    6 8 16
0 0 9
1 7 26
2 26 12
3 16 18
4 40 24
5 66 5

*/
