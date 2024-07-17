/*
* File: resident.h
* Author: Vo Huynh Anh Vu
* Date: 15/07/2024
* Description: This file is a menu header file that is used to manage information
*/

#ifndef __resident_h
#define __resident_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
*Struct: Member
*Description: This struct contains basic information of a Member object including UID, roomNumber, name, licensePlate 
*/

typedef struct {
 char uid[20]; // UID của RFID
 char roomNumber[10]; // Số Phòng
 char name[50]; // Tên
 char licensePlate[20]; // Biển Số Xe
} Member;

void addMember(const char* filename, Member member);
void deleteMember(const char* filename, const char* uid);
void editMember(const char* filename, Member updatedMember);
int searchByUID(const Member* member, const char* uid);
int searchByLicensePlate(const Member* member, const char* licensePlate);
Member* searchMember(const char* filename, const char* searchValue, int (*searchFunc)(const Member*, const char*));


#endif