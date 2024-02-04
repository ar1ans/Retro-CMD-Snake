// Include necessary libraries for input/output, console handling, time functions, and file operations
#include <iostream>
#include <conio.h> // For console input/output
#include <windows.h> // For Windows-specific console commands
#include <time.h> // For time functions
#include <vector> // For using dynamic array (vector)
#include <fstream> // For file input/output
#include <string> // For string manipulation
using namespace std;

// Define a class to represent the body of the snake
class SnakeBody {
public:
    int x, y; // Coordinates of the snake body part
};

// Define a class for managing scores
class scores {
public:
    int emtiaza;
    string name; // Player's name
};


// Function to move the cursor to a specific position on the console
void gotoxy(int x, int y) {
    static HANDLE h = NULL; // Handle to the console window
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y }; // Define coordinates
    SetConsoleCursorPosition(h, c); // Set cursor position
}
// Function to pause the game and wait for a key press
void pressAnyKeyToContinue() {
    cout << "Press any key to continue" << endl;
    getch(); // Wait for a key press
}

int speedValue=400;
vector<scores> allscores;

void sleep( int mili ){
	Sleep(mili);
}

void option(int a){
	system("cls");
	cout<<"1.  level"<<endl;
	if(cin>>a){
	system("cls");
	cout<<"1.easy"<<endl;
	cout<<"2.normal"<<endl;
	cout<<"3.propesional"<<endl;
	}
	//edame dare...//
}


void Build_Wall(){
    system("cls");
	cout << "################################################################################" << endl;
	for( int i=0 ; i<20 ; i++ )
	{
		gotoxy(0 , i+1);
		cout << "#";
		gotoxy(79 , i+1 );
		cout << "#" << endl;
	}
	gotoxy(0 , 21);
	cout << "################################################################################" << endl;
}


void print_main_menu(){
	gotoxy(25 , 2);
	cout << "********* MENU *********";
	gotoxy(25 , 3);
	cout << "1) play game";
	gotoxy(25 , 4);
	cout <<"2) last scores";
	gotoxy(25 , 5);
	cout << "3) info";
	gotoxy(25 , 6);
	cout << "4) set speed ";
	gotoxy(25 , 7);
	cout << "5) EXIT ";
}

int get_choice(){
	gotoxy(20 , 8);
	cout << "According to the above menu enter your choice: ";
	int choice;
	cin >> choice;
	return choice;
}
void read_from_file(){
    scores temp;
    fstream file;
file.open("emtiaz.txt",fstream::in);

while(file>>temp.emtiaza>>temp.name)
   allscores.push_back(temp);

}
void write_to_file(){
     fstream file( "emtiaz.txt" , ios::out );
     for( int i=0 ; i < allscores.size() ; i++ )
     file << allscores[i].emtiaza <<" "<< allscores[i].name << endl;
     }
