#include "head.h"

void postView(Post *_Post) {
	int select;
	int sortRank[POST_MAX];
	char timeDis[15];

	for (int i = 0; i < postCount; i++)
		sortRank[i] = 1;
	
	printf("(1-번호 순 정렬, 2-시간 순 정렬, 3-조회 수 정렬)\n");
	printf(">>");
	scanf("%d", &select);

	switch (select)
	{
	case 1: //번호순
		for (int i = 0; i < postCount; i++) {
			for (int j = 0; j < postCount; j++) {
				if (_Post[i].number > _Post[j].number)
					sortRank[i]++;
			}
		}

		break;
	case 2: //시간순
		for (int i = 0; i < postCount; i++) {
			for (int j = 0; j < postCount; j++) {
				if (atoi(_Post[i].time) > atoi(_Post[j].time))
					sortRank[i]++;
			}
		}

		break;
	case 3: //조회순
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

	printf(" 글번호                                  제목                                 작성자         시간         조회수\n");
	printf("================================================================================================================\n");
	for (int i = 0; i < postCount + 1; i++) {
		for (int j = 0; j < postCount; j++) {
			if ((i == sortRank[j]) && _Post[j].type != IS_BLIND) {
				timeDisplay(_Post[j].time, timeDis);
				printf(" %d    ", _Post[j].number);
				if (_Post[j].type == IS_NOTICE) printf("[공지]");
				else printf("      ");
				printf("%-34s%33s%18s%9d\n", _Post[j].titleText, _Post[j].ID, timeDis, _Post[j].views);
			}
		}
	}
	printf("================================================================================================================\n");
	printf("조회할 글 번호를 선택하여 주세요.\n");
	printf(">>");
	scanf("%d", &select);

	system("cls");

	for (int i = 0; i < postCount; i++) {
		if (_Post[i].number == select)
		{
			timeDisplay(_Post[i].time, timeDis);
			printf("====================================================================================================\n");
			printf(" 글 번호 : %d   |   작성자 : %s   |   최종 수정 시간 : %s   |   조회 수 : %d \n", _Post[i].number, _Post[i].ID, timeDis, _Post[i].views);
			printf("----------------------------------------------------------------------------------------------------\n");
			printf(" 글 제목 : "); if (_Post[i].type == IS_NOTICE) printf("[공지]"); printf("%-s\n", _Post[i].titleText);
			printf("----------------------------------------------------------------------------------------------------\n");
			for (int j = 0; j < _Post[i].curLine; j++)
				printf(" %s\n", _Post[i].mainText[j]);
			printf("====================================================================================================\n");
			_Post[i].views++;
		}
	}

	_getch();
}
