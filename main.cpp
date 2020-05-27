
# include <opencv2/opencv.hpp> 
# include <iostream>
# include "image.h"
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
	

	
	
	cv::destroyAllWindows();
	return 0;
}
