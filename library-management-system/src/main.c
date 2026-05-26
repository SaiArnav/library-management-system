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
                updateMember();
                break;
            case 7:
                updateMemberDetails();
                break;
            case 8:
                removeMember();
                break;
            case 9: 
               showAllMembers();
               break;
            case 10:
                issueBook();
                break;
            case 11:
                returnBook();
                break;
            case 12:
                searchBooksByTitle());
                break;
            case 13:
                searchBooksByAuthor();
                break;
            case 14:
                searchBooksByGenre();
                break;
            case 15:
                listIssuedBooks();
                break;
            case 16:
                overdueReport();
                break;
            case 17:
                memberReport();
                break;
            case 18:
                fineReport();
                break;
            case 19:
                printf("\nEnter Member ID for personalized recommendations: ");
                scanf("%d", &memberIdForRec);
                recommendBooksForMember(memberIdForRec);
                break;
            case 20:
                printf("\nSaving all data to files...\n");
                saveAllDataToFiles();
                printf("Thank you for using Library Management System!\n");
                printf("Goodbye!\n");
                break;
            
            default:
                printf("Invalid choice! Please enter a number between 1-19.\n");
        }
    } while(choice != 20);
shutdownSystem();
}
