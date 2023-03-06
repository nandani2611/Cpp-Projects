// 12th project
// By Nandani Dalsaniya
// Supermarket Billing Project for class 12 CBSE board

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>


//******************** welcome screen ********************
void wlcm()
{
	int gdriver = DETECT,gmode,errorcode;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");

	errorcode = graphresult();
	if (errorcode != grOk)  /* an error occurred */
	{
	 printf("Graphics error: %s\n", grapherrormsg(errorcode));
	 printf("Press any key to halt:");
	  getch();
	 exit(1); /* terminate with an error code */
	}
	settextstyle(10,0,4);
	setcolor(YELLOW);
	outtextxy(150,100,"WELCOME"); 	delay(100);
	outtextxy(250,200,"TO");      	delay(120);
	outtextxy(240,300,"C++");      	delay(140);
	
delay(1000);
getch();
}

//******************** box function ********************
void box(int l, int t, int r, int b)
{
	int i;
	textcolor(2);

	gotoxy(l,t);
	cout<<char(201);

	for(i=l+1;i<r;i++)
	{
		cout<<char(205);
	}
	cout<<char(187);
	for(i=t+1;i<b;i++)
	{
	       gotoxy(l,i);
	       cout<<char(186);
	       gotoxy(r,i);
	       cout<<char(186);
	}

	gotoxy(l,b);
	cout<<char(200);

	for(i=l+1;i<r;i++)
	{
		gotoxy(i,b);
		cout<<char(205);
	}

	gotoxy(r,b);
	cout<<char(188);
}

 

//******************** date and time ********************
void datee()
{
    struct date d;
    char p[3],c;

    getdate(&d);
    gotoxy(57,22); textcolor(22);
    cprintf("Date : ");
    cprintf("%d: ",d.da_day);
    cprintf("%d: ",d.da_mon);
    cprintf("%d ",d.da_year);

    struct time t;
    gettime(&t);
    gotoxy(5,22); textcolor(22);
    cprintf("Time: %2d:%02d:%02d", t.ti_hour, t.ti_min, t.ti_sec);
}

//******************** introduction ********************
void intro()
{
	datee();
	box(1,1,79,24);
	textmode(C80);
	gotoxy(23,3);  	textcolor(12);
	cprintf(" ST. ANTHONY'S SE. SEC SCHOOL ");      delay(100);

	gotoxy(32,4);  	textcolor(12);
	cprintf(" UDAIPUR ");      delay(100);

	gotoxy(28,6);  	textcolor(15);
	cprintf(" SESSION 2018-19 ");    delay(100);

	gotoxy(25,8);  	textcolor(10);
	cprintf(" Computer Science Project ");     delay(100);

	gotoxy(31,10); 	textcolor(14);
	cprintf(" Project on ");     delay(100);

	
gotoxy(27,11); 	textcolor(13);
	cprintf(" C/C++ Programming ");     delay(100);

	gotoxy(24,13); 	textcolor(11);
	cprintf(" TOPIC  :  SUPER MARKET ");     delay(100);

	gotoxy(29,15); 	textcolor(12);
	cprintf(" Class : XII Sci. ");       delay(100);

	gotoxy(11,18);  textcolor(3);
	cprintf(" Submitted by :  ");       delay(100);

	gotoxy(13,19);  textcolor(2);
	cprintf(" Nandani Dalsaniya  ");       delay(100);

	gotoxy(46,18); 	textcolor(3);
	cprintf(" Under guidance of : ");       delay(100);

	gotoxy(48,19); 	textcolor(2);
	cprintf(" Sunil Kumar Sharma ");       delay(100);

	delay(1000);

getch();
}

//******************** progress bar ********************
void pro_bar()
{
clrscr();
       //	box(1,1,79,24);
	int j,x,y,k;
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");

	x=getmaxx()/2;
	y=getmaxy()/2;

	settextstyle(7,0,4);
	setcolor(YELLOW);
	
    outtextxy(250,245,"LOADING.....");
	delay(100);
	for(k=30;k<200;k++)
	{
		delay(20);
		setcolor(k/15);
		arc(x,y,0,180,k-15);
	}
}

