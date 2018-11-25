#include "Sprite.h"

sprite::sprite(int snum)
{
	spritenum=snum;	
};


void sprite::SizeAndFormat(SpriteSize size,SpriteColorFormat color)
{
	spriteSize=size;
	spriteColor=color;
};

void sprite::setTiles(const void* tiles,uint32 size,int palette)
{
	spriteTiles=tiles;
	TileSize=size;
	paletteNum=palette;
};
void sprite::setXY(int sx,int sy)
{
	x=sx;
	y=sy;
};
void sprite::loadGfx(bool onMain,int size)
{
	switch(onMain)
	{
		case true:
			Main=true;
			gfx=oamAllocateGfx(&oamMain,spriteSize,spriteColor);
			for(int i=0; i < size * size /2;i++)
			{
				gfx[i]=1| (1<<8);
			}
			break;

		case false:
			Main=false;
			gfx=oamAllocateGfx(&oamSub,spriteSize,spriteColor);
			for(int i=0; i < size * size /2;i++)
			{
				gfx[i]=1| (1<<8);
			}
			break;
	}
};

void sprite::Update()
{
	switch (Main)
	{
		case true:
			oamSet(&oamMain,spritenum,x,y,0,paletteNum,spriteSize,spriteColor,gfx,-1,false,false,false,false,false);
			break;
		case false:
			oamSet(&oamSub,spritenum,x,y,0,paletteNum,spriteSize,spriteColor,gfx,-1,false,false,false,false,false);
			break;
	}
}
