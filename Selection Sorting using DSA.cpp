/* Selection SOrting using DSA */
#include<iostream>
using namespace std;
int main()
{
 int n;
 cout<<"Enter the No. of Elements to be Added in Array : "<<endl;
 cin>>n;
 int array[n];
 for(int i=0;i<n;i++)
 {
  cout<<"Element No. "<<i+1<<" : ";
  cin>>array[i];
 }
 cout<<"The Entered Array : "<<"[ "<<array[0];
 for(int i=1;i<n;i++)
 {
  cout<<", "<<array[i];
 }
 cout<<" ]"<<endl;
 int smallest,current = 0,walker = current + 1,count=0;
 while(current < n-1)
 {
  smallest = current;
  walker = current + 1;
  while(walker < n)
  {
   if(array[walker] < array[smallest])
   {
    smallest = walker;
   }
   walker += 1;
  }
  int temp = array[current];
  array[current] = array[smallest];
  array[smallest]= temp;
  current += 1;
  count += 1;
 }
 cout<<"The Sorted Array : "<<"[ "<<array[0];
 for(int i=1;i<n;i++)
 {
  cout<<", "<<array[i];
 }
 cout<<" ]"<<endl;
 cout<<"Total No. of Passes : "<<count<<endl;
 return 0;
}
 
 
