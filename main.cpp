#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>

unsigned int bounce_logo = 1; //direction

int main()
{
	srand(time(NULL));
	sf::RenderWindow tv(sf::VideoMode(800,600),"DVD Video");
	tv.setVerticalSyncEnabled(true);
	
	sf::Texture logo_image;
	if(!logo_image.loadFromFile("logo.png"))
	{
		return -1;
	}
	
	sf::Sprite logo;
	logo.setTexture(logo_image);
	logo.setPosition(rand()%800,rand()%600);
	logo.setOrigin(75, 50);
	logo.setScale(2, 2);
	int logo_speed = 1;
	
	while(tv.isOpen())
	{
        sf::Event event;
        while (tv.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                tv.close();
        }
		switch(bounce_logo)
		{
			case 1:
				logo.setPosition(logo.getPosition().x + logo_speed, logo.getPosition().y - logo_speed); //NE
				break;
			case 2:
				logo.setPosition(logo.getPosition().x - logo_speed, logo.getPosition().y - logo_speed); //NW
				break;
			case 3:
				logo.setPosition(logo.getPosition().x - logo_speed, logo.getPosition().y + logo_speed); //SW
				break;
			case 4:
				logo.setPosition(logo.getPosition().x + logo_speed, logo.getPosition().y + logo_speed); //SE
				break;
		}
		if(logo.getPosition().x < 150 && bounce_logo == 3)
		{
			bounce_logo = 4;
		}
		if(logo.getPosition().x < 150 && bounce_logo == 2)
		{
			bounce_logo = 1;
		}
		if(logo.getPosition().x > 800 && bounce_logo == 1)
		{
			bounce_logo = 2;
		}
		if(logo.getPosition().x > 800 && bounce_logo == 4)
		{
			bounce_logo = 3;
		}
		if(logo.getPosition().y < 100 && bounce_logo == 1)
		{
			bounce_logo = 4;
		}
		if(logo.getPosition().y < 100 && bounce_logo == 2)
		{
			bounce_logo = 3;
		}
		if(logo.getPosition().y > 600 && bounce_logo == 3)
		{
			bounce_logo = 2;
		}
		if(logo.getPosition().y > 600 && bounce_logo == 4)
		{
			bounce_logo = 1;
		}
		
		tv.clear(sf::Color::Black);
		tv.draw(logo);
		tv.display();
	}
}