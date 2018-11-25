#include <nds.h>
#ifndef SPRITE_H
#define SPRITE_H
class sprite
{
	private:
		u16* gfx;
		int x;
		int y;
		
		SpriteSize spriteSize;
		SpriteColorFormat spriteColor;

		const void* spriteTiles;
		uint32 TileSize;

		int paletteNum;
		int spritenum;

		bool Main;
		bool Mosaic;
		bool Vflip;
		bool Hflip;
		bool Hide;
		bool DoubleSize;

	public:
		sprite(int snum);
		void SizeAndFormat(SpriteSize size,SpriteColorFormat color);
		void setTiles(const void* tiles,uint32 size,int palette);
		void setMosaic(bool mosaic);
		void VerticalFlip(bool vflip);
		void HorizontalFlip(bool hflip);
		void Hide(bool SHW);
		void setXY(int sx,int sy);
		void loadGfx(bool onMain,int size);
		void Update();



};

#endif

