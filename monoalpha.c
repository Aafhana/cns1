#include <stdio.h>
#include <string.h>
#include<ctype.h>

void main()
{
  char pt[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  char ct[26] = {'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'};
  char p[20] = {'\0'}, c[20] = {'\0'}, r[20] = {'\0'};
  
  int i, j;
  printf("\nEnter plain text: ");
  scanf("%s",p);
  for(i=0; i<strlen(p);i++)
  {
    for(j=0; j<26; j++)
    {
      if(toupper(p[i]) == pt[j])
      c[i] = ct[j];
    }
  }
  
  printf("\nCipher text: %s",c);
  for(i=0; i<strlen(c);i++)
  {
    for(j=0; j<26; j++)
    {
      if(toupper(c[i]) == ct[j])
      r[i] = pt[j];
    }
  }
  printf("\nPlain text is: %s",r);
  printf("\n");
}