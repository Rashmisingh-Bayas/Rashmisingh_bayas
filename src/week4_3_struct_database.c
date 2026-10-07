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
}
