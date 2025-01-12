//
//  main.c
//  ABPTreeReview
//

#include <stdio.h>
#include "passwordTreeAnalyzer.h"
#include "passwordBST.h"

#define MAX_CHAR 100

void updateFileName(char fileName[], int amount);

int main(int argc, const char * argv[]) {
    
    int amount = 10000;
    
    char fileNameOrdered[MAX_CHAR] = "Ordered";
    char fileNameNotOrdered[MAX_CHAR] = "NotOrdered";
    char fileNameConsult[MAX_CHAR] = "Consult";
    char fileNameConsult50[MAX_CHAR] = "Consult50";
    char fileNameConsult80[MAX_CHAR] = "Consult80";
    Password *passwordTreeOrdered = createPasswordTree();
    Password *passwordTreeNotOrdered = createPasswordTree();
    
    updateFileName(fileNameOrdered, amount);
    updateFileName(fileNameNotOrdered, amount);
    updateFileName(fileNameConsult, amount);
    updateFileName(fileNameConsult50, amount);
    updateFileName(fileNameConsult80, amount);
    
    passwordTreeOrdered = getFileInfo(passwordTreeOrdered, fileNameOrdered);
    passwordTreeNotOrdered = getFileInfo(passwordTreeNotOrdered, fileNameNotOrdered);
    
    analyzesPasswordTree(passwordTreeOrdered, fileNameConsult, 1);
    analyzesPasswordTree(passwordTreeOrdered, fileNameConsult50, 1);
    analyzesPasswordTree(passwordTreeOrdered, fileNameConsult80, 1);
    
    analyzesPasswordTree(passwordTreeNotOrdered, fileNameConsult, 0);
    analyzesPasswordTree(passwordTreeNotOrdered, fileNameConsult50, 0);
    analyzesPasswordTree(passwordTreeNotOrdered, fileNameConsult80, 0);
    
    destroyPasswordTree(passwordTreeOrdered);
    destroyPasswordTree(passwordTreeNotOrdered);
    
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
