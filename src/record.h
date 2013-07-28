#ifndef RECORD_H
#define RECORD_H

//#ifdef __cplusplus
//extern "C" {
//#endif

#include "def.h"

void openplay(char* name);
void recstart(void);
void recname(char* name);
void playgetdir(Sint4* dir, bool* fire);
void recinit(void);
void recputrand(Uint5 randv);
Uint5 playgetrand(void);
void recputinit(char* init);
void recputeol(void);
void recputeog(void);
void playskipeol(void);
void recputdir(Sint4 dir, bool fire);
void recsavedrf(void);

extern bool playing,savedrf,gotname,gotgame,drfvalid,kludge;

//#ifdef __cplusplus
//}
//#endif

#endif /* RECORD_H */
