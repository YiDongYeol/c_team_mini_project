#define TITLE_TEXT_MAX 60							//���� �ִ� ���� ��
#define MAIN_LINE_MAX 10	
#define MAIN_TEXT_MAX 100							//���� ���� �� �ִ� ���� ��
#define POST_MAX 10									//�Խñ� �ִ��
#define TIME_DIGIT 11
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

int postCount;										//��ϵǾ��ִ� �Խñ� ��
int lastPostNumber;									//�������� �ۼ��Ǵ� �Խñ��� ��ȣ
	
typedef struct Post {
	char titleText[TITLE_TEXT_MAX+1];				//���� ���ڿ�
	char mainText[MAIN_LINE_MAX][MAIN_TEXT_MAX+1];	//���� ���ڿ�
	char time[TIME_DIGIT];							//��� �ð�
	int number;										//�� ��ȣ
	int views;										//��ȸ ��
	int blind;										//����ε� ���� (0�̸� �ƴϰ� 1�̸� ����ε�)
	int curLine;									//�ۼ��� ������ ���� ��

}Post;

int menu();

void postRegist(Post* _Post);
void postEdit(Post* _Post);
void postView(Post* _Post);
void postDelete(Post* _Post);

void postInitializing(Post* _Post);
void currentTime(char* timeStr);
void timeDisplay(char* timeStr, char* timeDis);

void sample(Post* _Post);