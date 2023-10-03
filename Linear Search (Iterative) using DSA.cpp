//Sequential Linear Search using DSA
#include<iostream>
using namespace std;
int seqSearch(int array[],int last,int target,int &locn)
{
 int looker = 0;
 while(looker < last && target != array[looker])
 {
  looker += 1;
 }
 locn = looker;
 if(target == array[looker])
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
 int target;
 cout<<"Enter the Element to be Searched : "<<endl;
 cin>>target;
 int locn = 0,result;
 result = seqSearch(array,n-1,target,locn);
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