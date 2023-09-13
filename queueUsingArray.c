#include <stdio.h>
#include <stdlib.h>

struct student
{
    int rollno;
};
struct queue
{
    int first_index, last_index;
    unsigned size;
    struct student *arr;
};
int IsEmpty(struct queue *q);
int IsFull(struct queue *q);
void Enqueue(struct queue *q,struct student s);
struct student dequeue(struct queue *q);
struct student peek_front(struct queue *q);
struct student peek_end(struct queue *q);
void printQueue(struct queue *q);
void main()
{
    int choice_operation, rollno,queue_option;
    struct queue q1,q2;
    struct queue *ptr_to_queue;
    struct student s;
    q1.first_index =q2.first_index= 0;
    q1.last_index = q2.last_index=-1;
    q1.arr=q2.arr=NULL;
    printf("Which queue you wanna operate?\n");
    scanf("%d",&queue_option);
    switch(queue_option)
    {
        case 1: 
            printf("\nEnter the maximum size of first queue : ");
            scanf("%d",&q1.size);
            q1.arr=(struct student *)malloc(q1.size*sizeof(struct student));
            ptr_to_queue=&q1;
            break;
        case 2: 
            printf("\nEnter the maximum size of the second queue : ");
            scanf("%d",&q2.size);
            ptr_to_queue=&q2;
    }
    while (1)
    {
        printf("\nEnter your choice : ");
        printf("\n1. Enqueue\n2. Dequeue\n3. Check whether queue is empty\n4. Check whether the queue is full\n5. Peek Front\n6. Peek End\n7. Print Queue \n8. Exit\n");
        scanf("%d", &choice_operation);
        switch (choice_operation)
        {
        case 1:
            if(IsFull(ptr_to_queue))
                printf("Cannot Enqueue");
            else 
            {
                printf("Enter Your Roll No. : ");
                scanf("%d", &s.rollno);
                Enqueue(ptr_to_queue,s);
            }
            break;
        case 2:
        if(IsEmpty)
            printf("Cannot Delete!");
        else
            {
                s=dequeue(ptr_to_queue);
                printf("Dequeued Element is %d",s.rollno);
            }
            break;
        case 3:
            if (IsEmpty(ptr_to_queue))
                printf("UNDERFLOW");
            else
                printf("Queue is not Empty");
            break;
        case 4:
            if (IsFull(ptr_to_queue))
                printf("OVERFLOW");
            else
                printf("Queue is not filled");
            break;
        case 5:
            if(IsEmpty(ptr_to_queue))
                printf("UNDERFLOW");
            else
            {
                s=peek_front(ptr_to_queue);
                printf("Front Student Roll No. : %d",s.rollno);
            }
            break;
        case 6:
            if (IsEmpty(ptr_to_queue))
                printf("UNDERFLOW");
            else
            {
                s=peek_end(ptr_to_queue);
                printf("Last Student Roll No.: %d",s.rollno);
            }
            break;
        case 7:
            printQueue(ptr_to_queue);
            break;
        case 8:
            exit(0);
        }
    }
}
void Enqueue(struct queue *q,struct student s)
{
    q->last_index++;
    q->arr[q->last_index]=s;
}
int IsEmpty(struct queue *q)
{
    return q->first_index > q->last_index;
}
int IsFull(struct queue *q)
{
    return (int)q->size - 1 == q->last_index;
}
struct student dequeue(struct queue *q)
{
    struct student s;
    s=q->arr[q->first_index];
    q->first_index++;
    return s;
}
struct student peek_front(struct queue *q)
{
    return q->arr[q->first_index];
}
struct student peek_end(struct queue *q)
{
    return q->arr[q->last_index];
}
void printQueue(struct queue *q)
{
    int i;
    for(i=q->first_index;i<=q->last_index;i++)
        printf("%d ",q->arr[i]);
}
