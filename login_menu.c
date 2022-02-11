#include "head.h"

int loginMenu() {
	int select = 0;

	printf("IOT 게시판 Ver.3\n\n");
	printf("1.로그인\n");
	printf("2.회원가입\n");
	printf("0.종료\n");
	printf(">>");

	scanf("%d", &select);

	system("cls");
	return select;
}