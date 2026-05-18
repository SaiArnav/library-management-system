#include "library.h"
#include "recommendation.h"
#include "book.h"
#include "member.h"
#include "search.h"
#include "issue.h"
#include "fine.h"

extern void addBook();
extern void updateBook();
extern void deleteBook();
extern void displayAllBooks();
extern void registerMember();
extern void updateMember();
extern void deleteMember();
extern void displayAllMembers();
extern void issueBook();        
extern void returnBook();       
extern void listIssuedBooks(); 
extern void searchByTitle();
extern void searchByAuthor();
extern void searchByGenre();
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
                addBook();
                break;
            case 2:
                updateBook();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                displayAllBooks();
                break;
            case 5:
                registerMember();
                break;
            case 6:
                updateMember();
                break;
            case 7:
                deleteMember();
                break;
            case 8:
                displayAllMembers();
                break;
            case 9:
                issueBook();
                break;
            case 10:
                returnBook();
                break;
            case 11:
                searchByTitle();
                break;
            case 12:
                searchByAuthor();
                break;
            case 13:
                searchByGenre();
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
