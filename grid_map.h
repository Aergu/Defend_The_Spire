#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GRID_SIZE 10
#define TILE_SIZE 50
#define SCREEN_WIDTH (GRID_SIZE * TILE_SIZE)
#define SCREEN_HEIGHT (GRID_SIZE * TILE_SIZE)

// Directions for BFS (right, down, left, up)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// Grid representation (0 = walkable, 1 = obstacle)
int grid[GRID_SIZE][GRID_SIZE] = {
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 1, 1, 1, 0}
};

// BFS Distance Map
int distanceMap[GRID_SIZE][GRID_SIZE];

// Enemy Position
int enemyX = 0, enemyY = 0;

// BFS to compute shortest path from goal (9,9)
void bfs(int goalX, int goalY) {
    int queue[GRID_SIZE * GRID_SIZE][2];
    int front = 0, rear = 0;

    // Initialize distance map
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            distanceMap[i][j] = -1;
        }
    }

    // Start BFS from goal
    queue[rear][0] = goalX;
    queue[rear][1] = goalY;
    rear++;
    distanceMap[goalX][goalY] = 0;

    while (front < rear) {
        int x = queue[front][0];
        int y = queue[front][1];
        front++;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < GRID_SIZE && ny >= 0 && ny < GRID_SIZE &&
                grid[nx][ny] == 0 && distanceMap[nx][ny] == -1) {
                queue[rear][0] = nx;
                queue[rear][1] = ny;
                rear++;
                distanceMap[nx][ny] = distanceMap[x][y] + 1;
            }
        }
    }
}

// Enemy movement function
void moveEnemy() {
    int bestX = enemyX, bestY = enemyY;
    int minDist = distanceMap[enemyX][enemyY];

    for (int d = 0; d < 4; d++) {
        int nx = enemyX + dx[d];
        int ny = enemyY + dy[d];

        if (nx >= 0 && nx < GRID_SIZE && ny >= 0 && ny < GRID_SIZE && distanceMap[nx][ny] != -1) {
            if (distanceMap[nx][ny] < minDist) {
                minDist = distanceMap[nx][ny];
                bestX = nx;
                bestY = ny;
            }
        }
    }
    enemyX = bestX;
    enemyY = bestY;
}