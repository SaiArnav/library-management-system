#include "library.h"

Book* books = NULL;
int bookCount = 0;
int bookCapacity = 0;

Member* members = NULL;
int memberCount = 0;
int memberCapacity = 0;

IssueRecord* issues = NULL;
int issueCount = 0;
int issueCapacity = 0;

int nextBookId = 1;
int nextMemberId = 1;
int nextIssueId = 1;

void initializeSystem() {
  bookCapacity = 20;
  books = (Book*)malloc(bookCapacity * sizeof(Book));
  
  memberCapacity = 20;
  members = (Member*)malloc(memberCapacity * sizeof(Member));

  issueCapacity = 20;
  issues = (IssueRecord*)malloc(issueCapacity * sizeof(IssueRecord));

  if (!books || !members || !issues) {
  printf("Memory allocation failed!\n");
  exit(0);
  }
  }

void shutdownSystem() {
  free(books);
  free(members);
  free(issues);
  books = NULL;
  members = NULL;
  issues = NULL;
}

void addBookToArray(Book book) {
  if(bookCount >= bookCapacity) {
    bookCapacity *= 2;
    books = (Book*)realloc(books, bookCapacity * sizeof(Book));
  }
  books[bookCount++] = book;
}

void addMemberToArray(Member member) {
  if(memberCount >= memberCapacity) {
    memberCapacity *= 2;
    members = (Member*)realloc(members, memberCapacity * sizeof(Member));
  }
  members[memberCount++] = member;
}

void addIssueToArray(IssueRecord issue) {
  if(issueCount >= issueCapacity) {
    issueCapacity *= 2;
    issues = (IssueRecord*)realloc(issues, issueCapacity * sizeof(IssueRecord));
  }
  issues[issueCount++] = issue;
}

int findBookIndexById(int bookId) {
  for(int i = 0; i < bookCount; i++) {
    if(books[i].id == bookId) {
      return i;
    }
  }
  return -1;
}

int findMemberIndexById(int memberId) {
    for(int i = 0; i < memberCount; i++) {
      if(members[i].id == memberId) {
        return i;
      }
    }
    return -1;
}

int findIssueIndexById(int issueId) {
     for(int i = 0; i < issueCount; i++) {
        if(issues[i].issueId == issueId) {
          return i;
        }
     }
    return -1;
}

void loadBooksFromFile() {
  FILE* file = fopen(BOOKS_FILE, "rb");
  if(file) {
    bookCount = 0;
    Book book;
    while (fread(&book, sizeof(Book), 1, file)) {
        addBookToArray(book);
        if (book.id >= nextBookId) {
          nextBookId = book.id + 1;
        }
    }
    fclose(file);
    printf("Loaded %d books from file.\n", bookCount);
  } else {
      printf("No existing books from file.\n");
  }
}

void loadMembersFromFile() {
    FILE* file = fopen(MEMBERS_FILE, "rb");
    if (file) {
        memberCount = 0;
        Member member;
        while (fread(&member, sizeof(Member), 1, file)) {
            addMemberToArray(member);
            if (member.id >= nextMemberId) {
                nextMemberId = member.id + 1;
            }
        }
        fclose(file);
        printf("Loaded %d members from file.\n", memberCount);
    } else {
        printf("No existing members from file.\n");
    }
}

void loadIssuesFromFile() {
    FILE* file = fopen(ISSUED_FILE, "rb");
    if (file) {
        issueCount = 0;
        IssueRecord issue;
        while (fread(&issue, sizeof(IssueRecord), 1, file)) {
            addIssueToArray(issue);
            if (issue.issueId >= nextIssueId) {
                nextIssueId = issue.issueId + 1;
            }
        }
        fclose(file);
        printf("Loaded %d issue records from file.\n", issueCount);
    } else {
        printf("No existing issues file.\n");
    }
}

void saveBooksToFile() {
    FILE* file = fopen(BOOKS_FILE, "wb");
    if (file) {
        fwrite(books, sizeof(Book), bookCount, file);
        fclose(file);
        printf("Saved %d books to file.\n", bookCount);
    }
}

void saveMembersToFile() {
    FILE* file = fopen(MEMBERS_FILE, "wb");
    if (file) {
        fwrite(members, sizeof(Member), memberCount, file);
        fclose(file);
        printf("Saved %d members to file.\n", memberCount);
    }
}

void saveIssuesToFile() {
    FILE* file = fopen(ISSUED_FILE, "wb");
    if (file) {
        fwrite(issues, sizeof(IssueRecord), issueCount, file);
        fclose(file);
        printf("Saved %d issue records to file.\n", issueCount);
    }
}

void loadAllDataFromFiles() {
    loadBooksFromFile();
    loadMembersFromFile();
    loadIssuesFromFile();
}

void saveAllDataToFiles() {
    saveBooksToFile();
    saveMembersToFile();
    saveIssuesToFile();
}

void showMainMenu() {
    printf("\n+================================================+\n");
    printf("|         LIBRARY MANAGEMENT SYSTEM                |\n");
    printf("+==================================================+\n");
    printf("|                                                  |\n");
    printf("|   BOOK MANAGEMENT                                |\n");
    printf("|     1.  Add New Book                             |\n");
    printf("|     2.  Update Book Details                      |\n");
    printf("|     3.  Remove Book                              |\n");
    printf("|     4.  Show All Books                           |\n");
    printf("|                                                  |\n");
    printf("|   MEMBER MANAGEMENT                              |\n");
    printf("|     5.  Register New Member                      |\n");
    printf("|     6.  Update Member Details                    |\n");
    printf("|     7.  Remove Member                            |\n");
    printf("|     8.  Show All Members                         |\n");
    printf("|                                                  |\n");
    printf("|   ISSUE & RETURN                                 |\n");
    printf("|     9.  Issue Book to Member                     |\n");
    printf("|     10. Return Book from Member                  |\n");
    printf("|                                                  |\n");
    printf("|   SEARCH                                         |\n");
    printf("|     11. Search by Title                          |\n");
    printf("|     12. Search by Author                         |\n");
    printf("|     13. Search by Genre                          |\n");
    printf("|                                                  |\n");
    printf("|   REPORTS                                        |\n");
    printf("|     14. Show Currently Issued Books              |\n");
    printf("|     15. Show Overdue Books Report                |\n");
    printf("|     16. Generate Member Report                   |\n");
    printf("|     17. Generate Fine Report                     |\n");
    printf("|                                                  |\n");
    printf("|   AI RECOMMENDATIONS                             |\n");
    printf("|     18. Get Personalized Book Recommendations    |\n");
    printf("|                                                  |\n");
    printf("|   SYSTEM                                         |\n");
    printf("|     19. Save & Exit                              |\n");
    printf("|                                                  |\n");
    printf("+==================================================+\n");
    printf("Enter your choice: ");
}
