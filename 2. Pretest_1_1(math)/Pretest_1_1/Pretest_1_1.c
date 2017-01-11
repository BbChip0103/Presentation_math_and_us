#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define COS(angle) cos(PI * angle / 180)
#define SIN(angle) sin(PI * angle / 180)
#define VERTICAL_SCALE 2	// 콘솔창에서 가로세로 크기가 달라서, 2로 하면 세로크기를 1/2로 줄여줌

int Pretest1_2();
int GetArraySize();
void ResizeWindow(int _array_size);
char** NewArray(int _array_size);
void FreeArray(char ** _spiral_array, int _array_size);
void InitializeArray(char ** _spiral_array, int _array_size);
void MakeSpiral(char ** _spiral_array, int _array_size);
void PrintSpiral(char ** _spiral_array, int _array_size);

void main() {

	Pretest1_2();

}

int Pretest1_2() {
	char ** spiral_array;
	int array_size;

	array_size = GetArraySize();

	ResizeWindow(array_size);

	spiral_array = NewArray(array_size);

	InitializeArray(spiral_array, array_size);

	MakeSpiral(spiral_array, array_size);

	PrintSpiral(spiral_array, array_size);

	FreeArray(spiral_array, array_size);

	return 0;
}

int GetArraySize() {
	int array_size;

	while (1) {
		printf("배열의 크기를 입력해주세요 : ");
		scanf("%d", &array_size);
		while (getchar() != '\n');	//	flush input buffer

		if (array_size < 1)	printf("1 이상의 자연수만 입력해주세요.\n\n");
		else break;
	}
	
	return array_size;
}

void ResizeWindow(int _array_size) {
	char temp[40];

	if (_array_size < 14) {	// 이거 이하로는 콘솔창이 안 줄어들던;;
		system("mode con:cols=15 lines=14");
		
		return;
	}

	sprintf(temp, "mode con:cols=%d lines=%d", 
		    _array_size + 1, (_array_size / VERTICAL_SCALE));	// 반올림 때문에 X 사이즈 +1 해줌
	system(temp);
}

char** NewArray(int _array_size) {
	unsigned char** array;
	int i;

	array = (char **)malloc(sizeof(char*) * _array_size / VERTICAL_SCALE);

	for (i = 0; i < (_array_size / VERTICAL_SCALE); i++)
		array[i] = (char*)malloc(sizeof(char*) * _array_size);

	return array;
}

void FreeArray(char ** _array, int _array_size) {
	int i;

	for (i = 0; i < (_array_size / VERTICAL_SCALE); i++)
		free(_array[i]);
	free(_array);
}

void InitializeArray(char ** _spiral_array, int _array_size) {
	int i, j;

	for (i = 0; i < _array_size / VERTICAL_SCALE; i++)
		for (j = 0; j < _array_size ; j++)
			_spiral_array[i][j] = ' ';
}

void MakeSpiral(char ** _spiral_array, int _array_size) {

	double rotation_count;
	int radius, angle;
	int x, y;
	int i;

	radius = _array_size / 2;	// 반지름 계산
	rotation_count = radius / 5;	// 몇 바퀴 돌릴지 계산, 뒤에 나누는 숫자는 선과 선 사이의 간격
	angle = 360 * rotation_count;	// 각도 계산

	// 반올림 할 경우가 중앙의 디테일이 좀 더 살음 +0.5하고 내림하는식으로 구현
	for (i = 0; i < angle; i++) {
		x = (int)floor((COS(i) * radius * i / angle) + (radius - 1) + 0.5);
		y = (int)floor(((SIN(i) * radius * i / angle) + radius + 1) / VERTICAL_SCALE + 0.5);

		//요게 반올림 안한거
		//x = (int)(COS(i) * radius * i / angle) + (radius - 1);
		//y = (int)(((SIN(i) * radius * i / angle) + radius + 1) / VERTICAL_SCALE);

		_spiral_array[y][x] = '*';
	}
}

void PrintSpiral(char ** _spiral_array, int _array_size) {
	int i, j;

	for (i = 0; i < _array_size / VERTICAL_SCALE; i++) {
		for (j = 0; j < _array_size; j++) {
			printf("%c", _spiral_array[i][j]);
		}
		printf("\n");
	}
}