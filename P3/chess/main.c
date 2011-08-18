#include <stdio.h>
#include "func.h"
#include "various.h"

int main(void)
{
	init_data();

	fb_line(300,0,0,p_v.h-1,0x00840228);
	fb_line(p_v.w-1,0,724,p_v.h-1,0x00ffce7b);
	fb_line(300,0,724,p_v.h-1,0x0033a3dc);
	fb_line(p_v.w-1,0,p_v.w-1,p_v.h-1,0x00f36c21);
	fb_line(0,p_v.h-1,p_v.w-1,p_v.h-1,0x00c1a173);
	fb_line(0,p_v.h-1,p_v.w-1,0,0x00a11e25);

	fb_circle(p_v.w/2,p_v.h/2,100,0x00280537);
	return 0;
}
