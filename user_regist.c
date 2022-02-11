#include "head.h"

void userRegist(User* _User) {
	char code[11];
	int select;
	User* cur=_User;
	User* newUser;

	if (userCount == USER_MAX) {
		printf("�ִ� �������� �ʰ��մϴ�.\n");
		system("pause");
		return;
	}

	newUser = (User*)malloc(sizeof(User));
	printf("ȸ������\n\n");
	printf("1. �Ϲ�ȸ��\n");
	printf("2. ������ȸ��\n");
	printf(">>");
	scanf("%d", &select);
	switch (select) {
	case 1:
		newUser->type = IS_USER;
		break;
	case 2:
		printf("\n�ڵ� = ");
		scanf("%s", code);
		if (!(strcmp(code, "1234"))) {
			system("cls");
			newUser->type = IS_ADMIN;
			break;
		}
		else {
			printf("�ڵ尡 Ʋ���ϴ�.\n");
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
			printf("\n�̹� ���� ���̵� �����մϴ�.\n");
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