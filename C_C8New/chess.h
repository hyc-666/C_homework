#ifndef __chess_h__
#define __chess_h__
#include<stdio.h>
#include<windows.h>
#include<time.h>
#define ROW 3//棋盘行
#define COL 3//棋盘列
#define PLAYER1 'X'//玩家1的棋子
#define COMPUTER 'O'//电脑的棋子
#define PLAYER2 'X'//玩家2的棋子
#define NEXT 'N'//未分胜负且棋盘未满，继续
#define FULL 'F'//棋盘下满，和棋
void menu();//展示菜单
void play_triple();//开始游戏
//void board(char[][COL],int row,int col);
void inti_board(char[][COL],int row,int col);//初始化（清空）棋盘
void show_board(char board[][COL], int row, int col);//显示棋盘
void to_player1(char board[][COL], int row, int col);//玩家走棋
void to_computer(char board[][COL], int row, int col);//电脑走棋
char judge(char board[][COL], int row, int col);//判断
int one_step();//先后手
#endif