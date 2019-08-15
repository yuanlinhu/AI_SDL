
#include "BlockMgr.hpp"
#include "Block.hpp"
#include "AStar.hpp"

//Block		g_BlockArray[11][15];

BlockMgr::BlockMgr()
{

}

void BlockMgr::init(int mapW, int mapH, int blockW, int blockH)
{
	m_MapW = mapW;
	m_MapH = mapH;
	m_BlockW = blockW;
	m_BlockH = blockH;
	m_Row = mapW / blockW;
	m_Col = mapH / blockH;

	m_Row = ((mapW % blockW) > 0) ? m_Row + 1 : m_Row;
	m_Col = ((mapH % blockH) > 0) ? m_Col + 1 : m_Col;

	//m_BlockList = new Block*[m_Col];
	for (int i = 0; i < m_Row; i++)
	{
		//m_BlockList[i] = new Block();
	}

	//int nsize = sizeof(**m_BlockList);


	int index = 0;
	for (int j =0; j < m_Col; j++)
	{
		for (int i = 0; i < m_Row; i++)
		{
			//Block* newBlock = &(m_BlockList[i][j]);

			Block* newBlock = new Block();
			newBlock->setConfig(mapW, mapH, m_BlockW, m_BlockH, m_Row, m_Col);
			newBlock->init(i, j, index);
			m_BlockVec.push_back(newBlock);
			index++;

			//Block* tmp = &(g_BlockArray[i][j]);
			//tmp->copy(newBlock);
		}
	}

	for (int j = 0; j < m_Col; j++)
	{
		for (int i = 0; i < m_Row; i++)
		{
			int tmpIndex = i + j * m_Row;
			Block * tmpBlock = getBlock(i, j);//m_BlockVec[i*m_Col + j];
			if (tmpBlock->m_RowIndex != i )
			{
				int jj = 0;
				jj++;
				cout << "error m_RowIndex: " << tmpBlock->m_RowIndex << ", i:" << i << endl;
			}
			if (tmpBlock->m_ColIndex != j)
			{
				int jj = 0;
				jj++;
				cout << "error m_ColIndex: " << tmpBlock->m_ColIndex << ", j:" << j << endl;
			}

			if (tmpBlock->m_index != tmpIndex)
			{
				int jj = 0;
				jj++;
				cout << "error m_index: " << tmpBlock->m_index << ", tmpIndex:" << tmpIndex << endl;
			}
		}
	}

	int kk = 0;
	kk++;
}

void BlockMgr::resetSelect()
{
	for (auto& tmp : m_BlockVec)
	{
		tmp->setSelect(0);
	}
}

void BlockMgr::resetCostG()
{
	for (auto& tmp : m_BlockVec)
	{
		tmp->setCostG(0);
	}
}



Block* BlockMgr::getBlock(int rowIndex, int colIndex)
{
	if ((rowIndex < 0) || (rowIndex >= m_Row))
	{
		return nullptr;
	}

	if ((colIndex < 0) || (colIndex >= m_Col))
	{
		return nullptr;
	}

	int index = rowIndex + colIndex * m_Row;

	return m_BlockVec[index];
}

Block* BlockMgr::getBlockByPoint(int x, int y)
{
	int x_index = x / m_BlockW;
	int y_index = y / m_BlockH;

	//x_index = ((x % m_BlockW) > 0) ? x_index + 1 : x_index;
	//y_index = ((y % m_BlockH) > 0) ? y_index + 1 : y_index;

	Block* blk = getBlock(x_index, y_index);

	cout << "x: " << x << ", y:" << y << endl;
	cout << "x_index: " << x_index << ", y_index:" << y_index << endl;
	if (nullptr != blk)
	{
		cout << " blk:" << blk->m_index << endl;
	}
	return getBlock(x_index, y_index);
}

void BlockMgr::get9GridBlockListByPoint(int x, int y, vector<Block*>& outList)
{
	Block* curBlock = getBlockByPoint(x, y);
	get9GridBlockList(curBlock, outList);
}

