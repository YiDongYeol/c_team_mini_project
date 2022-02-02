#include "head.h"

int menu() {
	int select=0;

	printf("프로그램 명 뭐로하죠?\n\n");
	printf("1.등록\n");
	printf("2.수정\n");
	printf("3.조회\n");
	printf("4.삭제\n");
	printf("5.복구\n");
	printf("6.종료\n");
	printf(">>");

	scanf("%d", &select);

	system("cls");
	return select;
}