#include "library.h"
#include "recommendation.h"
#include "book.h"
#include "member.h"
#include "search.h"
#include "issue.h"
#include "fine.h"

extern void addNewBook();
extern void updateBookDetails();
extern void removeBook();
extern void showAllBooks();
extern void registerNewMember();
extern void updateMemberDetails();
extern void removeMember();
extern void showAllMembers();
extern void issueBook();        
extern void returnBook();       
extern void listIssuedBooks(); 
extern void searchBooksByTitle();
extern void searchBooksByAuthor();
extern void searchBooksByGenre();
extern void overdueReport();  
extern void memberReport();
extern void fineReport();

int main() {
  int choice;
  int memberIdForRec;
  initializeSystem();
  loadAllDataFromFiles();

      printf("\n╔════════════════════════════════════════╗\n");
    printf("║   WELCOME TO LIBRARY MANAGEMENT SYSTEM ║\n");
    printf("╚════════════════════════════════════════╝\n");

  do {
        showMainMenu();
        scanf("%d", &choice);
        getchar(); 
        
        switch(choice) {
            case 1:
                addNewBook();
                break;
            case 2:
                updateBookDetails();
                break;
            case 3:
                removeBook();
                break;
            case 4:
                showAllBooks();
                break;
            case 5:
               registerNewMember();
                break;
            case 6:
              updateMemberDetails();
                break;
            case 7:
                removeMember();
                break;
            case 8: 
               showAllMembers();
               break;
            case 9:
                issueBook();
                break;
            case 10:
                returnBook();
                break;
            case 11:
                searchBooksByTitle());
                break;
            case 12:
                searchBooksByAuthor();
                break;
            case 13:
                searchBooksByGenre();
                break;
            case 14:
                listIssuedBooks();
                break;
            case 15:
                overdueReport();
                break;
            case 16:
                memberReport();
                break;
            case 17:
                fineReport();
                break;
            case 18:
                printf("\nEnter Member ID for personalized recommendations: ");
                scanf("%d", &memberIdForRec);
                recommendBooksForMember(memberIdForRec);
                break;
            case 19:
                printf("\nSaving all data to files...\n");
                saveAllDataToFiles();
                printf("Thank you for using Library Management System!\n");
                printf("Goodbye!\n");
                break;
            
            default:
                printf("Invalid choice! Please enter a number between 1-19.\n");
        }
    } while(choice != 19);
shutdownSystem();
}
