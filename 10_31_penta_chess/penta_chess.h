#ifndef __PENTA_CHESS_H__
#define  __PENTA_CHESS_H__
#include<stdio.h>
#include<time.h>
#include<windows.h>
#define ROW 15
#define COL 15
#define PLAYER 'X'//���1������
#define COMPUTER 'O'//���Ե�����
#define NEXT 'N'//δ��ʤ��������δ��������
#define FULL 'F'//��������������

void menu();//չʾ�˵�
void play_penta();
void init_table(char table[][COL], int row, int col);
void show_table(char table[][COL], int row, int col);
void to_player(char board[][COL], int row, int col,int plater_xy[2]);//�������
void to_computer(char board[][COL], int row, int col,int pc_xy[2]);//��������
char judge(char board[][COL], int row, int col,int xy[2]);//�ж�
int one_step();
#endif