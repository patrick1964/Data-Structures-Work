#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
#define null 0
class node{
	public:
	int on;
	int off;
	node* next;
	node* last;
	
};
class Elevator{
	public:
		Elevator(){
			node* m=new node;
			m->on=1;
			m->off=null;
			m->last=null;
			m->next=null;
			head=m;
			current=head;
		}
		void getOn(int val, int val2){
			node* m= new node;
			m->on=val;
			m->off=val2;
			addForward(m);
		}
		void getOff(int val){
			node* m= new node;
			m->on=val;
			m->off=null;
			m->next=null;
			addForward(m);
		}
		void addForward(node* w){
			node* temp=current;
			while(temp->next!=null&&temp->on<w->on)
				temp=temp->next;
			if(temp->on>w->on){
				addBackward(w,temp);
			}
			if(temp->on<=w->on)
				addElemAfter(w, temp);
		}
		
		void addBackward(node* w,node* t){
			node* temp=t;
			while(temp->last!=null&&temp->on>w->on){
				temp=temp->last;
			}
			if(temp->on<=w->on)
				addElemAfter(w,temp);
			if(temp->on>w->on)
				addElemBefore(w,temp);
				 	
		}
		void move(string name){
			/*if(current->off==null){
				current=current->next;
			}*/
			if(current->next!=null){
				if(current->last!=null){
					if((current->next->on-current->on)<=(current->on-current->last->on)){
						current=moveup(name);
						current=movedown(name);
					}else{
						current=movedown(name);
						current=moveup(name);
					}		
				}else{
					current=moveup(name);
					current=movedown(name);
				}
			}else{
				current=movedown(name);
				current=moveup(name);
			}
			/*if(current==head)
				cout<<"back to floor one"<<endl;*/
		}
		node* moveup(string name){
			node* temp=current;
			if(current->last!=null||current->next!=null){
				deletenode(current);
				current=current->next;
			}
			while(current!=null){
				if(current->off!=null){
					cout<<name<<": getting on at "<<current->on<<endl;
					getOff(current->off);
				}else
					cout<<name<<": getting off at "<<current->on<<endl;
				deletenode(current);
				temp=current;
				current=current->next;
				if(current!=null)
					delete temp;
			}
			if(temp->last!=null){
				current=temp;
				return movedown(name);
			}
			return temp;
		}
		node* movedown(string name){
			node* temp=current;
			if(current!=null){
				deletenode(current);
				current=current->last;
			}
			while(current!=null){
				if(current->off!=null){
					cout<<name<<": getting on at "<<current->on<<endl;
					getOff(current->off);
				}else{
					cout<<name<<": getting off at "<<current->on<<endl;
				}
				deletenode(current);
				temp=current;
				current=current->last;
				if(current!=null)
					delete temp;
			}
			if(temp->next!=null){
				current=temp;
				return moveup(name);
			}
			return temp;
		}
		void deletenode(node* temp){
			if(temp->next!=null)
				temp->next->last=temp->last;
			if(temp->last!=null)
				temp->last->next=temp->next;
		}
		void printNodes(){
			node* temp=current;
			cout<<"{";
			while(temp!=null){
				cout<<"("<<temp->on<<", "<<temp->off<<"),";
				temp=temp->next;
			}
			cout<<"}"<<endl;
		}
		void addElemBefore(node* w,node*t){
			w->next=t;
			if(t->last!=null){
				w->last=t->last;
				w->last->next=w;
			}
			else
				w->last=null;
			t->last=w;
		}
		void addElemAfter(node* w,node*t){
			w->last=t;
			if(t->next!=null){
				w->next=t->next;
				w->next->last=w;
			}else
				w->next=null;
			t->next=w;
		}
		node* head;
		node* current;
};
class ElevatorControl{
	public:
		Elevator ele1;
		Elevator ele2;
		bool ele1added=false,ele2added=false;
		void getOn(int on,int off){
			int ele1dis=ele1.current->on-on,ele2dis=ele2.current->on-on;
			if(abs(ele1dis)<=abs(ele2dis)){
				ele1.getOn(on,off);
				ele1added=true;
			}
			else{
				ele2.getOn(on,off);
				ele2added=true;
			}
		}
		void move(){
			if(ele1added){
				ele1.move("ele1");
				ele1added=false;
			}
			if(ele2added){
				ele2.move("ele2");
				ele2added=false;
			}
		}
};
static ElevatorControl ele;
int main(){
	ele.getOn(4,6);
	ele.move();
	ele.getOn(8,2);
	ele.getOn(1,5);
	ele.getOn(9,3);
	ele.move();
	ele.getOn(10,2);
	ele.getOn(7,4);
	ele.move();
	ele.getOn(1,7);
	ele.move();
}
