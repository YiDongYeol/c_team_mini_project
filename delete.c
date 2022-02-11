#include "head.h"


void postDelete(Post* _Post)
{
	int del_selc, del_how = 1;
	int j = 0;
	char timeDis[15];
	printf(" 글번호                                  제목                                시간         조회수\n");
	printf("===================================================================================================\n");
	for (int i = 0; i < postCount; i++) {
		if (currentUserType == IS_USER) {
			if (_Post[i].type == IS_BLIND || strcmp(_Post[i].ID, currentUser))
				continue;
		}
		else {
			if (_Post[i].type == IS_BLIND)
				continue;
		}
		timeDisplay(_Post[i].time, timeDis);
		printf(" %d    %-40s%35s%9d\n", _Post[i].number, _Post[i].titleText, timeDis, _Post[i].views);
	}
	printf("===================================================================================================\n");

	printf("삭제할 게시판의 번호>>");
	scanf("%d", &del_selc);
	printf("\n");
	if (currentUserType == IS_ADMIN) {
		printf("블라인드를 하시겠습니까?\n");
		printf("1.Y 2.N\n");
		printf(">>");
		scanf("%d", &del_how);
	}

	switch (del_how) {
	case 1:

		for (int i = 0; i < postCount; i++) {
			if (_Post[i].number == del_selc) {
				_Post[i].type = IS_BLIND;

				break;
			}
		}

		break;
		
	case 2:

		for (int i = 0; i < postCount; i++) {
			if (_Post[i].number == del_selc) {
				for (int j = i; j < postCount - 1; j++) {
					strcpy(_Post[j].titleText, _Post[j + 1].titleText);
					strcpy(_Post[j].time, _Post[j + 1].time);
					strcpy(_Post[j].ID, _Post[j + 1].ID);
					for (int k = 0; k < MAIN_LINE_MAX; k++)
						strcpy(_Post[j].mainText[k], _Post[j+1].mainText[k]);
					_Post[j].number = _Post[j + 1].number;
					_Post[j].views = _Post[j + 1].views;
					_Post[j].type = _Post[j + 1].type;
					_Post[j].curLine = _Post[j + 1].curLine;
				}
				postCount--;
				postInitializing(&(_Post[postCount]));

				break;
			}
		}
		
		break;
	}

}