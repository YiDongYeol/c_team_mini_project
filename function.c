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
	timeDis[0] = timeStr[0]; timeDis[1] = timeStr[1];
	timeDis[2] = '/';
	timeDis[3] = timeStr[2]; timeDis[4] = timeStr[3];
	timeDis[5] = ' ';
	timeDis[6] = timeStr[4]; timeDis[7] = timeStr[5];
	timeDis[8] = ':';
	timeDis[9] = timeStr[6]; timeDis[10] = timeStr[7];
	timeDis[11] = ':';
	timeDis[12] = timeStr[8]; timeDis[13] = timeStr[9];
	timeDis[14] = '\0';
}
//timeStr 문자열을 표시에 적절하게 수정하여 timeDis 문자열에 저장하는 함수
//사용법 
//timeDisplay(시간이 저장된 문자열, 표기에 맞게 수정된 데이터를 저장할 문자열);
//수정된 데이터를 저장할 문자열은 따로 선언해서 사용할 것 크기 = 15
//결과
//timeDis에 표기가 수정된 문자열이 저장된다
 
void postInitializing(Post* _Post) {
	for (int i = 0; i < MAIN_LINE_MAX; i++)
		strcpy(_Post->mainText[i], "\0");
	strcpy(_Post->titleText, "\0");
	strcpy(_Post->time, "\0");
	strcpy(_Post->ID, "\0");
	_Post->number = 0;
	_Post->views = 0;
	_Post->type = IS_NORMAL;
	_Post->curLine = 0;
}
//해당 포스트 구조체를 초기화 해주는 함수
//문자열은 \0(NULL)값으로 int형은 0으로 초기화 한다
//사용법
//postInitializing(&(_Post[배열번호]));
//결과
//해당 배열번호의 _Post 구조체 내용이 전부 초기화된다

void userInitializing(User* _User) {
	strcpy(_User->ID, "\0");
	strcpy(_User->PW, "\0");
	_User->blind = 0;
	_User->type = 0;
}

void sample(Post* _Post, User* _User) {
	strcpy(_Post[0].titleText, "안녕하세요");
	strcpy(_Post[0].mainText[0], "안녕하세요");
	strcpy(_Post[0].mainText[1], "반갑습니다");
	strcpy(_Post[0].mainText[2], "잘 부탁드리겠습니다.");
	strcpy(_Post[0].time, "0127101014");
	strcpy(_Post[0].ID, "ph5421");
	_Post[0].number = 148532;
	_Post[0].views = 569;
	_Post[0].type = IS_NOTICE;
	_Post[0].curLine = 3;

	strcpy(_Post[1].titleText, "이글은");
	strcpy(_Post[1].mainText[0], "블라인드 처리된");
	strcpy(_Post[1].mainText[1], "글입니다");
	strcpy(_Post[1].time, "0127113212");
	strcpy(_Post[1].ID, "kim0123");
	_Post[1].number = 148533;
	_Post[1].views = 421;
	_Post[1].type = IS_BLIND;
	_Post[1].curLine = 2;

	strcpy(_Post[2].titleText, "샘플");
	strcpy(_Post[2].mainText[0], "만들기");
	strcpy(_Post[2].mainText[1], "매우 귀찮");
	strcpy(_Post[2].time, "0127140854");
	strcpy(_Post[2].ID, "choi486");
	_Post[2].number = 148534;
	_Post[2].views = 101;
	_Post[2].type = IS_NORMAL;
	_Post[2].curLine = 2;

	postCount = 3;
	lastPostNumber = 148535;

	strcpy(_User[0].ID, "ph5421");
	strcpy(_User[0].PW, "1q2w3e4r");
	_User[0].blind = IS_NORMAL;
	_User[0].type = IS_ADMIN;
	strcpy(_User[1].ID, "kim0123");
	strcpy(_User[1].PW, "abcdefgh");
	_User[1].blind = IS_BLIND;
	_User[1].type = IS_USER;
	strcpy(_User[2].ID, "choi486");
	strcpy(_User[2].PW, "qwerasdf");
	_User[2].blind = IS_NORMAL;
	_User[2].type = IS_USER;

	userCount = 3;
}
