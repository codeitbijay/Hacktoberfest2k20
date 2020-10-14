// Implementing Circular Queue Program in C++

#include<iostream>
using namespace std;
int main()
{
      int que[10],fr=-1,re=-1,i;
while(1){
    cout<<"Choose any option:\n1.Insert \n2.Delete \n3.Print \n4.Exit \nEnter Choice number:";
    int c;
    cin>>c;
    switch(c)
    {
    case 1:
        if(fr==(re+1)%10)
            cout<<"Condition of overflow\n";
        else
        {
            if(fr==-1)
            fr=re=0;
            else{
            re=(re+1)%10;}
            int ele;cout<<"Enter element:";
            cin>>ele;
            que[re]=ele;
        }
        break;
    case 2:
        if(fr==-1)
            cout<<"Condition of underflow\n";
        else
        {
            if(fr==re)
            fr=re-1;
            else
            fr=(fr+1)%10;
        }
        break;
    case 3:
        cout<<"Queue is:";
       for(i=fr;i!=re;i=(i+1)%10)
       cout<<que[i]<<"";
       cout<<que[re]<<endl;
            break;
    case 4:
        goto end;
    }
}
end:
    cout<<"EXIT";
}
