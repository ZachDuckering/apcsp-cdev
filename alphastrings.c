#include <stdio.h>
#include <string.h>

int main(){
  char str1[27];
  char str2[27]="abcdefghijklmnopqrstuvwxyz";
  char str3[53];

  for (int i=0; i<26; i++){
  str1[i] = 97+i;
  }
  str1[27]=0;
  printf("str1: %s\n", str1);
  printf("str2: %s\n", str2);

  if (strcmp(str1, str2) == 0)
    printf("str1 and str2 are the same\n");
  else
    printf("str1 and str2 are different\n");
  for (int i=0; i<26; i++){
  str2[i]-=32;
  }
  printf("str1: %s\n", str1);
  printf("str2: %s\n", str2);

  if (strcmp(str1, str2) == 0)
    printf("str1 and str2 are the same\n");
  else
    printf("str1 and str2 are different\n");

  strcpy(str3, str1);
  strcat(str3, str2);
  printf("str3: %s\n", str3);

}
