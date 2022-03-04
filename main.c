#include <stdbool.h>

#include "render.h"
#include "game.h"

int main() 
{
	render_init();
	game_init();
	

	while (true)
	{
		render_update();
	}
	
	return 0;
}