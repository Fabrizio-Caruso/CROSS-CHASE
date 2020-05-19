#include "display_macros.h"

#include "graphics_settings.h"

#if !defined(ANIMATE_PLAYER)
	extern Image PLAYER_IMAGE;
#else
	extern Image PLAYER_DOWN_IMAGE;
	extern Image PLAYER_UP_IMAGE;
	extern Image PLAYER_RIGHT_IMAGE;
	extern Image PLAYER_LEFT_IMAGE;	
#endif
	
extern Image GHOST_IMAGE;
extern Image BOMB_IMAGE;

#if !defined(NO_DEAD_GHOSTS)
	extern Image DEAD_GHOST_IMAGE;
#endif

#if !defined(TINY_GAME)
	extern Image SKULL_IMAGE;
	extern Image POWERUP_IMAGE;
	extern Image GUN_IMAGE;
	extern Image BULLET_IMAGE;
	extern Image EXTRA_POINTS_IMAGE;
	
	extern Image HORIZONTAL_BRICK_IMAGE;
	extern Image VERTICAL_BRICK_IMAGE;
#endif

#if defined(FULL_GAME)
	extern Image LEFT_HORIZONTAL_MISSILE_IMAGE;
	extern Image RIGHT_HORIZONTAL_MISSILE_IMAGE;

	extern Image ROCKET_IMAGE;

	extern Image FREEZE_IMAGE;
	extern Image EXTRA_LIFE_IMAGE;
	extern Image INVINCIBILITY_IMAGE;
	extern Image SUPER_IMAGE;	
	extern Image CONFUSE_IMAGE;
	extern Image ZOMBIE_IMAGE;
	
	extern Image BROKEN_BRICK_IMAGE;
#endif


// TODO: MOVE THIS TO TARGET SPECIFIC SETTINGS
#define CPC_WHITE 1
#define CPC_YELLOW 2 
#define CPC_RED 3
#define CPC_BLACK 4

#define _AQUARIUS_RED 16
#define _AQUARIUS_WHITE (16+32+64)
#define _AQUARIUS_YELLOW (16+32) 
#define _AQUARIUS_VIOLET (16+64) 
#define _AQUARIUS_CYAN (32+64)


#ifndef COLOR_CYAN
	#define COLOR_CYAN COLOR_BLUE
#endif

#if defined(NO_GRAPHICS) || defined(NO_PRINT)
    #if !defined(COLOR_RED)
        #define COLOR_RED 0
    #endif
#endif 


#if defined(CPCRSLIB)
	#define _PLAYER_COLOR CPC_YELLOW
	#define _GHOST_COLOR CPC_WHITE
	#define _DEAD_GHOST_COLOR CPC_RED
	#define _SKULL_COLOR CPC_YELLOW
	#define _BOMB_COLOR CPC_RED
	#define _MISSILE_COLOR CPC_WHITE
	#define _ROCKET_COLOR CPC_WHITE
	#define _POWERUP_COLOR CPC_YELLOW
	#define _FREEZE_COLOR CPC_WHITE
	#define _SUPER_COLOR CPC_RED
	#define _GUN_COLOR CPC_YELLOW
	#define _BULLET_COLOR CPC_WHITE
	#define _BRICK_COLOR CPC_YELLOW
	#define _EXTRA_POINTS_COLOR CPC_YELLOW
	#define _EXTRA_LIFE_COLOR CPC_YELLOW
	#define _INVINCIBILITY_COLOR CPC_YELLOW
	#define _CONFUSE_COLOR CPC_RED
	#define _ZOMBIE_COLOR CPC_YELLOW	
#elif defined(__AQUARIUS__) && defined(MEMORY_MAPPED)
	#define _PLAYER_COLOR _AQUARIUS_CYAN
	#define _GHOST_COLOR _AQUARIUS_WHITE
	#define _DEAD_GHOST_COLOR _AQUARIUS_RED
	#define _SKULL_COLOR _AQUARIUS_YELLOW
	#define _BOMB_COLOR _AQUARIUS_RED
	#define _MISSILE_COLOR _AQUARIUS_WHITE
	#define _ROCKET_COLOR _AQUARIUS_WHITE
	#define _POWERUP_COLOR _AQUARIUS_YELLOW
	#define _FREEZE_COLOR _AQUARIUS_CYAN
	#define _SUPER_COLOR _AQUARIUS_RED
	#define _GUN_COLOR _AQUARIUS_YELLOW
	#define _BULLET_COLOR _AQUARIUS_WHITE
	#define _BRICK_COLOR _AQUARIUS_YELLOW
	#define _EXTRA_POINTS_COLOR _AQUARIUS_YELLOW
	#define _EXTRA_LIFE_COLOR _AQUARIUS_YELLOW
	#define _INVINCIBILITY_COLOR _AQUARIUS_YELLOW
	#define _CONFUSE_COLOR _AQUARIUS_RED
	#define _ZOMBIE_COLOR _AQUARIUS_YELLOW	
