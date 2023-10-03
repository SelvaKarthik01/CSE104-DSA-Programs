//Implementation of an Ordered Single Linked List
#include<iostream>
using namespace std;
struct node
{
 int data;
 node *link;
};
struct list
{
 int count;
 node *head;
};
class SLL
{
 list *slist;
 public :
 SLL()
 {
  slist = NULL;
 }
 void Createlist()
 {
  slist = new list();
  slist ->count = 0;
  slist->head = NULL;
 }

 void Insert(node *&ppre,int d)
 {
  node *t = new node;
  t->data = d;
  if(ppre == NULL)
  {
   t->link = slist->head;
   slist->head = t;
  }
  else
  {
   t->link = ppre->link;
   ppre->link = t;
  }
  slist->count += 1;
  cout<<slist->count<<endl;
 }
 void Delete(node *&ppre,node *&ploc, int &d)
 {
  d = ploc->data;
  if(ppre == NULL)
  {
   slist->head = ploc ->link;
  }
  else
  {
   ppre->link = ploc->link;
  }
  delete ploc;
  slist->count -= 1;
 }
 bool Search(node *&ppre,node *&ploc,int data)
 {
  ppre  = NULL;
  ploc = slist ->head;
  while(ploc != NULL && data > ploc->data)
  {
   ppre = ploc;
   ploc = ploc->link;
  }
  if(ploc == NULL)
  {
   return false;
  }
  else
  {
   if(data == ploc->data)
   {
    return true;
   }
   else 
   {
    return false;
   }
  }
 }
  bool Emptylist()
 {
  if (slist->count == 0)
  {
   return true;
  }
  else 
  {
   return false;
  }
 }
 void Display()
 {
  if(Emptylist())
  {
   cout<<"The List is Empty !!"<<endl;
  }
  else
  {
   node *t = slist->head;
   while(t!= NULL)
   {
    cout<<t->data<<" ";
    t = t->link;
   }
   cout<<endl;
  }
 }
 void DestroyList(node *&ppre,node *&ploc)
 {
  Createlist();
 }
};
int main()
{
 SLL S;
 int choice=0,data;
 node *ppre=NULL,*ploc = NULL;
 S.Createlist();
 while(choice != 6 )
 {
  cout<<"1. Insert "<<endl;
  cout<<"2. Delete "<<endl;
  cout<<"3. Search "<<endl;
  cout<<"4. Display List "<<endl;
  cout<<"5. DestroyList "<<endl;
  cout<<"6. To Exit "<<endl;
  cout<<"Enter Your Choice : "<<endl;
  cin>>choice;
  if(choice == 1)
  {
   cout<<"Enter the Element : "<<endl;
   cin>>data;
   if(S.Search(ppre,ploc,data))
   {
    cout<<"Duplicate Element "<<endl;
   }
   else
   {
    S.Insert(ppre,data);
   }
  }
  else if(choice == 2)
  {
   cout<<"Enter the Data to be Deleted : "<<endl;
   cin>>data;
   if(S.Search(ppre,ploc,data))
   {
    S.Delete(ppre,ploc,data);
    cout<<data<<" is Deleted !!"<<endl;
   }
   else
   {
    cout<<"Can't Perform !"<<endl;
   }
  }
  else if(choice == 3)
  {
   cout<<"Enter the Data to be Searched : "<<endl;
   cin>>data;
   if(S.Search(ppre,ploc,data))
   {
    cout<<"The Element is Found in the List !!"<<endl;
   }
   else
   {
    cout<<"The Element is not Found in the List !!"<<endl;
   }
  }
  else if(choice == 4)
  {
   S.Display();
  }
  else if(choice == 5)
  {
   S.DestroyList(ppre,ploc);
  }
  else if(choice == 6)
  {
   cout<<"Thank You !!"<<endl;
   break;
  }
 }
 return 0;
}
   
 
  
   
 
   

