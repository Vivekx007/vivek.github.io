#include<windows.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<conio.h>
#include<ctime>
#include<vector>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;


	
	

COORD coord = {0, 0};

void gotoxy (int x, int y)	//defining/initializing to predefined objects
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
       
}



class application{
	private:
		
		string c_no,o_date,o_time,l_no,v_no,m_no,p_state,t_fine,offence, ps;
		string o1,o2,o3,o4,o5,o6,o7,o8;	
		int k,sum;
		string st, ss;
		char oz, xx,oa;
        vector<string>pnish;
		
		
		public:
			void first();
			void citizen();
			void frame();
			void frame_fix();
			void wel();
			void login();
			void load();
			void details();
			void main_menu();
			void calculator();
			void form();
			void note();
			int random();
			string date();
			string times();
			void time_date();
};


// Display time...
void application::time_date(){
	time_t tt; 
    time (&tt);
    struct tm *ti = localtime(&tt); 
 
  
    cout <<"" <<asctime(ti)<<endl; 
}
int application::random()
{
	srand((unsigned) time(0));
	int rN;
	rN = (rand() % 99999)+10000;
	return rN;

}

string application::date ()
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,sizeof(buffer),"%H:%M:%S",timeinfo);
  string str(buffer);

  return str;
}

// Display two straight line in upper and lower side...
void application::frame()
{
	int i,j;
	for(i = 0,j=79;i<80,j>=0;i++,j--)
	{
		gotoxy(i,3);
		Sleep(10);
		cout<<"_";
		gotoxy(j,20);
		Sleep(10);
		cout<<"_";
	}
	gotoxy(54,2);
	time_date();
			//every frame has date on the right top 
	
}

string application::times ()
{
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time (&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer,sizeof(buffer),"%d-%m-%Y",timeinfo);
  string str(buffer);

  return str;
}

void application::first(){
	system("cls");
	frame();
	gotoxy(30, 11); cout<<"1 : Login as Admin.";
	gotoxy(30, 13); cout<<"2 : Login as Citizen.";
    char op;
    op = getch();

	if(op=='1'){
		system("cls");
		login();
	}
	else if(op=='2'){
		citizen();
	}

}

void application::citizen(){
	
	system("cls");
	frame_fix();
	string exist;
   	string ext=".txt";
   	gotoxy(30, 11);
   	cout<<"Enter Challan Number :-   ";
   	gotoxy(30, 12);
   	cin>>exist;
   	system("cls");
   
   	string exname=exist+ext;
   	ifstream exfile;
   	exfile.open(exname.c_str());
	   
	   if(exfile) {
	      while(!exfile.eof()){
	         string str;
	         
		        getline(exfile, str);
		        cout << str << endl;
	   	}
	   	gotoxy(2, 24);
	   	cout<<"B : Back";
	   	gotoxy(20, 24);
	   	cout<<"E : Exit";
		   char on;
		   on = getch(); 
		   
		   if(on=='B' || on=='b'){
		   	first();
		   }
		   else if(on=='E' || on=='e'){
		   	note();
		   }
	}
	else {
		frame_fix();
		gotoxy(30, 11);
	    cout<<"file doesn't exist";
	    gotoxy(2, 21);
	    cout<<"R : Retry";
	    gotoxy(20, 21);
	    cout<<"B : Back";
	    
	    char op = getch();
	    
	    if(op=='R' || op=='r'){
	    	citizen();
		}
		else if(op=='B' || op=='b'){
			first();
		}
		else{
			cout<<"Invalid Input";
		}
	}	
}


//  frame_fix starting....
void application::frame_fix(){
	int i,j=79;
	for(i = 0;i<80,j>=0;i++,j--)
	{
		gotoxy(i,3);
		cout<<"_";
		gotoxy(j,20);
		cout<<"_";
	}
	gotoxy(54,2);
	time_date();
}

