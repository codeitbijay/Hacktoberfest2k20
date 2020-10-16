#include<iostream>
#include<string>
#include<stack>
using namespace std;

int precidence(char oper){
	if(oper == '+'){
		return 1;
	}
	else if(oper == '-'){
		return 1;
	}
	else if(oper == '*'){
		return 2;
	}
	else if(oper == '/'){
		return 2;
	}
	return 0;
}

int operation(int v1 , int v2, char oper){
	if(oper == '+'){
		return v1 + v2;
	}
	else if(oper == '-'){
		return v1 - v2;
	}
	else if(oper == '*'){
		return v1 * v2;
	}
	else if(oper == '/'){
		return v1 / v2;
	}
	return 0;
}

int main()
{
	string str;
	getline(cin , str);
	stack<int> o1;
	stack<char> o2;

	for(int i = 0 ; i < str.length() ; i++)
	{
	    char ch = str.at(i);
        if(ch == ' ')
        {
        	continue;
        }
        else
        {
            if(ch == '(')
            {
            	o2.push(ch);
            }
            else if(ch == ')')
            {
            	while(o2.top() != '('){
            	char op = o2.top();
            	o2.pop();
            	int v2 = o1.top();
            	o1.pop();
            	int v1 = o1.top();
            	o1.pop();
            	int ans = operation(v1 ,v2 , op);
            	o1.push(ans);
            }
            o2.pop();
            }
            else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
              	int pc = precidence(str[i]);
              	while(!o2.empty() && o2.top() != '(' && precidence(o2.top()) >= pc)
              	{
              	    char op = o2.top();
            		o2.pop();
            		int v2 = o1.top();
            		o1.pop();
            		int v1 = o1.top();
            		o1.pop();
            		int ans = operation(v1 ,v2 , op);
            		o1.push(ans);
              	}
              	o2.push(ch);
            }
            else
            {
            	o1.push(int(str[i])- 48);
            }
        }
    }
        	while(!o2.empty()){
			char op = o2.top();
			o2.pop();
			int v2 = o1.top();
			o1.pop();
			int v1 = o1.top();
			o1.pop();
			int ans = operation(v1 ,v2 , op);
			o1.push(ans);
		}
		cout<<o1.top();

	return 0;
}
/*
Infix Evaluation

Question
1. You are given an infix expression.
2. You are required to evaluate and print it's value.

Constraints
1. Expression is balanced
2. The only operators used are +, -, *, /
3. Opening and closing brackets - () - are used to impact precedence of operations
4. + and - have equal precedence which is less than * and /. * and / also have equal precedence.
5. In two operators of equal precedence give preference to the one on left.
6. All operands are single digit numbers.
Sample Input
2 + 6 * 4 / 8 - 3
Sample Output
2
*/
