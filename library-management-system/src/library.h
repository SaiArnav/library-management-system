#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define MAX_GENRE 50
#define MAX_NAME 100
#define MAX_EMAIL 15

typedef struct {
  int id;
  char title[MAX_TITLE];
  char author[MAX_AUTHOR];
  char genre[MAX_GENRE];
  int isIssued;
} Book;

typedef struct {
    int id;
    char name[MAX_NAME];
    char email[MAX_EMAIL];
    char phone[MAX_PHONE];
} Member;

typedef struct {
  int id;
  int bookId;
  int memberId;
  time_t isssueDate;
  time_t dueDte;
  time_t returnDate;
  double fine;
  int isReturned;
} IssueRecord;

extern Book* books;
extern int bookCount;
extern int bookCapacity;

extern Member* members;
extern int memberCount;
extern int memberCapacity;

extern IssueRecord* issues;
extern int issueCount;
extern int issueCapacity;

extern int nextBookId;
extern int nextMemberId;
extern int nextIssueId;

#define BOOKS_FILE "../data/books.dat"
#define MEMBERS_FILE "../data/members.dat"
#define ISSUED_FILE "../data/issued.dat"

void initializeSystem();
void shutdownSystem();

void addBookToArray(Book book);
void addMemberToArray(Member member);
void addIssueToArray(IssueRecord issue);
int findBookIndexById(int bookId);
int findMemberIndexById(int memberId);
int findIssueIndexById(int issueId);

void loadAllDataFromFiles();
void saveAllDataToFiles();
void loadBooksFromFile();
void loadMembersFromFile();
void loadIssuesFromFile();
void saveBooksToFile();
void saveMembersToFile();
void saveIssuesToFile();

void showMainMenu();

void suggestBooksSimilarToReturnedBook(int returnedBookId);
void recommendBooksForMember(int memberId);

#endif
