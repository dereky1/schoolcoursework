

#ifdef WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <math.h>
#include <iostream>

// Defines maximum stack capacity.
#define STACK_CAP 16
// Defines pi for converting angles.
#define PI 3.14159265359

// Structure for the matrix stack, top specifies current top position on the stack, initially zero (which means one matrix in the stack).
struct matrix_stack
{
    GLdouble m[STACK_CAP][16];
    int top;
};

// Define a macro for retrieving current matrix from top of current stack.
#define current_matrix (current_stack->m[current_stack->top])

// Identity matrix constant.
const GLdouble identity[16] =
{1, 0, 0, 0,
 0, 1, 0, 0,
 0, 0, 1, 0,
 0, 0, 0, 1};

// The model view matrix stack.
struct matrix_stack model_view = {{{0}}, 0};
// The projection matrix stack.
struct matrix_stack projection = {{{0}}, 0};
// The current stack pointer that specifies the matrix mode.
struct matrix_stack *current_stack = &model_view;

// Multiplies current matrix with matrix b, put the result in current matrix.
// current = current * b
void matrix_multiply(const GLdouble *b)
{
	GLdouble temp[16];
	for(int i=0; i<16; ++i)
		temp[i] = current_matrix[i];

	current_matrix[0] = (temp[0] * b[0]) + (temp[4] * b[1]) + (temp[8] * b[2]) + (temp[12] * b[3]);
	current_matrix[4] = (temp[0] * b[4]) + (temp[4] * b[5]) + (temp[8] * b[6]) + (temp[12] * b[7]);
	current_matrix[8] = (temp[0] * b[8]) + (temp[4] * b[9]) + (temp[8] * b[10]) + (temp[12] * b[11]);
	current_matrix[12] = (temp[0] * b[12]) + (temp[4] * b[13]) + (temp[8] * b[14]) + (temp[12] * b[15]);
		///
	current_matrix[1] = (temp[1] * b[0]) + (temp[5] * b[1]) + (temp[9] * b[2]) + (temp[13] * b[3]);
	current_matrix[5] = (temp[1] * b[4]) + (temp[5] * b[5]) + (temp[9] * b[6]) + (temp[13] * b[7]);
	current_matrix[9] = (temp[1] * b[8]) + (temp[5] * b[9]) + (temp[9] * b[10]) + (temp[13] * b[11]);
	current_matrix[13] = (temp[1] * b[12]) + (temp[5] * b[13]) + (temp[9] * b[14]) + (temp[13] * b[15]);
		///
	current_matrix[2] = (temp[2] * b[0]) + (temp[6] * b[1]) + (temp[10] * b[2]) + (temp[14] * b[3]);
	current_matrix[6] = (temp[2] * b[4]) + (temp[6] * b[5]) + (temp[10] * b[6]) + (temp[14] * b[7]);
	current_matrix[10] = (temp[2] * b[8]) + (temp[6] * b[9]) + (temp[10] * b[10]) + (temp[14] * b[11]);
	current_matrix[14] = (temp[2] * b[12]) + (temp[6] * b[13]) + (temp[10] * b[14]) + (temp[14] * b[15]);
		///
	current_matrix[3] = (temp[3] * b[0]) + (temp[7] * b[1]) + (temp[11] * b[2]) + (temp[15] * b[3]);
	current_matrix[7] = (temp[3] * b[4]) + (temp[7] * b[5]) + (temp[11] * b[6]) + (temp[15] * b[7]);
	current_matrix[11] = (temp[3] * b[8]) + (temp[7] * b[9]) + (temp[11] * b[10]) + (temp[15] * b[11]);
	current_matrix[15] = (temp[3] * b[12]) + (temp[7] * b[13]) + (temp[11] * b[14]) + (temp[15] * b[15]);	
}

// Calculates cross product of b and c, put the result in a
// a = b x c.
void cross_product(GLdouble &ax, GLdouble &ay, GLdouble &az,
    GLdouble bx, GLdouble by, GLdouble bz,
    GLdouble cx, GLdouble cy, GLdouble cz)
{
	ax = (by*cz) - (bz*cy);
	ay = (bz*cx) - (bx*cz);
	az = (bx*cy) - (bx*cy);

	/*ax[12] = (bx[13] * cx[14]) - (bx[14] * cx[13]);
	ax[13] = (bx[12] * cx[14]) - (bx[14] * cx[12]);
	ax[14] = (bx[12] * cx[13]) - (bx[13] * cx[12]);

	ay[12] = (by[13] * cy[14]) - (by[14] * cy[13]);
	ay[13] = (by[12] * cy[14]) - (by[14] * cy[12]);
	ay[14] = (by[12] * cy[13]) - (by[13] * cy[12]);

	az[12] = (bz[13] * cz[14]) - (bz[14] * cz[13]);
	az[13] = (bz[12] * cz[14]) - (bz[14] * cz[12]);
	az[14] = (bz[12] * cz[13]) - (bz[13] * cz[12]);*/

}

