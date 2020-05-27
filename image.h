

# include <opencv2/opencv.hpp> 
# include <iostream>
#pragma once



class image {
private:
	cv::Mat img;
	cv::Mat dst;
	bool condition;
public:
	image();
	void changer_image(cv::String adresseimage);
	void change_brightness( int a,cv::String nom_nouveaux);
	void image_afficher(cv::String nom_fenetre);
	void convert_to_greyscale(cv::String nom_image);
	void filtreMedian(cv::String nom_image,int ForceBlur);
	void gaussianBlur(cv::String nom_image, int ForceBlur);
	void calcul_gradient(int dx, int dy, int bruit, cv::String nom_image);
	void Erosion(int erosion_elem, int erosion_size, cv::String nom_image);
	void Dilation(int dilation_elem, int dilation_size, cv::String nom_image);
	void contours(int low_threshold, int high_thresholds, cv::String nom_image);
	void seuil(int seuil_haut, int valeur_arbitraire, cv::String nom_image);
	void sauvegarder(cv::String nom_image);

	void regiongrow(int _x,int _y,int _scalar);
};


