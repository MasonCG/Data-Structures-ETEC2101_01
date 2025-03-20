#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <WordReader.h>
#include <arrayLists.h>
#include <iostream>

#define fname "../../media/american-words.txt"

int main(int argc, char**) 
{

	ssuds::WordReader wordreader;
	std::cout << wordreader.getWord() << std::endl;
	std::cout << wordreader.getWord() << std::endl;
	std::cout << wordreader.getWord() << std::endl;
	std::cout << wordreader.getWord() << std::endl;
	std::cout << wordreader.getWord() << std::endl;
	std::cout << wordreader.getWord() << std::endl;
	std::cout << wordreader.getWord() << std::endl;


	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Mason's Lab4");

	sf::CircleShape test(25.0f);
	test.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		window.clear();
		window.draw(test);
		window.display();
	}
	return 0;
}