// Normalizes vector (x, y, z).
void normalize(GLdouble &x, GLdouble &y, GLdouble &z)
{
	double mag = sqrt((x*x) + (y*y) + (z*z));
	x /= mag;
	y /= mag;
	z /= mag;
}

// Switches matrix mode by changing the current stack pointer.
void I_my_glMatrixMode(GLenum mode)
{
	if (mode == 0x1700)
		*current_stack = model_view;
	else if (mode = 0x1701)
		*current_stack = projection;
}

// Overwrites current matrix with identity matrix.
void I_my_glLoadIdentity(void)
{
	for (int i = 0; i < STACK_CAP; ++i)
		if (i % 5 == 0)
			current_matrix[i] = 1;
		else
			current_matrix[i] = 0;
}

// Pushes current matrix onto current stack, report error if the stack is already full.
void I_my_glPushMatrix(void)
{
	if (current_stack->top > 15)
		perror("ERROR: stack is empty!");

	current_stack->top++;
	for(int i=0; i<16; ++i)
		current_stack->m[current_stack->top][i] = current_matrix[i];
}

// Pops current matrix from current stack, report error if the stack has only one matrix left.
void I_my_glPopMatrix(void)
{
	if (current_stack->top < 0)
		perror("ERROR: stack is empty!");
	
	current_stack->top--;
	for (int i = 0; i < 16; ++i)
		current_matrix[i] = current_stack->m[current_stack->top][i];
	
}

// Overwrites currentmatrix with m.
void I_my_glLoadMatrixf(const GLfloat *m)
{
	for (int i = 0; i < STACK_CAP; ++i)
		current_matrix[i] = m[i];
}

void I_my_glLoadMatrixd(const GLdouble *m)
{
	for (int i = 0; i < STACK_CAP; ++i)
		current_matrix[i] = m[i];
}

void I_my_glTranslated(GLdouble x, GLdouble y, GLdouble z)
{
	GLdouble *temp = current_matrix;
	for (int i = 0; i < STACK_CAP; ++i)
		if (i % 5 == 0)
			current_matrix[i] = 1;
		else if (i == 12)
			current_matrix[i] = x;
		else if (i == 13)
			current_matrix[i] = y;
		else if (i == 14)
			current_matrix[i] = z;
		else
			current_matrix[i] = 0;

	//matrix_multiply(temp);
}

void I_my_glTranslatef(GLfloat x, GLfloat y, GLfloat z)
{
    I_my_glTranslated((GLdouble)x, (GLdouble)y, (GLdouble)z);
}

// Remembers to normalize vector (x, y, z), and to convert angle from degree to radius before calling sin and cos.
void I_my_glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z)
{
	/*GLdouble mag = sqrt((x*x) + (y*y) + (z*z));
	x /= mag;
	y /= mag;
	z /= mag;*/
	normalize(x, y, z);

	GLdouble c = cos(angle * PI / 180);
	GLdouble s = sin(angle * PI / 180);

	GLdouble temp[16] = {
		(x*x)*(1 - c) + c, (y*x)*(1 - c) + (z*s), (x*z)*(1 - c) - (y*s), 0,
		(x*y)*(1 - c) - (z*s), (y*y)*(1 - c) + c, (y*z)*(1 - c) + (x*s), 0,
		(x*z)*(1 - c) + (y*s), (y*z)*(1 - c) - (x*s), (z*z)*(1 - c) + c, 0,
		0, 0, 0, 1
	};
	
	matrix_multiply(temp);

}

void I_my_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
{
    I_my_glRotated((GLdouble)angle, (GLdouble)x, (GLdouble)y, (GLdouble)z);
}

void I_my_glScaled(GLdouble x, GLdouble y, GLdouble z)
{
	GLdouble scale[16] = { x,0,0,0,0,y,0,0,0,0,z,0,0,0,0,1 };

	matrix_multiply(scale);
}

