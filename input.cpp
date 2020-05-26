#include "input.h"
#include "brightness.h"




input::input():
	instance(0)
{}



void input::action()
{
	int action;
	std::cin >> action;

	switch (action)
	{
	case 1:
	{
		std::string adresse_image;
		std::cout << "rentrez l'adresse de l'image(doit etre sous la forme C:\\file/lena.jpg)" << std::endl;
		std::cin >> adresse_image;
		changer_image(adresse_image);
		cv::waitKey(0);
		cv::destroyAllWindows();
		break;
	}
	case 2:
	{
		image_afficher("obtenue");
		cv::waitKey(0);
		cv::destroyAllWindows();
		break;
	}
	case 3:
	{
		unsigned int brightness;
		std::cout << "quel changement de luminosite voulez vous " << std::endl;
		std::cout << "donnez un nombre entre -255 et 255" << std::endl;
		std::cin >> brightness;
		change_brightness(brightness, "brightness");
		cv::waitKey(0);
		cv::destroyAllWindows();
		break;
	}
	case 4:
	{
		unsigned int _x; unsigned int _y; unsigned int _kernel;

		std::cout << "donnez le nombre de derivee par x" << std::endl;
		std::cin >> _x;
		std::cout << "donnez le nombre de derivee par y" << std::endl;
		std::cin >> _y;
		std::cout << "donnez sur combien de pixel les derivee doivent étre faites(valeur conseilée au alentour de 30)" << std::endl;
		std::cin >> _kernel;
		calcul_gradient(_x, _y, _kernel, "derive");
		cv::waitKey(0);
		cv::destroyAllWindows();
		break;
	}
	case 5:
	{
		convert_to_greyscale("greyscale");
		cv::waitKey(0);
		cv::destroyAllWindows();
		break;
	}
	case 6:
	{	unsigned int _x;
	std::cout << "sur combien de pixel voulez vous flouter" << std::endl;
	std::cout << "plus le chiffre est grand plus le floutage sera important" << std::endl;
	std::cin >> _x;
	filtreMedian("floutage median", _x);
	cv::waitKey(0);
	cv::destroyAllWindows();
	break;
	};
	case 7:
	{
		unsigned int _x;
		std::cout << "sur combien de pixel voulez vous flouter" << std::endl;
		std::cout << "plus le chiffre est grand plus le floutage sera important" << std::endl;
		std::cin >> _x;
		gaussianBlur("floutage median", _x);
		cv::waitKey(0);
		cv::destroyAllWindows();
		break;
	}
	case 8:
	{
		unsigned int _x;  unsigned int _kernel;
		std::cout << "quelle erosion voulez vous" << std::endl;
		std::cout << "0.en forme de rectangle" << std::endl;
		std::cout << "1.en forme de croix" << std::endl;
		std::cout << "2.en forme d'ellipse" << std::endl;
		std::cin >> _x;
		std::cout << "quelle doit etre la taille de l'erosion" << std::endl;
		std::cin >> _kernel;
		Erosion(_x, _kernel, "erosion");
		cv::waitKey(0);
		cv::destroyAllWindows();
		break;
	}
	case 9:
	{
		unsigned int _x;  unsigned int _kernel;
		std::cout << "quelle dilation voulez vous" << std::endl;
		std::cout << "0.en forme de rectangle" << std::endl;
		std::cout << "1.en forme de croix" << std::endl;
		std::cout << "2.en forme d'ellipse" << std::endl;
		std::cin >> _x;
		std::cout << "quelle doit etre la taille de la dilation" << std::endl;
		std::cin >> _kernel;
		Dilation(_x, _kernel, "dilation");
		cv::waitKey(0);
		cv::destroyAllWindows();
		break;
	}
	case 10:
	{
		unsigned int _x;  unsigned int _y;
		std::cout << "limite inferieure" << std::endl;
		
		std::cin >> _x;
		std::cout << "limite superieure" << std::endl;
		std::cin >> _y;
		contours(_x, _y, "contours");
		cv::waitKey(0);
		cv::destroyAllWindows();
		break;
	}
	case 11:
	{
		unsigned int _x;  
		std::cout << "seuil bas" << std::endl;
		std::cin >> _x;
		
		seuil(_x, 255, "seuil");
		cv::waitKey(0);
		cv::destroyAllWindows();
		break;
	}
	case 12:
	{
		cv::String _y;
		std::cout << "sous quel nom voulez vous sauvegarder votre image" << std::endl;
		std::cin >> _y;
		sauvegarder(_y);
		break;
	}
	case 0:
	{
		exit(EXIT_SUCCESS);
		break;
	}
	default:
	{
	std::cout << "entrée invalide" << std::endl;
}
	}
}
