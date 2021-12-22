#include <iostream>

/// GDIEngine의 lib파일을 꼭 추가!
#pragma comment(lib, "GDIEngine.lib")
#include "framework.h"

#include "GameDefine.h"
#include "GDIEngine.h"
#include "GameManager.h"
#include "GameApp_Go.h"
#include "Board.h"
#include "Player.h"
#include "GameUI.h"

using namespace std;

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

HDC m_HDC;										// 핸들은 포인터다.
HWND g_hWnd;

//////////////////////////////////////////
/// 전역 클래스 변수 선언
GDIEngine* g_pGDIEngine;
GameManager* g_pGameManager;
//////////////////////////////////////////

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 여기에 코드를 입력합니다.

	// 전역 문자열을 초기화합니다.
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_GAMEAPPGO, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 애플리케이션 초기화를 수행합니다:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	// 전역 클래스 메모리 할당
	g_pGDIEngine = new GDIEngine;
	g_pGDIEngine->Initialize(g_hWnd);

	g_pGameManager = new GameManager(g_pGDIEngine);

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GAMEAPPGO));

	MSG msg;

	// 기본 메시지 루프입니다:
	while (true)
	{
		//while (GetMessage(&msg, nullptr, 0, 0))
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
			{
				break;
			}
		}
		else
		{
			// 1. 입력을 받는다
			// KeyInput / MouseInput();

			// 2. 연산을 한다(물리엔진, 충돌체크)
			// Update();
			g_pGameManager->CheckImDead(StoneType::STONE_WHITE);
			g_pGameManager->CheckImDead(StoneType::STONE_BLACK);

			// 3-0. 그리기 시작 전 백버퍼를 지운다
			g_pGDIEngine->RenderStart();

			// 3. Draw를 시작한다
			g_pGameManager->DrawAll();

			// 3-1. 주인공을 그린다
			// pPlayer->Draw();

			// 4. 백버퍼를 화면에 그린다
			g_pGDIEngine->Render();
		}
	}

	return (int)msg.wParam;
}


//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GAMEAPPGO));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_GAMEAPPGO);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}


//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석: 이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		100, 100, 900, 900, nullptr, nullptr, hInstance, nullptr);

	// 전역 hWnd에 지역 hWnd를 대입
	g_hWnd = hWnd;

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}


//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_COMMAND:
		{
			int wmId = LOWORD(wParam);
			// 메뉴 선택을 구문 분석합니다:
			switch (wmId)
			{
				case IDM_ABOUT:
					DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
					break;

				case IDM_EXIT:
					DestroyWindow(hWnd);
					break;

				default:
					return DefWindowProc(hWnd, message, wParam, lParam);
			}
		}
		break;

		case WM_MOUSEMOVE:
			g_pGameManager->SetPlayersMousePos(LOWORD(lParam), HIWORD(lParam));
			//g_pPlayer->CurrMousePos.x = LOWORD(lParam);
			//g_pPlayer->CurrMousePos.y = HIWORD(lParam);
			break;

		case WM_LBUTTONUP:
			g_pGameManager->PickTileChangeStoneType();
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
		case WM_INITDIALOG:
			return (INT_PTR)TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
			{
				EndDialog(hDlg, LOWORD(wParam));
				return (INT_PTR)TRUE;
			}
			break;
	}

	return (INT_PTR)FALSE;
}