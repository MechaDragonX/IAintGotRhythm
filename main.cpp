#include <iostream>
#include <map>
#include <string>
#include "raylib.h"
#include "controls.hpp"

int main() {
    const int screenWidth = 1600;
    const int screenHeight = 900;
    InitWindow(screenWidth, screenHeight, "What is this?");
    SetTargetFPS(60);

    Vector2 circlePosition = {
        (float)screenWidth / 2,
        (float)screenHeight / 2
    };

    //Controls
    keyboardControls.insert(std::pair<Controls, KeyboardKey>(Controls::Confirm, KEY_ENTER));
    keyboardControls.insert(std::pair<Controls, KeyboardKey>(Controls::Cancel, KEY_BACKSPACE));
    keyboardControls.insert(std::pair<Controls, KeyboardKey>(Controls::Up, KEY_UP));
    keyboardControls.insert(std::pair<Controls, KeyboardKey>(Controls::Down, KEY_DOWN));
    keyboardControls.insert(std::pair<Controls, KeyboardKey>(Controls::Left, KEY_LEFT));
    keyboardControls.insert(std::pair<Controls, KeyboardKey>(Controls::Right, KEY_RIGHT));
    keyboardControls.insert(std::pair<Controls, KeyboardKey>(Controls::Hit, KEY_X));

    if(IsGamepadAvailable(0) && (GetGamepadName(0) != SWITCH_NAME_ID)) {
        gamepadControls.insert(std::pair<Controls, int>(Controls::Confirm, GAMEPAD_BUTTON_RIGHT_FACE_DOWN));
        gamepadControls.insert(std::pair<Controls, int>(Controls::Cancel, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT));
        gamepadControls.insert(std::pair<Controls, int>(Controls::Hit, GAMEPAD_BUTTON_RIGHT_FACE_DOWN));
    } else {
        gamepadControls.insert(std::pair<Controls, int>(Controls::Confirm, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT));
        gamepadControls.insert(std::pair<Controls, int>(Controls::Cancel, GAMEPAD_BUTTON_RIGHT_FACE_DOWN));
        gamepadControls.insert(std::pair<Controls, int>(Controls::Hit, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT));
    }
    gamepadControls.insert(std::pair<Controls, int>(Controls::Up, GAMEPAD_BUTTON_LEFT_FACE_UP));
    gamepadControls.insert(std::pair<Controls, int>(Controls::Down, GAMEPAD_BUTTON_LEFT_FACE_DOWN));
    gamepadControls.insert(std::pair<Controls, int>(Controls::Left, GAMEPAD_BUTTON_LEFT_FACE_LEFT));
    gamepadControls.insert(std::pair<Controls, int>(Controls::Right, GAMEPAD_BUTTON_LEFT_FACE_RIGHT));

    // Color circleColor = RAYWHITE;
    bool isHit = false;

    while(!WindowShouldClose()) {
        // Update
        if(IsKeyPressed(keyboardControls[Controls::Hit]) || IsGamepadButtonPressed(0, gamepadControls[Controls::Hit]))
            isHit = true;
        if(IsKeyUp(keyboardControls[Controls::Hit]) || IsGamepadButtonUp(0, gamepadControls[Controls::Hit]))
            isHit = false;

        // Draw
        BeginDrawing();
            ClearBackground(DARKBLUE);
            if(!isHit)
                DrawCircleV(circlePosition, 100, RAYWHITE);
            else
                DrawCircleV(circlePosition, 100, RED);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
