#ifndef ADVANCED_H
#define ADVANCED_H

#include "Constants.h"

/* Posterize Image */
void Posterize( unsigned char R[WIDTH][HEIGHT,
 unsigned char G[WIDTH][HEIGHT],
 unsigned char B[WIDTH][HEIGHT],
 unsigned int pbits);

/* Fill Lights */
void FillLight( int number , int lightWidth,
 unsigned char R[WIDTH][HEIGHT],
 unsigned char G[WIDTH][HEIGHT],
 unsigned char B[WIDTH][HEIGHT]);

/* Overlay */
void Overlay( char fname[SLEN], 
 unsigned char R[WIDTH][HEIGHT], 
 unsigned char G[WIDTH][HEIGHT], 
 unsigned char B[WIDTH][HEIGHT], 
 int x_offset, int y_offset)

 /* Bonus : Cut and Paste */
 void CutPaste( unsigned char R[WIDTH][HEIGHT], 
 unsigned char G[WIDTH][HEIGHT], 
 unsigned char B[WIDTH][HEIGHT],
 unsigned int start_x, unsigned int start_y,
 unsigned int x_width, unsigned int y_width, 
 unsigned int pasteNumber);
 
 #endif