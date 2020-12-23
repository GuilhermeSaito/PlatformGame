#include "characterSelection.h"

using StartScreen::CharacterSelection;

CharacterSelection::CharacterSelection()
{
    menu1.setFont(*(Data::getInstance()->getOpenMenufont()));
    menu1.setString("New Game");
    menu1.setPosition({ 500.f, 200.f });
    menu1.setCharacterSize(25);

    menu2.setFont(*(Data::getInstance()->getOpenMenufont()));
    menu2.setString("Continue");
    menu2.setPosition({ 500.f, 280.f });
    menu2.setCharacterSize(25);

    menu3.setFont(*(Data::getInstance()->getOpenMenufont()));
    menu3.setString("Ranking");
    menu3.setPosition({ 500.f, 360.f });
    menu3.setCharacterSize(25);

    menu4.setFont(*(Data::getInstance()->getOpenMenufont()));
    menu4.setString("Exit");
    menu4.setPosition({ 500.f, 420.f });
    menu4.setCharacterSize(25);
}

CharacterSelection::~CharacterSelection()
{
}

int CharacterSelection::Start(sf::RenderWindow& window)
{
    return 1;
}

int CharacterSelection::phaseSelection(sf::RenderWindow& window)
{
    return 1;
}

int CharacterSelection::characterSelection(sf::RenderWindow& window)
{
    return 1;
}