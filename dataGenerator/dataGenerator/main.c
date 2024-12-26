//
//  main.c
//  dataGenerator
//
//  Created by Gustavo Machado Silva on 23/12/24.
//

#include <stdio.h>
#include "dataGenerator.h"

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    createDataFiles(100);
    
    return 0;
}
