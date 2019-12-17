#ifndef __PENTA_CHESS_H__
#define  __PENTA_CHESS_H__
#include<stdio.h>
#include<time.h>
#include<windows.h>
#define ROW 15
#define COL 15
#define PLAYER 'X'//玩家1的棋子
#define COMPUTER 'O'//电脑的棋子
#define NEXT 'N'//未分胜负且棋盘未满，继续
#define FULL 'F'//棋盘下满，和棋

void menu();//展示菜单
void play_penta();
void init_table(char table[][COL], int row, int col);
void show_table(char table[][COL], int row, int col);
void to_player(char board[][COL], int row, int col,int plater_xy[2]);//玩家走棋
void to_computer(char board[][COL], int row, int col,int pc_xy[2]);//电脑走棋
char judge(char board[][COL], int row, int col,int xy[2]);//判断
int one_step();
#endif