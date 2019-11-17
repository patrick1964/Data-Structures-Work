#include<iostream>
#include<string>
using namespace std;
#define null 0
class node{
	public:
		char key;
		node* children;
		node* next;
		node* parent;
};
class Trie{
	public:
		node* root= createNode(' ',null,null);
		node* createNode(char k, node* p, node* n){
			node* w= new node;
			w->key=k;
			w->children=null;
			w->parent=p;
			w->next=n;
			return w;
			//addNode(w,root);
		}
		void input(string in){
			node* temp=root;
			node* parent=null;
			for(int i=0;i<in.size();i++){
				if(in.at(i)!=' '){
					parent=temp;
					temp=psearch(in.at(i),temp->children);
					if(temp==null){
						temp=createNode(in.at(i),parent,parent->children);
						parent->children=temp;
					}
				}
				else{
					temp=root;
				}			
			}
		}
		node* psearch(char key, node* c){
			if(c!=null){
			//	node* temp=psearch(key,p->next);
				if(c->key==key){
					return c;
				}
				else if(c->next!=null)
					return psearch(key,c->next);
				else
					return null;
			}
			else{
				return null;
			}
		}
		void search(string s){
			node* res=psearch(s.at(0),root->children);
			for(int i=1;i<s.size();i++){
				if(res!=null)
					res=psearch(s.at(i),res->children);	
			}
			if(res!=null&&res->children==null)
				cout<<"found"<<endl;
			else
				cout<<"not found"<<endl;
		}
		void printTree(node* p){
			if(p!=null){
				cout<<p->key;
				printTree(p->children);
				printTree(p->next);
			}
		}
};
int main(){
	Trie t;
	t.input("i like food");
	string word;
	cout<<"enter a word to search: ";
	cin>>word;
	t.search(word);
	t.printTree(t.root);
	
}
