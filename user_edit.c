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
	printf("사용자 정보 변경\n\n");
	printf("ID = %s\n", _User[currentUserIndex].ID);
	printf("PW = %s\n\n", _User[currentUserIndex].PW);
	printf("1. 패스워드 변경\n");
	printf(">>");
	scanf("%d", &select);

	switch (select) {
	case 1:
		system("cls");
		printf("PW = ");
		scanf("%s", inputPW);
		if (strcmp(_User[currentUserIndex].PW, inputPW)) {
			printf("패스워드가 틀립니다.\n");
			system("pause");
			return 0;
		}
		printf("수정할 PW = ");
		scanf("%s", _User[currentUserIndex].PW);
		return 1;
	}
	return 0;
}