// Welcome screen....
void application::wel(){										// welcome page....
	gotoxy(33,10);
	load();
	system("color F4");
	
	for(int i=0; i<30; i++){
		gotoxy(i,11);
		cout<<" ";
		cout<<"CHALLAN APP";
		Sleep(40);
	}
	
	
	for(int j=78;j>=0;j--)
	{
		gotoxy(j,20);cout<<"!";
		gotoxy(j,4);cout<<"!";
		Sleep(30);
	}
	
	gotoxy(42,22);cout<<"Designed By: ";
	gotoxy(56,23);cout<<"Vivek Kumar";
	gotoxy(56,24);cout<<"Sayad Sarfraz Ali";
	gotoxy(56,25);cout<<"Sameer Sheikh";
	gotoxy(56,26);cout<<"Tushar Yadav";
	Sleep(3000);
	
	first();
}

	
	
//id password starting....
	void application::login(){   								// login ....
	
	system("cls");
	frame();
	gotoxy(30,10);
	int i=0;
    
    char parr[8], ch;
  
     cout<<"Enter Admin. password"<<endl;
     gotoxy(30,11);
     for (i=0;i<8;i++)
     { 
	     ch=getch();
         parr[i]=ch;
         ch='*';
         cout<<ch;
     }

 string p;

 
 for(int i=0;i<8;i++){
 	p+=parr[i];
 }
 cout<<endl;

 if (p=="vkssssty")
 {
    //system("cls");
    gotoxy(30,11);
    cout<<"Welcome!";
    system("cls");
    gotoxy(30,11);
    load();
    main_menu();
    
 }

 else
 {
  
    gotoxy(30,11);
    cout<<"Wrong password";
    Sleep(1000);
    system("cls");
    
    login();
 } 
 
}


// Loading..... Screen
void application::load(){                               
	cout<<"Loading";
	Sleep(400);
	cout<<".";
	Sleep(400);
	cout<<".";
	Sleep(400);
	cout<<".";
	Sleep(400);
	system("cls");

}


// main menu....
void application::main_menu(){                         //    main menu.....
	system("cls");
	system("color 1F");
	frame();
	
	string s = "\n\tMain Menu:";
	for(int i=0; i<12; i++){
		cout<<s[i];
		Sleep(100);
	}
	
	gotoxy(5, 2);
	cout<<"Admin";
	gotoxy(8, 8);
	cout<<"1 : Challan Offence details ";
	gotoxy(8, 10);
	cout<<"2 : Challan calculator ";
	gotoxy(8, 12);
	cout<<"3 : Challan Voilation form ";
	gotoxy(1, 21);
	cout<<"H : Help ";
	gotoxy(1, 22);
	cout<<"E : Exit ";
	
	char op;
	op = getch();
	
	if(op=='1'){
		details();
	}
	else if(op=='2'){
		calculator();
	}
	else if(op=='3'){
		form();
	}
	else if(op=='H' || op=='h'){
		//help_1();
	}
	else if(op=='E' || op=='e'){
		system("cls");
		note();
	}
}


