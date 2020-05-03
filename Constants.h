#pragma once
const int BOARD_MAX_WIDTH = 2009;
const int BOARD_MAX_HEIGHT = 2007;
const int PLAYER_MAX_SIZE = 500;
const int GAME_MAX_WIDTH = 1100;
const int GAME_MAX_HEIGHT = 800;

//this is for the background resolution 1100
const float BOARD_SCALE_FACTOR_X = 0.39f;

//this is for the background resolution 800
const float BOARD_SCALE_FACTOR_Y = 0.39f;

//const float TEXT_POSITION_X = 

const float STEP_SIZE_X = (BOARD_MAX_WIDTH * BOARD_SCALE_FACTOR_X) / 8;
const float STEP_SIZE_Y = (BOARD_MAX_HEIGHT * BOARD_SCALE_FACTOR_Y) / 8;

const int PADDING_LEFT = 9;
const int PADDING_TOP = 9;

const float PLAYER_SIZE_X = (float)STEP_SIZE_X / PLAYER_MAX_SIZE;
const float PLAYER_SIZE_Y = (float)STEP_SIZE_Y / PLAYER_MAX_SIZE;

const int POSITIONS[64][2] =
{
    {0, 7},
    {1, 7},
    {2, 7},
    {3, 7},
    {4, 7},
    {5, 7},
    {6, 7},
    {7, 7},
    {7, 6},
    {6, 6},
    {5, 6},
    {4, 6},
    {3, 6},
    {2, 6},
    {1, 6},
    {0, 6},
    {0, 5},
    {1, 5},
    {2, 5},
    {3, 5},
    {4, 5},
    {5, 5},
    {6, 5},
    {7, 5},
    {7, 4},
    {6, 4},
    {5, 4},
    {4, 4},
    {3, 4},
    {2, 4},
    {1, 4},
    {0, 4},
    {0, 3},
    {1, 3},
    {2, 3},
    {3, 3},
    {4, 3},
    {5, 3},
    {6, 3},
    {7, 3},
    {7, 2},
    {6, 2},
    {5, 2},
    {4, 2},
    {3, 2},
    {2, 2},
    {1, 2},
    {0, 2},
    {0, 1},
    {1, 1},
    {2, 1},
    {3, 1},
    {4, 1},
    {5, 1},
    {6, 1},
    {7, 1},
    {7, 0},
    {6, 0},
    {5, 0},
    {4, 0},
    {3, 0},
    {2, 0},
    {1, 0},
    {0, 0},
};