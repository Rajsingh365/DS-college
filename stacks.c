#include <stdio.h>
#include <stdlib.h>

struct student
{
    int rollno;
};
struct stack
{
    unsigned top, MAX;
    struct student *arr;
};
char IsEmpty(struct stack *s);
char IsFull(struct stack *s);
void push(struct stack *s, struct student temp);
unsigned peek(struct stack *s);
struct student pop(struct stack **s);
void print_stack(struct stack *s);
void main()
{
    struct stack s1, s2;
    struct student temp;
    struct stack *ptr_to_stack = NULL;
    int stack_option, operation, index;
    s1.top = s2.top = 0;
stackchoose:
    printf("Which stack you wanna operate ? \n");
    printf("Press 1 for \"stack 1\" \nPress 2 for \"stack 2\" \n");
    scanf("%d", &stack_option);
    if (stack_option == 1)
    {
        printf("Enter the size\n");
        scanf("%d", &s1.MAX);
        s1.arr = (struct student *)malloc((s1.MAX) * sizeof(struct student));
        ptr_to_stack = &s1;
    }
    else if (stack_option == 2)
    {
        printf("Enter the size\n");
        scanf("%d", &s2.MAX);
        s2.arr = (struct student *)malloc((s2.MAX) * sizeof(struct student));
        ptr_to_stack = &s2;
    }
    else
    {
        printf("Please Enter a valid choice ");
        goto stackchoose;
    }
    while (1)
    {
        printf("\n\nMention operations ? \n");
        printf("1) Check whether stack is empty or not \n");
        printf("2) Check whether stack is full or not \n");
        printf("3) Push an Element into the stack \n");
        printf("4) POP an Element from stack \n");
        printf("5) Peek into the stack \n");
        printf("6) Print Stack \n");
        printf("7) Exit \n");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            if (IsEmpty(ptr_to_stack))
                printf("Stack is Empty\n");
            else
                printf("Stack is Not Empty\n");
            break;
        case 2:
            if (IsFull(ptr_to_stack))
                printf("Stack is full\n");
            else
                printf("Stack is not Full\n");
            break;
        case 3:
            if (IsFull(ptr_to_stack))
                printf("STACK OVERFLOW, cannot PUSH\n");
            else
            {
                printf("Enter Your Roll no.: \n");
                scanf("%d", &temp.rollno);
                push(ptr_to_stack, temp);
            }
            break;
        case 4:
            if (IsEmpty(ptr_to_stack))
                printf("STACK UNDERFLOW, cannot pop\n");
            else
            {
                temp=pop(&ptr_to_stack);
                printf("Popped Student Roll No.: is %d",temp.rollno);
            }
            break;
        case 5:
            if (IsEmpty(ptr_to_stack))
                printf("STACK UNDERFLOW, cannot peek\n");
            else
            {
                index = peek(ptr_to_stack);
                printf("Last Roll No.: was %d", ptr_to_stack->arr[index]);
            }
            break;
        case 6:            
            if (IsEmpty(ptr_to_stack))
                printf("STACK UNDERFLOW\n");
            else
                print_stack(ptr_to_stack);
            break;
        case 7:
            exit(0);
        }
    }
}
char IsEmpty(struct stack *s)
{
    return s->top == 0;
}
char IsFull(struct stack *s)
{
    return s->top + 1 == s->MAX;
}
void push(struct stack *s, struct student temp)
{
    s->top++;
    s->arr[s->top] = temp;
}
unsigned peek(struct stack *s)
{
    return s->top;
}
struct student pop(struct stack **s)
{
    struct student temp;
    temp=(*s)->arr[peek(*s)];
    (*s)->top--;
    return temp;
}
void print_stack(struct stack *s)
{
    int i;
    for(i=1;i<=s->top;i++)
        printf("%d ",s->arr[i]);
}