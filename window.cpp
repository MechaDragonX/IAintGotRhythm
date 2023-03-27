#include "raylib.h"

int main() {
    const int screenWidth = 1600;
    const int screenHeight = 900;
    InitWindow(screenWidth, screenHeight, "What is this?");
    SetTargetFPS(60);

    Vector2 circlePosition = {
        (float)screenWidth / 2,
        (float)screenHeight / 2
    };

    while(!WindowShouldClose()) {
        // Update

        // Draw
        BeginDrawing();
            ClearBackground(DARKBLUE);
            DrawCircleV(circlePosition, 100, RAYWHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
