#pragma once

const unsigned WINDOW_HEIGHT = 700;
const unsigned WINDOW_WIDTH = 1000;
const unsigned LEVELS = 2;
const unsigned TEXT_REGULAR_SIZE = 40;
const unsigned TEXT_BOLD_SIZE = 50;
const unsigned PIC_SIZE = 100;

const std::string BUTTON_MUSIC = "buttonPopMusic.wav", FONT = "funt.ttf",
CLOCK_PRESENT_MUSIC = "ClockPresentMusic.wav",
TRAMPOLINE_MUSIC = "TrampolineMusic.wav",
HARD_GAME_MUSIC = "HardGameMusic.wav",
EASY_GAME_MUSIC = "EasyGameMusic.wav";
/*enum Object_t
{
   //0    //1     //...
	EMPTY, PLAYER, WALL, BOX, ACID, ELEVATOR, BUTTON,
														//IGNORE
	TIME_PRESENT, TRAMPOLINE, GOOD_LAZER, BAD_LAZER, ENUM_SIZE,

};*/

enum class Objects {
	PLAYER = 'P', TIME_PRESENT = 'W', WALL = '#', BOX = 'B', ACID = 'A', ELEVATOR = 'E', BUTTON = 'O', AIR = ' ', TRAMPOLINE = 'T',
	GOOD_LAZER = 'G', BAD_LAZER = 'M'
};


enum buttons
{
	START, EXIT,
};
std::vector <std::string> OBJECTS_PIC_NAMES = { "Player.png" , "Wall.png" , "Box.png"
   ,"BadLazer.png"  , "GoodLazer.png"  , "Acid.png"  , "Elevator.png"  , "Button.png" ,
	"Button.png" , "Trampoline.png" , "TimePresent.png" };

//std::string FILE_NAME = "level_";