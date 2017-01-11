#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256
#define PI 3.14159265358979323846
#define SIN(angle)  sin(PI * angle / 180)

int MathExample();
char** NewArray();
void FreeArray(unsigned char**);
void WritePicture(unsigned char**, char *, char *);

void main(){
	MathExample();

	system("pause");
}

int MathExample() {
	unsigned char **picture_array = NULL;
	int i, j;
	double angle;

	picture_array = NewArray();

	for (i = 0; i < HEIGHT; i++)
		for (j = 0; j < WIDTH; j++)
			picture_array[i][j] = i;
	WritePicture(picture_array, "수학이 없으면.raw", "wb");
	
	angle = 90;
	for (i = 0; i < HEIGHT; i++)
		for (j = 0; j < WIDTH; j++)
			picture_array[i][j] = (int)(SIN(i * (angle / 255)) * 255);
	WritePicture(picture_array, "하지만 삼각함수를 쓴다면 어떨까1.raw", "wb");

	for (i = 0; i < HEIGHT; i++)
		for (j = 0; j < WIDTH; j++)
			picture_array[i][j] = (int)((1 - SIN((255 - i) * (angle / 255))) * 255);
	
	WritePicture(picture_array, "하지만 삼각함수를 쓴다면 어떨까2.raw", "wb");

	FreeArray(picture_array);

	return 0;
}

char** NewArray() {
	unsigned char** array;
	int i;

	array = (unsigned char**)malloc(sizeof(unsigned char*) * HEIGHT);

	for (i = 0; i < HEIGHT; i++)
		array[i] = (unsigned char*)malloc(sizeof(unsigned char*) * WIDTH);

	return array;
}

void FreeArray(unsigned char** _array) {
	int i;

	for (i = 0; i < HEIGHT; i++)
		free(_array[i]);
	free(_array);
}

void WritePicture(unsigned char **_output_space, char *_file_name, char *_type) {
	FILE *output_file;
	int i, j;

	output_file = fopen(_file_name, _type);

	for (i = 0; i < HEIGHT; i++)
		for (j = 0; j < WIDTH; j++)
			fprintf(output_file, "%c", _output_space[(HEIGHT - 1) - i][j]);
	fclose(output_file);
}
