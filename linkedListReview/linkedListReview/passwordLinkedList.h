//
//  passwordLinkedList.h
//  linkedListReview
//
//  Created by Gustavo Machado Silva on 16/12/24.
//

#ifndef passwordLinkedList_h
#define passwordLinkedList_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define ID_ERROR -1
#define MAX_CHAR_ID 10
#define MAX_CHAR_PASSWORD 10
#define STRING_FINAL '\0'
#define SEPARATOR ';'
#define NEW_LINE '\n'

typedef struct passwordType {
    int id;
    char password[MAX];
    struct passwordType *next;
} Password;

//  Create an empty list
Password* createPasswordList(void);

//  Create a new password in password list
Password* insertPassword(Password* list, int id, char password[]);

//  Looks for the id in the password list and returns the password, if it doesn't find the id it returns null.
Password* findPasswordById(Password* list, int id);

//  Free up memory space
void destroyPasswordList(Password *list);

//  Print all values in the list
void printList(Password *list);

//  Get information from a file
Password* getFileInfo(Password *list, char *fileName);

#endif /* passwordLinkedList_h */
