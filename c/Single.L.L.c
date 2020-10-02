#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*first=NULL;

void createll(int a[],int n)
{
	struct node *last,*t;
	last=(struct node *)malloc(sizeof(struct node));
	last->data=a[0];
	last->next=NULL;
	first=last;
	
	for(int i=1;i<n;i++)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=a[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

void displayll(struct node *f)
{
	while(f!=NULL)
	{
		printf("%d -> ",f->data);
		f=f->next;
	}
	printf("NULL");
}

void countsummax(struct node *f)
{
	int count=0,sum=0,max=INT_MIN;
	while(f!=NULL)
	{
		count++;
		sum+=f->data;
		if(f->data>max)
		{
			max=f->data;
		}
		f=f->next;
	}
	
	printf("\nCOUNT = %d\nSUM = %d\nMAX = %d\n",count,sum,max);
}

void insert(struct node *f)
{
	int n,pos;
	struct node *t;
	printf("\n Enter the element to enter then its position : ");
	scanf("%d %d",&n,&pos);
	t=(struct node *)malloc(sizeof(struct node));
	t->data=n;
	
	if(pos==0)
	{
		t->next=first;
		first=t;
		
	}
	else
	{
		for(int i=1;i<pos;i++)
		{
			f=f->next;
		}
		t->data=n;
		t->next=f->next;
		f->next=t;
	}
}

void deletenode(struct node *f)
{
	int pos,x;
		struct node *p=f,*q=NULL;
	printf("\n Enter the position to delete : ");
	scanf("%d",&pos);
	if(pos==1){
	f=f->next;
	x=f->data;
	delete(p);
}
else
{
	for(int i=1;i<=pos-1;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	x=p->data;
	delete(p);
}
}

int main()
{
	int a[]={1,2,3,4,5};
	//int ;
	createll(a,5);
	displayll(first);
	countsummax(first);
	insert(first);
	printf("\n Following is the New LL : \n");
	displayll(first);
	deletenode(first); 
	printf("\n Following is the New LL : \n");
	displayll(first);
}
