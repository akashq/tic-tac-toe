/*
 * ticatactoe.cpp
 * 
 * Copyright 2017 shad0w <x32@parrot>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 1|2|3
 * 4|5|6
 * 7|8|9
 * 
 * 
 */


#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

void gboxshow();
void gboxupdate(int pos, int ele);
void player1input();
void player2input();
int linearsearchp1(int ele);
int linearsearchp2(int ele);
void gboxcalculationp1();
void gboxcalculationp2();
void printarray();
void initialize();
//int random();

//global variables
int player1arr[5], player2arr[5];
int gbox[3][3];
char player1[50], player2[50];
int checkarr[9];


//initializing
void initialize()
{	
	//checkarr
	for(int i=0;i<9;i++)
	{
		checkarr[i]=0;
	}
	
	//player1arr player2arr
	for(int i=0;i<=5;i++)
	{
		player1arr[i]=0;
		player2arr[i]=0;
	}
	
	//gbox
	int num=1;
	for(int i=0;i<3;i++)
	{
		for(int k=0;k<3;k++)
		{
			gbox[i][k] = num;
			num++;
		}
	}
}
	

void gboxshow()
{
	cout<<gbox[0][0]<<"|"<<gbox[0][1]<<"|"<<gbox[0][2]<<endl;
	cout<<gbox[1][0]<<"|"<<gbox[1][1]<<"|"<<gbox[1][2]<<endl;
	cout<<gbox[2][0]<<"|"<<gbox[2][1]<<"|"<<gbox[2][2]<<endl;
}

void player1input()
{
	int pos;
	
	//player1 t1
	cout<<"\n"<<endl;
	cout<<player1<<" enter the position: ";
	cin>>pos;
	
	for(int i=0;i<5;i++)
	{
		if(pos==player1arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos==player2arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos<1 && pos>9)
		{
			cout<<" are you dumb or what!"; 
			exit(1);
		}
	}
	player1arr[0]=pos;
	gboxupdate(pos, 0);
	cout<<endl;
	gboxshow();

	
	//player2 t2
	cout<<"\n"<<endl;
	cout<<player2<<" enter the position: ";
	cin>>pos;
	
	for(int i=0;i<5;i++)
	{
		if(pos==player1arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos==player2arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos<1 && pos>9)
		{
			cout<<" are you dumb or what!"; 
			exit(1);
		}
	}
	player2arr[0]=pos;
	gboxupdate(pos, 1);
	cout<<endl;
	gboxshow();
	
	//player1 t3
	cout<<"\n"<<endl;
	cout<<player1<<" enter the position: ";
	cin>>pos;
	
	for(int i=0;i<5;i++)
	{
		if(pos==player1arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos==player2arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos<1 && pos>9)
		{
			cout<<" are you dumb or what!"; 
			exit(1);
		}
	}
	player1arr[1]=pos;
	gboxupdate(pos, 0);
	cout<<endl;
	gboxshow();
	
	//player2 t4
	cout<<"\n"<<endl;
	cout<<player2<<" enter the position: ";
	cin>>pos;
	
	for(int i=0;i<5;i++)
	{
		if(pos==player1arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos==player2arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos<1 && pos>9)
		{
			cout<<" are you dumb or what!"; 
			exit(1);
		}
	}
	player2arr[1]=pos;
	gboxupdate(pos, 1);
	cout<<endl;
	gboxshow();
	
	//player1 t5
	cout<<"\n"<<endl;
	cout<<player1<<" enter the position: ";
	cin>>pos;
	
	for(int i=0;i<5;i++)
	{
		if(pos==player1arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos==player2arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos<1 && pos>9)
		{
			cout<<" are you dumb or what!"; 
			exit(1);
		}
	}
	player1arr[2]=pos;
	gboxupdate(pos, 0);
	cout<<endl;
	gboxshow();
	gboxcalculationp1();
	
	//player2 t6
	cout<<"\n"<<endl;
	cout<<player2<<" enter the position: ";
	cin>>pos;
	
	for(int i=0;i<5;i++)
	{
		if(pos==player1arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos==player2arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos<1 && pos>9)
		{
			cout<<" are you dumb or what!"; 
			exit(1);
		}
	}
	player2arr[2]=pos;
	gboxupdate(pos, 1);
	cout<<endl;
	gboxshow();
	gboxcalculationp2();
	
	//player1 t7
	cout<<"\n"<<endl;
	cout<<player1<<" enter the position: ";
	cin>>pos;
	
	for(int i=0;i<5;i++)
	{
		if(pos==player1arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos==player2arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos<1 && pos>9)
		{
			cout<<" are you dumb or what!"; 
			exit(1);
		}
	}
	player1arr[3]=pos;
	gboxupdate(pos, 0);
	cout<<endl;
	gboxshow();
	gboxcalculationp1();
	
	//player2 t8
	cout<<"\n"<<endl;
	cout<<player2<<" enter the position: ";
	cin>>pos;
	
	for(int i=0;i<5;i++)
	{
		if(pos==player1arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos==player2arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos<1 && pos>9)
		{
			cout<<" are you dumb or what!"; 
			exit(1);
		}
	}
	player2arr[3]=pos;
	gboxupdate(pos, 1);
	cout<<endl;
	gboxshow();
	gboxcalculationp2();

	
	//player1 t9
	cout<<"\n"<<endl;
	cout<<player1<<" enter the position: ";
	cin>>pos;
	
	for(int i=0;i<5;i++)
	{
		if(pos==player1arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos==player2arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos<1 && pos>9)
		{
			cout<<" are you dumb or what!"; 
			exit(1);
		}
	}
	player1arr[4]=pos;
	gboxupdate(pos, 0);
	cout<<endl;
	gboxshow();
	gboxcalculationp1();

}


