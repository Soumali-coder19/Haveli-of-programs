#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,A[500][500],num,temp;
	printf("\nEnter a number below 50(pawsitive) plixx : "); 
	scanf("%d",&num);
	temp=2*num-1;
	for(i=0;i<temp;i++)
	{
		for(j=i;j<=temp-1-i;j++)           //condition for j for 1st row
		{
			A[i][j]=num;
		}
		for(j=i+1;j<=temp-1-i;j++)       //condition for j for n-1th column
		{
			A[j][temp-i-1]=num;
		}
		for(j=temp-i-2;j>=i;j--)   //condition for j for n-1th row
		{
			A[temp-i-1][j]=num;
		}
		for(j=temp-i-2;j>i;j--)    //condition for j for 1st column
		{
			A[j][i]=num;
		}
		num--;
	}
	
	for(i=0;i<temp;i++)  //print array
	{
		for(j=0;j<temp;j++)
		{
			printf("%d\t",A[i][j]);  
		}
		printf("\n");        //
	}
	return 0;
	
}
