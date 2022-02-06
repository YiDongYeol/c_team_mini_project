#include "head.h"

int userBlind(User* _User) {
	int currentUserIndex;
	char inputPW[21];
	for (int i = 0; i < userCount; i++) {
		if (!(strcmp(_User[i].ID, currentUser))) {
			currentUserIndex = i;
			break;
		}
	}
	printf("PW = ");
	scanf("%s", inputPW);
	if (strcmp(_User[currentUserIndex].PW, inputPW)) {
		printf("패스워드가 틀립니다.\n");
		system("pause");
		return 0;
	}
	printf("정말 탈퇴하시겠습니까? (Y/N)\n");
	switch (_getch()) {
	case 'y':
	case 'Y':
		_User[currentUserIndex].blind = !(_User[currentUserIndex].blind);
		return 1;
	}
	return 0;
}