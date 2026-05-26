#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "member.h"

extern Member* members;
extern int memberCount;
extern int memberCapacity;
extern int nextMemberId;
extern IssueRecord* issues;
extern int issueCount;

void registerNewMember() {
    Member newMember;
    
    printf("\n===== REGISTER NEW MEMBER =====\n");
    
    printf("Enter Member Name: ");
    fgets(newMember.name, MAX_NAME, stdin);
    newMember.name[strcspn(newMember.name, "\n")] = '\0';
    
    printf("Enter Member Email: ");
    fgets(newMember.email, MAX_EMAIL, stdin);
    newMember.email[strcspn(newMember.email, "\n")] = '\0';
    
    printf("Enter Member Phone: ");
    fgets(newMember.phone, MAX_PHONE, stdin);
    newMember.phone[strcspn(newMember.phone, "\n")] = '\0';
    
    newMember.id = nextMemberId++;
    
    // Add to dynamic array
    if (memberCount >= memberCapacity) {
        memberCapacity *= 2;
        members = (Member*)realloc(members, memberCapacity * sizeof(Member));
        if (!members) {
            printf("Memory allocation failed!\n");
            return;
        }
    }
    
    members[memberCount++] = newMember;
    
    printf("\nMember registered successfully!\n");
    printf("Member ID: %d\n", newMember.id);
    printf("Name: %s\n", newMember.name);
    printf("Email: %s\n", newMember.email);
    printf("Phone: %s\n", newMember.phone);
    
    saveMembersToFile();
}

void updateMemberDetails() {
    int memberId;
    
    printf("\n===== UPDATE MEMBER =====\n");
    printf("Enter Member ID to update: ");
    scanf("%d", &memberId);
    getchar();
    
    int index = findMemberIndexById(memberId);
    if (index == -1) {
        printf("Member not found!\n");
        return;
    }
    
    printf("\nCurrent Details:\n");
    printf("Name: %s\n", members[index].name);
    printf("Email: %s\n", members[index].email);
    printf("Phone: %s\n", members[index].phone);
    
    printf("\nEnter New Details (press Enter to keep current):\n");
    
    char newName[MAX_NAME];
    char newEmail[MAX_EMAIL];
    char newPhone[MAX_PHONE];
    
    printf("New Name [%s]: ", members[index].name);
    fgets(newName, MAX_NAME, stdin);
    newName[strcspn(newName, "\n")] = '\0';
    if (strlen(newName) > 0) {
        strcpy(members[index].name, newName);
    }
    
    printf("New Email [%s]: ", members[index].email);
    fgets(newEmail, MAX_EMAIL, stdin);
    newEmail[strcspn(newEmail, "\n")] = '\0';
    if (strlen(newEmail) > 0) {
        strcpy(members[index].email, newEmail);
    }
    
    printf("New Phone [%s]: ", members[index].phone);
    fgets(newPhone, MAX_PHONE, stdin);
    newPhone[strcspn(newPhone, "\n")] = '\0';
    if (strlen(newPhone) > 0) {
        strcpy(members[index].phone, newPhone);
    }
    
    printf("\nMember updated successfully!\n");
    saveMembersToFile();
}

void removeMember() {
    int memberId;
    
    printf("\n===== DELETE MEMBER =====\n");
    printf("Enter Member ID to delete: ");
    scanf("%d", &memberId);
    
    int index = findMemberIndexById(memberId);
    if (index == -1) {
        printf("Member not found!\n");
        return;
    }
    
    int hasIssuedBooks = 0;
    for (int i = 0; i < issueCount; i++) {
        if (issues[i].memberId == memberId && issues[i].isReturned == 0) {
            hasIssuedBooks = 1;
            break;
        }
    }
    
    if (hasIssuedBooks) {
        printf("Cannot delete member! Member has issued books that are not returned.\n");
        return;
    }
    
    char confirm;
    printf("Are you sure you want to delete '%s'? (y/n): ", members[index].name);
    scanf(" %c", &confirm);
    
    if (confirm != 'y' && confirm != 'Y') {
        printf("Deletion cancelled.\n");
        return;
    }
    
    for (int i = index; i < memberCount - 1; i++) {
        members[i] = members[i + 1];
    }
    memberCount--;
    
    printf("Member deleted successfully!\n");
    saveMembersToFile();
}

void showAllMembers() {
    printf("\n===== ALL REGISTERED MEMBERS =====\n");
    
    if (memberCount == 0) {
        printf("No members registered.\n");
        return;
    }
    
    printf("\n+-----+------------------+---------------------------+---------------+\n");
    printf("| ID  | Name             | Email                     | Phone         |\n");
    printf("+-----+------------------+---------------------------+---------------+\n");
    
    for (int i = 0; i < memberCount; i++) {
        printf("| %3d | %-16s | %-25s | %-13s |\n",
               members[i].id,
               members[i].name,
               members[i].email,
               members[i].phone);
    }
    
    printf("+-----+------------------+---------------------------+---------------+\n");
    printf("\nTotal Members: %d\n", memberCount);
}
