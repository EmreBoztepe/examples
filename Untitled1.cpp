#include <stdio.h>    



typedef void (*j1939_FuncType)(void);

typedef struct {
    j1939_FuncType fun;  /**< pointer to function to use */
    int      cycleTime;  /**< cycle time of j1939 message in MS */
} J1939_MsgListType;



typedef enum {
	J1939_MSG_EEC1 = 0,
	J1939_MSG_ETC1,
	J1939_MSG_ETC2,
	J1939_MSG_COUNT,
} J1939_MsgListEnum;


void sum (int a, int b)
{
	printf("%d",a+b);
}

void J1939_Eec1(void)
{
	
		printf("eec1");
	
}
void J1939_Etc1(void)
{
	
		printf("etc1");
	
}

void J1939_Etc2(void)
{
	
		printf("etc2");
	
}

static const J1939_MsgListType J1939_MsgList[J1939_MSG_COUNT] =

{ 	    [J1939_MSG_EEC1] =    {.fun = J1939_Eec1, .cycleTime = 10 },
		[J1939_MSG_ETC1] =    {.fun = J1939_Etc1, .cycleTime = 100 },
		[J1939_MSG_ETC2] =    {.fun = J1939_Etc2, .cycleTime = 1000 }
};


int main()
{ 
	
	int systemTimer = 0;
	int i = 0;
	
	while(systemTimer < 5000)	/* for testing purpose */
	{
		systemTimer++;
		
		for( i = 0; i < J1939_MSG_COUNT; i++ )
		{
			if( systemTimer % J1939_MsgList[i].cycleTime == 0 )
			{
				J1939_MsgList[i].fun();
				printf(" system time = %d\n",systemTimer);
	
			}
			
		}
	
	}
    return 0;
}



