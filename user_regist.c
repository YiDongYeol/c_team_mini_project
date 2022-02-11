#include "head.h"

void userRegist(User* _User) {
	char code[11];
	int select;
	User* cur=_User;
	User* newUser;

	if (userCount == USER_MAX) {
		printf("최대 유저수를 초과합니다.\n");
		system("pause");
		return;
	}

	newUser = (User*)malloc(sizeof(User));
	printf("회원가입\n\n");
	printf("1. 일반회원\n");
	printf("2. 관리자회원\n");
	printf(">>");
	scanf("%d", &select);
	switch (select) {
	case 1:
		newUser->type = IS_USER;
		break;
	case 2:
		printf("\n코드 = ");
		scanf("%s", code);
		if (!(strcmp(code, "1234"))) {
			system("cls");
			newUser->type = IS_ADMIN;
			break;
		}
		else {
			printf("코드가 틀립니다.\n");
			system("pause");
			free(newUser);
			return;
		}
	}

	printf("ID = ");
	scanf("%s", newUser->ID);
	printf("PW = ");
	scanf("%s", newUser->PW);

	for (int i = 0; i < userCount; i++) {
		if (!(strcmp(newUser->ID, cur->ID))) {
			printf("\n이미 같은 아이디가 존재합니다.\n");
			system("pause");
			free(newUser);
			return;
		}
		cur = cur->nextUserAddress;
	}
	newUser->nextUserAddress = 0;
	while (cur->nextUserAddress != 0)
		cur = cur->nextUserAddress;
	cur->nextUserAddress = newUser;
	userCount++;
}