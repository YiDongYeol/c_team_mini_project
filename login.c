#include "head.h"

int login(User* _User) {
	char ID[ID_MAX];
	char PW[PW_MAX];
	printf("로그인\n\n");
	printf("ID = ");
	scanf("%s", ID);
	printf("PW = ");
	scanf("%s", PW);
	for (int i = 0; i < userCount; i++) {
		if (!(strcmp(ID, _User[i].ID))) {
			if (!(strcmp(PW, _User[i].PW))) {
				if (_User[i].blind == IS_BLIND) {
					printf("\n해당 유저는 탈퇴 상태 입니다.\n");
					system("pause");
					return 0;
				}
				strcpy(currentUser, ID);
				currentUserType = _User[i].type;
				return 1;
			}
		}
	}
	printf("\n아이디나 비밀번호가 틀립니다.\n");
	system("pause");
	return 0;
}