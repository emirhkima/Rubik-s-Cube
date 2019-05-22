#include <GL/glut.h>
#include <stdlib.h>
#include "ppm.c"


static GLuint texName[7];
GLubyte* white_textureId;
GLubyte* red_textureId;
GLubyte* yellow_textureId;
GLubyte* green_textureId;
GLubyte* blue_textureId;
GLubyte* orange_textureId;
GLubyte* metal_textureId;
int width, height;
float ex=1.5 ,ez=5;
float xRotation = 0.0, yRotation = 0.0;
float zTranslate = -3.0;



void init_texture(void)
{

   white_textureId = glmReadPPM("white.ppm", &width , &height); 
   glGenTextures(1, texName);



   glBindTexture(GL_TEXTURE_2D, texName[0]);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                   GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                white_textureId);

   glEnable(GL_TEXTURE_2D);



}

void affiche_metal(void)
{
  metal_textureId = glmReadPPM("metal.ppm", &width , &height); 
  glGenTextures(1, texName);
  glBindTexture(GL_TEXTURE_2D, texName[6]);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                   GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                metal_textureId);

   glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
    glTexCoord2i(0,0);      
    glVertex3i(-10,-10,-1);
    glTexCoord2i(10,0);     
    glVertex3i(10,-10,-1);
    glTexCoord2i(10,10);    
    glVertex3i(10,10,-1);
    glTexCoord2i(0,10);     
    glVertex3i(-10,10,-1);
    glEnd();


}

void display(void)
{

   glClear (GL_COLOR_BUFFER_BIT);
   glClear (GL_DEPTH_BUFFER_BIT);
   glPushMatrix();
   glEnable(GL_DEPTH_TEST); 
   glLoadIdentity();

    gluLookAt(ex,1.5,ez,0,0,0,-10,-10,0);
	
   xRotation += .5;
   yRotation += .375;
   affiche_metal();
   glRotatef(xRotation, 1, 0, 0);
   glRotatef(yRotation, 0, -0.5, 0); 

   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
//---------------------------------------------------------------------//

   init_texture();
   glTranslatef(-0.5,-0.25,0);
   glBegin(GL_QUADS);
   glTexCoord2f(0.0, 0.0); glVertex3f(0, 0, 0);
   glTexCoord2f(0.0, 3.0); glVertex3f(1, 0, 0);
   glTexCoord2f(3.0, 3.0); glVertex3f(1, 1, 0);
   glTexCoord2f(3.0, 0.0); glVertex3f(0, 1, 0);
   glEnd();

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++// 
  

//-------------------------------------------------------------------//
//Fond rouge
 glBindTexture(GL_TEXTURE_2D, texName[1]);
 red_textureId = glmReadPPM("red.ppm", &width , &height); 
   glGenTextures(1, texName);
   glEnable(GL_TEXTURE_2D);
   
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                   GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                red_textureId);

   

   glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0); glVertex3f (1, 0, 0);
      glTexCoord2f(0.0, 3.0); glVertex3f (1, 0, 1);
      glTexCoord2f(3.0, 3.0); glVertex3f (1, 1, 1);
      glTexCoord2f(3.0, 0.0); glVertex3f (1, 1, 0);
   glEnd();

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

  
//-------------------------------------------------------------------//

//Fond jaune
 glBindTexture(GL_TEXTURE_2D, texName[2]);
yellow_textureId = glmReadPPM("yellow.ppm", &width , &height); 
glGenTextures(1, texName);
glEnable(GL_TEXTURE_2D);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                   GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                yellow_textureId);
  
   glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0); glVertex3f (1, 0, 1);
      glTexCoord2f(0.0, 3.0); glVertex3f (1, 1, 1);
      glTexCoord2f(3.0, 3.0); glVertex3f (0, 1, 1);
      glTexCoord2f(3.0, 0.0); glVertex3f (0, 0, 1);
   glEnd();


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

//-------------------------------------------------------------------//

// Fond Orange

 glBindTexture(GL_TEXTURE_2D, texName[3]);
orange_textureId = glmReadPPM("orange.ppm", &width , &height); 
   glGenTextures(1, texName);
  glEnable(GL_TEXTURE_2D);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                   GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                orange_textureId);


   glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0); glVertex3f (0, 0, 0);
      glTexCoord2f(0.0, 3.0); glVertex3f (0, 0, 1);
      glTexCoord2f(3.0, 3.0); glVertex3f (0, 1, 1);
      glTexCoord2f(3.0, 0.0); glVertex3f (0, 1, 0);
   glEnd();

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
   

//-------------------------------------------------------------------//
  // fond vert

   //glColor3f (0.0, 1.0, 0.0);
 glBindTexture(GL_TEXTURE_2D, texName[4]);
  green_textureId = glmReadPPM("green.ppm", &width , &height); 
   glGenTextures(1, texName);
	
   glEnable(GL_TEXTURE_2D);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                   GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                green_textureId);
   glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0); glVertex3f (0, 0, 0);
      glTexCoord2f(0.0, 3.0); glVertex3f (0, 0, 1);
      glTexCoord2f(3.0, 3.0); glVertex3f (1, 0, 1);
      glTexCoord2f(3.0, 0.0); glVertex3f (1, 0, 0);
   glEnd();



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

//-------------------------------------------------------------------//
  // fond bleu

blue_textureId = glmReadPPM("blue.ppm", &width , &height); 
   glGenTextures(1, texName);

   glBindTexture(GL_TEXTURE_2D, texName[5]);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                   GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                   GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width,
                height, 0, GL_RGB, GL_UNSIGNED_BYTE,
                blue_textureId);

   glEnable(GL_TEXTURE_2D);
   glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0); glVertex3f (0, 1, 0);
      glTexCoord2f(0.0, 3.0); glVertex3f (0, 1, 1);
      glTexCoord2f(3.0, 3.0); glVertex3f (1, 1, 1);
      glTexCoord2f(3.0, 0.0); glVertex3f (1, 1, 0);
   glEnd();


//-------------------------------------------------------------------//

	glFlush();

glPopMatrix();


   glutSwapBuffers();
}




