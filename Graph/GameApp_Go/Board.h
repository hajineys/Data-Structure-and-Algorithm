#pragma once
#include "GDIEngine.h"
#include "GameDefine.h"
#include "Player.h"
#include "GameUI.h"
#include "Tile.h"

class Player;

/// <summary>
/// 게임판. 바둑의 논리적인 부분을 담당한다.
/// 게임 진행은 하지 않는다.
/// </summary>
class GoBoard
{
public:
	GoBoard();
	~GoBoard();

private:
	GDIEngine* m_GDIEngine;
	Player* m_Player;

	// 포인터 배열을 바둑판 갯수만큼 잡는다
	Tile* m_GoBoard[BOARD_Y][BOARD_X];

public:
	bool m_IsAlive;

	// 위치로부터 한번에 돌의 종류를 알아온다.
	StoneType GetStoneType(int x, int y) const;

	void Initialize(GDIEngine* pGDIEngine);

	// 스톤 값 초기화
	void InitBoard();

	void DrawBoard();
	void DrawBoardStoneType();
	
	// 플레이어가 클릭한 타일 스톤타입 값 변경
	void PickTileChangeStoneType(Player* pPlayer);

public:
	/// 주변 타일을 조사하는 함수가 여기 있게 되는 경우
	void CheckDeadStones(StoneType type);

private:
	// 내 돌의 타입의 반대를 가져온다. (백->흑 / 흑->백)
	StoneType GetOpponent(StoneType myType);
};