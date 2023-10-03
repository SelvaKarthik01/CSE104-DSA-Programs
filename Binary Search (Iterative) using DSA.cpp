//Sequential Binary Search using DSA
#include<iostream>
using namespace std;
int BinarySearch(int array[],int last,int target,int &locn)
{
 int begin = 0,mid;
 while(begin <= last)
 {
  mid = (begin+last)/2;
  if(target > array[mid])
  {
   begin = mid + 1;
  }
  else if (target < array[mid])
  {
   last = mid -1;
  }
  else 
  {
   begin = last + 1;
  }
 }
 locn = mid;
 if(target == array[mid])
 {
  return 1;
 }
 else
 {
  return 0;   
 }
}
int main()
{
 int n;
 cout<<"Enter the No. of Elements in Array : "<<endl;
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
 cout<<"] "<<endl;
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
 cout<<"The Sorted Array : ["<<array[0];
 for(int i=1;i<n;i++)
 {
  cout<<", "<<array[i];
 }
 cout<<"]"<<endl;
 int target;
 cout<<"Enter the Element to be Searched : ";;
 cin>>target;
 int locn = 0,result;
 result =BinarySearch(array,n-1,target,locn);
 if(result == 1)
 {
  cout<<"The Target Element "<<target<<" is found at Index : "<<locn<<endl;;
 }
 else if(result == 0)
 {
  cout<<"The Target Element "<<target<<" is not found in Array !!"<<endl;;
 }
 else
 {
  cout<<"Unexpected Error !! Please Try Again : "<<endl;
 }
 return 0;
}