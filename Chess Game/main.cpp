/// "main.cpp"
/// ----------
/// Entrance to the program
/// Created: Oct. 8, 2020
/// Edited:  Oct. 8, 2020

#include <Windows.h>
#include <cstdio>

#include "ChessGameManager.h"

// Internal globals for timing
double gPCFrequency = 0.0;
__int64 gCounterStart = 0;
double gLastFrame;

// Game manager - controls game stuff
ChessGameManager gameManager;



/// <summary>
/// Initializes the counter at startup
/// </summary>
void StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
	{
		printf("Failed to init performance counters.");
	}
	gPCFrequency = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	gCounterStart = li.QuadPart;
}

/// <summary>
/// Returns the time since the start of the program
/// </summary>
double GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return (double(li.QuadPart - gCounterStart) / gPCFrequency);
}

/// <summary>
/// Initializes OpenGL Graphics
/// </summary>
void InitGL()
{
	StartCounter();
	gLastFrame = GetCounter();
	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


/// <summary>
/// OpenGL calls this.
/// </summary>
void Display() 
{
	//glClear(GL_COLOR_BUFFER_BIT);
	gameManager.Render();
	//glFlush();
}


/// <summary>
/// OpenGL calls this...
/// </summary>
void Idle()
{
	static double prevTime = GetCounter();
	double tick = GetCounter() - prevTime;
	double currentTime = GetCounter();
	double deltaTime = currentTime - gLastFrame;

	gameManager.Update((float)deltaTime);
}
