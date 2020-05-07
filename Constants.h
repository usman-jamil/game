#pragma once
const int BOARD_MAX_WIDTH = 801;
const int BOARD_MAX_HEIGHT = 801;
const int PLAYER_MAX_SIZE = 500;
const int GAME_MAX_WIDTH = 1100;
const int GAME_MAX_HEIGHT = 800;

const float STEP_SIZE_X = (BOARD_MAX_WIDTH) / 10;
const float STEP_SIZE_Y = (BOARD_MAX_HEIGHT) / 10;

const float PLAYER_SIZE_X = (float)STEP_SIZE_X / PLAYER_MAX_SIZE;
const float PLAYER_SIZE_Y = (float)STEP_SIZE_Y / PLAYER_MAX_SIZE;

const int PLAYER_ONE_PADDING_LEFT = 15;
const int PLAYER_ONE_PADDING_TOP = 15;

const int PLAYER_TWO_PADDING_LEFT = 40;
const int PLAYER_TWO_PADDING_TOP = 15;

const int PLAYER_THREE_PADDING_LEFT = 25;
const int PLAYER_THREE_PADDING_TOP = 45;

const int paddings[3][2] = 
{
    {PLAYER_ONE_PADDING_LEFT, PLAYER_ONE_PADDING_TOP},
    {PLAYER_TWO_PADDING_LEFT, PLAYER_TWO_PADDING_TOP},
    {PLAYER_THREE_PADDING_LEFT, PLAYER_THREE_PADDING_TOP}
};

const int POSITIONS[100][2] =
{
    {0, 9},
    {1, 9},
    {2, 9},
    {3, 9},
    {4, 9},
    {5, 9},
    {6, 9},
    {7, 9},
    {8, 9},
    {9, 9},
    {9, 8},
    {8, 8},
    {7, 8},
    {6, 8},
    {5, 8},
    {4, 8},
    {3, 8},
    {2, 8},
    {1, 8},
    {0, 8},
    {0, 7},
    {1, 7},
    {2, 7},
    {3, 7},
    {4, 7},
    {5, 7},
    {6, 7},
    {7, 7},
    {8, 7},
    {9, 7},
    {9, 6},
    {8, 6},
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
    {8, 5},
    {9, 5},
    {9, 4},
    {8, 4},
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
    {8, 3},
    {9, 3},
    {9, 2},
    {8, 2},
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
    {8, 1},
    {9, 1},
    {9, 0},
    {8, 0},
    {7, 0},
    {6, 0},
    {5, 0},
    {4, 0},
    {3, 0},
    {2, 0},
    {1, 0},
    {0, 0}
};