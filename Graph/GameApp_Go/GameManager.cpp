#include "GameManager.h"
#include <vector>
#include "GameDefine.h"
#include "Board.h"
#include "GDIEngine.h"
#include "GameUI.h"
using namespace std;

GameManager::GameManager(GDIEngine* pEngine)
	: m_pEngine(pEngine)
{
	pGoBoard = new GoBoard;
	pGoBoard->Initialize(m_pEngine);
	pGoBoard->InitBoard();

	m_pPlayer = new Player;
	m_pPlayer->InitMyTrunStoneType();

	m_UI = new GameUI;
	m_UI->Initialize(m_pEngine, m_pPlayer);
}

GameManager::~GameManager()
{

}

void GameManager::DrawAll()
{
	// 바둑판을 그린다.
	pGoBoard->DrawBoard();
	pGoBoard->DrawBoardStoneType();

	// UI정보를 그린다.
	m_UI->DrawMyTurn();
}

void GameManager::SetPlayersMousePos(int x, int y)
{
	m_pPlayer->CurrMousePos.x = x;
	m_pPlayer->CurrMousePos.y = y;
}

void GameManager::PickTileChangeStoneType()
{
	pGoBoard->PickTileChangeStoneType(m_pPlayer);
}

void GameManager::CheckImDead(StoneType type)
{
	pGoBoard->CheckDeadStones(type);
}

/*
bool GameManager::Check_DeadOrAlive(GoBoard* pGoBoard, int x, int y)
{
	Tile* pTile = new Tile;

	// 조사하는 곳이 비어있다면 실패
	if (pGoBoard->GetGoBoard(x, y) == NULL)
	{
		return true;
	}

	/// 1. 한 지점으로부터 시작해서, 사방을 조사한다 가져온 돌은 특정 리스트에 넣어둔다
	/// 2. 자신이 순회를 했는가? 여부를 봐서 모두 리스트에 넣는다
	/// 3. 리스트 안의 돌들과 비교를 해서 중복체크
	Tile* NowTile = pGoBoard->GetGoBoard(x, y);
	StoneType StartStoneType = NowTile->GetStoneType();

	pGoBoard->m_IsAlive = false;

	// 순회를 해야 할 대상이 되는 리스트, 계속 작성을 해 나간다
	vector<Tile*> CheckList;

	// 시작 돌을 일단 넣어둔다
	CheckList.push_back(NowTile);

	while (true)
	{
		// 현재 확인하는 돌이 활로가 있다면 이 군은 살아남은 것이다
		if (NowTile->IsExistaWay() == true)
		{
			pGoBoard->m_IsAlive = true;
			break;
		}
		else
		{
			if (pTile->MatchType_NotPassed(NowTile->left, StartStoneType) == true)
			{
				NowTile->left->SetPassed();
				CheckList.push_back(NowTile->left);
			}

			if (pTile->MatchType_NotPassed(NowTile->right, StartStoneType) == true)
			{
				NowTile->right->SetPassed();
				CheckList.push_back(NowTile->right);
			}

			if (pTile->MatchType_NotPassed(NowTile->up, StartStoneType) == true)
			{
				NowTile->up->SetPassed();
				CheckList.push_back(NowTile->up);
			}

			if (pTile->MatchType_NotPassed(NowTile->down, StartStoneType) == true)
			{
				NowTile->down->SetPassed();
				CheckList.push_back(NowTile->down);
			}

			NowTile->SetPassed();

			// 현재 돌은 이미 조사를 다 했으므로, 리스트에서 뽑는다
			// 조사 대상인 리스트에서 뽑아도, 여전히 링크는 남아서 조사를 했었나? 에는 반응한다
			for (vector<Tile*>::iterator it = CheckList.begin(); it != CheckList.end(); it++)
			{
				if (*it = NowTile)
				{
					it = CheckList.erase(it);
					break;
				}
			}

			// 리스트가 비었다면, 모든 조사를 끝마친 것이다 살았나 죽었나는 어쨌든 판단되어 있을 것이다
			if (CheckList.empty())
			{
				break;
			}
			else
			{
				// 이제 리스트에서 하나를 뽑아, 현재 돌로 교체 해준다
				NowTile = CheckList[0];
			}
		}
	}

	delete pTile;

	/*
	if (pGoBoard->m_IsAlive == true)
	{
		ResetAllPassed();
	}
}
*/