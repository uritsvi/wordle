#include "letersTexturesStructs.h"
#include "letter.h"
#include "vec2.h"

void write_later(struct letter leter, struct vec2 position) 
{

}

struct leterTexture get_leter_texture(struct letter letter)
{
	switch (letter.character) 
	{
 	   case 'a' : return A;
	}
}