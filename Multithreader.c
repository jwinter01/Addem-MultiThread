#include "stdafx.h"
#include "tchar.h"
#include <stdio.h>
#include <process.h>
#include <windows.h>

/*

This code will run 2 threads (main and _beginthread)
which will sum the increments until count of 1000 is reached.
I slowed down the function addem to a quarter of a second
so you can see the process unfold.

*/

void addem(void*); //declare void pointer
int _tmain(int argc, _TCHAR* argv[])
{
	int count = 1000;
	//int *countp = &count;
	//countp = &count;

	_beginthread(addem, 0, &count);
	//_beginthread(addem, 0, &count);
	//_beginthread(addem, 0, (void *) countp); // _beginthread(function, stack_value, arguments)
	addem(&count);
	return 0;
}
//void addem(void* count)
void addem(void* count)
{
	//printf("IN ADDEM");
	//printf("count = %d\n", count);
	int sum = 0;
	for (int i = 1; i <= *(int*)count; i++) // int pointer to count (it works for some reason)
	{
		printf("The value of i is %d\n", i);
		sum += i;

		int x, y;
		Sleep(250);
		for (x = 0; x < 800; x++)
		{
			y = x;
		}
	}
	printf("The sum is %d\n", sum);
	getch(); // Press Enter to quit
	return;
}​; // A semicolon was needed here to run