#include "Sprite.h"

sprite::sprite(int snum)
{
	spritenum=snum;
	Mosaic=false;
	Vflip=false;
	Hflip=false;
	Hide=false;
	DoubleSize=false;	
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
			oamSet(&oamMain,spritenum,x,y,0,paletteNum,spriteSize,spriteColor,gfx,-1,DoubleSize,Hide,Hflip,Vflip,Mosaic);
			break;
		case false:
			oamSet(&oamSub,spritenum,x,y,0,paletteNum,spriteSize,spriteColor,gfx,-1,DoubleSize,Hide,Hflip,Vflip,Mosaic);
			break;
	}
};
void sprite::setMosaic(bool mosaic)
{
	Mosaic = mosaic;
};
void sprite::VerticalFlip(bool vflip)
{
	Vflip = vflip;
};
void sprite::HorizontalFlip(bool hflip)
{
	Hflip=hflip;
};
void sprite::Hide(bool SHW)
{
	Hide=SHW;
};
