#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<cstring>
#include<iomanip>
using namespace std;
class ALLOCATION{
	private:
	  int room_no;
	  char name[30];
	  char address[50];
	  char phone[15];
	  long time;
	  long t1;
	  long t2;
	  long cost;
	  char rtype[30];
	  long pay;          
	public:
	  void main_menu();	 	          //to dispay the main menu
	  void add();			          //to book a room
	  void display(); 		          //to display the specific customer information
	  void rooms();			          //to display alloted rooms
	  void edit();			          //to edit the customer by calling modify or delete
	  int check(int);		          //to check room status
	  void modify();		          //to modify the customer information
	  void delete_rec();              //to check out the customer
	  void modify_name(int);          //to modify name of guest
	  void modify_address(int);       //to modify address of guest
	  void modify_phone(int);         //to modify phone number of guest
	  void modify_time(int);          //to modify days of stay of guest
	  }h;
int main(){
		h.main_menu();
	return 0;
}
void ALLOCATION::main_menu(){
	int choice;
	while(choice!=6){
		cout<<"\n\t\t\t\t WELCOME IN THE IS Robotics";
		cout<<"\n\t\t\t\t *******************";
		cout<<"\n\t\t\t\t **** MAIN MENU ****";
		cout<<"\n\t\t\t\t *******************";
		cout<<"\n\n\t\t\t\t1. Book A Room";
		cout<<"\n\t\t\t\t2. Host Information";
		cout<<"\n\t\t\t\t3. Rooms Allotted";
		cout<<"\n\t\t\t\t4. Edit Customer Details";
		cout<<"\n\t\t\t\t5. Exit";
		cout<<"\n\n\t\t\t\tEnter Your Choice: ";
		cin>>choice;
		switch(choice){
			case 1:	add();
				break;
			case 2: display();
				break;
			case 3: rooms();
				break;
			case 4:	edit();
				break;
			case 6: return;
			default:{
					cout<<"\n\n\t\t\tWrong choice.";
					cout<<"\n\t\t\tPress any key to continue.";
					getchar();
            }
         }
    }
}
void ALLOCATION::add(){
		int r,flag;
	ofstream fout("Record.DAT",ios::app|ios::binary);
	cout<<"\n\t\t\t +-----------------------------+";
	cout<<"\n\t\t\t | Rooms   |  Chair Capability | ";
	cout<<"\n\t\t\t +-----------------------------+";
	cout<<"\n\t\t\t |   1-5   |     10 Persons    |";
	cout<<"\n\t\t\t |   6-10  |     20 Persons    |";
	cout<<"\n\t\t\t |  11-20  |     30 Persons    |";
	cout<<"\n\t\t\t +-----------------------------+";
	cout<<"\n\n ENTER CUSTOMER DETAILS";
	cout<<"\n -----------------------";
	cout<<"\n\n Room Number: ";
	cin>>r;
	flag=check(r);
	if(flag==1)
		cout<<"\n Sorry, Room is already booked.\n";
	else{
	   if(flag==2)
		   cout<<"\n Sorry, Room does not exist.\n";
	   else{
		   room_no=r;
		   cout<<" Host Name: ";
		   cin>>name;
		   cout<<" Host Address: ";
		   cin>>address;
		   cout<<" Host Phone Number: ";
		   cin>>phone;
		   cout<<" Enter the Time of start(in 24 hours format): ";
		   cin>>t1;
	       cout<<" Enter the Time of end(in 24 hours format): ";
	       cin>>t2;{
		   if(t2>t1){
		   time=t2-t1;
	       }
	       else{
		   	cout<<"time scheduling is wrong";
		   }
		   }
		   if(room_no>=1&&room_no<=5){
		      strcpy(rtype,"10 Persons");
		      cost=time*1000;
		   }
		   else{
		      if(room_no>=6&&room_no<=10){
			 strcpy(rtype,"20 Persons");
			 cost=time*1250;
		      }
		      else{
			 if(room_no>=11&&room_no<=20){
			    strcpy(rtype,"30 Persons");
			    cost=time*1500;
			 }
			}
		}
		   fout.write((char*)this, sizeof(ALLOCATION));
		   cout<<"\n Room has been booked.";
	   }
	}
	cout<<"\n Press any key to continue.";
	getchar();
	getchar();
	fout.close();
}
void ALLOCATION::display(){
	ifstream fin("Record.DAT",ios::in|ios::binary);
	int r,flag;
	cout<<"\n Enter Room Number: ";
	cin>>r;
	while(fin.read((char*)this,sizeof(ALLOCATION))){
		if(room_no==r){
		cout<<"\n Customer Details";
			cout<<"\n ----------------";
			cout<<"\n\n Room Number: "<<room_no;
			cout<<"\n Host Name: "<<name;
			cout<<"\n Host Address: "<<address;
			cout<<"\n Host Phone Number: "<<phone;
			cout<<"\n Starting Time"<<t1;
			cout<<"\n Ending Time"<<t2;
			cout<<"\n Total Time "<<time<<" hours.";
			cout<<"\n Room Type: "<<rtype;
			cout<<"\n Total Cost Of Booking: "<<cost;
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Room is Vacant.";
	cout<<"\n\n Press any key to continue.";
	getchar();
	getchar();
	fin.close();
}
void ALLOCATION::rooms(){
	
	const char separator=' ';
	const int NoWidth=8;
	const int GuestWidth=17;
	const int AddressWidth=16;
	const int RoomWidth=13;
	const int ContactNoWidth=13;
	ifstream fin("Record.DAT",ios::in|ios::binary);
	cout<<"\n\t\t\t    LIST OF ROOMS ALLOTED";
	cout<<"\n\t\t\t   -----------------------";
	cout<<"\n\n +---------+------------------+-----------------+--------------+--------------+";
	cout<<"\n | Room No.|    Host Name    |      Address    |   Room Type  |  Contact No. |";
	cout<<"\n +---------+------------------+-----------------+--------------+--------------+";
	while(fin.read((char*)this,sizeof(ALLOCATION))){
		cout<<"\n |"<<setw(NoWidth)<<setfill(separator)<<room_no<<" |";
		cout<<setw(GuestWidth)<<setfill(separator)<<name<<" |";
		cout<<setw(AddressWidth)<<setfill(separator)<<address<<" |";
		cout<<setw(RoomWidth)<<setfill(separator)<<rtype<<" |";
		cout<<setw(ContactNoWidth)<<setfill(separator)<<phone<<" |";
	}
	cout<<"\n +---------+------------------+-----------------+--------------+--------------+";
	cout<<"\n\n\n\t\t\tPress any key to continue.";
	getchar();
	getchar();
	fin.close();
}
void ALLOCATION::edit(){
	
	int choice,r;
	cout<<"\n EDIT MENU";
	cout<<"\n ---------";
	cout<<"\n\n 1. Modify Customer Information.";
	cout<<"\n 2. Customer Check Out.";
	cout<<"\n Enter your choice: ";
	cin>>choice;

	switch(choice)
	{
		case 1:	modify();
			break;
		case 2:	delete_rec();
			break;
		default: cout<<"\n Wrong Choice.";
			 break;
	}
	cout<<"\n Press any key to continue.";
	getchar();
	getchar();
}
int ALLOCATION::check(int r){
	int flag=0;
	ifstream fin("Record.DAT",ios::in|ios::binary);
	while(fin.read((char*)this,sizeof(ALLOCATION)))
	{
		if(room_no==r)
		{
			flag=1;
			break;
		}
		else
		{
		  if(r>100)
		  {
			flag=2;
			break;
		  }
		}
	}
	fin.close();
	return(flag);
}
void ALLOCATION::modify(){

	int ch,r;
	cout<<"\n MODIFY MENU";
	cout<<"\n -----------";
	cout<<"\n\n\n 1. Modify Name";
	cout<<"\n 2. Modify Address";
	cout<<"\n 3. Modify Phone Number";
	cout<<"\n 4. Modify Time";
	cout<<"\n Enter Your Choice: ";
	cin>>ch;
	
	cout<<"\n Enter Room Number: ";
	cin>>r;
	switch(ch)
	{
		case 1: modify_name(r);
			break;
		case 2: modify_address(r);
			break;
		case 3: modify_phone(r);
			break;
		case 4: modify_time(r);
			break;
		default: cout<<"\n Wrong Choice";
				 getchar();
				 getchar();
			 break;
	}
}
void ALLOCATION::modify_name(int r){
	long pos,flag=0;
	fstream file("Record.DAT",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(ALLOCATION));
		if(room_no==r)
		{
			cout<<"\n Enter New Host Name: ";
			cin>>name;
			file.seekg(pos);
			file.write((char*)this,sizeof(ALLOCATION));
			cout<<"\n Host Name has been modified.";
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is vacant.";
	getchar();
	getchar();
	file.close();
}
void ALLOCATION::modify_address(int r){
	long pos,flag=0;
	fstream file("Record.DAT",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(ALLOCATION));
		if(room_no==r)
		{
			cout<<"\n Enter New Host Address: ";
			cin>>address;
			file.seekg(pos);
			file.write((char*)this,sizeof(ALLOCATION));
			cout<<"\n Host Address has been modified.";
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is vacant.";
	getchar();
	getchar();
	file.close();
}
void ALLOCATION::modify_phone(int r){
	long pos,flag=0;
	fstream file("Record.DAT",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(ALLOCATION));
		if(room_no==r)
		{
			cout<<"\n Enter New Phone Number: ";
			cin>>phone;
			file.seekg(pos);
			file.write((char*)this,sizeof(ALLOCATION));
			cout<<"\n Host Phone Number has been modified.";
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is vacant.";
	getchar();
	getchar();
	file.close();
}
void ALLOCATION::modify_time(int r){
	long pos,flag=0;
	fstream file("Record.DAT",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(ALLOCATION));
		if(room_no==r)
		{
		   cout<<" Enter the Time of start(in 24 hours format): ";
		   cin>>t1;
	       cout<<" Enter the Time of end(in 24 hours format): ";
	       cin>>t2;
	       {
		   if(t2>t1)
		   {
		   time=t2-t1;
	       }
	       else
		   {
		   	cout<<"time scheduling is wrong";
		   }
	       }
			if(room_no>=1&&room_no<=5)
			{
				strcpy(rtype,"10 Persons");
				cost=time*1000;
			}
			else
			{
				if(room_no>=6&&room_no<=10)
				{
				   strcpy(rtype,"20 Persons");
				   cost=time*1250;
				}
				else
				{
					if(room_no>=11&&room_no<=20)
					{
					   strcpy(rtype,"30 Persons");
					   cost=time*1500;
					}
				}
			}
			file.seekg(pos);
			file.write((char*)this,sizeof(ALLOCATION));
			cout<<"\n Time Changing information is modified.";
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\n Sorry, Room is Vacant.";
	getchar();
	getchar();
	file.close();
}
void ALLOCATION::delete_rec(){
	int r,flag=0;
	char ch;
	cout<<"\n Enter Room Number: ";
	cin>>r;
	ifstream fin("Record.DAT",ios::in|ios::binary);
	ofstream fout("temp.DAT",ios::out|ios::binary);
	while(fin.read((char*)this,sizeof(ALLOCATION)))
	{
		if(room_no==r)
		{
			cout<<"\n Host Name: "<<name;
			cout<<"\n Host Address: "<<address;
			cout<<"\n Host Phone Number: "<<phone;
			cout<<"\n Room Type: "<<rtype;
			cout<<"\n Your total bill is: Rs. "<<cost;
			cout<<"\n\n Do you want to check out this customer(y/n): ";
			cin>>ch;
			if(ch=='n')
			   fout.write((char*)this,sizeof(ALLOCATION));
			else
			   cout<<"\n Customer Checked Out.";
			flag=1;
		}
		else
			fout.write((char*)this,sizeof(ALLOCATION));
	}
	fin.close();
	fout.close();
	if(flag==0)
		cout<<"\n Sorry, Room is Vacant.";
	else
	{
		remove("Record.dat");
		rename("temp.dat","Record.dat");
	}
	getchar();
	getchar();
}
