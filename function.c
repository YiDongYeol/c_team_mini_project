#include "head.h"

void currentTime(char* timeStr) {
	time_t t;
	struct tm* timeInfo;

	t = time(NULL);
	timeInfo = localtime(&t);

	sprintf(timeStr, "%02d%02d%02d%02d%02d", (timeInfo->tm_mon) + 1, timeInfo->tm_mday, timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);
}
//timeStr ���ڿ��� ����ð� ��ü(��,��,��,��,��,��) �� �ʿ��� ������ ���ڿ��� �����ϴ� �Լ�
//����
//currentTime(�ð��� ������ ���ڿ�);
//���
//timeStr�� ��,��,��,��,�� ������ 10�ڸ��� ����ȴ�
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
//timeStr ���ڿ��� ǥ�ÿ� �����ϰ� �����Ͽ� timeDis ���ڿ��� �����ϴ� �Լ�
//���� 
//timeDisplay(�ð��� ����� ���ڿ�, ǥ�⿡ �°� ������ �����͸� ������ ���ڿ�);
//������ �����͸� ������ ���ڿ��� ���� �����ؼ� ����� �� ũ�� = 15
//���
//timeDis�� ǥ�Ⱑ ������ ���ڿ��� ����ȴ�
 
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
//�ش� ����Ʈ ����ü�� �ʱ�ȭ ���ִ� �Լ�
//���ڿ��� \0(NULL)������ int���� 0���� �ʱ�ȭ �Ѵ�
//����
//postInitializing(&(_Post[�迭��ȣ]));
//���
//�ش� �迭��ȣ�� _Post ����ü ������ ���� �ʱ�ȭ�ȴ�

void userInitializing(User* _User) {
	strcpy(_User->ID, "\0");
	strcpy(_User->PW, "\0");
	_User->blind = 0;
	_User->type = 0;
}

void sample(Post* _Post, User* _User) {
	strcpy(_Post[0].titleText, "�ȳ��ϼ���");
	strcpy(_Post[0].mainText[0], "�ȳ��ϼ���");
	strcpy(_Post[0].mainText[1], "�ݰ����ϴ�");
	strcpy(_Post[0].mainText[2], "�� ��Ź�帮�ڽ��ϴ�.");
	strcpy(_Post[0].time, "0127101014");
	strcpy(_Post[0].ID, "ph5421");
	_Post[0].number = 148532;
	_Post[0].views = 569;
	_Post[0].type = IS_NOTICE;
	_Post[0].curLine = 3;

	strcpy(_Post[1].titleText, "�̱���");
	strcpy(_Post[1].mainText[0], "����ε� ó����");
	strcpy(_Post[1].mainText[1], "���Դϴ�");
	strcpy(_Post[1].time, "0127113212");
	strcpy(_Post[1].ID, "kim0123");
	_Post[1].number = 148533;
	_Post[1].views = 421;
	_Post[1].type = IS_BLIND;
	_Post[1].curLine = 2;

	strcpy(_Post[2].titleText, "����");
	strcpy(_Post[2].mainText[0], "�����");
	strcpy(_Post[2].mainText[1], "�ſ� ����");
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
