/* Demonstration of Stack and Queue using Linked Linear List */
#include<iostream>
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
 void CreateStack()
 {
  slist = new Stack;
  slist ->count = 0;
  slist->top = NULL;
 } 
 void PushStack(int d)
 {
  node *t = new node;
  t->data = d;
  t->link = slist->top;
  slist->top = t;
  slist->count += 1;
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
 bool StackTop(int &Top)
 {
  if(EmptyStack())
  {
   cout<<"The Stack is Empty !!"<<endl;
   return false;
  }
  else 
  {
   Top = slist->top->data;
   return true;
  }
 }

 bool Pop(int &d)
 {
  bool success;
  if(EmptyStack())
  {
   success = false;
  }
  else
  {
   d = slist->top->data;
   node *t = slist->top;
   slist->top = t->link;
   delete t;
   slist->count -= 1;
   success = true;
  }
  return success;
 }
 void DestroyStack()
 {
  if(EmptyStack())
  {
   cout<<"Stack is Empty!! Cannot Perform Operation !!"<<endl;
  }
  else 
  {
   CreateStack();
  }
 }
};
int main()
{
 StackEx S;
 S.CreateStack();
 int data,choice = 0;
 while(choice != 5)
 {
  cout<<"1. Push Oeration "<<endl;
  cout<<"2. Pop Operation "<<endl;
  cout<<"3. Stack Top Display "<<endl;
  cout<<"4. Destoy Stack "<<endl;
  cout<<"5. To Exit "<<endl;
  cout<<"Enter Your Choice : "<<endl;
  cin>>choice ;
  if(choice == 1)
  {
   cout<<"Enter the Data to be Pushed into the Stack : "<<endl;
   cin>>data;
   S.PushStack(data);
   cout<<"Data Pushed Sucessfully !!"<<endl;
  }
  else if(choice == 2)
  {
   int DataOut=0;
   if(S.Pop(DataOut))
   {
    cout<<"Pop Operation SUccessfull !!"<<endl;
    cout<<"Popped Data : "<<DataOut<<endl;
   }
   else
   {
    cout<<"Cannot Perform Operation !"<<endl;
   }
  }
  else if (choice == 3)
  {
   int Top=0;
   if(S.StackTop(Top))
   {
    cout<<"The Data at Top of Stack : "<<Top<<endl;
   }
   else
   {
    cout<<"Cannout Perform Operation !"<<endl;
   }
  }
  else if (choice == 4)
  {
   S.DestroyStack();
   cout<<"Whole Stack is Destroyed !!"<<endl;
  }
  else if(choice == 5)
  {
   cout<<"Thank You !!"<<endl;
   break;
  }
  else
  {
   cout<<"Enter the Valid Option !"<<endl;
  }
 }
 return 0;
}
  
   
  
 
  
