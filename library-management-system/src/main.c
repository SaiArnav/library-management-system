#include "library.h"
#include "recommendation.h"
#include "book.h"
#include "member.h"
#include "search.h"
#include "issue.h"
#include "fine.h"
#include <time.h>

#define ANSI_RESET "\x1b[0m"
#define ANSI_DIM   "\x1b[2m"
#define ANSI_BOLD  "\x1b[1m"
#define ANSI_CYAN  "\x1b[36m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_WHITE "\x1b[97m"

static void printShadowLine(const char *text) {
    printf(ANSI_DIM "  %s\n" ANSI_RESET, text);
    printf(ANSI_BOLD ANSI_WHITE "%s\n" ANSI_RESET, text);
}

static void printShadowBanner(void) {
    // ============== ASCII ART BANNER ==============
    printf(ANSI_CYAN ANSI_BOLD);
    printf("██╗     ██╗██████╗ ██████╗  █████╗ ██████╗ ██╗   ██╗    \n");
    printf("██║     ██║██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝    \n");
    printf("██║     ██║██████╔╝██████╔╝███████║██████╔╝ ╚████╔╝     \n");
    printf("██║     ██║██╔══██╗██╔══██╗██╔══██║██╔══██╗  ╚██╔╝      \n");
    printf("███████╗██║██████╔╝██║  ██║██║  ██║██║  ██║   ██║       \n");
    printf("╚══════╝╚═╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       \n");
    printf(ANSI_RESET);
    
    printf(ANSI_CYAN ANSI_BOLD);
    printf("███╗   ███╗ █████╗ ███╗   ██╗ █████╗  ██████╗ ███████╗███╗   ███╗███████╗███╗   ██╗████████╗\n");
    printf("████╗ ████║██╔══██╗████╗  ██║██╔══██╗██╔════╝ ██╔════╝████╗ ████║██╔════╝████╗  ██║╚══██╔══╝\n");
    printf("██╔████╔██║███████║██╔██╗ ██║███████║██║  ███╗█████╗  ██╔████╔██║█████╗  ██╔██╗ ██║   ██║   \n");
    printf("██║╚██╔╝██║██╔══██║██║╚██╗██║██╔══██║██║   ██║██╔══╝  ██║╚██╔╝██║██╔══╝  ██║╚██╗██║   ██║   \n");
    printf("██║ ╚═╝ ██║██║  ██║██║ ╚████║██║  ██║╚██████╔╝███████╗██║ ╚═╝ ██║███████╗██║ ╚████║   ██║   \n");
    printf("╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝   ╚═╝   \n");
    printf(ANSI_RESET);

    printf(ANSI_CYAN ANSI_BOLD);
    printf("███████╗██╗   ██╗███████╗████████╗███████╗███╗   ███╗\n");
    printf("██╔════╝╚██╗ ██╔╝██╔════╝╚══██╔══╝██╔════╝████╗ ████║\n");
    printf("███████╗ ╚████╔╝ ███████╗   ██║   █████╗  ██╔████╔██║\n");
    printf("╚════██║  ╚██╔╝  ╚════██║   ██║   ██╔══╝  ██║╚██╔╝██║\n");
    printf("███████║   ██║   ███████║   ██║   ███████╗██║ ╚═╝ ██║\n");
    printf("╚══════╝   ╚═╝   ╚══════╝   ╚═╝   ╚══════╝╚═╝     ╚═╝\n");
    printf(ANSI_RESET);
    printf("\n");
}

