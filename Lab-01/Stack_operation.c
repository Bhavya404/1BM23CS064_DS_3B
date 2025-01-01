#include<stdio.h>
#include<conio.h>
#define SIZE 5
void push(int);
void pop();
void display();
intstack[SIZE],top=-1;
void main()
{
  int choice,value;
  int clrscr();
  while(1)
  {
    printf("\nMENU\n");
    printf("1.push\n 2.pop\n 3.display\n 4.exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1: printf("Enter the value to be inserted: ");
    scanf("%d",&value);
    push(value);
    break;
    case 2:pop();
    break;
    case 3:display();
    break;
    case 4: exit(0);
    default:printf("WRONG SELECTION");
    }
  }
}
void push(int value)
{
  if(top==SIZE-1)
  {
    printf("Stack is full");
  }
  else
  {
    top++;
    stack[top]=value;
    printf("Insertion successful");
  }
}
void pop()
{
  if(top==-1)
  {
    printf("Stack is empty");
  }
  else
  {
    printf("deleted=%d",stack[top]);
    top--;
  }
}
void display()
{
  if(top==-1)
  {
    printf("stack is empty,underflow");
  }
  else
  {
    int i;
    printf("stack elements are:");
    for(i=top;i>=0;i--)
    {
      printf("%d",stack[i]);
    }
  }
}
