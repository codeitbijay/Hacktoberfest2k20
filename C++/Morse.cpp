#include <iostream>
using namespace std;

char alphabet [] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
string MorseAlphabet[] = {".-", "-...", "-.-.", "-..", ".",
        "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",
        "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--",
        "--.."};
char Alphabet[] = {'A', 'B', 'C','D', 'E', 'F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z', ' '}; 

void translate(string *nama, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<nama[i].length();j++){
            for(int k=0;k<26;k++){
            if(nama[i][j]==Alphabet[k] || nama[i][j]==alphabet[k]){
                cout << MorseAlphabet[k] << "/";
            }else if(nama[i][j]==alphabet[26]) {
                cout << "/"; break;
            }
        }
    }cout << endl;}
}
int main(){
    int n;
    cin>>n;
    string nama[n];cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin, nama[i]);
    }
    translate(nama, n);
    return 0;
}
