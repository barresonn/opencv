
#include "display.h"



display::display() {}



void display::initialisation()
{
	
	std::cout << std::endl << " ----------------------- MENU -----------------------" << std::endl << std::endl;
	std::cout << "1. importer une image" << std::endl;//atention au format du path il doit s'écrire sous la forme F:\\Personal/1.jpg
	std::cout << "2. Afficher image" << std::endl;
	std::cout << "3. changer la luminositée" << std::endl;
	std::cout << "4. calcul  gradient" << std::endl;
	std::cout << "5. convertir en greyscale" << std::endl;
	std::cout << "6. filtre median" << std::endl;
	std::cout << "7. filtre gaussian" << std::endl;
	std::cout << "8. erosion" << std::endl;
	std::cout << "9. dilatation" << std::endl;
	std::cout << "10. tracer contours" << std::endl;
	std::cout << "11. seuils" << std::endl;
	std::cout << "12. sauvegarder" << std::endl;
	std::cout << "0. Quitter" << std::endl;
	std::cout << "Choix : " << std::endl;
	std::cout << std::endl;
}
