#include "head.h"

void postView(Post *_Post) {
	int select;
	int sortRank[POST_MAX];
	char timeDis[15];

	for (int i = 0; i < postCount; i++)
		sortRank[i] = 1;
	
	printf("(1-��ȣ �� ����, 2-�ð� �� ����, 3-��ȸ �� ����)\n");
	printf(">>");
	scanf("%d", &select);

	switch (select)
	{
	case 1: //��ȣ��
		for (int i = 0; i < postCount; i++) {
			for (int j = 0; j < postCount; j++) {
				if (_Post[i].number > _Post[j].number)
					sortRank[i]++;
			}
		}

		break;
	case 2: //�ð���
		for (int i = 0; i < postCount; i++) {
			for (int j = 0; j < postCount; j++) {
				if (atoi(_Post[i].time) > atoi(_Post[j].time))
					sortRank[i]++;
			}
		}

		break;
	case 3: //��ȸ��
		for (int i = 0; i < postCount; i++) {
			for (int j = 0; j < postCount; j++) {
				if (_Post[i].views > _Post[j].views)
					sortRank[i]++;
			}
		}

		break;
	}
	for (int i = 0; i < postCount; i++) {
		if (_Post[i].type == IS_NOTICE)
			sortRank[i] = 0;
	}

	system("cls");

	printf(" �۹�ȣ                                  ����                                 �ۼ���         �ð�         ��ȸ��\n");
	printf("================================================================================================================\n");
	for (int i = 0; i < postCount + 1; i++) {
		for (int j = 0; j < postCount; j++) {
			if ((i == sortRank[j]) && _Post[j].type != IS_BLIND) {
				timeDisplay(_Post[j].time, timeDis);
				printf(" %d    ", _Post[j].number);
				if (_Post[j].type == IS_NOTICE) printf("[����]");
				else printf("      ");
				printf("%-34s%33s%18s%9d\n", _Post[j].titleText, _Post[j].ID, timeDis, _Post[j].views);
			}
		}
	}
	printf("================================================================================================================\n");
	printf("��ȸ�� �� ��ȣ�� �����Ͽ� �ּ���.\n");
	printf(">>");
	scanf("%d", &select);

	system("cls");

	for (int i = 0; i < postCount; i++) {
		if (_Post[i].number == select)
		{
			timeDisplay(_Post[i].time, timeDis);
			printf("====================================================================================================\n");
			printf(" �� ��ȣ : %d   |   �ۼ��� : %s   |   ���� ���� �ð� : %s   |   ��ȸ �� : %d \n", _Post[i].number, _Post[i].ID, timeDis, _Post[i].views);
			printf("----------------------------------------------------------------------------------------------------\n");
			printf(" �� ���� : "); if (_Post[i].type == IS_NOTICE) printf("[����]"); printf("%-s\n", _Post[i].titleText);
			printf("----------------------------------------------------------------------------------------------------\n");
			for (int j = 0; j < _Post[i].curLine; j++)
				printf(" %s\n", _Post[i].mainText[j]);
			printf("====================================================================================================\n");
			_Post[i].views++;
		}
	}

	_getch();
}
