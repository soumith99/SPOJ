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
  bool dfs(struct node *node[],int n);
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
        arr[k]->data=k;
        arr[k]->next=NULL;
      }
      for(j=0;j<m;j++){
        scanf("%d  %d",&x,&y);
        add_edge(arr,x-1,y-1,1);
        add_edge(arr,y-1,x-1,1);
      }
      printf(dfs(arr,n)?"NO\n":"YES\n");

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
  bool dfs(struct node *node[],int n){
    struct stack *head=NULL;
    struct node *u; struct adj_node *cur;
    int i=0;
    push(&head,node[i]);
    node[i]->colour=1;
    while(head!=NULL){
      u=pop(&head);
      if(u->colour==2) return true;
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
    for(i=0;i<n;i++) if(node[i]->colour!=2) return true;
    return false;
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
       return temp->node;
     }
    else return NULL;
  }
  void swap(struct node **a,struct node **b,int l1,int l2){
    struct node *temp=*a;
    *a=*b;
    *b=temp;
    (*b)->heap=l1;
    (*a)->heap=l2;
  }
