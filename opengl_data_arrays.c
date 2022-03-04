#include <string.h>

#include "opengl_data_arrays.h"
#include "render_sprites.h"

GLuint VAO, VBO, EBO;

GLfloat vertices[] =
{
	// position              //texture coords
	-1.0f , -1.0f , 0.0f ,   0.0f , 0.0f ,
	1.0f , -1.0f , 0.0f ,    1.0f , 0.0f ,
	1.0f , 1.0f , 0.0f ,     1.0f , 1.0f,
	-1.0f , 1.0f , 0.0f ,    0.0f , 1.0f

};

GLuint indices[] =
{
	0 , 1 , 2 ,
	0 , 3 , 2
};

void init_data_arrays() 
{
	create_VAO();
	create_VBO();
	create_EBO();

	bind_VAO();
	bind_VBO();
	set_VBO_vertices(vertices, sizeof(vertices));

	bind_EBO();
	set_EBO_indices(indices, sizeof(indices));

	VAO_linkAttrib(0, 3, GL_FLOAT, sizeof(float) * 5, (void*)0);
	VAO_linkAttrib(1, 2, GL_FLOAT, sizeof(float) * 5, (void*)(3 * sizeof(float)));
}

void create_VAO()
{
	glGenVertexArrays(1, &VAO);
}

void bind_VAO()
{
	glBindVertexArray(VAO);
}

void  VAO_linkAttrib(GLuint layout, GLuint numComponents, GLuint type, GLsizeiptr stride, void* offset)
{
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
}

void create_VBO()
{
	glGenBuffers(1, &VBO);
}
void bind_VBO()
{
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void set_VBO_vertices(GLfloat* vertices, GLsizeiptr size)
{
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void set_VBO_scale(struct vec2 scale) 
{
	GLfloat newVertices[] =
	{ 
		// position                                                //texture coords
        -1.0f * (scale.x / 100),  -1.0f * (scale.y /100),  0.0f ,  vertices[3],  vertices[4] ,
         1.0f * (scale.x / 100),  -1.0f * (scale.y / 100), 0.0f,   vertices[8],  vertices[9] ,
         1.0f * (scale.x / 100) ,  1.0f * (scale.y/ 100),  0.0f,   vertices[13], vertices[14] ,
        -1.0f * (scale.x / 100) ,  1.0f * (scale.y / 100), 0.0f,   vertices[18], vertices[19]
 	};

	memcpy(vertices, newVertices, sizeof(newVertices));
	set_VBO_vertices(vertices, sizeof(newVertices));
}

void set_VBO_texture_coords(struct minMaxVec2 textureCooords)
{
	GLfloat newVertices[] =
	{
		// position                                    //texture position
		vertices[0] , vertices[1] , vertices[2] ,      textureCooords.xMin , textureCooords.yMin ,
		vertices[5] , vertices[6] , vertices[7] ,      textureCooords.xMax , textureCooords.yMin ,
		vertices[10] , vertices[11] , vertices[12] ,   textureCooords.xMax , textureCooords.yMax ,
		vertices[15] , vertices[16] , vertices[17] ,   textureCooords.xMin , textureCooords.yMax
	};

	memcpy(vertices, newVertices, sizeof(newVertices));
	set_VBO_vertices(vertices, sizeof(newVertices));
}

void get_renderd_object_xMix_xMax(struct minMaxVec2* minMaxVec2 , struct sprite* sprite)
{
	set_VBO_scale(sprite->scale);

	minMaxVec2->xMin = (vertices[0] + (sprite->position.x / 100)) * 100;
    minMaxVec2->xMax = (vertices[5] + (sprite->position.x / 100)) * 100;

	minMaxVec2->yMin = (vertices[1] + (sprite->position.y / 100)) * 100;
	minMaxVec2->yMax = (vertices[11] + (sprite->position.y / 100)) * 100;
}

void create_EBO()
{
	glGenBuffers(1, &EBO);
}

void bind_EBO()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

void set_EBO_indices(GLuint* indices, GLsizeiptr size)
{
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}