static void printMainMenu(void) {
    // ============== MAIN MENU (PROPERLY ALIGNED) ==============
        printf("\n" ANSI_CYAN ANSI_BOLD);
    printf("  ╔══════════════════════════════════════════════════════════════════╗\n");
    printf("  ║                          MAIN MENU                               ║\n");
    printf("  ╠══════════════════════════════════════════════════════════════════╣\n");
    printf(ANSI_RESET);
    
    printf("  ║ " ANSI_CYAN "[ 1] " ANSI_CYAN "Add New Book" ANSI_CYAN "                                                ║\n");
    printf("  ║ " ANSI_CYAN "[ 2] " ANSI_CYAN "Update Book Details" ANSI_CYAN "                                         ║\n");
    printf("  ║ " ANSI_CYAN "[ 3] " ANSI_CYAN "Remove Book" ANSI_CYAN "                                                 ║\n");
    printf("  ║ " ANSI_CYAN "[ 4] " ANSI_CYAN "Show All Books" ANSI_CYAN "                                              ║\n");
    printf("  ║ " ANSI_CYAN "[ 5] " ANSI_CYAN "Register New Member" ANSI_CYAN "                                         ║\n");
    printf("  ║ " ANSI_CYAN "[ 6] " ANSI_CYAN "Update Member Details" ANSI_CYAN "                                       ║\n");
    printf("  ║ " ANSI_CYAN "[ 7] " ANSI_CYAN "Remove Member" ANSI_CYAN "                                               ║\n");
    printf("  ║ " ANSI_CYAN "[ 8] " ANSI_CYAN "Show All Members" ANSI_CYAN "                                            ║\n");
    printf("  ║ " ANSI_CYAN "[ 9] " ANSI_CYAN "Issue Book" ANSI_CYAN "                                                  ║\n");
    printf("  ║ " ANSI_CYAN "[10] " ANSI_CYAN "Return Book" ANSI_CYAN "                                                 ║\n");
    printf("  ║ " ANSI_CYAN "[11] " ANSI_CYAN "Search by Title" ANSI_CYAN "                                             ║\n");
    printf("  ║ " ANSI_CYAN "[12] " ANSI_CYAN "Search by Author" ANSI_CYAN "                                            ║\n");
    printf("  ║ " ANSI_CYAN "[13] " ANSI_CYAN "Search by Genre" ANSI_CYAN "                                             ║\n");
    printf("  ║ " ANSI_CYAN "[14] " ANSI_CYAN "List Issued Books" ANSI_CYAN "                                           ║\n");
    printf("  ║ " ANSI_CYAN "[15] " ANSI_CYAN "Overdue Report" ANSI_CYAN "                                              ║\n");
    printf("  ║ " ANSI_CYAN "[16] " ANSI_CYAN "Member Report" ANSI_CYAN "                                               ║\n");
    printf("  ║ " ANSI_CYAN "[17] " ANSI_CYAN "Fine Report"ANSI_CYAN "                                                 ║\n");
    printf(ANSI_MAGENTA);
    printf("  ║ " ANSI_MAGENTA "[18] " ANSI_WHITE "AI Recommendations" ANSI_MAGENTA "                                          ║\n");
    printf(ANSI_YELLOW);
    printf("  ║ " ANSI_YELLOW "[19] " ANSI_WHITE "Save & Exit" ANSI_YELLOW "                                                 ║\n");
    printf(ANSI_RESET);
    
    printf(ANSI_CYAN ANSI_BOLD);
    printf("  ╚══════════════════════════════════════════════════════════════════╝\n");
    printf(ANSI_RESET);
    
    printf("\n" ANSI_GREEN "  ➤ Enter your choice: " ANSI_RESET);
}

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

void runBenchmark() {
    clock_t start, end;
    double cpu_time_used;
    
    printf("\n========== BENCHMARK RESULTS ==========\n");
    printf("Running performance tests...\n\n");
    
    // 1. Book Search Benchmark (Use the actual search function)
    printf("1. Book Search:\n");
    start = clock();
    for (int i = 0; i < 100; i++) {
        // Since searchByTitle() takes no args, use displayAllBooks() as proxy
        showAllBooks();
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("   Display All Books (100 times): %.6f seconds\n", cpu_time_used);
    printf("   Average: %.6f seconds\n", cpu_time_used / 100);
    
    // 2. Add Book Benchmark (Direct array operations)
    printf("\n2. Add Book (Direct Array Operations):\n");
    start = clock();
    for (int i = 0; i < 100; i++) {
        Book testBook;
        testBook.id = nextBookId++;
        strcpy(testBook.title, "Benchmark Book");
        strcpy(testBook.author, "Benchmark Author");
        strcpy(testBook.genre, "Test");
        testBook.isIssued = 0;
        
        if (bookCount >= bookCapacity) {
            bookCapacity *= 2;
            books = (Book*)realloc(books, bookCapacity * sizeof(Book));
        }
        books[bookCount++] = testBook;
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("   Add 100 books: %.6f seconds\n", cpu_time_used);
    printf("   Average per book: %.6f seconds\n", cpu_time_used / 100);
    
    // 3. File Save Benchmark
    printf("\n3. File Save Operations:\n");
    start = clock();
    saveBooksToFile();
    saveMembersToFile();
    saveIssuesToFile();
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("   Save all 3 files: %.6f seconds\n", cpu_time_used);
    
    // 4. File Load Benchmark
    printf("\n4. File Load Operations:\n");
    start = clock();
    loadBooksFromFile();
    loadMembersFromFile();
    loadIssuesFromFile();
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("   Load all 3 files: %.6f seconds\n", cpu_time_used);
    
    // 5. Linear Search Simulation (if you want to measure search specifically)
    printf("\n5. Linear Search Simulation:\n");
    start = clock();
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < bookCount; j++) {
            if (strcmp(books[j].title, "Harry Potter") == 0) {
                break;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("   1000 linear searches: %.6f seconds\n", cpu_time_used);
    printf("   Average per search: %.6f seconds\n", cpu_time_used / 1000);
    
    printf("\n========================================\n");
    printf("Note: Results may vary based on hardware.\n");
}

int main() {
  int choice;
  int memberIdForRec;
  initializeSystem();
  loadAllDataFromFiles();
  //runBenchmark();

        printShadowBanner();
        printf(ANSI_DIM "\nUse the menu below to navigate.\n" ANSI_RESET);

  do {
        printMainMenu();
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
                searchBooksByTitle();
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
    return 0;
}
