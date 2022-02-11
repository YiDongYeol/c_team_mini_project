#include "head.h"
#include "board.h"

void postEdit(Post* _Post) {
	int cur_x, cur_y, select;
	char timeDis[15];
	Post backup;
	Post* cur=_Post;
	printf(" 글번호                                  제목                                시간         조회수\n");
	printf("===================================================================================================\n");
	for (int i = 0; i < postCount; i++) {
		if (cur->type == IS_BLIND || strcmp(cur->ID, currentUser)) {
			cur = cur->nextPostAddress;
			continue;
		}
		timeDisplay(cur->time, timeDis);
		printf(" %d    %-40s%35s%9d\n", cur->number, cur->titleText, timeDis, cur->views);
		cur = cur->nextPostAddress;
	}
	printf("===================================================================================================\n");
	printf("수정할 글 번호를 선택하여 주세요.\n");
	printf(">>");
	scanf("%d", &select);

	system("cls");
	cur = _Post;
	for (int i = 0; i < postCount; i++) {
		if (cur->number == select)
			break;
		cur = cur->nextPostAddress;
	}
	memcpy(&backup, cur, sizeof(Post));
	cur_y = cur->curLine - 1 + MAIN_START_Y;
	cur_x = strlen(cur->mainText[cur_y - MAIN_START_Y]) + MAIN_START_X;
	while (1) {
		system("cls");
		printf(" 글 수정 \n");
		printf("==========================================================\n");
		printf(" 제목 : %s\n", cur->titleText);
		printf("==========================================================\n");
		for (int i = 0; i < cur->curLine; i++)
			printf("%02d %s\n", i + 1, cur->mainText[i]);
		printf("\nF1 - 저장  esc - 나가기");
		gotoxy(cur_x, cur_y);
		switch (input(cur, &cur_x, &cur_y)) {
		case 1:
			currentTime(cur->time);
			return;
		case 2:
			memcpy(cur, &backup, sizeof(Post));
			return;
		}
	}
}