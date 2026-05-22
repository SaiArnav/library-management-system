#ifndef MEMBER_H
#define MEMBER_H

#include "library.h"

// Member Management Functions
void registerNewMember();
void updateMemberDetails();
void removeMember();
void showAllMembers();

// Helper Functions
int findMemberIndexById(int memberId);
void saveMembersToFile();

#endif
