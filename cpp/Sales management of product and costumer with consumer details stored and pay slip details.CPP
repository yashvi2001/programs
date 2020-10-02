/*HEADDER FILES*/
#include<iostream.>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
/* function prototype*/
void main();
void menu();
void details();
void new_costumer();
void old_costumer_detail();
void bill();
void add_new_product();
struct costumer          //TO STORE COSTUMER DETAIL
{
int inroll;
char name[50];
char address[100];
int pro_code[100];
int count;
char mob_no[10];
};
struct product         //TO STORE PRODUCT DETAIL
{
int pro_no;
char name_p[50];
int tax;
};
/*GLOBAL OPTIONS*/
int z=0,x=0;
/*DECLERATION OF STRUCTURES*/
costumer c[100];
product p[100];
/*CLASSES*/
void main()
{int op,n;
clrscr();
cout<<"\n\n\n\n\n\n\n";  //INTRO
cout<<"***************************************************************************";
cout<<"\n                                 WELCOME                             ";
cout<<"\n                        THIS IS COUMPUTER PROJECT         ";
cout<<"\n                          FOR SALE'S MANAGEMENT           ";
cout<<"\n                        BY NITISH KUMAR SONTHALIA         ";
cout<<"\n*************************************************************************";
cout<<"\nENTER ANY DIGIT AND PRESS ENTER TO CONTINUE - ";
cin>>n;
clrscr();
while(1)              //INFINITE LOOP
{
cout<<"\n**********************************";
cout<<"\n1.MENU\n2. EXIT";
cout<<"\nENTER YOUR OPTION-";
cin>>op;
switch(op)
{
case 1:
menu();
break;
case 2:
exit(0);
break;
default:
cout<<"\nWRONG OPTION";
}
}
}
void menu()
{
int op;
clrscr();
cout<<"\n**********************************";
cout<<"\nMAIN MENU";
cout<<"\n1.COSTUMER DETAILS";
cout<<"\n2.BILL";
cout<<"\n3.ADD NEW PRODUCT\n4. EXIT";
cout<<"\nENTER YOUR OPTION-";
cin>>op;
cout<<"\n**********************************";
switch(op)
{
case 1:
details();
break;
case 2:
bill();
break;
case 3:
add_new_product();
break;
case 4:
exit(0);
break;
default:
cout<<"\nWRONG OPTION";
}
}
void details()
{
int OP;
clrscr();
cout<<"\n**********************************";
cout<<"\nENTER YOUR OPTION";
cout<<"\n1. OLD COSTUMER DETAIL";
cout<<"\n2. NEW COSTUMER DETAIL\n3. BACK TO MAIN MENU\n 4.EXIT";
cout<<"\nENTER YOUR OPTION-";
cin>>OP;
cout<<"\n**********************************";
switch(OP)
{
case 1:
old_costumer_detail();
break;
case 2:
new_costumer();
break;
case 3:
menu();
break;
case 4:
exit(0);
break;
default:
cout<<"\nWRONG OPTION";
}
}
void old_costumer_detail()
{
int n=0,i,op;
clrscr();
cout<<"\n**********************************";
cout<<"\n1.GET DETAIL\n2.BACK TO MAIN MENU\n3.EXIT\nENTER YOUR OPTION- ";
cin>>op;
switch(op)
{
case 1:
clrscr();
cout<<"\n**********************************";
cout<<"\nENTER COSTUMER ENROLMENT NO.-";
cin>>n;
clrscr();
cout<<"\n**********************************";
cout<<"\nENROLMENT NUMBER:"<<n;
cout<<"\nNAME:"<<c[n-1].name;
for(i=0;i<c[n].count;i++)
cout<<"\nTHE PRODUCTS BOUGHT TILL DATE"<<c[n].pro_code[i];
cout<<"\nADDRESS:"<<c[n-1].address;
cout<<"\nMOBILE NO.:"<<c[n-1].mob_no;
break;
case 2:
menu();
break;
case 3:
exit(0);
break;
default:
cout<<"\nWRONG OPTION";
}
}
void new_costumer()
{int op;
clrscr();
cout<<"\n**********************************";
cout<<"\n1.INPUT DETAIL\n2.BACK TO MAIN MENU\n3.EXIT\nENTER YOUR OPTION- ";
cin>>op;
switch(op)
{
case 1:
clrscr();
cout<<"\n**********************************";
cout<<"\nCOSTUMER ENROLLMENT NO. IS:"<<x+1;
cout<<"\n**********************************";
cout<<"\nENTER NAME:";
cin.get();
cin.getline(c[x].name,80);
cout<<"\nENTER ADDRESS:";
cin.getline(c[x].address,80);
cout<<"\nENTER MOBILE NO.:\n";
cin>>c[x].mob_no;
c[x].inroll=x;
x++;
cout<<"\n**********************************";
break;
case 2:
menu();
break;
case 3:
exit(0);
break;
default:
cout<<"\nWRONG OPTION";
}
}
void bill()
{
int i,b,n,m[50],q[50],r[50],s=0,t;
int op;
clrscr();
cout<<"\n**********************************";
cout<<"\n1.BILL WITH OLD COSTUMER DETAIL\n2.BILL WITHOUT COSTIMER DETAIL";
cout<<"\n3.BACK TO MAIN MENU\n4.EXIT\nENTER YOUR OPTION- ";
cin>>op;
switch(op)
{
case 1:
clrscr();
cout<<"\n**********************************";
cout<<"\nENTER COUSTUMER ENROLLMENT NO.-";
cin>>n;
cout<<"\nENTER THE NO. OF PRODUCTS THE COSTUMER WANTS TO BUY-";
cin>>b;
for(i=0;i<b;i++)
{
cout<<"\n**********************************";
cout<<"\nENTER PRODUCT NO.-";
cin>>m[i];
c[n+i].pro_code[i]=m[i];
c[n+i].count++;
cout<<"\nENTER QUANTITY-";
cin>>q[i];
cout<<"\nENTER RATE-";
cin>>r[i];
cout<<"\n**********************************";
}
cout<<"\n**********************************";
clrscr();
cout<<"\n***********PAY SLIP***************";
cout<<"\nENROLMENT NUMBER:"<<(c[n-1].inroll)+1;
cout<<"   NAME:"<<c[n-1].name;
cout<<"   ADDRESS:"<<c[n-1].address;
cout<<"   MOBILE NO.:"<<c[n-1].mob_no;
cout<<"\n**********************************";
for(i=0;i<b;i++)
{
 cout<<"\nPRODUCT NAME: "<<p[m[i]-1].name_p;
 cout<<"  RATE: "<<r[i];
 cout<<"  QUANTITY: "<<q[i];
 t=r[i]*(p[m[i]-1].tax)*q[i]/100;  //CALCULATING TAX
 cout<<"  TAX: "<<t;
 s=s+r[i]*q[i]+t;                  //CALCULATING TOTAL AMOUNT
 cout<<"  AMOUNT: "<<r[i]*q[i]+t;
 cout<<"\n**********************************";
 cout<<"\n";
}
cout<<"\n**********************************";
cout<<"\nTOTAL AMT: "<<s;
cout<<"\n**********************************";
cout<<"\nTHANKS FOR SHOPPING \n PLEASE VISIT AGAIN";
cout<<"\n**********************************";
break;
case 2:
clrscr();
cout<<"\n**********************************";
cout<<"\nENTER THE NO. OF PRODUCTS THE COSTUMER WANTS TO BUY-";
cin>>b;
for(i=0;i<b;i++)
{
cout<<"\n**********************************";
cout<<"\nENTER PRODUCT NO.-";
cin>>m[i];
cout<<"\nENTER QUANTITY-";
cin>>q[i];
cout<<"\nENTER RATE-";
cin>>r[i];
cout<<"\n**********************************";
}
cout<<"\n**********************************";
clrscr();
cout<<"\n***********PAY SLIP***************";
cout<<"   NAME:CASH";
cout<<"   ADDRESS:--";
cout<<"   MOBILE NO.:--";
cout<<"\n**********************************";
for(i=0;i<b;i++)
{
 cout<<"\nPRODUCT NAME: "<<p[m[i]-1].name_p;
 cout<<"  RATE: "<<r[i];
 cout<<"  QUANTITY: "<<q[i];
 t=r[i]*(p[m[i]-1].tax)*q[i]/100;
 cout<<"  TAX: "<<t;
 s=s+r[i]*q[i]+t;
 cout<<"  AMOUNT: "<<r[i]*q[i]+t;
 cout<<"\n**********************************";
 cout<<"\n";
}
break;
case 3:
menu();
break;
case 4:
exit(0);
break;
default:
cout<<"\nWRONG OPTION";
}
}
void add_new_product()
{int op;
 clrscr();
 cout<<"\n**********************************";
cout<<"\n1.ADD PRODUCT\n2.BACK TO MAIN MENU\n3.EXIT\nENTER YOUR OPTION- ";
 cin>>op;
 switch(op)
 {
 case 1:
 clrscr();
 cout<<"\n**********************************";
 cout<<"\nPRODUCT NO. IS:"<<z+1;
 cout<<"\n**********************************";
 cout<<"\nENTER PRODUCT NAME:";
 cin>>p[z].name_p;
 cout<<"INPUT TAX % FOR THE PRODUCT:";
 cin>>p[z].tax;
 p[z].pro_no=z;
 z++;
 break;
 case 2:
 menu();
 break;
 case 3:
 exit(0);
 break;
 default:
 cout<<"\nWRONG OPTION";
 }
}
