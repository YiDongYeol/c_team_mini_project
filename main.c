#include "head.h"

void main() {
	Post _Post[POST_MAX];
	sample(_Post);
	while (1) {
		
		
		system("cls");
		switch (menu()) {
		case 1:
			postRegist(_Post);
			break;
		case 2:
			postEdit(_Post);
			break;
		case 3:
			postView(_Post);
			break;
		case 4:
			postDelete(_Post);
			break;
		case 5:
			//º¹±¸
			break;
		case 6:
			return;
		}
	}
}