//******************** class used in project ********************
class product
{
	int pno;
	char name[50];
	float price , qty;
 public :
	void inputpno()
	{	cout<<"\n Enter product no.    ";
		cin>>pno;
	}
	void inputpnm()
	{	cout<<"\n Enter product name    ";
		gets(name);
	}
	void inputprice()
	{	cout<<"\n Enter price of the product      ";
		cin>>price;
	}

	void createprdct()
	{	inputpno();
		inputpnm();
		inputprice();
	}

	void showprdct()
	{		cout<<"\n Product no.   "<<pno<<"\t    Product name  "<<name<<"\t    product price  "<<price<<endl;
	}

	int givepno()	 	{ return pno ;}
	int givepprice()  	{ return price ;}
	char * givepnm() 	{ return name ;}

}p1;

char filenm[30]="shop.txt";

//******************* adding product records ********************
void writeprdct()
{
	ofstream fout;
	fout.open(filenm,ios::binary|ios::app);
	p1.createprdct();
	fout.write((char*)&p1,sizeof(p1));
	fout.close();

	cout<<"\n\nThe Product Has Been Created ";
}

//******************** printing records ********************
void displayprdct()
{
clrscr();
	ifstream fin;

	fin.open(filenm,ios::in);
	int flag=0;

	if(!fin)
	{  cout<<" File not open ";
	   getch();
	  return;
	}

	while(!fin.eof())
	{	fin.read((char*)&p1,sizeof(p1));

		if(fin.eof())
			break;

		p1.showprdct();

		flag=1;
	}

	if(!flag)
	 cout<<"\n SORRY !!!  FILE NOT FOUND  ";
}

//******************** deleting all information *************************
void delinfo()
{
	ofstream fout;
	char ch;

	cout<<"\n Do you really want to delete all information ? (y/n)";
	cin>>ch;

	if(ch=='y'||ch=='Y')
	{	fout.open(filenm,ios::binary);
		fout.close();
	}
}

//******************** total no of information *************************
void totalinfo()
{
	ifstream fin;
	int p;

	fin.open(filenm,ios::binary);
	fin.seekg(0,ios::end);
	p=fin.tellg();

	cout<<"\n\n\t Total no. of products are    "<<p/sizeof(p1);
}

//******************** print by specific detail ********************
//******************** print by product no. ********************
void printbyprdct_no()

{
	ifstream fin;
	fin.open(filenm,ios::binary);
	int flag=0;
	int p;

	displayprdct();

	cout<<"\n\n Enter product no. you want to print ";
	cin>>p;

	while(!fin.eof())
	{
		fin.read((char*)&p1,sizeof(p1));

		if(fin.eof())
			break;
		if(p1.givepno()==p)
			p1.showprdct();

		flag=1;
	}
	if(!flag)
	 cout<<"\n SORRY !!!  FILE NOT FOUND  ";
}

//******************** print by product name ********************
void printbyprdct_nm()
{
	ifstream fin;
	fin.open(filenm,ios::binary);
	int flag=0;
	char s[20];

	displayprdct();

	cout<<"\n\n Enter product name you want to search :-   ";
	gets(s);

	while(!fin.eof())

	{
		fin.read((char*)&p1,sizeof(p1));
		if(fin.eof())
			break;

		if(strcmpi(p1.givepnm(),s)==0)
			p1.showprdct();

		flag=1;
	}
	if(!flag)
	 cout<<"\n SORRY !!!  FILE NOT FOUND  ";
}

//******************** print by product price ********************
void printbyprdct_price()
{
	ifstream fin;
	fin.open(filenm,ios::binary);
	int flag=0;
	float p;

	displayprdct();
	cout<<"\n\n Enter product's price you want to search    ";
	cin>>p;

	while(!fin.eof())
	{
		fin.read((char*)&p1,sizeof(p1));

		if(fin.eof())
			break;

		if(p1.givepprice()==p)
			p1.showprdct();

		flag=1;
	}
	if(!flag)
	 cout<<"\n SORRY !!!  FILE NOT FOUND  ";

}

