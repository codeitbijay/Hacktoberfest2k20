#include<iostream>
#include<string>
#include<cmath>
using namespace std;
void subseq(char *ind,char *out,int i,int j)
{
    int t=1;
    if(ind[i]=='\0')
    {
        out[j]='\0';
        cout<<" "<<out;
        return;
    }
    //exclude
    subseq(ind,out,i+1,j);   // .1
    
    //here .1  and   .2  can be change their position so as to reverse the outcome
    
    out[j]=ind[i];
    //include
    subseq(ind,out,i+1,j+1);//  .2
    
    
}
int main()
{
    char ind[1000];
    char out[1000];
    cin>>ind;
	int i=0,t=0;
    while(ind[i])
    {
        t++;
        i++;
    }
	int p=pow(2,t);
    subseq(ind,out,0,0);
    cout<<endl<<p;
    return 0;
}
