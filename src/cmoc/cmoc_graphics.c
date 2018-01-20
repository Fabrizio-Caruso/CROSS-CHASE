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

#define NOT_INVERTED 64
	
// BLUE
#define _PLAYER ('*'+NOT_INVERTED)
// #define _PLAYER_DOWN 0
// #define _PLAYER_UP 1
// #define _PLAYER_RIGHT 2
// #define _PLAYER_LEFT 3

#define _SPACE (' '+NOT_INVERTED)

#define _GUN 4

// YELLOW
#define _INVINCIBLE_GHOST 5
#define _VERTICAL_BRICK 6
#define _HORIZONTAL_BRICK 7
#define _EXTRA_LIFE 8
#define _EXTRA_POINTS 9

// GREEN
#define _POWERUP  10

// RED
#define _BOMB 'X'
#define _DEAD_GHOST '#'

#define _INVINCIBILITY 13
#define _MISSILE 14

#define _GHOST 'O'

#define _LEFT_ENEMY_MISSILE 16
#define _RIGHT_ENEMY_MISSILE 17
#define _BUBBLE 18

#include "../display_macros.h"

extern Image PLAYER_IMAGE;
extern Image GHOST_IMAGE;
extern Image BOMB_IMAGE;

#if !defined(TINY_GAME)
	extern Image DEAD_GHOST_IMAGE;
	extern Image INVINCIBLE_GHOST_IMAGE;
	extern Image MISSILE_IMAGE;
	
	extern Image POWERUP_IMAGE;	
	extern Image FREEZE_IMAGE;
	extern Image GUN_IMAGE;
	extern Image EXTRA_POINTS_IMAGE;
	
#endif
	
#if defined(FULL_GAME)
	extern Image LEFT_ENEMY_MISSILE_IMAGE;
	extern Image RIGHT_ENEMY_MISSILE_IMAGE;

	extern Image BUBBLE_IMAGE;

	extern Image EXTRA_LIFE_IMAGE;
	extern Image INVINCIBILITY_IMAGE;	
	
	extern Image BROKEN_WALL_IMAGE;
#endif

#define BASE_ADDR (unsigned short)(0x0400)



#if defined(REDEFINED_CHARS)
	Image PLAYER_DOWN;
	Image PLAYER_UP;
	Image PLAYER_RIGHT;
	Image PLAYER_LEFT;
#endif
	
#define POKE(addr,val)     (*(unsigned char*) (addr) = (val))
#define POKEW(addr,val)    (*(unsigned*) (addr) = (val))
#define PEEK(addr)         (*(unsigned char*) (addr))
#define PEEKW(addr) (*(unsigned*) (addr))

#define _DRAW(x,y,image) \
{ \
	POKE(BASE_ADDR+x+((unsigned short) y)*32,image); \
}

#define _DELETE(x,y) \
{ \
		POKE(BASE_ADDR+x+((unsigned short) y)*32,_SPACE); \
}

#define _DRAW_VERTICAL_WALL(x,y)  
#define _DRAW_HORIZONTAL_WALL(x,y)  
#define _DRAW_BROKEN_WALL(x,y)  	


void INIT_GRAPHICS(void)
{

}

void INIT_IMAGES(void)
{		
	GHOST_IMAGE._imageData = _GHOST;
	BOMB_IMAGE._imageData = _BOMB;
	PLAYER_IMAGE._imageData = _PLAYER;
	
	#if !defined(TINY_GAME)
		INVINCIBLE_GHOST_IMAGE._imageData = _INVINCIBLE_GHOST;	
		MISSILE_IMAGE._imageData = _MISSILE;
		DEAD_GHOST_IMAGE._imageData = _DEAD_GHOST;	
		
		POWERUP_IMAGE._imageData = _POWERUP;
		FREEZE_IMAGE._imageData = _POWERUP;
		
		GUN_IMAGE._imageData = _GUN;
		EXTRA_POINTS_IMAGE._imageData = _EXTRA_POINTS;		
	#endif

	#if defined(REDEFINED_CHARS)
		PLAYER_DOWN._imageData = _PLAYER_DOWN;
		PLAYER_UP._imageData = _PLAYER_UP;	
		PLAYER_RIGHT._imageData = _PLAYER_RIGHT;
		PLAYER_LEFT._imageData = _PLAYER_LEFT;		
	#endif
		
	#if defined(FULL_GAME)
		LEFT_ENEMY_MISSILE_IMAGE._imageData = _LEFT_ENEMY_MISSILE;
		RIGHT_ENEMY_MISSILE_IMAGE._imageData = _RIGHT_ENEMY_MISSILE;
		
		BUBBLE_IMAGE._imageData = _BUBBLE;
				
		EXTRA_LIFE_IMAGE._imageData = _EXTRA_LIFE;
		INVINCIBILITY_IMAGE._imageData = _INVINCIBILITY;	
			
	#endif
}

