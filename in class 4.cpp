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
char arr[]={')','+','-','*','/','^','('};
bool eval(char v1, char v2){
	int val1,val2;
	for(int i=0;i<7;i++){
		if(arr[i]==v1)
			val1=i;
		if(arr[i]==v2)
			val2=i;
	}
	if((val1+val2)==3||(val1+val2)==7||val1<val2)
		return true;
	return false;
}
bool isOperator(char c){
	for(int i=0;i<7;i++){
		if(arr[i]==c)
			return true;
	}
	return false;
}
void convert(string s){
	string output="";
	stack stk;
	char temp;
	for(int i=0;i<s.length();i++){
		char c=s.at(i);
		if(!isOperator(s.at(i)))
			output+=c;
		else{
			temp=c;
			while(!stk.isempty()&&eval(temp,stk.top())){
				temp=stk.pop();
				if(temp!='(')
					output+=temp;
			}
			if(c!=')')
				stk.push(c);
		}
	}
	while(!stk.isempty()){
		output+=stk.pop();
	}
	cout<<output;
}
int main(){
	string c;
	cout<<"enter an arithmatic expression without parentheses: ";
	getline(cin,c);
	convert(c);
}
