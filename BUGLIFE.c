#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
  int data,colour,sex;
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
void add_edge(struct node *arr[],int start,int end,int weight);
bool bfs(struct node *node[],int n,int s);
bool check(struct node *arr[],int n);
void enque(struct queue **head,struct queue **tail,struct node *node);
struct node *deque(struct queue **head,struct queue **tail);

int main(){
  int t,n,e,i,j,k,a,b;
  scanf("%d",&t);
  for(i=0;i<t;i++){
    scanf("%d %d",&n,&e);
    struct node *node[n];
    for(k=0;k<n;k++){
      node[k]=malloc(sizeof(struct node));
      node[k]->data=k;
      node[k]->next=NULL;
    }
    for(j=0;j<e;j++){
      scanf("%d %d",&a,&b);
      add_edge(node,a-1,b-1,1);
      add_edge(node,b-1,a-1,1);
    }
    if(check(node,n)) printf("Scenario #%d:\nNo suspicious bugs found!\n",i+1);
    else printf("Scenario #%d:\nSuspicious bugs found!\n",i+1);
  }
}
void add_edge(struct node *arr[],int start,int end,int weight){
  struct adj_node *adj=malloc(sizeof(struct adj_node)),*cur;
  adj->data=arr[end]->data;
  adj->cost=weight;
  adj->root=arr[end]; adj->next=NULL;
  cur=arr[start]->next;
  adj->next=arr[start]->next;
  arr[start]->next=adj;
}
bool check(struct node *node[],int n){
  int trvs=0; struct adj_node *v;
  for(int i=0;i<n;i++) node[i]->sex=0;
  while(trvs<n){
    node[trvs]->sex=1;
    if(bfs(node,n,trvs)) return false;
    while(trvs<n){
      if(node[trvs]->sex==0) break;
      trvs++;
    }
  }
  return true;
}

bool bfs(struct node *node[],int n,int s){
  struct queue *head=NULL,*tail=NULL;
  struct node *u;
  struct adj_node *v;
  int sex;
  for(int i=0;i<n;i++) node[i]->colour=0;
  u=node[s];
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
      if(u->sex ==1) sex=2;
      else sex=1;
      if(v->root->sex==0) v->root->sex=sex;
      else if(v->root->sex!=sex){
        return true;
        }
      v=v->next;
    }
  }
return false;
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
    return temp;
  }
  else return NULL;
}
