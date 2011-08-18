#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <string.h>
#include "func.h"

pscr_t p_v;

int init_data(void)
{
	int p = 0;
	struct fb_var_screeninfo p_var;

	p = open("/dev/fb0",O_RDWR);

	if (p < 0)
	{
		perror("open fb0");
		exit(0);
	}

	if (ioctl(p,FBIOGET_VSCREENINFO,&p_var) < 0)
	{
		perror("ioctl");
		exit(0);
	}

	printf("w = %d\t  h = %d\t  bpp = %d\t\n",p_var.xres,p_var.yres,p_var.bits_per_pixel);

	p_v.w = p_var.xres;
	p_v.h = p_var.yres;
	p_v.bpp = p_var.bits_per_pixel;
	p_v.memo = mmap(NULL,p_v.w*p_v.h*p_v.bpp/8,PROT_READ|PROT_WRITE,MAP_SHARED,p,0);

	if (p_v.memo == MAP_FAILED)
	{
		perror("map");
		exit(0);
	}
	
	memset(p_v.memo,0,p_v.w*p_v.h*p_v.bpp/8);
/*
	int i;
	u32_t *P = p_v.memo;

	for (i = 0; i < p_v.w; i++)
	{
		P[i+5] = 0x0065c294;
	}

	for (i = 0; i <p_v.h;i++)
	{
		P[i*p_v.w+5] = 0x00ff0000;
	}
*/
	return 0;
}
