#include "head.h"

int menu() {
	int select = 0;

	printf("IOT 게시판 Ver.F\n");
	printf("현재 유저 = %s   등급 = ", currentUser);
	switch (currentUserType) {
	case IS_ADMIN:
		printf("관리자\n\n");
		printf("1.게시글 등록\n");
		printf("2.게시글 수정\n");
		printf("3.게시글 열람\n");
		printf("4.게시글 삭제\n");
		printf("5.블라인드 복구\n");
		printf("6.사용자 관리\n");
		printf("0.로그아웃\n");
		break;
	case IS_USER:
		printf("일반\n\n");
		printf("1.게시글 등록\n");
		printf("2.게시글 수정\n");
		printf("3.게시글 열람\n");
		printf("4.게시글 삭제\n");
		printf("5.사용자 정보 변경\n");
		printf("6.사용자 탈퇴\n");
		printf("0.로그아웃\n");
		break;
	}
	printf(">>");

	scanf("%d", &select);

	system("cls");
	return select;
}