void I_my_glScalef(GLfloat x, GLfloat y, GLfloat z)
{
    I_my_glScaled((GLdouble)x, (GLdouble)y, (GLdouble)z);
}

// Copies current matrix to m.
void I_my_glGetMatrixf(GLfloat *m)
{
	for (int i = 0; i < STACK_CAP; ++i)
		m[i] = (GLfloat)current_matrix[i];
}

void I_my_glGetMatrixd(GLdouble *m)
{
	for (int i = 0; i < STACK_CAP; ++i)
		m[i] = current_matrix[i];
}

// Remember to normalize vectors.
void I_my_gluLookAt(GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ, 
    GLdouble centerX, GLdouble centerY, GLdouble centerZ, 
    GLdouble upX, GLdouble upY, GLdouble upZ)
{
	GLdouble* temp = current_matrix;
	GLdouble fx = centerX - eyeX;
	GLdouble fy = centerY - eyeY;
	GLdouble fz = centerZ - eyeZ;

	normalize(fx, fy, fz);
	normalize(upX, upY, upZ);

	GLdouble sx = 0;
	GLdouble sy = 0;
	GLdouble sz = 0;
	cross_product(sx, sy, sz, fx, fy, fz, upX, upY, upZ);

	normalize(sx, sy, sz);

	GLdouble ux = 0;
	GLdouble uy = 0;
	GLdouble uz = 0;
	cross_product(ux, uy, uz, sx, sy, sz, fx, fy, fz);

	int count = 0;
	current_matrix[count++] = sx;
	current_matrix[count++] = ux;
	current_matrix[count++] = -fx;
	current_matrix[count++] = 0;
	current_matrix[count++] = sy;
	current_matrix[count++] = uy;
	current_matrix[count++] = -fy;
	current_matrix[count++] = 0;
	current_matrix[count++] = sz;
	current_matrix[count++] = uz;
	current_matrix[count++] = -fz;
	current_matrix[count++] = 0;
	current_matrix[count++] = 0;
	current_matrix[count++] = 0;
	current_matrix[count++] = 0;
	current_matrix[count++] = 1;

	matrix_multiply(temp);
	I_my_glTranslated(-eyeX, -eyeY, -eyeZ);
}

void I_my_glFrustum(GLdouble left, GLdouble right, GLdouble bottom,
    GLdouble top, GLdouble zNear, GLdouble zFar)
{
	GLdouble temp[16];
	for(int i=0; i<16; ++i)
		temp[i] = current_matrix[i];

	int count = 0;
	temp[count++] = (2 *zNear)/(right - left);
	temp[count++] = 0;
	temp[count++] = 0;
	temp[count++] = 0;
	temp[count++] = 0;
	temp[count++] = (2* zNear) / (top-bottom);
	temp[count++] = 0;
	temp[count++] = 0;
	temp[count++] = (right+left)/(right-left);
	temp[count++] = (top + bottom)/(top - bottom);
	temp[count++] = -(zFar + zNear) / (zFar - zNear);
	temp[count++] = -1;
	temp[count++] = 0;
	temp[count++] = 0;
	temp[count++] = -(2*zFar*zNear)/(zFar - zNear);
	temp[count++] = 0;

	matrix_multiply(temp);
}

// Based on the inputs, calculate left, right, bottom, top, and call I_my_glFrustum accordingly
// remember to convert fovy from degree to radius before calling tan.
void I_my_gluPerspective(GLdouble fovy, GLdouble aspect, 
    GLdouble zNear, GLdouble zFar)
{
	fovy *= (PI / 180);
	GLdouble f = 1 / (tan(fovy/2));
	GLdouble* temp = current_matrix;
	int count = 0;
	current_matrix[count++] = f;///aspect;
	current_matrix[count++] = 0;
	current_matrix[count++] = 0;
	current_matrix[count++] = 0;
	current_matrix[count++] = 0;
	current_matrix[count++] = f;
	current_matrix[count++] = 0;
	current_matrix[count++] = 0;
	current_matrix[count++] = 0;
	current_matrix[count++] = 0;
	current_matrix[count++] = (zFar+zNear)/(zNear-zFar);
	current_matrix[count++] = -1;
	current_matrix[count++] = 0;
	current_matrix[count++] = 0;
	current_matrix[count++] = (2*zFar*zNear)/(zNear-zFar);
	current_matrix[count++] = 0;

	//matrix_multiply(temp);
}

