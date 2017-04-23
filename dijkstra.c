// Dijkstra's Shortest Path algorithm implementation in C. //
#include<stdio.h>
#include<stdlib.h>
#define V 5
#define INF 32767

// define a utility function to find minimum distance node. //
int minNode(int dist[], int sptset[]){
    int min = INF;
    int min_index;
    int i = 0;
    for(i; i<V; i+=1){
        if(sptset[i] == 0 && dist[i] <= min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// define a print() function to print the minimum distances. //
void print(int dist[], int size){
    int i = 0;
    for(i; i<size; i+=1){
        printf("%d \t\t %d \n", i, dist[i]);
    }
}

// Now define the dijkstra's algorithm. //
void dijkstra(int graph[V][V], int source){
    // initialise distance and sptset arrays. //
    int dist[V];
    int sptset[V];

    // Now initialise each node with some distance. //
    int i = 1;
    for(i; i<V; i+=1){
        dist[i] = INF;
        sptset[i] = 0;
    }

    // initialise source with distance 0. //
    dist[source] = 0;
    sptset[source] = 0;

    int u;
    // Now traverse the graph and find the minimum value node. //
    int count = 0;
    for(count; count<V; count +=1){
        u = minNode(dist, sptset);
        // Set this minimum node as visited. //
        sptset[u] = 1;

        // Now traverse the adjacent nodes of this node u. //
        int v = 0;
        for(v; v<V; v+=1){
            if(!sptset[v] && graph[u][v] && dist[u] != INF && dist[v] > dist[u] + graph[u][v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // After this just print the graph. //
    print(dist, V);
}

void main(){
    // define a graph here. //
    int graph[V][V] = {
                        {0, 1, 0, 0, 2},
                        {1, 0, 10, 0, 6},
                        {0, 10, 0, 11, 0},
                        {0, 0, 11, 0, 5},
                        {2, 6, 0, 5, 0}
                      };
    dijkstra(graph, 0);
}
