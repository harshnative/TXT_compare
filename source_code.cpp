#include<iostream>
#include<fstream>
#include<string> 
#include<algorithm> 
#include<windows.h>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>
#include<unistd.h>
#include<conio.h>

using namespace std;

int stringCompare_NotCaseSentitive(string str1 , string str2)
//returns 0 for match and 1 for non match
{
	string temp0 , temp1;
		temp0 = str1;
		temp1 = str2;
		
		//transforming the strings to same case - here to upper 
	transform(temp0.begin(), temp0.end(), temp0.begin(), ::toupper); 			//#include<algorithm.h>
	transform(temp1.begin(), temp1.end(), temp1.begin(), ::toupper);			
	
		if((temp0.compare(temp1)) == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
}






int stringCompare(string str1 , string str2)
//returns 0 for match and 1 for non match
{
	string temp0 , temp1;
		temp0 = str1;
		temp1 = str2;
	if((temp0.compare(temp1)) == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
}





int main()
{
	long int input0=0;
	system("cls");
	string STRING1[100000];
	string STRING0[100000];
	string filename0 , filename1;
	long int i=0;
	long int j=0;
	long int compareValue = 10;
		
		
		
	returnx : ; 			//goto statement 
	
	cout<<"FILES ABOVE 100,000 lines are currently not comptable :(\n\n";
	cout<<"1 for simple [ Procedure if you don't know the path directory ] "<<endl;
	cout<<"2 for adv [ Procedure if you know the path directory ] \n"<<endl;
	cout<<"ENTER THE MODE TO WORK : ";
	cin>>input0;
	
	system("cls");
	cout<<"FILES ABOVE 100,000 lines are currently not comptable :(\n\n";
	cout<<"0 for comparing without considering the letter casing - a and A will be same\n\n";
	cout<<"1 for comparing with considering the letter casing - a and A will be diff\n\n";
	cout<<"Enter your choice : ";
	cin>>compareValue;	
	if(compareValue<0 || compareValue>1)
	{
		system("cls");
		cout<<"Wrong input - program will now exit>>>>\n\n";
		system("pause");
		exit(1);
	}

	
	//reading file code for the file directory
	if(input0==2)
	{
		i=0;
		j=0;
	
		returnto012 : ;			//goto statement 
		cin.ignore();
		
  		system("cls");
  		cout<<"If your XYZ.txt file is present at Destop in user named john then your path should be\n\nC:\\Users\\john\\Desktop\\XYZ.txt";			//double "\\" as "\\" prints "\"
  		cout<<"\n\n\nEnter the full path with name [ refer the above EX ] of the file 1 - ";
		
		getline(cin , filename0);
  		
		ifstream infile0;
		infile0.open (filename0.c_str(), ios::in);
		system("cls");
			if ( ! infile0.is_open() ) 
			{              
      			cout<<"Their was some ERROR in opening the file - try next time :)\n\n"<< endl;
      			system("pause");
      			goto returnto012 ;	
      		
   			}
   			else 
			{
      			cout <<"FILE 1 was opened succesfully in the background\n\n" << endl;
      			system("pause");
   			}
		while(!infile0.eof()) 
        {
	        getline(infile0,STRING0[i]); 
	        i++;
        }
		infile0.close();
   			
   		returnto123 : ; 		//goto statement
   		j=0;
   		
   		system("cls");
  		cout<<"If your XYZ.txt file is present at Destop in user named john then your path should be\n\nC:\\Users\\john\\Desktop\\XYZ.txt";			//double "\\" as "\\" prints "\"
  		cout<<"\n\n\nEnter the full path with name [ refer the above EX ] of the file 2 - ";
		getline(cin, filename1);
		ifstream infile1;
		system("cls");
		infile1.open (filename1.c_str(), ios::in);
			if ( !infile1.is_open() ) 
			{              
      			cout<<"Their was some ERROR in opening the file - try next time :)\n\n"<< endl;
      			system("pause");
      			goto returnto123 ;
   			}
   			else 
			{
      			cout <<"FILE 2 was opened succesfully in the background\n\n" << endl;
      			system("pause");
   			}
   		while(!infile1.eof()) 
        {
	        getline(infile1,STRING1[j]); 
	        j++;
        }
		infile1.close();
		system("cls");
	}
	
	
	//code for the file without directory 
	else
	if(input0==1)
	{
		system("cls");
		cout<<"**********WARNING DONT SKIP THIS**********\n\n";
		cout<<"YOU have selected the simple mode\n\n";
		cout<<"Two Files have been created in the folder in which this program is stored - named TXT1.txt and TXT2.txt\n\n";
		cout<<"Go ahead and copy and paste the data of your two txt files into these respectively\n\n";
			
			ofstream infile2;
			infile2.open ("TXT1.txt", ios::out);
			infile2.close();
			
			ofstream infile3;
			infile3.open ("TXT2.txt", ios::out);
			infile3.close();
		
		sleep(3);				//time given to read the points and avoid accidental enter press 
		system("pause");
		i=0;
		j=0;
		
		ifstream infile4;
		infile4.open("TXT1.txt", ios::in);
			while(!infile4.eof()) 
        {
	        getline(infile4,STRING0[i]); 
	        i++;
        }
		infile4.close();
		
		ifstream infile5;
		infile5.open("TXT2.txt", ios::in);
			while(!infile5.eof()) 
        {
	        getline(infile5,STRING1[j]); 
	        j++;
        }
		infile5.close();
	}
	
	
	else
	{
		system("cls");
		cout<<"OOPS - WRONG INPUT ....\n\n";
		system("pause");
		goto returnx ;
	}
	
	
	
	
	
	//NOW starting actual comparing
	system("cls");
	ofstream infile6;
	infile6.open ("C:\\Users\\harsh\\Desktop\\RESULT detail.txt", ios::out);
	
	long long int larger = 0;
	if(i>=j)
	{
		larger = i;
	}
	else
	{
		larger = j;
	}
	
	
	//asking for whether to compare whole file or not 
	toCompare : ;	//goto statement 
	cout<<"Total lines to be compared = "<<larger<<endl<<endl;
	cout<<"Enter 0 below to compare the whole file\n\n";
	cout<<"Do you want to compare whole file or upto line no - ";
	int tempINPUT = 0;
	cin>>tempINPUT;
	if(tempINPUT > 0 && tempINPUT <= larger)
	{
		larger = tempINPUT;
	}
	else
	if(tempINPUT == 0)
	{
		cout<<"";
	}
	else
	{
		system("cls");
		cout<<"oops someTHING went wrong - \n\n";
		system("pause");
		goto toCompare;
	}
	
	
	long int result;
	long int perCount=0,finalCount=0;
	for(long int k=0;k<larger;k++)
	{
		if(compareValue==0)
		{
			system("cls");
			cout<<"on line - "<<k<<" out of "<<larger;
			result = stringCompare_NotCaseSentitive(STRING0[k] , STRING1[k]);
			if(result==0)
			{
				perCount++;
			}
			else
			if(result==1)
			{
				infile6<<"line - "<<k<<" fail "<<endl;
				infile6<<"String from txt 1 = "<<STRING0[k]<<endl;
				infile6<<"String from txt 2 = "<<STRING1[k]<<endl;
				infile6<<endl<<endl<<endl;
			}
			else
			{
				system("cls");
				cout<<"OOPS - their was error while comparing the file\n\n"<<endl;
				cout<<"Soory for this , but the program will now exit\n\n";
				system("pause");
				exit(1);
			}
		}
		else
		{
			result = stringCompare(STRING0[k] , STRING1[k]);
				if(result==0)
			{
				perCount++;
			}
			else
			if(result==1)
			{
				infile6<<"line - "<<k<<" fail "<<endl;
				infile6<<"String from txt 1 = "<<STRING0[k]<<endl;
				infile6<<"String from txt 2 = "<<STRING1[k]<<endl;
				infile6<<endl<<endl<<endl;
			}
			else
			{
				system("cls");
				cout<<"OOPS - their was error while comparing the file\n\n"<<endl;
				cout<<"Soory for this , but the program will now exit\n\n";
				system("pause");
				exit(1);
			}
		}
		finalCount = k;
	}
	system("cls");
	cout<<"File were compared succesfull :)\n\n";
	float percentage = ((float) perCount / (float)finalCount ) * 100.0;
	cout<<"percentage matched btw both files = "<<percentage;
	cout<<"\n\nThe diff btw the lines that were not match as been outputted to RESULT detail.txt present at desktop\n\n";
	cout<<"THANK YOU for using the program - download more at [ harshnative github ]\n\n";
	system("pause");
	infile6.close();
	return 0;
}