// calculator....
void application::calculator(){                            // Calculator
	
	system("cls");
	for(int i=0; i<79; i++){
		gotoxy(i, 3);
		cout<<"`";
	}
	gotoxy(54, 2);
	time_date();
		
			char of;
			
		string s = "\t\t\t\tChoose Voilations:-";
		
		for(int i=0; i<23; i++){
			cout<<s[i];
			Sleep(100);
		}
			
		gotoxy(1,6);
		cout<<"1 : Not wear helmet";
		gotoxy(1,8);
		cout<<"2 : Overspeeding \\ Rash Driving";
		gotoxy(1,10);
		cout<<"3 : Overloading of Passenger";
		gotoxy(1, 12);
		cout<<"4 : Drink n Drive";
		gotoxy(1,14);
		cout<<"5 : Without Licence";
		gotoxy(1, 16);
		cout<<"6 : Driving Without Insurance";
		gotoxy(1, 18);
		cout<<"7 : Not Wearing Seatbelt";
		gotoxy(1, 20);
		cout<<"8 : General Offence";
		gotoxy(1, 23);
		cout<<"0 : Confirm";
			
				of = getch();
				
				 sum=0;
				while(of!=0)
				{
					
				
						if(of=='1'){
						
								o1="Charged For Not Wearing Helmet ";
								pnish.push_back(o1);
								cout<<"\n\nCharged For Not Wearing Helmet "<<"\t"<<"Rs.1,000"<<endl;
							 	sum+=1000;
							 	
						}
						else if(of=='2'){
						
								o2="Charged For Overspeeding \\ Rash Driving ";
								pnish.push_back(o2);
								cout<<"Charged For Overspeeding \\ Rash Driving "<<"\t"<<"Rs.5,000"<<endl;
								sum+=5000;
								
						}
						else if(of=='3'){
						
								o3="Charged For Overloading of Passenger ";
								pnish.push_back(o3);
								cout<<"Charged For Overloading of Passenger "<<"\t"<<"Rs.1,000"<<endl;
								sum+=1000;
						}
						else if(of=='4'){
	
								o4="Charged For Drink and Drive ";
								pnish.push_back(o4);
								cout<<"Charged For Drink and Drive "<<"\t"<<"Rs.10,000"<<endl;
								sum+=10000;
						
						}
						else if(of=='5'){
						
								o5="Charged For Not Carrying License \\ R.C. ";
								pnish.push_back(o5);
								cout<<"Charged For Not Carrying License \\ R.C. "<<"\t"<<"Rs.5,000"<<endl;
								sum+=5000;
		
						}
						else if(of=='6'){
						
								o6="Charged For Driving Without Insurance";
								pnish.push_back(o6);
								cout<<"Charged For Driving Without Insurance"<<"\t"<<"Rs.2,000"<<endl;
							 	sum+=2000;
					
						}
						else if(of=='7'){
						
								o7="Charged For Not Wearing Seatbelt ";
								pnish.push_back(o7);
								cout<<"Charged For Not Wearing Seatbelt "<<"\t"<<"Rs.1,000"<<endl;
								sum+=1000;
						
						}
						else if(of=='8'){
					
								o8="Charged For General Offence ";
								pnish.push_back(o8);
								cout<<"Charged For General Offence "<<"\t"<<"Rs.500"<<endl;
							 	sum+=500;
						
						}
						else if(of=='0') {
						
								system("cls");
								gotoxy(30, 11);cout<<"Y : Yes to Confirm";
								gotoxy(30, 12);cout<<"N : No to Repeat";
								break; 
								
						}
						else{
						
								cout<<"No Such Offences , Please Try Again "<<endl;
						}
						of = getch();
					
					}
					
				 oz = getch();
				 
				 if(oz=='N' || oz=='n'){
				 	calculator();
				 }
				 else if(oz=='Y' || oz=='y'){
				 	system("cls");
				 	frame_fix();
				 	cout<<"\n\nOffences Charged"<<endl;
				 	
				 	for(int i=0; i<pnish.size(); i++){
				 		cout<<pnish[i]<<endl;
					 }

					cout<<endl;
					cout<<"Totle Fine = "<<sum;
					
					gotoxy(2, 21);cout<<"M : Main Menu";
					gotoxy(20, 21);cout<<"C : Challan Form";
					char ox;
					ox = getch();
					
					if(ox=='M' || ox=='m'){
						main_menu();
					}
					else if(ox=='C' || ox=='c'){
						form();
					}
					
				 }
				

		
}


