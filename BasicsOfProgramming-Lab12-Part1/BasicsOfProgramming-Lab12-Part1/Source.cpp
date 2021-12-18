#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#define TEXT_SIZE 256
struct Inscription
{
	wchar_t text[TEXT_SIZE];
	int x, y;
	char R, G, B;
	int fontSize;
};

int main()
{
	unsigned int figuresCount = 0;

	printf("Enter figures count:");
	scanf_s("%d", &figuresCount);

	Inscription* inscription = (Inscription*)malloc(sizeof(Inscription) * figuresCount);

	for (int i = 0; i < figuresCount; i++)
	{
		printf("\nENTERING PROPERTIES FOR FIGURE %d\n", i);
		
		printf("Enter text for inscription:");
		wscanf_s(L" %[^\t\n]s", inscription[i].text, TEXT_SIZE);
		
		printf("Enter inscription x position:");
		scanf_s("%d", &inscription[i].x);

		printf("Enter inscription y position:");
		scanf_s("%d", &inscription[i].y);

		printf("Enter inscription R color:");
		scanf_s("%d", &inscription[i].R);

		printf("Enter inscription G color:");
		scanf_s("%d", &inscription[i].G);

		printf("Enter inscription B color:");
		scanf_s("%d", &inscription[i].B);

		printf("Enter inscription font size:");
		scanf_s("%d", &inscription[i].fontSize);
	}

	FILE* filePointer = nullptr;
	fopen_s(&filePointer, "data.txt", "wb");
	fwrite(&figuresCount, sizeof(int), 1, filePointer);
	fwrite(inscription, sizeof(Inscription), figuresCount, filePointer);
	fclose(filePointer);
	fclose(filePointer);

}