void player2input()
{
	int pos;
	
	//player2 t1
	cout<<"\n"<<endl;
	cout<<player2<<" enter the position: ";
	cin>>pos;
	
	for(int i=0;i<5;i++)
	{
		if(pos==player1arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos==player2arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos<1 && pos>9)
		{
			cout<<" are you dumb or what!"; 
			exit(1);
		}
	}
	
	player2arr[0]=pos;
	gboxupdate(pos, 0);
	cout<<endl;
	gboxshow();
	
	//player1 t2
	cout<<"\n"<<endl;
	cout<<player1<<" enter the position: ";
	cin>>pos;
	
	for(int i=0;i<5;i++)
	{
		if(pos==player1arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos==player2arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos<1 && pos>9)
		{
			cout<<" are you dumb or what!"; 
			exit(1);
		}
	}
	
	player1arr[0]=pos;
	gboxupdate(pos, 1);
	cout<<endl;
	gboxshow();
	
	//player2 t3
	cout<<"\n"<<endl;
	cout<<player2<<" enter the position: ";
	cin>>pos;
	for(int i=0;i<5;i++)
	{
		if(pos==player1arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos==player2arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos<1 && pos>9)
		{
			cout<<" are you dumb or what!"; 
			exit(1);
		}
	}
	
	player2arr[1]=pos;
	gboxupdate(pos, 0);
	cout<<endl;
	gboxshow();
	
	//player1 t4
	cout<<"\n"<<endl;
	cout<<player1<<" enter the position: ";
	cin>>pos;
	
	for(int i=0;i<5;i++)
	{
		if(pos==player1arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos==player2arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos<1 && pos>9)
		{
			cout<<" are you dumb or what!"; 
			exit(1);
		}
	}
	
	player1arr[1]=pos;
	gboxupdate(pos, 1);
	cout<<endl;
	gboxshow();
	
	//player1 t5
	cout<<"\n"<<endl;
	cout<<player2<<" enter the position: ";
	cin>>pos;
	
	for(int i=0;i<5;i++)
	{
		if(pos==player1arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos==player2arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos<1 && pos>9)
		{
			cout<<" are you dumb or what!"; 
			exit(1);
		}
	}
	
	player2arr[2]=pos;
	gboxupdate(pos, 0);
	cout<<endl;
	gboxshow();
	gboxcalculationp2();
	
	//player1 t6
	cout<<"\n"<<endl;
	cout<<player1<<" enter the position: ";
	cin>>pos;
	
	for(int i=0;i<5;i++)
	{
		if(pos==player1arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos==player2arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos<1 && pos>9)
		{
			cout<<" are you dumb or what!"; 
			exit(1);
		}
	}
	
	player1arr[2]=pos;
	gboxupdate(pos, 1);
	cout<<endl;
	gboxshow();
	gboxcalculationp1();
	
	//player2 t7
	cout<<"\n"<<endl;
	cout<<player2<<" enter the position: ";
	cin>>pos;
	
	for(int i=0;i<5;i++)
	{
		if(pos==player1arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos==player2arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos<1 && pos>9)
		{
			cout<<" are you dumb or what!"; 
			exit(1);
		}
	}
	
	player2arr[3]=pos;
	gboxupdate(pos, 0);
	cout<<endl;
	gboxshow();
	gboxcalculationp2();
	
	//player1 t8
	cout<<"\n"<<endl;
	cout<<player1<<" enter the position: ";
	cin>>pos;
	
	for(int i=0;i<5;i++)
	{
		if(pos==player1arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos==player2arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos<1 && pos>9)
		{
			cout<<" are you dumb or what!"; 
			exit(1);
		}
	}
	
	player1arr[3]=pos;
	gboxupdate(pos, 1);
	cout<<endl;
	gboxshow();
	gboxcalculationp1();
	
	//player2 t9
	cout<<"\n"<<endl;
	cout<<player2<<" enter the position: ";
	cin>>pos;
	
	for(int i=0;i<5;i++)
	{
		if(pos==player1arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos==player2arr[i])
		{
			cout<<" are you dumb or what!";
			exit(1);
		}
		else if(pos<1 && pos>9)
		{
			cout<<" are you dumb or what!"; 
			exit(1);
		}
	}
	
	player2arr[4]=pos;
	gboxupdate(pos, 0);
	cout<<endl;
	gboxshow();
	gboxcalculationp2();
	
}

