#include <iostream>
#include <fstream>
#include <assert.h>
#include <ctype.h>
#include <conio.h>
#include "screen.h"
#include "cursor.h"

//ERIC SOGNEFESST && VENICE MAGUNGA

using namespace std;

char alphabet[] = {"abcdefghijklmnoprstuvwxyz12345789:;'|?/,!@#$%^&*"};
char menu ();
char continf();
char randChar ();
bool systems (string nope);
void info ();
void screen ();
int encrypt ();
void decrypt ();
void mid_string(string banner, int starting, int number);
void rectangle_box(int x, int y, int length, int width);
void tickertape(string banner, int repeats, int box_size, int x_right_box, int y_middle, int x_left_box);


int main()
{
char contin;
char ans;
screen();
string collect;
contin=continf();

while(contin=='y'||contin=='i')
{
while(contin=='i')
{
	info();
	contin=continf();
}

ans=menu();
switch (ans)
{

case ('1'):
	{
		getline(cin,collect);
		cls();
		int eric = encrypt();
		cls();
        if(eric==1)
		{
		rectangle_box(30, 10, 12, 4);
        string banner = "YOUR MESSAGE HAS BEEN ENCODED!!!";
        tickertape(banner, 1, 11, 42, 12, 31);
        cout<<flush<<endl<<endl<<endl<<endl;
        cls();
		}
		break;
	}
case ('2'):
	{
		getline(cin,collect);
		cls();
		decrypt();
		cls();
	    break;


	}
default:
	{
		getline(cin,collect);
		cout<<"You have entered an invalid number. Please try again."<<endl;
		cout<<"Please try again by entering 1 or 2"<<endl;
		wait(500);
		cls();
		break;
	}
}

contin=continf();
}
cls();
color(lightred);
	cout<<" _______ _                 _                         \n"
	    <<"|__   __| |               | |                        \n"
	    <<"   | |  | |__   __ _ _ __ | | __  _   _  ___  _   _  \n"
	    <<"   | |  | '_ \\ / _` | '_ \\| |/ / | | | |/ _ \\| | | | \n"
	    <<"   | |  | | | | (_| | | | |   <  | |_| | (_) | |_| | \n"
	    <<"   |_|  |_| |_|\\__,_|_| |_|_|\\_\\  \\__, |\\___/ \\__,_| \n"
	    <<"                                   __/ |             \n"
	    <<"                                  |___/              \n";
wait(550);

 return 0;
}

void screen (){
color(green);
 cout<<"    _______ _    _ ______   ______ _   _  _____ ____  _____  ______ _____ \n"
	 <<"   |__   __| |  | |  ____| |  ____| \\ | |/ ____/ __ \\|  __ \\|  ____|  __ \\\n "
	 <<"     | |  | |__| | |__    | |__  |  \\| | |   | |  | | |  | | |__  | |__) |\n"
	 <<"      | |  |  __  |  __|   |  __| | . ` | |   | |  | | |  | |  __| |  _  / \n"
	 <<"      | |  | |  | | |____  | |____| |\\  | |___| |__| | |__| | |____| | \\ \\ \n"
	 <<"      |_|  |_|  |_|______| |______|_| \\_|\\_____\\____/|_____/|______|_|  \\_\\ \n\n";
	cent("ENCRYPTOR AND DECRYPTOR");
	cout<<"\n\n\n\n\n\n\n";
color(white);
return;
}
//MEMU
char menu (){
string collect;
cls();
char ans;
cout<<"What would you like to do?\n"
	<<"To Encrypt    |Enter (1)\n"
	<<"To Decrypt    |Enter (2)\n"
	<<"\n\n\n\nEnter: ";
	if(ans !='1' || ans !='2')
	{
		ans='3';
	}
cin>>ans;
getline(cin,collect);
return ans;
}

char continf(){
char contin;
string collect;
int x=0;
do{
cout<<"Go to Main Menu  |Enter (Y)\n"
	<<"See intructions  |Enter (I)\n"
	<<"To Quit          |Enter (Q)\n"
	<<"\n\n\n\n\n\n\nEnter: ";
cin>>contin;
contin=tolower(contin);
if(contin=='y'||contin=='i'||contin=='q')
{
	getline(cin,collect);
	x=1;
}
else
{
getline(cin,collect);
cout<<"INVALID!!!";
wait(500);
}
cls();
}
while(x !=1);

return contin;

}

void info (){
	cls();
	cent("INSTRUCTIONS");
	cout<<"\n|-----------------------------------------------------------------------------|\n"
		<<"|When prompted for a FILE NAME:                                               |\n"
		<<"|                                                                             |\n"
		<<"|                                                                             |\n"
		<<"|";color(brightwhite,black,"IMPORTANT");cout<<": The message itself cannot exceed 95 characters!!!                 |\n"
		<<"|                                                                             |\n"
		<<"|For ENCODING, Please designate NAME and FILE TYPE of your choosing           |\n"
		<<"|(Example: hello.dat(message file) and whatever.docx(key file)                |\n"
		<<"|                                                                             |\n"
		<<"|For DECODING, Please enter SAME NAME and FILE TYPE as before in CORRECT ORDER|\n"
		<<"|(Example: hello.dat or whatever.docx)                                        |\n"
		<<"|-----------------------------------------------------------------------------|\n";
getch();
cls();
}

void mid_string(string banner, int starting, int number){

     for (int n = 0; n <= number - 1; n++)
     {
          cout<<banner[starting+n];
          cout<<flush;
     }
     return;
}

