#include <stdio.h>
#include <stdlib.h>
#include "issue.h"
#include "fine.h"

void issueBook() {

    FILE *file;

    struct Issue issue;

    file = fopen("data/issued.dat", "ab");

    if(file == NULL) {

        printf("File Error!\\n");
        return;
    }

    printf("\\n===== ISSUE BOOK =====\\n");

    printf("Enter Book ID: ");
    scanf("%d", &issue.bookId);

    printf("Enter Member ID: ");
    scanf("%d", &issue.memberId);

    printf("Enter Issue Date (DD MM YYYY): ");
    scanf("%d%d%d",
          &issue.issueDate.day,
          &issue.issueDate.month,
          &issue.issueDate.year);

    printf("Enter Due Date (DD MM YYYY): ");
    scanf("%d%d%d",
          &issue.dueDate.day,
          &issue.dueDate.month,
          &issue.dueDate.year);

    fwrite(&issue, sizeof(issue), 1, file);

    fclose(file);

    printf("\\nBook Issued Successfully!\\n");
}

void returnBook() {

    int bookId;
    int returnDay;
    int fine;

    FILE *file;

    struct Issue issue;

    file = fopen("data/issued.dat", "rb");

    if(file == NULL) {

        printf("No issued books found!\\n");
        return;
    }

    printf("\\n===== RETURN BOOK =====\\n");

    printf("Enter Book ID: ");
    scanf("%d", &bookId);

    printf("Enter Return Day: ");
    scanf("%d", &returnDay);

    while(fread(&issue, sizeof(issue), 1, file)) {

        if(issue.bookId == bookId) {

            fine = calculateFine(issue.dueDate.day,
                                 returnDay);

            printf("\\nBook Returned Successfully!\\n");

            printf("Fine Amount: ₹%d\\n", fine);

            break;
        }
    }

    fclose(file);
}

void viewIssuedBooks() {

    FILE *file;

    struct Issue issue;

    file = fopen("data/issued.dat", "rb");

    if(file == NULL) {

        printf("No issued books found!\\n");
        return;
    }

    printf("\\n===== ISSUED BOOKS =====\\n");

    while(fread(&issue, sizeof(issue), 1, file)) {

        printf("\\nBook ID: %d\\n", issue.bookId);

        printf("Member ID: %d\\n", issue.memberId);

        printf("Issue Date: %d/%d/%d\\n",
               issue.issueDate.day,
               issue.issueDate.month,
               issue.issueDate.year);

        printf("Due Date: %d/%d/%d\\n",
               issue.dueDate.day,
               issue.dueDate.month,
               issue.dueDate.year);
    }

    fclose(file);
}