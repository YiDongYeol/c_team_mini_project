#include "head.h"

int userEdit(User* _User) {
	int select;
	char inputPW[21];
	User* cur = _User;
	for (int i = 0; i < userCount; i++) {
		if (!(strcmp(cur->ID, currentUser)))
			break;
		cur = cur->nextUserAddress;
	}
	printf("����� ���� ����\n\n");
	printf("ID = %s\n", cur->ID);
	printf("1. �н����� ����\n");
	printf(">>");
	scanf("%d", &select);

	switch (select) {
	case 1:
		system("cls");
		printf("PW = ");
		scanf("%s", inputPW);
		if (strcmp(cur->PW, inputPW)) {
			printf("�н����尡 Ʋ���ϴ�.\n");
			system("pause");
			return 0;
		}
		printf("������ PW = ");
		scanf("%s", cur->PW);
		return 1;
	}
	return 0;
}