#include<iostream>
#include<string>
using namespace std;
#define null 0
class node{
	public:
		string name;
		double balance;
		int key;
		node* left;
		node* right;
		node* parent;
};
class BST{
	public:
		node* root=null;
		void createNode(int k, string n, double b){
			node* w= new node;
			w->name=n;
			w->key=k;
			w->balance=b;
			w->left=null;
			w->right=null;
			addNode(w,root);
		}
		void addNode(node *&n, node *&p){
			if(p==null){
				p=n;
			}
			else if(p->key>n->key){
				addNode(n,p->left);
			}else if(p->key<n->key){
				addNode(n,p->right);
			}else
				cout<<"error"<<endl;

		}
		node* psearch(int key, node* p){
			if(p!=null){
				node* temp=psearch(key,p->left);
				if(temp!=null){
					return temp;
				}
				else if(p->key==key)
					return p;
				else
					psearch(key,p->right);
			}
			else{
				return null;
			}
		}
		void search(int key, node* p){
			node* res=psearch(key,root);
			if(res!=null)
				cout<<"node search results: {"<<res->key<<", "<<res->name<<", "<<res->balance<<"}"<<endl;
			else
				cout<<"node not found"<<endl;
		}
		void printTree(node* p){
			if(p!=null){
				printTree(p->left);
				cout<<"{"<<p->key<<", "<<p->name<<", "<<p->balance<<"}";
				printTree(p->right);
			}
		}
};
int main(){
	int key;
	string name;
	double balance;
	int temp;
	BST tree;
	cout<<"enter number of keys to be entered: ";
	cin>>temp;
	for(int i=0;i<temp;i++){
		cout<<"enter key: ";
		cin>>key;
		cout<<"enter name: ";
		cin.ignore();
		getline(cin,name);
		cout<<"enter balance: ";
		cin>>balance;
		tree.createNode(key,name,balance);
	}
	cout<<"enter key to search: ";
	cin>>key;
	tree.search(key,tree.root);
	tree.printTree(tree.root);
	
}
