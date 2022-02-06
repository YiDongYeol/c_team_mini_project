#include "head.h"
#include "board.h"

void postEdit(Post* _Post) {
	int cur_x, cur_y, select, index;
	char timeDis[15];
	Post backup;
	printf(" 글번호                                  제목                                시간         조회수\n");
	printf("===================================================================================================\n");
	for (int i = 0; i < postCount; i++) {
		if (_Post[i].type == IS_BLIND || strcmp(_Post[i].ID, currentUser))
			continue;
		timeDisplay(_Post[i].time, timeDis);
		printf(" %d    %-40s%35s%9d\n", _Post[i].number, _Post[i].titleText, timeDis, _Post[i].views);
	}
	printf("===================================================================================================\n");
	printf("수정할 글 번호를 선택하여 주세요.\n");
	printf(">>");
	scanf("%d", &select);

	system("cls");

	for (int i = 0; i < postCount; i++) {
		if (_Post[i].number == select) {
			index = i; break;
		}
	}
	memcpy(&backup, &(_Post[index]), sizeof(Post));
	cur_y = _Post[index].curLine - 1 + MAIN_START_Y;
	cur_x = strlen(_Post[index].mainText[cur_y - MAIN_START_Y]) + MAIN_START_X;
	while (1) {
		system("cls");
		printf(" 글 수정 \n");
		printf("==========================================================\n");
		printf(" 제목 : %s\n", _Post[index].titleText);
		printf("==========================================================\n");
		for (int i = 0; i < _Post[index].curLine; i++)
			printf("%02d %s\n", i + 1, _Post[index].mainText[i]);
		printf("\nF1 - 저장  esc - 나가기");
		gotoxy(cur_x, cur_y);
		switch (input(&_Post[index], &cur_x, &cur_y)) {
		case 1:
			currentTime(_Post[index].time);
			return;
		case 2:
			memcpy(&(_Post[index]), &backup, sizeof(Post));
			return;
		}
	}
}