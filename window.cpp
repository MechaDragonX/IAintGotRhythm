#include "raylib.h"

int main() {
    const int screenWidth = 1600;
    const int screenHeight = 900;
    InitWindow(screenWidth, screenHeight, "What is this?");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        // Update

        // Draw
        BeginDrawing();
            ClearBackground(DARKBLUE);
            DrawText("Some text", 190, 200, 30, RAYWHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