//**************** sub menu of displaying information *****************
void submenu1()
{
clrscr();
	int ch;

	while(1)
	{
		clrscr();
		cout<<"\n\t **************** DISPLAY   ONE   INFORMATION  *****************\n\n";
		cout<<"\n\t 1. Display information by product no.   ";
		cout<<"\n\t 2. Display information by product name  ";
		cout<<"\n\t 3. Display information by product price ";
		cout<<"\n\t 0. Back ";

		cout<<"\n\n\t Enter your choice   ";
		box(1,1,79,24);
		gotoxy(30,10);  cin>>ch;

		switch(ch)
		{
			case 1 : printbyprdct_no(); 	break;

			case 2 : printbyprdct_nm();	 break;

			case 3 : printbyprdct_price();	 break;

			case 0 : return ;
		}// end of switch
	getch();
	}//end of while
getch();
}

//********************* delete by product no. *******************
void delbypno()
{
	
char ch;
	int r,flag=0;

	ifstream fin(filenm,ios::binary);
	ofstream fout("tmp",ios::binary);

	displayprdct();

	cout<<"\n\n Enter product no. you want to delete ";
	cin>>r;

	cout<<"\n\n Do you really want to delete  ?(y/n) \n ";
	cin>>ch;

	if(ch=='y'||ch=='Y')
	{
		while(!fin.eof())
		{
			fin.read((char*)&p1,sizeof(p1));
			if(fin.eof())
				break;
			if(r!=p1.givepno())
				fout.write((char*)&p1,sizeof(p1));
			else
			   flag=1;
		}
	}

	fin.close();
	fout.close();

	remove(filenm);
	rename("tmp",filenm);

	if(!flag)
		cout<<"\n Sorry!! Record not found....   ";
	else
	{	cout<<"\n After deletion  ";
		displayprdct();
	}

}

// ******************** delete info by product name **********************
void delbypnm()
{
	char ch,s[20];
	int flag=0;

	ifstream fin(filenm,ios::binary);
	ofstream fout("tmp",ios::binary);

	cout<<"\n\t Before Deletion  ";
	displayprdct();

	cout<<"\n\n Enter product name you want to delete ";
	gets(s);

	cout<<"\n\n Do you really want to delete  ?  (y/n) ";
	cin>>ch;

	if(ch=='y'||ch=='Y')
	{
		while(!fin.eof())
		{
			fin.read((char*)&p1,sizeof(p1));

			if(fin.eof())
				break;

			if(strcmpi(p1.givepnm(),s)!=0)
				fout.write((char*)&p1,sizeof(p1));
			else
				flag=1;
		}

		if(!flag)
		   cout<<"\n SORRY !!!  FILE NOT FOUND  ";
	}

	fin.close();
	
fout.close();

	remove(filenm);
	rename("tmp",filenm);

	if(!flag)
		cout<<"\n Sorry!! Record not found....   ";
	else
	{	cout<<"\n After deletion  ";
		displayprdct();
	}
}

// ******************** delete info by price **********************
void delbyprice()
{
	char ch;
	float p;
	int flag=0;
	ifstream fin(filenm,ios::binary);
	ofstream fout("tmp",ios::binary);

	cout<<"\n\n Before Deletion  ";
	displayprdct();

	cout<<"\n\n Enter product price  you want to delete ";
	cin>>p;

	cout<<"\n Do you really want to delete  ? (y/n)";
	cin>>ch;

	if(ch=='y'||ch=='Y')
	{
		while(!fin.eof())
		{
			fin.read((char*)&p1,sizeof(p1));

			if(fin.eof())
				break;


			if(p!=p1.givepprice())
				fout.write((char*)&p1,sizeof(p1));
			else
				flag=1;
		}
	}

	fin.close();
	fout.close();

	remove(filenm);
	rename("tmp",filenm);

	if(!flag)
		cout<<"\n Sorry!! Record not found....   ";
	else
	{	cout<<"\n After deletion  ";
		displayprdct();
	}
}

