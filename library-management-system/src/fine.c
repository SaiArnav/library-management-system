#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fine.h"

extern IssueRecord* issues;
extern int issueCount;

extern Book* books;
extern int bookCount;

extern Member* members;
extern int memberCount;

void memberReport() {

    printf("\n===== MEMBER REPORT =====\n");

    if(memberCount == 0) {

        printf("No Members Registered.\n");
        return;
    }

    for(int i = 0; i < memberCount; i++) {

        double totalFine = 0;

        for(int j = 0; j < issueCount; j++) {

            if(issues[j].memberId ==
               members[i].id) {

                totalFine += issues[j].fine;
            }
        }

        printf("\nMember ID   : %d\n",
               members[i].id);

        printf("Name        : %s\n",
               members[i].name);

        printf("Email       : %s\n",
               members[i].email);

        printf("Total Fine  : Rs. %.0f\n",
               totalFine);

        printf("----------------------------\n");
    }
}

void fineReport() {

    printf("\n===== FINE REPORT =====\n");

    int found = 0;

    for(int i = 0; i < issueCount; i++) {

        if(issues[i].fine > 0) {

            int bookIndex =
                findBookIndexById(
                    issues[i].bookId
                );

            int memberIndex =
                findMemberIndexById(
                    issues[i].memberId
                );

            printf("\nIssue ID    : %d\n",
                   issues[i].issueId);

            printf("Book        : %s\n",
                   books[bookIndex].title);

            printf("Member      : %s\n",
                   members[memberIndex].name);

            printf("Fine Amount : Rs. %.0f\n",
                   issues[i].fine);

            printf("-------------------------\n");

            found = 1;
        }
    }

    if(!found) {

        printf("No Fine Records Found.\n");
    }
}
