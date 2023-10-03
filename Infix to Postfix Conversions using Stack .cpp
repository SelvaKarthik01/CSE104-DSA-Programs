/* Infix to Postfix Conversion using Stack as an Applications */
#include<iostream>
#include<cstring>
using namespace std;
struct node
{
 int data;
 node *link;
};
struct Stack
{
 int count;
 node *top;
};
class StackEx
{
 Stack *slist;
 public :
 StackEx()
 {
  slist = NULL;
 }
 char postFixExpr[100];
 int strcount = 0;
 void CreateStack()
 {
  slist = new Stack;
  slist->count = 0;
  slist->top = NULL;
 }
 bool EmptyStack()
 {
  if(slist->count == 0)
  {
   return true;
  }
  else 
  {
   return false;
  }
 }
 void StackTop(char &Top)
 {
  if(EmptyStack() != true)
  {
   Top = slist->top->data;
  }
 } 
 int priority(char opr)
 {
  int result = 0;
  if(opr == '^')
  {
   result = 3;
  }
  else if(opr == '/' || opr == '*')
  {
   result = 2;
  }
  else if(opr == '+' || opr == '-')
  {
   result = 1;
  }
  else
  {
   result = 0;
  }
  return result;
 }
 void PushStack(char d)
 {
  if(d == '(')
  {
   node *t = new node;
   t->data = d;
   t->link = slist->top;
   slist->top = t;
   slist->count += 1;
  }
  else if(d == ')')
  {
   d = slist->top->data;
   node *t = slist->top;
   slist->top = t->link;
   delete t;
   slist->count -= 1;
   while(d != '(')
   {
    postFixExpr[strcount]= d;
    strcount += 1;
    d = slist->top->data;
    node *t = slist->top;
    slist->top = t->link;
    delete t;
    slist->count -= 1;
   }
  }
  else if (d == '+' || d == '-' || d == '*' || d == '/' || d == '^')
  {
   if(EmptyStack() == true)
   {
    node *t = new node;
    t->data = d;
    t->link = slist->top;
    slist->top = t;
    slist->count += 1;
   }
   else
   {
    char topToken;
    StackTop(topToken);
    if(priority(d) > priority(topToken))
    {
     node *t = new node;
     t->data = d;
     t->link = slist->top;
     slist->top = t;
     slist->count += 1;
    }
    else if(priority(d) <= priority(topToken))
    {
     while(EmptyStack() != true && priority(d) <= priority(topToken))
     {
      char tokenOut;
      tokenOut = slist->top->data;
      node *t = slist->top;
      slist->top = t->link;
      delete t;
      slist->count -= 1;
      postFixExpr[strcount] = tokenOut;
      strcount += 1;
      StackTop(topToken);
     }
     PushStack(d);
    }
   }
  }
  else 
  {
   postFixExpr[strcount]=d;
   strcount += 1;
  } 
 }
 void Display()
 {
  while(EmptyStack() != true)
  {
   char a = slist->top->data;
   node *t = slist->top;
   slist->top = t->link;
   delete t;
   slist->count -= 1;
   postFixExpr[strcount] = a;
   strcount += 1;
  }
  cout<<"The PostFix Expression is : "<<postFixExpr<<endl;
 }
};
int main()
{
 string infix;
 cout<<"Enter the Infix Expression : "<<endl;
 cin>>infix;
 StackEx S;
 S.CreateStack();
 for(int i=0;i<infix.length();i++)
 {
  S.PushStack(infix[i]);
 }
 S.Display();
 return 0;
}
 

 
