#include<iostream>
#include<string>
#include<math.h>
using namespace std;
#define null 0
class node{
	public:
	int key=0,p,mins;
	string lname;
	string ffs;
	node* next;
	node* last;
	
};
class SortedDLL{
	public:
		void addForward(node* w){
			if(head==null){
				head=w;
				current=head;
				w->last=null;
				return;
			}
			node* temp=head;
			while(temp->next!=null&&!(temp->key>w->key))
				temp=temp->next;
			if(temp->key>w->key){
				addElemBefore(w,temp);
			}
			else
				addElemAfter(w, temp);
		}
		node* pop(){
			if(head!=null){
				node* temp=head;
				head=head->next;
				if(head!=null)
					head->last=null;
				return temp;
			}else
				return null;
		}
		/*void printNodes(){
			node* temp=head;
			cout<<"{";
			while(temp!=null){
				cout<<"("<<temp->on<<", "<<temp->off<<"),";
				temp=temp->next;
			}
			cout<<"}"<<endl;
		}*/
		void addElemBefore(node* e,node* p){
			e->next=p;
			if(p->last!=null){
				e->last=p->last;
				e->last->next=e;
			}
			else{
				e->last=null;
				head=e;
			}
			p->last=e;
		}
		void addElemAfter(node* e,node* p){
			e->last=p;
			if(p->next!=null){
				e->next=p->next;
				e->next->last=e;
			}else
				e->next=null;
			p->next=e;
		}
		node* takeInput(){
			node* temp=new node;
			cout<<"enter Passenger last name then press enter: ";
			getline(cin, temp->lname);
			cout<<"enter Frequent Flyer status [4 letters] then press enter: ";
			cin>>temp->ffs;
			cout<<"enter price paid then press enter: ";
			cin>>temp->p;
			cout<<"enter minutes prior to departure then press enter: ";
			cin>>temp->mins;	
		}
		void calculateKey(node* temp){
			if(temp->ffs.compare("NONE")==0)
				temp->key+=40;
			else if(temp->ffs.compare("SLVR")==0)
				temp->key+=30;
			else if(temp->ffs.compare("GOLD")==0)
				temp->key+=20;
			if(temp->p<500){
				temp->key+=(ceil((500.0-temp->p)/50)*5);
			}
			if(temp->mins<60)
				temp->key+=(60-temp->mins);
			addForward(temp);
		}
		void addNode(){
			node* temp=takeInput();
			calculateKey(temp);
		}
		void addNode(string lname, string ffs, int p, int mins){
			node* temp= new node;
			temp->lname=lname;
			temp->ffs=ffs;
			temp->p=p;
			temp->mins=mins;
			calculateKey(temp);
		}
		void print(){
			node* temp=pop();
			cout<<"{";
			while(temp!=null){
				cout<<"("<<temp->lname<<", "<<temp->key<<"),";
				temp=pop();
			}
			cout<<"}"<<endl;
		}
		node* head=null;
		node* current=null;
};
int main(){
	SortedDLL priority;
	priority.addNode("jones","GOLD", 437, 30);
	priority.addNode("smith","PLAT", 385, 38);
	priority.addNode("lee","NONE",600,58);
	priority.addNode("harris","SLVR",486,45);
	priority.addNode("white", "GOLD",451,60);
	priority.print(); 
}
