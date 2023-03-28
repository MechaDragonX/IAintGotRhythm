#ifndef CONTROLS_HPP
#define CONTROLS_HPP

#include <map>
#include <string>
#include "raylib.h"

enum Controls {
    Confirm,
    Cancel,
    Up,
    Down,
    Left,
    Right,
    Hit
};

const std::string XBOX_360_NAME_ID = "Xbox 360 Controller";
const std::string XBOX_ONE_NAME_ID = "Microsoft Corp. Xbox One Controller";
const std::string XBOX_SERIES_NAME_ID = "Microsoft Corp. Xbox Wireless Controller";
const std::string PS3_NAME_ID = "PLAYSTATION(R)3 Controller";
const std::string PS4_NAME_ID = "Wireless Controller";
const std::string PS5_NAME_ID = "Wireless controller";
const std::string SWITCH_NAME_ID = "Nintendo Switch Pro Controller";

std::map<Controls, KeyboardKey> keyboardControls;
std::map<Controls, int> gamepadControls;

#endif
