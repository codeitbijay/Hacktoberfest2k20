#include <iostream>
using namespace std;
#include<math.h>

#define p(c) (c*c+c)/2
long  long solve(long long N)
{
    long long x=(long long)p(N);
     if(x%2==1)
      return 0;
      if(N==3)
      return 2;
      long long n=floor((sqrt(1+4*x)-1)/2);
      long long t=p(n);
      if(2*t==x)
      return (t-n)+ (x + t -N -n*N)+N-n;
      return N-n;
     
    
}
int main() {
	 int tc;
	 cin>>tc;
	 long long N;
	 while(tc--)
	 {
	    cin>>N;
	    cout<<solve(N)<<endl;
	    
	 }
	return 0;
}
