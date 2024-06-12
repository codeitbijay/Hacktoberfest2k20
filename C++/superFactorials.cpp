#include<bits/stdc++.h>
using namespace std;

string add(string s1, string s2){
    string ans = "";
    int ptr1 = s1.length()-1, ptr2 = s2.length()-1;
    int carry = 0;
    while(ptr1 >= 0 && ptr2 >= 0){
        int val = (s1[ptr1]-'0')+(s2[ptr2]-'0')+carry;
        if(val > 9){ ans += to_string(val%10); carry = val/10; }
        else{ ans += to_string(val); carry = 0; }
        --ptr1; --ptr2;
    }
    if(ptr1 < 0 && ptr2 < 0){
        if(carry > 0){ ans += to_string(carry); }
    }
    else if(ptr1 >= 0){
        while(ptr1 >= 0){
            int val = (s1[ptr1]-'0')+carry;
            if(val > 9){ ans += to_string(val%10); carry = val/10; }
            else{ ans += to_string(val); carry = 0; }
            --ptr1;
        }
        if(carry > 0){ ans += to_string(carry); }
    }
    else{
            while(ptr2 >= 0){
            int val = (s2[ptr2]-'0')+carry;
            if(val > 9){ ans += to_string(val%10); carry = val/10; }
            else{ ans += to_string(val); carry = 0; }
            --ptr2;
        }
        if(carry > 0){ ans += to_string(carry); }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string multiply(string num1, string num2) {
    string ans = "0", temp = "";
    int n1 = num1.length(), n2 = num2.length();
    if(n1 < n2){ swap(num1, num2); swap(n1, n2); }
    for(int i = n2-1; i >= 0; i--){
        int carry = 0;
        for(int j = n1-1; j >= 0; j--){
            int val = (num2[i]-'0')*(num1[j]-'0') + carry;
            if(val > 9){
                temp += to_string(val%10);
                carry = val/10;
            }
            else{ temp += to_string(val); carry = 0; }
        }
        if(carry > 0){ temp += to_string(carry); }
        reverse(temp.begin(), temp.end());
        for(int j = 0; j < n2-1-i; j++) temp += to_string(0);
        ans = add(ans, temp); temp = "";
    }
    int ptr = 0;
    for(int i = 0; i < ans.length()-1; i++){ 
        if(ans[i] == '0') ptr = i+1; 
        else break;
    }
    return ans.substr(ptr);
}

int main(){ 
    int val;
    cout<<"enter a number below 500 for factorial calculation : ";
    cin>>val;
    string ans = "1";
    for(int i = val; i > 0; i--){
        ans = multiply(ans, to_string(i));
    }
    cout<<"factorial of "<<val<<" is "<<ans<<endl;
}
