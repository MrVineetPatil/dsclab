#include<stdio.h>
#include<stdlib.h>
typedef struct node* nodeptr;
struct node{
    int vertex;
    nodeptr link;
};
int queue[20];
nodeptr graph[10];
int visited[10]={0};
int front=-1;
int rear=-1;
void bfs(int);
void insert(int,int);
void addq(int);
int deleteq();
void main(){
    int no,n,name;
    printf("Enter the number of nodes\n");
    scanf("%d",&no);
    for(int i=0;i<no;i++){
        nodeptr temp;
        printf("Enter the number of adjacent nodes of node %d\n",i);
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            printf("Enter the node\n");
            scanf("%d",&name);
            insert(name,i);
        }
    }
    printf("Enter the node from where dfs has to start\n");
    scanf("%d",&no);
    printf("BFS traversal\n");
    bfs(no);
}
void insert(int name,int i){
    nodeptr nnode=(nodeptr)malloc(sizeof(struct node));
    nnode->vertex=name;
    nnode->link=NULL;
    if(!graph[i]){
        graph[i]=nnode;
    }
    else{
        nodeptr temp=graph[i];
        while(temp->link){
            temp=temp->link;
        }
        temp->link=nnode;
    }
}
void bfs(int no){
    nodeptr temp;
    visited[no]=1;
    printf("%d->",no);
    addq(no);
    while(front!=rear){
        no=deleteq();
        for(temp=graph[no];temp;temp=temp->link){
            if(!visited[temp->vertex]){
                printf("%d->",temp->vertex);
                addq(temp->vertex);
                visited[temp->vertex]=1;
            }
        }
    }
}
void addq(int temp){
    if(rear==19){
        printf("QueueFull\n");
    }
    else{
        queue[++rear]=temp;
    }
}
int deleteq(){
    if(front==rear){
        printf("QueueEmpty\n");
        return -1;
    }
    else{
        return queue[++front];
    }
}
