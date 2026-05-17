#ifndef ISSUE_H
#define ISSUE_H

struct Date {

    int day;
    int month;
    int year;
};

struct Issue {

    int bookId;
    int memberId;

    struct Date issueDate;
    struct Date dueDate;
};

void issueBook();
void returnBook();
void viewIssuedBooks();

#endif