//******************* Submenu for deleting one record *******************
void submenu2()
{
clrscr();
	int ch;

	while(1)
	{
	clrscr();
              cout<<"\n\t\t **************** DELETE  ONE  RECORD *****************\n\n";
		cout<<"\n\t 1. Delete information by product no.   ";
		cout<<"\n\t 2. Delete information by product name  ";
		cout<<"\n\t 3. Delete information by product price ";
		cout<<"\n\t 0. Back ";

		cout<<"\n\n\t Enter your choice  :  ";
		box(1,1,79,24);
		gotoxy(30,10);  cin>>ch;

		switch(ch)
		{
			case 1 : delbypno();		 break;

			case 2 : delbypnm();		break;

			case 3 : delbyprice();		 break;

			case 0 : return ;
		}// end of switch
	getch();
	}//end of while
getch();
}

//********************* modify by product no. ********************
void modibypno()
{
	int r,flag=0,loc;
	char ch;

	fstream file(filenm,ios::binary|ios::in|ios::out);

	cout<<"\n Before Modification  ";
	displayprdct();

	cout<<"\n Enter product no. you want to modify ";
	cin>>r;

	cout<<"\n\n Do you really want to modify  ?(y/n) ";
	cin>>ch;

	if(ch=='y'||ch=='Y')
	{
		while(!file.eof())
		{
			loc=file.tellg();
			file.read((char*)&p1,sizeof(p1));
			if(file.eof())
				break;
			
if(r==p1.givepno())
			{
				cout<<"\n Information found ";
				p1.showprdct();
				file.seekg(loc,ios::beg);

				p1.inputpno();

				file.write((char*)&p1,sizeof(p1));
				flag=1;
			}
		}
	}

	file.close();

	if(!flag)
		cout<<"\n Sorry!! Record not found....   ";
	else
	{	cout<<"\n After modification  ";
		displayprdct();
	}
}

//********************* modify by name *******************
void modibyname()
{
	int flag=0,loc;
	char ch, s[20];

	fstream file(filenm,ios::binary|ios::in|ios::out);

	cout<<"\n Before Modification  ";
	displayprdct();

	cout<<"\n Enter name you want to modify ";
	gets(s);

	cout<<"\n\n Do you really want to modify  ?(y/n) ";
	cin>>ch;

	if(ch=='y'||ch=='Y')
	{
		while(!file.eof())
		{
			loc=file.tellg();
			file.read((char*)&p1,sizeof(p1));
			if(file.eof())
				break;
			if(strcmpi(p1.givepnm(),s)==0)
			{
				cout<<"\n Information found ";
				p1.showprdct();
				file.seekg(loc,ios::beg);

				p1.inputpnm();

				file.write((char*)&p1,sizeof(p1));

				flag=1;
			}
		}
	}

	file.close();

	if(!flag)
		cout<<"\n Sorry!! Record not found....   ";
	else
	{ 	cout<<"\n After modification  ";
		displayprdct();
	}
}

//********************** modify by pricee *****************************
void modibyprice()
{
	int flag=0,loc;
	char ch;
	float p;

	
fstream file(filenm,ios::binary|ios::in|ios::out);

	cout<<"\n Before Modification  ";
	displayprdct();

	cout<<"\n Enter price of the product you want to modify ";
	cin>>p;

	cout<<"\n Do you really want to modify  ?(y/n) ";
	cin>>ch;

	if(ch=='y'||ch=='Y')
	{
		while(!file.eof())
		{
			loc=file.tellg();
			file.read((char*)&p1,sizeof(p1));
			if(file.eof())
				break;
			if(p==p1.givepprice())
			{
				cout<<"\n  Information found ";
				p1.showprdct();
				file.seekg(loc,ios::beg);

				p1.inputprice();

				file.write((char*)&p1,sizeof(p1));
				flag=1;
			}
		}
	}

	file.close();

	if(!flag)
		cout<<"\n Sorry!! Record not found....   ";
	else
	{
		cout<<"\n After modification  ";
		
displayprdct();
	}
}

