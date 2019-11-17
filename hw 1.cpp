#include <iostream>
#include <algorithm>
using namespace std;

void getGrades(int a){
	int grades[a];
	int total=0;
	for(int i=0;i<a;i++){
		cout<<"enter grade number "<<i+1<<": ";
		cin>>grades[i];
		total+=grades[i];
	}
	sort(grades, grades+a);
	for(int i=0;i<a;i++){
		cout<<grades[i]<<endl;
	}
	cout<<"average: "<<total/a;
}

int main(){
	int temp;
	cout<<"enter the number of students (max of 30): ";
	cin>>temp;
	getGrades(temp);
}
