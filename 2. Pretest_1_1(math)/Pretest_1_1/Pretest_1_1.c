#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define COS(angle) cos(PI * angle / 180)
#define SIN(angle) sin(PI * angle / 180)
#define VERTICAL_SCALE 2	// �ܼ�â���� ���μ��� ũ�Ⱑ �޶�, 2�� �ϸ� ����ũ�⸦ 1/2�� �ٿ���

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
		printf("�迭�� ũ�⸦ �Է����ּ��� : ");
		scanf("%d", &array_size);
		while (getchar() != '\n');	//	flush input buffer

		if (array_size < 1)	printf("1 �̻��� �ڿ����� �Է����ּ���.\n\n");
		else break;
	}
	
	return array_size;
}

void ResizeWindow(int _array_size) {
	char temp[40];

	if (_array_size < 14) {	// �̰� ���Ϸδ� �ܼ�â�� �� �پ���;;
		system("mode con:cols=15 lines=14");
		
		return;
	}

	sprintf(temp, "mode con:cols=%d lines=%d", 
		    _array_size + 1, (_array_size / VERTICAL_SCALE));	// �ݿø� ������ X ������ +1 ����
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

	radius = _array_size / 2;	// ������ ���
	rotation_count = radius / 5;	// �� ���� ������ ���, �ڿ� ������ ���ڴ� ���� �� ������ ����
	angle = 360 * rotation_count;	// ���� ���

	// �ݿø� �� ��찡 �߾��� �������� �� �� ���� +0.5�ϰ� �����ϴ½����� ����
	for (i = 0; i < angle; i++) {
		x = (int)floor((COS(i) * radius * i / angle) + (radius - 1) + 0.5);
		y = (int)floor(((SIN(i) * radius * i / angle) + radius + 1) / VERTICAL_SCALE + 0.5);

		//��� �ݿø� ���Ѱ�
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