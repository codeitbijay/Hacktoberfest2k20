#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    stringstream ss(str);
    char ch;
    int a;
    vector<int> In;
    ss>>a;
    In.push_back(a);
    for(int i=0;i<str.size();i++)
    {
        ss>>ch>>a;
        if(ss.fail())
        {
            break;
        }
        else
        {
            In.push_back(a);
        }
    }
    return In;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

