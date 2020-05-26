#include "brightness.h"

#pragma once

image::image()//constructeur
{
	img = cv::imread("C:\\file/lena.jpg");
	condition = 1;
}

void image::changer_image(cv::String adresseimage)//charge une image autre que lena 
{
	img = cv::imread(adresseimage,1);
	cv::waitKey(0);
}


void image::change_brightness(int a,cv::String nom_image) {


	cv::Mat nom_nouveaux;
	img.convertTo(nom_nouveaux, -1, 1, a);

	imshow(nom_image, nom_nouveaux);
	this->dst = nom_nouveaux;
}

void image::image_afficher(cv::String nom_fenetre)
{
	
	imshow(nom_fenetre, img);
	

}

void image::convert_to_greyscale(cv::String nom_image)
{
	cv::Mat greymat;
	cv::cvtColor(img, greymat,cv::COLOR_BGR2GRAY);
	
	
	cv::imshow(nom_image, greymat);//bug dans cette fonction imshow ne fonctione pas 
	
	
	
	this->dst = greymat;

}

void image::filtreMedian(cv::String nom_image,int ForceBlur)
{

	for (int i = 1; i < ForceBlur ; i=i+2)
	{
		
		cv::medianBlur(img, dst, i);
		
		cv::imshow(nom_image, dst);
		this->dst = dst;

	}
}

void image::gaussianBlur(cv::String nom_image, int ForceBlur)
{
	for (int i = 1; i < ForceBlur; i = i + 2)
	{
		cv::GaussianBlur(img, dst, cv::Size(i, i), 0, 0);
	}
	
	cv::imshow(nom_image, dst);
	this->dst = dst;
}

void image::calcul_gradient(int dx ,int dy,int bruit,cv::String nom_image)
{
	
 	cv::Sobel(img, dst, 0, dx, dy, 3,  1,  bruit, cv::BORDER_DEFAULT);


	cv::String dx_ = std::to_string(dx); cv::String dy_ = std::to_string(dy); cv::String bruit_ = std::to_string(bruit);
	this->dst = dst;
	cv::imshow("gradient", dst);
/*
ddepth profondeur image sortie
ordre de la derivée par rapport a x
ordre dérivée par rapport a y 
scale=taille du kernel aka les derivé sur combien de pixels
deltat= ajout de bruit
bordertype=???
*/
	this->dst = dst;
}

void image::Erosion(int erosion_elem,int erosion_size,cv::String nom_image) //https://docs.opencv.org/2.4/doc/tutorials/imgproc/erosion_dilatation/erosion_dilatation.html
{
	int erosion_type; int test;
	do {
		test = erosion_elem;
		if (erosion_elem == 0) { erosion_type = cv::MORPH_RECT; }
		else if (erosion_elem == 1) { erosion_type = cv::MORPH_CROSS; }
		else if (erosion_elem == 2) { erosion_type = cv::MORPH_ELLIPSE; }
		else {
			std::cout << "la valeur de erosion doit etre entre 0 et 2 inclu" << std::endl;
			std::cin >> erosion_elem;
		}

		
	} while (test > 2);

	cv::Mat element = cv::getStructuringElement(erosion_type,
		cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		cv::Point(erosion_size, erosion_size));

	/// Apply the erosion operation
	cv::erode(img, dst, element);
	cv::imshow(nom_image, dst);
	this->dst = dst;
}

void image::Dilation(int dilation_elem, int dilation_size, cv::String nom_image)
{
	int dilation_type;
	if (dilation_elem == 0) { dilation_type = cv::MORPH_RECT; }
	else if (dilation_elem == 1) { dilation_type = cv::MORPH_CROSS; }
	else if (dilation_elem == 2) { dilation_type = cv::MORPH_ELLIPSE; }

	cv::Mat element = cv::getStructuringElement(dilation_type,
		cv::Size(2 * dilation_size + 1, 2 * dilation_size + 1),
		cv::Point(dilation_size, dilation_size));
	/// Apply the dilation operation
	cv::dilate(img, dst, element);
	cv::imshow(nom_image, dst);
	cv::imwrite(nom_image + ".jpg", dst);
	this->dst = dst;
}

void image::contours(int low_threshold, int high_thresholds,cv::String nom_image) {

	cv::Canny(img,dst,low_threshold,high_thresholds);        
	cv::imshow(nom_image, dst);
	
	this->dst = dst;
}

void image::seuil(int seuil_haut,int valeur_arbitraire,cv::String nom_image) {

	cv::Mat graymat;
	cv::cvtColor(img, graymat, cv::COLOR_BGR2GRAY);
	cv::threshold(graymat, dst, seuil_haut, valeur_arbitraire, cv::THRESH_TRUNC);
	cv::imshow(nom_image, dst);
	
	this->dst = dst;

}



void image::sauvegarder(cv::String nom_image)
{
	this->img = this->dst;
	cv::imwrite(nom_image + ".jpg", img);
	
}

bool image::getcondition()
{
	return (condition);
}

void image::setcondition()
{
	this->condition = 0;
}
