//
//  main.c
//  linkedListReview
//
//  Created by Gustavo Machado Silva on 16/12/24.
//

#include <stdio.h>
#include <stdlib.h>
#include "passwordLinkedList.h"

int main(int argc, const char * argv[]) {
    
    Password *passwordList = createPasswordList();
    char fileName[100] = "test100Ordered.txt";
    
    passwordList = getFileInfo(passwordList, fileName);
    
    printList(passwordList);
    
    destroyPasswordList(passwordList);
    
    return 0;
}
