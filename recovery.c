#include "head.h"

void postRecovery(Post* _Post) {
	char timeDis[15];
	int select;
	printf(" 글번호                                  제목                                시간         조회수\n");
	printf("===================================================================================================\n");
	for (int i = 0; i < postCount; i++) {
		if (_Post[i].blind == 0)
			continue;
		timeDisplay(_Post[i].time, timeDis);
		printf(" %d    %-40s%35s%9d\n", _Post[i].number, _Post[i].titleText, timeDis, _Post[i].views);
	}
	printf("===================================================================================================\n");
	printf("복구할 글 번호를 선택하여 주세요.\n");
	printf(">>");
	scanf("%d", &select);
	for (int i = 0; i < postCount; i++) {
		if (_Post[i].number == select) {
			_Post[i].blind = 0;

			break;
		}
	}
}