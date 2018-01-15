#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
  int data,colour,priority,heap;
  struct node *pie;
  struct adj_node *next;
};
struct adj_node{
  int data,cost;
  struct node *root;
  struct adj_node *next;
};
struct queue{
  struct node *node;
  struct queue *next;
};
struct stack{
  struct node *node;
  struct stack *next;
};
void add_edge(struct node *arr[],int start,int end,int weight);
void shortest_path(struct node *arr[],int n);
void bfs(struct node *node[],int n);
void dfs(struct node *node[],int n);
void enque(struct queue **head,struct queue **tail,struct node *node);
struct node *deque(struct queue **head,struct queue **tail);
void push(struct stack **head,struct node *root);
struct node *pop(struct stack **head);
void swap(struct node **a,struct node **b,int l1,int l2);
void btmup(struct node *arr[],int i);
void topdown(struct node *arr[],int i,int len);
void insert(struct node *arr[],int *len,struct node *ptr);
void decrease(struct node *arr[],int i,int x);
struct node *delete_min(struct node *arr[],int *len);
/*
red=0
yellow=1
blue=2
*/
int main(){
  int t,i,n,m,x,y,j;
    scanf("%d  %d",&n,&m);
    struct node *arr[n];
    for(int k=0;k<n;k++){
      arr[k]=malloc(sizeof(struct node));
      arr[k]->data=i+1;
      arr[k]->next=NULL;
    }
    for(j=0;j<m;j++){
      scanf("%d  %d",&x,&y);
      add_edge(arr,x-1,y-1,1);
      add_edge(arr,y-1,x-1,1);
    }
    shortest_path(arr,n);
    printf("%d\n",arr[n-1]->priority);

/*  struct node *arr[100];
  for(int i=0;i<100;i++){
    arr[i]=malloc(sizeof(struct node));
    arr[i]->data=i;
    arr[i]->next=NULL;
  }
  for(int j=0;j<1000;j++){
    int k=rand()%100,k1=rand()%100;
    add_edge(arr,k,k1,rand()%10);
  }
  shortest_path(arr,100);*/
}
void add_edge(struct node *arr[],int start,int end,int weight){
  struct adj_node *adj=malloc(sizeof(struct adj_node)),*cur;
  adj->data=arr[end]->data;
  adj->cost=weight;
  adj->root=arr[end]; adj->next=NULL;
  cur=arr[start]->next;
  if(cur==NULL) arr[start]->next=adj;
  else{
    while(cur->next!=NULL) cur=cur->next;
    cur->next=adj;
  }
}
void shortest_path(struct node *arr[],int n){
  struct node *hp[n],*u;
  int hl=0;
  insert(hp,&hl,arr[0]);
  arr[0]->priority=0;
  arr[0]->colour=1;
  while(hl!=0){
    u=delete_min(hp,&hl);
    u->colour=2;
    struct adj_node *v;
    v=u->next;
    while(v!=NULL){
      if(v->root->colour==0){
        v->root->priority=u->priority+v->cost;
        v->root->colour=1;
        insert(hp,&hl,v->root);
        v->root->pie=u;
      }
      else if(v->root->colour==1){
        if(v->root->priority>u->priority+v->cost){
        //  v->root->priority=u->priority+v->cost;
          decrease(hp,v->root->heap,u->priority+v->cost);
          v->root->pie=u;
        }
      }
      v=v->next;
    }

  }

}
void bfs(struct node *node[],int n){
  struct queue *head=NULL,*tail=NULL;
  struct node *u;
  struct adj_node *v;
  u=node[0];
  enque(&head,&tail,u);
  u->colour=1;
  while(head!=NULL){
    u=deque(&head,&tail);
    u->colour=2;
    v=u->next;
    while(v!=NULL){
      if(v->root->colour==0){
        v->root->colour=1;
        enque(&head,&tail,v->root);
        v->root->pie=u;
      }
      v=v->next;
    }
  }

}
void dfs(struct node *node[],int n){
  struct stack *head=NULL;
  struct node *u; struct adj_node *cur;
  push(&head,node[0]);
  node[0]->colour=1;
  while(head!=NULL){
    u=pop(&head);
    if(u->colour==1){
      u->colour=2;
      cur=u->next;
      while(cur!=NULL){
        if(cur->root->colour==0){
            cur->root->pie=u;
            push(&head,cur->root);
            cur->root->colour=1;
        }
        else if(cur->root->colour==1){
          push(&head,cur->root);
          cur->root->pie=u;
        }
        cur=cur->next;
      }
    }
  }
}
void enque(struct queue **head,struct queue **tail,struct node *node){
  struct queue *newptr;
  newptr=malloc(sizeof(struct queue ));
  newptr->next=NULL;
  newptr->node=node;
  if((*head)!=NULL){
    (*tail)->next=newptr;
    (*tail)=(*tail)->next;
  }
  else{
    *head=newptr;
    *tail=newptr;
  }
}
struct node *deque(struct queue **head,struct queue **tail){
  struct node *temp;
  if((*head)!=NULL){
    if(head==tail){
      temp=(*head)->node;
      *head=NULL;
      *tail=NULL;
    }
    else{
      temp=(*head)->node;
      *head=(*head)->next;
    }
    printf("%d\n",temp->data);
    return temp;
  }
  else return NULL;
}
void push(struct stack **head,struct node *node){
  struct stack *new;
  new=malloc(sizeof(struct stack));
  new->node =node;
  new->next=*head;
  *head=new;
}
struct node *pop(struct stack **head){
  struct stack *temp=*head;
  if(temp!=NULL){
    *head=(*head)->next;
    printf("%d\n",temp->node->data);
     return temp->node;
   }
  else return NULL;
}
void btmup(struct node *arr[],int i){
  int p=(i-1)/2;
  while(i>0){
    if(arr[i]->priority<arr[p]->priority){
      swap(&arr[i],&arr[p],i,p);
      i=p;
      p=(i-1)/2;
    }
    else break;
  }
}
void topdown(struct node *arr[],int i,int len){
  int r=2*i+2,l=2*i+1,j;
  if(l==(len-1)&&arr[i]->priority>arr[l]->priority){
    swap(&arr[i],&arr[l],i,l);
  }
  else{
    while(r<len){
      //j=mini(arr,r,l);
      if(arr[l]->priority>arr[r]->priority) j=r;
      else j=l;

      if(arr[i]->priority<arr[j]->priority) break;
      else{
        swap(&arr[i],&arr[j],i,j);
        i=j;
        r=2*i+2;
        l=2*i+1;
      }
    }
  }
}
void insert(struct node *arr[],int *len,struct node *ptr){
  arr[*len]=malloc(sizeof(struct node));
  arr[*len]=ptr;
  arr[*len]->heap=(*len);
  btmup(arr,*len);
  *len=*len+1;
}
void decrease(struct node *arr[],int i,int x){
  arr[i]->priority=x;
  btmup(arr,i);
}
struct node *delete_min(struct node *arr[],int *len){
  struct node *temp=arr[0];
  arr[0]=arr[*len-1];
  arr[0]->heap=0;
  topdown(arr,0,*len-1);
  //free(arr[*len]);
  *len=*len-1;
  return temp;
}
void swap(struct node **a,struct node **b,int l1,int l2){
  struct node *temp=*a;
  *a=*b;
  *b=temp;
  (*b)->heap=l1;
  (*a)->heap=l2;
}
