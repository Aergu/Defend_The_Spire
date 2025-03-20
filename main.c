#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "grid_map.h"

int main () {
        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Defend_The_Spire");
        SetTargetFPS(2);  // Slow for visualization
        bfs(GRID_SIZE - 1, GRID_SIZE - 1);

        while (!WindowShouldClose()) {
            moveEnemy();

            BeginDrawing();
            ClearBackground(RAYWHITE);

            // Draw grid
            for (int i = 0; i < GRID_SIZE; i++) {
                for (int j = 0; j < GRID_SIZE; j++) {
                    Color color = (grid[i][j] == 1) ? DARKGRAY : LIGHTGRAY;
                    DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, color);
                    DrawRectangleLines(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLACK);
                }
            }

            DrawCircle((GRID_SIZE - 1) * TILE_SIZE + TILE_SIZE / 2,
                       (GRID_SIZE - 1) * TILE_SIZE + TILE_SIZE / 2,
                       TILE_SIZE / 3, GREEN);


            DrawCircle(enemyY * TILE_SIZE + TILE_SIZE / 2, enemyX * TILE_SIZE + TILE_SIZE / 2, TILE_SIZE / 3, RED);

            EndDrawing();
        }
        CloseWindow();
        return 0;
}