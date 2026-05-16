/* issue.c */

#include <stdio.h>
#include "issue.h"

void issueBook() {
    printf("\n+----------------------------------------+\n");
    printf("|           ISSUE BOOK MODULE            |\n");
    printf("+----------------------------------------+\n");
    printf("| Book issued successfully!              |\n");
    printf("+----------------------------------------+\n\n");
}

void returnBook() {
    printf("\n+----------------------------------------+\n");
    printf("|          RETURN BOOK MODULE            |\n");
    printf("+----------------------------------------+\n");
    printf("| Book returned successfully!            |\n");
    printf("+----------------------------------------+\n\n");
}

void listIssuedBooks() {
    printf("\n+----------------------------------------+\n");
    printf("|          ISSUED BOOKS LIST             |\n");
    printf("+----------------------------------------+\n");
    printf("| 1. C Programming                       |\n");
    printf("| 2. Data Structures                     |\n");
    printf("| 3. Operating Systems                   |\n");
    printf("+----------------------------------------+\n\n");
}