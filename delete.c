#include "head.h"


Post* postDelete(Post* _Post)
{
	Post* cur=_Post;
	Post* pre=0;
	int del_selc, del_how = 1;
	char timeDis[15];

	printf(" �۹�ȣ                                  ����                                �ð�         ��ȸ��\n");
	printf("===================================================================================================\n");
	for (int i = 0; i < postCount; i++) {
		if (currentUserType == IS_USER) {
			if (cur->type == IS_BLIND || strcmp(cur->ID, currentUser)) {
				cur = cur->nextPostAddress;
				continue;
			}
		}
		else {
			if (cur->type == IS_BLIND) {
				cur = cur->nextPostAddress;
				continue;
			}
		}
		timeDisplay(cur->time, timeDis);
		printf(" %d    %-40s%35s%9d\n", cur->number, cur->titleText, timeDis, cur->views);
		cur = cur->nextPostAddress;
	}
	printf("===================================================================================================\n");

	printf("������ �Խ����� ��ȣ>>");
	scanf("%d", &del_selc);
	printf("\n");
	if (currentUserType == IS_ADMIN) {
		printf("����ε带 �Ͻðڽ��ϱ�?\n");
		printf("1.Y 2.N\n");
		printf(">>");
		scanf("%d", &del_how);
	}
	cur = _Post;
	switch (del_how) {
	case 1:
		for (int i = 0; i < postCount; i++) {
			if (cur->number == del_selc) {
				if (cur->type == IS_NOTICE) {
					printf("������ ����ε� �� �� �����ϴ�.\n");
					system("pause");
				}
				else 
					cur->type = IS_BLIND;

				break;
			}
			cur = cur->nextPostAddress;
		}

		break;

	case 2:

		for (int i = 0; i < postCount; i++) {
			if (cur->number == del_selc) {
				if (i == 0)
					_Post = _Post->nextPostAddress;
				else
					pre->nextPostAddress = cur->nextPostAddress;
				free(cur);
				postCount--;
				break;
			}
			pre = cur;
			cur = cur->nextPostAddress;
		}

		break;
	}
	return _Post;
}