#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;
int main()
{

	srand((unsigned)time(NULL));
	
	int d[4];
	
	int c[3],j,ch;

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
    
	int ans,fenmu=1;
	
	for(j=0;j<3;j++) 
	{
		int k;
		for(k=0;;k++)
		{
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
			       	fenmu*=d[j+1];
					ch=j;
					switch(ch)
					{
						case 0: d[2]*=fenmu;d[3]*=fenmu;break;
						case 1: d[0]*=fenmu;d[3]*=fenmu;break;
						case 2: d[0]*=fenmu;d[1]*=fenmu;break;
					}
					
					d[j+1]=d[j];
					d[j]=0;	
				}
		    } 
		    
			if(c[j]==45)
			
			d[j+1]=-d[j+1];
			
			ans=d[0]+d[1]+d[2]+d[3]; 
		    
			if(abs(ans)<1)break;
		    
			if(ans==int(ans))break;
		}  
	} 
	
    if(c[0]=='/'||c[1]=='/'||c[2]=='/')
        cout<<ans<<'/'<<fenmu<<endl;
    else
        cout<<ans<<endl;
	return 0;
	
	
}
