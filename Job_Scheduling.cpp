#include<bits/stdc++.h>
using namespace std;

struct Job_Scheduling
{
    int deadline;
    int profit;
};

bool cmp(struct Job_Scheduling x,struct Job_Scheduling y)
{
    return x.profit>y.profit;
}

int main()
{
    int n,i;
    cin >> n ;
    int max_deadline,j;
    cin >> max_deadline;
    int ans[max_deadline];
    Job_Scheduling a[n];
    for(i=0;i<n;i++)
    {
        cin >> a[i].deadline >> a[i].profit;
    }
    sort(a,a+n,cmp);
    for(i=0;i<max_deadline;i++)
    {
        ans[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=a[i].deadline;j>=0;j--)
        {
            if(ans[j-1]==0)
            {
                ans[j-1]=a[i].profit;
                break;
            }
        }
    }
    cout << "Job will be selected as per given below" << endl;
    for(i=0;i<max_deadline;i++)
    {
        cout << ans[i] << endl;
    }
}