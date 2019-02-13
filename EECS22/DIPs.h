#ifndef DIPS_H
#define DIPS_H

#include "Constants.h"

/* Black & White */
void    BlackNWhite(unsigned char R[WIDTH][HEIGHT],
 unsigned char G[WIDTH][HEIGHT],
 unsigned char B[WIDTH][HEIGHT]);

/* Flip Image Vertically */
void    VFlip(unsigned char R[WIDTH][HEIGHT],
 unsigned char G[WIDTH][HEIGHT],
 unsigned char B[WIDTH][HEIGHT]);

/* Mirror Image Horizontally */
void    HMirror(unsigned char R[WIDTH][HEIGHT],
 unsigned char G[WIDTH][HEIGHT],
 unsigned char B[WIDTH][HEIGHT]);

/* Color Filter */
void    ColorFilter(unsigned char R[WIDTH][HEIGHT],
 unsigned char G[WIDTH][HEIGHT],
 unsigned char B[WIDTH][HEIGHT],
 int target_r,
 int target_g,
 int target_b,
 int threshold,
 double factor_r,
 double factor_g,
 double factor_b) ;

/* Edge Detection */
void    Edge(unsigned char R[WIDTH][HEIGHT],
 unsigned char G[WIDTH][HEIGHT],
 unsigned char B[WIDTH][HEIGHT]);

/* Shuffle Image */
void    Shuffle(unsigned char R[WIDTH][HEIGHT],
 unsigned char G[WIDTH][HEIGHT],
 unsigned char B[WIDTH][HEIGHT]);
 
 #endif