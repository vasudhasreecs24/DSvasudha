#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
};
struct Node *head=NULL;
void createList(int n){
struct Node *newNode,*temp;
int data,i;
if(n<=0){printf("Number of nodes should be greater than 0\n");
return ;}
for(i=1;i<=n;i++)
{
    newNode=(struct Node *)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data for node %d: ",i);
    scanf("%d",&data);
    newNode ->data=data;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        temp->next=newNode;
    }
    temp=newNode;
    }
    printf("\nLinked list created successfully\n");
}
void deleteFirst(){
struct Node *temp;
if(head==NULL){
    printf("List is empty.Nothing to delete.\n");
    return;
}
temp=head;
head=head->next;
printf("Deleted element:%d\n",temp->data);
free(temp);
}
void deleteLast(){
struct Node *temp,*prev;
if(head==NULL){
    printf("List is empty .Nothing to delete\n");
    return;
}
temp=head;
while(temp->next!=NULL){
    prev=temp;
    temp=temp->next;
}
printf("Deleted element:%d\n",temp->data);
prev->next=NULL;
free(temp);
}
void deleteSpecific(int value){
struct Node *temp=head,*prev=NULL;
if(head==NULL){
    printf("List is empty .Nothing to delete\n");
    return;
}
if(head->data==value){
    head=head->next;
    printf("Deleted element:%d\n",temp->data);
    free(temp);
    return;
}
while(temp!=NULL && temp->data!=value){
    prev=temp;
    temp=temp->next;
    printf("Deleted element:%d\n,temp->data");
    free(temp);
}
}
void displayList(){
struct Node *temp=head;
if(head==NULL){
    printf("List is empty\n");
}
printf("\nLinked List: ");
while (temp!=NULL){
    printf("%d -> ",temp->data);
    temp=temp->next;
}
printf("NULL");
}
int main(){
int choice,n,value;
while(1){
    printf("\n---SIngly Linked List Operations---\n");
    printf("1.Create Linked List 2.Delete at beginnning 4. delete any position 3.delete at end 5.display 6.exit\n");

    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
    case 1:printf("Enter num of nodes");
           scanf("%d" ,&n);
           createList(n);
           break;
    case 2:
            deleteFirst();
            break;
    case 4:printf("enter  value: ");
             scanf("%d",&value);
            deleteSpecific(value);
             break;
    case 3:

       deleteLast();break;
    case 5:
        displayList();
        break;
    case 6:printf("exiting...");
            exit(0);

    default:printf("Invalid choice Try again\n");
    }
}
return 0;
}

