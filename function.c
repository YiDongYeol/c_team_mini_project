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
//timeStr ���ڿ��� ǥ�ÿ� �����ϰ� �����Ͽ� timeDis ���ڿ��� �����ϴ� �Լ�
//���� 
//timeDisplay(�ð��� ����� ���ڿ�, ǥ�⿡ �°� ������ �����͸� ������ ���ڿ�);
//������ �����͸� ������ ���ڿ��� ���� �����ؼ� ����� �� ũ�� = 15
//���
//timeDis�� ǥ�Ⱑ ������ ���ڿ��� ����ȴ�

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
//�ش� ����Ʈ ����ü�� �ʱ�ȭ ���ִ� �Լ�
//���ڿ��� \0(NULL)������ int���� 0���� �ʱ�ȭ �Ѵ�
//����
//postInitializing(&(_Post[�迭��ȣ]));
//���
//�ش� �迭��ȣ�� _Post ����ü ������ ���� �ʱ�ȭ�ȴ�

void sample(Post* _Post, User* _User) {
	Post* newPost;
	User* newUser;
	strcpy(_Post->titleText, "�ȳ��ϼ���");
	strcpy(_Post->mainText[0], "�ȳ��ϼ���");
	strcpy(_Post->mainText[1], "�ݰ����ϴ�");
	strcpy(_Post->mainText[2], "�� ��Ź�帮�ڽ��ϴ�.");
	strcpy(_Post->time, "0127101014");
	strcpy(_Post->ID, "ph5421");
	_Post->number = 148532;
	_Post->views = 569;
	_Post->type = IS_NOTICE;
	_Post->curLine = 3;
	_Post->nextPostAddress = 0;

	newPost = (Post*)malloc(sizeof(Post));
	strcpy(newPost->titleText, "�̱���");
	strcpy(newPost->mainText[0], "����ε� ó����");
	strcpy(newPost->mainText[1], "���Դϴ�");
	strcpy(newPost->time, "0127113212");
	strcpy(newPost->ID, "kim0123");
	newPost->number = 148533;
	newPost->views = 421;
	newPost->type = IS_BLIND;
	newPost->curLine = 2;
	newPost->nextPostAddress = 0;
	_Post->nextPostAddress = newPost;

	newPost = (Post*)malloc(sizeof(Post));
	strcpy(newPost->titleText, "����");
	strcpy(newPost->mainText[0], "�����");
	strcpy(newPost->mainText[1], "�ſ� ����");
	strcpy(newPost->time, "0127140854");
	strcpy(newPost->ID, "choi486");
	newPost->number = 148534;
	newPost->views = 101;
	newPost->type = IS_NORMAL;
	newPost->curLine = 2;
	newPost->nextPostAddress = 0;
	_Post->nextPostAddress->nextPostAddress = newPost;

	newPost = (Post*)malloc(sizeof(Post));
	strcpy(newPost->titleText, "����2");
	strcpy(newPost->mainText[0], "�����");
	strcpy(newPost->mainText[1], "�ſ� ��������");
	strcpy(newPost->mainText[2], "�ؾ���");
	strcpy(newPost->time, "0125110532");
	strcpy(newPost->ID, "choi486");
	newPost->number = 148531;
	newPost->views = 23;
	newPost->type = IS_NORMAL;
	newPost->curLine = 3;
	newPost->nextPostAddress = 0;
	_Post->nextPostAddress->nextPostAddress->nextPostAddress = newPost;

	newPost = (Post*)malloc(sizeof(Post));
	strcpy(newPost->titleText, "����3");
	strcpy(newPost->mainText[0], "�����");
	strcpy(newPost->mainText[1], "�ſ� ��������");
	strcpy(newPost->mainText[2], "�����Ѵ�");
	strcpy(newPost->time, "0123121110");
	strcpy(newPost->ID, "ph5421");
	newPost->number = 148535;
	newPost->views = 999;
	newPost->type = IS_NORMAL;
	newPost->curLine = 3;
	newPost->nextPostAddress = 0;
	_Post->nextPostAddress->nextPostAddress->nextPostAddress->nextPostAddress = newPost;

	newPost = (Post*)malloc(sizeof(Post));
	strcpy(newPost->titleText, "����4");
	strcpy(newPost->mainText[0], "�����");
	strcpy(newPost->mainText[1], "����");
	strcpy(newPost->mainText[2], "����");
	strcpy(newPost->mainText[3], "����");
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