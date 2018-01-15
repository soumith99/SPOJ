#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct queue{
  long long int num;
  struct queue *next,*prev;
};
int arr[100000];
void check(int len,int k);
void addstart(struct queue **head,struct queue **tail,long long int num);
void addend(struct queue **head,struct queue **tail,long long int num);
void popend(struct queue **head,struct queue **tail);
void popstart(struct queue **head,struct queue **tail);
int main(){
  long long int n,k,i;
  scanf("%lld",&n);
  for(i=0;i<n;i++) scanf("%d",&arr[i]);
  scanf("%lld",&k);
  check(n,k);
}
void check(int len,int k){
  struct queue *head=NULL,*tail=NULL;
  long long int i;
  for(i=0;i<k;i++){
    if(head==NULL){
      addstart(&head,&tail,arr[i]);
    }
    else{
      while((tail->num)<arr[i] && tail!=NULL){
        popend(&head,&tail);
        if(tail==NULL) break;
      }
      addend(&head,&tail,arr[i]);
    }
  }
  printf("%lld\n",head->num);
  for(;i<len;i++){
    if(head->num==arr[i-k]){
      popstart(&head,&tail);
    }
    while(tail->num<arr[i] && tail!=NULL){
      popend(&head,&tail);
      if(tail==NULL) break;
    }
    addend(&head,&tail,arr[i]);
    printf("%lld\n",head->num);
  }
}
void addstart(struct queue **head,struct queue **tail,long long int num){
  struct queue *new=malloc(sizeof(struct queue));
  new->next=NULL;
  new->prev=NULL;
  new->num=num;
  *head=new;
  *tail=new;
}
void addend(struct queue **head,struct queue **tail,long long int num){
  struct queue *new=malloc(sizeof(struct queue));
  new->num=num;
  if((*head)==NULL){
    new->next=NULL;
    new->prev=NULL;
    *head=new;
    *tail=new;
  }
  else if(*head==(*tail)){
    (*head)->next=new;
    new->prev=(*head);
    new->next=NULL;
    *tail=new;
  }
  else{
    new->next=NULL;
    new->prev=*tail;
    (*tail)->next=new;
    *tail=new;

  }
}
void popend(struct queue **head,struct queue **tail){
  if((*head)==(*tail)){
    *head=NULL;
    *tail=NULL;
  }
  else{
    struct queue *cur=(*tail)->prev;

    *tail=cur;
    cur->next=NULL;
  }
}
void popstart(struct queue **head,struct queue **tail){
  if(*head==(*tail)){
    *head=NULL;
    *tail=NULL;
  }
  else{
    struct queue *cur=(*head)->next;
    *head=cur;

    cur->prev=NULL;
  }
}
