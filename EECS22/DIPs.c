#include "DIPs.h"

/* Black And White */
void BlackNWhite(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
        int     x, y;

        for (y = 0; y < HEIGHT; y++){
                for (x = 0; x < WIDTH; x++) {
                        R[x][y] = G[x][y] = B[x][y]
                                = (R[x][y] + G[x][y] + B[x][y]) / 3;
                }
        }
}

/* Vertical Flip */
void VFlip(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
        int     x, y;
        unsigned char   tR, tG, tB;

        for (y = 0; y < HEIGHT/2; y++) {
                for (x = 0; x < WIDTH; x++) {
                        tR = R[x][HEIGHT - 1 - y];
                        tG = G[x][HEIGHT - 1 - y];
                        tB = B[x][HEIGHT - 1 - y];

                        R[x][HEIGHT - 1 - y] = R[x][y];
                        G[x][HEIGHT - 1 - y] = G[x][y];
                        B[x][HEIGHT - 1 - y] = B[x][y];

                        R[x][y] = tR;
                        G[x][y] = tG;
                        B[x][y] = tB;
                }
        }
}

/* Horizontal Mirroring */
void HMirror(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
        int     x, y;
        for (y = 0; y < HEIGHT; y++) {
                for (x = 0; x < WIDTH / 2; x++) {
                        R[x][y] = R[WIDTH - 1 - x][y] ;
                        G[x][y] = G[WIDTH - 1 - x][y] ;
                        B[x][y] = B[WIDTH - 1 - x][y] ;
                }
        }
}

/* Color Filter */
void ColorFilter (unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT], int target_r, int target_g, int target_b, int threshold, double factor_r, double f$
 {
        int x, y ;
        int temp ;

        for (y=0; y<HEIGHT; y++){
                for (x=0; x<WIDTH; x++){
                        if ((R[x][y] < target_r + threshold)&&
                            (R[x][y] > target_r - threshold)&&
                            (G[x][y] < target_g + threshold)&&
                            (G[x][y] > target_g - threshold)&&
                            (B[x][y] < target_b + threshold)&&
                            (B[x][y] > target_b - threshold))
                        {
                                temp = factor_r;
                                R[x][y] = (temp > 255)? 255 : (temp <0)? 0 : temp ;
                                temp = factor_g;
                                G[x][y] = (temp > 255)? 255 : (temp <0)? 0 : temp ;
                                temp = factor_b;
                                B[x][y] = (temp > 255)? 255 : (temp <0)? 0 : temp ;
                        }
                }
        }
}

/* Edge */
void Edge(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
        int             x, y, m, n, a, b;
        int             tmpR = 0;
        int             tmpG = 0;
        int             tmpB = 0;

        unsigned char   tR[WIDTH][HEIGHT];
        unsigned char   tG[WIDTH][HEIGHT];
        unsigned char   tB[WIDTH][HEIGHT];

        for (y = 0; y < HEIGHT; y++){
                for (x = 0; x < WIDTH; x++) {
                        tR[x][y] = R[x][y];
                        tG[x][y] = G[x][y];
                        tB[x][y] = B[x][y];
                }
        }

        for (y = 0; y < HEIGHT; y++){
                for (x = 0; x < WIDTH; x++){
                        for (n = -1; n <= 1; n++){
                                for (m = -1; m <= 1; m++) {
                                        a = x + m;
                                        b = y + n;
                                        if (a > WIDTH - 1)
                                                a = WIDTH - 1;
                                        if (a < 0)
                                                a = 0;
                                        if (b > HEIGHT - 1)
                                                b = HEIGHT - 1;
                                        if (b < 0)
                                                b = 0;

                                        if ((n==0)&&(m==0))
                                        {
                                                tmpR += 8*tR[a][b] ;
                                                tmpG += 8*tG[a][b] ;
                                                tmpB += 8*tB[a][b] ;
										}
                                        else
                                        {
                                                tmpR -= tR[a][b] ;
                                                tmpG -= tG[a][b] ;
                                                tmpB -= tB[a][b] ;
                                        }
                                }
                        }
                        R[x][y] = (tmpR>255)? 255: (tmpR<0)? 0: tmpR ;
                        G[x][y] = (tmpG>255)? 255: (tmpG<0)? 0: tmpG ;
                        B[x][y] = (tmpB>255)? 255: (tmpB<0)? 0: tmpB ;
                        tmpR = tmpG = tmpB = 0;
                }
        }
}


/*Shuffle Image */
void Shuffle(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
        int block_cnt = SHUFF_HEIGHT_DIV * SHUFF_WIDTH_DIV;
        int block_width = WIDTH/SHUFF_WIDTH_DIV;
        int block_height = HEIGHT/SHUFF_HEIGHT_DIV;
        int block[SHUFF_WIDTH_DIV][SHUFF_HEIGHT_DIV];
        int i, j;

        srand(time(NULL));
        /* Initialize block markers to not done (-1) */
        for (i = 0; i < SHUFF_WIDTH_DIV; i++) {
                for (j = 0; j< SHUFF_HEIGHT_DIV; j++) {
                        block[i][j] = -1;
                }
        }

        while (block_cnt > 0) {
                /* Generate a random pair of blocks */
                int dest_height = rand() % SHUFF_HEIGHT_DIV;
                int dest_width = rand() % SHUFF_WIDTH_DIV;
                int src_height = rand() % SHUFF_HEIGHT_DIV;
                int src_width = rand() % SHUFF_WIDTH_DIV;

                /* Check if these blocks are already swaped, if not swap blocks */
                if ((block[dest_width][dest_height] == -1) && (block[src_width][src_height] == -1)) {
                        /* Swap blocks */
                        for (i = 0; i < block_height; i++) {
                                /* Init src and dest height offset */
                                int h_dest = ((dest_height * block_height) + i) % HEIGHT;
                                int h_src  = ((src_height * block_height) + i) % HEIGHT;
                                for (j = 0; j < block_width; j++) {
                                        int temp;
                                        /* Init src and dest width offset */
                                        int w_src  = ((src_width * block_width) + j) % WIDTH;
                                        int w_dest = ((dest_width * block_width) + j) % WIDTH;

                                        temp = R[w_dest][h_dest];
                                        R[w_dest][h_dest] = R[w_src][h_src];
                                        R[w_src][h_src] = temp;

                                        temp = G[w_dest][h_dest];
                                        G[w_dest][h_dest] = G[w_src][h_src];
                                        G[w_src][h_src] = temp;

                                        temp = B[w_dest][h_dest];
                                        B[w_dest][h_dest] = B[w_src][h_src];
                                        B[w_src][h_src] = temp;
                                }
                        }
                        /* Set marker as done */
                        block[dest_width][dest_height] = 1;
                        block[src_width][src_height] = 1;
                        /* Decrease block count */
                        block_cnt -= 2; /* Two blocks are swapped */
                }
        }
}