void rectangle_box(int x, int y, int length, int width){
     gotoxy(x,y);
     cout<<char(201);
     for(int i = 1; i<=length; i++) // row across the top
     {
          cout<<char(205)<<flush;
     }
     cout<<char(187)<<flush;
     for(int j = 1; j <= width; j++) // edges of box
     {
           gotoxy(x,y+j);
           cout<<char(186)<<flush;
           gotoxy(x+length+1, y+j);
           cout<<char(186)<<flush;
     }
     gotoxy(x,y+width);
     cout<<char(200)<<flush;
     for(int i=1; i <= length ; i++) // row across the bottom
     {
          cout<<char(205)<<flush;
     }
     cout<<char(188)<<flush;
     return;
}

void tickertape(string banner, int repeats, int box_size, int x_right_box, int y_middle, int x_left_box){

     for (int k = 1; k <= repeats; k++)
     {

          for(int s = 1; s <= box_size; s++)
          {
               gotoxy(x_right_box-s, y_middle);
               // control speed of tickertape
              wait(150);
              cout<<flush;
              for(int m = 0; m <= s-1; m++) //fill box with leftmost characters of banner
              {
                      cout<<banner[m];
                      cout<<flush;
              }

          }
         for(int y = 1; y < banner.length()-box_size; y++)
         {
                gotoxy(x_left_box, y_middle);
                // control speed of tickertape
                wait(150);
                cout<<flush;
                mid_string(banner, y, box_size);

	 }

	 }
     return;
}

int encrypt (){
//fills an entire arry with ~
char code[22][80];
char secret [22][80];
for( int row=0; row< 22; row++)
{
	for(int col=0; col<80; col++)
	{
		secret[row][col] = {'~'};
		code[row][col]=31;
	}
}
cout<<"Imput the message you would like to Encrypt:\n\n";
string message;
getline(cin,message);
srand(time(NULL));
//if there is an ~ replace that space with a charicter from the tring
int x=33;
for(int len = message.length(); len>0; len--)
{
		int row=randomInt(0,22);
		int col=randomInt(1,80);
		if(secret[row][col] == '~')
		{
		if(message[len-1]==' ')
		{
			secret[row][col]='`';
			code[row][col]=x;
			x++;
		}
		else
		{
		secret[row][col]=char(message[len-1]);
		code[row][col]=x;
		x++;
		}
		}
		else if(len>0)
			len+=1;
		else
			continue;
}
//fill an array with random charicters from the globally declared alphabet
char rowsdf [22][80];
for( int row=0; row< 22; row++)
{
	for(int col=0; col<80; col++)
	{
		rowsdf[row][col] = randChar();
	}
}
string grid, chord;
cout<<"message file name? (0=default) :";
getline(cin, grid);
if(systems(grid))
	return 2;
cout<<"key file name? (0=default) :";
getline(cin, chord);
if(systems(chord))
	return 2;
//asks for the name of the file it is sending out to.
if(grid=="0")
	grid="grid.dat";
if(chord =="0")
	chord="location.dat";
ofstream fgrid;
fgrid.open(grid,ios::out);
assert(! fgrid.fail());
ofstream loc;
loc.open(chord,ios::out);
assert(! loc.fail());
//sends out the message array and the location of the charicter file.
for( int row=0; row< 22; row++)
{
	for(int col=0; col<80; col++)
	{
		loc<<code[row][col];

		if(secret[row][col]=='~')
		{
		//sends out a randdom charicter that is randomly uppercae it a-z if there is and ~ in secret otherwise it sends out the charicter in that space
		//in secret
		int yes=1+rand()%2;
		if(yes==1)
		{
		if(rowsdf[row][col] >='a' && rowsdf[row][col] <= 'z')
			fgrid<<char(rowsdf[row][col]-32);
		else
			fgrid<<char(rowsdf[row][col]);
		}
		else
		{
		fgrid<<char(rowsdf[row][col]);
		}
		}
		else
		{
		fgrid<<char(secret[row][col]);
		}
	}
fgrid<<"\n";
loc<<"\n";
}
fgrid.close();
loc.close();
return 1;
}

char randChar (){
//random charicter from alphabet
int n;
int x=sizeof(alphabet)-1;
n=randomInt(0,x);
return alphabet[n];
}

void decrypt (){

char grid[22][80];
char location[22][80];
string grids, chord;

//asks for name of a file to take in

cout<<"message file name? (0=default) :";
getline(cin,grids);
cout<<"key file name? (0=default) :";
getline(cin, chord);
if(grids=="0")
	grids="grid.dat";
if(chord =="0")
	chord="location.dat";
ifstream inloc;
inloc.open(chord,ios::in);
ifstream ingrid;
ingrid.open(grids,ios::in);
//takes in the infromation from the files
for(int row=0; row<22; row++)
{
	for(int col=0; col<80; col++)
	{
		inloc>>location[row][col];
		ingrid>>grid[row][col];
	}

}
inloc.close();
ingrid.close();

//this cheaks for the largest ascii value in location so it will know how many times to fun the loop for the print for loop
int x=33;
int y;


x=33;
for(int row=0; row<22; row++)
{
	for(int col=0; col<80; col++)
	{
		if(location[row][col]>x)
			x=location[row][col];

	}

}

//prints out the message
for(x;x>32;x--)
{
	for(int row=0; row<22; row++)
	{
		for(int col=0; col<80; col++)
		{
			if(location[row][col]==x)
			{
			if(char(grid[row][col])=='`')
				cout<<" ";
			else
				cout<<char(grid[row][col]);
			}
		}
	}
}
getch();
cout<<"\n\n";
return;
}

bool systems (string nope)
{
	int x;
	x=nope.find("Windows");
	if(x == -1)
		return false;
	if(nope.substr(x,7)=="Windows")
		{
			cls();
			cout<<"ERROR: Supected of trying to change a system file";
			_getch();
			return true;
		}
	else
		return false;
}
