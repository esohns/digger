#ifndef MAIN_H
#define MAIN_H

//#ifdef __cplusplus
//extern "C" {
//#endif

#include "def.h"

#if defined _WIN32 || defined _WIN64
void do_windows_events(void);
#endif

Sint4 getlevch(Sint4 bp6,Sint4 bp8,Sint4 bpa);
void incpenalty(void);
Sint4 levplan(void);
Sint4 levof10(void);
void setdead(bool df);
void cleartopline(void);
void finish(void);
Sint4 randno(Sint4 n);
void game(void);
void maininit(void);
int mainprog(void);

extern Sint4 nplayers,diggers,curplayer,startlev;
extern bool levfflag;
extern char levfname[];
extern char pldispbuf[];
extern Sint5 randv;
extern Sint3 leveldat[8][10][15];
extern int gtime;
extern bool gauntlet,timeout,synchvid,unlimlives;

//#ifdef __cplusplus
//}
//#endif

#endif /* MAIN_H */
