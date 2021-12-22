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
	// �ٵ����� �׸���.
	pGoBoard->DrawBoard();
	pGoBoard->DrawBoardStoneType();

	// UI������ �׸���.
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

	// �����ϴ� ���� ����ִٸ� ����
	if (pGoBoard->GetGoBoard(x, y) == NULL)
	{
		return true;
	}

	/// 1. �� �������κ��� �����ؼ�, ����� �����Ѵ� ������ ���� Ư�� ����Ʈ�� �־�д�
	/// 2. �ڽ��� ��ȸ�� �ߴ°�? ���θ� ���� ��� ����Ʈ�� �ִ´�
	/// 3. ����Ʈ ���� ����� �񱳸� �ؼ� �ߺ�üũ
	Tile* NowTile = pGoBoard->GetGoBoard(x, y);
	StoneType StartStoneType = NowTile->GetStoneType();

	pGoBoard->m_IsAlive = false;

	// ��ȸ�� �ؾ� �� ����� �Ǵ� ����Ʈ, ��� �ۼ��� �� ������
	vector<Tile*> CheckList;

	// ���� ���� �ϴ� �־�д�
	CheckList.push_back(NowTile);

	while (true)
	{
		// ���� Ȯ���ϴ� ���� Ȱ�ΰ� �ִٸ� �� ���� ��Ƴ��� ���̴�
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

			// ���� ���� �̹� ���縦 �� �����Ƿ�, ����Ʈ���� �̴´�
			// ���� ����� ����Ʈ���� �̾Ƶ�, ������ ��ũ�� ���Ƽ� ���縦 �߾���? ���� �����Ѵ�
			for (vector<Tile*>::iterator it = CheckList.begin(); it != CheckList.end(); it++)
			{
				if (*it = NowTile)
				{
					it = CheckList.erase(it);
					break;
				}
			}

			// ����Ʈ�� ����ٸ�, ��� ���縦 ����ģ ���̴� ��ҳ� �׾����� ��·�� �ǴܵǾ� ���� ���̴�
			if (CheckList.empty())
			{
				break;
			}
			else
			{
				// ���� ����Ʈ���� �ϳ��� �̾�, ���� ���� ��ü ���ش�
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