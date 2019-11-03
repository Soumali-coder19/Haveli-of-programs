#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int main()
{
	char str[1000];
	int count[10]={0},c=0,x;
	printf("Enter string:");
	scanf("%s",&str);
	while(str[c]!='\0')
	{
		if(str[c]>='0' && str[c]<='9'){
		    x=str[c]-'0';
			count[x]++;	
		}
	c++;		
	}
	
	printf("Reqd array\n");
	for(c=0;c<10;c++)
	{
		printf("%d ",count[c]);
	}
	
	getch();
	return 0;
}
