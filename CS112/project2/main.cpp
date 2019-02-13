/*
 * OpenGL demonstration program for UCI ICS Computer Graphics courses
 * main.cpp,v 2.2 2016/10/05 11:38 pm
 *
 */

#include "sceneModule.h"
#include "inputModule.h"

#include <iostream>
#include "my_gl.h"
#include "i_my_gl.h"
#include <iostream>

#define IMAGE_WIDTH  512
#define IMAGE_HEIGHT 512

int window;

GLfloat fieldOfView;
GLfloat aspect;
GLfloat nearPlane;
GLfloat farPlane;

void printMat(GLfloat* mat)
{   
	std::cout << "{ ";
	for (int i = 0; i < 16; ++i)
		std::cout << mat[i] << " ";
	std::cout << " }\n";
}

bool compareMat(GLfloat* mat1, GLfloat* mat2)
{
	int right = 0;
	for (int i = 0; i < 16; ++i)
		if (mat1[i] == mat2[i])
			right++;
		else
			break;
	if (right == 15)
		return true;
	return false;
}	


//##########################################
// Init display settings

void initDisplay( ){
  /* Perspective projection parameters */
	
  fieldOfView = 45.0;
  aspect = (float)IMAGE_WIDTH/IMAGE_HEIGHT;
  nearPlane   = 0.1;
  farPlane    = 50.0;

  /* setup context */
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  gluPerspective( fieldOfView, aspect, nearPlane, farPlane );

  glEnable( GL_DEPTH_TEST );
  glDisable( GL_CULL_FACE );

  glClearColor( 0.0, 0.0, 0.0, 1.0 );
  glClearDepth( 1 );

  glMatrixMode( GL_MODELVIEW );

  GLfloat tempmatrix[16] = { 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };
  GLfloat newmatrix[16] = { 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };
  glPushMatrix();
  glTranslated(2, 2, 2);
  glGetFloatv(GL_MODELVIEW_MATRIX, tempmatrix);
  glPopMatrix();

  my_glTranslated(2, 2, 2);
  I_my_glGetMatrixf(newmatrix);
  printMat(newmatrix);
  printMat(tempmatrix);
  if (compareMat(newmatrix, tempmatrix))
	  std::cout << "Matrix is wrong\n";

  glPushMatrix();
  glRotated(90, 2, 2, 2);
  glGetFloatv(GL_MODELVIEW_MATRIX, tempmatrix);
  glPopMatrix();

  my_glRotated(90, 2, 2, 2);
  I_my_glGetMatrixf(newmatrix);
  printMat(newmatrix);
  printMat(tempmatrix);
  if (compareMat(newmatrix, tempmatrix))
	  std::cout << "Matrix is wrong\n";

  glPushMatrix();
  glScaled(2, 2, 2);
  glGetFloatv(GL_MODELVIEW_MATRIX, tempmatrix);
  glPopMatrix();

  my_glScaled(2, 2, 2);
  I_my_glGetMatrixf(newmatrix);
  printMat(newmatrix);
  printMat(tempmatrix);
  if (compareMat(newmatrix, tempmatrix))
	  std::cout << "Matrix is wrong\n";

  glPushMatrix();
  printMat(newmatrix);
  my_glLoadIdentity();
  I_my_glGetMatrixf(newmatrix);
  printMat(newmatrix);
  if (compareMat(newmatrix, tempmatrix))
	  std::cout << "Matrix is wrong\n";

  glPushMatrix();
  glFrustum(5, 5, 5, 5, 10, 20);
  glGetFloatv(GL_MODELVIEW_MATRIX, tempmatrix);
  glPopMatrix();

  my_glFrustum(5, 5, 5, 5, 10, 20);
  I_my_glGetMatrixf(newmatrix);
  printMat(newmatrix);
  printMat(tempmatrix);
  if (compareMat(newmatrix, tempmatrix))
	  std::cout << "Matrix is wrong\n";

  glPushMatrix();
  gluPerspective(90, 2, 10, 20);
  glGetFloatv(GL_MODELVIEW_MATRIX, tempmatrix);
  glPopMatrix();

  my_gluPerspective(90, 2, 10, 20);
  I_my_glGetMatrixf(newmatrix);
  printMat(newmatrix);
  printMat(tempmatrix);
  if (compareMat(newmatrix, tempmatrix))
	  std::cout << "Matrix is wrong\n";


}


//##########################################
// Main function

int main( int argc, char **argv ){

  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB |
                       GLUT_DEPTH | GLUT_MULTISAMPLE );

  glutInitWindowSize( IMAGE_WIDTH,IMAGE_HEIGHT );

  glutInitWindowPosition(100,120);
  window = glutCreateWindow("Assignment 2");

  /* Register the appropriate callback functions with GLUT */
  glutDisplayFunc( display );
  glutKeyboardFunc( readKeyboard );
  glutMouseFunc( mouseButtHandler );
  glutMotionFunc( mouseMoveHandler );
  glutPassiveMotionFunc( mouseMoveHandler );

  glutIdleFunc(display);

  initDisplay( );
  glutMainLoop( );

  return( 0 );
}
