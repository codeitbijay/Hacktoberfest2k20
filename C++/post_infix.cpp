#include<iostream>
#include<string.h>
using namespace std;
#define max 100

class post_infix{
public:
	int top;
	char s[max],temp[max];
	post_infix(){
		top=-1;
	}
	void input();
	void convert();
	int precedence(char ch);
	void display();
};

void post_infix::input(){
	cout<<"Enter the infix expression you wish to convert: ";
	cin>>temp;
}

int post_infix::precedence(char ch){
	switch(ch){
		case '/':
		case '*':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return -1;
	}
}
void post_infix::convert(){
	int n=strlen(temp);
	for(int i=0;i<n;i++){
		if(temp[i]=='+' || temp[i]=='-' || temp[i]=='*' || temp[i]=='/'){
			int p1,p2;
					p1=precedence(s[top]);
					p2=precedence(temp[i]);
				if(p1>=p2){
					cout<<s[top--];
					s[++top]=temp[i];
				}
				else{
					s[++top]=temp[i];
				}
		}
		else if( temp[i]=='(' ){
			s[++top]=temp[i];
		}
		else if( temp[i]==')' ){
			while(s[top]!='('){
				cout<<s[top--];
			}
			top--;
		}
		else{
			cout<<temp[i];
		}
	}
}
void post_infix::display(){
		while(top!=-1){
			cout<<s[top--];
		}
}
int main(){
	post_infix ob;
	ob.input();
	ob.convert();
	ob.display();
	return 0;
}