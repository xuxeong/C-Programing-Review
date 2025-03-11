#include <stdio.h>
#define MAX 5

int front = -1;
int back = -1;
int count = 0;
int queue[MAX];

int queue_empty(){
    if(count == 0)
        return 1;
    else
        return 0;
}

int queue_full(){
    if(count == MAX)
        return 1;
    else
        return 0;
}

void enqueue(int value){
    if(count == 0){
        front = back = 0;
    }
    else
        back = (back + 1) % MAX;
    queue[back] = value;
    count++;
}

int dequeue(){
    int value = queue[front];
    count--;

    if(count == 0){
        front = -1;
        back = -1;
    }
    else
        front = (front+1) % MAX;
    return value;
}

void print_queue(){
    printf("Elements in Circular Queue are: ");
    if(back >= front){
        for (int i = front; i <= back; i++)
            printf("%d ", queue[i]);
    }
    else{
        for(int i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for(int i = 0; i <= back; i++)
            printf("%d ", queue[i]);
    }
    printf("\n\n");
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

    while(queue_empty() != 1){
        val = dequeue();
        printf("Dequeue: %d\n", val);
    }
    printf("This queue is empty.\n");

    return 0;
}