void gboxupdate(int pos, int ele)
{
	switch(pos)
	{
		case 1:
			gbox[0][0]=ele;
			break;
		case 2:
			gbox[0][1]=ele;
			break;
		case 3:
			gbox[0][2]=ele;
			break;
		case 4:
			gbox[1][0]=ele;
			break;
		case 5:
			gbox[1][1]=ele;
			break;
		case 6:
			gbox[1][2]=ele;
			break;
		case 7:
			gbox[2][0]=ele;
			break;
		case 8:
			gbox[2][1]=ele;
			break;
		case 9:
			gbox[2][2]=ele;
			break;
	}
}

int linearsearchp1(int ele)
{
	int flag=0;
	for(int i=0;i<5;i++)
	{
		if(player1arr[i]==ele)
		{
			flag=1;
			break;
		}
	}
	
	
	return flag;
}

int linearsearchp2(int ele)
{
	int flag=0;
	for(int i=0;i<5;i++)
	{
		if(player2arr[i]==ele)
		{
			flag=1;
			break;
		}
	}
	
	return flag;
}

//for player1
void gboxcalculationp1()
{

	//i know i could use a loop her but i didn't
	
	//horizontal
	//row1
	checkarr[0]=linearsearchp1(1);
	checkarr[1]=linearsearchp1(2);
	checkarr[2]=linearsearchp1(3);
	
	//row2
	checkarr[3]=linearsearchp1(4);
	checkarr[4]=linearsearchp1(5);
	checkarr[5]=linearsearchp1(6);
	
	//row3
	checkarr[6]=linearsearchp1(7);
	checkarr[7]=linearsearchp1(8);
	checkarr[8]=linearsearchp1(9);
	
	
	if((checkarr[0]==1 && checkarr[1]==1 && checkarr[2]==1) || (checkarr[3]==1 && checkarr[4]==1 && checkarr[5]==1) || (checkarr[6]==1 && checkarr[7]==1 && checkarr[8]==1))
	{
		cout<<"\n";
		cout<<"good job "<<player1<<endl;
		exit(0);
	}
	
	//vertical
	//column1
	checkarr[0]=linearsearchp1(1);
	checkarr[1]=linearsearchp1(4);
	checkarr[2]=linearsearchp1(7);
	
	//column2
	checkarr[3]=linearsearchp1(2);
	checkarr[4]=linearsearchp1(5);
	checkarr[5]=linearsearchp1(8);
	
	//column3
	checkarr[6]=linearsearchp1(3);
	checkarr[7]=linearsearchp1(6);
	checkarr[8]=linearsearchp1(9);
	

	if((checkarr[0]==1 && checkarr[1]==1 && checkarr[2]==1) || (checkarr[3]==1 && checkarr[4]==1 && checkarr[5]==1) || (checkarr[6]==1 && checkarr[7]==1 && checkarr[8]==1))
	{
		cout<<"\n";
		cout<<"good job "<<player1<<endl;
		exit(0);
	}
	
	//cross
	checkarr[0]=linearsearchp1(1);
	checkarr[1]=linearsearchp1(5);
	checkarr[2]=linearsearchp1(9);
	
	checkarr[3]=linearsearchp1(3);
	checkarr[4]=linearsearchp1(5);
	checkarr[5]=linearsearchp1(7);
	
	
	if((checkarr[0]==1 && checkarr[1]==1 && checkarr[2]==1) || (checkarr[3]==1 && checkarr[4]==1 && checkarr[5]==1))
	{
		cout<<"\n";
		cout<<"good job "<<player1<<endl;
		exit(0);
	}
	
}

