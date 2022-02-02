#include "head.h"

void postView(Post *_Post) {
	int select;
	int sortRank[POST_MAX];
	char timeDis[15];

	for (int i = 0; i < postCount; i++)
		sortRank[i] = 1;

	printf(" 글번호                                  제목                                시간         조회수\n");
	printf("===================================================================================================\n");
	for (int i = 0; i < postCount; i++) {
		if (_Post[i].blind == 1)
			continue;
		timeDisplay(_Post[i].time, timeDis);
		printf(" %d    %-40s%35s%9d\n", _Post[i].number, _Post[i].titleText, timeDis, _Post[i].views);
	}
	printf("===================================================================================================\n");
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

	system("cls");

	printf(" 글번호                                  제목                                시간         조회수\n");
	printf("===================================================================================================\n");
	for (int i = 1; i < postCount + 1; i++) {
		for (int j = 0; j < postCount; j++) {
			if ((i == sortRank[j]) && _Post[j].blind != 1) {
				timeDisplay(_Post[j].time, timeDis);
				printf(" %d    %-40s%35s%9d\n", _Post[j].number, _Post[j].titleText, timeDis, _Post[j].views);
			}
		}
	}
	printf("===================================================================================================\n");
	printf("조회할 글 번호를 선택하여 주세요.\n");
	printf(">>");
	scanf("%d", &select);

	system("cls");

	for (int i = 0; i < postCount; i++) {
		if (_Post[i].number == select)
		{
			timeDisplay(_Post[i].time, timeDis);
			printf("===============================================================================\n");
			printf(" 글 번호 : %d    |   최종 수정 시간 : %s    |   조회 수 : %d \n", _Post[i].number, timeDis, _Post[i].views);
			printf("-------------------------------------------------------------------------------\n");
			printf(" 글 제목 : %-s\n", _Post[i].titleText);
			printf("-------------------------------------------------------------------------------\n");
			for (int j = 0; j < _Post[i].curLine; j++)
				printf(" %s\n", _Post[i].mainText[j]);
			printf("===============================================================================\n");
			_Post[i].views++;
		}
	}

	_getch();
}
