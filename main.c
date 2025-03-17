#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "grid_map.h"

int main () {
    InitWindow(800, 600, "BFS Part One");
    SetTargetFPS(1000);

    Graph graph = {0};
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0,2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 5);
    addEdge(&graph, 2, 6);

    Node nodes [MAX_NODES] = {
        {400, 100}, {300, 200}, {500, 200},
        {250, 300}, {350, 300}, {450, 300},
        {550, 300}
    };

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE) && !bfsStarted) {
            bfsStarted = true;
            bfs(&graph, 0);
        }

        if (bfsStarted) {
            bfsStep(&graph);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < MAX_NODES; i++) {
            for (int j = 0; j < graph.size[i]; j++) {
                int neighbor = graph.neighbors[i][j];
                DrawLine(nodes[i].x, nodes[i].y, nodes[neighbor].x, nodes[neighbor].y, RED);
            }
        }

        for (int i = 0; i < MAX_NODES; i++) {
            Color nodeColor = BLUE;
            for (int j = 0; j < orderIndex; j++) {
                if (bfsOrder[j] == i) {
                    nodeColor = YELLOW;
                    break;
                }
            }
            DrawCircle(nodes[i].x, nodes[i].y, 20, nodeColor);
            DrawText(TextFormat("%d", i), nodes[i].x - 5, nodes[i].y - 5, 20, BLACK);
        }

        DrawText("Press SPACE to start the BFS", 20, 20, 20, RED);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}