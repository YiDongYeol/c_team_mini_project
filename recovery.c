#include "head.h"

void postRecovery(Post* _Post) {
	Post* cur=_Post;
	char timeDis[15];
	int select;
	printf(" 글번호                                  제목                                시간         조회수\n");
	printf("===================================================================================================\n");
	for (int i = 0; i < postCount; i++) {
		if (cur->type == IS_BLIND) {
			timeDisplay(cur->time, timeDis);
			printf(" %d    %-40s%35s%9d\n", cur->number, cur->titleText, timeDis, cur->views);
		}
		cur = cur->nextPostAddress;
	}
	printf("===================================================================================================\n");
	printf("복구할 글 번호를 선택하여 주세요.\n");
	printf(">>");
	scanf("%d", &select);
	cur = _Post;
	for (int i = 0; i < postCount; i++) {
		if (cur->number == select) {
			cur->type = IS_NORMAL;

			break;
		}
		cur = cur->nextPostAddress;
	}
}