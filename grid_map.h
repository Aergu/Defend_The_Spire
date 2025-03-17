//
// Created by media on 3/17/2025.
//

#ifndef GRID_MAP_H
#define GRID_MAP_H
#include <raylib.h>
#include <stdio.h>

#define MAX_NODES 100

typedef struct {
    int x, y;
} Node;

typedef struct {
    int items[MAX_NODES];
    int front, rear;
} Queue;

typedef struct {
    int neighbors [MAX_NODES][MAX_NODES];
    int size [MAX_NODES];
} Graph;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

bool isEmpty(Queue* q) {
    return q->rear < q->front;
}

void enqueue (Queue *q, int value) {
    if (q->rear < MAX_NODES - 1) {
        q->items [++q->rear] = value;
    }
}

int dequeue (Queue *q) {
    if (!isEmpty(q)) {
        return q -> items[q->front++];
    }
    return -1;
}

void addEdge(Graph *graph, int u, int v) {
    graph->neighbors [u][graph->size[u]++] = v;
    graph->neighbors [v][graph->size[v]++] = u;
}

bool bfsStarted = false;
bool reached [MAX_NODES] = {false};
int bfsOrder [MAX_NODES];
int orderIndex = 0;
Queue frontier;

void bfs (Graph *graph, int start) {
    Queue frontier;
    initQueue(&frontier);
    enqueue(&frontier, start);
    reached[start] = true;
    bfsOrder[orderIndex++] = start;
}

void bfsStep (Graph * graph) {
    if (!isEmpty(&frontier)) {
        int current = dequeue(&frontier);
        for (int i = 0; i < graph->size[current]; i++) {
            int next = graph->neighbors [current][i];
            if (reached[next]) {
                enqueue(&frontier, next);
                reached[next] = true;
                bfsOrder[orderIndex++] = next;
            }
        }
    }
}




#endif //GRID_MAP_H
