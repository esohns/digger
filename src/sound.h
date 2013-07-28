#ifndef SOUND_H
#define SOUND_H

//#ifdef __cplusplus
//extern "C" {
//#endif

#include "def.h"

void initsound(void);
void soundstop(void);
void music(Sint4 tune);
void musicoff(void);
void soundlevdone(void);
void sound1up(void);
#if defined _WIN32 || defined _WIN64
void pause_windows_sound_playback(void);
void resume_windows_sound_playback(void);
#endif
void soundpause(void);
void soundpauseoff(void);
void setsoundt2(void);
#if defined _WIN32 || defined _WIN64
void set_sound_volume(int n);
#endif
void sett2val(Sint4 t2v);
void startint8(void);
void stopint8(void);
void soundbonus(void);
void soundbonusoff(void);
void soundfire(int n);
void soundexplode(int n);
void soundfireoff(int n);
void soundem(void);
void soundemerald(int emn);
void soundeatm(void);
void soundddie(void);
void soundwobble(void);
void soundwobbleoff(void);
void soundfall(void);
void soundfalloff(void);
void soundbreak(void);
void soundgold(void);

void soundint(void);

/*
void soundoff(void);
void timer2(Uint4 t2v);
*/


extern bool soundflag,musicflag;
extern Sint4 volume,timerrate;
extern Uint4 timercount;
extern bool wave_device_available;

extern void (*setupsound)(void);
extern void (*killsound)(void);
extern void (*fillbuffer)(void);
extern void (*initint8)(void);
extern void (*restoreint8)(void);
extern void (*soundoff)(void);
extern void (*setspkrt2)(void);
extern void (*settimer0)(Uint4 t0v);
extern void (*timer0)(Uint4 t0v);
extern void (*settimer2)(Uint4 t2v);
extern void (*timer2)(Uint4 t2v);
extern void (*soundkillglob)(void);

//#ifdef __cplusplus
//}
//#endif

#endif /* SOUND_H */
