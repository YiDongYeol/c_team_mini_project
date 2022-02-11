#include "head.h"

int login(User* _User) {
	char ID[ID_MAX];
	char PW[PW_MAX];
	User* cur=_User;
	printf("로그인\n\n");
	printf("ID = ");
	scanf("%s", ID);
	printf("PW = ");
	scanf("%s", PW);
	for (int i = 0; i < userCount; i++) {
		if (!(strcmp(ID, cur->ID))) {
			if (!(strcmp(PW, cur->PW))) {
				if (cur->blind == IS_BLIND) {
					printf("\n해당 유저는 탈퇴 상태 입니다.\n");
					system("pause");
					return 0;
				}
				strcpy(currentUser, ID);
				currentUserType = cur->type;
				return 1;
			}
		}
		cur = cur->nextUserAddress;
	}
	printf("\n아이디나 비밀번호가 틀립니다.\n");
	system("pause");
	return 0;
}