#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;
int main()
{

	srand((unsigned)time(NULL));
	
	int d[5];
	
	int c[4]={0},j,ch;

	d[0]=rand()%10+1;                      //整数数字随机函数 

	d[1]=rand()%10+1;

	d[2]=rand()%10+1;

	d[3]=rand()%10+1;

	    for(j=0;;j++)                         //+，-，*，/的随机 

	    {

		    c[0]=rand()%6+42;

		    if(c[0]!=44&&c[0]!=46)break;

	    }

	    for(j=0;;j++)

	    {

		    c[1]=rand()%6+42;

		    if(c[1]!=44&&c[1]!=46)break;

	    }

	    for(j=0;;j++)

	    {

		    c[2]=rand()%6+42;

		    if(c[2]!=44&&c[2]!=46)break;

	    }
	cout<<d[0]<<char(c[0])<<d[1]<<char(c[1])<<d[2]<<char(c[2])<<d[3]<<'='<<endl;
	
	for(j=0;j<3;j++)
	{
		if(c[j]==45)  // '-'
		{
			d[j+1]=-d[j+1];
			c[j]=43;
		}
	}
	
	int fenzi=0,fenmu=1,ans,flag=0;
	
	for(j=1;j<3;j++)
	    if(c[j]==42 && c[j-1]==47)
	     	{
	     	    flag=1;
				ch=j;	
			}
	
	for(j=0;j<3;j++)
	{
		
		if(c[0]==47&&c[2]==47&&c[1]==43)
		{
			fenzi=d[0]*d[3]+d[2]*d[1];
			fenmu=d[1]*d[3];
		    c[1]=0;
			break;
		}
		if(c[j]==42)
		    {
		    	d[j+1]*=d[j];
		    	d[j]=0;
		    	c[j]=43;
			}
		
		if(c[j]==47)
		{
			fenzi=d[j];
			fenmu*=d[j+1];
			d[j+1]=d[j];
			d[j]=0;
		}
    }
	
	if(flag==1)
		d[ch+1]=0;
	
	for(j=0;j<3;j++)
	{	
		if(c[j]==43)
			{
				if(j==0)
				    fenzi+=d[0]*fenmu;
				fenzi+=d[j+1]*fenmu;			
			}		
	}
	
	if(fenzi%fenmu==0)                                               //结果不一定有除号 ，可能是整数 
        
		cout<<fenzi/fenmu<<endl;
    else
	{
		cout<<fenzi<<'/'<<fenmu<<endl;
    }
}
	
	
