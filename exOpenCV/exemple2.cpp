/*
 * Code written by Vinz (GeckoGeek.fr)
 */
 
#include <stdio.h>
#include "highgui.h"
#include "cv.h"
#include "assert.h"
 


void invert_color (IplImage* img)
{
CvScalar p;
int x, y, k;
assert (img->depth == IPL_DEPTH_8U);
for (y = 0; y < img->height; ++y)
{
for (x = 0; x < img->width; ++x)
{
p = cvGet2D (img, y, x);
/*for (k = 0; k < img->nChannels; ++k)
{
p.val[k] = 255 - p.val[k];
}*/
p.val[0]=0;
p.val[1]=0;
cvSet2D (img, y, x, p);
}
}
} 



int main() {
 
    // Touche clavier
    char key;

    // Image
     IplImage *image;
    // Capture vidéo
    CvCapture *capture;
 
    // Ouvrir le flux vidéo
    //capture = cvCreateFileCapture("/path/to/your/video/test.avi"); // chemin pour un fichier
    capture = cvCreateCameraCapture(CV_CAP_ANY);
 
    // Vérifier si l'ouverture du flux est ok
    if (!capture) {
 
       printf("Ouverture du flux vidéo impossible !\n");
       return 1;
 
    }
 
    // Définition de la fenêtre
    cvNamedWindow("couleur", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("noir et blanc", CV_WINDOW_AUTOSIZE);
 
    // Boucle tant que l'utilisateur n'appuie pas sur la touche q (ou Q)
    while(key != 'q' && key != 'Q') {
 
       // On récupère une image
       image = cvQueryFrame(capture);

 
       // On affiche l'image dans une fenêtre

       cvShowImage( "couleur", image);
	invert_color(image);
	cvShowImage( "noir et blanc", image);	
 
       // On attend 10ms
       key = cvWaitKey(1);
 
    }
 
    cvReleaseCapture(&capture);
    cvDestroyWindow("GeckoGeek Window");
 
    return 0;
 
}
