#include <stdio.h>
 
int main()
{
   char text[100], blank[100];
   int a = 0, b = 0;
 
   printf("Enter a string:");
   gets(text);
 
   while (text[a] != '\0')
   {
      if (!(text[a] == ' ' && text[a+1] == ' ')) {
        blank[b] = text[a];
        b++;
      }
      a++;
   }
 
   blank[b] = '\0';
 
   printf("String after removing extra white spaces:%s", blank);
 
   return 0;
}
