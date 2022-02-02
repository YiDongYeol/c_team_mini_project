#include "head.h"
#include "board.h"


int input(Post* _Post, int* cur_x, int* cur_y) {
	int c, i = 0, j = 0;
	c = _getch();
	switch (c) {
	case 27:      //esc
		return 2;
	case 8:        //bs
		if (*cur_y == TITLE_START_Y) {			//제목일때
			if ((*cur_x) == TITLE_START_X && _Post->titleText[0] == '\0')
				break;
			moveCursor(_Post, 'l', cur_x, cur_y);
			deleteChar(_Post->titleText, (*cur_x) - TITLE_START_X);
		}
		else if (*cur_y > MAIN_START_Y - 1) {					//본문일때
			if (*cur_y == MAIN_START_Y && *cur_x == MAIN_START_X)
				break;
			if (*cur_x == MAIN_START_X) {
				(*cur_y)--;
				(*cur_x) = strlen(_Post->mainText[(*cur_y) - MAIN_START_Y]) + MAIN_START_X;
				strcat(_Post->mainText[(*cur_y) - MAIN_START_Y], _Post->mainText[(*cur_y) - MAIN_START_Y + 1]);
				deleteLine(_Post->mainText, (*cur_y) - MAIN_START_Y + 1, &(_Post->curLine));
				break;
			}
			moveCursor(_Post, 'l', cur_x, cur_y);
			deleteChar(_Post->mainText[(*cur_y) - MAIN_START_Y], (*cur_x) - MAIN_START_X);
		}
		break;
	case 224:
		c = _getch();
		switch (c) {
		case 72: //up
			moveCursor(_Post, 'u', cur_x, cur_y);
			break;
		case 80: //down
			moveCursor(_Post, 'd', cur_x, cur_y);
			break;
		case 75: //left
			moveCursor(_Post, 'l', cur_x, cur_y);
			break;
		case 77: //right
			moveCursor(_Post, 'r', cur_x, cur_y);
			break;
		case 71: //home
			(*cur_x) = MAIN_START_X;
			break;
		case 79: //end
			(*cur_x) = strlen(_Post->mainText[(*cur_y) - MAIN_START_Y]) + MAIN_START_X;
			break;
		case 73: //pageup
			if (*cur_y == TITLE_START_Y)
				break;
			(*cur_x) = MAIN_START_X;
			(*cur_y) = MAIN_START_Y;
			break;
		case 81: //pagedown
			if (*cur_y == TITLE_START_Y)
				break;
			(*cur_x) = strlen(_Post->mainText[_Post->curLine - 1]) + MAIN_START_X;
			(*cur_y) = _Post->curLine + MAIN_START_Y - 1;
			break;
		case 83: //delete
			if (*cur_y == TITLE_START_Y)
				deleteChar(_Post->titleText, (*cur_x) - TITLE_START_X);
			else {
				if (_Post->mainText[(*cur_y) - MAIN_START_Y][(*cur_x) - MAIN_START_X] == '\0') {
					if ((*cur_y) - MAIN_START_Y == _Post->curLine - 1)
						break;
					strcat(_Post->mainText[(*cur_y) - MAIN_START_Y], _Post->mainText[(*cur_y) - MAIN_START_Y + 1]);
					deleteLine(_Post->mainText, (*cur_y) - MAIN_START_Y + 1, &(_Post->curLine));
					break;
				}
				deleteChar(_Post->mainText[(*cur_y) - MAIN_START_Y], (*cur_x) - MAIN_START_X);
			}
		default:
			break;
		}
		break;
	case 13: //enter
		if ((*cur_y) == TITLE_START_Y || _Post->curLine == MAIN_LINE_MAX)
			break;
		insertLine(_Post->mainText, (*cur_y) - MAIN_START_Y + 1, &(_Post->curLine));
		if (_Post->mainText[(*cur_y) - MAIN_START_Y][(*cur_x) - MAIN_START_X] != '\0') {
			strncpy(_Post->mainText[(*cur_y) - MAIN_START_Y + 1], _Post->mainText[(*cur_y) - MAIN_START_Y] + (*cur_x) - MAIN_START_X, strlen(_Post->mainText[(*cur_y) - MAIN_START_Y]) - ((*cur_x) - MAIN_START_X) + 1);
			_Post->mainText[(*cur_y) - MAIN_START_Y][(*cur_x) - MAIN_START_X] = '\0';
		}
		(*cur_y)++;
		(*cur_x) = MAIN_START_X;
		break;
	case 0:
		switch (_getch()) {
		case 59:
			if (!(strcmp(_Post->titleText, "\0"))) {
				*cur_y = MAIN_START_Y + _Post->curLine + 3; *cur_x = 0;
				gotoxy(*cur_x, *cur_y);
				printf("[제목을 작성하여 주십시오.]\n");
				system("pause");
				*cur_y = TITLE_START_Y; *cur_x = TITLE_START_X;
				break;
			}
			if (_Post->curLine == 1 && _Post->mainText[0][0] == '\0') {
				*cur_y = MAIN_START_Y + _Post->curLine + 3; *cur_x = 0;
				gotoxy(*cur_x, *cur_y);
				printf("[내용을 작성하여 주십시오.]\n");
				system("pause");
				*cur_y = MAIN_START_Y; *cur_x = MAIN_START_X;
				break;
			}
			return 1;
		default:
			break;
		}
		break;
	default:
		if ((*cur_y) == TITLE_START_Y) {
			if (strlen(_Post->titleText) > TITLE_TEXT_MAX - 2)
				break;
			insertChar(_Post->titleText, c, (*cur_x) - TITLE_START_X);
			(*cur_x)++;
			if (c & 0x80) {
				if (_kbhit()) {
					c = _getch();
					insertChar(_Post->titleText, c, (*cur_x) - TITLE_START_X);
					(*cur_x)++;
				}
			}
		}
		else {
			if (strlen(_Post->mainText[(*cur_y) - MAIN_START_Y]) > MAIN_TEXT_MAX - 2)
				break;
			insertChar(_Post->mainText[(*cur_y) - MAIN_START_Y], c, (*cur_x) - MAIN_START_X);
			(*cur_x)++;
			if (c & 0x80) {
				if (_kbhit()) {
					c = _getch();
					insertChar(_Post->mainText[(*cur_y) - MAIN_START_Y], c, (*cur_x) - MAIN_START_X);
					(*cur_x)++;
				}
			}
		}
		break;
	}

	return 0;
}
void insertChar(char* string, char c, int index) {
	for (int i = strlen(string) + 1; i > index; i--)
		string[i] = string[i - 1];
	string[index] = c;
}
void insertLine(char mainText[][MAIN_TEXT_MAX + 1], int index, int* curLine) {
	for (int i = *curLine; i > index; i--)
		strcpy(mainText[i], mainText[i - 1]);
	strcpy(mainText[index], "\0");
	(*curLine)++;
}
void deleteChar(char* string, int index) {
	if (string[index] & 0x80) {
		while (string[index] != '\0') {
			string[index] = string[index + 2];
			string[index + 1] = string[index + 3];
			index++;
		}
	}
	else {
		while (string[index] != '\0') {
			string[index] = string[index + 1];
			index++;
		}
	}
}
void deleteLine(char mainText[][MAIN_TEXT_MAX + 1], int index, int* curLine) {
	for (int i = index; i < *curLine; i++)
		strcpy(mainText[i], mainText[i + 1]);
	strcpy(mainText[--(*curLine)], "\0");
}
void moveCursor(Post* _Post, char direction, int* cur_x, int* cur_y) {
	int i = 0, j = 0, k = 0;
	switch (direction) {
	case 'u':
		if ((*cur_y) == TITLE_START_Y)
			break;
		if ((*cur_y) == MAIN_START_Y) {
			(*cur_y) = TITLE_START_Y;
			(*cur_x) = strlen(_Post->titleText) + TITLE_START_X;
			break;
		}
		(*cur_y)--;
		if ((*cur_x) - MAIN_START_X > strlen(_Post->mainText[(*cur_y) - MAIN_START_Y])) {
			(*cur_x) = strlen(_Post->mainText[(*cur_y) - MAIN_START_Y]) + MAIN_START_X;
			break;
		}
		while (i < (*cur_x) - MAIN_START_X) {
			if (_Post->mainText[(*cur_y) - MAIN_START_Y][i] & 0x80) {
				j = i; i += 2;
			}
			else {
				j = i; i += 1;
			}
		}
		if (i == (*cur_x) - MAIN_START_X)
			break;
		else
			(*cur_x) = j + MAIN_START_X;
		break;
	case 'd':
		if ((*cur_y) == TITLE_START_Y) {
			(*cur_y) = MAIN_START_Y;
			(*cur_x) = strlen(_Post->mainText[0]) + MAIN_START_X;
			break;
		}
		if ((*cur_y) - MAIN_START_Y + 1 == _Post->curLine)
			break;
		(*cur_y)++;
		if ((*cur_x) - MAIN_START_X > strlen(_Post->mainText[(*cur_y) - MAIN_START_Y])) {
			(*cur_x) = strlen(_Post->mainText[(*cur_y) - MAIN_START_Y]) + MAIN_START_X;
			break;
		}
		while (i < (*cur_x) - MAIN_START_X) {
			if (_Post->mainText[(*cur_y) - MAIN_START_Y][i] & 0x80) {
				j = i; i += 2;
			}
			else {
				j = i; i += 1;
			}
		}
		if (i == (*cur_x) - MAIN_START_X)
			break;
		else
			(*cur_x) = j + MAIN_START_X;
		break;
	case 'l':
		if ((*cur_y) > MAIN_START_Y && (*cur_x) == MAIN_START_X) {
			(*cur_y)--;
			(*cur_x) = strlen(_Post->mainText[(*cur_y) - MAIN_START_Y]) + MAIN_START_X;
			break;
		}
		if (*cur_y > MAIN_START_Y - 1)
			k = (*cur_x) - MAIN_START_X;
		else
			k = (*cur_x) - TITLE_START_X;
		while (i < k) {
			if (*cur_y == TITLE_START_Y) {
				if (_Post->titleText[i] & 0x80) {
					j = 2;	i += j;
				}
				else {
					j = 1; i += j;
				}
			}
			else {
				if (_Post->mainText[(*cur_y) - MAIN_START_Y][i] & 0x80) {
					j = 2;	i += j;
				}
				else {
					j = 1; i += j;
				}
			}
		}
		i -= j;
		*cur_x = i + (*cur_y == TITLE_START_Y ? TITLE_START_X : MAIN_START_X);
		break;
	case 'r':
		if ((*cur_y) == TITLE_START_Y) {
			if (_Post->titleText[(*cur_x) - TITLE_START_X] == '\0')
				break;
			if (_Post->titleText[(*cur_x) - TITLE_START_X] & 0x80)
				(*cur_x) += 2;
			else
				(*cur_x)++;
		}
		else {
			if (_Post->mainText[(*cur_y) - MAIN_START_Y][(*cur_x) - MAIN_START_X] & 0x80) {
				(*cur_x) += 2;
			}
			else if (_Post->mainText[(*cur_y) - MAIN_START_Y][(*cur_x) - MAIN_START_X] == '\0') {
				if ((*cur_y) - MAIN_START_Y == _Post->curLine - 1)
					break;
				(*cur_y)++;
				(*cur_x) = MAIN_START_X;
			}
			else {
				(*cur_x)++;
			}
		}
		break;
	}
}
void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}