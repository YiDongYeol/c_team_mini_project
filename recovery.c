#include "head.h"

void postRecovery(Post* _Post) {
	Post* cur=_Post;
	char timeDis[15];
	int select;
	printf(" �۹�ȣ                                  ����                                �ð�         ��ȸ��\n");
	printf("===================================================================================================\n");
	for (int i = 0; i < postCount; i++) {
		if (cur->type == IS_BLIND) {
			timeDisplay(cur->time, timeDis);
			printf(" %d    %-40s%35s%9d\n", cur->number, cur->titleText, timeDis, cur->views);
		}
		cur = cur->nextPostAddress;
	}
	printf("===================================================================================================\n");
	printf("������ �� ��ȣ�� �����Ͽ� �ּ���.\n");
	printf(">>");
	scanf("%d", &select);
	cur = _Post;
	for (int i = 0; i < postCount; i++) {
		if (cur->number == select) {
			cur->type = IS_NORMAL;

			break;
		}
		cur = cur->nextPostAddress;
	}
}