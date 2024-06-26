#ifndef DEF_H
#define DEF_H

//#ifdef __cplusplus
//extern "C" {
//#endif

#ifdef TRUE
#undef TRUE
#endif

#ifdef FALSE
#undef FALSE
#endif

#define TRUE -1
#define FALSE 0
typedef int bool;

typedef signed char Sint3;
typedef unsigned char Uint3;
typedef signed short int Sint4;
typedef unsigned short int Uint4;
typedef signed int Sint;
typedef unsigned int Uint;
typedef signed long int Sint5;
typedef unsigned long int Uint5;

#define DIR_NONE  -1
#define DIR_RIGHT 0
#define DIR_UP    2
#define DIR_LEFT  4
#define DIR_DOWN  6

#define TYPES 5

#define BONUSES 1
#define BAGS 7
#define MONSTERS 6
#define FIREBALLS DIGGERS
#define DIGGERS 2
#define SPRITES (BONUSES+BAGS+MONSTERS+FIREBALLS+DIGGERS)

/* Sprite order is figured out here. By LAST I mean last+1. */

#define FIRSTBONUS 0
#define LASTBONUS (FIRSTBONUS+BONUSES)
#define FIRSTBAG LASTBONUS
#define LASTBAG (FIRSTBAG+BAGS)
#define FIRSTMONSTER LASTBAG
#define LASTMONSTER (FIRSTMONSTER+MONSTERS)
#define FIRSTFIREBALL LASTMONSTER
#define LASTFIREBALL (FIRSTFIREBALL+FIREBALLS)
#define FIRSTDIGGER LASTFIREBALL
#define LASTDIGGER (FIRSTDIGGER+DIGGERS)

#define MWIDTH 15
#define MHEIGHT 10
#define MSIZE MWIDTH*MHEIGHT

#define MAX_REC_BUFFER 262144l
/* I reckon this is enough for about 36 hours of continuous play. */

#define INI_GAME_SETTINGS "Game"
#define INI_GRAPHICS_SETTINGS "Graphics"
#define INI_SOUND_SETTINGS "Sound"
#if defined _WIN32 || defined _WIN64
#define INI_KEY_SETTINGS "Win Keys"
#else
#define INI_KEY_SETTINGS "Keys"
#endif

#if defined _WIN32 || defined _WIN64
#if defined USE_SDL
#define DEFAULT_SPEED_FACTOR 20 // _DEBUG only
#endif
#define DEFAULT_BUFFER 2048
#define DEF_SND_DEV 1
#else
#define DEFAULT_BUFFER 128
#ifdef ARM
#define DEF_SND_DEV 1
#else
#define DEF_SND_DEV 0
#endif
#endif

#if !defined (_MSVC) && defined (WIN32)
#define _int64 LARGE_INTEGER
#endif

#ifdef WIN32
 #if defined (RUNTIMEDYNAMICLINK) && !defined (DIRECTX)
  #define DIRECTX
 #endif
#else
 #ifdef DIRECTX
  #undef DIRECTX
 #endif
 #ifdef RUNTIMEDYNAMICLINK
  #undef RUNTIMEDYNAMICLINK
 #endif
 #if defined (_WINDOWS)
  #ifndef WIN16
   #define WIN16
  #endif
  #ifdef _MSVC
   #define farmalloc _fmalloc
   #define farfree _ffree
  #endif
 #endif 
#endif

// *TODO* improve supported platform specification
#if defined ARM || \
	  (defined _WIN32 || defined _WIN64) || \
		defined UNIX
#define FLATFILE
#endif

#ifdef FLATFILE
#define near
#define far
#define huge
#define farmalloc malloc
#define farfree free
#define farcoreleft coreleft
#endif

#ifdef ARM
#define ININAME "Digger:Settings"
#elif defined FREEBSD && defined _VGL
/* Applications using FreeBSD's console graphics running as root */
#define ININAME "/var/games/digger/digger.rc"
#elif defined UNIX && !defined _VGL
/* While SDL and other X11 related apps could be runned as ordinary user */
#ifdef FREEBSD
#include <sys/syslimits.h>
#else /* I donno what is analog of PATH_MAX for Linux :( */
#define PATH_MAX 1024
#endif
#define ININAME strncat(strncpy(malloc(PATH_MAX),getenv("HOME"),PATH_MAX),"/.digger.rc",PATH_MAX)
#else
#define ININAME "DIGGER.INI"
#endif

#if defined FREEBSD || defined LINUX
#include "fbsd_sup.h"
#endif

#ifdef UNIX
#define stricmp(x, y) strcasecmp(x, y)
#define strnicmp(x, y, z) strncasecmp(x, y, z)
#endif

#if defined _WINDOWS
#define DIGGER_VERSION "TD WIN 19990707"
#elif defined ARM
#define DIGGER_VERSION "JB ARM 19990320"
#elif defined _VGL
#define DIGGER_VERSION "MS FBSD 20000407"
#elif defined USE_SDL
#define DIGGER_VERSION "MS SDL 20000407"
#else
#define DIGGER_VERSION "AJ DOS 19990506"
#endif

/* Version string:
  First word: your initials if you have changed anything.
  Second word: platform.
  Third word: compilation date in yyyymmdd format. */

#endif /* DEF_H */
