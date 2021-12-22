// GDIEngine.cpp : 정적 라이브러리를 위한 함수를 정의합니다.
#include "GDIEngine.h"

/// <summary>
/// 게임 프로젝트에서 사용 될 Draw 함수
/// 
/// 2020. 12. 10 Hacgeum
/// </summary>

GDIEngine::GDIEngine()
{

}

GDIEngine::~GDIEngine()
{

}


void GDIEngine::Initialize(HWND hWnd)
{
	// MainProject의 hdc를 받아서 GDIEngine의 hdc에 저장한다
	mainhdc = GetDC(hWnd);

	// 백버퍼 초기화
	backbuffer = (CreateCompatibleDC(mainhdc));
	backbufferbitmap = CreateCompatibleBitmap(mainhdc, 800, 800);
	SelectObject(GetBackbuffer(), backbufferbitmap);
}

// 사각형 그리는 함수
void GDIEngine::DrawRect(int x, int y, int x1, int y1)
{
	Rectangle(GetBackbuffer(), x, y, x1, y1);
}

// 선 그리는 함수
void GDIEngine::DrawLine(int x, int y, int x1, int y1)
{
	HPEN NewHpen;
	HPEN OldHpen;

	NewHpen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	OldHpen = (HPEN)::SelectObject(GetBackbuffer(), (HGDIOBJ)NewHpen);

	MoveToEx(GetBackbuffer(), x, y, NULL);
	LineTo(GetBackbuffer(), x1, y1);

	NewHpen = (HPEN)::SelectObject(GetBackbuffer(), OldHpen);
	DeleteObject(NewHpen);
}

// 원 그리는 함수
void GDIEngine::DrawElli(int x, int y)
{
	HBRUSH NewHbrush;
	HBRUSH OldHbrush;

	NewHbrush = CreateSolidBrush(RGB(255, 255, 255));
	OldHbrush = (HBRUSH)SelectObject(GetBackbuffer(), NewHbrush);

	Ellipse(GetBackbuffer(), x, y, x + 40, y + 40);

	SelectObject(GetBackbuffer(), OldHbrush);
	DeleteObject(NewHbrush);
}
// 원 그리는 함수
void GDIEngine::DrawElliBlack(int x, int y)
{
	HBRUSH NewHbrush;
	HBRUSH OldHbrush;

	NewHbrush = CreateSolidBrush(RGB(0, 0, 0));
	OldHbrush = (HBRUSH)SelectObject(GetBackbuffer(), NewHbrush);

	Ellipse(GetBackbuffer(), x, y, x + 40, y + 40);

	SelectObject(GetBackbuffer(), OldHbrush);
	DeleteObject(NewHbrush);
}

// 백버퍼
void GDIEngine::Render()
{
	BitBlt(mainhdc, 0, 0, 800, 800, GetBackbuffer(), 0, 0, SRCCOPY);
}

void GDIEngine::RenderStart()
{
	Rectangle(GetBackbuffer(), 0, 0, 800, 800);
}