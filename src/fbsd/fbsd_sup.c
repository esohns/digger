
//#include <ctype.h>

#include "fbsd_sup.h"

#include "def.h"
#include "hardware.h"

#if 0
void strupr(char* str)
{
	while (*str != 0) {
		*str = toupper(*str);
		str++;
	}
}
#endif

void catcher(int num) {
	fprintf(stderr, "Signal %d catched, exitting\n", num);
	graphicsoff();
	restorekeyb();
	exit(0);
}
	

