#include "head.h"

int menu() {
	int select=0;

	printf("���α׷� �� ��������?\n\n");
	printf("1.���\n");
	printf("2.����\n");
	printf("3.��ȸ\n");
	printf("4.����\n");
	printf("5.����\n");
	printf("6.����\n");
	printf(">>");

	scanf("%d", &select);

	system("cls");
	return select;
}