// Queue Operations using DSA
#include<iostream>
using namespace std;
class Queue
{
private:
int n,q[300],front,rear,i,x,t;
public:
Queue()
{
	front=-1;
	rear=-1;
	for(i=0;i<4;i++)
	{
		q[i]=0;
	}
}
bool isempty()
{
	if(front==-1 && rear==-1)
	return true;
	else
	return false;
}
bool isfull()
{
	if(rear-front==3)
	return true;
	else
	return false;
}

int enqueue(int x)
{
	if(isfull())
	{
		cout<<"queue is full";
	}
	else if(isempty())
	{
		rear=0;
		front=0;
		q[rear]=x;
	}
	else
	{
		rear++;
		q[rear]=x;
	}
}
void dequeue()
{
	if(isempty())
	{
		cout<<"queue is empty";
	}
	else if(front==rear)
	{
		t=q[front];
		q[front]=0;
		front=-1;
		rear=-1;
	}
	else
	{
		t=q[front];
		q[front]=0;
		front++;
		
	}
}
void display()
{	if(isempty())
	{
		cout<<"queue is empty";
	}
	else if(front>-1)
	{
		for(i=front;i<=rear;i++)

		{
			cout<<q[i];
		}
	}
	else 
	{
		for(i=0;i<=rear;i++)

		{
			cout<<q[i];
		}
	}
}
};
int main()
{
Queue q1;
int n,s[300],top,i,x,t,b;
do
{
	cout<<"choose your option"<<endl;
	cout<<"1-full,2-empty,3-enqueue,4-dequeue,5-display"<<endl;
	cin>>b;
		switch(b)
	{
		case 1:
			if(q1.isfull())
			cout<<"full";
			else
			cout<<"not full";
			break;
		case 2:
			if(q1.isempty())
			cout<<"empty";
			else
			cout<<"not empty";
			break;
		case 3:
			cout<<"enter an value";
			cin>>x;
			q1.enqueue(x);
			break;
		case 4:
			q1.dequeue();
			break;
		case 5:
			q1.display();
			break;
		default:
			cout<<"enter a proper option";
			break;
	}
}
while(b!=0);

}


