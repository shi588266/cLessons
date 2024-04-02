/**
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void)
{
    Queue que;
    Item item;
    InitializeQueue(&que);
    if (QueueIsFull(&que)) {
        fprintf(stderr, "The queue is full.\n");
        exit(EXIT_FAILURE);
    }
    puts("Enter an integer number:");
    while (scanf("%d", &item) == 1) {
        if(false == EnQueue(item, &que)) {
            fprintf(stderr, "Error, Enqueue incorrectlly.\n");
            exit(EXIT_FAILURE);
        }
        if (QueueIsFull(&que)) {
            puts("The Queue is full");
            break;
        }
        puts("Enter another integer number:");
    }
    puts("Elements in the queue:");
    while (DeQueue(&item, &que)) {
        printf("%d\n", item);
    }
    puts("Done!");
    return 0;
}