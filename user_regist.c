#include "head.h"

void userRegist(User* _User) {
	char ID[ID_MAX];
	char PW[PW_MAX];
	char code[11];
	int select;
	int type=IS_USER;

	printf("ȸ������\n\n");
	printf("1. �Ϲ�ȸ��\n");
	printf("2. ������ȸ��\n");
	printf(">>");
	scanf("%d", &select);
	switch (select) {
	case 1:
		_User[userCount].type = 1;
		break;
	case 2:
		printf("\n�ڵ� = ");
		scanf("%s", code);
		if (!(strcmp(code, "1234"))) {
			system("cls");
			type = IS_ADMIN;
			break;
		}
		else {
			printf("�ڵ尡 Ʋ���ϴ�.\n");
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
			printf("\n�̹� ���� ���̵� �����մϴ�.\n");
			system("pause");
			return;
		}
	}
	strcpy(_User[userCount].ID, ID);
	strcpy(_User[userCount].PW, PW);
	_User[userCount].type = type;
	userCount++;
}