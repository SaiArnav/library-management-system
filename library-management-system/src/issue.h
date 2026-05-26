#ifndef ISSUE_H
#define ISSUE_H

#include "library.h"

void issueBook();
void returnBook();
void listIssuedBooks();
void overdueReport();

int findIssueIndexById(int issueId);
void saveIssuesToFile();

#endif
