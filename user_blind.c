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
		printf("�н����尡 Ʋ���ϴ�.\n");
		system("pause");
		return 0;
	}
	printf("���� Ż���Ͻðڽ��ϱ�? (Y/N)\n");
	switch (_getch()) {
	case 'y':
	case 'Y':
		cur->blind = IS_BLIND;
		return 1;
	}
	return 0;
}