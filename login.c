#include "head.h"

int login(User* _User) {
	char ID[ID_MAX];
	char PW[PW_MAX];
	printf("�α���\n\n");
	printf("ID = ");
	scanf("%s", ID);
	printf("PW = ");
	scanf("%s", PW);
	for (int i = 0; i < userCount; i++) {
		if (!(strcmp(ID, _User[i].ID))) {
			if (!(strcmp(PW, _User[i].PW))) {
				if (_User[i].blind == IS_BLIND) {
					printf("\n�ش� ������ Ż�� ���� �Դϴ�.\n");
					system("pause");
					return 0;
				}
				strcpy(currentUser, ID);
				currentUserType = _User[i].type;
				return 1;
			}
		}
	}
	printf("\n���̵� ��й�ȣ�� Ʋ���ϴ�.\n");
	system("pause");
	return 0;
}