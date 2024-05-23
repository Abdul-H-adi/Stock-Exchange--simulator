//							Abdul Hadi
//							i22-1646
//							BS(CY)-D

#include <iostream>
#include <ctime>
#include<fstream>

#include<string>

#include<iomanip>
using namespace std;
//main output function
int redrawMarket(char [][50], char [][50], float [38],float[38], float min[38]);

int main()
{
//storages
char sig[38][50];
char name[38][50];
char arr[80];
float price[238];
float high[38];
float min[38];
fstream file;
int i =0;
int count = 0;
int ans = 1;

						//initializing array for high[] on redrawmarket function
						for(int i = 0; i<38 ; i++)
						{
						high[i] = 0;
						}
						
//reading companies.txt						
file.open("companies.txt",ios::in);

	while(!file.eof())
	{
		if (count == 0)
		{
		file.getline(arr,80,'\n');
		}
	
	file.getline(sig[count],50,',');
	
	file.getline(name[count],50,',');
	
	file>>price[count];
	
	count++;
	
	}					//intializing min[] with given price[] for min[] to work on redrawmarket()
						for(int i = 0; i<38 ; i++)
						{
						min[i] = price[i];
/*input*/					}	
char ch;
//seed
srand(time(0));
		//function call
		while(ans == 1)
		{

		ans =redrawMarket(sig,name,price,high,min);
		system("clear");
		 }
		
		
file.close();
	



}


int redrawMarket(char sig[38][50], char name[38][50], float price[38], float high[38] , float min[38])
{
//upper output of live stock market
cout<<right;
cout<<"\033[100;30m"<<setw(85)<<"Karachi Stock Market Live"<<setw(60)<<"\033[0m"<<endl;
cout<<"\033[40;93m"<<"Show Updates:Enter"<<setw(25)<<"Show Portfolio:P"<<setw(23)<<"Add stock:A"<<setw(26)<<"Remove stock:R"<<setw(30)<<"Add money to account: M"<<setw(19)<<"Exit:E"<<"\033[0m"<<endl;
cout<<"\033[100;30m"<<"Stocks"<<setw(25)<<"Company Name"<<setw(50)<<"Previous Price"<<setw(25)<<"Current Price"<<setw(15)<<"High"<<setw(17)<<"LOW"<<setw(7)<<"\033[0m"<<endl;
//storage
float arr2[38];
float temp = 0;
float percenter = 0;
int decide = 0;
float storee;


	
	//array for previous values
	for(int i = 0; i<38; i++)
	{
	temp = price[i];
	arr2[i] = temp;
	}
	float store[38];
		//array for rand maipulation in array
		for(int i = 0; i<38; i++)
		{
		percenter = (rand()%16)+1;
		store [i] = percenter;
		decide = rand()%2;
		temp = price[i];
		storee = (temp/100)*percenter;
			if(decide == 0)
			{
			temp -= storee;
			price[i]=temp;
			}
			if(decide == 1)
			{
			temp += storee;
			price[i] = temp;
			}
		}
	
	bool pass;
	//array for highest value in session
	for(int i = 0; i<38 ; i++)
	{
		if(price[i]>high[i])
		{
		high[i] = price[i];
		
		}
	}
	//array for lowest value in session
	for(int i = 0; i<38 ; i++)
	{
		if(price[i]<min[i])
		{
		min[i] = price[i];
		
		}
	}
	//percent advancer
	int x = 0;
	float maxi = 0;
	for(int i = 0; i<38 ; i++)
	{
		for(int j = 1; j<38 ; j++)
		{
			if ((store[i]>store[j]) && (store[i]>maxi))
			{
			maxi = store[i];
			x = i;
			}
		}
	}
	//percent decliner
	int check4 = 0;
	int y = 0;
	float mini = 0;
	for(int i = 0; i<38 ; i++)
	{
		for(int j = 1; j<38 ; j++)
		{
		if (check4 == 0)
			if ((store[i]<store[j]))
			{
			mini = store[i];
			y = i;
			check4++;
			}
		if((store[i]<store[j])&&(store[i]<mini))
		{
		mini = store[i];
		y = i;
		}
		}
	}

			
		 
	
	
	
	
float shares;	
string signature;
char ch;
	//output of the lower part
	for(int i=0;i<38;i++)
	{

	cout<<left<<fixed<<setprecision(2);

	cout<<setw(18)<<sig[i]<<setw(50)<<name[i]<<setw(22)<<arr2[i]<<setw(12);
	if(arr2[i]<price[i])
	{
	cout<<"\033[1;92m"<<"\u2191"<<setw(22)<<price[i]<<"\033[0m"<<setw(16);
	}
	if(arr2[i] > price[i]) 
	{
	cout<<"\033[1;91m"<<"\u2193"<<setw(22)<<price[i]<<"\033[0m"<<setw(16);
	}
	cout<<high[i]<<min[i];
	
	}
	cout<<endl;
	cout<<"advancer % : "<<sig[x];
	cout<<endl;
	cout<<"Decliner & :"<<sig[y];
	cout<<endl<<endl;
	
	
	cin>>ch;
	
	
	
	//incase porfilio is required
	string owner;
	if((ch == 'p') || (ch == 'P'))
	{
	cout<<"Please Enter Your name"<<endl;
			cin.ignore();
			getline(cin,owner);
			
			cout<<right;
			
	int a = 0;		
	bool signal = 0;
		//printing portfolio	
		while((ch != 'l') && (ch != 'L'))
		{	

		cout<<right;
		cout<<"\033[100;30m"<<setw(70)<<"Profile Owner: "<<owner<<setw(68)<<"\033[0m"<<endl;
			cout<<"\033[40;93m"<<"Show Updates:Enter"<<setw(25)<<"Live Market: L"<<setw(23)<<"Add stock:A"<<setw(26)<<"Remove stock:R"<<setw(30)<<"Add money to account: M"<<setw(19)<<"Withdraw Money"<<"\033[0m"<<endl;
			cout<<"\033[100;30m"<<"Stocks"<<setw(25)<<"Company Name"<<setw(25)<<"shares"<<setw(25)<<"Previous"<<setw(25)<<"Gain/Loss"<<setw(15)<<"High"<<setw(17)<<"LOW"<<setw(7)<<"\033[0m"<<endl;
			if((ch=='a') || (ch =='A'))
			{
			int check = 0;
			
			cout<<"Enter Signature NO: ";
			cin>>a;
			cout<<"Enter Shares"<<endl;
			cin>>shares;
			
			}
			char out[10][50];
char out2[10][50];
char out3[10][50];
//portfolio reading in file as well as writinh
fstream object;
object.open("portfolio.txt",ios::out);
object<<sig[a];
object<<",";
object<<name[a];
object<<",";
object<<shares;
object.close();
int i = 0;
fstream Port;
Port.open("portfolio.txt",ios::in);
while(!(Port.eof()))
{
Port.getline(out[i],50,',');
Port.getline(out2[i],50,',');
Port.getline(out3[i],50,'\n');

i++;
}
int j =i;

i = 0;//output-portfolio
cout<<left;
cout<<setw(18)<<out[i]<<setw(34)<<out2[i]<<setw(22)<<out3[i]<<setw(23)<<arr2[i]<<setw(17)<<price[i]<<setw(20)<<high[i]<<min[i];
			cin>>ch;
			
			system("clear");
			}
	}
	
	
	
	
	if((ch == 'e') || (ch == 'E'))
	return 0;
	else return 1;
}











