//Recursive Linear Search using DSA
#include<iostream>
using namespace std;
int RecursiveLinearSearch(int array[],int index ,int last,int &locn,int target)
{
 if(index > last)
 {
  locn = -1;
  return 0;
 }
 if(target == array[index])
 {
  locn = index;
  return 1;
 }
 return RecursiveLinearSearch(array,index+1,last,locn,target);
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
 int target;
 cout<<"Enter the Element to be Searched : ";;
 cin>>target;
 int locn = 0,result;
 result = RecursiveLinearSearch(array,0,n-1,locn,target);
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