// Voilation_type starting.....
void application::details(){                            //details...
	system("cls");
	
	//application r;
//	login();

		for(int i=0;i<79;i++)
	{
		gotoxy(i,3);
		cout<<"_";
	}
	gotoxy(54,2);
	time_date();
	system("color 1F");
		

	 k = random();
     st = date();
	 ss = times();
	gotoxy(10,4);cout<<"Challan No :     ";
	cout<<"TTPCC2020"<<k;                   
	                                          
	gotoxy(10,6);cout<<"Offense Date :   ";
	cout<<st;                                         
	                                          
	gotoxy(10,8);cout<<"Offense Time :   ";
	cout<<ss;                                         
                                          	
	gotoxy(10,10);cout<<"License No :     ";
	cin>>l_no;                                          
                                          	
	gotoxy(10,12);cout<<"Vehicle No :     ";
	cin>>v_no;                                         
                                          	
	gotoxy(10,14);cout<<"Mobile No :      ";
	cin>>m_no;                     
	
	gotoxy(30, 17);cout<<"Confirmation";
	gotoxy(25, 19);cout<<"Y : yes";
	gotoxy(40,19);cout<<"N : No";
	
	char o;
	o = getch();
	if(o=='Y' || o=='y'){
		
		system("cls");
		gotoxy(30,11);
		cout<<"Saving ";
		Sleep(400);
		cout<<".";
		Sleep(400);
		cout<<".";
		Sleep(400);
		cout<<".";
		Sleep(400);
		system("cls");
		frame_fix();
		
		gotoxy(30, 9);
		cout<<"S : show Offender Details";
		gotoxy(30,11);
		cout<<"C : Calculator";
		gotoxy(30,13);
		cout<<"M : Main Menu";
		
	//	char oa;
		oa = getch();
		
		if(oa=='S' || oa=='s'){
			system("cls");
			frame_fix();
			gotoxy(10,4);cout<<"Challan No :     ";
			cout<<"TTPCC2020"<<k;                   
	                                          
			gotoxy(10,6);cout<<"Offense Date :   ";
			cout<<st;                                         
	                                          
			gotoxy(10,8);cout<<"Offense Time :   ";
			cout<<ss; 
			
			gotoxy(10,10);cout<<"License No :     ";
			cout<<l_no;                                          
                                          	
			gotoxy(10,12);cout<<"Vehicle No :     ";
			cout<<v_no;                                         
                                          	
			gotoxy(10,14);cout<<"Mobile No :      ";
			cout<<m_no; 
			
		
		gotoxy(1, 21);
		cout<<"C : Calculator";
		gotoxy(22 ,21);
		cout<<"M : Main Menu";
		
		xx = getch();
		
		if(xx=='C' || xx=='c'){
			calculator();
		}
		else if(xx=='M' || xx=='m'){
			main_menu();
		}
		
		}
		
		
		else if(oa=='C' || oa=='c'){
			calculator();
		}
		else if(oa=='M' || oa=='m'){
			main_menu();
		}
	}
	
	else if(o=='N' || o=='n'){
		details();
	}
}

