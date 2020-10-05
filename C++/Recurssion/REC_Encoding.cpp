#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void encoding(string s, string f)
{
    if(s.length() == 0)  //if no input 
    {
        cout<<f<<endl;  //print empty string or updated string
    }
    else if(s.length() == 1)//if 1 character in string
    {
        char ch = s[0]; 
        if(ch == '0') // and is if 0 
        {
            return; // return 
        }
        else  
        {
            int chv = ch - '0';  //make the char int 
            char code = (char)('a' + chv - 1);  //if ch was 2 code is b
            f = f + code;  //add that char in string 
            cout<<f<<endl; //and print 
        }
    }
    else 
    {
        char ch = s[0];
        string roq = s.substr(1); // containing rest of the string from index 1
        if(ch == '0')
        {
            return;
        }
        else
        {
            int chv = ch - '0';  //make the char int
            char code = (char)('a' + chv - 1);  //if ch was 2 code is b
            encoding(roq,f+code);         // recursively for rest of string
        }
        string ch12 = s.substr(0,2);  // taken 1st 2 chars of string
        string roq12 = s.substr(2);   // rest of string is stored in roq12
        int ch12v = stoi(ch12);       //converted string to int 
        if(ch12v <= 26)          // and if char < 26 then do opertation else not vaild code
        {
            char code = (char)('a' + ch12v - 1);
            encoding(roq12,f+code);
        }
        
    }
}
int main()
{
    string s;
    cin>>s;
    encoding(s,"");
}
