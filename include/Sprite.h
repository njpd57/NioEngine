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

	public:
		sprite(int snum);
		void SizeAndFormat(SpriteSize size,SpriteColorFormat color);       	    void setTiles(const void* tiles,uint32 size,int palette);
		void setXY(int sx,int sy);
		void loadGfx(bool onMain,int size);
		void Update();



};

#endif

