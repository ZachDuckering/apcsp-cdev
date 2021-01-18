//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";


// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args
  students[numStudents] = (Student*)malloc(sizeof(Student));
  students[numStudents]->firstName = (char*)malloc(strlen(fname));
  students[numStudents]->lastName = (char*)malloc(strlen(lname));
  strcpy(students[numStudents]->firstName, fname);
  strcpy(students[numStudents]->lastName, lname);
  students[numStudents]->age = age;
  students[numStudents]->id = id;
  numStudents++;
}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
  free(student->firstName);
  free(student->lastName);
  free(student);
}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting the pointer
  // values to 0 and adjusting the numStudents to 0
  for(int i=0; i<numStudents; i++){
    deleteStudent(students[i]);
    students[i] = 0;
  }

  numStudents = 0;
}


void saveStudents(int key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532 
  char str[600];
  FILE* fp;
  fp = fopen(STUFILE, "w");
  if (fp){
    for(int i = 0; i < numStudents; i++){
      sprintf(str, "%s %s %d %ld", students[i]->firstName, students[i]->lastName, students[i]->age, students[i]->id);
      caesarEncrypt(str, key);
      fprintf(fp, "%s\n", str);
      printf("Saving: %s\n", str);
    }
    printf("Saved %d students", numStudents);
    fclose(fp);
  }


}


void loadStudents(int key)
{
  // load the students from the data file overwriting all exisiting students in memory

  // because the number and size of the students in memory might not match the file,
  // we have to remove all students and start all over from the file to
  // avoid going beyond what was allocated with malloc
  char str1[256];
  char str2[256];
  char str3[10];
  char str4[20];
  char str[600];
  const int BUFFSIZE = 256;
  char fname[BUFFSIZE];
  char lname[BUFFSIZE];
  unsigned int age;
  long id;
  FILE* fp;

  fp = fopen(STUFILE, "r");
  deleteStudents();
  if (fp){
    while (1){
      if(fscanf(fp, "%s %s %s %s\n", str1, str2, str3, str4) == 4){
        sprintf(str, "%s %s %s %s", str1, str2, str3, str4);
        caesarDecrypt(str, key);
        if(sscanf(str, "%s %s %d %ld", fname, lname, &age, &id) == 4){
          createStudent(fname, lname, age, id);
        }else{
           break;
        }
      }else{
         break;
      }
    }
    fclose(fp);
  }


}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




