#include "recommendation.h"

void suggestBooksSimilarToReturnedBook(int returnedBookId) {
    int bookIndex = findBookIndexById(returnedBookId);
    if (bookIndex == -1) {
      return;
    }
  Book* returnedBook = &books[bookIndex];
  Book suggestions[3];
  int suggestionCount = 0;

  for(int i = 0; i < bookCount && suggestionCount < 3; i++) {
    if(books[i].id != returnedBookId && books[i].isIssued == 0) {
      if(strcmp(books[i].author, returnedBook -> author) == 0) {
        suggestions[suggestionCount++] = books[i];
      } else if (strcmp(books[i].genre, returnedBook -> genre) == 0) {
          suggestions[suggestionCount++] = books[i];
      }
    }
  }
 if(suggestionCount > 0) {
    printf("\nYou might also enjoy(Similar to '%s'):\n", returnedBook->title);
    for(int i = 0; i < suggestionCount; i++) {
      printf("%s\n", suggestions[i].title);
      printf("By: %s | Genre: %s\n", suggestions[i].author, suggestions[i].genre);
      printf("Status: %s\n\n", suggestions[i].isIssued ? "Issued" : "Available");
    }
  }
}

void recommendBooksForMember(int memberId) {
    if(findMemberIndexById(memberId) == -1) {
      printf("Member ID %d not found!\n", memberId);
      return;
    }
char favoriteAuthors[10][MAX_AUTHOR];
char favoriteGenres[10][MAX_GENRE];
int authorCount = 0;
int genreCount = 0;

for(int i = 0; i < issueCount; i++) {
  if( issue[i].memberId == memberId && issues[i].isReturned == 1) {
    int bookIndex = findBookIndexById(issues[i].bookId);
                if (bookIndex != -1) {
                int authorExists = 0;
                for (int j = 0; j < authorCount; j++) {
                    if (strcmp(favoriteAuthors[j], books[bookIndex].author) == 0) {
                        authorExists = 1;
                        break;
                    }
                }
  if (!authorExists && authorCount < 10) {
                    strcpy(favoriteAuthors[authorCount++], books[bookIndex].author);
  }
  int genreExists = 0;
    for (int j = 0; j < genreCount; j++) {
                    if (strcmp(favoriteGenres[j], books[bookIndex].genre) == 0) {
                        genreExists = 1;
                        break;
                    }
                }
                if (!genreExists && genreCount < 10) {
                    strcpy(favoriteGenres[genreCount++], books[bookIndex].genre);
                }
            }
        }
    }
    if (authorCount == 0 && genreCount == 0) {
        printf("\nNo borrowing history found for this member.\n");
        printf("Try borrowing some books first to get personalized recommendations!\n");
        return;
    }
    Book recommendations[5];
    int recCount = 0;
    for (int i = 0; i < bookCount && recCount < 5; i++) {
        if (books[i].isIssued == 0) {  
            for (int j = 0; j < authorCount; j++) {
                if (strcmp(g_books[i].author, favoriteAuthors[j]) == 0) {
                    int alreadyAdded = 0;
                    for (int k = 0; k < recCount; k++) {
                        if (recommendations[k].id == books[i].id) {
                            alreadyAdded = 1;
                            break;
                        }
                    }
                       if (!alreadyAdded) {
                        recommendations[recCount++] = books[i];
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < bookCount && recCount < 5; i++) {
        if (books[i].isIssued == 0) {
            for (int j = 0; j < genreCount; j++) {
                if (strcmp(books[i].genre, favoriteGenres[j]) == 0) {
                    int alreadyAdded = 0;
                    for (int k = 0; k < recCount; k++) {
                        if (recommendations[k].id == books[i].id) {
                            alreadyAdded = 1;
                            break;
                        }
                    }
                    if (!alreadyAdded) {
                        recommendations[recCount++] = books[i];
                        break;
                    }
                }
            }
        }
    }
printf("\nPERSONALIZED RECOMMENDATIONS FOR MEMBER ID %d:\n", memberId);
    printf("\nBased on your reading history:\n");
    printf("Favorite Authors: ");
    for (int i = 0; i < authorCount; i++) {
        printf("%s ", favoriteAuthors[i]);
    }
    printf("\n      Favorite Genres:  ");
    for (int i = 0; i < genreCount; i++) {
        printf("%s ", favoriteGenres[i]);
    }
    printf("\n\n");

      if (recCount > 0) {
        printf("BOOKS YOU MIGHT LIKE:\n");
        for (int i = 0; i < recCount; i++) {
            printf("%d. %s\n", i+1, recommendations[i].title);
            printf("By: %s | Genre: %s\n", recommendations[i].author, recommendations[i].genre);
        }
    } else {
        printf("No new recommendations available right now.\n");
        printf("All books matching your taste are currently issued!\n");
    }
    printf("\n");
}
