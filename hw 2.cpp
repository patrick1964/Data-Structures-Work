#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Party{
	public:
	char partyT;
	string address;
	string phone;
};
class Person : public Party{
	public:
	string fname;
	string lname;
	string dob;	
};

class Passenger : public Person
{
	public:
	string tnum;
	int ffnum;
	double price;
	int fnum;
	string seat;
	string date;
	char status;
	void enterPas(){
		cout<<"enter Passenger first name then press enter: ";
		cin.ignore();
		getline(cin, fname);
		cout<<"enter Passenger last name then press enter: ";
		getline(cin, lname);
		cout<<"enter Passenger address then press enter: ";
		getline(cin, address);
		cout<<"enter Passenger phone number in format [###-###-####] then press enter: ";
		getline(cin, phone);
		cout<<"enter Passenger date of birth in format [##-##-####] then press enter: ";
		getline(cin, dob);
		cout<<"enter Ticket Number in format [#######] then press enter: ";
		getline(cin, tnum);
		cout<<"enter Frequent Flyer Number (valid alphanumeric or 0) then press enter: ";
		cin>>ffnum;
		cout<<"enter Ticket Price in format [##.##] then press enter: ";
		cin>>price;
		cout<<"enter flight Number in format [####] then press enter: ";
		cin>>fnum;
		cout<<"enter the seat location then press enter: ";
		cin.ignore();
		getline(cin, seat);
		cout<<"enter flight date then press enter: ";
		getline(cin, date);
		partyT='p';
		status='t';
	}
};
static vector<Passenger> pas;
/*
void enterPas(){
	Passenger temp;
	string t;
	cout<<"enter Passenger first name then press enter: ";
	cin.ignore();
	getline(cin, temp.fname);
	cout<<"enter Passenger last name then press enter: ";
	getline(cin, temp.lname);
	cout<<"enter Passenger address then press enter: ";
	getline(cin, temp.address);
	cout<<"enter Passenger phone number in format [###-###-####] then press enter: ";
	getline(cin, temp.phone);
	cout<<"enter Passenger date of birth in format [##-##-####] then press enter: ";
	getline(cin, temp.dob);
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
	temp.partyT='p';
	temp.status='t';
	pas.push_back(temp);
}*/

void searchPas(){
	if(!pas.empty()){
		string temp;
		cout<<"enter the ticket number: ";
		cin.ignore();
		getline(cin, temp);
		for(int i=0; i< pas.size();i++){
			if(pas[i].tnum.compare(temp)==0){
				cout<<"name: "<<pas[i].fname<<" "<<pas[i].lname<<endl;
				cout<<"ticket number: "<<pas[i].tnum<<endl;
				if(pas[i].ffnum!=0)
					cout<<"frequent flyer number: "<<pas[i].ffnum<<endl;
				cout<<"ticket price: $"<<pas[i].price<<endl;
				cout<<"flight number: "<<pas[i].fnum<<endl;
				cout<<"seat location: "<<pas[i].seat<<endl;
				cout<<"flight date: "<<pas[i].date<<endl;
				cout<<"status: "<<((pas[i].status=='t')? "ticketed": (pas[i].status=='h')? "on hold": (pas[i].status=='c')? "cancelled": "N/A")<<endl;
			}
		}
	}else
		cout<<"no passangers entered"<<endl;
}
void changeStatus(){
	if(!pas.empty()){
		string temp;
		cout<<"enter the ticket number: ";
		cin.ignore();
		getline(cin, temp);
		for(int i=0; i< pas.size();i++){
			if(pas[i].tnum.compare(temp)==0){
				cout<<"what would you like to chance the status to? enter t for ticketed, h for on hold, and c for cancelled: ";
				cin>>pas[i].status;
				cout<<"name: "<<pas[i].fname<<" "<<pas[i].lname<<endl;
				cout<<"ticket number: "<<pas[i].tnum<<endl;
				if(pas[i].ffnum!=0)
					cout<<"frequent flyer number: "<<pas[i].ffnum<<endl;
				cout<<"ticket price: $"<<pas[i].price<<endl;
				cout<<"flight number: "<<pas[i].fnum<<endl;
				cout<<"seat location: "<<pas[i].seat<<endl;
				cout<<"flight date: "<<pas[i].date<<endl;
				cout<<"status: "<<((pas[i].status=='t')? "ticketed": (pas[i].status=='h')? "on hold": (pas[i].status=='c')? "cancelled": "N/A")<<endl;
			}
		}
	}else
		cout<<"no passangers entered"<<endl;
}
void changeSeat(){
	if(!pas.empty()){
		string temp;
		cout<<"enter the ticket number: ";
		cin.ignore();
		getline(cin, temp);
		for(int i=0; i< pas.size();i++){
			if(pas[i].tnum.compare(temp)==0){
				cout<<"enter a new seat number: ";
				getline(cin, pas[i].seat);
				cout<<"name: "<<pas[i].fname<<" "<<pas[i].lname<<endl;
				cout<<"ticket number: "<<pas[i].tnum<<endl;
				if(pas[i].ffnum!=0)
					cout<<"frequent flyer number: "<<pas[i].ffnum<<endl;
				cout<<"ticket price: $"<<pas[i].price<<endl;
				cout<<"flight number: "<<pas[i].fnum<<endl;
				cout<<"seat location: "<<pas[i].seat<<endl;
				cout<<"flight date: "<<pas[i].date<<endl;
				cout<<"status: "<<((pas[i].status=='t')? "ticketed": (pas[i].status=='h')? "on hold": (pas[i].status=='c')? "cancelled": "N/A")<<endl;
			}
		}
	}else
		cout<<"no passangers entered"<<endl;
}

int main(){
	int task=1;
	while(task!=0){
		cout<<"what would you like to do now? [for ticket purchasing enter 1 to search for a passanger enter 2 to change ticket status enter 3 to change seating enter 4 to exit enter 0: ";
		cin>>task;
		if(task==1){
			Passenger p;
			p.enterPas();
			pas.push_back(p);
		}
		if(task==2)
			searchPas();
		if(task==3)
			changeStatus();
		if(task==4)
			changeSeat();
		if(task==0)
			cout<<"Initilizing hack..."<<endl<<endl<<endl<<"na, just kidding professor. have a good day!";
	}
	
}
