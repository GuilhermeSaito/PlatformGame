// Included for remove \r from players name
#include <algorithm>

#include "characterSelection.h"

using StartScreen::CharacterSelection;

CharacterSelection::CharacterSelection() : isMultiplayer(false), player1Name(""), player2Name("")
{
    menu1.setFont(*(Data::getInstance()->getOpenMenufont()));
    menu2.setFont(*(Data::getInstance()->getOpenMenufont()));
    menu3.setFont(*(Data::getInstance()->getOpenMenufont()));
    menu4.setFont(*(Data::getInstance()->getOpenMenufont()));

    beginnerPhaseSprite.setTexture(*(Data::getInstance()->getBeginnerPhaseBackGround()));
    // Width 550, Height 690
    beginnerPhaseSprite.setPosition({ 500.f, 20.f });
    beginnerPhaseSprite.setScale(sf::Vector2f(0.2865, 0.8323));
    blueOceanPhaseSprite.setTexture(*(Data::getInstance()->getBlueOceanPhaseBackGround()));
    blueOceanPhaseSprite.setPosition({ 500.f, 20.f });
    blueOceanPhaseSprite.setScale(sf::Vector2f(0.1571, 0.3504));
    cavePhaseSprite.setTexture(*(Data::getInstance()->getCavePhaseBackGround()));
    cavePhaseSprite.setPosition({ 500.f, 20.f });
    cavePhaseSprite.setScale(sf::Vector2f(0.1572, 0.3504));
    deathPhaseSprite.setTexture(*(Data::getInstance()->getDathPhaseBackGround()));
    deathPhaseSprite.setPosition({ 500.f, 20.f });
    deathPhaseSprite.setScale(sf::Vector2f(0.4297, 0.9584));

    player1Sprite.setTexture(*(Data::getInstance()->getPlayer1Texture()));
    player1Sprite.setPosition({ 550.f, 360.f });
    player2Sprite.setTexture(*(Data::getInstance()->getPlayer2Texture()));
    player2Sprite.setPosition({ 815.f, 360.f });
}

CharacterSelection::~CharacterSelection()
{
}

int CharacterSelection::Start(sf::RenderWindow& window)
{
    return phaseSelection(window);
}

int CharacterSelection::phaseSelection(sf::RenderWindow& window)
{
    menu1.setString("Beginner Phase");
    menu1.setPosition({ 100.f, 150.f });
    menu1.setCharacterSize(25);

    menu2.setString("Blue Ocean Phase");
    menu2.setPosition({ 100.f, 300.f });
    menu2.setCharacterSize(25);

    menu3.setString("Cave Phase");
    menu3.setPosition({ 100.f, 450.f });
    menu3.setCharacterSize(25);

    menu4.setString("Death Phase");
    menu4.setPosition({ 100.f, 600.f });
    menu4.setCharacterSize(25);

    int controller = 0;

    while (1)
    {
        window.clear();
        sf::Event event;
        if (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                return EXIT_GAME;
            if (event.type == sf::Event::KeyPressed)
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    controller--;
                    break;
                case sf::Keyboard::Down:
                    controller++;
                    break;

                case sf::Keyboard::Return:
                    if (controller == 0)
                        return characterSelection(window);
                    else if (controller == 1)
                        return characterSelection(window);
                    else if (controller == 2)
                        return characterSelection(window);
                    else
                        return characterSelection(window);
                }
            if (controller <= 0)
                controller = 0;
            if (controller >= 3)
                controller = 3;
        }
        updateMenuCollor(controller, window, true);
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        window.draw(menu4);
        window.display();
    }
}

