#ifndef ISSUE_H
#define ISSUE_H

#include "library.h"

// Issue Functions
void issueBookToMember();
void returnBookFromMember();
void showCurrentlyIssuedBooks();
void showOverdueBooksReport();

// Helper Functions
int findIssueIndexById(int issueId);
void saveIssuesToFile();

#endif
