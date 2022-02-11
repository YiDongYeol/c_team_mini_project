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
	printf("사용자 정보 변경\n\n");
	printf("ID = %s\n", cur->ID);
	printf("1. 패스워드 변경\n");
	printf(">>");
	scanf("%d", &select);

	switch (select) {
	case 1:
		system("cls");
		printf("PW = ");
		scanf("%s", inputPW);
		if (strcmp(cur->PW, inputPW)) {
			printf("패스워드가 틀립니다.\n");
			system("pause");
			return 0;
		}
		printf("수정할 PW = ");
		scanf("%s", cur->PW);
		return 1;
	}
	return 0;
}