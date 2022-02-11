#include "head.h"
#include "board.h"

void postRegist(Post *_Post) {
	int cur_x = TITLE_START_X, cur_y = TITLE_START_Y;
	if (postCount == POST_MAX) {
		printf("�ִ� �� ������ �ѽ��ϴ�.\n");
		system("pause");
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
			strcpy(_Post[postCount].ID, currentUser);
			currentTime(_Post[postCount].time);
			if (currentUserType == IS_ADMIN) {
				system("cls");
				printf("������ ����մϱ�? (Y/N)");
				while (1) {
					int flag = 0;
					switch (_getch()) {
					case 'y':
						_Post[postCount].type = IS_NOTICE;
						flag = 1;
						break;
					case 'n':
						_Post[postCount].type = IS_NORMAL;
						flag = 1;
						break;
					}
					if (flag) break;
				}
			}
			postCount++;
			return;
		case 2:
			postInitializing(&(_Post[postCount]));
			return;
		}
	}
}