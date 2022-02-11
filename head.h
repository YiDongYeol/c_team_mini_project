#define POST_MAX 100
#define USER_MAX 100
#define TITLE_TEXT_MAX 60							//제목 최대 글자 수
#define MAIN_LINE_MAX 10	
#define MAIN_TEXT_MAX 100							//내용 라인 당 최대 글자 수
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

char currentUser[ID_MAX];							//현재 접속한 아이디
int currentUserType;								//현재 유저의 등급
int postCount;										//등록되어있는 게시글 수
int lastPostNumber;									//다음번에 작성되는 게시글의 번호
int userCount;										//현재 저장된 유저 수

typedef struct User {
	char ID[ID_MAX];								//ID 문자열
	char PW[PW_MAX];								//PW 문자열
	int blind;
	int type;										//유저타입 (0이면 관리자 1이면 일반)
	struct User* nextUserAddress;
}User;
typedef struct Post {
	char titleText[TITLE_TEXT_MAX + 1];				//제목 문자열
	char mainText[MAIN_LINE_MAX][MAIN_TEXT_MAX + 1];	//내용 문자열
	char time[TIME_DIGIT];							//등록 시간 문자열
	char ID[ID_MAX];								//작성한 아이디 문자열
	int number;										//글 번호
	int views;										//조회 수
	int type;										//글 타입 (0이면 일반 1이면 블라인드 2이면 공지사항)
	int curLine;									//작성된 내용의 라인 수
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