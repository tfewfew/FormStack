include "Base.h"

typedef struct rbtTaskEntry
{
	ULONG* pulTaskEntryFuncAddr;
	ULONG ulFuncLen;
}RBT_TASKENTRY_S;

RBT_TASKENTRY_S g_stTaskEntry;


/*******************************************/
/* ��������:�������񹫹����               */
/* �������:                               */
/* ��������:                               */
/* ��������:                               */
/*******************************************/
VOID RBT_SetTaskEntry( ULONG *pulTaskEntryFuncAddr, ULONG ulFuncLen )
{
	g_stTaskEntry.pulTaskEntryFuncAddr = pulTaskEntryFuncAddr;
	g_stTaskEntry.ulFuncLen = ulFuncLen
	return;
}

/*******************************************/
/* ��������:ͨ��������ڹ��������ĵ�ַ���ҵ�
            ջ�ı�����ʼλ��               */
/* �������:                               */
/* ��������:                               */
/* ��������:                               */
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


