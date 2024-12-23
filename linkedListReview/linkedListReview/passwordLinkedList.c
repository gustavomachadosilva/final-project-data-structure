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

Password* insertPassword(Password* list, int id, char *password) {
    
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

void printList(Password *list) {
    
    Password *current = list;
    
    while (current != NULL) {
        printf("ID: %d - PASSWORD: %s\n", current->id, current->password);
        current = current->next;
    }
    
}


Password* getFileInfo(Password *list, char *fileName) {
    
    Password* passwordList = createPasswordList();
    FILE *file;
    char c = ' ';
    char strId[MAX_CHAR_ID] = "";
    char strPassword[MAX_CHAR_PASSWORD] = "";
    int indexId = 0;
    int indexPassword = 0;
    int id = 0;
    
    
    file = fopen(fileName, "r");
    
    if (file == NULL) {
        printf("Error opening file!");
    }
    else {
        do {
            
            strcpy(strId, "");
            indexId = 0;
            
            do {
            
                c = getc(file);
                
                if (c != SEPARATOR && c != EOF) {
                    strId[indexId] = c;
                    indexId++;
                }
                
            } while (c != SEPARATOR && c != EOF);
            
            strId[indexId] = STRING_FINAL;
            id = atoi(strId);
            
            
            strcpy(strPassword, "");
            indexPassword = 0;
            
            do {
                
                c = getc(file);
                
                if (c != NEW_LINE && c != EOF) {
                    strPassword[indexPassword] = c;
                    indexPassword++;
                }
                

            } while (c != NEW_LINE && c != EOF);
            
            
            if (id != 0) {
                passwordList = insertPassword(passwordList, id, strPassword);
            }
            
            
        } while (c != EOF);
        
        
        fclose(file);
    }
    
    return passwordList;
    
}
