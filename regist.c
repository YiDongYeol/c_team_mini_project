#include "head.h"
#include "board.h"

void postRegist(Post *_Post) {
	int cur_x = TITLE_START_X, cur_y = TITLE_START_Y;
	if (postCount == POST_MAX) {
		printf("�ִ� �� ������ �ѽ��ϴ�.\n");
		return;
	}
	postInitializing(&(_Post[postCount]));
	_Post[postCount].curLine = 1;
	while (1) {
		system("cls");
		printf(" �� �ۼ� \n");
		printf("==========================================================\n");
		printf(" ���� : %s\n",_Post[postCount].titleText);
		printf("==========================================================\n");
		for (int i = 0; i < _Post[postCount].curLine; i++)
			printf("%02d %s\n", i + 1, _Post[postCount].mainText[i]);
		printf("\nF1 - ����  esc - ������");
		gotoxy(cur_x, cur_y);
		switch (input(&(_Post[postCount]), &cur_x, &cur_y)) {
		case 1:
			_Post[postCount].number = lastPostNumber++;
			currentTime(_Post[postCount].time);
			postCount++;
			return;
		case 2:
			postInitializing(&(_Post[postCount]));
			return;
		}
	}
}