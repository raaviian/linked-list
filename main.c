  #include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
  int id;
  char name[20];
  double cpa;
  struct Student *nextPtr;

} * head;
struct Student *start = NULL;

void insertNode(int id, char *name, double cpa) {

  struct Student *student = (struct Student *)malloc(sizeof(struct Student));
  student->id = id;
  strcpy(student->name, name);
  student->cpa = cpa;
  student->nextPtr = NULL;

  if (head == NULL) {
    // if head is NULL
    // set student as the new head
    head = student;
  } else {
    // if list is not empty
    // insert student in beginning of head
    student->nextPtr = head;
    head = student;
  }
}

void deleteNode(int id) {
  struct Student *temp1 = head;
  struct Student *temp2 = head;
  while (temp1 != NULL) {

    if (temp1->id == id) {

      printf("Record with ID %d Found !!!\n", id);

      if (temp1 == temp2) {
        // this condition will run if
        // the record that we need to delete is the first node
        // of the linked list
        head = head->nextPtr;
        free(temp1);
      } else {
        // temp1 is the node we need to delete
        // temp2 is the node previous to temp1
        temp2->nextPtr = temp1->nextPtr;
        free(temp1);
      }

      printf("Record Successfully Deleted !!!\n");
      return;
    }
    temp2 = temp1;
    temp1 = temp1->nextPtr;
  }
  printf("Student with ID %d is not found !!!\n", id);
}

void displaylist() {
  struct Student *temp = head;

  while (temp != NULL) {

    printf("\n\t\tStudent ID : %d", temp->id);
    printf("\n\t\tStudent Name : %s", temp->name);
    printf("\n\t\tCPA: %.2lf", temp->cpa);
    temp = temp->nextPtr;
  }
}

int main() {
  head = NULL;
  int choice;
  char name[20];
  int id;
  double cpa;
  char username[15];
  char password[12];
  int ans;

  printf("\n\t\tSTUDENT INFORMATION SYSTEM");

  printf("\n\n\t\tPress enter to continue [ENTER]:");
  char enter = 0;
  while (enter != '\r' && enter != '\n') {
    enter = getchar();
  }
  printf("\n\t\tLoading..");
  sleep(1);
  printf("\n\t\t.............");
  sleep(1);
  printf("\n\t\t.............");
  sleep(1);

  printf("ADMIN LOGIN PAGE");

  printf("\n\t\tEnter your username : ");
  scanf("%s", &username);

  printf("\n\t\tEnter your password : ");
  scanf("%s", &password);

  if (((strcmp(username, "admin1") == 0) && (strcmp(password, "1234") == 0)) ||
      ((strcmp(username, "admin") == 0) && (strcmp(password, "0000") == 0))) {
    do {

      printf("\n\t\t1.Insert New Student Info");
      printf("\n\t\t2.Delete existing entry");
      printf("\n\t\t3.Display all data");

      printf("\n\t\tEnter a Choice: ");
      scanf("%d", &choice);
      switch (choice) {
      case 1: {
        printf("\n\t\tEnter Student name : ");
        scanf("%s", name);
        // fgets(name, sizeof(name), stdin);
        printf("\n\t\tEnter Student ID: ");
        scanf("%d", &id);
        printf("\n\t\tEnter CPA: ");
        scanf("%lf", &cpa);
        insertNode(id, name, cpa);
        printf("\n\t\tSaving Record....");
        sleep(1);
        printf("\n\t\t.........");
        sleep(1);
        printf("\n\t\t.........");
        sleep(1);
        printf("\n\t\tRecord has been saved");
        displaylist();
        break;
      }
      case 2: {
        printf("Enter Student ID to delete: ");
        scanf("%d", &id);
        deleteNode(id);
        displaylist();
        break;
      }
      case 3: {
        displaylist();
        break;
      }
      }
      printf("\nDo you want to continue using the program? [1 to continue / 2 "
             "to exit ] : ");
      scanf("%d", &ans);

    } while (ans == 1);
    printf("Thank you!");
  }
  return 0;
}