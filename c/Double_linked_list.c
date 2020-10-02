//1905622 - NITISH KUMAR SONTHALIA
//Double Linked list
#include<stdio.h>
#include <stdlib.h>



struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void creat_list(struct node ** ,struct node ** ,int n);
void display_list(struct node ** );
void add_first_node(struct node ** ,int n);
void del_first_node(struct node ** );
void ins_node_after_data(struct node ** ,int n,int data1);
void ins_node_before_data(struct node ** ,int n,int data1);
void del_node_with_data(struct node ** ,int n);
void del_node_after_data(struct node ** ,int n);
void del_last_node(struct node **end );
void del_node_before_data(struct node ** ,int n);
void sort(struct node ** );
void rev(struct node **st,struct node **end);

int main(){
    struct node *start = NULL;

    struct node *end = NULL;
    int t;

    int f=1;

    while(f){
    printf("\n MENU ");
    printf("\n 1. Enter An Element ");
    printf("\n 2. Display The List ");
    printf("\n 3. Add First Node ");
    printf("\n 4. Delete First Node ");
    printf("\n 5. Insert Node After Data ");
    printf("\n 6. Insert Node Before Data ");
    printf("\n 7. Deletion of Node With Data ");
    printf("\n 8. Deletion of Node After Data ");
    printf("\n 9. Deletion of Last Node ");
    printf("\n 10. Deletion of Node Before Data ");
    printf("\n 11. Sort ");
    printf("\n 12. Reverse the list ");
    printf("\n 13. EXIT ");
    scanf("%d",&t);
    int e,p;

    switch (t)
    {

    case 1:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        creat_list(&start,&end,e);
        break;

    case 2:
        display_list(&start);
        break;

    case 3:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        add_first_node(&start,e);
        break;

    case 4:
        del_first_node(&start);
        break;

    case 5:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        printf("\n Enter The Element Data: ");
        scanf("%d",&p);
        ins_node_after_data(&start,p,e);
        break;

    case 6:
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        printf("\n Enter The Element Data: ");
        scanf("%d",&p);
        ins_node_before_data(&start,p,e);
        break;

    case 7:
        printf("\n Enter The Element Data: ");
        scanf("%d",&p);
        del_node_with_data(&start,p);
        break;

    case 8:
        printf("\n Enter The Element Data: ");
        scanf("%d",&p);
        del_node_after_data(&start,p);
        break;

    case 9:
        del_last_node(&end);
        break;

    case 10:
        printf("\n Enter The Element Data: ");
        scanf("%d",&p);
        del_node_before_data(&start,p);
        break;

    case 11:
        sort(&start);
        break;

    case 12:
        rev(&start);
        break;

    case 13:
        f=0;
        break;

    default:
        break;
    }
    }
}

void creat_list(struct node **st,struct node **end ,int n){
    struct node *temp;

    struct node *new1 = (struct node *)malloc(sizeof(struct node ));

    new1->data=n;

    new1->next=NULL;

    new1->prev=NULL;

    if(*st==NULL){
        *st=new1;
        *end=new1;
        return;
    }
    else{
        temp=*st;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        temp->next = new1;
        *end=new1;
    }
}


void display_list(struct node **st){

    if (*st == NULL){ 
      printf("\n Empty List"); 
      return ;
    }

    struct node*temp=*st;
    printf("Elements in LIST are:");

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void add_first_node(struct node **st ,int n){

    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    struct node *temp=*st;

    ptr->data = n;
    ptr->next=*st;
    ptr->prev=NULL;
    temp->prev=ptr;
    *st=ptr;
}


void del_first_node(struct node **st ){

    struct node *ptr=*st;

    ptr->next->prev=NULL;
    *st=ptr->next;
    free(ptr);
}

void del_last_node(struct node **end ){

    struct node *t=*end;
    t->prev->next=NULL;
    *end=t->prev;
    free(t);
}

void rev(struct node **st,struct node **end){
    struct node *t1,*t2;
    int t;
    t1=*st;
    t2=*end;
    while(t1!=t2 && t1->prev!=t2){
        t=t1->data;
        t1->data=t1->data;
        t2->data=t;
        t1=t1->next;
        t2=t2->prev;
    }
}

void ins_node_after_data(struct node **st ,int n,int data1){

    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    struct node *t=*st;

    while(t->data!=n){
        t=t->next;
    }

    ptr->prev=t;
    ptr->next=t->next;
    ptr->data = data1;
    t->next=ptr;
}


void del_node_with_data(struct node **st ,int n){

    struct node *t;

    t=*st;

    while (t->data!=n)
    {
        t=t->next;
    }
    t->prev->next=t->next;
    t->next->prev=t->prev;
    free(t);
}

void ins_node_before_data(struct node **st ,int n,int data1){

    struct node *t;

    t=*st;

    while (t->data!=n)
    {
        t=t->next;
    }

    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    ptr->data = data1;
    ptr->prev=t->prev;
    ptr->next=t;
    t->prev->next=ptr;
    t->prev=ptr;
}


void del_node_after_data(struct node **st ,int n){

    struct node *t=*st;

    while(t->data!=n){
        t=t->next;
    }
    struct node *t1=t->next;
    t->next=t1->next;
    t1->next->prev=t;
    free(t1);    
}

void del_node_before_data(struct node **st ,int n){

    struct node *t;

    t=*st;

    while (t->data!=n)
    {
        t=t->next;
    }
    struct node *t1=t->prev;
    t->prev=t1->prev;
    t1->prev->next=t;
    free(t1);
}

void sort(struct node **st ){

    struct node *t1=*st;

    struct node *t2;

    int k;

    while (t1!=NULL)
    {
        for(t2=t1->next;t2!=NULL;t2=t2->next){
            if(t1->data>t2->data){
                k=t1->data;
                t1->data = t2->data;
                t2->data=k;
            }
        }
        t1=t1->next;
    }
    
}