#include <iostream>
#include <cstring>
using namespace std;
int main() {
    string str;
    getline(cin, str);
    cout<<str[0];
    int count=1;
    if(str.length() == 1){
        cout<<count;
    }
    for(int i=1; i<str.length(); i++){
        
        if(str[i]==str[i-1]){
            count++;
        }
        else{
            cout<<count;
            cout<<str[i];
            count = 1;
        }
        if(i==(str.length()-1)){
            cout<<count;
        }
    }
    

}
