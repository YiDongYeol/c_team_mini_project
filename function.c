#include "head.h"

void currentTime(char* timeStr) {
	time_t t;
	struct tm* timeInfo;

	t = time(NULL);
	timeInfo = localtime(&t);

	sprintf(timeStr, "%02d%02d%02d%02d%02d", (timeInfo->tm_mon) + 1, timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
}
//timeStr 문자열에 현재시간 전체(년,월,일,시,분,초) 중 필요한 정보만 문자열로 저장하는 함수
//사용법
//currentTime(시간을 저장할 문자열);
//결과
//timeStr에 월,일,시,분,초 순으로 10자리가 저장된다
void timeDisplay(char* timeStr, char* timeDis) {
	*(timeDis + 0) = *(timeStr + 0); *(timeDis + 1) = *(timeStr + 1);
	*(timeDis + 2) = '/';
	*(timeDis + 3) = *(timeStr + 2); *(timeDis + 4) = *(timeStr + 3);
	*(timeDis + 5) = ' ';
	*(timeDis + 6) = *(timeStr + 4); *(timeDis + 7) = *(timeStr + 5);
	*(timeDis + 8) = ':';
	*(timeDis + 9) = *(timeStr + 6); *(timeDis + 10) = *(timeStr + 7);
	*(timeDis + 11) = ':';
	*(timeDis + 12) = *(timeStr + 8); *(timeDis + 13) = *(timeStr + 9);
	*(timeDis + 14) = '\0';
}
//timeStr 문자열을 표시에 적절하게 수정하여 timeDis 문자열에 저장하는 함수
//사용법 
//timeDisplay(시간이 저장된 문자열, 표기에 맞게 수정된 데이터를 저장할 문자열);
//수정된 데이터를 저장할 문자열은 따로 선언해서 사용할 것 크기 = 15
//결과
//timeDis에 표기가 수정된 문자열이 저장된다

void postInitializing(Post* _Post){
	for (int i = 0; i < MAIN_LINE_MAX; i++)
		strcpy(_Post->mainText[i], "\0");
	strcpy(_Post->titleText, "\0");
	strcpy(_Post->time, "\0");
	strcpy(_Post->ID, "\0");
	_Post->number = 0;
	_Post->views = 0;
	_Post->type = IS_NORMAL;
	_Post->curLine = 0;
	_Post->nextPostAddress = 0;
}
//해당 포스트 구조체를 초기화 해주는 함수
//문자열은 \0(NULL)값으로 int형은 0으로 초기화 한다
//사용법
//postInitializing(&(_Post[배열번호]));
//결과
//해당 배열번호의 _Post 구조체 내용이 전부 초기화된다

void sample(Post* _Post, User* _User) {
	Post* newPost;
	User* newUser;
	strcpy(_Post->titleText, "안녕하세요");
	strcpy(_Post->mainText[0], "안녕하세요");
	strcpy(_Post->mainText[1], "반갑습니다");
	strcpy(_Post->mainText[2], "잘 부탁드리겠습니다.");
	strcpy(_Post->time, "0127101014");
	strcpy(_Post->ID, "ph5421");
	_Post->number = 148532;
	_Post->views = 569;
	_Post->type = IS_NOTICE;
	_Post->curLine = 3;
	_Post->nextPostAddress = 0;

	newPost = (Post*)malloc(sizeof(Post));
	strcpy(newPost->titleText, "이글은");
	strcpy(newPost->mainText[0], "블라인드 처리된");
	strcpy(newPost->mainText[1], "글입니다");
	strcpy(newPost->time, "0127113212");
	strcpy(newPost->ID, "kim0123");
	newPost->number = 148533;
	newPost->views = 421;
	newPost->type = IS_BLIND;
	newPost->curLine = 2;
	newPost->nextPostAddress = 0;
	_Post->nextPostAddress = newPost;

	newPost = (Post*)malloc(sizeof(Post));
	strcpy(newPost->titleText, "샘플");
	strcpy(newPost->mainText[0], "만들기");
	strcpy(newPost->mainText[1], "매우 귀찮");
	strcpy(newPost->time, "0127140854");
	strcpy(newPost->ID, "choi486");
	newPost->number = 148534;
	newPost->views = 101;
	newPost->type = IS_NORMAL;
	newPost->curLine = 2;
	newPost->nextPostAddress = 0;
	_Post->nextPostAddress->nextPostAddress = newPost;

	newPost = (Post*)malloc(sizeof(Post));
	strcpy(newPost->titleText, "샘플2");
	strcpy(newPost->mainText[0], "만들기");
	strcpy(newPost->mainText[1], "매우 귀찮지만");
	strcpy(newPost->mainText[2], "해야지");
	strcpy(newPost->time, "0125110532");
	strcpy(newPost->ID, "choi486");
	newPost->number = 148531;
	newPost->views = 23;
	newPost->type = IS_NORMAL;
	newPost->curLine = 3;
	newPost->nextPostAddress = 0;
	_Post->nextPostAddress->nextPostAddress->nextPostAddress = newPost;

	newPost = (Post*)malloc(sizeof(Post));
	strcpy(newPost->titleText, "샘플3");
	strcpy(newPost->mainText[0], "만들기");
	strcpy(newPost->mainText[1], "매우 귀찮으니");
	strcpy(newPost->mainText[2], "복붙한다");
	strcpy(newPost->time, "0123121110");
	strcpy(newPost->ID, "ph5421");
	newPost->number = 148535;
	newPost->views = 999;
	newPost->type = IS_NORMAL;
	newPost->curLine = 3;
	newPost->nextPostAddress = 0;
	_Post->nextPostAddress->nextPostAddress->nextPostAddress->nextPostAddress = newPost;

	newPost = (Post*)malloc(sizeof(Post));
	strcpy(newPost->titleText, "샘플4");
	strcpy(newPost->mainText[0], "만들기");
	strcpy(newPost->mainText[1], "복붙");
	strcpy(newPost->mainText[2], "복붙");
	strcpy(newPost->mainText[3], "복붙");
	strcpy(newPost->time, "0129182341");
	strcpy(newPost->ID, "ph5421");
	newPost->number = 147354;
	newPost->views = 9;
	newPost->type = IS_NOTICE;
	newPost->curLine = 4;
	newPost->nextPostAddress = 0;
	_Post->nextPostAddress->nextPostAddress->nextPostAddress->nextPostAddress->nextPostAddress = newPost;
			 
	postCount = 6;
	lastPostNumber = 148536;

	strcpy(_User->ID, "ph5421");
	strcpy(_User->PW, "1q2w3e4r");
	_User->blind = IS_NORMAL;
	_User->type = IS_ADMIN;
	_User->nextUserAddress = 0;

	newUser = (User*)malloc(sizeof(User));
	strcpy(newUser->ID, "kim0123");
	strcpy(newUser->PW, "abcdefgh");
	newUser->blind = IS_BLIND;
	newUser->type = IS_USER;
	newUser->nextUserAddress = 0;
	_User->nextUserAddress = newUser;

	newUser = (User*)malloc(sizeof(User));
	strcpy(newUser->ID, "choi486");
	strcpy(newUser->PW, "qwerasdf");
	newUser->blind = IS_NORMAL;
	newUser->type = IS_USER;
	newUser->nextUserAddress = 0;
	_User->nextUserAddress->nextUserAddress = newUser;

	userCount = 3;
}