void last_scoure(){
    int h=4;
    system("cls");
    for(int f=0;f < allscores.size();f++){
cout << allscores[f].name << "  " << allscores[f].emtiaza << endl;
    }
    cout << endl << endl;
    pressAnyKeyToContinue();

}
void play(){

     scores temp;
	Build_Wall();
	vector<char> tolemar;
        int i=3;
        int a;
        int b;
        srand(time(NULL));
        a=rand()%73;

        b=rand()%15;
		a+=2;

		b+=2;

        gotoxy(a,b);
        cout<<(char) i;
	char key , lastKey = 77;
	int curX = 10 , curY = 10;
	vector <SnakeBody> mySnake;
	SnakeBody head;
	head.x = curX;
	head.y = curY;
	mySnake.push_back(head);
    int emtiaz=0;
	while( true ){
		Sleep(speedValue);
		if( kbhit() )
			key = getch();
		if( key == 'p' ){
			Sleep(3000);
			key = lastKey;
		}

		if( key == 27 ){
			gotoxy(38,22);
			cout << "END OF GAME!" << endl;
			break;
		}

		if( key == 72 && lastKey != 80 || key == 80 && lastKey != 72 || key == 77 && lastKey != 75 || key == 75 && lastKey != 77 ){
			lastKey = key;
		}
		gotoxy(curX , curY);
		cout << " ";

		switch( lastKey ){
			case 75:
				curX--;
				break;
			case 77:
				curX++;
				break;
			case 80:
				curY++;
				break;
			case 72:
				curY--;
				break;
		}
        int sz = mySnake.size();
        SnakeBody dom = mySnake[sz-1];
        for( int i=sz-1 ; i>0 ; i-- )
            mySnake[i] = mySnake[i-1];
		mySnake[0].x = curX;
		mySnake[0].y = curY;
        if(curX==a && curY==b){
            mySnake.push_back(dom);
            a=rand()%50;
            b=rand()%19;
            gotoxy(a,b);
            cout<<(char) i;
            emtiaz+=10;
        }
        else
        {
           gotoxy(dom.x , dom.y);
           cout <<" ";
        }
		if( curX < 1 || curX > 80 || curY < 1 || curY > 20 ){
			gotoxy(38,22);
			cout << "GAME OVER!" << endl;
			gotoxy(38,23);
			cout << "your score is: " << emtiaz <<endl;
			gotoxy(38,24);
            cout<<"please enter your name"<<endl;
            cin>>temp.name;
            temp.emtiaza = 0 ;
            temp.emtiaza = emtiaz;
            allscores.push_back(temp);
			int bugh = 7;
			sleep(500);
            {
			cout<<char(bugh)<<char(bugh)<<char(bugh)<<endl;
            }
			break;
		}

        for( int i=0; i<sz ;i++ ){
            gotoxy(mySnake[i].x , mySnake[i].y);
            cout << "*";
		}
	}

}
int help(){
int p=5;
    system("cls");
    gotoxy(10,5);
    Sleep(1500);
        cout<< "for play this game you should use your hands!!!" << "   " << "just this" <<endl;
    gotoxy(10,7);
    Sleep(2000);
        cout<< "mr.sabounchi" <<"    ::        snake781@gmail.com"<<endl;
    gotoxy(10,9);
    Sleep(1800);
        cout<< "allame helli 7 Hischool"<<endl;
    gotoxy(27,11);
    Sleep(1500);
        cout<< "2013-2014" <<endl;
    pressAnyKeyToContinue();

return 0;
}
void speed(){
   int a=1;

system("cls");
gotoxy(25 , 3);
cout<<"1)worm"<<endl;
gotoxy(25 , 4);
cout<<"2)snake"<<endl;
gotoxy(25 , 5);
cout<<"3)dragon"<<endl;
gotoxy(25 , 7);
cout<<"please enter your number"<<endl;
cin >> a;
if(a==1){
    speedValue = 180;
}
else if(a==2){
    speedValue = 120;
}
else if(a==3){
    speedValue = 50;
}
else
gotoxy(25 , 8);
    cout<<"wrong choice...try again!!"<<endl;
}


int main(){
// declare vectors and read \rmations from file!
read_from_file();
	int choice;

	do{
		system("cls");
		print_main_menu();
		choice = get_choice();
		switch( choice ){
			case 1:
				play();
				break;
			case 2:
				last_scoure();
				break;
			case 3:
				help();
				break;
			case 4:
				speed();
				break;
			case 5:
                //do noting...//
                 break;
			default:
				gotoxy(30 , 22);
				cout << "Wrong choice! try again.";
				sleep(1500);
				break;
		}
	}
	while( choice != 5 );

	system("cls");
	gotoxy(30 , 22);
	cout << "End of program. Good Luck!";
	sleep(2000);
	system("cls");
write_to_file();

	// save all vectors to files.
	return 0;
}


/*
Copyright (c) © Aryan Sabounchi, 2014
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
- Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER "AS IS" AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
OF SUCH DAMAGE.
*/


