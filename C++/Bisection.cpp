#include<iostream>
using namespace std;
#include <math.h>
#include <cstdlib>
double error;
int z,n;
// Bisection method for numerical solution of non Linear equations //
double f(double x)
{
    //Non Linear equation
    return x*x*x - 4*x -9 ;      
}
void bisection(double a,double b)
{
    double m;
    if (f(a)*f(b)>0)
    {
        cout<<"Invalid values for a and b .";
        return;
    }
    else
    {
        if (z==0)
        {
            do
            {
                m=(a+b)/2;
                cout<<"Therefore new root = "<<m<<" & f("<<m<<")= "<<f(m)<<endl;
                if (f(m)==0)
                {
                    break;
                }
                else if (f(a)*f(m)<0)
                {
                    b=m;
                }
                else
                {
                    a=m;
                }
            }while (abs(b-a)>=error);

        }

        else if(z==1)
        {
            for(int i=0;i<n;i++)
            {
                n--;
                m=(a+b)/2;
                cout<<"Therefore new root = "<<m<<" & f("<<m<<")= "<<f(m)<<endl;
                if (f(m)==0)
                {
                    break;
                }
                else if (f(a)*f(m)<0)
                {
                    return bisection(a,m);
                }
                else
                {
                    return bisection(m,b);
                }
            }
        }

        else
        {
            cout<<"invalid"<<endl;
        }

    }

}

int main()
{
    double a,b;
    cout<<"Enter a value for a : ";
    cin>>a;
    cout<<"Enter a value for b : ";
    cin>>b;
    cout<<"Enter 0 to specify Maximum error || Enter 1 to specify maximum number of iterations : ";
    cin>>z;
    if (z==0)
    {
        cout<<"Enter the max error : ";
        cin>>error;
        cout<<endl;
    }
    else if(z==1)
    {
        cout<<"Enter the number of iterations : ";
        cin>>n;
        cout<<endl;
    }
    else
    {
        cout<<"Invalid input";
    }
    bisection(a,b);
} 