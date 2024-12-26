//
//  dataGenerator.h
//  dataGenerator
//
//  Created by Gustavo Machado Silva on 23/12/24.
//

#ifndef dataGenerator_h
#define dataGenerator_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 100
#define MAX_CHAR 27
#define MAX_NUMBERS 10
#define MAX_PASSWORD_CHAR 10

typedef struct password {
    int id;
    char value[MAX_PASSWORD_CHAR];
} Password;


void createDataFiles(int amount);
void createRandomPassword(char password[]);
char getRandomUppercaseLetter(void);
char getRandomLowercaseLetter(void);
char getRandomNumber(void);

#endif /* dataGenerator_h */