void BlockMgr::get9GridBlockList(Block* curBlock, vector<Block*>& outList)
{
	if (nullptr == curBlock)
	{
		return;
	}

	outList.clear();
	int curRowIndex = curBlock->m_RowIndex;
	int curColIndex = curBlock->m_ColIndex;
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{

			Block* tmpBlock = getBlock(curRowIndex + i, curColIndex + j);
			if (i == 0 && j == 0)
			{
				//过滤自己
				continue;
			}
			if (nullptr != tmpBlock)
			{
				outList.push_back(tmpBlock);
			}
		}
	}
}

void BlockMgr::addBlock(int rowIndex, int colIndex, BlockType type)
{
	Block* tmp = getBlock(rowIndex, colIndex);
	if (nullptr != tmp)
	{
		//tmp->setType(type);
	}
}

void BlockMgr::update(Uint32 delta)
{

}

void BlockMgr::render()
{
	for (auto &tmp : m_BlockVec)
	{
		(tmp)->render();
	}

	//SDL_SetRenderDrawColor(g_render, 255, 255, 50, 0);
	//SDL_Rect  rect;
	//rect.x = 100;
	//rect.y = 100;
	//rect.w = 100;
	//rect.h = 100;
	//SDL_RenderFillRect(g_render, &rect);
}

void BlockMgr::findPath(int x, int y, int target_x, int target_y)
{
	Block* src_block = getBlockByPoint(x, y);
	if (NULL == src_block)
	{
		return;
	}

	Block* tar_block = getBlockByPoint(target_x, target_y);
	if (NULL == tar_block)
	{
		return;
	}

	//1. 把起点加入 open list
	AddToOpenList(src_block);

	//2. 重复如下过程：
	//	a.遍历 open list ，查找 F 值最小的节点，把它作为当前要处理的节点。
	//	b.把这个节点移到 close list 。
	//	c.对当前方格的 8 个相邻方格的每一个方格？
	//	◆     如果它是不可抵达的或者它在 close list 中，忽略它。否则，做如下操作。
	//	◆     如果它不在 open list 中，把它加入 open list ，并且把当前方格设置为它的父亲，
	//			记录该方格的 F ， G 和 H 值。
	//	◆     如果它已经在 open list 中，检查这条路径(即经由当前方格到达它那里) 是否更好，
	//			用 G 值作参考。更小的 G 值表示这是更好的路径。
	//			如果是这样，把它的父亲设置为当前方格，并重新计算它的 G 和 F 值。
	//			如果你的 open list 是按 F 值排序的话，改变后你可能需要重新排序。

	vector<Block*> nearBlockVec;

	while (Block* curBlockOpen = getAndDelMinCostBlockFromOpenList())
	{

		cout << "curBlockOpen m_RowIndex: " << curBlockOpen->m_RowIndex << ", m_ColIndex:" << curBlockOpen->m_ColIndex << endl;
		AddToCloseList(curBlockOpen);

		get9GridBlockList(curBlockOpen, nearBlockVec);

		for (auto& tmpNear : nearBlockVec)
		{
			if (true == tmpNear->isObtacle())
			{
				//过滤障碍点
				continue;
			}
			if (true == isInCloseList(tmpNear))
			{
				//过滤 closelist里的点
				continue;
			}

			if (false == isInOpenList(tmpNear))
			{
				//不在open列表
				//
				tmpNear->setParent(curBlockOpen);
				tmpNear->calculateG(curBlockOpen);
				tmpNear->calculateH(tar_block);

				if (tmpNear->m_index == tar_block->m_index)
				{
					//结束
					break;
				}

				//
				AddToOpenList(tmpNear);
			}
			else
			{
				//	◆     如果它已经在 open list 中，检查这条路径(即经由当前方格到达它那里) 是否更好，
				//			用 G 值作参考。更小的 G 值表示这是更好的路径。
				//			如果是这样，把它的父亲设置为当前方格，并重新计算它的 G 和 F 值。
				//			如果你的 open list 是按 F 值排序的话，改变后你可能需要重新排序。
				Block* parent = curBlockOpen->getParent();
				if (nullptr != parent)
				{
					int costG = curBlockOpen->getCostG() + AStar::calculateG(tmpNear, curBlockOpen);
					int costParentG = AStar::calculateG(tmpNear, curBlockOpen->getParent());
					if (costParentG <= costG)
					{
						curBlockOpen = curBlockOpen->getParent();
						int newCostG = curBlockOpen->getCostG() + AStar::calculateG(tmpNear, curBlockOpen);
						tmpNear->setCostG(newCostG);
						//tmpNear->calculateG();
						//curBlockOpen->calculateG();
					}
				}
				
				int kk = 0;
				kk++;

				sortOpenList();
			}
		}

	}



	int kk1 = 0;



	return;









	//vector<Block*> vec;
	//get9GridBlockList(tar_block, vec);

	//for (auto& tmp : vec)
	//{
	//	AddToOpenList(tmp->getCostF(), tmp);
	//}


	//for (int i = 0; i < 12; ++i)
	//{
	//	Block* popBlock = getMinCostBlockFromOpenList();
	//	if (popBlock)
	//	{
	//		cout << "popBlock: " << popBlock->m_index << ", m_costG:" << popBlock->m_costG << endl;
	//		delBlockFromOpenList(popBlock);
	//	}
	//}

	//for (auto& tmp : vec)
	//{
	//	delBlockFromOpenList(tmp);
	//}


	int kk = 0;
}


