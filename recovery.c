#include "head.h"

void postRecovery(Post* _Post) {
	char timeDis[15];
	int select;
	printf(" �۹�ȣ                                  ����                                �ð�         ��ȸ��\n");
	printf("===================================================================================================\n");
	for (int i = 0; i < postCount; i++) {
		if (_Post[i].type == IS_BLIND) {
			timeDisplay(_Post[i].time, timeDis);
			printf(" %d    %-40s%35s%9d\n", _Post[i].number, _Post[i].titleText, timeDis, _Post[i].views);
		}
	}
	printf("===================================================================================================\n");
	printf("������ �� ��ȣ�� �����Ͽ� �ּ���.\n");
	printf(">>");
	scanf("%d", &select);
	for (int i = 0; i < postCount; i++) {
		if (_Post[i].number == select) {
			_Post[i].type = IS_NORMAL;

			break;
		}
	}
}