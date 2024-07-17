/*
* File: menu.c
* Author: Vo Huynh Anh Vu
* Date: 15/07/2024
* Description: This file contains all the functions/methods for building management 
*/


#include "..\Header\menu.h"
#include "..\Header\resident.h"

/*
* Description: Write value to member
* Input: Member
* Output: Member information update
*/

void input(Member* member)
{
    printf("Enter UID: ");
    scanf("%s",member->uid);
    printf("Enter roomNumber: ");
    scanf("%s",member->roomNumber);
    printf("Enter name: ");
    scanf("%s", member->name);
    printf("Enter licensePlate: ");
    scanf("%s",member->licensePlate);
}

/*
* Description: Add new member to the end of file csv
* Input: Filename
* Output: File csv update
*/

void feature1(const char* filename)
{   
    printf("Feature 1 selected\n");
    printf("Enter the information of member to be added\n");
    Member member;
    input(&member);
    addMember(filename,member);
   
}

/*
* Description: Delete member information based on UID from CSV file
* Input: Filename
* Output: File csv update
*/

void feature2(const char* filename) 
{   
    printf("Feature 2 selected\n"); 
    printf("Enter the uid of the member to be deleted: ");
    char uid[20] = "";
    scanf("%s",uid);
    deleteMember(filename,uid);

}

/*
* Description: Update member information based on UID in CSV file
* Input: Filename
* Output: File csv update
*/

void feature3(const char* filename) 
{ 
    printf("Feature 3 selected\n"); 
    printf("Enter the information of member to be edited ");
    Member updatedMember;
    input(&updatedMember);
    editMember(filename,updatedMember);

}

/*
* Description: Search for member information based on UID or license plate number
* Input: Filename
* Output: Information found or message not found
*/

void feature4(const char* filename) 
{ 
    printf("Feature 4 selected\n");
    again: printf("If you search by uid, press 1, if you search by licensePlate, press 2\n");
    int a ;
    scanf("%d",&a);
    char uid[20], licensePlate[20];
    if (a == 1)
    {
        printf("Enter uid: ");
        scanf("%s",uid);
        Member* foundMember = searchMember(filename,uid, searchByUID);
        if (foundMember == NULL)
        {
            printf("Member not found\n");
        }
        else 
        {
            printf("Found member: %s, %s, %s, %s\n", foundMember->uid, foundMember->roomNumber, foundMember->name, foundMember->licensePlate);
        }
    }
    else if (a == 2)
    {
        printf("Enter licensePlate: ");
        scanf("%s",licensePlate);
        Member* foundMember = searchMember(filename,licensePlate, searchByLicensePlate);
        if (foundMember == NULL)
        {
            printf("Member not found\n");
        }
        else 
        {
            printf("Found member: %s, %s, %s, %s\n", foundMember->uid, foundMember->roomNumber, foundMember->name, foundMember->licensePlate);
        }
    }
    else 
    {
        printf("Invalid input value\n");
        goto again;
    }
}

/*
* Description: Exit the program
* Input: Filename
* Output: Print "Exit the program"
*/

void feature5(const char* filename) 
{
    printf("Exit the program");
}

/*
* Description: Select a feature from menu
* Input: Filename
* Output: Execute the selected feature
*/

void menu(const char* filename)
{
    again: PRINT_MENU("Add member", "Delete member", "Edit member","Search member", "Exit");
    printf("Please select a feature: ");
    int option ;
    scanf("%d", &option);

    HANDLE_OPTION(option,
        CASE_OPTION(1, feature1(filename))
        CASE_OPTION(2, feature2(filename))
        CASE_OPTION(3, feature3(filename))
        CASE_OPTION(4, feature4(filename))
        CASE_OPTION(5, feature5(filename))
    )
    if (option == 5)
    {
        goto end;
    }
    else 
    {
        goto again;
    }
    end:
}