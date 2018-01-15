#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

struct node{
  string name;
  int data,colour,priority,heap,d,f;
  struct node *pie;
  struct adj_node *next;
};
struct adj_node{
  string name;
  int data,cost;
  struct node *root;
  struct adj_node *next;
};

int find_index(struct node *arr[],string name);
void add_edge(struct node *arr[],int start,int end,int weight);
void shortest_path(struct node *arr[],int n,int start);
void btmup(struct node *arr[],int i);
void topdown(struct node *arr[],int i,int len);
void insert(struct node *arr[],int *len,struct node *ptr);
void decrease(struct node *arr[],int i,int x);
struct node *delete_min(struct node *arr[],int *len);
void swap(struct node **a,struct node **b,int l1,int l2);

int main(){
  int s,n,i,j,p,a,b,c,r;
  string name;
  cin>>s;
  for(int llll=0;llll<s;llll++){
    cin>>n;
    struct node *node[n];
    for(i=0;i<n;i++){
      node[i]=(struct node*)std::malloc(sizeof(struct node));
      node[i]->next=NULL;
      node[i]->data=i+1;
    }
    for(i=0;i<n;i++){
      cin>>name;cin>>p;
      node[i]->name=name;
      for(j=0;j<p;j++){
        cin>>b>>c;
        add_edge(node,i,b-1,c);
      }
    }
    cin>>r;
    for(i=0;i<r;i++){
      string c1,c2;
      cin>>c1>>c2;
      int i1=find_index(node,c1),i2=find_index(node,c2);
      shortest_path(node,n,i1);
      cout<<node[i2]->priority;
    }
  }
}
int find_index(struct node *arr[],string name){
  int i=0;
  while(1){
    if(arr[i]->name==name) return i;
    i++;
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
