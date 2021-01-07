#include<iostream>
#include<cstdlib>
#include<cstring>
#include<windows.h>
using namespace std;
int call();
void display();
int main()
{
    char a;
    cout<<"\t***********************************************Word Gussing Game*********************************************************\n\n"<<endl;
    
	 char n;
     string Name;
     cout<<"Enter name  :       ";
     getline(cin,Name);
     cout<<endl;
     int score;
     do
     {
     	system("cls");
     	display(); 	
        score=score+call();
        cout<<"Do you want to play again y/n   :   ";
        cin>>n;
        cout<<endl;
     }while(n!='n');
     cout<<Name<<"  ";
     cout<<"your score is   :   "<<score<<endl;
     cout<<"\n\n\t***************************************************************************************************************\n\n"<<endl;
}
int call()
{

    int hint;
    string output;
    string a[10]={"Efficient","Learning","World",
					"Hello","Name","Jani","Share","Complete"
							,"Global","Comment"};
    char arr[10][10];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            char c;
            int r;
            r= rand() % 26;   // generate a random number
            c= 'a' + r;            // Convert to a character from a-z
            arr[i][j]=c;
        }
    }
    int index=rand()%10;
    output=a[index];
    if(a[index].length()%2==0)
    {
        // for even string length case
            int row=rand()%10;
            int col=rand()%3;
            for(int i=0;a[index][i]!='\0';i++,col++)
            {
                arr[row][col]=a[index][i];
            }
        
    }
    else
    {
        // for odd string length case
                // for even string length case
            int row=rand()%3;
            int col=rand()%10;
            for(int i=0;a[index][i]!='\0';i++,row++)
            {
                arr[row][col]=a[index][i];
            }
    }
     for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
          cout<<" "<<arr[i][j];
          Sleep(90);
        }
        cout<<endl;
    }
    
    string guess;
	cout<<"Press 1 for Guess number	"<<endl;
	cout<<"Press 2 for see Hint and then guess number	"<<endl;
	label1:
	cout<<"Enter input		:	";
	cin>>hint;
	cout<<endl;
	if(hint==1)
	{
		// do nothing
		//This part will be empty because in this part i have to ask user input for guess variable
		//But this part was common in if and else if also.So, i just write cin>>guess part outside if/elseif
		//You can also write that part here but then you have to write it in else if also but if you do this then you 
		//cannot write this thing after ifelseif .Because it will ask input again 2 times then .So  you have 2 methods
		//1)You can simple use this code
		//2)You can cut(Ctrlx+X) line 114 and 115 and past(Ctrl+V) it in if and else if
	}
       else if(hint==2)
       {
       cout<<"Guessed word in puzzle size is  :       ";
       cout<<output.size();
       cout<<endl;
       }
       else
       {
    	cout<<"Invalid input	";
    	goto label1;
	}
    cout<<"Enter word you guess         :       ";
    cin>>guess;
    cout<<endl;
    if(guess==a[index])
    {
        cout<<"Congratulations ! You have guessed correct word  "<<endl;
        return 1;
    }
    else
    {
        cout<<"Sorry ! Your guessed word is incorrect.Try again "<<endl;
        return 0;
    }
}
void display()
{
	    cout<<"\t***********************************************Word Gussing Game*********************************************************\n\n"<<endl;
    cout<<"You have to guess the word in this puzzle"<<endl;
    cout<<"For example word in this puzzle can be (world,Jani,Efficient etc )"<<endl;
    cout<<"You can also take help for hint from the system"<<endl<<endl;
    
}
