#include <iostream>
#include <string>
using namespace std;

void max_pal(string s){
    int n = s.length();
    int max_len = 0;
    int si, ei;

    //odd
    for(int axis = 0; axis < n; axis++){
        int k = 0;
        while(axis-k>=0 && axis+k<n && s.at(axis - k) == s.at(axis + k)){   
            int l = 2*k + 1;         
            if(max_len < l){
                max_len = l;
                si = axis - k;
                ei = axis + k;
            }
            k++;
        }
    }

    //even
    for(float axis = 0.5; axis < n; axis+=0.5){
        float k = 0.5;
        while(axis-k>=0 && axis+k<n && s.at(axis - k) == s.at(axis + k)){     
            if(max_len < 2*k + 1 ){
                max_len = 2*k + 1;
                si = axis - k;
                ei = axis + k;
            }
            k++;
        }
    }
    cout<<endl<<"Max pallindrome: ";
    for(int c = si; c <= ei; c++)
        cout<<s.at(c);
}

int main(){
    string s;
    getline(cin,s);

    max_pal(s);

    return 0;
}
