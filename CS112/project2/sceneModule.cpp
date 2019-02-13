/*
 * OpenGL demonstration program for UCI ICS Computer Graphics courses
 * sceneModule.cpp,v 2.2 2016/10/05 11:38 pm
 *
 */

#include "sceneModule.h"
#include "my_gl.h"
#include <math.h>

GLfloat angley = 20;    /* in degrees */
GLfloat anglex = 30;   /* in degrees */
GLfloat distanceX = 0.0;
GLfloat distanceY = 0.0;
GLfloat distanceZ = 5.0;
GLfloat count = .025;
GLfloat time = .001;

#define PI 3.14159265359

static float cubeColors[6][4] =
{
  {0.8, 0.8, 0.8, 1.0},
  {0.8, 0.0, 0.0, 1.0},
  {0.0, 0.8, 0.0, 1.0},
  {0.0, 0.0, 0.8, 1.0},
  {0.0, 0.8, 0.8, 1.0},
  {0.8, 0.0, 0.8, 1.0},
};

static float cubeVertexes[6][4][4] =
{
  {
    {-1.0, -1.0, -1.0, 1.0},
    {-1.0, -1.0, 1.0, 1.0},
    {-1.0, 1.0, 1.0, 1.0},
    {-1.0, 1.0, -1.0, 1.0}},

  {
    {1.0, 1.0, 1.0, 1.0},
    {1.0, -1.0, 1.0, 1.0},
    {1.0, -1.0, -1.0, 1.0},
    {1.0, 1.0, -1.0, 1.0}},

  {
    {-1.0, -1.0, -1.0, 1.0},
    {1.0, -1.0, -1.0, 1.0},
    {1.0, -1.0, 1.0, 1.0},
    {-1.0, -1.0, 1.0, 1.0}},

  {
    {1.0, 1.0, 1.0, 1.0},
    {1.0, 1.0, -1.0, 1.0},
    {-1.0, 1.0, -1.0, 1.0},
    {-1.0, 1.0, 1.0, 1.0}},

  {
    {-1.0, -1.0, -1.0, 1.0},
    {-1.0, 1.0, -1.0, 1.0},
    {1.0, 1.0, -1.0, 1.0},
    {1.0, -1.0, -1.0, 1.0}},

  {
    {1.0, 1.0, 1.0, 1.0},
    {-1.0, 1.0, 1.0, 1.0},
    {-1.0, -1.0, 1.0, 1.0},
    {1.0, -1.0, 1.0, 1.0}}
};

void drawScene(){

  for (int i = 0; i < 6; i++) {
    glBegin(GL_POLYGON);
		glColor3fv(&cubeColors[i][0]);
		glVertex4fv(&cubeVertexes[i][0][0]);
		glVertex4fv(&cubeVertexes[i][1][0]);
		glVertex4fv(&cubeVertexes[i][2][0]);
		glVertex4fv(&cubeVertexes[i][3][0]);
    glEnd();
  }
}

void sceneTransformation(){
  glLoadIdentity( );

  //glTranslatef(-distanceX, distanceY, -distanceZ);
  //glRotatef( anglex, 1.0, 0.0, 0.0 );
  //glRotatef( angley, 0.0, 1.0, 0.0 );

  gluLookAt(-sin((PI / 180)*angley)*cos((PI/180)*anglex)*distanceZ, 
	  sin((PI/180)*anglex)*distanceZ, 
	  cos((PI/180)*anglex)*cos((PI/180)*angley)*distanceZ,
	  0, 0, 0, 0, 
	  cos((PI/180)*anglex), 0);
	  
  //gluLookAt(eyeX, eyeY, eyeZ, atX, atY, atZ, upX, upY, upZ);
}

void display(){
  /*glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  // Sets up transformation.
  sceneTransformation();
  // Draws the scene into the back buffer.
  //drawScene();
  my_glPushMatrix();
  my_glTranslated(0, 0, -10);
  my_glRotated(2* count, 0,1,0);
  drawScene();
  my_glPopMatrix();
  my_glPushMatrix();
  my_glTranslated(2*sin(time),0 , -10+2*cos(time));
  my_glRotated(2*count, 0, 1, 0);
  my_glScaled(.5,.5,.5);
  drawScene();
  my_glPopMatrix();
  // Swaps the front buffer with the back buffer - assumes double buffering.
  glutSwapBuffers();
  count+= .025;
  time += .000875;*/

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Sets up transformation.
	sceneTransformation();
	// Draws the scene into the back buffer.
	drawScene();
	// Swaps the front buffer with the back buffer - assumes double buffering.
	glutSwapBuffers();
}