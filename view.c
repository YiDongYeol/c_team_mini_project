#define _CRT_SECURE_NO_WARNINGS
#include "head.h"

void postView(Post* _Post) {
	Post* _PostView[POST_MAX];
	Post* tmp=_Post;
	int select;
	int NoticeIndex=0;
	char timeDis[15];

	for (int i = 0; i < postCount; i++) {
		_PostView[i] = tmp;
		tmp = tmp->nextPostAddress;
	}

	printf("(1-��ȣ �� ����, 2-�ð� �� ����, 3-��ȸ �� ����)\n");
	printf(">>");
	scanf("%d", &select);

	switch (select)
	{
	case 1: //��ȣ��
		for (int i = postCount - 1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (_PostView[j]->number > _PostView[j + 1]->number) {
					tmp = _PostView[j];
					_PostView[j] = _PostView[j + 1];
					_PostView[j + 1] = tmp;
				}
			}
		}

		break;
	case 2: //�ð���
		for (int i = postCount - 1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (atoi(_PostView[j]->time) > atoi(_PostView[j + 1]->time)) {
					tmp = _PostView[j];
					_PostView[j] = _PostView[j + 1];
					_PostView[j + 1] = tmp;
				}
			}
		}

		break;
	case 3: //��ȸ��
		for (int i = postCount - 1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (_PostView[j]->views > _PostView[j + 1]->views) {
					tmp = _PostView[j];
					_PostView[j] = _PostView[j + 1];
					_PostView[j + 1] = tmp;
				}
			}
		}

		break;
	}

	for (int i = 0; i < postCount; i++) {
		if (_PostView[i]->type == IS_NOTICE) {
			tmp = _PostView[i];
			for (int j = i; j > NoticeIndex; j--)
				_PostView[j] = _PostView[j-1];
			_PostView[NoticeIndex++] = tmp;
		}
	}
	tmp = _Post;
	system("cls");

	printf(" �۹�ȣ                                  ����                                 �ۼ���         �ð�         ��ȸ��\n");
	printf("================================================================================================================\n");
	for (int i = 0; i < postCount; i++) {
		if (_PostView[i]->type != IS_BLIND) {
			timeDisplay(_PostView[i]->time, timeDis);
			printf(" %d    ", _PostView[i]->number);
			if (_PostView[i]->type == IS_NOTICE) printf("[����]");
			else printf("      ");
			printf("%-34s%33s%18s%9d\n", _PostView[i]->titleText, _PostView[i]->ID, timeDis, _PostView[i]->views);
		}
	}
	printf("================================================================================================================\n");
	printf("��ȸ�� �� ��ȣ�� �����Ͽ� �ּ���.\n");
	printf(">>");
	scanf("%d", &select);

	system("cls");

	for (int i = 0; i < postCount; i++) {
		if (_PostView[i]->number == select)
		{
			timeDisplay(_PostView[i]->time, timeDis);
			printf("====================================================================================================\n");
			printf(" �� ��ȣ : %d   |   �ۼ��� : %s   |   ���� ���� �ð� : %s   |   ��ȸ �� : %d \n", _PostView[i]->number, _PostView[i]->ID, timeDis, _PostView[i]->views);
			printf("----------------------------------------------------------------------------------------------------\n");
			printf(" �� ���� : "); if (_PostView[i]->type == IS_NOTICE) printf("[����]"); printf("%-s\n", _PostView[i]->titleText);
			printf("----------------------------------------------------------------------------------------------------\n");
			for (int j = 0; j < _PostView[i]->curLine; j++)
				printf(" %s\n", _PostView[i]->mainText[j]);
			printf("====================================================================================================\n");
			_PostView[i]->views++;
			break;
		}
	}

	_getch();
}