#ifndef SEARCH_H
#define SEARCH_H

#include "library.h"

// Search Functions
void searchBooksByTitle();
void searchBooksByAuthor();
void searchBooksByGenre();

// Helper Functions
void displaySearchResults(Book* results, int resultCount, const char* searchType);

#endif
