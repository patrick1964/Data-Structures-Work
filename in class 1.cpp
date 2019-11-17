#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct pasInfo
{
	string name;
	string tnum;
	int ffnum;
	double price;
	int fnum;
	string seat;
	string date;
};
static vector<pasInfo> pas;

void enterPas(){
	pasInfo temp;
	string t;
	cout<<"enter Passenger Name then press enter: ";
	cin.ignore();
	getline(cin, temp.name);
	cout<<"enter Ticket Number in format [#######] then press enter: ";
	getline(cin, temp.tnum);
	cout<<"enter Frequent Flyer Number (valid alphanumeric or 0) then press enter: ";
	cin>>temp.ffnum;
	cout<<"enter Ticket Price in format [##.##] then press enter: ";
	cin>>temp.price;
	cout<<"enter flight Number in format [####] then press enter: ";
	cin>>temp.fnum;
	cout<<"enter the seat location then press enter: ";
	cin.ignore();
	getline(cin, temp.seat);
	cout<<"enter flight date then press enter: ";
	getline(cin, temp.date);
	pas.push_back(temp);
}

void searchPas(){
	if(!pas.empty()){
		string temp;
		cout<<"enter the ticket number: ";
		cin.ignore();
		getline(cin, temp);
		cout<<temp<<endl;
		for(int i=0; i< pas.size();i++){
			if(pas[i].tnum.compare(temp)==0){
				cout<<"name: "<<pas[i].name<<endl;
				cout<<"ticket number: "<<pas[i].tnum<<endl;
				if(pas[i].ffnum!=0)
					cout<<"frequent flyer number: "<<pas[i].ffnum<<endl;
				cout<<"ticket price: $"<<pas[i].price<<endl;
				cout<<"flight number: "<<pas[i].fnum<<endl;
				cout<<"seat location: "<<pas[i].seat<<endl;
				cout<<"flight date: "<<pas[i].date<<endl;
			}
		}
	}else
		cout<<"no passangers entered"<<endl;
}

int main(){
	int task=1;
	while(task!=0){
		cout<<"what would you like to do now? [to enter a passanger enter 1 to search for a passanger enter 2 to exit enter 0: ";
		cin>>task;
		if(task==1)
			enterPas();
		if(task==2)
			searchPas();
		if(task==0)
			cout<<"Initilizing hack..."<<endl<<endl<<endl<<"na, just kidding professor. have a good day!";
	}
	
}