#elif defined(__PC6001__) || defined(__SPC1000__)
	#define _PLAYER_COLOR COLOR_BLUE 
	#define _GHOST_COLOR COLOR_CYAN
	#define _DEAD_GHOST_COLOR COLOR_RED
	#define _SKULL_COLOR COLOR_YELLOW
	#define _BOMB_COLOR COLOR_RED
	#define _MISSILE_COLOR COLOR_CYAN
	#define _ROCKET_COLOR COLOR_CYAN
	#define _POWERUP_COLOR COLOR_CYAN
	#define _FREEZE_COLOR COLOR_BLUE
	#define _SUPER_COLOR COLOR_RED
	#define _GUN_COLOR COLOR_BLUE
	#define _BULLET_COLOR COLOR_CYAN
	#define _BRICK_COLOR COLOR_YELLOW
	#define _EXTRA_POINTS_COLOR COLOR_YELLOW
	#define _EXTRA_LIFE_COLOR COLOR_YELLOW
	#define _INVINCIBILITY_COLOR COLOR_YELLOW
	#define _CONFUSE_COLOR COLOR_RED
	#define _ZOMBIE_COLOR COLOR_YELLOW
#elif defined(NO_GRAPHICS)
	#define _PLAYER_COLOR 0 
	#define _GHOST_COLOR 0
	#define _DEAD_GHOST_COLOR 0
	#define _SKULL_COLOR 0
	#define _BOMB_COLOR 0
	#define _MISSILE_COLOR 0
	#define _ROCKET_COLOR 0
	#define _POWERUP_COLOR 0
	#define _FREEZE_COLOR 0
	#define _SUPER_COLOR 0
	#define _GUN_COLOR 0
	#define _BULLET_COLOR 0
	#define _BRICK_COLOR 0
	#define _EXTRA_POINTS_COLOR 0
	#define _EXTRA_LIFE_COLOR 0
	#define _INVINCIBILITY_COLOR 0
	#define _CONFUSE_COLOR 0
	#define _ZOMBIE_COLOR 0
#else
	#define _PLAYER_COLOR COLOR_CYAN
	#define _GHOST_COLOR COLOR_WHITE
	#define _DEAD_GHOST_COLOR COLOR_RED
	#define _SKULL_COLOR COLOR_YELLOW
	#define _BOMB_COLOR COLOR_RED
	#define _MISSILE_COLOR COLOR_WHITE
	#define _ROCKET_COLOR COLOR_WHITE
	#define _POWERUP_COLOR COLOR_GREEN
	#define _FREEZE_COLOR COLOR_CYAN
	#define _SUPER_COLOR COLOR_RED
	#if !defined(__NCURSES__)
		#define _GUN_COLOR COLOR_BLUE
	#else
		#define _GUN_COLOR COLOR_YELLOW
	#endif
	#define _BULLET_COLOR COLOR_WHITE
	#define _BRICK_COLOR COLOR_YELLOW
	#define _EXTRA_POINTS_COLOR COLOR_YELLOW
	#define _EXTRA_LIFE_COLOR COLOR_YELLOW
	#define _INVINCIBILITY_COLOR COLOR_YELLOW
	#define _CONFUSE_COLOR COLOR_RED
	#define _ZOMBIE_COLOR COLOR_YELLOW
#endif


