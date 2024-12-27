//
//  passwordListAnalyzer.c
//  linkedListReview
//
//  Created by Gustavo Machado Silva on 27/12/24.
//

#include "passwordListAnalyzer.h"

void analyzesPasswordList(Password *passwordList, char dataFileName[],  int amount, int isOrdered) {
    
    char resultsFileName[100] = "results";
    char dataIsOrdered[100] = "Ordered_";
    char dataIsNotOrdered[100] = "NotOrdered_";
    char strId[MAX_CHAR_ID] = "";
    char strPassword[MAX_CHAR_PASSWORD] = "";
    int indexId = 0;
    int indexPassword = 0;
    char c = ' ';
    int id = 0;
    char strOk[3] = "OK";
    char strError[6] = "Error";
    clock_t secondsBegin;
    clock_t secondsEnd;
    double time_ms;
    clock_t seconds1;
    clock_t seconds2;
    double time_ms_2;
    FILE *fileSource;
    FILE *fileDestiny;
    Password *searchPassword;
    
    if (isOrdered == 1) {
        strcat(resultsFileName, dataIsOrdered);
    }
    else {
        strcat(resultsFileName, dataIsNotOrdered);
    }
    
    strcat(resultsFileName, dataFileName);
    
    fileSource = fopen(dataFileName, "r");
    fileDestiny = fopen(resultsFileName, "w");
    
    if (fileSource == NULL || fileDestiny == NULL) {
        printf("Error opening file!\n");
    }
    else {
        
        secondsBegin = clock();
        
        do {
            
            strcpy(strId, "");
            indexId = 0;
            
            do {
            
                c = getc(fileSource);
                
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
                
                c = getc(fileSource);
                
                if (c != NEW_LINE && c != EOF) {
                    strPassword[indexPassword] = c;
                    indexPassword++;
                }
                

            } while (c != NEW_LINE && c != EOF);
            
            
            if (id != 0) {
                
                seconds1 = clock();
                
                searchPassword = findPasswordById(passwordList, id);
                
                seconds2 = clock();
                
                time_ms_2 = (double)(seconds2 - seconds1) / CLOCKS_PER_SEC * 1000;
                
                if (searchPassword != NULL && (strcmp(searchPassword->password, strPassword) == 0)) {
                    fprintf(fileDestiny, "%d;%s;%.3f\n", id, strOk, time_ms_2);
                }
                else {
                    fprintf(fileDestiny, "%d;%s;%.3f\n", id, strError, time_ms_2);
                }
                
            }
            
            
        } while (c != EOF);
        
        secondsEnd = clock();
        
        time_ms = (double)(secondsEnd - secondsBegin) / CLOCKS_PER_SEC * 1000;
        
        fprintf(fileDestiny, "%.3f\n", time_ms);
        
        
        
        fclose(fileSource);
        fclose(fileDestiny);
    }
    
    
    
    
}
