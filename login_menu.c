#include "head.h"

int loginMenu() {
	int select = 0;

	printf("IOT �Խ��� Ver.3\n\n");
	printf("1.�α���\n");
	printf("2.ȸ������\n");
	printf("0.����\n");
	printf(">>");

	scanf("%d", &select);

	system("cls");
	return select;
}