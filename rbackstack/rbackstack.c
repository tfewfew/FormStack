include "Base.h"

typedef struct rbtTaskEntry
{
	ULONG* pulTaskEntryFuncAddr;
	ULONG ulFuncLen;
}RBT_TASKENTRY_S;

RBT_TASKENTRY_S g_stTaskEntry;


/*******************************************/
/* 函数功能:设置任务公共入口               */
/* 函数入参:                               */
/* 函数出参:                               */
/* 函数返回:                               */
/*******************************************/
VOID RBT_SetTaskEntry( ULONG *pulTaskEntryFuncAddr, ULONG ulFuncLen )
{
	g_stTaskEntry.pulTaskEntryFuncAddr = pulTaskEntryFuncAddr;
	g_stTaskEntry.ulFuncLen = ulFuncLen
	return;
}

/*******************************************/
/* 函数功能:通过任务入口公共函数的地址，找到
            栈的遍历起始位置               */
/* 函数入参:                               */
/* 函数出参:                               */
/* 函数返回:                               */
/*******************************************/
ULONG* RBT_FindTaskEntry( ULONG ulStackHead, ULONG ulStackBottom )
{
	ULONG* pulStackLocal;
	for ( pulStackLocal = ulStackHead; pulStackLocal < ulStackBottom; pulStackLocal++ )
	{
		if ( *pulStackLocal >= g_stTaskEntry.pulTaskEntryFuncAddr &&
			 *pulStackLocal <= (g_stTaskEntry.pulTaskEntryFuncAddr + g_stTaskEntry.ulFuncLen))
		{
			return pulStackLocal;
		}
	}
	return NULL_PTR;
}


