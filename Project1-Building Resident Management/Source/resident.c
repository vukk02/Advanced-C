/*
* File: resident.c
* Author: Vo Huynh Anh Vu
* Date: 15/07/2024
* Description: This file contains all the functions/methods for information management 
*/

#include "..\Header\resident.h"

/*
* Description: Add new member to the end of file csv
* Input: New member
* Output: File csv update
*/

void addMember(const char* filename, Member member) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Unable to open file");
        return;
    }
    fprintf(file, "%s,%s,%s,%s\n", member.uid, member.roomNumber, member.name, member.licensePlate);
    fclose(file);
    printf("Member is added successfully\n");
}

/*
* Description: Delete member information based on UID from CSV file
* Input: UID of member to be deleted
* Output: File csv update
*/

void deleteMember(const char* filename, const char* uid) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file");
        return;
    }

    FILE* tempFile = fopen("temp.csv", "w");
    if (tempFile == NULL) {
        printf("Unable to open temporary file");
        fclose(file);
        return;
    }

    char line[200];
    while (fgets(line, sizeof(line), file)) {
        Member member;
        sscanf(line, "%[^,],%[^,],%[^,],%s", member.uid, member.roomNumber, member.name, member.licensePlate);
        if (strcmp(member.uid, uid) != 0) {
            fprintf(tempFile, "%s", line);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);
    rename("temp.csv", filename);
    printf("Member is deleted successfully\n");
}

/*
* Description: Update member information based on UID in CSV file
* Input: Updated member and UID
* Output: File csv update
*/

void editMember(const char* filename, Member updatedMember) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file");
        return;
    }

    FILE* tempFile = fopen("temp.csv", "w");
    if (tempFile == NULL) {
        printf("Unable to open temporary file");
        fclose(file);
        return;
    }

    char line[200];
    while (fgets(line, sizeof(line), file)) {
        Member member;
        sscanf(line, "%[^,],%[^,],%[^,],%s", member.uid, member.roomNumber, member.name, member.licensePlate);
        if (strcmp(member.uid, updatedMember.uid) == 0) {
            fprintf(tempFile, "%s,%s,%s,%s\n", updatedMember.uid, updatedMember.roomNumber, updatedMember.name, updatedMember.licensePlate);
        } else {
            fprintf(tempFile, "%s", line);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);
    rename("temp.csv", filename);
    printf("Member is edited successfully\n");
}

/*
* Description: Search for member information based on UID or license plate number
* Input: Search value and criteria (UID/License Plate Number)
* Output: Information found or message not found
*/

int searchByUID(const Member* member, const char* uid) {
    return strcmp(member->uid, uid) == 0;
}

int searchByLicensePlate(const Member* member, const char* licensePlate) {
    return strcmp(member->licensePlate, licensePlate) == 0;
}

Member* searchMember(const char* filename, const char* searchValue, int (*searchFunc)(const Member*, const char*)) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file");
        return NULL;
    }

    char line[200];
    while (fgets(line, sizeof(line), file)) {
        Member* member = (Member*)malloc(sizeof(Member));
        sscanf(line, "%[^,],%[^,],%[^,],%s", member->uid, member->roomNumber, member->name, member->licensePlate);
        if (searchFunc(member, searchValue)) {
            fclose(file);
            return member;
        }
        free(member);
    }

    fclose(file);
    return NULL;
}
