#include "head.h"
#include "board.h"

void postRegist(Post* _Post) {
	int cur_x = TITLE_START_X, cur_y = TITLE_START_Y;
	Post* newPost;
	Post* cur=_Post;
	while (cur->nextPostAddress != 0)
		cur = cur->nextPostAddress;
	if (postCount == POST_MAX) {
		printf("최대 글 개수를 초과합니다.\n");
		system("pause");
		return;
	}
	newPost = (Post*)malloc(sizeof(Post));
	postInitializing(newPost);
	newPost->curLine = 1;
	while (1) {
		system("cls");
		printf(" 글 작성 \n");
		printf("==========================================================\n");
		printf(" 제목 : %s\n", newPost->titleText);
		printf("==========================================================\n");
		for (int i = 0; i < newPost->curLine; i++)
			printf("%02d %s\n", i + 1, newPost->mainText[i]);
		printf("\nF1 - 저장  esc - 나가기");
		gotoxy(cur_x, cur_y);
		switch (input(newPost, &cur_x, &cur_y)) {
		case 1:
			newPost->number = lastPostNumber++;
			strcpy(newPost->ID, currentUser);
			currentTime(newPost->time);
			if (currentUserType == IS_ADMIN) {
				system("cls");
				printf("공지로 등록합니까? (Y/N)");
				while (1) {
					int flag = 0;
					switch (_getch()) {
					case 'y':
						newPost->type = IS_NOTICE;
						flag = 1;
						break;
					case 'n':
						newPost->type = IS_NORMAL;
						flag = 1;
						break;
					}
					if (flag) break;
				}
			}
			postCount++;
			cur->nextPostAddress = newPost;
			return;
		case 2:
			free(newPost);
			return;
		}
	}
}