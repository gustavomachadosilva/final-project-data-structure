//
//  dataGenerator.c
//  dataGenerator
//
//  Created by Gustavo Machado Silva on 23/12/24.
//

#include "dataGenerator.h"

void createDataFiles(int amount) {
    
    char amountStr[MAX];
    char fileName[MAX] = "data";
    int id = 1;
    FILE *file;
    Password passwords[amount];
    Password passwordsNotOrdered[amount];
    Password passwordsNotOrderedForConsultation[amount];
    Password passwordsNotOrderedForConsultation50[amount];
    Password passwordsNotOrderedForConsultation80[amount];
    Password aux;
    int i, j;
    int amountPasswords50 = 0;
    int amountPasswords80 = 0;
    
    sprintf(amountStr, "%d", amount);
    strcat(amountStr, "Ordered.txt");
    strcat(fileName, amountStr);
    
    for (i = 0; i < amount; i++) {
        
        passwords[i].id = id;
        createRandomPassword(passwords[i].value);
        id++;
        
    }
    
    for (i = 0; i < amount; i++) {
        
        passwordsNotOrdered[i].id = passwords[i].id;
        strcpy(passwordsNotOrdered[i].value, passwords[i].value);
        
    }
    
    for (i = 0; i < amount; i++) {
        
        j = rand() % amount;
        
        if (i != j) {
            aux.id = passwordsNotOrdered[i].id;
            strcpy(aux.value, passwordsNotOrdered[i].value);
            
            passwordsNotOrdered[i].id = passwordsNotOrdered[j].id;
            strcpy(passwordsNotOrdered[i].value, passwordsNotOrdered[j].value);
            
            passwordsNotOrdered[j].id = aux.id;
            strcpy(passwordsNotOrdered[j].value, aux.value);
        }
        
        
    }
    
    for (i = 0; i < amount; i++) {
        
        passwordsNotOrderedForConsultation[i].id = passwords[i].id;
        strcpy(passwordsNotOrderedForConsultation[i].value, passwords[i].value);
        
    }
    
    for (i = 0; i < amount; i++) {
        
        j = rand() % amount;
        
        if (i != j) {
            aux.id = passwordsNotOrderedForConsultation[i].id;
            strcpy(aux.value, passwordsNotOrderedForConsultation[i].value);
            
            passwordsNotOrderedForConsultation[i].id = passwordsNotOrderedForConsultation[j].id;
            strcpy(passwordsNotOrderedForConsultation[i].value, passwordsNotOrderedForConsultation[j].value);
            
            passwordsNotOrderedForConsultation[j].id = aux.id;
            strcpy(passwordsNotOrderedForConsultation[j].value, aux.value);
        }
        
        
    }
    
    for (i = 0; i < amount; i++) {
        
        j = rand() % 2;
        
        passwordsNotOrderedForConsultation50[i].id = passwordsNotOrderedForConsultation[i].id;
        
        if (amountPasswords50 <= (amount / 2) && j == 1) {
            strcpy(passwordsNotOrderedForConsultation50[i].value, "AAABBBCCC");
            amountPasswords50++;
        }
        else {
            strcpy(passwordsNotOrderedForConsultation50[i].value, passwordsNotOrderedForConsultation[i].value);
        }
        
    }
    
    
    for (i = 0; i < amount; i++) {
        
        j = rand() % 2;
        
        passwordsNotOrderedForConsultation80[i].id = passwordsNotOrderedForConsultation[i].id;
        
        if (amountPasswords80 <= (amount * 0.8) && j == 1) {
            strcpy(passwordsNotOrderedForConsultation80[i].value, "AAABBBCCC");
            amountPasswords80++;
        }
        else {
            strcpy(passwordsNotOrderedForConsultation80[i].value, passwordsNotOrderedForConsultation[i].value);
        }
        
    }
    
    

    
    
    file = fopen(fileName, "w");
    
    if (file == NULL) {
        printf("Error creating file!\n");
    }
    else {
        
        for (i = 0; i < amount; i++) {
            fprintf(file, "%d;%s\n", passwordsNotOrderedForConsultation50[i].id, passwordsNotOrderedForConsultation50[i].value);
        }
        
        fclose(file);
    }
    
    
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
