#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct stack{
  int num;
  struct stack *next;
};

void adds(struct stack **head,int num);
int pops(struct stack **head);
bool check(int arr[],int len);
bool stack_check(struct stack *ptr);
int main(){
  int n,i,arr[1000];
  scanf("%d",&n);
  while(n!=0){
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    if(check(arr,n)) printf("yes\n");
    else printf("no\n");
    scanf("%d",&n);
  }
}
bool check(int arr[],int len){
  int i=1,j=0;bool done=false;
  struct stack *ptr=NULL;
  while(j<len){
    done=false;
    if(arr[j]==i){
      j++;
      i++;
      done=true;
    }
    else if(ptr!=NULL){
      if(ptr->num==i) {
        pops(&ptr);
        i++;
        done=true;
      }
    }
    if(!done){
      adds(&ptr,arr[j]);
      j++;
      if(stack_check(ptr)) return false;
    }
  }
  return true;
}
void adds(struct stack **head,int num){
  struct stack *new;
  new=malloc(sizeof(struct stack));
  new->num=num;
  new->next=*head;
  *head=new;
}
int pops(struct stack **head){
  struct stack *temp=*head;
  if(temp!=NULL){
    *head=(*head)->next;
     return temp->num;
   }
  else return -1;
}
bool stack_check(struct stack *ptr){
  if(ptr->next!=NULL){
    if(ptr->num>ptr->next->num){
      return true;
    }
  }
  return false;
}
