#include "head.h"

int userBlind(User* _User) {
	char inputPW[21];
	User* cur=_User;
	for (int i = 0; i < userCount; i++) {
		if (!(strcmp(cur->ID, currentUser)))
			break;
		cur = cur->nextUserAddress;
	}
	printf("PW = ");
	scanf("%s", inputPW);
	if (strcmp(cur->PW, inputPW)) {
		printf("패스워드가 틀립니다.\n");
		system("pause");
		return 0;
	}
	printf("정말 탈퇴하시겠습니까? (Y/N)\n");
	switch (_getch()) {
	case 'y':
	case 'Y':
		cur->blind = IS_BLIND;
		return 1;
	}
	return 0;
}