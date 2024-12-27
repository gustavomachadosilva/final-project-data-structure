//
//  main.c
//  linkedListReview
//
//  Created by Gustavo Machado Silva on 16/12/24.
//

#include <stdio.h>
#include "passwordListAnalyzer.h"
#include "passwordLinkedList.h"

#define MAX_CHAR 100

void updateFileName(char fileName[], int amount);

int main(int argc, const char * argv[]) {
    
    int amount = 100;
    
    char fileNameOrdered[MAX_CHAR] = "Ordered";
    char fileNameNotOrdered[MAX_CHAR] = "NotOrdered";
    char fileNameConsult[MAX_CHAR] = "Consult";
    char fileNameConsult50[MAX_CHAR] = "Consult50";
    char fileNameConsult80[MAX_CHAR] = "Consult80";
    Password *passwordListOrdered = createPasswordList();
    Password *passwordListNotOrdered = createPasswordList();
    
    updateFileName(fileNameOrdered, amount);
    updateFileName(fileNameNotOrdered, amount);
    updateFileName(fileNameConsult, amount);
    updateFileName(fileNameConsult50, amount);
    updateFileName(fileNameConsult80, amount);
    
    passwordListOrdered = getFileInfo(passwordListOrdered, fileNameOrdered);
    passwordListNotOrdered = getFileInfo(passwordListNotOrdered, fileNameNotOrdered);
    
    analyzesPasswordList(passwordListOrdered, fileNameConsult, amount, 1);
    analyzesPasswordList(passwordListOrdered, fileNameConsult50, amount, 1);
    analyzesPasswordList(passwordListOrdered, fileNameConsult80, amount, 1);
    
    analyzesPasswordList(passwordListNotOrdered, fileNameConsult, amount, 0);
    analyzesPasswordList(passwordListNotOrdered, fileNameConsult50, amount, 0);
    analyzesPasswordList(passwordListNotOrdered, fileNameConsult80, amount, 0);
    
    destroyPasswordList(passwordListOrdered);
    destroyPasswordList(passwordListNotOrdered);
    
    return 0;
}

void updateFileName(char fileName[], int amount) {
    
    char newFileName[MAX_CHAR] = "data";
    char amountStr[MAX_CHAR] = "";
    
    sprintf(amountStr, "%d", amount);
    strcat(fileName, ".txt");
    strcat(amountStr, fileName);
    strcat(newFileName, amountStr);
    
    strcpy(fileName, newFileName);
    
}