int CharacterSelection::characterSelection(sf::RenderWindow& window)
{
    int controller = 0;
    int contAnimationPlayer1 = 0, controller1 = 0;
    int contAnimationPlayer2 = 0, controller2 = 0;

    menu1.setString("1 Player");
    menu1.setPosition({ 100.f, 225.f });

    menu2.setString("2 Player");
    menu2.setPosition({ 100.f, 525.f });

    // Soh arrumando a cor dos menus
    updateMenuCollor(0, window, false);

    while (1)
    {
        window.clear();
        sf::Event event;
        if (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                return EXIT_GAME;
            if (event.type == sf::Event::KeyPressed)
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    controller--;
                    break;
                case sf::Keyboard::Down:
                    controller++;
                    break;

                case sf::Keyboard::Return:
                    if (controller == 0)
                        isMultiplayer = false;
                    else if (controller == 1)
                        isMultiplayer = true;
                    return nameCharacterSelection(window);
                   }
            if (controller <= 0)
                controller = 0;
            if (controller >= 1)
                controller = 1;
        }
        player1Animation(contAnimationPlayer1, controller1);
        if (controller)
            player2Animation(contAnimationPlayer2, controller2);
        updateMenuCollor(controller, window, false);
        window.draw(menu1);
        window.draw(menu2);
        window.display();
    }
}

int CharacterSelection::nameCharacterSelection(sf::RenderWindow& window)
{
    int tabPressed = 1;
    int totalChar1 = 0, totalChar2 = 0;

    player1Name = "";
    player2Name = "";

    menu1.setPosition({ 340.f, 230.f });
    menu1.setFillColor(sf::Color(sf::Color::White));
    menu1.setCharacterSize(40);
    menu1.setString(player1Name);

    menu2.setPosition({ 340.f, 270.f });
    menu2.setFillColor(sf::Color(sf::Color::White));
    menu2.setCharacterSize(40);
    menu2.setString(player2Name);

    menu3.setPosition({ 340.f, 100.f });
    menu3.setFillColor(sf::Color(sf::Color::White));
    menu3.setCharacterSize(30);
    menu3.setString("Type your character name: (Enter to Start)");

    menu4.setPosition({ 340.f, 50.f });
    menu4.setFillColor(sf::Color(sf::Color::White));
    menu4.setCharacterSize(30);
    menu4.setString("Tab to name other player");

    while (1)
    {
        window.clear();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::TextEntered)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
                    tabPressed++;
                if (isMultiplayer)
                {
                    if (tabPressed % 2 == 1)
                        player1NameEnter(totalChar1, event);
                    else
                        player2NameEnter(totalChar2, event);
                    menu2.setString(player2Name);
                }
                else player1NameEnter(totalChar1, event);
                menu1.setString(player1Name);
            }
            // close button clicked
            if (event.type == sf::Event::Closed)
                return EXIT_GAME;

            if (event.type == sf::Event::KeyPressed)
                switch (event.key.code)
                {
                case sf::Keyboard::Return:
                    player1Name.erase(std::remove(player1Name.begin(), player1Name.end(), '\r'), player1Name.end());
                    player2Name.erase(std::remove(player2Name.begin(), player2Name.end(), '\r'), player2Name.end());
                    return PHASE_MANAGER;
                }
            if (tabPressed > 1111)
                tabPressed = 0;
        }

        if (isMultiplayer)
        {
            window.draw(menu2);
            window.draw(menu4);
        }
        window.draw(menu1);
        window.draw(menu3);
        window.display();
    }
}

