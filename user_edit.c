#include "head.h"

int userEdit(User * _User) {
	int currentUserIndex, select;
	char inputPW[21];
	for (int i = 0; i < userCount; i++) {
		if (!(strcmp(_User[i].ID, currentUser))) {
			currentUserIndex = i;
			break;
		}
	}
	printf("����� ���� ����\n\n");
	printf("ID = %s\n", _User[currentUserIndex].ID);
	printf("PW = %s\n\n", _User[currentUserIndex].PW);
	printf("1. �н����� ����\n");
	printf(">>");
	scanf("%d", &select);

	switch (select) {
	case 1:
		system("cls");
		printf("PW = ");
		scanf("%s", inputPW);
		if (strcmp(_User[currentUserIndex].PW, inputPW)) {
			printf("�н����尡 Ʋ���ϴ�.\n");
			system("pause");
			return 0;
		}
		printf("������ PW = ");
		scanf("%s", _User[currentUserIndex].PW);
		return 1;
	}
	return 0;
}