void application::form(){                    					// form....
	system("cls");
	system("color 87");
	
	if((oz=='Y' || oz=='y') && ((oa=='C' || oa=='c') || (xx=='C' || xx=='c'))){
		cout<<" ___________________________________________________________________" <<endl;
		cout<<"|                          CHALLAN DETAILS                          |"<<endl;
		cout<<"|___________________________________________________________________|"<<endl;
		cout<<"|  CHALLAN NO.      |"   <<"TTPCC2020"<<k<<"                        |"<<endl;                      
		cout<<"|___________________|_______________________________________________|"<<endl;
		cout<<"|  OFFENSE DATE     |"   <<st<<"                                    |"<<endl;
		cout<<"|___________________|_______________________________________________|"<< endl;
		cout<<"|  OFFENSE TIME     |"   <<ss<<"                                    |"<<endl;
		cout<<"|___________________|_______________________________________________|"<< endl;
		cout<<"|  LICENSE NO.      |"   <<l_no<<"                                  |"<<endl;
		cout<<"|___________________|_______________________________________________|"<< endl;
		cout<<"|  VEHICLE NO.      |"   <<v_no<<"                                  |"<<endl;
		cout<<"|___________________|_______________________________________________|"<< endl;
		cout<<"|  MOBILE NO.       |"   <<m_no<<"         						   |"<<endl;
		cout<<"|___________________|_______________________________________________|"<< endl;
		cout<<"|  OFFENCES NO.     |"   <<pnish[0]<<"                              |"<<endl;
		cout<<"|                   |"   <<pnish[1]<<"                              |"<<endl;
		cout<<"|                   |"   <<pnish[2]<<"                              |"<< endl;
		cout<<"|___________________|_______________________________________________|"<< endl;
		cout<<"|  TOTAL FINE       |"   <<"Rs."<<sum<<"							   |"<< endl;
		cout<<"|___________________|_______________________________________________|"<< endl;
		
		
		
		ofstream ifile;
		string fname="TTPCC2020";
		int n=k;
		string string2 = ".txt";
		string s;
	
	while(n){
		int i=(n%10);
		s+=(char)(i+48);
		n/=10;
	}
    reverse(s.begin(),s.end());
    
    string fn= fname+s+string2;
    ifile.open(fn.c_str(), ios::app);
		
		ifile<<" ___________________________________________________________________" <<endl;
		ifile<<"|                          CHALLAN DETAILS                          |"<<endl;
		ifile<<"|___________________________________________________________________|"<<endl;
		ifile<<"|  CHALLAN NO.      |"   <<"TTPCC2020"<<k<<"                        |"<<endl;                      
		ifile<<"|___________________|_______________________________________________|"<<endl;
		ifile<<"|  OFFENSE DATE     |"   <<st<<"                                    |"<<endl;
		ifile<<"|___________________|_______________________________________________|"<< endl;
		ifile<<"|  OFFENSE TIME     |"   <<ss<<"                                    |"<<endl;
		ifile<<"|___________________|_______________________________________________|"<< endl;
		ifile<<"|  LICENSE NO.      |"   <<l_no<<"                                  |"<<endl;
		ifile<<"|___________________|_______________________________________________|"<< endl;
		ifile<<"|  VEHICLE NO.      |"   <<v_no<<"                                  |"<<endl;
		ifile<<"|___________________|_______________________________________________|"<< endl;
		ifile<<"|  MOBILE NO.       |"   <<m_no<<"         						    |"<<endl;
		ifile<<"|___________________|_______________________________________________|"<< endl;
		ifile<<"|  OFFENCES NO.     |"   <<pnish[0]<<"                              |"<<endl;
		ifile<<"|                   |"   <<pnish[1]<<"                              |"<<endl;
		ifile<<"|                   |"   <<pnish[2]<<"                              |"<< endl;
		ifile<<"|___________________|_______________________________________________|"<< endl;
		ifile<<"|  TOTAL FINE       |"   <<"Rs."<<sum<<"							|"<< endl;
		ifile<<"|___________________|_______________________________________________|"<< endl;
		
	gotoxy(3, 24);
	cout<<"M : Main Menu";	
	gotoxy(35, 24);
	cout<<"S : Save";
	char c;
	c = getch();
	
	if(c=='M' || c=='m'){
		main_menu();
	}
	else if(c=='S' || c=='s'){
		
		system("cls");
		gotoxy(10, 26);
		
		system("color B0");
		frame_fix();
		cout<<"Saving";
		Sleep(400);
		cout<<".";
		Sleep(400);
		cout<<".";
		Sleep(400);
		cout<<".";
		Sleep(400);
		system("cls");
		frame_fix();
		gotoxy(22,5);
		cout<<"Offence form Successfully saved";
		gotoxy(2, 23);
		cout<<"L : Logout";
		gotoxy(18, 23);
		cout<<"M : Main Menu";
		gotoxy(2, 24);
		cout<<"E : Exit";
		char op;
		op=getch();
		
		if(op=='L' || op=='l'){
			first();
		}
		else if(op=='M' || op=='m'){
			main_menu();
		}	
		else if(op=='E' || op=='e'){
			note();
		}
		else{
			cout<<"Invalid Input";
		}
}
	else{
		cout<<"Invalid Input";
	}
	

	}
		else{
			frame_fix();
			gotoxy(30, 11);
			cout<<"File doesn't exist";
			gotoxy(28, 23);
			cout<<"Main Menu : Press Any Key";
			char o;
			o = getch();
			main_menu();
	}
	
	}
	

// note page...
void application::note(){                              // Exit page
	system("cls");
	frame_fix();
	system("color F4");	
	gotoxy(10,5);cout<<"HELLO RESPECTED TEACHERS AND LOVELY FREINDS GOOD TO SEE HERE ";
	gotoxy(10,9);cout<<"THIS IS GROUP PROJECT DONE FOR 2ND YEAR 3rd SEM SUBMISSION.";
	gotoxy(10,10);cout<<"I HOPE IT IS SIMPLE AND EASY TO UNDERSTAND.";
	gotoxy(10,11);cout<<"THE PROJECT HAVE BEEN CODED  IN C&C++.";
	gotoxy(10,12);cout<<"AND AFTER THIS I WILL THINKING OUR NEXT INNOVATIVE PROJECT.";
	
	
	gotoxy(10,15);cout<<"STAY SAFE & STAY INNOVATIVE.";
    gotoxy(10,16);cout<<"THANKS. ";
	
	
	getch();
	exit(0);
}

int main(){
	application a;
	a.wel();
}
