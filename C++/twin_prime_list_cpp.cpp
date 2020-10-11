// program to take a long integer N from the user and print all the twin prime numbers between one and the given number
// twin primes are those pairs of prime numbers whose difference is 2 

#include<iostream>
#include<math.h>

using namespace std;

bool isPrime(long int a)
{
    int flag=1;
    for(long int i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
		{
			flag=0;
			break;
    	}
    }
    if(flag == 1)
        return(true);
    else
        return(false);
}

int main()
{
    long int N;
    cout << "to find all twin prime number between one and a given upper bound number (less than +2,147,483,645) " << endl;
    cout << "enter the upperbound ";
    cin >> N;
    cout << "the twin primes in the given range are:" << endl;

    for(long int i=2;i<=N;i++)
    {
        if(isPrime(i) && isPrime(i+2))
            cout << "(" << i << "," << i+2 << ")" << endl;
    }
    return 0;
}