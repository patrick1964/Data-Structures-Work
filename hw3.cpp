#include<iostream>
#include<string>
using namespace std;
#define null 0
class node{
	public:
	string ac;
	int d;
	node* next;
};
class LL{
	public:
		LL(){
			node* m=new node;
			m->ac="LGA";
			m->d=0;
			head=m;
			current=head;
			last=m;
		}
		void addElem(string c, int val){
			node* m= new node;
			m->ac=c;
			m->d=val;
			m->next=null;
			if(last!=null)
				last->next=m;
			last=m;
			if(head==null){
				head=m;
			}
		}
		void print(){
			current=head;
			while(current!=null){
				cout<<current->ac<<": "<<current->d<<endl;
				current=current->next;
			}
		}
		node* head;
		node* current;
		node* last;
};
static LL list;
void search(string c){
	node* n=list.head;
	while(n->ac!=c){
		n=n->next;
	}
	while(n!=null){
		cout<<"airport: "<<n->ac<<endl;
		cout<<"distance: "<<n->d<<endl;
		n=n->next;
	}
}
void add(){
	string c;
	int temp;
	cout<<"enter a 3 digit airport code: ";
	cin.ignore();
	getline(cin, c);
	cout<<"enter a distance and press enter: ";
	cin>>temp;
	list.addElem(c,temp);
}
int main(){
	int t=1;
	cout<<"please enter the airports in the order of closest to farthest."<<endl;
	while(t!=0){
		cout<<"what would you like to do? enter 1 to enter an airport and 2 to search for one. enter 0 to exit: ";
		cin>>t;
		if(t==1)
			add();
		if(t==2){
			string c;
			cout<<"enter the airport code: ";
			cin.ignore();
			getline(cin,c);
			search(c);
		}
	}
}
