#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

unsigned int bounce_logo = 1; //direction

int main()
{
	srand(time(NULL));
	sf::RenderWindow tv(sf::VideoMode(800,600),"DVD Simulator (0 corner hits)");
	tv.setVerticalSyncEnabled(true);
	
	sf::Texture logo_image;
	if(!logo_image.loadFromFile("logo.png"))
	{
		return -1;
	}
	
	sf::Sprite logo;
	logo.setTexture(logo_image);
	logo.setPosition((rand()%400)+200,(rand()%300)+100);
	logo.setOrigin(75, 50);
	logo.setScale(2, 2);
	int logo_speed = 1;
	
	int debounce;
	
	int cornerhits = 0;
	
	while(tv.isOpen())
	{
        sf::Event event;
        while (tv.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                tv.close();
        }
		//speed adjustment
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && debounce > 15 && logo_speed > 0)
		{
			logo_speed--;
			debounce = 0;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && debounce > 15)
		{
			logo_speed++;
			debounce = 0;
		}
		
		//move LOGO
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
		
		//check for hits
		if(logo.getPosition().y < 100 && logo.getPosition().x > 800)
		{
			cornerhits++;
		}
		if(logo.getPosition().y < 100 && logo.getPosition().x < 150)
		{
			cornerhits++;
		}
		if(logo.getPosition().y > 600 && logo.getPosition().x > 800)
		{
			cornerhits++;
		}
		if(logo.getPosition().y > 600 && logo.getPosition().x < 150)
		{
			cornerhits++;
		}
		
		//bounce
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
		
		debounce++;
		
		tv.setTitle("DVD Simulator (" + std::to_string(cornerhits) + " corner hits)");
		tv.clear(sf::Color::Black);
		tv.draw(logo);
		tv.display();
	}
}