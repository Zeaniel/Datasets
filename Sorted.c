//
//  Sorted.c
//  YSVD_2
//
//  Created by Sotiris Kaniras on 14/01/2017.
//  Copyright © 2017 com.me. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sorted.h"

int Sorted_CreateFile(char* fileName) {
    // -----------------------------------------------
    // Create a new file and then open it
    
    if (BF_CreateFile(fileName) < 0) {
        BF_PrintError("Error creating heap file in Sorted_CreateFile");
        return -1;
    }
    
    // -----------------------------------------------
    // Open it
    
    int fileDesc;
    
    if ((fileDesc = BF_OpenFile(fileName)) < 0) {
        BF_PrintError("Error opening heap file in Sorted_CreateFile");
        return -1;
    }
    
    // -----------------------------------------------
    // Allocate a new block, where the special info
    // will be stored and then read it
    
    void* block;
    
    if (BF_AllocateBlock(fileDesc) < 0) {
        BF_PrintError("Error allocating block in Sorted_CreateFile");
        BF_CloseFile(fileDesc);
        
        return -1;
    }
    
    if (BF_ReadBlock(fileDesc, 0, &block) < 0) {
        BF_PrintError("Error getting block in Sorted_CreateFile");
        BF_CloseFile(fileDesc);
        
        return -1;
    }
    
    // -----------------------------------------------
    // Store the special info to the first block
    
    memcpy(block, &FILE_ID, strlen(FILE_ID));
    
    if (BF_WriteBlock(fileDesc, 0) < 0) {
        BF_PrintError("Error writing to block in Sorted_CreateFile");
        BF_CloseFile(fileDesc);
        
        return -1;
    }
    
    return 0;
}

int Sorted_OpenFile(char* fileName) {
    // -----------------------------------------------
    // Open file
    
    int fileDesc;
    
    if ((fileDesc = BF_OpenFile(fileName)) < 0) {
        BF_PrintError("Error opening heap file in Sorted_OpenFile");
        return -1;
    }
    
    // -----------------------------------------------
    // Retrieve block no 0, where the info of the block
    // is stored
    
    void* block;
    
    if (BF_ReadBlock(fileDesc, 0, &block) < 0) {
        BF_PrintError("Error getting block in Sorted_OpenFile");
        BF_CloseFile(fileDesc);
        
        return -1;
    }
    
    // -----------------------------------------------
    // Copy the retrieved struct to "info"
    
    char* identificationString = malloc(strlen(FILE_ID) + 1);
    memcpy(identificationString, block, strlen(FILE_ID));
    
    if (strcmp(identificationString, FILE_ID) == 0) {
        return fileDesc;
    }
    
    return -1;
}

int Sorted_CloseFile(int fileDesc) {
    if (BF_CloseFile(fileDesc) < 0) {
        BF_PrintError("Error closing heap file in Sorted_CloseFile");
        return -1;
    }
    
    return 0;
}

int Sorted_InsertEntry(int fileDesc, Record record) {
    return 0;
}

void Sorted_SortFile(char* fileName, int fieldNo) {
    
}

void Sorted_checkSortedFile(char* fileName, int fieldNo) {
    
}

void Sorted_GetAllEntries(int fileDesc, int* fieldNo, void* value) {
    
}
