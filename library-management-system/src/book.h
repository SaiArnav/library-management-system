#ifndef BOOK_H
#define BOOK_H

#include "library.h"

// Book Management Functions
void addNewBook();
void updateBookDetails();
void removeBook();
void showAllBooks();

// Helper Functions
int findBookIndexById(int bookId);
int isBookAvailable(int bookId);
void saveBooksToFile();

#endif
