#include <nds.h>
#include <stdio.h>
#include "System.h"
#include "Sprite.h"

int main(void) {
	
	LoadRam();
	LoadVideo();
	LoadOam();

	while(1) {

		swiWaitForVBlank();
		scanKeys();
	}

}