#if defined(FULL_GAME)
	void DRAW_BROKEN_WALL(unsigned char x, unsigned char y)
	{
		_DRAW_BROKEN_WALL(x,y);
	}
#endif
	
void _draw(unsigned char x, unsigned char y, Image * image) 
{
	_DRAW(x,y,image->_imageData);
}

void _delete(unsigned char x, unsigned char y)
{
	_DELETE(x,y);
}

void _blink_draw(unsigned char x, unsigned char y, Image * image, unsigned char *blinkCounter) 
{
	if(*blinkCounter) 
	{
		_DRAW(x,y,image->_imageData);
		*blinkCounter=0;
	} 
	else 
	{
		_DELETE(x,y);
		*blinkCounter=1;
	}	
}

void CLEAR_SCREEN(void)
{
	unsigned char i;
	unsigned char j;
	
	for(i=0;i<YSize;++i)
	{
		for(j=0;j<XSize;++j)
		{
			POKE(BASE_ADDR+j+i*((unsigned short )XSize),_SPACE);
		}
	}
}

unsigned char screenCode(char ch)
{
	if(ch==32) 
	{
		return 32+64;
	}
	else
	{
		return ch-32;
	}	
}

void PRINT(unsigned char x, unsigned char y, char * str)
{
	unsigned char i = 0;
	while(str[i]!='\0')
	{
		POKE(BASE_ADDR+x+i+y*((unsigned short)XSize), screenCode(str[i])); //str[i]-32-64);
		++i;
	}
}

void print_05u0(unsigned char x, unsigned char y, char * str, unsigned short val)
{
	unsigned char i;
	unsigned char digits[6];
	unsigned short tmp = val;
	
	digits[0] = 0;
	for(i=1;i<6;++i)
	{
		digits[i] = (unsigned char) (tmp)%10;
		tmp/=10;
	}
	
	for(i=0;i<6;++i)
	{
		POKE(BASE_ADDR+x+i+y*((unsigned short)XSize), (unsigned char) (digits[5-i])+48);
	}
}	

void print_02u(unsigned char x, unsigned char y, char * str, unsigned short val)
{
	POKE(BASE_ADDR+x+y*  ((unsigned short)XSize), ((unsigned char) val)/10+48);		
	POKE(BASE_ADDR+x+1+y*((unsigned short)XSize), ((unsigned char) val)%10+48);	
}	


void print_u(unsigned char x, unsigned char y, char * str, unsigned short val)
{

	POKE(BASE_ADDR+x+y*((unsigned short)XSize), (unsigned char) (val+48));
}

void PRINTF(unsigned char x, unsigned char y, char * str, unsigned short val)
{
	if(strlen(str)==5)
	{	
		print_05u0(x,y,str,val);
	}
	else if(strlen(str)==4)
	{
		print_02u(x,y,str,val);		
	}
	else 
	{
		print_u(x,y,str,val);		
	}
}




// #if defined(REDEFINED_CHARS)
	// void DRAW_VERTICAL_LINE(unsigned char x,unsigned char y, unsigned char length)
	// { 
		// unsigned char i;
		// for(i=0;i<length;++i)
		// {
			// _DRAW_VERTICAL_WALL(x,y+i);
		// }
	// }

	// void DRAW_HORIZONTAL_LINE(unsigned char x,unsigned char y, unsigned char length)
	// {
		// unsigned char i;
		// for(i=0;i<length;++i)
		// {
			// _DRAW_HORIZONTAL_WALL(x+i,y);
		// }
	// }
// #endif	


