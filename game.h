#ifndef _GAME_H
#define _GAME_H

#include <stdio.h>
#include <windows.h>
#include <time.h>
#pragma warning(disable:4996)
 
#define ROW 3
#define COL 3

#define PLAYER 'X'//�����X
#define COMP 'O'//������O
#define DRAW 'D'//ƽ��
#define NEXT 'N'//

void game();
void menu();

#endif