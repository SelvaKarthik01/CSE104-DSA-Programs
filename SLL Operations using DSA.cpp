//Implementation of a Single Linked List
#include<iostream>
using namespace std;
struct node
{
 int data;
 node *link;
};
class SLL
{
 node *first;
 public:
 SLL()
 {
  first = NULL;
 }
void InsertBag(int d)
{
 node *t = new node;
 t->data = d;
 if(first == NULL)
 {
  t->link = NULL;
  first = t;
 }
 else
 {
  t->link = first;
  first = t;
 }
}
void InsertEnd(int d)
{
 node *t = new node;
 t->data = d;
 if(first == NULL)
 {
  t->link = NULL;
  first = t;
 }
 else
 {
  node *temp = first;
  while(temp->link != NULL)
  {
   temp=temp->link;
  }
  temp->link=t;
  t->link = NULL;
 }
}
void InsertatLocn(int d,int locn)
{
 node *t = new node;
 t->data = d;
 if(first == NULL)
 {
  t->link = NULL;
  first = t;
 }
 else
 {
  node *temp = first;
  int count = 1;
  while(count<locn)
  {
   temp = temp->link;
   count ++;
  }
  t->link = temp->link;
  temp->link = t;
 }
}
void Deletebag()
{
 if(first == NULL)
 {
  cout<<"Can't Perform Delete operation as the List is Empty !"<<endl;
 }
 else
 {
  node *t = first;
  first = first->link;
  delete t;
 }
}
void DeleteatLocn(int locn)
{
 if(first == NULL)
 {
  cout<<"Can't Perform Delete operation as the List is Empty !"<<endl;
 }
 else
 {
  int c= 1;
  node *t1 = first;
  node *t2;
  while(c < locn)
  {
   t2 = t1;
   t1 = t1->link;
   c++;
  }
  t2->link = t1->link;
  delete t1;
 }
}
void SearchNode(int d)
{
 if(first == NULL)
 {
  cout<<"Can't Perform Search operation as the List is Empty !"<<endl;
 }
 else
 {
  node *temp = first;
  int count = 0;
  while(temp != NULL)
  {
   if(temp->data == d)
   {
    count ++;
    cout<<"The Node is Present at Location : "<<count<<endl;
    cout<<"The Node Data : "<<temp->data<<endl;
    cout<<"The Node Link : "<<temp->link<<endl;
    break;
   }
   else 
   {
    temp = temp->link;
   }
  }
 }
}
void RetrieveNode(int locn)
{
 if(first == NULL)
 {
  cout<<"Can't Perform Retrieve operation as the List is Empty !"<<endl;
 }
 else
 {
  int count = 0;
  node *temp = first;
  
  while(count < locn)
  {
   temp=temp->link;
   count += 1;
  }
  cout<<"The Node Data : "<<temp->data<<endl;;
  cout<<"The Node Link : "<<temp->link<<endl;;
 }
}
void NodeCount()
{
 int count=0;
 node *temp = first;
 while(temp != NULL)
 {
  temp = temp->link;
  count += 1;
 }
 cout<<"The Total No. of Nodes in the Linked List is : "<<count<<endl;
}
void UpdateNode(int d,int locn)
{
 if(first == NULL)
 {
  cout<<"Can't Perform Update operation as the List is Empty !"<<endl;
 }
 else
 {
  int c = -1;
  node *t1 = first;
  node *t2;
  while(c < locn)
  {
   t2 = t1;
   t1=t1->link;
   c++;
  }
  t2->data = d;
  cout<<"The Updated Node : "<<endl;
  cout<<"The Node Data : "<<t2->data<<endl;;
  cout<<"The Node Link : "<<t2->link<<endl;;
 }
}
void Display()
{
 if(first == NULL)
 {
  cout<<"Empty List !!"<<endl;
 }
 else
 {
  node *t = first;
  while(t!= NULL)
  {
   cout<<t->data<<" ";
   t = t->link;
  }
  cout<<endl;
 }
}
};
int main()
{
 SLL S;
 int choice=0,data,locn;
 while(choice != 11)
 {
  cout<<"1. Insert in Beginning "<<endl;
  cout<<"2. Insert at End "<<endl;
  cout<<"3. Insert at a Specific Location "<<endl;
  cout<<"4. Delete at Beginning "<<endl;
  cout<<"5. Delete a Specific Node "<<endl;
  cout<<"6. Search a Specific Node "<<endl;
  cout<<"7. Retrieve Data of a Specific Node "<<endl;
  cout<<"8. Update a Specific Node "<<endl;
  cout<<"9. Find the Total Number of Nodes "<<endl;
  cout<<"10. Display the Nodes in Sequence "<<endl;
  cout<<"11. To Exit "<<endl;
  cout<<"Enter Your Choice : ";
  cin>>choice;
  if(choice == 1)
  {
   cout<<"Enter the Data to be Added : "<<endl;
   cin>>data;
   S.InsertBag(data);
  }
  else if(choice ==2)
  {
   cout<<"Enter the Data to be Added : "<<endl;
   cin>>data;
   S.InsertEnd(data);
  }
   else if(choice ==3)
  {
   cout<<"Enter the Data to be Added : "<<endl;
   cin>>data;
   cout<<"Enter the Location to be Added : "<<endl;
   cin>>locn;
   S.InsertatLocn(data,locn);
  }
  else if(choice ==4)
  {
   S.Deletebag();
  }
  else if(choice ==5)
  {
   cout<<"Enter the Location to be Added: "<<endl;
   cin>>locn;
   S.DeleteatLocn(locn);
  }
  else if(choice ==6)
  {
   cout<<"Enter the Data to be Searched: "<<endl;
   cin>>data;
   S.SearchNode(data);
  }
  else if(choice == 7)
  {
   cout<<"Enter the Location of the Node to Retrieve : "<<endl;
   cin>>locn;
   S.RetrieveNode(locn);
  }
  else if(choice == 8)
  {
   cout<<"Enter the Data to be Updated : "<<endl;
   cin>>data;
   cout<<"Enter the Location to be Updated : "<<endl;
   cin>>locn;
   S.UpdateNode(data,locn);
  }
  else if(choice == 9)
  {
   S.NodeCount();
  }
  else if(choice == 10)
  {
   S.Display();
  }
  else if(choice == 11)
  {
   cout<<"Thank You !"<<endl;
   break;
  }
 }
 return 0;
}
  

  


