/* --------------------------------------------------------------------------------------- */ 
// 
// CROSS CHASE by Fabrizio Caruso
//
// Fabrizio_Caruso@hotmail.com
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from
// the use of this software.

// Permission is granted to anyone to use this software for non-commercial applications, 
// subject to the following restrictions:

// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software in
// a product, an acknowledgment in the product documentation would be
// appreciated but is not required.

// 2. Altered source versions must be plainly marked as such, and must not
// be misrepresented as being the original software.

// 3. This notice may not be removed or altered from any source distribution.
/* --------------------------------------------------------------------------------------- */ 


#include "ghost.h"
#include "settings.h"

extern unsigned short ghostLevel;
extern unsigned char level;

extern Character ghosts[GHOSTS_NUMBER];
extern Character bombs[BOMBS_NUMBER];

#if !defined(TINY_GAME)
unsigned short computeGhostSlowDown(void)
{
	if(ghostLevel<MAX_GHOST_LEVEL)
	{
		#if defined(TURN_BASED)
			return INITIAL_GHOST_SLOWDOWN-(unsigned short)level*256-ghostLevel*8;		
		#else
			return INITIAL_GHOST_SLOWDOWN-(unsigned short)level*256-ghostLevel*16;
		#endif
	}
	return GHOST_MIN_SLOWDOWN;
}
#endif

#if defined(FULL_GAME)
	void decreaseGhostLevel(void)
	{
		if(ghostLevel>GHOST_LEVEL_DECREASE)
			ghostLevel-=GHOST_LEVEL_DECREASE;
		else
			ghostLevel=0;
	}
#endif

void displayBombs(void)
{
	unsigned char i;

	for(i=0;i<BOMBS_NUMBER;++i)
	{
		displayBomb(&bombs[i]);
	}
}	

#if defined(FULL_GAME)
	unsigned char firstAlive(void)
	{
		unsigned char i;
		
		i=0;
		while(i<GHOSTS_NUMBER)
		{
			if(ghosts[i]._status)
				return i;
			++i;
		}
		return GHOSTS_NUMBER;
	}
#endif
