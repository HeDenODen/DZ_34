#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#define MAX_SIZE 128

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const char* path = "Text2.txt";
	const char* path2 = "NewText2.txt";
	FILE* myFile, * myNewFile;

	char line[MAX_SIZE];
	bool error = false;
	int c = 0, c1 = 0;

	if (fopen_s(&myFile, path, "r") != NULL)
		cout << "The file cannot be opened";
	else if (fopen_s(&myNewFile, path2, "w") != NULL)
		cout << "The file cannot be opened";
	else {
		while (!error) {
			if (fgets(line, sizeof(line), myFile) != NULL) {
				c++;
				if(c % 2 != 0)
					fputs(line, myNewFile);
			}
			else {
				error = true;
			}
		}
		if (fclose(myFile) == EOF)
			cout << "\nThis 1 file could not be closed!" << endl;
		else
			cout << "\nThis 1 file is closed!" << endl;
		if (fclose(myNewFile) == EOF)
			cout << "\nThis 2 file could not be closed!" << endl;
		else
			cout << "\nThis 2 file is closed!" << endl;
	}

	return 0;
}