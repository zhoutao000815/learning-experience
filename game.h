#ifndef _GAME_H
#define _GAME_H

#include <stdio.h>
#include <windows.h>
#include <time.h>
#pragma warning(disable:4996)
 
#define ROW 3
#define COL 3

#define PLAYER 'X'//玩家用X
#define COMP 'O'//电脑用O
#define DRAW 'D'//平局
#define NEXT 'N'//

void game();
void menu();

#endif