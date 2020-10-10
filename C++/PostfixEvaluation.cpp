// Program to evaluate postfix expression in c++ by chinmay

#include <iostream>
#include <stack>
using namespace std;

// Function to verify whether a character is numeric digit or not 
bool IsNumericDigit(char C) 
{
	if(C >= '0' && C <= '9') 
		return true;
	else
		return false;
}

// Function to evaluate postfix expression
int Evaluator(string exp)
{
	stack<int> stack;

	for (int i = 0; i < exp.length(); i++)
	{
		if(exp[i] == ' ' || exp[i] == ',') 
			continue; 
		
		else if (IsNumericDigit(exp[i])) {
			stack.push(exp[i] - '0');
		}
		
		else
		{
			int op1 = stack.top();
			stack.pop();

			int op2 = stack.top();
			stack.pop();

			if (exp[i] == '+')
				stack.push(op2 + op1);

			else if (exp[i] == '-')
				stack.push(op2 - op1);

			else if (exp[i] == '*')
				stack.push(op2 * op1);

			else if (exp[i] == '/')
				stack.push(op2 / op1);
		}
	}

	return stack.top();
}

int main() { // Driver code
	string exp;	
	cout<<"Enter postfix expression: ";
	cin>>exp;
	cout <<"Output: "<<Evaluator(exp);

	return 0;
}