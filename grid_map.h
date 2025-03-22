#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GRID_SIZE 15
#define TILE_SIZE 60
#define SCREEN_WIDTH (GRID_SIZE * TILE_SIZE)
#define SCREEN_HEIGHT (GRID_SIZE * TILE_SIZE)

#define GOAL_X (GRID_SIZE - 1)
#define GOAL_Y (GRID_SIZE - 1)


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int grid[GRID_SIZE][GRID_SIZE];


int distanceMap[GRID_SIZE][GRID_SIZE];

int enemyX = 0, enemyY = 0;

bool GameOver = false;
bool GameCleared = false;

void bfs(int goalX, int goalY) {
    int queue[GRID_SIZE * GRID_SIZE][2];
    int front = 0, rear = 0;

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            distanceMap[i][j] = -1;
        }
    }

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


void moveEnemy() {
        if (GameOver) return;



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

    if (enemyX == GOAL_X && enemyY == GOAL_Y) {
        GameOver = true;
    }
}