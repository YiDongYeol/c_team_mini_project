#define TITLE_TEXT_MAX 60							//제목 최대 글자 수
#define MAIN_LINE_MAX 10	
#define MAIN_TEXT_MAX 100							//내용 라인 당 최대 글자 수
#define POST_MAX 10									//게시글 최대수
#define TIME_DIGIT 11
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

int postCount;										//등록되어있는 게시글 수
int lastPostNumber;									//다음번에 작성되는 게시글의 번호
	
typedef struct Post {
	char titleText[TITLE_TEXT_MAX+1];				//제목 문자열
	char mainText[MAIN_LINE_MAX][MAIN_TEXT_MAX+1];	//내용 문자열
	char time[TIME_DIGIT];							//등록 시간
	int number;										//글 번호
	int views;										//조회 수
	int blind;										//블라인드 여부 (0이면 아니고 1이면 블라인드)
	int curLine;									//작성된 내용의 라인 수

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