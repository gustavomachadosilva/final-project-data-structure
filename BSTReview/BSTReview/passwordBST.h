#ifndef passwordABPTree_h
#define passwordABPTree_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD 10
#define ID_ERROR -1
#define MAX_CHAR_ID 10
#define MAX_CHAR_PASSWORD 10
#define STRING_FINAL '\0'
#define SEPARATOR ';'
#define NEW_LINE '\n'

typedef struct passwordType {
    int key;
    char password[MAX_PASSWORD];
    struct passwordType *left, *right;
}Password;

//  Create an empty search tree
Password* createPasswordTree(void);

//  Inserts a new password in password tree
Password* insertPassword(Password* tree, int key, char password[]);

//  Looks for the key in the password tree and returns the password, if it doesn't find the key, returns null.
Password* findPasswordByKey(Password* tree, int key);

//  Free up memory space
void destroyPasswordTree(Password *tree);

//  Print all values in the search tree
void printTreeCentralRight(Password *tree);

//  Get information from a file
Password* getFileInfo(Password *tree, char *fileName);



#endif /* passwordABPTree_h */
