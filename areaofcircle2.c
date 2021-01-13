#include <stdio.h>
#include <math.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%d", b);
  }
}



// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main

float areaOfCircle(int rad){
  return (rad * rad * M_PI);
}


int main(int argc, char* argv[]) 
{
  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2
//  float start = 5.2;
//  int reps = upper - lower + 1;
  
  // for testing only - do not change
//  getTestInput(argc, argv, &start, &reps);

//  printf("calculating area of circle starting at %f, and ending at %f\n", start, start+reps-1);
  
  // add your code below to call areaOfCircle function with values between
  // start and end

//for (int i = 0; i < reps; i++){
  //int radius = lower + i;
  //printf("Area of circle with radius %d is: %d\n", lower, areaOfCircle(lower));
//}
char input[256];
int lower;
int upper;

if(argc == 3){
  if(sscanf(argv[1], "%d", &lower) == 1 && sscanf(argv[2], "%d", &upper) == 1){
    int reps = upper-lower+1;
    for (int i = 0; i < reps; i++){
      int radius = lower + i;
      printf("Area of circle with radius %d is: %f\n", radius, areaOfCircle(radius));
    }
  }else{
    printf("Not a valid number\n");
  }
}


if(argc<3 || argc>3){
  printf("input lower: \n");

  while (1){
    fgets(input, 256, stdin);
    if(sscanf(input, "%d", &lower) == 1) break;
    printf("Not a valid number\n");
  }
  printf("input upper: \n");

  while (1){
    fgets(input, 256, stdin);
    if((sscanf(input, "%d", &upper) == 1) && upper>=lower) break;
      printf("Not a valid number\n");
  }

  printf("%d\n", lower);
  printf("%d\n", upper);

  int reps = upper - lower + 1;
  for (int i = 0; i < reps; i++){
    int radius = lower + i;
    printf("Area of circle with radius %d is: %f\n", radius, areaOfCircle(radius));
  }



}

  
}
