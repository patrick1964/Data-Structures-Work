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
//			m->next=null;
			head=m;
			current=head;
		}
		void addElem(string c, int val){
			node* m= new node;
			m->ac=c;
			m->d=val;
			m->next=head;
			head=m;
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
};
static LL list;
void search(string c){
	node* n=list.head;
	while(n->ac!=c){
		n=n->next;
	}
	while(n!=null){
		cout<<"airport: "<<n->ac<<endl;
		cout<<"distance distance from last: "<<n->d<<endl;
		n=n->next;
	}
}
int recursAdd(node* h){
	if(h==null){
		return 0;
	}else
		return recursAdd(h->next)+h->d;
}
int loopAdd(node* p){
	int total;
	for(node* i=p;i!=null;i=i->next){
		total+=i->d;
	}
	return total;
}
void add(){
	string c;
	int temp;
	cout<<"enter a 3 digit airport code: ";
	cin.ignore();
	getline(cin, c);
	cout<<"enter a distance from last and press enter: ";
	cin>>temp;
	list.addElem(c,temp);
}
int main(){
	int t=1;
	cout<<"please enter the airports\nin the order of closest to farthest."<<endl;
	while(t!=0){
		cout<<"what would you like to do? enter one of the following\n1) to enter an airport\n"
			<<"2) to search for one\n3) add distance recursively\n4) add distance in a loop\nenter 0 to exit: ";
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
		if(t==3||t==4){
			node* h=list.head;
			string c;
			cout<<"enter the code for the destination airport: ";
			cin.ignore();
			getline(cin,c);
			while( h != null&&h->ac != c){
				h=h->next;
			}
			if(h==null){
				cout<<"nonexisting code entered."<<endl;
			}
			else if(t==3){
				cout<<"distance from LGA to "<<c<<" is: "<<recursAdd(h)<<endl;
			}
			else if(t==4){
				cout<<"distance from LGA to "<<c<<" is: "<<loopAdd(h)<<endl;
			}
		}
	}
}
