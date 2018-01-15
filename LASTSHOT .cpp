#include<cstdio>
#include<cstdlib>
using namespace std;

struct node{
  int data,colour,priority,heap,d,f;
  struct node *pie;
  struct adj_node *next;
};
struct adj_node{
  int data,cost;
  struct node *root;
  struct adj_node *next;
};
struct stack{
  struct node *node;
  struct stack *next;
};

void add_edge(struct node *arr[],int start,int end,int weight);
int dfs(struct node *node[],int n,int start);
void push(struct stack **head,struct node *node);
struct node *pop(struct stack **head);

int main(){
  int n,m,t,a,b,max=0,k;
  scanf("%d %d",&n,&m);
    struct node *node[n];
    for(t=0;t<n;t++){
      node[t]=(struct node *) std::malloc(sizeof(struct node));
      node[t]->next=NULL;
      node[t]->data=t;
      node[t]->colour=0;
    }
    for(t=0;t<m;t++){
      scanf("%d %d",&a,&b);
      add_edge(node,a-1,b-1,1);
      //add_edge(node,b-1,a-1,1);
    }
    for(t=0;t<n;t++){
      if(node[t]->colour==0){
        k=dfs(node,n,t);
        if(k>max) max=k;
      }
    }
    printf("%d\n",max);
}
void add_edge(struct node *arr[],int start,int end,int weight){
  struct adj_node *adj=(struct adj_node*) std::malloc(sizeof(struct adj_node)),*cur;
  adj->data=arr[end]->data;
  adj->cost=weight;
  adj->root=arr[end]; adj->next=NULL;
  cur=arr[start]->next;
  adj->next=arr[start]->next;
  arr[start]->next=adj;
}
int dfs(struct node *node[],int n,int start){
  struct stack *head=NULL;
  struct node *u; struct adj_node *cur;
  for(int i=0;i<n;i++) node[i]->colour=0;
  push(&head,node[start]);
  node[start]->colour=1;
  int count=0;
  while(head!=NULL){
    u=pop(&head);
    if(u->colour==1){
      count++;
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
  return count;
}
void push(struct stack **head,struct node *node){
  struct stack *new1;
  new1 =(struct stack*)std::malloc(sizeof(struct stack));
  new1->node =node;
  new1->next=*head;
  *head=new1;
}
struct node *pop(struct stack **head){
  struct stack *temp=*head;
  if(temp!=NULL){
    *head=(*head)->next;
    //printf("%d\n",temp->node->data);
     return temp->node;
   }
  else return NULL;
}
