#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool redundant(string str)
{
    stack <char> s; 
   
    int n = str.length() ; 
    for(int i = 0 ; i < n;i++)
    {
        if(str[i] == ')' && !s.empty())
        {
            if(s.top() == '('){
                return true;
            }
            else{
                while(s.top() != '('){
                    s.pop();
                }
                s.pop();
            }

        }
        else
        {
            s.push(str[i]) ;
        }
    }
    return false ;     
}

 
int main(){

        string str ; 
        getline(cin, str); 
        if(redundant(str))
        {
            cout<<"true"<<endl ; 
        }
        else
        {
            cout<<"false"<<endl ; 
        }

    }