void CharacterSelection::updateMenuCollor(int controller, sf::RenderWindow& window, bool isPhaseSelection)
{
    if (controller == 0)
    {
        menu1.setFillColor(sf::Color(255, 0, 0, 255));
        menu2.setFillColor(sf::Color(255, 255, 255, 255));
        menu3.setFillColor(sf::Color(255, 255, 255, 255));
        menu4.setFillColor(sf::Color(255, 255, 255, 255));
        if (isPhaseSelection) window.draw(beginnerPhaseSprite);
        else window.draw(player1Sprite);
    }
    else if (controller == 1)
    {
        menu1.setFillColor(sf::Color(255, 255, 255, 255));
        menu2.setFillColor(sf::Color(255, 0, 0, 255));
        menu3.setFillColor(sf::Color(255, 255, 255, 255));
        menu4.setFillColor(sf::Color(255, 255, 255, 255));
        if (isPhaseSelection) window.draw(blueOceanPhaseSprite);
        else
        {
            window.draw(player1Sprite);
            window.draw(player2Sprite);
        }
    }
    else if (controller == 2)
    {
        menu1.setFillColor(sf::Color(255, 255, 255, 255));
        menu2.setFillColor(sf::Color(255, 255, 255, 255));
        menu3.setFillColor(sf::Color(255, 0, 0, 255));
        menu4.setFillColor(sf::Color(255, 255, 255, 255));
        window.draw(cavePhaseSprite);
    }
    else
    {
        menu1.setFillColor(sf::Color(255, 255, 255, 255));
        menu2.setFillColor(sf::Color(255, 255, 255, 255));
        menu3.setFillColor(sf::Color(255, 255, 255, 255)); 
        menu4.setFillColor(sf::Color(255, 0, 0, 255));
        window.draw(deathPhaseSprite);
    }
}

void CharacterSelection::player1Animation(int& contAnimationPlayer1, int& controller)
{
    contAnimationPlayer1++;
    if (!(contAnimationPlayer1 % 300))
        controller++;
    if (controller > 2)
        controller = 0;
    if (contAnimationPlayer1 > 10000)
        contAnimationPlayer1 = 0;
    player1Sprite.setTextureRect(sf::IntRect(47 * controller, 48, 47, 48));
}

void CharacterSelection::player2Animation(int& contAnimationPlayer2, int& controller)
{
    contAnimationPlayer2++;
    if (!(contAnimationPlayer2 % 300))
        controller++;
    if (controller > 2)
        controller = 0;
    if (contAnimationPlayer2 > 10000)
        contAnimationPlayer2 = 0;
    player2Sprite.setTextureRect(sf::IntRect(47 * controller, 0, 47, 48));
}

void CharacterSelection::player1NameEnter(int& totalChar1, sf::Event& event)
{
    // To not take the tab
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
    {
        // If backspace is pressed, erase the char
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && (totalChar1 > 0))
            player1Name.erase(player1Name.begin() + totalChar1--);
        else if ((totalChar1 <= 14) && (totalChar1 >= 0)) // Allow any char of the ASCII table
        {
            player1Name += (char)event.text.unicode;
            totalChar1++;
        }
    }
}
void CharacterSelection::player2NameEnter(int& totalChar2, sf::Event& event)
{
    // To not take the tab
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
    {
        // If backspace is pressed, erase the char
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && (totalChar2 > 0))
            player2Name.erase(player2Name.begin() + totalChar2--);
        else if ((totalChar2 <= 14) && (totalChar2 >= -1)) // Allow any char of the ASCII table
        {
            player2Name += (char)event.text.unicode;
            totalChar2++;
        }
    }
}


void CharacterSelection::setPlayer1Name(const string name1) { player1Name = name1; }
const string CharacterSelection::getPlayer1Name() const { return player1Name; }
void CharacterSelection::setPlayer2Name(const string name2) { player2Name = name2; }
const string CharacterSelection::getPlayer2Name() const { return player2Name; }
void CharacterSelection::setIsMultiplayer(const bool multiplayer) { isMultiplayer = multiplayer; }
const bool CharacterSelection::getIsMultiplayer() const { return isMultiplayer; }




int CharacterSelection::notImplementedYet(sf::RenderWindow& window)
{
    window.clear();
    sf::Sprite notImplementedYet;
    notImplementedYet.setTexture(*(Data::getInstance()->getNotImplementedYet()));
    notImplementedYet.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
    window.draw(notImplementedYet);
    window.display();

    while (true)
    {
        sf::Event event;
        if (window.pollEvent(event))
            switch (event.type)
            {
            case sf::Event::MouseButtonPressed:
            case sf::Event::KeyPressed:
                return OPEN_MENU;
            case sf::Event::Closed:
                return -1;
            }
    }
}