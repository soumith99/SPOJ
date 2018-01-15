#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

struct node{
  int data,colour,priority,heap;
  bool marked;
  struct node *pie;
  struct adj_node *next;
};
struct adj_node{
  string name;
  int data,cost;
  struct node *root;
  struct adj_node *next;
};

void almst_shortest_path(struct node *arr[],int n,int start);
void add_edge(struct node *arr[],int start,int end,int weight);
void shortest_path(struct node *arr[],int n,int start);
void mark_shortestpath(struct node *arr[],struct node *arr1[],int s,int d,int n);
void btmup(struct node *arr[],int i);
void topdown(struct node *arr[],int i,int len);
void insert(struct node *arr[],int *len,struct node *ptr);
void decrease(struct node *arr[],int i,int x);
struct node *delete_min(struct node *arr[],int *len);
void swap(struct node **a,struct node **b,int l1,int l2);

int main(){

  int n,m,i,s,d,u,v,p;
  while(1){
    cin>>n>>m;
    if(n==0 && m==0) break;
    else{
      struct node *node[n];
      struct node *node1[n];
      for(i=0;i<n;i++){
        node[i]=(struct node*)std::malloc(sizeof(struct node));
        node[i]->next=NULL;
        node[i]->data=i;
        node[i]->marked=false;
        node1[i]=(struct node*)std::malloc(sizeof(struct node));
        node1[i]->next=NULL;
        node1[i]->data=i;
        node1[i]->marked=false;
      }
      cin>>s>>d;
      for(i=0;i<m;i++){
        cin>>u>>v>>p;
        add_edge(node,u,v,p);
        add_edge(node1,v,u,p);
      }
      shortest_path(node,n,s);
      shortest_path(node1,n,d);
      if(node[d]->colour==0) cout<<-1<<endl;
      else{
        mark_shortestpath(node,node1,s,d,n);
        almst_shortest_path(node,n,s);
        if(node[d]->colour==0) cout<<-1<<endl;
        else cout<<node[d]->priority<<endl;
      }

    }
  }

}
void almst_shortest_path(struct node *arr[],int n,int start){
  struct node *hp[n],*u;
  int hl=0;
  for(int i=0;i<n;i++){
    arr[i]->priority=0;
    arr[i]->colour=0;
  }
  insert(hp,&hl,arr[start]);
  arr[start]->priority=0;
  arr[start]->colour=1;
  while(hl!=0){
    u=delete_min(hp,&hl);
    u->colour=2;
    struct adj_node *v;
    v=u->next;
    while(v!=NULL){
      if(v->root->colour==0){
        if(!(u->marked && v->root->marked)){
          v->root->priority=u->priority+v->cost;
          v->root->colour=1;
          insert(hp,&hl,v->root);
          v->root->pie=u;
        }
      }
      else if(v->root->colour==1){
        if(v->root->priority>u->priority+v->cost){
        //  v->root->priority=u->priority+v->cost;
        if(!(u->marked && v->root->marked)){
            decrease(hp,v->root->heap,u->priority+v->cost);
            v->root->pie=u;
          }
        }
      }
      v=v->next;
    }
  }
}
void mark_shortestpath(struct node *arr[],struct node *arr1[],int s,int d,int n){
  struct node *v=arr[d];
  int shtp=arr[d]->priority;
  for(int i=0;i<n;i++){
      if(arr[i]->priority+arr1[i]->priority==shtp){
        arr[i]->marked=true;
      }
  }
}
void add_edge(struct node *arr[],int start,int end,int weight){
  struct adj_node *adj=(struct adj_node*)std::malloc(sizeof(struct adj_node)),*cur;
  adj->data=arr[end]->data;
  adj->cost=weight;
  adj->root=arr[end]; adj->next=NULL;
  cur=arr[start]->next;
  adj->next=arr[start]->next;
  arr[start]->next=adj;
}
void shortest_path(struct node *arr[],int n,int start){
  struct node *hp[n],*u;
  int hl=0;
  for(int i=0;i<n;i++){
    arr[i]->priority=0;
    arr[i]->colour=0;
  }
  insert(hp,&hl,arr[start]);
  arr[start]->priority=0;
  arr[start]->colour=1;
  arr[start]->pie=NULL;
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
  arr[*len]=(struct node*)std::malloc(sizeof(struct node));
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
  (*b)->heap=l2;
  (*a)->heap=l1;
}
