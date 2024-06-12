#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1000000000
#define mod 1000000007
#define f first 
#define s second
#define speedup ios_base::sync_with_stdio(false);cin.tie(NULL);
int NumberOfSquares(int X[],int Y[],int N,int M)
{
    unordered_map<int,int> m1,m2;
    int res=0;
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            int dist=abs(X[i]-X[j]);
            if(m1[dist]==0)
                m1[dist]++;
        }
    }
    for(int i=0;i<M;i++) {
        for(int j=i+1;j<M;j++)
        {
            int dist=abs(Y[i]-Y[j]);
            if(m2[dist]==0)
                m2[dist]++;
        }
    }
    for(auto i=m1.begin();i!=m1.end();i++)
        if(m2.find(i->f)!=m2.end())
            res+=(i->s*m2[i->f]);
    return res;
}
int main(){
	speedup
	int t=1;
	//cin>>t;
	while(t--){
	    int v,h,n,m;
	    cin>>v>>h>>n>>m;
	    int a[n],b[m],c[h+1];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    //sort(a,a+n);
	    for(int i=0;i<m;i++)
	        cin>>b[i];
	    //sort(b,b+n);
	    for(int i=0;i<=h;i++)
	        c[i]=i;
	    for(int i=0;i<=h;i++)
	        for(int j=0;j<m;j++)
	            if(b[j]==c[i])
	                c[i]=(h+1);
	    /*
	    for(int i=0;i<n;i++)
	        cout<<a[i]<<" ";
	    cout<<endl;
	    for(int i=0;i<m;i++)
	        cout<<b[i]<<" ";
	    cout<<endl;
	    /*/
	    /*
	    for(int i=0;i<=h;i++)
	        cout<<c[i]<<" ";
	    cout<<endl;
	    */
	    int T=(h-m)+1,ifc=0,ans=0;
	    while(T--){
	        int x[m+1];
	        for(int i=0;i<m+1;i++)
	        {
	            if(i==m)
	            {
	                if(c[ifc]==(h+1)&&ifc!=h)
	                {
	                    x[i]=c[ifc+1];
	                    ifc+=2;
	                }
	                else
	                {
	                    x[i]=c[ifc];
	                    ifc++;
	                }
	            }
	            else
	                x[i]=b[i];
	        }
	        //sort(x,x+(m+1));
	        ans=max(ans,NumberOfSquares(a,x,n,(m+1)));
	        /*
	        for(int i=0;i<m+1;i++)
	           cout<<x[i]<<" ";
	        cout<<endl;
	        cout<<NumberOfSquares(a,x,n,(m+1))<<endl;
	        */
	    }
	    cout<<ans<<endl;
	}
}
