#include "passwordBST.h"

Password* createPasswordTree(void){
    return NULL;
}

//Base: TAD ABP disponibilizado no Moodle
//Adaptações: novo campo "password"
Password* insertPassword(Password* tree, int key, char password[]){
    if (tree == NULL){
        tree =  (Password*) malloc(sizeof(Password));
        tree->key = key;
        strcpy(tree->password, password);
        tree->left = NULL;
        tree->right = NULL;
        return tree;
    }
    else{
        if (key < tree->key)
            tree->left = insertPassword(tree->left, key, password);
        else if (key > tree->key)
            tree->right = insertPassword(tree->right, key, password);
    }
    return tree;
    
}

//Base: TAD ABP disponibilizado no Moodle
Password* findPasswordByKey(Password* tree, int key){
    while (tree != NULL){
        if (tree->key == key ){
            return tree;
        }
        else{
            if (tree->key > key)
                tree = tree->left;
            else
                tree = tree->right;
        }
    }
    return NULL; //not found
}


void destroyPasswordTree(Password *tree){
    Password *node = tree;
    
    if(node != NULL){
        
        destroyPasswordTree(node->left);
        destroyPasswordTree(node->right);
        
        free(node);
    }
}

//Base: TAD ABP disponibilizado no Moodle
void printTreeCentralRight(Password *tree){
    if (tree!= NULL)
    {
        printTreeCentralRight(tree->right);
        printf("KEY: %d - PASSWORD: %s\n", tree->key, tree->password);
        printTreeCentralRight(tree->left);
     }
}



Password* getFileInfo(Password *tree, char *fileName){
    Password* passwordTree = createPasswordTree();
    FILE *file;
    char c = ' ';
    char strId[MAX_CHAR_ID] = "";
    char strPassword[MAX_CHAR_PASSWORD] = "";
    int indexId = 0;
    int indexPassword = 0;
    int key = 0;
        
        
        file = fopen(fileName, "r");
        
        if (file == NULL) {
            printf("Error opening file!");
        }
        else {
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
                key = atoi(strId);
                
                
                strcpy(strPassword, "");
                indexPassword = 0;
                
                do {
                    
                    c = getc(file);
                    
                    if (c != NEW_LINE && c != EOF) {
                        strPassword[indexPassword] = c;
                        indexPassword++;
                    }
                    

                } while (c != NEW_LINE && c != EOF);
                
                
                if (key != 0) {
                    passwordTree = insertPassword(passwordTree, key, strPassword);
                }
                
                
            } while (c != EOF);
            
            
            fclose(file);
        }
        
        return passwordTree;
}
