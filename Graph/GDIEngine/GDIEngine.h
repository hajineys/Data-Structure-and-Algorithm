#pragma once

#include <windows.h>

class GDIEngine
{
public:
	GDIEngine();
	~GDIEngine();

protected:
	HDC mainhdc;
	HDC backbuffer;
	
	HBITMAP backbufferbitmap;

public:
	HDC GetBackbuffer() const { return backbuffer; }

	void Initialize(HWND hWnd);

	void DrawRect(int x, int y, int x1, int y1);
	void DrawLine(int x, int y, int x1, int y1);
	void DrawElli(int x, int y);
	void DrawElliBlack(int x, int y);

	void Render();
	void RenderStart();
};