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
		printf("�н����尡 Ʋ���ϴ�.\n");
		system("pause");
		return 0;
	}
	printf("���� Ż���Ͻðڽ��ϱ�? (Y/N)\n");
	switch (_getch()) {
	case 'y':
	case 'Y':
		_User[currentUserIndex].blind = !(_User[currentUserIndex].blind);
		return 1;
	}
	return 0;
}