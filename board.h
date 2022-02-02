#define TITLE_START_X 8
#define TITLE_START_Y 2
#define MAIN_START_X 3
#define MAIN_START_Y 4

int input(Post* _Post, int* cur_x, int* cur_y);
void insertChar(char* string, char c, int index);
void insertLine(char mainText[][MAIN_TEXT_MAX + 1], int index, int* curLine);
void deleteChar(char* string, int index);
void deleteLine(char mainText[][MAIN_TEXT_MAX + 1], int index, int* curLine);
void moveCursor(Post* _Post, char direction, int* cur_x, int* cur_y);
void gotoxy(int x, int y);