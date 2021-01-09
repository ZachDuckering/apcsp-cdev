#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);

  float d;
  float e;

  d = 3.6;
  e = 2.1;


  float* ptrtod;
  float* ptrtoe;

  ptrtod = &d;
  ptrtoe = &e;



  printf("The the value of ptrtod is %p\n", (void*)ptrtod);
  printf("It stores the value of %f\n", *ptrtod);
  printf("The address of d is %p\n", (void*)&d);

  printf("The the value of ptrtoe is %p\n", (void*)ptrtoe);
  printf("It stores the value of %f\n", *ptrtoe);
  printf("The address of e is %p\n", (void*)&e);


  float z = *ptrtod;
  float* ptrtoz = &z;

  *ptrtod = *ptrtoe;
  *ptrtoe = *ptrtoz;

  printf("The value of ptrtod is %p\n", (void*)ptrtod);
  printf("It stores the value of %f\n", *ptrtod);

  printf("The value of ptrtoe is %p\n", (void*)ptrtoe);
  printf("It stores the value of %f\n", *ptrtoe);



}
