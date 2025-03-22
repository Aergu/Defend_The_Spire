#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "grid_map.h"
#include "towers.h"

typedef enum {
    MENU,
    GAME,
    TUTORIAL
} GameState;

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Defend_The_Spire");

    int gameFPS = 7;
    int menuFPS = 60;
    int towerSpawnFPS = 60;

    GameState state = MENU;

    bool tutorialStarted = false;
    int tutorialStep = 0;

    while (!WindowShouldClose()) {
        switch (state) {
            case MENU:
                SetTargetFPS(menuFPS);
                BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawText("Defend The Spire", SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 - 75, 40, BLACK);
                DrawText("Press SPACE to start game", SCREEN_WIDTH / 2 - 125, SCREEN_HEIGHT / 2, 20, BLACK);
                DrawText("Press T to start tutorial", SCREEN_WIDTH / 2 - 120, SCREEN_HEIGHT / 2 + 50, 20, BLACK);

                if (IsKeyPressed(KEY_SPACE)) {
                    state = GAME;
                } else if (IsKeyPressed(KEY_T)) {
                    state = TUTORIAL;
                    tutorialStarted = true;
                    tutorialStep = 0;
                }

                EndDrawing();
                break;

            case GAME:
                SetTargetFPS(gameFPS);
                moveEnemy();
                shootBullets();
                updateBullets();

                BeginDrawing();
                ClearBackground(RAYWHITE);

                for (int i = 0; i < GRID_SIZE; i++) {
                    for (int j = 0; j < GRID_SIZE; j++) {
                        Color color = LIGHTGRAY;

                        if (grid[i][j] == 1) {
                            color = DARKBLUE;
                        }

                        DrawRectangle(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, color);
                        DrawRectangleLines(j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLACK);
                    }
                }

                for (int i = 0; i < 10; i++) {
                    if (bullets[i].active) {
                        DrawCircle(bullets[i].x, bullets[i].y, BULLET_RADIUS, BLUE);
                    }
                }

                DrawCircle((GRID_SIZE - 1) * TILE_SIZE + TILE_SIZE / 2,
                           (GRID_SIZE - 1) * TILE_SIZE + TILE_SIZE / 2,
                           TILE_SIZE / 3, GREEN);

                DrawCircle(enemyY * TILE_SIZE + TILE_SIZE / 2, enemyX * TILE_SIZE + TILE_SIZE / 2, TILE_SIZE / 3, RED);

            if (GameOver) {
                DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);

                if (GameCleared) {
                    DrawText("GAME CLEARED!", SCREEN_WIDTH / 2 - 140, SCREEN_HEIGHT / 2 - 20, 40, GREEN);
                } else {
                    DrawText("GAME OVER", SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 20, 40, RED);

                    for (int i = 0; i < 10; i++) {
                        bullets[i].active = false;
                    }
                }
                DrawText("PRESS SPACE TO RESTART", SCREEN_WIDTH / 2 - 120, SCREEN_HEIGHT / 2 + 50, 20, WHITE);


                if (IsKeyPressed(KEY_SPACE)) {
                    for (int i = 0; i < GRID_SIZE; i++) {
                        for (int j = 0; j < GRID_SIZE; j++) {
                            grid[i][j] = 0;
                        }
                    }

                    enemyX = 0;
                    enemyY = 0;
                    GameOver = false;
                    GameCleared = false;

                    for (int i = 0; i < 10; i++) {
                        bullets[i].active = false;
                    }

                    bfs(GOAL_X, GOAL_Y);
                }
            }


                if (!GameOver) {
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                        SetTargetFPS(towerSpawnFPS);
                        int towerX = GetMouseY() / TILE_SIZE;
                        int towerY = GetMouseX() / TILE_SIZE;

                        if (grid[towerX][towerY] == 0 &&
                            !(towerX == enemyX && towerY == enemyY)
                            && !(towerX == GOAL_X && towerY == GOAL_Y)) {

                            grid[towerX][towerY] = 1;
                            bfs(GOAL_X, GOAL_Y);
                        }
                    }
                }

                EndDrawing();
                break;

           case TUTORIAL:
    if (tutorialStarted) {
        switch (tutorialStep) {
            case 0:
                BeginDrawing();
                ClearBackground(RAYWHITE);

                int textWidth = MeasureText("Welcome to Defend The Spire!", 30);
                int textHeight = 30;

                int textX = SCREEN_WIDTH / 2 - textWidth / 2;
                int textY = SCREEN_HEIGHT / 2 - textHeight / 2;

                DrawText("Welcome to Defend The Spire!", textX, textY, 30, BLACK);

                textWidth = MeasureText("Press SPACE to continue", 20);
                textHeight = 20;

                textX = SCREEN_WIDTH / 2 - textWidth / 2;
                textY = SCREEN_HEIGHT / 2 + 50;

                DrawText("Press SPACE to continue", textX, textY, 20, BLACK);

                if (IsKeyPressed(KEY_SPACE)) {
                    tutorialStep++;
                }

                EndDrawing();
                break;

            case 1:
                BeginDrawing();
                ClearBackground(RAYWHITE);

                textWidth = MeasureText("Build towers by clicking on empty spaces", 30);
                textHeight = 30;

                textX = SCREEN_WIDTH / 2 - textWidth / 2;
                textY = SCREEN_HEIGHT / 2 - textHeight / 2;

                DrawText("Build towers by clicking on empty spaces", textX, textY, 30, BLACK);

                textWidth = MeasureText("Press SPACE to continue", 20);
                textHeight = 20;

                textX = SCREEN_WIDTH / 2 - textWidth / 2;
                textY = SCREEN_HEIGHT / 2 + 50;

                DrawText("Press SPACE to continue", textX, textY, 20, BLACK);

                if (IsKeyPressed(KEY_SPACE)) {
                    tutorialStep++;
                }

                EndDrawing();
                break;

            case 2:
                BeginDrawing();
                ClearBackground(RAYWHITE);

                textWidth = MeasureText("Towers will automatically shoot enemies", 30);
                textHeight = 30;

                textX = SCREEN_WIDTH / 2 - textWidth / 2;
                textY = SCREEN_HEIGHT / 2 - textHeight / 2;

                DrawText("Towers will automatically shoot enemies", textX, textY, 30, BLACK);

                textWidth = MeasureText("Press SPACE to continue", 20);
                textHeight = 20;

                textX = SCREEN_WIDTH / 2 - textWidth / 2;
                textY = SCREEN_HEIGHT / 2 + 50;

                DrawText("Press SPACE to continue", textX, textY, 20, BLACK);

                if (IsKeyPressed(KEY_SPACE)) {
                    tutorialStep++;
                }

                EndDrawing();
                break;

            case 3:
                BeginDrawing();
                ClearBackground(RAYWHITE);

                textWidth = MeasureText("The game is over when an enemy reaches the goal", 30);
                textHeight = 30;

                textX = SCREEN_WIDTH / 2 - textWidth / 2;
                textY = SCREEN_HEIGHT / 2 - textHeight / 2;

                DrawText("The game is over when an enemy reaches the goal", textX, textY, 30, BLACK);

                textWidth = MeasureText("Press SPACE to start the game", 20);
                textHeight = 20;

                textX = SCREEN_WIDTH / 2 - textWidth / 2;
                textY = SCREEN_HEIGHT / 2 + 50;

                DrawText("Press SPACE to continue", textX, textY, 20, BLACK);

                if (IsKeyPressed(KEY_SPACE)) {
                    tutorialStep++;
                }

                EndDrawing();
                break;

            case 4:
                BeginDrawing();
            ClearBackground(RAYWHITE);

            textWidth = MeasureText("You win when the enemy is defeated", 30);
            textHeight = 30;

            textX = SCREEN_WIDTH / 2 - textWidth / 2;
            textY = SCREEN_HEIGHT / 2 - textHeight / 2;

            DrawText("You win when the enemy is defeated", textX, textY, 30, BLACK);

            textWidth = MeasureText("Press SPACE to start the game", 20);
            textHeight = 20;

            textX = SCREEN_WIDTH / 2 - textWidth / 2;
            textY = SCREEN_HEIGHT / 2 + 50;

            DrawText("Press SPACE to start the game", textX, textY, 20, BLACK);

            if (IsKeyPressed(KEY_SPACE)) {
                state = GAME;
            }

            EndDrawing();
            break;
        }
    }

    break;

        }
    }

    CloseWindow();
    return 0;
}
