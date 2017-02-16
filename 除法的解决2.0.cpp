#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;
int main()
{

	srand((unsigned)time(NULL));
	
	int d[4];
	
	int c[5]={0},j,ch;

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
    
	int ans,fenmu=1,fenzi;
	for(j=0;j<3;j++)
	{
		if(c[j]==45)
		{
			d[j+1]=-d[j+1];
			c[j]=43;
		}
	}
	for(j=0;j<3;j++) 
	{
		int k;
			if(c[j]==42)
		    {
		        d[j+1]=d[j]*d[j+1];
			    d[j]=0;
		    }
			
			if(c[j]==47)
		    {   
			    if(d[j+1]<d[j] && d[j]%d[j+1]==0)			   
			    {
			   	  d[j+1]=d[j]/d[j+1];
				  d[j]=0;	  
			    }
			    else
			    {
			        fenzi=d[j];
					if(c[0]==47&&c[2]==47)
					{
						fenzi=d[0]*d[3]+d[2]*d[1];
						fenmu=d[1]*d[3];
					}
					for(k=j;k<3;k++)
					{
						if(c[k]==47)fenmu*=d[k+1];
						if(c[k+1]==42)
						{
						    fenzi*=d[k+2];
						    if(c[k+2]==42)fenzi*=d[k+3];
						}
					}
					if(j!=0)fenzi=fenzi+d[0]*fenmu;
					for(j=0;j<3;j++)
					{
						if(c[j]==43)
						{
							fenzi=fenzi+d[j+1]*fenmu;
						}
					}
					int r=1,t,x=fenzi,y=fenmu;
					if(x>y){t=x;x=y;y=t;}
					while(r!=0)
					{
						r=y%x;
						y=x;
						x=r;
					}
					fenzi=fenzi/y;
					fenmu=fenmu/y;
					break;		
					//r=gcd(fenzi,fenmu);
					//fenzi=fenzi/r;fenmu=femn/r;	 	
				}
		    } 	   
	} 
	ans=d[0]+d[1]+d[2]+d[3];
    if(c[0]=='/'||c[1]=='/'||c[2]=='/')
	{
		if(fenmu==1)cout<<ans<<endl;
	    else if(fenzi%fenmu==0)                                               //结果不一定有除号 ，可能是整数 
            cout<<fenzi/fenmu<<endl;
        else
		{
			cout<<fenzi<<'/'<<fenmu<<endl;
		}         	        
    }
    else
        {cout<<ans<<endl;}
	return 0;
	
	
}
