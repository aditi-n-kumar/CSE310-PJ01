
#include "list_read.h"
#include "list_write.h"
#include <stdio.h>
#include <stdlib.h>

//RE-CHECK MEMORY ALLOCATION CONDITIONS

void listRelease(LIST *pLIST){ //need to look at again
    NODE *pNODE;
    //NODE *current = pLSIT->head;
    //NODE *next;
    
    if (pLIST == NULL) {
        fprintf(stderr, "Error in releasting list: NULL list\n");
        exit(1);
    }
    
    while (pLIST->head != NULL) {
        pNODE = pLIST->head; //temporary variable
        pLIST->head = pLIST->head->next;
        free(pNODE);
    }

    pLIST->head = NULL;
    pLIST->tail = NULL;
    pLIST->length = 0;
    /*
    while (current == NULL) {
        next = current->next; //setting pointer to the next node
        free(current); //freeing node if NOT null
        current = next; //moving the pointer to the next node
    }*/ 
    //fprintf(stderr, "You need to write the function listRelease\n");
    //Delete and free all the nodes on pLIST
    //memory leakage
    //delete every single node mannually
}


NODE * listInsert(LIST *pLIST, double key){ //at the head
    NODE *pNODE;
    pNODE = NULL;

    if (pLIST == NULL) {
        fprintf(stdout, "NULL list\n");
        return NULL;
    }
    
    pNODE = (NODE*)malloc(sizeof(NODE));
    if (pNODE == NULL) {
        fprintf(stderr, "Failed memory allocation\n");
        return NULL;
    }

    
    pNODE->key = key;
    pNODE->next = pLIST->head;
    pLIST->head = pNODE;
    pLIST->length++;
    //fprintf(stderr, "You need to write the function listInsert\n");
    return pNODE;
}


NODE * listAppend(LIST *pLIST, double key){
    NODE *pNODE;
    pNODE = NULL;

    if (pLIST == NULL) {
        fprintf(stderr, "Error in appending: NULL list\n");
        return NULL;
    }

    pNODE = (NODE*)malloc(sizeof(NODE));
    if (pNODE == NULL) {
        fprintf(stderr, "Failed memory allocation\n");
        return NULL;
    }

    
    pNODE->key = key;
    pNODE->next = NULL;

    if (pLIST->head == NULL) {
        pLIST->head = pNODE;
    }
    else {
        NODE *current = pLIST->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = pNODE;
    }

    pLIST->length += 1;
    //fprintf(stderr, "You need to write the function listAppend\n");
    return pNODE;
}

NODE * listDelete(LIST *pLIST, double key){
    NODE *pNODE = NULL;
    NODE *curr = pLIST->head;
    NODE *prev = NULL;

    // Go through the list to find the node containing the key
    while (curr != NULL) {
        if (curr->key == key) {
            // Key in the node had been found
            if (prev == NULL) {
                pLIST->head = curr->next;
            } else {
                prev->next = curr->next;
            }
            pNODE = curr; 
            pLIST->length -= 1; //Updating the length
            return pNODE;      
        }
        prev = curr;
        curr = curr->next;
        
    }
    // If the key is not found
    printf("Warning in listDelete: Key %.6f not in list\n", key);
    return NULL;
}






/*
NODE * listDelete(LIST *pLIST, double key){ //recheck method
    NODE *pNODE;
    pNODE = NULL;
    
    NODE *previous = NULL;

    if (pLIST->head == NULL) {
        fprintf(stderr, "not in list");
        return NULL;
    }

    pNODE = pLIST->head;

    while (pNODE != NULL && pNODE->key != key) {
        previous = pNODE;
        pNODE = pNODE->next;
        
    }
    /*
    if (pNODE == NULL) {
        fprintf(stderr, "Failed to find key in list\n");
        return NULL;
    }
    */ /*
    if (previous == NULL) {
        pLIST->head = pNODE->next;
        }
        else {
        previous->next = pNODE->next;
    }

    free(pNODE);
    //return pLIST->head; 
    pLIST->length--;

    if (previous != NULL) {
        return previous;
    }
    else {
        return pLIST->head;
    }

    //fprintf(stderr, "You need to write the function listDelete\n");
    //return pNODE;
} 

*/


