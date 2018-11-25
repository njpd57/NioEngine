#include <nds.h>
#include "System.h"

void LoadRam()
{
	vramSetBankA(VRAM_A_MAIN_SPRITE);
	vramSetBankB(VRAM_B_MAIN_BG);
	vramSetBankC(VRAM_C_SUB_BG);
	vramSetBankD(VRAM_D_SUB_SPRITE);
}
void LoadVideo()
{
	videoSetMode(MODE_5_2D);
	videoSetModeSub(MODE_5_2D);
}
void LoadOam()
{
	oamInit(&oamMain,SpriteMapping_1D_32,false);	
	oamInit(&oamSub,SpriteMapping_1D_32,false);	
}

#include <nds.h>
#include "System.h"

int mapx=0;
int mapy=0;


void LoadBg(int layer, BgType type,BgSize bgsize, int mapBase, int tileBase,bool main,const void* source,void* dest,uint32 Tilesize,const void*sourcePal,uint32 PalSize)
{
    if(main)
    {
        int LOADBG=bgInit(layer,type,bgsize,mapBase,tileBase);
        dmaCopy(source,dest,Tilesize);
        dmaCopy(sourcePal,BG_PALETTE,PalSize);
    }
    if(!main)
    {
        int LOADBG=bgInitSub(layer,type,bgsize,mapBase,tileBase);
        dmaCopy(source,dest,Tilesize);
        dmaCopy(sourcePal,BG_PALETTE_SUB,PalSize);
    }
}

void LoadMap(
            int LOADMAP,
            int layer, BgType type,BgSize bgsize, int mapBase, int tileBase, //BGINIT
            bool main,
            const void* sourceTiles,uint32 sourceTilesLen,
            const void* sourcePal,uint32 sourcePalLen,
            const void* sourceMap,uint32 sourceMapLen)
{
    if(main)
    {
        LOADMAP=bgInit(layer,type,bgsize,mapBase,tileBase);
        dmaCopy(sourceTiles,bgGetGfxPtr(LOADMAP),sourceTilesLen);
        dmaCopy(sourceMap,bgGetMapPtr(LOADMAP),sourceMapLen);
        dmaCopy(sourcePal,BG_PALETTE,sourcePalLen);
    }
    if(!main)
    {
        LOADMAP=bgInitSub(layer,type,bgsize,mapBase,tileBase);
        dmaCopy(sourceTiles,bgGetGfxPtr(LOADMAP),sourceTilesLen);
        dmaCopy(sourceMap,bgGetMapPtr(LOADMAP),sourceMapLen);
        dmaCopy(sourcePal,BG_PALETTE_SUB,sourcePalLen);
    }
}



void setStartXY(int startx,int starty)
{
    mapx=startx;
    mapy=starty;
}

void Input(int id, int width, int height,int PlayerX,int PlayerY)
{
    int keys=keysCurrent();
    if(keys & KEY_A);
    if(keys & KEY_UP){
        PlayerY--;
        mapy--;
    }
    if(keys & KEY_DOWN){
        PlayerY++;
        mapy++;
    }
    if(keys & KEY_LEFT){
        PlayerX--;
        mapx--;
    }
    if(keys & KEY_RIGHT){
        PlayerX++;
        mapx++;
    }
    if(mapx < 0) mapx = 0;
    if(mapx >= width - 256) mapx = width - 1 - 256;
    if(mapy < 0) mapy = 0;
    if(mapy >= height - 192) mapy = height - 1 - 192;
    bgSetScroll(id, mapx, mapy);
}

int Returnmapx()
{
    return mapx;
}

int Returnmapy()
{
    return mapy;
}