//
//  passwordListAnalyzer.c
//  linkedListReview
//


#include "passwordTreeAnalyzer.h"

void analyzesPasswordTree(Password *passwordTree, char dataFileName[], int isOrdered) {
    
    char resultsFileName[100] = "results";
    char dataIsOrdered[100] = "Ordered_";
    char dataIsNotOrdered[100] = "NotOrdered_";
    char strId[MAX_CHAR_ID] = "";
    char strPassword[MAX_CHAR_PASSWORD] = "";
    int indexId = 0;
    int indexPassword = 0;
    char c = ' ';
    int key = 0;
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
    
    //name results file
    if (isOrdered == 1) {
        strcat(resultsFileName, dataIsOrdered);
    }
    else {
        strcat(resultsFileName, dataIsNotOrdered);
    }
    
    strcat(resultsFileName, dataFileName);
    
    //open files
    fileSource = fopen(dataFileName, "r");
    fileDestiny = fopen(resultsFileName, "w");
    
    //file operations
    if (fileSource == NULL || fileDestiny == NULL) {
        printf("Error opening file!\n");
    }
    else {
        
        secondsBegin = clock();
        
        do {
            //reads one key from the file
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
            key = atoi(strId);
            
            //reads one password from the file
            strcpy(strPassword, "");
            indexPassword = 0;
            
            do {
                
                c = getc(fileSource);
                
                if (c != NEW_LINE && c != EOF) {
                    strPassword[indexPassword] = c;
                    indexPassword++;
                }
                

            } while (c != NEW_LINE && c != EOF);
            
            //finds the key of test file on the tree and clocks the time it takes
            if (key != 0) {
                
                seconds1 = clock();
                
                searchPassword = findPasswordByKey(passwordTree, key);
                
                seconds2 = clock();
                
                time_ms_2 = (double)(seconds2 - seconds1) / CLOCKS_PER_SEC * 1000;
                
                //writes data on results file
                if (searchPassword != NULL && (strcmp(searchPassword->password, strPassword) == 0)) {
                    fprintf(fileDestiny, "%d;%s;%.3f\n", key, strOk, time_ms_2);
                }
                else {
                    fprintf(fileDestiny, "%d;%s;%.3f\n", key, strError, time_ms_2);
                }
                
            }
            
            
        } while (c != EOF);
        
        secondsEnd = clock();
        
        time_ms = (double)(secondsEnd - secondsBegin) / CLOCKS_PER_SEC * 1000;
        
        //writes total time
        fprintf(fileDestiny, "%.3f\n", time_ms);
        
        
        
        fclose(fileSource);
        fclose(fileDestiny);
    }
    
    
    
    
}