//******************* Submenu for modifying one information *****************
void submenu3()
{
clrscr();
//textmode(C80);
	int ch;
	while(1)
	{
	clrscr();
               cout<<"\n\t\t ***************** MODIFY  ONE  INFORMATION  *****************\n\n";
		cout<<"\n\t 1. Modify information by product no.   ";
		cout<<"\n\t 2. Modify information by product name  ";
		cout<<"\n\t 3. Modify information by product price ";
		cout<<"\n\t 0. Back ";
		cout<<"\n\n\t Enter your choice :  ";
		box(1,1,79,24);
		gotoxy(30,10); cin>>ch;

		switch(ch)
		{
			case 1 : modibypno();		 break;

			case 2 : modibyname();		break;

			case 3 : modibyprice();		 break;

			case 0 : return ;
		}// end of switch
	getch();
	}//end of while
getch();
}
 

// ********************* backup ************************
void backup()
{
	ifstream fin(filenm,ios::binary);
	ofstream fout("backup.txt",ios::binary);

	while(!fin.eof())
	{
		fin.read((char*)&p1,sizeof(p1));

		if(fin.eof())
			break;
		fout.write((char*)&p1,sizeof(p1));
	}

	fin.close();
	fout.close();
	cout<<"\n\n Backup done Succesfully   ";
}

// ********************* restore ************************
void restore()
{
	ifstream fin("backup.txt",ios::binary);
	ofstream fout(filenm,ios::binary);

	while(!fin.eof())
	{
		fin.read((char*)&p1,sizeof(p1));

		if(fin.eof())
			break;
		fout.write((char*)&p1,sizeof(p1));
	}

	fin.close();
	fout.close();

	cout<<"\n\n Successfully restore   ";
}

// ************************* product menu *****************************
void menu()
{
clrscr();
	fstream file(filenm,ios::in);
	if(!file)
	{
	cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
		cout<<"\n\n\n Program is closing ....";

		getch();
		exit(0);
	}

	cout<<"\n\n\t\t PRODUCT MENU \n\n";
	cout<<"====================================================\n";
	cout<<"P.NO.\t\tNAME\t\tPRICE\n";
	cout<<"====================================================\n";

	while(file.read((char*)&p1,sizeof(p1)))
	{
		cout<<p1.givepno()<<"\t\t"<<p1.givepnm()<<"\t\t"<<p1.givepprice()<<endl;
	}
	file.close();
}

//********************* placing order *************************

void place_order()
{
	fstream file(filenm,ios::in|ios::out);
	int order_arr[50],quan[50],c=0;

	float amt,total=0;
	char ch='Y';

	menu();

	cout<<"\n======================================================";
	cout<<"\n\t PLACE YOUR ORDER";
	cout<<"\n======================================================\n";
	do
	{
		cout<<"\nEnter The Product No. Of The Product : ";
		cin>>order_arr[c];
		cout<<"\nQuantity in number : ";
		cin>>quan[c];
		c++;
		cout<<"\nDo You Want To Order Another Product ? (y/n)";
		cin>>ch;
	}while(ch=='y' ||ch=='Y');

	cout<<"\n\nThank You For Placing The Order";
	getch();
	clrscr();

	cout<<"\n\n*********************** INVOICE ***********************\n";
	cout<<"\nPr No.   Pr Name    Quantity   Pr Price    Price \n";

	while(!file.eof())
	{
		file.read((char*)&p1,sizeof(p1));
		if(file.eof())
		   break;
		for(int x=0;x<=c;x++)
		 if(p1.givepno()==order_arr[x])
		 {	amt=p1.givepprice()*quan[x];
			cout<<"\n"<<order_arr[x]<<"\t  "<<p1.givepnm()
		<<"\t     "<<quan[x]<<"\t       "<<p1.givepprice()<<"\t  "<<amt;
			total+=amt;
		 }
	 }
	 file.close();

	cout<<"\n\n\t\t\t\t\tTOTAL = "<<total<<" /- ";
getch();
}

