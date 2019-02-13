#include "Advanced.h"

/* Posterize the image */
void Posterize(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], unsigned int pbits)
{
        int x , y;
        int bbit = 1;
        int shift = (8 - pbits);

        unsigned char r[WIDTH][HEIGHT];
        unsigned char g[WIDTH][HEIGHT];
        unsigned char b[WIDTH][HEIGHT];

        for (x = (pbits - 1); x > 0; x--){
                bbit *= 2;
                }

        for (x = 0; x < WIDTH; x++)
                for ( y = 0; y < HEIGHT; y++){
                        r[x][y] = R[x][y];
                        g[x][y] = G[x][y];
                        b[x][y] = B[x][y];

                        r[x][y] = (((r[x][y] << shift) | 255) >> shift);
                        g[x][y] = (((g[x][y] << shift) | 255) >> shift);
                        b[x][y] = (((b[x][y] << shift) | 255) >> shift);

                        R[x][y] = ((r[x][y] | R[x][y]) - bbit);
                        G[x][y] = ((g[x][y] | G[x][y]) - bbit);
                        B[x][y] = ((b[x][y] | B[x][y]) - bbit);
                        }
}

/* Fill christmas lights to image */
void FillLight( int number, int lightWidth, unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
        srand(time(NULL));

        int x, y ;
        int count = number;

        int red = 0;
        int green = 0;
        int blue = 0;

        int ran, ranx, rany;

        unsigned char r[WIDTH][HEIGHT];
        unsigned char g[WIDTH][HEIGHT];
        unsigned char b[WIDTH][HEIGHT];

        while (count > 0){
                ran = (rand() % 3) + 1;
                switch(ran){
                        case 1:
                                red = 255;
                                break;
                        case 2:
                                green = 255;
                                break;
                        case 3:
                                blue = 255;
                                break;
                        }

                for ( x = 0; x < WIDTH; x++)
                        for ( y = 0; y < HEIGHT; y++){
                                r[x][y] = 0;
                                g[x][y] = 0;
                                b[x][y] = 0;
                                }

                ranx = rand() % (WIDTH - (lightWidth));
                rany = rand() % (HEIGHT - (lightWidth));
                for (x = 0; x < (lightWidth/2); x++)
                        for (x = 0; x < (lightWidth/2); x++)
                        for ( y = 0; y < (lightWidth/2); y++){

                                r[ranx+x][rany+y] = red;
                                g[ranx+x][rany+y] = green;
                                b[ranx+x][rany+y] = blue;

                                r[ranx-x][rany+y] = red;
                                g[ranx-x][rany+y] = green;
                                b[ranx-x][rany+y] = blue;

                                r[ranx+x][rany] = red;
                                g[ranx+x][rany] = green;
                                b[ranx+x][rany] = blue;

                                r[ranx][rany+y] = red;
                                g[ranx][rany+y] = green;
                                b[ranx][rany+y] = blue;

                                r[ranx][rany-y] = red;
                                g[ranx][rany-y] = green;
                                b[ranx][rany-y] = blue;
								
                                r[ranx-x][rany] = red;
                                g[ranx-x][rany] = green;
                                b[ranx-x][rany] = blue;

                                r[ranx+x][rany-y] = red;
                                g[ranx+x][rany-y] = green;
                                b[ranx+x][rany-y] = blue;

                                r[ranx-x][rany-y] = red;
                                g[ranx-x][rany-y] = green;
                                b[ranx-x][rany-y] = blue;
                                }
                count -= 1;
                }

        for ( x = 0; x < (WIDTH - (lightWidth/2)); x++)
                for ( y = 0; y < (HEIGHT - (lightWidth/2)); y++){
                        if (r[x][y] != 255 || g[x][y] != 255 || b[x][y] != 255){
                                r[x][y] = R[x][y];
                                g[x][y] = G[x][y];
                                b[x][y] = B[x][y];
                                }
                        else {
                                R[x][y] = r[x][y];
                                G[x][y] = g[x][y];
                                B[x][y] = b[x][y];
                                }
                        }
}

/*Overaly an image onto the original image*/
void Overlay(char fname[SLEN], unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], int x_offset, int y_offset)
{
        int x, y;

        unsigned char r[WIDTH][HEIGHT];
        unsigned char g[WIDTH][HEIGHT];
        unsigned char b[WIDTH][HEIGHT];

        unsigned char rr[WIDTH][HEIGHT];
        unsigned char gg[WIDTH][HEIGHT];
        unsigned char bb[WIDTH][HEIGHT];

        ReadImage(fname, r, g, b);

        for ( x = 0; x < WIDTH; x++ )
                for ( y = 0; y < HEIGHT; y++ ){
                        rr[x][y] = r[x][y];
                        gg[x][y] = g[x][y];
                        bb[x][y] = b[x][y];

                        if (x - x_offset < 0 ||  y - y_offset < 0){
                                r[x][y] = rr[x][y];
                                g[x][y] = gg[x][y];
                                b[x][y] = bb[x][y];
                                }
                        else{
                                r[x][y] = rr[abs(x - x_offset)][abs(y - y_offset)];
                                g[x][y] = gg[abs(x - x_offset)][abs(y - y_offset)];
                                b[x][y] = bb[abs(x - x_offset)][abs(y - y_offset)];
                                }
                        if ( r[x][y] >= 250 &&  g[x][y] >= 250 && b[x][y] >= 250 ){
                                r[x][y] = R[x][y];
                                g[x][y] = G[x][y];
                                b[x][y] = B[x][y];
                                }
                         else {
                                R[x][y] = r[x][y];
                                G[x][y] = g[x][y];
                                B[x][y] = b[x][y];
                                }
                        }
}


