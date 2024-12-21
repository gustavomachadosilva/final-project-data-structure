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

#define MAX 9
#define ID_ERROR -1

typedef struct passwordType {
    int id;
    char password[MAX];
    struct passwordType *next;
} Password;

Password* insertPassword(Password* list, int id, char password[]);


#endif /* passwordLinkedList_h */
