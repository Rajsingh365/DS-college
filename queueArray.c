#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int capacity, front, rear;
    int *ptr;
};
struct Queue *createQueue(int cap);
void Enqueue(struct Queue **q, int data);
void dequeue(struct Queue **q);
int getFront(struct Queue *q);
int getRear(struct Queue *q);
char isFull(struct Queue *q);
char isEmpty(struct Queue *q);
void displayQueue(struct Queue *q);
void main()
{
    int cap, option_value, data;
    printf("Enter the size of queue: ");
    scanf("%d", &cap);
    struct Queue *queue = createQueue(cap);
    while (1)
    {
        printf("Enter Your Choice: \n");
        printf("1. Enqueue\n2. Dequeue\n3. getFront\n4. getRear\n5. isFull\n6. isEmpty\n7. Display\n8. Exit\n");
        scanf("%d", &option_value);
        switch (option_value)
        {
        case 1:
            printf("Enter a Number: ");
            scanf("%d",&data);
            Enqueue(&queue,data);
            break;
        case 2:
            dequeue(&queue);
            break;
        case 3:
            printf("front Element: %d\n",getFront(queue));
            printf("\n");
            break;
        case 4:
            printf("Rear Element: %d\n",getRear(queue));
            printf("\n");
            break;
        case 5:
            if(isFull(queue)=='a')
                printf("Queue OverFlow\n");
            else
                printf("Queue is not full\n");
            break;
        case 6:
            if(isEmpty(queue)=='a')
                printf("Queue UnderFlow\n");
            else
                printf("Queue is not Empty\n");
            break;
        case 7:
            displayQueue(queue);
            break;
        case 8:
            exit(0);
        }
    }
}
struct Queue *createQueue(int cap)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = cap;
    queue->front = queue->rear = -1;
    queue->ptr = (int *)malloc(sizeof(int) * cap);
    return queue;
}
void Enqueue(struct Queue **q, int data)
{
    if ((*q)->rear == (*q)->capacity - 1)
    {
        (*q)->rear = 0;
        (*q)->ptr[(*q)->rear] = data;
    }
    else
    {
        if ((*q)->front == -1 && (*q)->rear == -1)
        {
            (*q)->front = 0;
        }
        (*q)->ptr[++(*q)->rear] = data;
    }
}
void dequeue(struct Queue **q)
{
    if((*q)->front==(*q)->rear)
        (*q)->front=(*q)->rear=-1;
    else if((*q)->front==(*q)->capacity-1)
        (*q)->front=0;
    else
        (*q)->front++;
}
int getFront(struct Queue *q)
{
    return q->ptr[q->front];
}
int getRear(struct Queue *q)
{
    return q->ptr[q->rear];
}
char isFull(struct Queue *q)
{
    if(((q->front==0)&&(q->rear==q->capacity-1))||((q->rear+1)==(q->front)))
        return 'a';
    return 'z';
}
char isEmpty(struct Queue *q)
{
    if((q->front==0&&q->rear==0))
        return 'a';
    return 'z';
}
void displayQueue(struct Queue *q)
{
    int i;
    printf("Queue is: \n");
    if(q->front<=q->rear)
    {
        for(i=q->front;i<=q->rear;i++)
        printf("%d \n", q->ptr[i]);
    }
    else
    {
    for(i=q->front;i<q->capacity;i++)
        printf("%d \n", q->ptr[i]);

    for (i = 0; i <= q->rear; i++)
        printf("%d \n", q->ptr[i]);
    }
}