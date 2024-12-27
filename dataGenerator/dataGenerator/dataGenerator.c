//
//  dataGenerator.c
//  dataGenerator
//
//  Created by Gustavo Machado Silva on 23/12/24.
//

#include "dataGenerator.h"

void createDataFiles(int amount) {
    
    char fileNameOrdered[MAX] = "Ordered";
    char fileNameNotOrdered[MAX] = "NotOrdered";
    char fileNameConsult[MAX] = "Consult";
    char fileNameConsult50[MAX] = "Consult50";
    char fileNameConsult80[MAX] = "Consult80";
    int id = INITIAL_ID;
    Password passwords[amount];
    Password passwordsNotOrdered[amount];
    Password passwordsNotOrderedForConsultation[amount];
    Password passwordsNotOrderedForConsultation50[amount];
    Password passwordsNotOrderedForConsultation80[amount];
    int i;
    
    updateFileName(fileNameOrdered, amount);
    updateFileName(fileNameNotOrdered, amount);
    updateFileName(fileNameConsult, amount);
    updateFileName(fileNameConsult50, amount);
    updateFileName(fileNameConsult80, amount);
    
    for (i = 0; i < amount; i++) {
        
        passwords[i].id = id;
        createRandomPassword(passwords[i].value);
        id++;
        
    }
    
    shuffleData(passwordsNotOrdered, passwords, amount);
    shuffleData(passwordsNotOrderedForConsultation, passwords, amount);
    
    implementWrongValues(passwordsNotOrderedForConsultation50, passwordsNotOrderedForConsultation, amount, FIRST_PERCENTAGE);
    implementWrongValues(passwordsNotOrderedForConsultation80, passwordsNotOrderedForConsultation, amount, SECOND_PERCENTAGE);
    
    putValuesInTheFile(passwords, fileNameOrdered, amount);
    putValuesInTheFile(passwordsNotOrdered, fileNameNotOrdered, amount);
    putValuesInTheFile(passwordsNotOrderedForConsultation, fileNameConsult, amount);
    putValuesInTheFile(passwordsNotOrderedForConsultation50, fileNameConsult50, amount);
    putValuesInTheFile(passwordsNotOrderedForConsultation80, fileNameConsult80, amount);
    
}


void createRandomPassword(char password[]) {
    
    int position = 0;
    
    strcpy(password, "");
    
    while (position < (MAX_PASSWORD_CHAR - 1)) {
        
        password[position] = getRandomUppercaseLetter();
        position++;
        
        password[position] = getRandomLowercaseLetter();
        position++;
        
        password[position] = getRandomNumber();
        position++;
        
    }
    
    password[position] = '\0';
    
}


char getRandomUppercaseLetter(void) {
    
    char uppercaseLetters[MAX_CHAR] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int randomPosition = rand() % (MAX_CHAR - 1);
    
    return uppercaseLetters[randomPosition];
    
}


char getRandomLowercaseLetter(void) {
    
    char lowercaseLetters[MAX_CHAR] = "abcdefghijklmnopqrstuvwxyz";
    int randomPosition = rand() % (MAX_CHAR - 1);
    
    return lowercaseLetters[randomPosition];
    
}


char getRandomNumber(void) {
    
    char numbers[MAX_NUMBERS + 1] = "0123456789";
    int randomPosition = rand() % (MAX_NUMBERS);
    
    return numbers[randomPosition];
    
}


void updateFileName(char fileName[], int amount) {
    
    char newFileName[MAX] = "data";
    char amountStr[MAX] = "";
    
    sprintf(amountStr, "%d", amount);
    strcat(fileName, ".txt");
    strcat(amountStr, fileName);
    strcat(newFileName, amountStr);
    
    strcpy(fileName, newFileName);
    
}


void shuffleData(Password destiny[], Password source[], int amount) {
    
    int i, j;
    Password aux;
    
    for (i = 0; i < amount; i++) {
        
        destiny[i].id = source[i].id;
        strcpy(destiny[i].value, source[i].value);
        
    }
    
    for (i = 0; i < amount; i++) {
        
        j = rand() % amount;
        
        if (i != j) {
            aux.id = destiny[i].id;
            strcpy(aux.value, destiny[i].value);
            
            destiny[i].id = destiny[j].id;
            strcpy(destiny[i].value, destiny[j].value);
            
            destiny[j].id = aux.id;
            strcpy(destiny[j].value, aux.value);
        }
        
        
    }
    
}


void implementWrongValues(Password destiny[], Password source[], int amount, float percentageWrongValues) {
    
    int i, j;
    int amountWrongPasswords = 0;
    
    for (i = 0; i < amount; i++) {
        
        destiny[i].id = source[i].id;
        strcpy(destiny[i].value, source[i].value);
        
    }
    
    while (amountWrongPasswords < (amount * percentageWrongValues)) {
        j = rand() % amount;
        
        if (strcmp(destiny[j].value, "AAABBBCCC") != 0) {
            strcpy(destiny[j].value, "AAABBBCCC");
            amountWrongPasswords++;
        }
        
    }
    
}


void putValuesInTheFile(Password passwords[], char fileName[], int amount) {
    
    FILE *file;
    int i;
    
    file = fopen(fileName, "w");
    
    if (file == NULL) {
        printf("Error opening file: %s", fileName);
    }
    else {
        
        for (i = 0; i < amount; i++) {
            fprintf(file, "%d;%s\n", passwords[i].id, passwords[i].value);
        }
        
        fclose(file);
    }
    
}
