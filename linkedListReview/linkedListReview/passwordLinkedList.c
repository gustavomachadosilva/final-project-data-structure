//
//  passwordLinkedList.c
//  linkedListReview
//
//  Created by Gustavo Machado Silva on 16/12/24.
//

#include "passwordLinkedList.h"

Password* createPasswordList(void) {
    return NULL;
}

Password* insertPassword(Password* list, int id, char password[]) {
    
    Password *newPassword = (Password*) malloc(sizeof(Password));
    newPassword->id = id;
    strcpy(newPassword->password, password);
    newPassword->next = NULL;
    
    Password *currentPassword = list;
    
    if (currentPassword == NULL) {
        return newPassword;
    }
    
    while (currentPassword->next != NULL) {
        currentPassword = currentPassword->next;
    }
    
    currentPassword->next = newPassword;
    
    return list;
    
}

Password* findPasswordById(Password* list, int id) {
    
    Password *currentPassword = list;
    
    while (currentPassword != NULL && currentPassword->id != id) {
        currentPassword = currentPassword->next;
    }
    
    if (currentPassword == NULL) {
        return NULL;
    }
    else {
        return currentPassword;
    }
    
}

void destroyPasswordList(Password *list) {
    
    Password *currentPassword = list;
    Password *aux = list;
    
    
    while (currentPassword != NULL) {
        aux = currentPassword;
        currentPassword = currentPassword->next;
        free(aux);
    }
    
}
