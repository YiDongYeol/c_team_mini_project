#include "head.h"

void userRegist(User* _User) {
	char ID[ID_MAX];
	char PW[PW_MAX];
	char code[11];
	int select;
	int type=IS_USER;

	printf("회원가입\n\n");
	printf("1. 일반회원\n");
	printf("2. 관리자회원\n");
	printf(">>");
	scanf("%d", &select);
	switch (select) {
	case 1:
		_User[userCount].type = 1;
		break;
	case 2:
		printf("\n코드 = ");
		scanf("%s", code);
		if (!(strcmp(code, "1234"))) {
			system("cls");
			type = IS_ADMIN;
			break;
		}
		else {
			printf("코드가 틀립니다.\n");
			system("pause");
			return;
		}
	}

	printf("ID = ");
	scanf("%s", ID);
	printf("PW = ");
	scanf("%s", PW);

	for (int i = 0; i < userCount; i++) {
		if (!(strcmp(ID, _User[i].ID))) {
			printf("\n이미 같은 아이디가 존재합니다.\n");
			system("pause");
			return;
		}
	}
	strcpy(_User[userCount].ID, ID);
	strcpy(_User[userCount].PW, PW);
	_User[userCount].type = type;
	userCount++;
}