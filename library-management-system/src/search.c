#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "search.h"

// External global variables from library.c
extern Book* books;
extern int bookCount;

// Convert string to lowercase for case-insensitive search
void toLowercase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void searchBooksByTitle() {
    char keyword[MAX_TITLE];
    Book results[100];
    int resultCount = 0;
    
    printf("\n===== SEARCH BOOKS BY TITLE =====\n");
    printf("Enter title keyword: ");
    fgets(keyword, MAX_TITLE, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';
    
    char lowerKeyword[MAX_TITLE];
    strcpy(lowerKeyword, keyword);
    toLowercase(lowerKeyword);
    
    for (int i = 0; i < bookCount; i++) {
        char lowerTitle[MAX_TITLE];
        strcpy(lowerTitle, books[i].title);
        toLowercase(lowerTitle);
        
        if (strstr(lowerTitle, lowerKeyword) != NULL) {
            results[resultCount++] = books[i];
        }
    }
    
    displaySearchResults(results, resultCount, "Title");
}

void searchBooksByAuthor() {
    char keyword[MAX_AUTHOR];
    Book results[100];
    int resultCount = 0;
    
    printf("\n===== SEARCH BOOKS BY AUTHOR =====\n");
    printf("Enter author name: ");
    fgets(keyword, MAX_AUTHOR, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';
    
    char lowerKeyword[MAX_AUTHOR];
    strcpy(lowerKeyword, keyword);
    toLowercase(lowerKeyword);
    
    for (int i = 0; i < bookCount; i++) {
        char lowerAuthor[MAX_AUTHOR];
        strcpy(lowerAuthor, books[i].author);
        toLowercase(lowerAuthor);
        
        if (strstr(lowerAuthor, lowerKeyword) != NULL) {
            results[resultCount++] = books[i];
        }
    }
    
    displaySearchResults(results, resultCount, "Author");
}

void searchBooksByGenre() {
    char keyword[MAX_GENRE];
    Book results[100];
    int resultCount = 0;
    
    printf("\n===== SEARCH BOOKS BY GENRE =====\n");
    printf("Enter genre: ");
    fgets(keyword, MAX_GENRE, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';
    
    char lowerKeyword[MAX_GENRE];
    strcpy(lowerKeyword, keyword);
    toLowercase(lowerKeyword);
    
    for (int i = 0; i < bookCount; i++) {
        char lowerGenre[MAX_GENRE];
        strcpy(lowerGenre, books[i].genre);
        toLowercase(lowerGenre);
        
        if (strstr(lowerGenre, lowerKeyword) != NULL) {
            results[resultCount++] = books[i];
        }
    }
    
    displaySearchResults(results, resultCount, "Genre");
}

void displaySearchResults(Book* results, int resultCount, const char* searchType) {
    if (resultCount == 0) {
        printf("\nNo books found matching %s.\n", searchType);
        return;
    }
    
    printf("\n===== SEARCH RESULTS (%s) =====\n", searchType);
    printf("\n+-----+--------------------------+------------------+------------------+----------+\n");
    printf("| ID  | Title                    | Author           | Genre            | Status   |\n");
    printf("+-----+--------------------------+------------------+------------------+----------+\n");
    
    for (int i = 0; i < resultCount; i++) {
        printf("| %3d | %-24s | %-16s | %-16s | %-8s |\n",
               results[i].id,
               results[i].title,
               results[i].author,
               results[i].genre,
               results[i].isIssued ? "Issued" : "Available");
    }
    
    printf("+-----+--------------------------+------------------+------------------+----------+\n");
    printf("\nFound %d book(s).\n", resultCount);
}