//for player2
void gboxcalculationp2()
{
	
	//horizontal
	//row1
	checkarr[0]=linearsearchp2(1);
	checkarr[1]=linearsearchp2(2);
	checkarr[2]=linearsearchp2(3);
	
	//row2
	checkarr[3]=linearsearchp2(4);
	checkarr[4]=linearsearchp2(5);
	checkarr[5]=linearsearchp2(6);
	
	//row3
	checkarr[6]=linearsearchp2(7);
	checkarr[7]=linearsearchp2(8);
	checkarr[8]=linearsearchp2(9);
	

	if((checkarr[0]==1 && checkarr[1]==1 && checkarr[2]==1) || (checkarr[3]==1 && checkarr[4]==1 && checkarr[5]==1) || (checkarr[6]==1 && checkarr[7]==1 && checkarr[8]==1))
	{
		cout<<"\n";
		cout<<"good job "<<player2<<endl;
		exit(0);
	}
	
	//vertical
	//column1
	checkarr[0]=linearsearchp2(1);
	checkarr[1]=linearsearchp2(4);
	checkarr[2]=linearsearchp2(7);
	
	//column2
	checkarr[3]=linearsearchp2(2);
	checkarr[4]=linearsearchp2(5);
	checkarr[5]=linearsearchp2(8);
	
	//column3
	checkarr[6]=linearsearchp2(3);
	checkarr[7]=linearsearchp2(6);
	checkarr[8]=linearsearchp2(9);
	

	if((checkarr[0]==1 && checkarr[1]==1 && checkarr[2]==1) || (checkarr[3]==1 && checkarr[4]==1 && checkarr[5]==1) || (checkarr[6]==1 && checkarr[7]==1 && checkarr[8]==1))
	{
		cout<<"\n";
		cout<<"good job "<<player2<<endl;
		exit(0);
	}
	
	//cross
	checkarr[0]=linearsearchp2(1);
	checkarr[1]=linearsearchp2(5);
	checkarr[2]=linearsearchp2(9);
	
	checkarr[3]=linearsearchp2(3);
	checkarr[4]=linearsearchp2(5);
	checkarr[5]=linearsearchp2(7);
	
	if((checkarr[0]==1 && checkarr[1]==1 && checkarr[2]==1) || (checkarr[3]==1 && checkarr[4]==1 && checkarr[5]==1))
	{
		cout<<"\n";
		cout<<"good job "<<player2<<endl;
		exit(0);
	}
}



int main()
{
	initialize();
	
	char choose01;
	
	cout<<"Player 1:\n"<<"Enter your name: ";
	cin>>player1;
	
	cout<<"\nPlayer 2:\n"<<"Enter your name: ";
	cin>>player2;
	
	cout<<"\nIf you can't choose simply press"<<endl;
	cout<<"'d' i'll randomly pick one of you."<<endl;
	
	cout<<"\n\n1."<<player1<<endl;
	cout<<"2."<<player2<<endl;
	
	cout<<"Who is gonna go first: ";
	cin>>choose01;
	
	if(choose01 == '1')
	{
		cout<<"\n"<<player1<<" you are gonna play with 0"<<endl;
		cout<<player2<<" you are gonna play with 1"<<endl;
	}
	else if(choose01 == '2')
	{
		cout<<"\n"<<player2<<" you are gonna play with 0"<<endl;
		cout<<player1<<" you are gonna play with 1"<<endl;
	}
	else if(choose01 == 'd')
	{
		//random();
	}
	else
	{
		cout<<"Invalid input"<<endl;
		exit(1);
	}
	
	cout<<endl;
	gboxshow();
		
	if(choose01=='1')
	{
		player1input();
	}
	else if(choose01=='2')
	{
		player2input();
	}
	cout<<"\n"<<"It's a draw"<<endl;
	return 0;
}
