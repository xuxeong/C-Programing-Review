//linked list (dummy head, static node array alocation)

#define DEBUG
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 10

struct NODE{
    int key;
    struct NODE* next;
}node[MAXNUM];

void InitNode();
struct NODE* CreateNode();
int InsertKey(struct NODE*, int);
int DeleteKey(struct NODE*, int);
void ScanList(struct NODE*);

int main(){
    int ret;
    int input_values[] = {10, 20, 30, 20, 40, 5, 50};

    int length = sizeof(input_values)/sizeof(int);

    #ifdef DEBUG
    printf("The length of input_values is: %d\n", length);
    #endif

    InitNode();
    #ifdef DEBUG
    printf("Create a dummy head node.\n");
    #endif
    struct NODE* head = CreateNode();
    head->key = -100;
    head->next = NULL;

    for (int i = 0; i < length; i++){
        ret = InsertKey(head, input_values[i]);

        #ifdef DEBUG
        if(ret == 0)
            printf("Succeeded to insert the key value: %d\n", input_values[i]);
        else   
            printf("Failed to insert the key value: %d\n", input_values[i]);
        ScanList(head);
        #endif
    }

    #ifdef DEBUG
    printf("\nFinal Result\n");
    #endif
    ScanList(head);

    return 0;
} 

void InitNode(){
    for (int i =0; i < MAXNUM; i++){
        node[i].key = -1;
        node[i].next = NULL;
    }
}

struct NODE* CreateNode(){
    for (int i = 0; i < MAXNUM; i++){
        if(node[i].key == -1){
            #ifdef DEBUG
            printf("Return an unused node address: node[%d],\n", i);
            #endif
            return &node[i];
        }
    }

    #ifdef DEBUG
    printf("Memory is full.\n");
    #endif

    return NULL;
}

int InsertKey(struct NODE* head, int value){
    #ifdef DEBUG
    printf("\nInsert Value: %d\n", value);
    #endif

    struct NODE* ptr = head->next, * prev_ptr = head, * new_node = NULL;
    while(ptr){
        if(ptr->key > value)
            break;
        else if(ptr->key == value){
            #ifdef DEBUG
            printf("The input key already exists.\n");
            #endif
            return -1;
        }

        #ifdef DEBUG
        printf("Key value of the curent node: %d\n", ptr->key);
        #endif
        prev_ptr = ptr;
        ptr = ptr->next;
    }
    #ifdef DEBUG
    printf("Create a new node.\n");

    #endif
    new_node = CreateNode();

    if(new_node != NULL){
        new_node->key = value;
        prev_ptr->next = new_node;
        new_node->next = ptr;
        return 0;
    }
    else{
        #ifdef DEBUG
        printf("Fail to create a new node.\n");
        #endif
        return -1;
    }
}

void ScanList(struct NODE* head){
    printf("\n-----Start ScanList-----\n");
    struct NODE* ptr = head->next;

    int i = 0;
    while(ptr != NULL){
        printf("The %d-th node's key value: %d\n", i, ptr->key);
        ptr = ptr->next;
        i++;
    }
    printf("-------End ScanList------\n\n");
}