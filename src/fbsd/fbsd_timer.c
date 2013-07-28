#include <stdlib.h>
//#include <errno.h>
#include <time.h>

// *TODO* improve supported platform specification
#if defined _WIN32 || defined _WIN64
#include <WinSock.h>
#elif defined FREEBSD
#include <sys/time.h>
#include <sys/fbio.h>
#include <sys/consio.h>
#endif

#ifdef _VGL
#include <vgl.h>
#endif

#include "def.h"
#include "fbsd_sup.h"

extern Uint5 ftime;
long int account = 0;
long int slept = 0;
int i = 0;

struct timeval* prev = NULL;

void
inittimer(void)
{
	FIXME("inittimer called");
}

Sint5
getlrt(void)
{
	FIXME("getlrt called");
	return(0);
}

#ifdef _VGL
Uint5
gethrt(void)
{
	long int diff;
	int was_error;
	struct timeval curr;
	struct timespec timer, elapsed;

	VGLCheckSwitch();
	/* Speed controlling stuff */
	if (prev == NULL) {
		prev = malloc(sizeof (struct timeval));
		gettimeofday(prev, NULL);
	} else {
		gettimeofday(&curr, NULL);
		diff = (ftime - (curr.tv_sec - prev->tv_sec)*1000000 - (curr.tv_usec - prev->tv_usec)) * 1000;
		if (diff > 0) {
			timer.tv_sec = 0;
			timer.tv_nsec = diff;
			do {
				errno = 0;
				was_error = nanosleep(&timer, &elapsed);
				timer.tv_sec -= elapsed.tv_sec;
				timer.tv_nsec -= elapsed.tv_nsec;
			} while( was_error && (errno == EINTR) );
		}
		gettimeofday(&curr, NULL);
		memcpy(prev, &curr, (sizeof (struct timeval)));
	}
	return(0);
}
#endif /* _VGL */

Sint5
getkips(void)
{
	FIXME("getkips called");
	return(0);
}

void
s0initint8(void)
{
	FIXME("s0initint8 called");
}

void
s0restoreint8(void)
{
	FIXME("s0restoreint8 called");
}

void
s1initint8(void)
{
	FIXME("s1initint8 called");
}

void
s1restoreint8(void)
{
	FIXME("s1restoreint8 called");
}

void
s0soundoff(void)
{
	FIXME("s0soundoff called");
}

void
s0setspkrt2(void)
{
	FIXME("s0setspkrt2 called");
}

void
s0settimer0(Sint4 t0v)
{
	FIXME("s0settimer0 called");
}

void
s0settimer2(Sint4 t0v)
{
	FIXME("s0settimer2 called");
}

void
s0timer0(Sint4 t0v)
{
	FIXME("s0timer0 called");
}

void
s0timer2(Sint4 t0v)
{
	FIXME("s0timer2 called");
}

void
s0soundkillglob(void)
{
/* No-op */
}
