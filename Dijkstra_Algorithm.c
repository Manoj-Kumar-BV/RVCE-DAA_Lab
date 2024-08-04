#include<stdio.h>

#define INF 999
void dijs(int n, int source, int cost[10][10], int distance[], int predecessor[]){
    int v, count, visited[10]={0},min;

    for(int i=0; i<n; i++){
        distance[i] = cost[source][i];
        if(distance[i] != INF)
            predecessor[i] = source;
    }

    visited[source] = 1;
    distance[source] = 0;
    predecessor[source] = -1;
    count = 1;

    while(count < n){
        min = INF;
        for(int w =0; w<n; w++){
            if(!visited[w] && distance[w]<min){
                min = distance[w];
                v = w;
            }
        }

        visited[v] = 1;
        count++;

        for(int w=0; w<n; w++){
            if(!visited[w] && distance[v]+cost[v][w]<distance[w]){
                distance[w] = distance[v]+cost[v][w];
                predecessor[w]=v;
            }
        }
    }
}

int main(){
    int n,source,distance[10], cost[10][10],predecessor[10];

    printf("Enter number of vertices: \n");
    scanf("%d",&n);

    printf("Enter the cost of the matrix: \n");
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex (0 indexed) : \n");
    scanf("%d",&source);

    dijs(n,source,cost,distance,predecessor);

    printf("\n Shortest paths from node %d are: \n",source);
    printf("\nNode\tDistance\tPath\n");

    for(int i=0; i<n; i++){
        if(i != source){
            printf("%d\t%d", i, distance[i]);
            printf("\t\t%d",i);

            int j=i;

            do{
                j = predecessor[j];
                printf("<-%d",j);
            }while(j != source);

            printf("\n");
        }
    }
    printf("\n");

    return 0;
}