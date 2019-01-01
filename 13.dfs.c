#include<stdio.h>
typedef struct node* nodeptr;
struct node{
    int vertex;
    nodeptr link;
};
nodeptr graph[10];
int visited[10]={0};
void dfs(int);
void insert(int,int);
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
    printf("DFS traversal\n");
    dfs(no);
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
void dfs(int no){
    nodeptr temp;
    visited[no]=1;
    printf("%d->",no);
    for(temp=graph[no];temp;temp=temp->link){
        if(!visited[temp->vertex]){
            dfs(temp->vertex);
        }
    }
}
