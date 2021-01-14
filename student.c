#include <stdio.h>
#include <string.h>


// student structure
//struct Student...
struct Student {
  char first[50];
  char last[50];
  int age;
  int id;
};

void printStudent(struct Student* student)
{
  printf("---- student ----\n");
  printf("Student first name: %s\n", student->first);
  printf("Student last name: %s\n", student->last);
  printf("Age: %d\n", student->age);
  printf("id: %d", student->id);
}


void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students

  for(int i=0; i<num; i++){
    printStudent(students[i]);

  }
}


int main()
{

  // an array of students
  //xxx students;

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
      char input[256];
      char first[50];
      char last[50];
      int age;
      int id;
      struct Student numStudents;
      printf("First name: \n");
      fgets(input, 256, stdin);
      sscanf(input, "%s", first);
      printf("Last name: \n");
      fgets(input, 256, stdin);
      sscanf(input, "%s", last);
      printf("Enter age: \n");
      fgets(input, 256, stdin);
      sscanf(input, "%d", &age);
      printf("Enter id: \n");
      fgets(input, 256, stdin);
      sscanf(input, "%d", &id);
      strcpy(numStudents.first, first);
      strcpy(numStudents.last, last);
      numStudents.age = age;
      numStudents.id = id;


      numStudents++;
    }
  }
  
  printf("\nGoodbye!\n");
}
