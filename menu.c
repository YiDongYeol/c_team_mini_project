#include "head.h"

int menu() {
	int select = 0;

	printf("IOT �Խ��� Ver.F\n");
	printf("���� ���� = %s   ��� = ", currentUser);
	switch (currentUserType) {
	case IS_ADMIN:
		printf("������\n\n");
		printf("1.�Խñ� ���\n");
		printf("2.�Խñ� ����\n");
		printf("3.�Խñ� ����\n");
		printf("4.�Խñ� ����\n");
		printf("5.����ε� ����\n");
		printf("6.����� ����\n");
		printf("0.�α׾ƿ�\n");
		break;
	case IS_USER:
		printf("�Ϲ�\n\n");
		printf("1.�Խñ� ���\n");
		printf("2.�Խñ� ����\n");
		printf("3.�Խñ� ����\n");
		printf("4.�Խñ� ����\n");
		printf("5.����� ���� ����\n");
		printf("6.����� Ż��\n");
		printf("0.�α׾ƿ�\n");
		break;
	}
	printf(">>");

	scanf("%d", &select);

	system("cls");
	return select;
}