#ifndef __chess_h__
#define __chess_h__
#include<stdio.h>
#include<windows.h>
#include<time.h>
#define ROW 3//������
#define COL 3//������
#define PLAYER1 'X'//���1������
#define COMPUTER 'O'//���Ե�����
#define PLAYER2 'X'//���2������
#define NEXT 'N'//δ��ʤ��������δ��������
#define FULL 'F'//��������������
void menu();//չʾ�˵�
void play_triple();//��ʼ��Ϸ
//void board(char[][COL],int row,int col);
void inti_board(char[][COL],int row,int col);//��ʼ������գ�����
void show_board(char board[][COL], int row, int col);//��ʾ����
void to_player1(char board[][COL], int row, int col);//�������
void to_computer(char board[][COL], int row, int col);//��������
char judge(char board[][COL], int row, int col);//�ж�
int one_step();//�Ⱥ���
#endif