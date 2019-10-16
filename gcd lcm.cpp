#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n1,n2,prod,gcd,lcm;
	printf("Enter 1st number:");
	scanf("%d",&n1);
	printf("Enter the 2nd number:");
	scanf("%d",&n2);
	prod=n1*n2;
	while(n1!=n2)
	{
	 if(n1>n2)
	  n1=n1-n2;
	if(n2>n1)
	  n2=n2-n1;	
	}
	gcd=n1;
	lcm=prod/gcd;
	printf("GCD=%d",gcd);
	printf("LCM=%d",lcm);
	return 0;
}
