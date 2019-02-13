#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "FileIO.h"
#include "DIPs.h"
#include "Advanced.h"

int     main()
{
        int             FileNotRead ;
        unsigned char   R[WIDTH][HEIGHT];
        unsigned char   G[WIDTH][HEIGHT];
        unsigned char   B[WIDTH][HEIGHT];

        char            fname[SLEN];
        int             choice;

        int             target_r ;
        int             target_g ;
        int             target_b ;
        int             threshold ;
        double          factor_r ;
        double          factor_g ;
        double          factor_b ;
		

        FileNotRead = 1 ;
        PrintMenu();
        printf("Please make your choice: ");
        scanf("%d", &choice);

        while (choice != 14) {
                switch (choice) {
                case 1:
                        printf("Please input the file name to load: ");
                        scanf("%s", fname);
                        FileNotRead = ReadImage(fname, R, G, B);
                        break;
                case 2:
                        if (FileNotRead != 0)
                        {
                                printf("No Image Loaded.\n") ;
                        }
                        else
                        {
                                printf("Please input the file name to save: ");
                                scanf("%s", fname);
                                SaveImage(fname, R, G, B);
                        }
                        break;
                case 3:
                        if (FileNotRead != 0)
                        {
                                printf("No Image Read Yet !!\n") ;
                        }
                        else
                        {
                                BlackNWhite(R, G, B);
                                printf("Black N White completed!\n");
                        }
                        break;
                case 4:
                        if (FileNotRead != 0)
                        {
                                printf("No Image Loaded.\n") ;
                        }
                        else
                        {
                                VFlip(R,G,B);
                                printf( "Vertical Flipping completed!\n" );
                        }
						break;
                case 5:
                        if (FileNotRead != 0)
                        {
                                printf("No Image Loaded.\n") ;
                        }
                        else
                        {
                                HMirror(R, G, B);
                                printf("Horizontal Mirrorring completed!\n");
                        }
                        break;
                case 6:
                        if (FileNotRead != 0)
                        {
                                printf("No Image Loaded.\n") ;
                        }
                        else
                        {
                                printf("Enter Red   component for the target color: ") ;
                                scanf("%d", &target_r) ;
                                printf("Enter Green component for the target color: ") ;
                                scanf("%d", &target_g) ;
                                printf("Enter Blue  component for the target color: ") ;
                                scanf("%d", &target_b) ;
                                printf("Enter threshold for the color difference: ") ;
                                scanf("%d", &threshold) ;
                                printf("Enter value for Red component in the target color: ") ;
                                scanf("%lf", &factor_r) ;
                                printf("Enter value for Green component in the target color: ") ;
                                scanf("%lf", &factor_g) ;
                                printf("Enter value for Blue  component in the target color: ") ;
                                scanf("%lf", &factor_b) ;

                                ColorFilter(R, G, B, target_r, target_g, target_b, threshold, factor_r, factor_g, factor_b);
                                printf("Color Filtering completed!\n");
                        }
                        break;
                case 7:
                        if (FileNotRead != 0)
                        {
                                printf("No Image Loaded.\n") ;
                        }
                        else
                        {
								Edge(R, G, B);
                                printf("Edging completed!\n");
                        }
                        break;
                case 8:
                         if (FileNotRead != 0)
                        {
                                printf("No Image Loaded.\n") ;
                        }
                        else
                        {
                                Shuffle(R, G, B);
                                printf("Shuffling completed!\n");
                        }
                        break;
                case 9:
                        if (FileNotRead != 0)
                        {
                                printf("No Image Loaded.\n") ;
                        }
                        else
                        {

                        }
                        break;
                case 10:
                        if (FileNotRead != 0)
                        {
                                printf("No Image Loaded.\n") ;
                        }
                        else
                        {

                        }
                        break;
                case 11:
                        if (FileNotRead != 0)
                        {
                                printf("No Image Loaded.\n") ;
                        }
                        else
                        {

                        }
                        break;
				case 12:
                        if (FileNotRead != 0)
                        {
                                printf("No Image Loaded.\n") ;
                        }
                        else
                        {

                        }
                        break;
                case 13:
                        AutoTest(R, G, B);
                        FileNotRead = 0 ;
                        break;
                default:
                        printf("Choice not available!\n");
                        break;
                }

                PrintMenu();
                printf("please make your choice: ");
                scanf("%d", &choice);
        }

        return 0;
}

/* print a menu */
void	PrintMenu()
{
        printf("--------------------------------\n");
        printf(" 1:  Load a PPM image\n");
        printf(" 2:  Save an image in PPM and JPEG format\n");
        printf(" 3:  Change a color image to Black & White\n");
        printf(" 4:  Flip an image vertically\n");
        printf(" 5:  Mirror an image horizontally\n");
        printf(" 6:  Color filter an image\n");
        printf(" 7:  Sketch the edge of an image\n");
        printf(" 8:  Shuffle an image\n");
        printf(" 9:  Posterize the image");
        printf(" 10: Fill lights to an image\n");
        printf(" 11: Overlay an image\n");
        printf(" 12: Bonus, Cut and Paste operation on image\n");
        printf(" 13: Test all functions\n");
        printf(" 14: Exit\n");
}

/* auto test*/
void	AutoTest(unsigned char R[WIDTH][HEIGHT], unsigned char G[WIDTH][HEIGHT], unsigned char B[WIDTH][HEIGHT])
{
        char            fname[SLEN] = "RingMall";
        char            sname[SLEN];

        ReadImage(fname, R, G, B);
        BlackNWhite(R, G, B);
        strcpy(sname, "bw");
        SaveImage(sname, R, G, B);
        printf("Black & White tested!\n\n");

        ReadImage(fname, R, G, B);
        VFlip(R, G, B);
        strcpy(sname, "vflip");
        SaveImage(sname, R, G, B);
        printf("VFlip tested!\n\n");

        ReadImage(fname, R, G, B);
        HMirror(R, G, B);
        strcpy(sname, "hmirror");
        SaveImage(sname, R, G, B);
        printf("HMirror tested!\n\n");

        ReadImage(fname, R, G, B);
        ColorFilter(R, G, B, 180, 180, 50, 70, 0, 255, 0);
        strcpy(sname, "colorfilter");
        SaveImage(sname, R, G, B);
        printf("Color Filter tested!\n\n");

        ReadImage(fname, R, G, B);
        Edge(R, G, B);
        strcpy(sname, "edge");
        SaveImage(sname, R, G, B);
        printf("Edge Detection tested!\n\n");

        ReadImage(fname, R, G, B);
        Shuffle(R, G, B);
        strcpy(sname, "shuffle");
        SaveImage(sname, R, G, B);
        printf("Shuffle tested!\n\n");

}
                                                                    		