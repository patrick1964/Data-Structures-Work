#include<iostream>
#include<algorithm>
#include <stdexcept>
using namespace std;
typedef int Elem;
class ArrayVector{
	public:
		ArrayVector(){
			capacity=0, n=0, A= new Elem;
		}
		int size() const{
			return n;
		}
		bool empty() const{
			return size()==0;
		}
		Elem operator[] (int i){
			return A[i];
		}
		
		Elem at(int i){
			if (i<0 || i>=n){
				cout<<"illegal index in function at ("<<i<<")";
				return -1;
			}
			return A[i];
		}
		
		void erase(int i){
  			for (int j = i+1; j<n; j++)
				A[j-1] = A[j];
			A[n-1]=0;
			n--;
			}
			
		void insert (int i, const Elem& e){
  			if (n >= capacity)
  				reserve(max(1,2 *capacity));
  			while(capacity<=i) reserve(max(1,2*capacity));
  			//cout<<"["<<capacity<<", "<<n<<"]";
  			//cout<<e<<" "<<size();
  			if(n>1){
				for (int j = n-1; j>=i; j--)
					A[j+1] = A[j];
			}
			A[i] = e;
			n++;
		}
		
		void reserve(int N){
  			if (capacity >= N) return;
  			Elem* B = new Elem[N];
  			for (int j=0; j<n; j++)
				B[j] = A[j];
  			if (A != NULL) delete [] A;
  			A = B;
  			capacity = N;
		}
		void content(){
			cout<<"{";
			if(n>1){
				for(int i=0;i<capacity-1;i++){
					if(A[i]!= 0)
						cout<<A[i];
					if(A[i+1]!=0)
						cout<<", ";
				}
			}
			if(A[capacity-1]!=0)
				cout<<A[capacity-1];
			cout<<"}";
		}
		void set(int i,const Elem& e){
			A[i]=e;
		}
	private:
		int capacity;
		int n;
		Elem* A;
};
int main(){
	ArrayVector v;
	v.insert(1,7);
	v.content();
	cout<<endl;
	v.insert(0,4);
	v.content();
	cout<<endl;
	cout<<v.at(1)<<"    ";
	v.content();
	cout<<endl;
	v.insert(2,2);
	v.content();
	cout<<endl;
	cout<<v.at(3)<<"    ";
	v.content();
	cout<<endl;
	v.erase(1);
	v.content();
	cout<<endl;
	v.insert(1,5);
	v.content();
	cout<<endl;
	v.insert(1,3);
	v.content();
	cout<<endl;
	v.insert(4,9);
	v.content();
	cout<<endl;
	cout<<v.at(2)<<"    ";
	v.content();
	cout<<endl;
	v.set(3,8);
	v.content();
}


