
# include <opencv2/opencv.hpp> 
# include <iostream>
# include "brightness.h"
#include "input.h"
#include "display.h"

bool Variable_glabale_sortie_de_boucle_infinie = 1;

int main(){
	
	int menu = 13;
	
	image lena;
	display display;
	input input;
	do {
		display.initialisation();
		input.action();
		cv::waitKey(0);
		
	} while (1);
	

	
	//lena.image_afficher("test1");
	//lena.calcul_gradient(1, 1, 0, "derive");
	//lena.change_brightness(-100,"lennnnnna.jpg");
	
	//lena.convert_to_greyscale("greyscale");
	//lena.filtreMedian("a l'aide",10);
	//lena.gaussianBlur("nom_image", 10);
	
	//lena.Erosion(1, 1, "igsyifgd");
	//Dilation(1, 1, "dsgyiqcaeydgy");
	//lena.contours(0, 100, "contour"); 
	
	//lena.seuil(100,255, "hjifhsdui");
	cv::destroyAllWindows();
	return 0;
}
