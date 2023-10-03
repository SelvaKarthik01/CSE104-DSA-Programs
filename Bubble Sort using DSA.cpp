#include<iostream>
using namespace std;
int main()
{
 int n;
 cout<<"Enter the No. of Elements to be Added in the Array : "<<endl;
 cin>>n;
 int array[n];
 for(int i=0;i<n;i++)
 {
  cout<<"Element No. "<<i+1<<" : ";
  cin>>array[i];
 }
 cout<<"The Given Array : [ "<<array[0];;
 for(int i=1;i<n;i++)
 {
  cout<<", "<<array[i];
 }
 cout<<" ]"<<endl;
 int walker = n-1,current = 0,sorted = 1,count = 0;
 while((current < n-1) && (sorted == 1))
 {
  walker = n-1;
  sorted = 0;
  while(walker > current)
  {
   if(array[walker-1] > array[walker])
   {
    int temp = array[walker];
    array[walker] = array[walker-1];
    array[walker-1] = temp;
    sorted = 1;
   }
   walker -= 1;
  }
  current += 1;
  count += 1;
 }
 cout<<"The Sorted Array : [ "<<array[0];
 for(int i=1;i<n;i++)
 {
  cout<<", "<<array[i];
 }
 cout<<" ]"<<endl;
 cout<<"No. of Passes : "<<count<<endl;
 return 0;
}