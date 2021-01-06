#include<stdio.h>

int main()
{
  int a = 545;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));

  unsigned int b = 545;

  // print value and size of an unsigned int variable
  printf("unsigned int b value: %d and size: %lu bytes\n", b, sizeof(b));

  long int c = 545;

  // print value and size of a long int variable
  printf("long int c value: %d and size: %lu bytes\n", c, sizeof(c));

  char d = 'd';

  // print value and size of a char variable
  printf("char d value: %d and size: %lu bytes\n", d, sizeof(d));

  float e = 1.23;

  // print value and size of a float variable
  printf("float e value: %d and size: %lu bytes\n", e, sizeof(e));

  double f = 1.234;

  // print value and size of a double float variable
  printf("double float f value: %d and size: %lu bytes\n", f, sizeof(f));

}
