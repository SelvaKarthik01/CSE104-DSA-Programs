//Insertion Sprting using DSA
#include<iostream>
using namespace std;
int main()
{
 int n;
 cout<<"Enter the Total No. of Elements in Array : "<<endl;
 cin>>n;
 int array[n];
 for(int i=0;i<n;i++)
 {
  cout<<"Element No. "<<i+1<<" : ";
  cin>>array[i];
 }
 cout<<"The Entered Array : ["<<array[0];
 for(int i=1;i<n;i++)
 {
  cout<<", "<<array[i];
 }
 cout<<"]"<<endl;
 int current = 1,walker,count=0,key=0;
 while(current <= n-1)
 {
  walker = current -1;
  key = array[current];
  while(walker >= 0)
  {
   if(array[walker]> key)
   {
    int temp = array[walker];
    array[walker] = key;
    array[walker + 1] = temp;
   }
   walker = walker - 1;
  }
  current = current + 1;
  count += 1;
 }
 cout<<"The Sorted Array : ["<<array[0];
 for(int i=1;i<n;i++)
 {
  cout<<", "<<array[i];
 }
 cout<<"]"<<endl;
 cout<<"Total No. of Passes : "<<count<<endl;
 return 0;
}
