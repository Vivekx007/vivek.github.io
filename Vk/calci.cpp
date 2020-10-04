#include<iostream>
using namespace std;
int main(){
	int sum=0;
	int choice;
	cout<<" Enter your choice ";
	cin>>choice;
	while(choice!=0){
	switch(choice)
	{
		case 1 :
			cout<<"Charged For Not Wearing Helmet "<<"\t"<<"Rs.1,000"<<endl;
			 sum+=1000;
			break;
		case 2 :
			cout<<"Charged For Overspeeding "<<"\t"<<"Rs.5,000"<<endl;                                                              
			 sum+=5000;
			break;
		case 3 :
			cout<<"Charged For Overloading of Passenger "<<"\t"<<"Rs.1,000"<<endl;
			 sum+=1000;
			break;
		case 4 :
			cout<<"Charged For Drink and Drive "<<"\t"<<"Rs.10,000"<<endl;
			 sum+=10000;
			break;
		case 5 :
			cout<<"Charged For Not Carrying License "<<"\t"<<"Rs.5,000"<<endl;
			 sum+=5000;
			break;
		case 6 :
			cout<<"Charged For Driving Without Insurance"<<"\t"<<"Rs.2,000"<<endl;
			 sum+=2000;
			break;
		case 7 :
			cout<<"Charged For Not Wearing Seatbelt "<<"\t"<<"Rs.1,000"<<endl;
			 sum+=1000;
			break;
		case 8 :
			cout<<"Charged For General Offence "<<"\t"<<"Rs.500"<<endl;
			 sum+=500;
			break;
		case 9 :
			cout<<"Charged For Disobeying orders from the Authorities and Refusing to Share Information "<<"\t"<<"Rs.20,00"<<endl;
			 sum+=2000;
			break;
		case 10 :
			cout<<"Charged Accident Related Offences "<<"\t"<<"Rs.5,000"<<endl;
			 sum+=5000;
		     break;	
		case 11 :
			cout<<"Charged For Vehicle Without Permit "<<"\t"<<"Rs.10,000"<<endl;
			 sum+=10000;
			 break;
		case 12 :
			cout<<"Charged For Not Providing Way for Emergency Vehicles "<<"\t"<<"Rs.10,000"<<endl;
			 sum+=10000;
			 break;
		case 13 :
			cout<<"Charged For Offences by Juveniles "<<"\t"<<"Rs.25,000"<<endl;
			 sum+=25000;
			 break;
		case 14 :
			cout<<"Charged For Rash Driving "<<"\t"<<"Rs.5,000"<<endl;
			 sum+=5000;
			 break;
		case 15 :
			cout<<"Charged For Not Carrying R.C. "<<"\t"<<"Rs.5,000"<<endl;
			 sum+=5000;
			 break;
		case 16 :
			cout<<"Charged For Driving Unauthorised Vechicles  "<<"\t"<<"Rs.5,000"<<endl;
			 sum+=5000;
			 break;
		case 17 :
			cout<<"Charged For Disqualified License  "<<"\t"<<"Rs.10,000"<<endl;
			 sum+=10000;
			 break;
		case 18 :
			cout<<"Charged For Not having Valid Vechicle Fitness Certficate "<<"\t"<<"Rs.5,000"<<endl;
			 sum+=5000;
			 break;
		case 19 :
			cout<<"Charged For Not Following Traffic Regulations "<<"\t"<<"Rs.500"<<endl;
			 sum+=500;
			 break;
		case 20 :
			cout<<"Charged For Illegal Racing "<<"\t"<<"Rs.5,000"<<endl;
			 sum+=5000;
			 break;	   	  	  	  	  	  	  			 	
		case 0 :
			system("cls"); 
			return 0;
			break;
		default :
			cout<<"No Such Offences , Please Try Again "<<endl;
			break;				
	}
	cin>>choice ;
	}
	cout<<"\t"<<"Fine Charged in Total = "<<sum;}
	
	
	


