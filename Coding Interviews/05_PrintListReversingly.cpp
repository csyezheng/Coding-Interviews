#include <iostream>
#include "05_PrintListReversingly.h"

void printListReversingly(ListNode *pHead)
{
	if (pHead == nullptr)
		return;
	printListReversingly(pHead->m_pNext);
	std::cout << pHead->m_nKey << std::endl;
}