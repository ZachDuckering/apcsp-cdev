#include <stdio.h>
#include <string.h>


int getInputNumber(){
  char input[256];
  int num;
  while (1){
    fgets(input, 256, stdin);
    if (sscanf(input, "%ud", &num) == 1 && num >= 0) break;
    printf("Not a valid number try again");

  }
  return num;

}


// student structure
//struct Student...
struct Student {
  char firstName[20];
  char lastName[20];
  unsigned int age;
  long id;
};

void printStudent(struct Student* student)
{
  printf("---- student ----\n");
  printf("Student name: %s %s\n", student->firstName, student->lastName);
  printf("Age: %d\n", student->age);
  printf("id: %d", student->id);
}


void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students

  for(int i=0; i<num; i++){
    printStudent(&students[i]);

  }
}


int main()
{
  char input[256];
  // an array of students
  //xxx students;
  struct Student students[10];
  int numStudents = 0;
  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
      printf("First name: \n");
      fgets(input, 256, stdin);
      sscanf(input, "%s", students[numStudents].firstName);
      printf("Last name: \n");
      fgets(input, 256, stdin);
      sscanf(input, "%s", students[numStudents].lastName);
      printf("Enter age: \n");
      students[numStudents].age = getInputNumber();
      printf("Enter id: \n");
      students[numStudents].id = getInputNumber();



      numStudents++;
    }
  }
  
  printf("\nGoodbye!\n");
}
