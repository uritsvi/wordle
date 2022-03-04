#include <stdio.h>
#include <stddef.h>

#include "letters_textures.h"

struct letterTexture A_LETTER = { .placeInFontTexture = {.xMin = 0.0f , .xMax = 0.12f , .yMin = 0.84f , .yMax = 1.0f } };
struct letterTexture B_LETTER = { .placeInFontTexture = {.xMin = 0.12f , .xMax = 0.22f , .yMin = 0.84f , .yMax = 1.0f }};
struct letterTexture C_LETTER = { .placeInFontTexture = {.xMin = 0.22f , .xMax = 0.32f , .yMin = 0.84f , .yMax = 1.0f }};
struct letterTexture D_LETTER = { .placeInFontTexture = {.xMin = 0.32f , .xMax = 0.44f , .yMin = 0.84f , .yMax = 1.0f }};
struct letterTexture E_LETTER = { .placeInFontTexture = {.xMin = 0.44f , .xMax = 0.54f , .yMin = 0.84f , .yMax = 1.0f }};
struct letterTexture F_LETTER = { .placeInFontTexture = {.xMin = 0.54f , .xMax = 0.62f , .yMin = 0.84f , .yMax = 1.0f }};
struct letterTexture G_LETTER = { .placeInFontTexture = {.xMin = 0.62f , .xMax = 0.74f , .yMin = 0.84f , .yMax = 1.0f }};
struct letterTexture H_LETTER = { .placeInFontTexture = {.xMin = 0.74f , .xMax = 0.84f , .yMin = 0.84f , .yMax = 1.0f }};
struct letterTexture I_LETTER = { .placeInFontTexture = {.xMin = 0.84f , .xMax = 0.92f , .yMin = 0.84f , .yMax = 1.0f }};
struct letterTexture J_LETTER = { .placeInFontTexture = {.xMin = 0.9f , .xMax = 1.0f , .yMin = 0.84f , .yMax = 1.0f }};
struct letterTexture K_LETTER = { .placeInFontTexture = {.xMin = 0.0f , .xMax = 0.1f , .yMin = 0.56f , .yMax = 0.72f}};
struct letterTexture L_LETTER = { .placeInFontTexture = {.xMin = 0.1f , .xMax = 0.2f , .yMin = 0.56f , .yMax = 0.72f}};
struct letterTexture M_LETTER = { .placeInFontTexture = {.xMin = 0.2f , .xMax = 0.34f , .yMin = 0.56f , .yMax = 0.72f}};
struct letterTexture N_LETTER = { .placeInFontTexture = {.xMin = 0.34f , .xMax = 0.45f , .yMin = 0.56f , .yMax = 0.72f}};
struct letterTexture O_LETTER = { .placeInFontTexture = {.xMin = 0.45f , .xMax = 0.57f , .yMin = 0.56f , .yMax = 0.72f}};
struct letterTexture P_LETTER = { .placeInFontTexture = {.xMin = 0.57f , .xMax = 0.68f , .yMin = 0.56f , .yMax = 0.72f}};
struct letterTexture Q_LETTER = { .placeInFontTexture = {.xMin = 0.68f , .xMax = 0.8f , .yMin = 0.56f , .yMax = 0.72f}};
struct letterTexture R_LETTER = { .placeInFontTexture = {.xMin = 0.8f , .xMax = 0.91f , .yMin = 0.56f , .yMax = 0.72f}};
struct letterTexture S_LETTER = { .placeInFontTexture = {.xMin = 0.91f , .xMax = 1.0f , .yMin = 0.56f , .yMax = 0.72f}};
struct letterTexture T_LETTER = { .placeInFontTexture = {.xMin = 0.0f , .xMax = 0.1f , .yMin = 0.28f , .yMax = 0.44f}};
struct letterTexture U_LETTER = { .placeInFontTexture = {.xMin = 0.1f , .xMax = 0.2f , .yMin = 0.28f , .yMax = 0.44f}};
struct letterTexture V_LETTER = { .placeInFontTexture = {.xMin = 0.2f , .xMax = 0.3f , .yMin = 0.28f , .yMax = 0.44f}};
struct letterTexture W_LETTER = { .placeInFontTexture = {.xMin = 0.31f , .xMax = 0.46f , .yMin = 0.28f , .yMax = 0.44f}};
struct letterTexture X_LETTER = { .placeInFontTexture = {.xMin = 0.46f , .xMax = 0.56f , .yMin = 0.28f , .yMax = 0.44f}};
struct letterTexture Y_LETTER = { .placeInFontTexture = {.xMin = 0.58f , .xMax = 0.68f , .yMin = 0.28f , .yMax = 0.44f}};
struct letterTexture Z_LETTER = { .placeInFontTexture = {.xMin = 0.69f , .xMax = 0.79f , .yMin = 0.28f , .yMax = 0.44f}};
struct letterTexture UN_KNOWN_LETTER = { .placeInFontTexture = {.xMin = 0.0f , .xMax = 0.0f , .yMin = 0.0f , .yMax = 0.0f} };

struct letterTexture get_letter_texture(char c)
{
	switch (c)
	{
	    case 'A': return A_LETTER; break;
		case 'B': return B_LETTER; break;
		case 'C': return C_LETTER; break;
		case 'D': return D_LETTER; break;
		case 'E': return E_LETTER; break;
		case 'F': return F_LETTER; break;
		case 'G': return G_LETTER; break;
		case 'H': return H_LETTER; break;
		case 'I': return I_LETTER; break;
		case 'J': return J_LETTER; break;
		case 'K': return K_LETTER; break;	
		case 'L': return L_LETTER; break;
		case 'M': return M_LETTER; break;
		case 'N': return N_LETTER; break;
		case 'O': return O_LETTER; break;
		case 'P': return P_LETTER; break;
		case 'Q': return Q_LETTER; break;
		case 'R': return R_LETTER; break;
		case 'S': return S_LETTER; break;
		case 'T': return T_LETTER; break;
		case 'U': return U_LETTER; break;
		case 'V': return V_LETTER; break;
		case 'W': return W_LETTER; break;
		case 'X': return X_LETTER; break;
		case 'Y': return Y_LETTER; break;
		case 'Z': return Z_LETTER; break;	  
		
		case 'a': return A_LETTER; break;
		case 'b': return B_LETTER; break;
		case 'c': return C_LETTER; break;
		case 'd': return D_LETTER; break;
		case 'e': return E_LETTER; break;
		case 'f': return F_LETTER; break;
		case 'g': return G_LETTER; break;
		case 'h': return H_LETTER; break;
		case 'i': return I_LETTER; break;
		case 'j': return J_LETTER; break;
		case 'k': return K_LETTER; break;	
		case 'l': return L_LETTER; break;
		case 'm': return M_LETTER; break;
		case 'n': return N_LETTER; break;
		case 'o': return O_LETTER; break;
		case 'p': return P_LETTER; break;
		case 'q': return Q_LETTER; break;
		case 'r': return R_LETTER; break;
		case 's': return S_LETTER; break;
		case 't': return T_LETTER; break;
		case 'u': return U_LETTER; break;
		case 'v': return V_LETTER; break;
		case 'w': return W_LETTER; break;
		case 'x': return X_LETTER; break;
		case 'y': return Y_LETTER; break;
		case 'z': return Z_LETTER; break;


		default:
			return UN_KNOWN_LETTER;
			break;
	}
}