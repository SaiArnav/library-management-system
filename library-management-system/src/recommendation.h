#ifndef RECOMMENDATION_H
#define RECOMMENDATION_H

#include "library.h"
/** 
- Suggests 3 similar books to a just returned book
- Based on: Same Author or Genre
*/
void suggestBooksSimilarToReturnedBook(int returnedBookId);

/**
- Recommends books based on members borrowing history
- Suggests boooks by favourite authors or genres
*/
void recommendBooksForMember(int memberId);

#endif
