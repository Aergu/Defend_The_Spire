#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define BULLET_SPEED 40
#define BULLET_RADIUS 5
#define TOWER_RANGE 2

typedef struct {
    int x, y;
    bool active;
} Bullet;

Bullet bullets [10];

bool isEnemyInRange(int towerX, int towerY) {
    return abs(towerX - enemyX) <= TOWER_RANGE && abs(towerY - enemyY) <= TOWER_RANGE;
}

void shootBullets() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 1 && isEnemyInRange(i, j)) {
                for (int k = 0; k < 10; k++) {
                    if (!bullets[k].active) {
                        bullets[k].x = j * TILE_SIZE + TILE_SIZE / 2;
                        bullets[k].y = i * TILE_SIZE + TILE_SIZE / 2;
                        bullets[k].active = true;
                        break;
                    }
                }
            }
        }
    }
}

void updateBullets() {
    for (int i = 0; i < 10; i++) {
        if (bullets[i].active) {
            if (bullets[i].x < enemyY * TILE_SIZE + TILE_SIZE / 2) bullets[i].x += BULLET_SPEED;
            if (bullets[i].x > enemyY * TILE_SIZE + TILE_SIZE / 2) bullets[i].x -= BULLET_SPEED;
            if (bullets[i].y < enemyX * TILE_SIZE + TILE_SIZE / 2) bullets[i].y += BULLET_SPEED;
            if (bullets[i].y > enemyX * TILE_SIZE + TILE_SIZE / 2) bullets[i].y -= BULLET_SPEED;

            if (abs(bullets[i].x - (enemyY * TILE_SIZE + TILE_SIZE / 2)) < BULLET_RADIUS
                && abs (bullets[i].y - (enemyX * TILE_SIZE + TILE_SIZE / 2)) < BULLET_RADIUS) {
               bullets[i].active = false;
                GameOver = true;
            }
        }
    }
}
