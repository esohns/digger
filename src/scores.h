#ifndef SCORES_H
#define SCORES_H

//#ifdef __cplusplus
//extern "C" {
//#endif

#include "def.h"

void loadscores(void);
void showtable(void);
void zeroscores(void);
void writecurscore(int col);
void drawscores(void);
void initscores(void);
void endofgame(void);
void scorekill(int n);
void scorekill2(void);
void scoreemerald(int n);
void scoreoctave(int n);
void scoregold(int n);
void scorebonus(int n);
void scoreeatm(int n,int msc);
void addscore(int n,Sint4 score);

#ifdef INTDRF
Sint5 getscore0(void);
#endif

extern Uint4 bonusscore;
extern Sint5 scoret;

extern char scoreinit[11][4];

//#ifdef __cplusplus
//}
//#endif

#endif /* SCORES_H */
