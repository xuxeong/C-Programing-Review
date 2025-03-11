#include <stdio.h>

#define MAX 5

int front = -1;
int back = -1;
int count = 0;
int queue[MAX];

int queue_full(){
    if(count == MAX)
        return 1;
    else
        return 0;
}

int queue_empty(){
    if(count == 0)
        return 1;
    else
        return 0;
}

void enqueue(int value){
    if(count == 0)
        front = back = 0;
    else    
        back = back + 1;
    queue[back]= value;
    count++;
}

void repacking_queue(){
    for(int i = front; i < back; i++){
        queue[i] = queue[i+1];    
    }
    front = 0;
    back = back - 1;
}

int dequeue(){
    int value = queue[front];
    count--;

    if(count == 0){
        front = -1;
        back = -1;
    }
    else
        repacking_queue();
    return value;
}

void print_queue(){
    printf("Print a queue: ");

    for(int i = front; i <= back; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main(){
    int val;
    int input_values[] = {10, 40, 15, 35, 50, 20, 25, 50};

    int length = sizeof(input_values)/sizeof(int);

    for(int i = 0; i < length; i++){
        val = input_values[i];
        if(queue_full() != 1){
            enqueue(val);
            printf("Enqueue: %d\n", val);
        }
        else
            printf("Failed to push %d. This queue is full.\n", val);
    }

    print_queue();

    while(queue_empty()!=1){
        val = dequeue();
        printf("Dequeue: %d\n", val);
    }
    printf("This queue is empty.\n");
}