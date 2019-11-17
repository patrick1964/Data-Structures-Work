#include<iostream>
#include<string>
using namespace std;

class node{
	public:
		char a;
		node* next;
};
class stack{
	public:
		node* head=0;
		char pop(){
			node* e=head;
			head=head->next;
			return e->a;
		}
		void push(char c){
			node* e=new node;
			e->a=c;
			e->next=head;
			head=e;
		}
		char top(){
			return head->a;
		}
		bool isempty(){
			if(head==0)
				return true;
			else
				return false;
		}
};
char arr[]={'(','{','[', ']','}',')' };
bool eval(char v1, char v2){
	int val1,val2;
	for(int i=0;i<6;i++){
		if(arr[i]==v1)
			val1=i;
		if(arr[i]==v2)
			val2=i;
	}
	if(val1+val2!=5)
		return false;
	return true;
}
void convert(string s){
	stack stk;
	char temp,c;
	int val1;
	for(int i=0;i<s.length();i++){
		c=s.at(i);
		val1=0;
		for(int j=0;j<6;j++){
			if(arr[j]==c)
				val1=j;
		}
		
		if(val1>2&&!stk.isempty()){
			temp=stk.pop();
			if(!eval(temp, c)){
				cout<<"parenthesis do not match: "<<temp<<c;
				return;
			}
		}
		else{
			stk.push(c);
		}
	}
	if(stk.isempty())
		cout<<"parenthesis do match";
	else
		cout<<"parenthesis do not match: "<<stk.pop();
}
int main(){
	string c;
	cout<<"enter a set of parenthesis: ";
	getline(cin,c);
	convert(c);
}