//****************** main menu ******************
void mainmenu()
{	int ch;

	while(1)
	{
		clrscr();
		box(1,1,79,24);
		textcolor(7);
		gotoxy(5,2);   cprintf("***********************************************************************");
		textcolor(11);
		gotoxy(30,3);  cprintf("  A D M I N   M E N U                ");
		textcolor(7);
		gotoxy(5,4);   cprintf("***********************************************************************");
		gotoxy(15,8);  cprintf(" 1. Writing product information      ");
		gotoxy(15,9);  cprintf(" 2. Displaying product information   ");
		gotoxy(15,10); cprintf(" 3. Deleting all product information ");
		gotoxy(15,11); cprintf(" 4. Display one product information  ");
		gotoxy(15,12); cprintf(" 5. Deleting one information         ");
		gotoxy(15,13); cprintf(" 6. Modifying one information        ");
		gotoxy(15,14); cprintf(" 7. Total no. of information   ");
		gotoxy(15,15); cprintf(" 8. Backup   ");
		gotoxy(15,16); cprintf(" 9. Restore       ");
		gotoxy(15,17); cprintf(" 0. Back     ");

		gotoxy(4,20);  cprintf(" Enter your choice  :  ");
		gotoxy(33,20); cin>>ch;

		switch(ch) 
		{
			case 1 : clrscr();
				 writeprdct();	 break;

			case 2 : clrscr();
				 displayprdct(); 		 break;

			case 3 : clrscr();
				 delinfo();	 		break;

			case 4 : clrscr();
				 submenu1();	 	break;

			case 5 : clrscr();
				 submenu2();     		break;

			case 6 : clrscr();
				 submenu3(); 	 	break;

			case 7 : clrscr();
				 totalinfo(); 	 	break;

			case 8 : clrscr();
				 backup(); 	 		break;

			case 9 : clrscr();
				 restore(); 	 		break;

			case 0 : return ;
		}// end of switch
	getch();
	}//end of while
getch();
}

//******************** User selection ********************
void user()
{	int ch ;

	while(1)
	{
		clrscr();

		gotoxy(2,2);
		
cout<<" ===========================================================================";
		gotoxy(27,3);  	textcolor(12);
		cprintf("      NATIONAL   SUPERMARKET   \n");
		gotoxy(20,4);
		cprintf("     100 ft. ROAD   SHOBHAGPURA   UDAIPUR \n");
		gotoxy(2,5);
		cout<<" ===========================================================================";
		textcolor(11);
		gotoxy(24,10);	cprintf(" 1. Administrator ");
		gotoxy(24,12);	cprintf(" 2. Customer  ");
		gotoxy(24,14);	cprintf(" 3. Exit ");
		gotoxy(24,16);	cprintf(" Enter the choice  :  ");
		box(1,1,79,24);
		gotoxy(50,16);	cin>>ch;

		switch(ch)
		{
			case 1 : mainmenu();		 break;

			case 2 : place_order();	 break;

			case 3 : gotoxy(50,22); cprintf(" Bye Bye :) :)  ");
					 return;
		}
	}
}
void psswrd()
{
	int i;
	char ch[20],ps[20],t=1;
	box(1,1,79,24);
	box(16,9,35,11);
	box(16,14,35,16);

st :{
	gotoxy(19,10);
	
    cout<<" USER NAME ";
	gotoxy(40,10);	gets(ch);

	gotoxy(19,15);
	cout<<" PASSWORD  ";
	gotoxy(40,15);	cin>>ps;
    }

     if(strcmp(ps,"0")==0)
      {	gotoxy(55,22);
	cout<<" CORRECT ";
      }
     else
     {
	gotoxy(40,20);
	cout<<" INCORRECT ";
	t++;
	gotoxy(40,21);
	cout<<"\n\t\t TRY AGAIN ";
	delay(800);
	clrscr();
	if(t<=3)
	      goto st;
   }
}
void main()
{
clrscr();
textmode(C80);

	wlcm();
	pro_bar();
	cleardevice();
	closegraph();
	intro();
	psswrd();
	user();

getch();
}
