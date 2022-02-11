#include "head.h"

User* userManage(User* _User) {
	User *view[USER_MAX];
	User* cur=_User;
	User* pre=0;
	int userSelect;
	int menuSelect;
	int viewIndex = 0;
	for (int i = 0; i < userCount; i++) {
		if (cur->type == IS_USER)
			view[viewIndex++] = cur;
		cur = cur->nextUserAddress;
	}
	printf(" no.     ID       탈퇴여부\n");
	printf("============================\n");
	for (int i = 0; i < viewIndex; i++) {
		printf(" %d.    %-10s", i + 1, view[i]->ID);
		printf("%5c\n", (view[i]->blind == IS_BLIND ? 'Y' : 'N'));
	}
	printf("============================\n");
	printf("관리할 유저의 번호를 선택하여 주세요\n");
	printf(">>");
	scanf("%d", &userSelect);

	system("cls");
	printf(" no.     ID       탈퇴여부\n");
	printf("=============================\n");
	printf(" %d.    %-10s", userSelect, view[userSelect - 1]->ID);
	printf("%5c\n", (view[userSelect - 1]->blind == IS_BLIND ? 'Y' : 'N'));
	printf("==============================\n");
	printf("1. 패스워드 초기화\n");
	printf("2. 유저 %s\n", (view[userSelect - 1]->blind == IS_BLIND ? "복구" : "탈퇴"));
	printf("3. 유저 삭제\n");
	scanf("%d", &menuSelect);
	printf("\n");

	cur = _User;
	for (int i = 0; i < userCount; i++) {
		if (!(strcmp(cur->ID, view[userSelect - 1]->ID)))
			break;
		pre = cur;
		cur = cur->nextUserAddress;
	}

	switch (menuSelect) {
	case 1:
		printf("패스워드를 초기화합니까? (Y/N)\n");
		printf(">>");
		switch (_getch()) {
		case 'y':
		case 'Y':
			strcpy(cur->PW, "1234");
			break;
		}
		break;
	case 2:
		printf("유저를 %s합니까? (Y/N)\n", (cur->blind == IS_BLIND ? "복구" : "탈퇴"));
		printf(">>");
		switch (_getch()) {
		case 'y':
		case 'Y':
			if (cur->blind == IS_BLIND)
				cur->blind = IS_NORMAL;
			else
				cur->blind = IS_BLIND;
			break;
		}
		break;
	case 3:
		printf("유저 삭제를 진행할 시 데이터가 삭제 되고 복구 할 수 없습니다!!!\n");
		printf("유저를 삭제합니까? (Y/N)\n");
		printf(">>");
		switch (_getch()) {
		case 'y':
		case 'Y':
			if (pre == 0)
				_User = _User->nextUserAddress;
			else 
				pre->nextUserAddress = cur->nextUserAddress;
			free(cur);
			userCount--;
			break;
		}
		break;
	}
	return _User;
}