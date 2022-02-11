#define POST_MAX 100
#define USER_MAX 100
#define TITLE_TEXT_MAX 60							//���� �ִ� ���� ��
#define MAIN_LINE_MAX 10	
#define MAIN_TEXT_MAX 100							//���� ���� �� �ִ� ���� ��
#define TIME_DIGIT 11
#define ID_MAX 11
#define PW_MAX 21
#define IS_NORMAL 0
#define IS_BLIND 1
#define IS_NOTICE 2
#define IS_ADMIN 0
#define IS_USER 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>	
#include <conio.h>
#include <time.h>

char currentUser[ID_MAX];							//���� ������ ���̵�
int currentUserType;								//���� ������ ���
int postCount;										//��ϵǾ��ִ� �Խñ� ��
int lastPostNumber;									//�������� �ۼ��Ǵ� �Խñ��� ��ȣ
int userCount;										//���� ����� ���� ��

typedef struct User {
	char ID[ID_MAX];								//ID ���ڿ�
	char PW[PW_MAX];								//PW ���ڿ�
	int blind;
	int type;										//����Ÿ�� (0�̸� ������ 1�̸� �Ϲ�)
	struct User* nextUserAddress;
}User;
typedef struct Post {
	char titleText[TITLE_TEXT_MAX + 1];				//���� ���ڿ�
	char mainText[MAIN_LINE_MAX][MAIN_TEXT_MAX + 1];	//���� ���ڿ�
	char time[TIME_DIGIT];							//��� �ð� ���ڿ�
	char ID[ID_MAX];								//�ۼ��� ���̵� ���ڿ�
	int number;										//�� ��ȣ
	int views;										//��ȸ ��
	int type;										//�� Ÿ�� (0�̸� �Ϲ� 1�̸� ����ε� 2�̸� ��������)
	int curLine;									//�ۼ��� ������ ���� ��
	struct Post* nextPostAddress;
}Post;

int loginMenu();
void userRegist(User* _User);
int login(User* _User);

int menu();
void postRegist(Post* _Post);
void postEdit(Post* _Post);
void postView(Post* _Post);
Post* postDelete(Post* _Post);
void postRecovery(Post* _Post);
int userEdit(User* _User);
User* userManage(User* _User);
int userBlind(User* _User);

void postInitializing(Post* _Post);
void currentTime(char* timeStr);
void timeDisplay(char* timeStr, char* timeDis);

void sample(Post* _Post, User* _User);