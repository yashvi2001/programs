#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*first=NULL;

void create(int a[],int n)
{
struct node *last,*t;
last=(struct node *)malloc(sizeof(struct node));
last->data=a[0];
last->next=last;
first=last;

for(int i=1;i<n;i++)
{
	t=(struct node*)malloc(sizeof(struct node));
	t->data=a[i];
	t->next=last->next;
	last->next=t;
	last=t;
}	
}

void display(struct node *f)
{
	do
	{
		printf("%d -> ",f->data);
		f=f->next;
	}
	while(f!=first);
}

void insert(struct node *f)
{
	struct node *t,*p=f;
	int n,pos;
		
	t=(struct node*)malloc(sizeof(struct node));
	
	printf("\n Enter the the element and position : \n ");
	scanf("%d %d",&n,&pos);
	
	if(pos!=0){
	for(int i=1;i<=pos-1;i++)
	p=p->next;
	t->data=n;
	t->next=p->next;
	p->next=t;
}
else
{
	if(first==NULL)
	{
	first=t;
	t->next=t;	
	}
	else{
	while(p->next!=first)
	{
		p=p->next;
	}
	t=(struct node*)malloc(sizeof(struct node));
	t->data=n;	
	t->next=first;
	p->next=t;
	first=t;
}
}
	
}

void deletenode(struct node *f)
{
	int n,x;
	struct node *p=first,*q=NULL;
	
	printf("\n Enter the node number to delete : \n");
	scanf("%d",&n);
	if(n!=0){
	for(int i=1;i<=n-1;i++)
	{
		p=p->next;
	}
	q=p->next;
	p->next=q->next;
	x=q->data;
	delete(q);
}
else
{
	while(p->next!=first)
	{
		p=p->next;
	}
	p->next=first->next;
	x=first->data;
	delete(first);
	first=p->next;
	}
	
	
}

int main()
{
	int a[]={2,2,3,4,5};
	create(a,5);
	display(first);
	insert(first);
		display(first);
		deletenode(first);
		display(first);
}
