/*Stack operation using DSA */
#include<iostream>
using namespace std;
int EmptyStack(int Stack[],int &top)
{
 int empty;
 if(top == -1)
 {
  empty = 1;
 }
 else
 {
  empty = 0;
 }
 return empty;
}
int FullStack(int Stack[],int n,int &top)
{
 int full;
 if(top == n-1)
 {
  full = 1;
 }
 else
 {
  full = 0;
 }
 return full;
}
int PushStack(int Stack[],int data,int &top,int n)
{
 int result;
 if (FullStack(Stack,top,n) == 1)
 {
  result = 0;
 }
 else
 {
  top += 1;
  Stack[top] = data;
  result = 1;
 }
 return result;
}
int PopStack(int Stack[],int &dataOut,int &top)
{
 int result;
 if(EmptyStack(Stack,top)==1)
 {
  result = 0;
 }
 else
 {
  dataOut = Stack[top];
  top -=1;
  result = 1;
 }
 return result;
}
int StackTop(int Stack[],int &top)
{
 int dataTop;
 if(EmptyStack(Stack,top)==1)
 {
  dataTop =  -1;
 }
 else
 {
  dataTop = Stack[top];
 }
 return dataTop;
}
void Display(int Stack[],int &top)
{
 if(EmptyStack(Stack,top)==0)
 {
  cout<<Stack[top]<<" <---- TOP"<<endl;
  for(int i=top-1;i>=0;i--)
  {
   cout<<Stack[i]<<endl;
  }
 }
 else
 {
  cout<<"EMPTY STACK !!!"<<endl;
 }
}
int main()
{
 int n;
 cout<<"Enter the Maximum Size of Stack : "<<endl;
 cin>>n;
 int Stack[n];
 int top = -1;
 int choice=0 ;
 while(choice != 4)
 {
  cout<<"1. Push Operation "<<endl;
  cout<<"2. Pop Operation "<<endl;
  cout<<"3. Display Stack "<<endl;
  cout<<"4. TO Exit"<<endl;
  cout<<"Enter Your Choice : ";;
  cin>>choice;
  if(choice == 1)
  {
   int data,result;
   cout<<"Enter the Data to be Pushed : "<<endl;
   cin>>data;
   result = PushStack(Stack,data,top,n);
   if(result == 1)
   {
    cout<<"Element Pushed Successfully !!"<<endl;
   }
   else if(result == 0)
   {
    cout<<"OverFlowing Error !!!(Stack Reached Max Elements)"<<endl;
   }
  }
  else if(choice == 2)
  {
   int result,dataOut=0;
   result = PopStack(Stack,dataOut,top);
   if(result == 1)
   {
    cout<<"Pop Operation Successfull !!"<<endl;
    cout<<"Popped Element : "<<dataOut<<endl;
   }
   else if(result == 0)
   {
    cout<<"UnderFlowing Error !!(No Elements in Stack to be Popped)"<<endl;
   }
  }
  else if(choice == 3)
  {
   Display(Stack,top);
  }
 }
 return 0;
}
