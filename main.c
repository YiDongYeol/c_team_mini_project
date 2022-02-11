#include "head.h"

void main() {
	Post _Post[POST_MAX];
	User _User[USER_MAX];
	int loginSuccess = 0;
	int flag = 0;
	sample(_Post, _User);
	while (1) {
		while (1) {
			system("cls");
			switch (loginMenu()) {
			case 1:
				loginSuccess = login(_User);
				break;
			case 2:
				userRegist(_User);
				break;
			case 0:
				return;
			}
			if (loginSuccess)
				break;
		}
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
				if (currentUserType == IS_ADMIN)
					postRecovery(_Post);
				else
					flag = userEdit(_User);
				break;
			case 6:
				if (currentUserType == IS_ADMIN)
					userManage(_User);
				else
					flag = userBlind(_User);
				break;
			case 0:
				flag = 1;
				break;
			}
			if (flag)
				break;
		}
	}
}
