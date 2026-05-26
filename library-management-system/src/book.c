#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

extern Book* books;
extern int bookCount;
extern int bookCapacity;
extern int nextBookId;

void addNewBook() {
    Book newBook;
    
    printf("\n===== ADD NEW BOOK =====\n");
    
    printf("Enter Book Title: ");
    fgets(newBook.title, MAX_TITLE, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';
    
    printf("Enter Book Author: ");
    fgets(newBook.author, MAX_AUTHOR, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';
    
    printf("Enter Book Genre: ");
    fgets(newBook.genre, MAX_GENRE, stdin);
    newBook.genre[strcspn(newBook.genre, "\n")] = '\0';
    
    newBook.id = nextBookId++;
    newBook.isIssued = 0;

    if (bookCount >= bookCapacity) {
        bookCapacity *= 2;
        books = (Book*)realloc(books, bookCapacity * sizeof(Book));
        if (!books) {
            printf("Memory allocation failed!\n");
            return;
        }
    }
    
    books[bookCount++] = newBook;
    
    printf("\nBook added successfully!\n");
    printf("Book ID: %d\n", newBook.id);
    printf("Title: %s\n", newBook.title);
    printf("Author: %s\n", newBook.author);
    printf("Genre: %s\n", newBook.genre);
    
    saveBooksToFile();
}

void updateBookDetails() {
    int bookId;
    
    printf("\n===== UPDATE BOOK =====\n");
    printf("Enter Book ID to update: ");
    scanf("%d", &bookId);
    getchar();
    
    int index = findBookIndexById(bookId);
    if (index == -1) {
        printf("Book not found!\n");
        return;
    }
    
    printf("\nCurrent Details:\n");
    printf("Title: %s\n", books[index].title);
    printf("Author: %s\n", books[index].author);
    printf("Genre: %s\n", books[index].genre);
    printf("Status: %s\n", books[index].isIssued ? "Issued" : "Available");
    
    printf("\nEnter New Details (press Enter to keep current):\n");
    
    char newTitle[MAX_TITLE];
    char newAuthor[MAX_AUTHOR];
    char newGenre[MAX_GENRE];
    
    printf("New Title [%s]: ", books[index].title);
    fgets(newTitle, MAX_TITLE, stdin);
    newTitle[strcspn(newTitle, "\n")] = '\0';
    if (strlen(newTitle) > 0) {
        strcpy(books[index].title, newTitle);
    }
    
    printf("New Author [%s]: ", books[index].author);
    fgets(newAuthor, MAX_AUTHOR, stdin);
    newAuthor[strcspn(newAuthor, "\n")] = '\0';
    if (strlen(newAuthor) > 0) {
        strcpy(books[index].author, newAuthor);
    }
    
    printf("New Genre [%s]: ", books[index].genre);
    fgets(newGenre, MAX_GENRE, stdin);
    newGenre[strcspn(newGenre, "\n")] = '\0';
    if (strlen(newGenre) > 0) {
        strcpy(books[index].genre, newGenre);
    }
    
    printf("\nBook updated successfully!\n");
    saveBooksToFile();
}

void removeBook() {
    int bookId;
    
    printf("\n===== DELETE BOOK =====\n");
    printf("Enter Book ID to delete: ");
    scanf("%d", &bookId);
    
    int index = findBookIndexById(bookId);
    if (index == -1) {
        printf("Book not found!\n");
        return;
    }
    
    if (books[index].isIssued == 1) {
        printf("Cannot delete book! Book is currently issued.\n");
        return;
    }
    
    char confirm;
    printf("Are you sure you want to delete '%s'? (y/n): ", books[index].title);
    scanf(" %c", &confirm);
    
    if (confirm != 'y' && confirm != 'Y') {
        printf("Deletion cancelled.\n");
        return;
    }
    
    for (int i = index; i < bookCount - 1; i++) {
        books[i] = books[i + 1];
    }
    bookCount--;
    
    printf("Book deleted successfully!\n");
    saveBooksToFile();
}

void showAllBooks() {
    printf("\n===== ALL BOOKS IN LIBRARY =====\n");
    
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }
    
    printf("\n+-----+--------------------------+------------------+------------------+----------+\n");
    printf("| ID  | Title                    | Author           | Genre            | Status   |\n");
    printf("+-----+--------------------------+------------------+------------------+----------+\n");
    
    for (int i = 0; i < bookCount; i++) {
        printf("| %3d | %-24s | %-16s | %-16s | %-8s |\n",
               books[i].id,
               books[i].title,
               books[i].author,
               books[i].genre,
               books[i].isIssued ? "Issued" : "Available");
    }
    
    printf("+-----+--------------------------+------------------+------------------+----------+\n");
    printf("\nTotal Books: %d\n", bookCount);
}

int isBookAvailable(int bookId) {
    int index = findBookIndexById(bookId);
    if (index == -1) return 0;
    return (books[index].isIssued == 0);
}
