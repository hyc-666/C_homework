#ifndef __MINE_CLEAR_H__
#define __MINE_CLEAR_H__

#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<string.h>

#define ROW 12
#define COL 12
#define MINE_NUM 10

void menu();
void game_start();
void set_mine(char mine_table[][COL], int row, int col);
void show(char show_table[][COL],int row, int col);
int clear_mine(char mine_table[][COL], int row, int col);//��ʼɨ��
char count_mine(char mine_table[][COL], int x, int y);//��Χ�׵ĸ���
void open(char mine_table[][COL], char show_table[][COL], int x, int y);//�����Χû���ף���չ��
void no_min(char mine_table[][COL],int x0,int y0);//��û���׵�һ����
int win(char show_table[][COL], int row, int col);

#endif
