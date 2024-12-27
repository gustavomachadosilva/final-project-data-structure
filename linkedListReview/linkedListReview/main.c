//
//  main.c
//  linkedListReview
//
//  Created by Gustavo Machado Silva on 16/12/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "passwordLinkedList.h"
#include <time.h>

int main(int argc, const char * argv[]) {
    
    Password *passwordList = createPasswordList();
    Password *searchPassword;
    char fileName[100] = "data10000Ordered.txt";
    char fileNameTest[100] = "data10000Consult50.txt";
    char fileNameExit[100] = "data10000Results.txt";
    FILE *file;
    FILE *fileResult;
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
    
    
    
    passwordList = getFileInfo(passwordList, fileName);
    
    file = fopen(fileNameTest, "r");
    fileResult = fopen(fileNameExit, "w");
    
    if (file == NULL) {
        printf("Error opening fileTest!");
    }
    else if (fileResult == NULL) {
        printf("Error opening fileResult!");
    }
    else {
        
        secondsBegin = clock();
        
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
                
                seconds1 = clock();
                
                searchPassword = findPasswordById(passwordList, id);
                
                seconds2 = clock();
                
                time_ms_2 = (double)(seconds2 - seconds1) / CLOCKS_PER_SEC * 1000;
                
                if (searchPassword != NULL && (strcmp(searchPassword->password, strPassword) == 0)) {
                    fprintf(fileResult, "%d;%s;%.3f\n", id, strOk, time_ms_2);
                }
                else {
                    fprintf(fileResult, "%d;%s;%.3f\n", id, strError, time_ms_2);
                }
                
            }
            
            
        } while (c != EOF);
        
        secondsEnd = clock();
        
        time_ms = (double)(secondsEnd - secondsBegin) / CLOCKS_PER_SEC * 1000;
        
        fprintf(fileResult, "%.3f\n", time_ms);
        
        fclose(file);
        fclose(fileResult);
    }
    
    
    destroyPasswordList(passwordList);
    
    return 0;
}
