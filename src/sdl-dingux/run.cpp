
// Run module
#include <SDL/SDL.h>

#include "burner.h"
#include "snd.h"
#include "font.h"

#include "sdl_run.h"
#include "sdl_video.h"
#include "sdl_input.h"
extern char* blit_fun_name;
extern unsigned int FBA_KEYPAD[4]; // sdlinput.cpp
extern SDL_Surface *screen; //sdl_video.cpp//
bool bShowFPS = false;
int bRunPause = 0;

extern int InpMake(unsigned int[]);
extern bool bInputOk;
extern bool bRotate;
void VideoTrans();

int RunReset()
{
	nFramesEmulated = 0;
	nCurrentFrame = 0;
	nFramesRendered = 0;

	return 0;
}

int RunOneFrame(bool bDraw, int fps)
{
	do_keypad();
	InpMake(FBA_KEYPAD);
	if (!bRunPause)
	{
		nFramesEmulated++;
		nCurrentFrame++;

		pBurnDraw = NULL;
		if ( bDraw )
		{
			nFramesRendered++;
			pBurnDraw = (unsigned char *)BurnVideoBuffer; 
		}

		BurnDrvFrame();

		if ( bDraw )
		{
			VideoTrans();
			if (bShowFPS)
			{
				char buf[11];
				char screenInfo[200];
				int x;
				sprintf(buf, "FPS:%2d/%2d", fps,(nBurnFPS/100));
				sprintf(screenInfo, "screen:%d,%d game:%d,%d %s %s",screen->w,screen->h,VideoBufferWidth,VideoBufferHeight,blit_fun_name,bRotate?"r":"");
				DrawRect((uint16 *) (unsigned short *) &VideoBuffer[0],0, 0, 60, 9, 0,PhysicalBufferWidth);
				DrawString (buf, (unsigned short *) &VideoBuffer[0], 0, 0,PhysicalBufferWidth);
				DrawString (screenInfo, (unsigned short *) &VideoBuffer[0], 64, 0,PhysicalBufferWidth);
			}

			VideoFlip();
		}
	} else {
		DrawString ("PAUSED", (unsigned short *) &VideoBuffer[0], (PhysicalBufferWidth>>1)-24, 120,PhysicalBufferWidth);
		VideoFlip();
	}
	return 0;
}

void ChangeFrameskip()
{
	bShowFPS = !bShowFPS;
	VideoClear();
	nFramesRendered = 0;
}
