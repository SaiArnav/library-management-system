#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "issue.h"
#include "fine.h"

// External Variables
extern IssueRecord* issues;
extern int issueCount;
extern int issueCapacity;

extern int nextIssueId;

extern Book* books;
extern int bookCount;

extern Member* members;
extern int memberCount;

// Recommendation Function
extern void suggestBooksSimilarToReturnedBook(int returnedBookId);

void issueBook() {

    int bookId;
    int memberId;
    int dueDays;

    printf("\n===== ISSUE BOOK =====\n");

    printf("Enter Book ID: ");
    scanf("%d", &bookId);

    printf("Enter Member ID: ");
    scanf("%d", &memberId);

    printf("Enter Due Days: ");
    scanf("%d", &dueDays);

    int bookIndex = findBookIndexById(bookId);

    if(bookIndex == -1) {

        printf("Book not found!\n");
        return;
    }

    if(books[bookIndex].isIssued == 1) {

        printf("Book already issued!\n");
        return;
    }

    int memberIndex = findMemberIndexById(memberId);

    if(memberIndex == -1) {

        printf("Member not found!\n");
        return;
    }

    if(issueCount >= issueCapacity) {

        issueCapacity *= 2;

        issues = realloc(
                    issues,
                    issueCapacity * sizeof(IssueRecord)
                 );

        if(issues == NULL) {

            printf("Memory Allocation Failed!\n");
            return;
        }
    }

    IssueRecord newIssue;

    newIssue.issueId = nextIssueId++;

    newIssue.bookId = bookId;

    newIssue.memberId = memberId;

    newIssue.isssueDate = time(NULL);

    newIssue.dueDate =
        newIssue.isssueDate + (dueDays * 24 * 60 * 60);

    newIssue.returnDate = 0;

    newIssue.fine = 0;

    newIssue.isReturned = 0;

    issues[issueCount++] = newIssue;

    books[bookIndex].isIssued = 1;

    printf("\nBook Issued Successfully!\n");

    printf("Issue ID : %d\n", newIssue.issueId);

    printf("Book     : %s\n",
           books[bookIndex].title);

    printf("Member   : %s\n",
           members[memberIndex].name);

    printf("Due Date : %s",
           ctime(&newIssue.dueDate));

    saveIssuesToFile();
}

void returnBook() {

    int issueId;

    printf("\n===== RETURN BOOK =====\n");

    printf("Enter Issue ID: ");
    scanf("%d", &issueId);

    int issueIndex = findIssueIndexById(issueId);

    if(issueIndex == -1) {

        printf("Issue Record Not Found!\n");
        return;
    }

    if(issues[issueIndex].isReturned == 1) {

        printf("Book already returned!\n");
        return;
    }

    time_t now = time(NULL);

    issues[issueIndex].returnDate = now;

    issues[issueIndex].isReturned = 1;

    double seconds =
        difftime(now, issues[issueIndex].dueDate);

    if(seconds > 0) {

        int days =
            (int)(seconds / (60 * 60 * 24));

        issues[issueIndex].fine = days * 2;
    }
    else {

        issues[issueIndex].fine = 0;
    }

    int bookIndex =
        findBookIndexById(issues[issueIndex].bookId);

    if(bookIndex != -1) {

        books[bookIndex].isIssued = 0;
    }

    printf("\nBook Returned Successfully!\n");

    printf("Fine Amount : Rs. %.0f\n",
           issues[issueIndex].fine);

    suggestBooksSimilarToReturnedBook(
        issues[issueIndex].bookId
    );

    saveIssuesToFile();
}

void listIssuedBooks() {

    int found = 0;

    printf("\n===== CURRENTLY ISSUED BOOKS =====\n");

    for(int i = 0; i < issueCount; i++) {

        if(issues[i].isReturned == 0) {

            int bookIndex =
                findBookIndexById(issues[i].bookId);

            int memberIndex =
                findMemberIndexById(issues[i].memberId);

            printf("\nIssue ID : %d\n",
                   issues[i].issueId);

            printf("Book     : %s\n",
                   books[bookIndex].title);

            printf("Member   : %s\n",
                   members[memberIndex].name);

            printf("Due Date : %s",
                   ctime(&issues[i].dueDate));

            printf("-----------------------------\n");

            found = 1;
        }
    }

    if(!found) {

        printf("No Books Currently Issued.\n");
    }
}

void overdueReport() {

    time_t now = time(NULL);

    int found = 0;

    printf("\n===== OVERDUE BOOKS REPORT =====\n");

    for(int i = 0; i < issueCount; i++) {

        if(issues[i].isReturned == 0 &&
           now > issues[i].dueDate) {

            double seconds =
                difftime(now, issues[i].dueDate);

            int days =
                (int)(seconds / (60 * 60 * 24));

            int fine = days * 2;

            int bookIndex =
                findBookIndexById(issues[i].bookId);

            int memberIndex =
                findMemberIndexById(issues[i].memberId);

            printf("\nIssue ID      : %d\n",
                   issues[i].issueId);

            printf("Book          : %s\n",
                   books[bookIndex].title);

            printf("Member        : %s\n",
                   members[memberIndex].name);

            printf("Overdue Days  : %d\n", days);

            printf("Fine          : Rs. %d\n",
                   fine);

            printf("-----------------------------\n");

            found = 1;
        }
    }

    if(!found) {

        printf("No Overdue Books.\n");
    }
}