void INIT_IMAGES(void)
{
# if !defined(NO_GRAPHICS)
	// Set color data 
	#if !defined(NO_COLOR)
		
		#if defined(ANIMATE_PLAYER)
			PLAYER_DOWN_IMAGE._color = _PLAYER_COLOR;
			PLAYER_UP_IMAGE._color = _PLAYER_COLOR;
			PLAYER_RIGHT_IMAGE._color = _PLAYER_COLOR;
			PLAYER_LEFT_IMAGE._color = _PLAYER_COLOR;
		#else
			PLAYER_IMAGE._color = _PLAYER_COLOR;
		#endif	
	
		BOMB_IMAGE._color = _BOMB_COLOR;
		GHOST_IMAGE._color = _GHOST_COLOR;		
		
		#if !defined(NO_DEAD_GHOSTS)
			DEAD_GHOST_IMAGE._color = _DEAD_GHOST_COLOR;
		#endif
		
		#if !defined(TINY_GAME)
			SKULL_IMAGE._color = _SKULL_COLOR;
			POWERUP_IMAGE._color = _POWERUP_COLOR;
			GUN_IMAGE._color = _GUN_COLOR;
			EXTRA_POINTS_IMAGE._color = _EXTRA_POINTS_COLOR;
			BULLET_IMAGE._color = _BULLET_COLOR;
			
			VERTICAL_BRICK_IMAGE._color = _BRICK_COLOR;
			HORIZONTAL_BRICK_IMAGE._color = _BRICK_COLOR;			
		#endif
		
		#if defined(FULL_GAME)
			RIGHT_HORIZONTAL_MISSILE_IMAGE._color = _MISSILE_COLOR;		
			LEFT_HORIZONTAL_MISSILE_IMAGE._color = _MISSILE_COLOR;
			
			ROCKET_IMAGE._color = _ROCKET_COLOR;

			FREEZE_IMAGE._color = _FREEZE_COLOR;
			EXTRA_LIFE_IMAGE._color = _EXTRA_LIFE_COLOR;
			
			INVINCIBILITY_IMAGE._color = _INVINCIBILITY_COLOR;
			SUPER_IMAGE._color = _SUPER_COLOR;
			CONFUSE_IMAGE._color = _CONFUSE_COLOR;
			ZOMBIE_IMAGE._color = _ZOMBIE_COLOR;
			
			BROKEN_BRICK_IMAGE._color = _BRICK_COLOR;
		#endif	
	#endif	

	// Set Image Data
	#if defined(ANIMATE_PLAYER)
		PLAYER_DOWN_IMAGE._imageData = _PLAYER_DOWN;
		PLAYER_UP_IMAGE._imageData = _PLAYER_UP;	
		PLAYER_RIGHT_IMAGE._imageData = _PLAYER_RIGHT;
		PLAYER_LEFT_IMAGE._imageData = _PLAYER_LEFT;	
	#else
		PLAYER_IMAGE._imageData = _PLAYER;			
	#endif
	
	GHOST_IMAGE._imageData = _GHOST;
	BOMB_IMAGE._imageData = _BOMB;
	
	#if !defined(NO_DEAD_GHOSTS)
		DEAD_GHOST_IMAGE._imageData = _DEAD_GHOST;	
	#endif
	
	#if !defined(TINY_GAME)
		SKULL_IMAGE._imageData = _SKULL;

		POWERUP_IMAGE._imageData = _POWERUP;
		GUN_IMAGE._imageData = _GUN;
		EXTRA_POINTS_IMAGE._imageData = _EXTRA_POINTS;
		
		BULLET_IMAGE._imageData = _BULLET;
		
		VERTICAL_BRICK_IMAGE._imageData = _VERTICAL_BRICK;
		HORIZONTAL_BRICK_IMAGE._imageData = _HORIZONTAL_BRICK;		
	#endif
	
	#if defined(FULL_GAME)
		LEFT_HORIZONTAL_MISSILE_IMAGE._imageData = _LEFT_HORIZONTAL_MISSILE;
		
		RIGHT_HORIZONTAL_MISSILE_IMAGE._imageData = _RIGHT_HORIZONTAL_MISSILE;
		
		ROCKET_IMAGE._imageData = _ROCKET;

		// If colors are present POWERUP/FREEZE/SUPER can be differentiated by the color attribute -> same _POWERUP for all of them
		#if !defined(NO_COLOR) && !defined(UDG_GRAPHICS) && !defined(__NES__) && !defined(__MO5__)
			FREEZE_IMAGE._imageData = _POWERUP;
			SUPER_IMAGE._imageData = _POWERUP;
		#else
			FREEZE_IMAGE._imageData = _FREEZE;
			SUPER_IMAGE._imageData = _SUPER;
		#endif
		
		EXTRA_LIFE_IMAGE._imageData = _EXTRA_LIFE;
		INVINCIBILITY_IMAGE._imageData = _INVINCIBILITY;
        
        #if defined(NO_BLINKING) && defined(_CONFUSE) && defined(_ZOMBIE)
            CONFUSE_IMAGE._imageData = _CONFUSE;
            ZOMBIE_IMAGE._imageData = _ZOMBIE;
        #else
            CONFUSE_IMAGE._imageData = _SKULL;
            ZOMBIE_IMAGE._imageData = _GHOST;
        #endif
		
		BROKEN_BRICK_IMAGE._imageData = _BROKEN_BRICK;
	#endif
#endif 
}



