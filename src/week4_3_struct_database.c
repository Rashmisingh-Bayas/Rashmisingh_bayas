<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>  // For malloc and free
#include <string.h>  // For strcpy (not strictly needed here if using scanf, but good practice)

// Define the struct globally
struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  int n;
  printf("Enter number of students: ");

  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid number.\n");
    return 1;
  }

  // Allocate memory for an array of n Students
  struct Student* students =
      (struct Student*)malloc(n * sizeof(struct Student));

  if (students == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }

  // Read data for each student
  for (int i = 0; i < n; i++) {
    printf("Enter data for student %d: ", i + 1);
    // scanf returns the number of successfully read items. We need 3.
    if (scanf("%s %d %f", students[i].name, &students[i].id,
              &students[i].grade) != 3) {
      printf("Invalid input.\n");
      free(students);  // Free memory before exiting
      return 1;
    }
  }

  // Print an empty line before the table
  printf("\n");

  // Print the table header with exact spacing
  printf("%-6s %-11s %s\n", "ID", "Name", "Grade");

  // Print each student's row with exact spacing
  for (int i = 0; i < n; i++) {
    printf("%-6d %-11s %.1f\n", students[i].id, students[i].name,
           students[i].grade);
  }

  // Free the dynamically allocated memory
  free(students);
  return 0;
=======
/*
 * week4_3_struct_database.c
 * Author: [Your Name]
 * Student ID: [Your ID]
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Use malloc to allocate space for n Student records,
 *   read each record from the user, print them as a table,
 *   and then free the memory.
 *
 *   Output must match the format in the Week 4 instructions exactly
 *   (it is checked by the autograder).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Define struct Student with fields name (char[50]), id (int), grade (float)
//       (same definition as in Task 2)

int main(void) {
    int n;
    struct Student *students = NULL;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    // TODO: Allocate memory for n Student structs using malloc
    //       Example: students = malloc(n * sizeof(struct Student));

    // TODO: Check allocation success
    // If students is NULL: print "Memory allocation failed." and return 1

    // TODO: Read student data in a loop. For student i (counting from 1):
    //       print "Enter data for student %d: ", then read
    //       name (scanf("%49s", ...)), id and grade.
    //       If a value cannot be read: print "Invalid input.",
    //       free the array and return 1

    // TODO: Print an empty line, then the table:
    //       printf("%-6s %-11s %s\n", "ID", "Name", "Grade");
    //       and for each student:
    //       printf("%-6d %-11s %.1f\n", id, name, grade);

    // Optional (not autograded): after the table, print the average
    // grade or the top student

    // TODO: Free allocated memory
    (void)students;  // remove this line once you use students

    return 0;
>>>>>>> e8e7440f80c47790c60ade84f408eb29becd396b
}
