//to find the two prime numbers which sum up to give the given number (accroding to golbach's conjecture) 
// Golbachs conjecture states that any number greater than two can be written as the sum of two primes

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
    cout << "enter the number (greater than 2) to be written as the sum of the two primes according to Golbach's conjecture" << endl;
    long int n;
    cin >> n;
    for(long int i=2;i<=n/2;i++)
    {
        if(isPrime(i)&&isPrime(n-i))
        {
            cout << "the required numbers are:" << endl << "(" << i << "," << n-i<< ")" << endl;
            break;
        }
    }
    return 0;
}