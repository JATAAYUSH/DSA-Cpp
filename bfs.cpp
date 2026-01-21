#include <iostream>
#define MAX 100
using namespace std;

void Bfs(int graph[][MAX],int visited[],int start,int v){
    int queue[MAX];
    int front= 0 ,rear =0;
    queue[++rear]= start;
    visited[start]=1;
    printf("BFS : \n");
    while(rear>=front){
        start= queue[front++];
        printf("%d\n",start);
        int i;
        for(i=0;i<v;i++){
            if(graph[start][i] && !visited[i]){
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}
int main (){
    int v,e;
    printf("Enter the number of Edges :");
    scanf("%d",&e);
    printf("Enter the number of Vertex :");
    scanf("%d",&v);
    int graph[MAX][MAX]= {0};
    int i,s,d;
    for(int i=0 ;i<e;i++){
        printf("Enter the source:");
        scanf("%d",&s);
        printf("Enter the destination:");
        scanf("%d",&d);
        graph[s][d] = 1;
    }
    int visited[MAX]={0};
    int start;
    printf("Enter the starting vertex:");
    scanf("%d",&start);
    Bfs(graph,visited,start,v);
}