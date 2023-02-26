#include<lpc21xx.h>
void cmd(int c);
void data(char d);
void delay();
void delay2();
void display(const char *p);
char rec();
char key();
void main()
{
int a,i,d=0,g=0,l=0,n,o,p,q,r,s,t,x;
char b[4]="1111",c[4],e[4]="2222",f[4],j[4]="3333",k[4],m[10];
IO0DIR=0XFFFFFFFF;
IO1DIR=0X0FF0FFFF;
PINSEL0=0X00000005;
U0LCR=0X83;
U0DLM=0X00;
U0DLL=0X63;
U0LCR=0X03;
cmd(0X38);
cmd(0X01);
cmd(0X80);
cmd(0X06);
cmd(0X0E);
while(1)
{
if((IO1PIN&0X80000000)==0)
{
display("Two Wheeler");
cmd(0XC0);
display("Entering...");
cmd(0X01);
display("Enter pin");
cmd(0XC0);
for(i=0;i<4;i++)
{
c[i]=key();
data(c[i]);
}
cmd(0X01);
for(i=0;i<4;i++)
{
if(b[i]==c[i])
{
d++;
}
}
if(d==4)
{
d=0;
display("APPROVED");
cmd(0X01);
display("Payment");
cmd(0XC0);
o=rec();
data(o);
o=o-48;
p=rec();
data(p);
p=p-48;
q=rec();
data(q);
q=q-48;
cmd(0X01);
display("Balance");
cmd(0XC0);
x=(o*100)+(p*10)+q;	
x=x-100;
o=x/100+48;
data(o);
p=(x%100)/10+48;
data(p);
q=x%10+48;
data(q);
IO0CLR=0X00FF0000;
IO0SET=0X00410000;
delay2();
IO0CLR=0X00FF0000;
IO0SET=0X00000000;
delay2();
IO0CLR=0X00FF0000;
IO0SET=0X00420000;
delay2();
IO0CLR=0X00FF0000;
IO0SET=0X00000000;
cmd(0X01);
}
else
{
display("DENIED");
cmd(0X01);
}
}
else if((IO1PIN&0X40000000)==0)
{
display("Four Wheeler");
cmd(0XC0);
display("Entering...");
cmd(0X01);
display("Enter pin");
cmd(0XC0);
for(i=0;i<4;i++)
{
f[i]=key();
data(f[i]);
}
cmd(0X01);
for(i=0;i<4;i++)
{
if(e[i]==f[i])
{
g++;
}
}
if(g==4)
{
g=0;
display("APPROVED");
cmd(0X01);
display("Payment");
cmd(0XC0);
o=rec();
data(o);
o=o-48;
p=rec();
data(p);
p=p-48;
q=rec();
data(q);
q=q-48;
cmd(0X01);
display("Balance");
cmd(0XC0);
x=(o*100)+(p*10)+q;	
x=x-200;
o=x/100+48;
data(o);
p=(x%100)/10+48;
data(p);
q=x%10+48;
data(q);
IO0CLR=0X00FF0000;
IO0SET=0X00440000;
delay2();
IO0CLR=0X00FF0000;
IO0SET=0X00000000;
delay2();
IO0CLR=0X00FF0000;
IO0SET=0X00480000;
delay2();
IO0CLR=0X00FF0000;
IO0SET=0X00000000;
cmd(0X01);
}
else
{
display("DENIED");
cmd(0X01);
}
}
else if((IO1PIN&0X20000000)==0)
{
display("Heavy Vehicle");
cmd(0XC0);
display("Entering...");
cmd(0X01);
display("Enter pin");
cmd(0XC0);
for(i=0;i<4;i++)
{
k[i]=key();
data(k[i]);
}
cmd(0X01);
for(i=0;i<4;i++)
{
if(j[i]==k[i])
{
l++;
}
}
if(l==4)
{
l=0;
display("APPROVED");
cmd(0X01);
display("Payment");
cmd(0XC0);
o=rec();
data(o);
o=o-48;
p=rec();
data(p);
p=p-48;
q=rec();
data(q);
q=q-48;
cmd(0X01);
display("Balance");
cmd(0XC0);
x=(o*100)+(p*10)+q;	
x=x-300;
o=x/100+48;
data(o);
p=(x%100)/10+48;
data(p);
q=x%10+48;
data(q);
IO0CLR=0X00FF0000;
IO0SET=0X00500000;
delay2();
IO0CLR=0X00FF0000;
IO0SET=0X00000000;
delay2();
IO0CLR=0X00FF0000;
IO0SET=0X00600000;
delay2();
IO0CLR=0X00FF0000;
IO0SET=0X00000000;
cmd(0X01);
}
else
{
display("DENIED");
cmd(0X01);
}
}
}
}
char rec()
{
while((U0LSR&0X01)==0);
return(U0RBR);
}
char key()
{
int e;
while(1)
{
IO1CLR=0XFFFFFFFF;
IO1SET=0X007F0000;
e=IO1PIN&0X000F0000;
switch(e)
{  
case 0X00070000:return('1');break;
case 0X000B0000:return('2');break;
case 0X000D0000:return('3');break;
case 0X000E0000:return('4');break;
}
IO1CLR=0XFFFFFFFF;
IO1SET=0X00BF0000;
e=IO1PIN&0X000F0000;
switch(e)
{
case 0X00070000:return('5');break;
case 0X000B0000:return('6');break;
case 0X000D0000:return('7');break;
case 0X000E0000:return('8');break;
}
IO1CLR=0XFFFFFFFF;
IO1SET=0X00DF0000;
e=IO1PIN&0X000F0000;
switch(e)
{
case 0X00070000:return('9');break;
case 0X000B0000:return('A');break;
case 0X000D0000:return('B');break;
case 0X000E0000:return('C');break;
}
IO1CLR=0XFFFFFFFF;
IO1SET=0X00EF0000;
e=IO1PIN&0X000F0000;
switch(e)
{
case 0X00070000:return('D');break;
case 0X000B0000:return('E');break;
case 0X000D0000:return('F');break;
case 0X000E0000:return('G');break;
}
}
}
void cmd(int c)
{
IO0CLR=0XFFFFFFFF;
IO0SET=c<<4;
IO0SET=0X00002000;
delay();
IO0CLR=0X00002000;
}
void data(char d)
{
IO0CLR=0XFFFFFFFF;
IO0SET=d<<4;
IO0SET=0X00003000;
delay();
IO0CLR=0X00002000;
}
void delay()
{
int i,j;
for(i=0;i<1000;i++)
for(j=0;j<1000;j++);
}
void delay2()
{
int i,j;
for(i=0;i<3000;i++)
for(j=0;j<3000;j++);
}
void display(const char *p)
{
while(*p!='\0')
{
data(*p);
p++;
}
}