bool BlockMgr::isInOpenList(Block* block)
{
	map<int, list<Block *>>::iterator mapIter;
	list<Block *>::iterator iter;
	for (mapIter = m_OpenList.begin(); mapIter != m_OpenList.end(); ++mapIter)
	{
		list<Block *>& block_list = mapIter->second;
		for (iter = block_list.begin(); iter != block_list.end(); ++iter)
		{
			if ((*iter)->m_index == block->m_index)
			{
				return true;
			}
		}
	}
	return false;
}

void BlockMgr::AddToOpenList(Block* block)
{
	AddToOpenList(block->getCostF(), block);
}
void BlockMgr::AddToOpenList(int costF, Block* block)
{
	map<int, list<Block *>>::iterator iter = m_OpenList.find(costF);
	if (iter == m_OpenList.end())
	{
		//未找到
		list<Block *> block_list;
		block_list.push_back(block);

		m_OpenList[costF] = block_list;
	}
	else
	{
		//找到
		iter->second.push_back(block);
	}
}

void BlockMgr::delBlockFromOpenList(Block* block)
{
	map<int, list<Block *>>::iterator mapIter;
	list<Block *>::iterator iter;
	for (mapIter = m_OpenList.begin(); mapIter != m_OpenList.end();)
	{
		list<Block *>& block_list = mapIter->second;
		for (iter = block_list.begin(); iter != block_list.end(); ++iter)
		{
			if ((*iter)->m_index == block->m_index)
			{
				block_list.erase(iter);
				break;
			}
		}
		if (block_list.empty())
		{
			m_OpenList.erase(mapIter++);
		}
		else
		{
			++mapIter;
		}
	}
}

Block* BlockMgr::getAndDelMinCostBlockFromOpenList()
{
	Block* retInfo = getMinCostBlockFromOpenList();
	if (nullptr != retInfo)
	{
		delBlockFromOpenList(retInfo);
	}

	return retInfo;
}
Block* BlockMgr::getMinCostBlockFromOpenList()
{
	Block* retInfo = nullptr;

	map<int, list<Block *>>::iterator mapIter;
	list<Block *>::iterator iter;
	for (mapIter = m_OpenList.begin(); mapIter != m_OpenList.end(); ++mapIter)
	{
		list<Block *>& block_list = mapIter->second;
		
		for (iter = block_list.begin(); iter != block_list.end(); ++iter)
		{
			if (nullptr == retInfo)
			{
				retInfo = *iter;
			}
			else
			{
				if ((*iter)->getCostF() < retInfo->getCostF())
				{
					retInfo = *iter;
				}
			}
		}
		
	}

	return retInfo;
}

bool BlockMgr::isInCloseList(Block* block)
{
	map<int, Block *>::iterator iter = m_CloseList.find(block->m_index);
	if (iter != m_CloseList.end())
	{
		return true;
	}

	return false;
}

void BlockMgr::AddToCloseList(Block* block)
{
	if (false == isInCloseList(block))
	{
		m_CloseList[block->m_index] = block;
	}
}

void BlockMgr::sortOpenList()
{

}