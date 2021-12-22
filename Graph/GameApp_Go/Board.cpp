#include "Board.h"

GoBoard::GoBoard()
	:m_GDIEngine(nullptr),
	m_Player(nullptr),
	m_IsAlive(false),
	m_GoBoard()
{

}

GoBoard::~GoBoard()
{

}

StoneType GoBoard::GetStoneType(int x, int y) const
{
	return m_GoBoard[y][x]->GetStoneType();
}

void GoBoard::Initialize(GDIEngine* pGDIEngine)
{
	m_GDIEngine = pGDIEngine;
}

void GoBoard::InitBoard()
{
	for (int y = 0; y < BOARD_Y; y++)
	{
		for (int x = 0; x < BOARD_X; x++)
		{
			m_GoBoard[y][x] = new Tile(StoneType::STONE_EMPTY, x, y);

			m_GoBoard[y][x]->SetPosY(y * TILESIZE);
			m_GoBoard[y][x]->SetPosX(x * TILESIZE);
		}
	}
}

void GoBoard::DrawBoard()
{
	//SelectObject(m_GDIEngine->GetBackbuffer(), GetStockObject(GRAY_BRUSH));
	m_GDIEngine->DrawRect(0, 0, 800, 800);

	for (int i = 0; i < BOARD_X; i++)
	{
		m_GDIEngine->DrawLine((TILESIZE * i) + 20, 0, (TILESIZE * i) + 20, 800);
		m_GDIEngine->DrawLine(0, (TILESIZE * i) + 20, 800, (TILESIZE * i) + 20);
	}
}

void GoBoard::DrawBoardStoneType()
{
	for (int y = 0; y < BOARD_Y; y++)
	{
		for (int x = 0; x < BOARD_X; x++)
		{
			if (m_GoBoard[y][x]->GetStoneType() == StoneType::STONE_BLACK)
			{
				m_GDIEngine->DrawElliBlack(m_GoBoard[y][x]->GetPosX(), m_GoBoard[y][x]->GetPosY());
			}
			else if (m_GoBoard[y][x]->GetStoneType() == StoneType::STONE_WHITE)
			{
				m_GDIEngine->DrawElli(m_GoBoard[y][x]->GetPosX(), m_GoBoard[y][x]->GetPosY());
			}
			else
			{
				//...
			}
		}
	}
}

void GoBoard::PickTileChangeStoneType(Player* pPlayer)
{
	int CurPickTilePosX;
	int CurPickTilePosY;

	CurPickTilePosX = pPlayer->CurrMousePos.x / TILESIZE;
	CurPickTilePosY = pPlayer->CurrMousePos.y / TILESIZE;

	if (m_GoBoard[CurPickTilePosY][CurPickTilePosX]->GetStoneType() != StoneType::STONE_EMPTY)
	{
		return;
	}

	if (pPlayer->MyTurnStoneType == StoneType::STONE_BLACK)
	{
		m_GoBoard[CurPickTilePosY][CurPickTilePosX]->SetStoneType(StoneType::STONE_BLACK);
		pPlayer->MyTurnStoneType = StoneType::STONE_WHITE;
	}
	else
	{
		m_GoBoard[CurPickTilePosY][CurPickTilePosX]->SetStoneType(StoneType::STONE_WHITE);
		pPlayer->MyTurnStoneType = StoneType::STONE_BLACK;
	}
}

void GoBoard::CheckDeadStones(StoneType type)
{
	StoneType _opponent = GetOpponent(type);

	for (int y = 1; y < BOARD_Y; y++)
	{
		for (int x = 1; x < BOARD_X; x++)
		{
			/// 한집 따는 조건-방소연 코딩
			if (m_GoBoard[y][x]->IsStoneType(type))
			{
				if (m_GoBoard[y - 1][x]->IsStoneType(_opponent) &&
					m_GoBoard[y + 1][x]->IsStoneType(_opponent) &&
					m_GoBoard[y][x - 1]->IsStoneType(_opponent) &&
					m_GoBoard[y][x + 1]->IsStoneType(_opponent))
				{
					m_GoBoard[y][x]->SetStoneType(StoneType::STONE_EMPTY);
				}
			}
		}
	}
}

StoneType GoBoard::GetOpponent(StoneType myType)
{
	StoneType _opponent = StoneType::STONE_EMPTY;

	if (myType == StoneType::STONE_BLACK) _opponent = StoneType::STONE_WHITE;
	else if (myType == StoneType::STONE_WHITE) _opponent = StoneType::STONE_BLACK;

	return _opponent;
}

/*
BOOL Tile::ResetAllPassed(GoBoard* pGoBoard)
{
	// 판 내의 모든 돌의 Passed 여부를 비워준다
	for (int y = 0; y<BOARD_Y; y++)
	{
		for (int x=0; x<BOARD_X; x++)
		{
			if (pGoBoard->GetGoBoard(x, y) != NULL)
			{
				pGoBoard->GetGoBoard(x, y)->SetPassed();
			}
		}
	}

	return 0;
}
*/