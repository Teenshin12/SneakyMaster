#include "GUIManager.h"
#include <iostream>

GUIManager::GUIManager(sf::Vector2f resolution, int characterSize, int textPosition){
    font.loadFromFile("fonts/font.ttf");
    this->resolution = resolution;
    this->characterSize = characterSize;
    this->textPosition = textPosition;

    unTouched = {255,255,255};
    Touched = {0,0,102};
}

void GUIManager::setMenu(){

    texts.clear();

    sf::Text play;
    font.loadFromFile("fonts/font.ttf");
    play.setFont(font);
    play.setCharacterSize(characterSize);
    play.setString("PLAY");
    play.setFillColor(unTouched);
    sf::FloatRect textRect = play.getLocalBounds();
    play.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    play.setPosition(sf::Vector2f(resolution.x/2.0f, textPosition + characterSize*(texts.size()+1)));
    texts.emplace_back(play);

    sf::Text settings;
    settings.setFont(font);
    settings.setCharacterSize(characterSize);
    settings.setString("SETTINGS");
    settings.setFillColor(unTouched);
    textRect = settings.getLocalBounds();
    settings.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    settings.setPosition(sf::Vector2f(resolution.x/2.0f, textPosition + characterSize*(texts.size()+1)));
    texts.emplace_back(settings);

    sf::Text quit;
    quit.setFont(font);
    quit.setCharacterSize(characterSize);
    quit.setString("QUIT");
    quit.setFillColor(unTouched);
    textRect = quit.getLocalBounds();
    quit.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    quit.setPosition(sf::Vector2f(resolution.x/2.0f, textPosition + characterSize*(texts.size()+1)));
    texts.emplace_back(quit);

    scene = 0;
}

void GUIManager::setSettings(){

    texts.clear();

    sf::Text resolutions;
    font.loadFromFile("fonts/font.ttf");
    resolutions.setFont(font);
    resolutions.setCharacterSize(characterSize / 2);
    resolutions.setString("RESOLUTIONS");
    resolutions.setFillColor(unTouched);
    sf::FloatRect textRect = resolutions.getLocalBounds();
    resolutions.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    resolutions.setPosition(sf::Vector2f(resolution.x/2.0f, textPosition + characterSize / 2*(texts.size()+1)));
    texts.emplace_back(resolutions);

    sf::Text firstRes;
    firstRes.setFont(font);
    firstRes.setCharacterSize(characterSize / 2);
    firstRes.setString("800 x 600");
    firstRes.setFillColor(unTouched);
    textRect = firstRes.getLocalBounds();
    firstRes.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    firstRes.setPosition(sf::Vector2f(resolution.x/2.0f, textPosition + characterSize / 2*(texts.size()+1)));
    texts.emplace_back(firstRes);

    sf::Text secondRes;
    secondRes.setFont(font);
    secondRes.setCharacterSize(characterSize / 2);
    secondRes.setString("1920 x 1080");
    secondRes.setFillColor(unTouched);
    textRect = secondRes.getLocalBounds();
    secondRes.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    secondRes.setPosition(sf::Vector2f(resolution.x/2.0f, textPosition + characterSize / 2*(texts.size()+1)));
    texts.emplace_back(secondRes);

    sf::Text thirdRes;
    thirdRes.setFont(font);
    thirdRes.setCharacterSize(characterSize / 2);
    thirdRes.setString("2560 x 1440");
    thirdRes.setFillColor(unTouched);
    textRect = thirdRes.getLocalBounds();
    thirdRes.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    thirdRes.setPosition(sf::Vector2f(resolution.x/2.0f, textPosition + characterSize / 2*(texts.size()+1)));
    texts.emplace_back(thirdRes);

    sf::Text setFullScreen;
    setFullScreen.setFont(font);
    setFullScreen.setCharacterSize(characterSize / 2);
    if(windowFullscreen == true)setFullScreen.setString("FULLSCREEN - ON");
    else setFullScreen.setString("FULLSCREEN - OFF");
    setFullScreen.setFillColor(unTouched);
    textRect = setFullScreen.getLocalBounds();
    setFullScreen.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    setFullScreen.setPosition(sf::Vector2f(resolution.x/2.0f, textPosition + characterSize / 2*(texts.size()+1)));
    texts.emplace_back(setFullScreen);

    sf::Text apply;
    apply.setFont(font);
    apply.setCharacterSize(characterSize / 2);
    apply.setString("APPLY");
    apply.setFillColor(unTouched);
    textRect = apply.getLocalBounds();
    apply.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    apply.setPosition(sf::Vector2f(resolution.x/2.0f, textPosition + characterSize / 2*(texts.size()+1)));
    texts.emplace_back(apply);

    sf::Text back;
    back.setFont(font);
    back.setCharacterSize(characterSize / 2);
    back.setString("BACK");
    back.setFillColor(unTouched);
    textRect = back.getLocalBounds();
    back.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    back.setPosition(sf::Vector2f(resolution.x/2.0f, textPosition + characterSize / 2*(texts.size()+1)));
    texts.emplace_back(back);

    scene = 1;
}

int GUIManager::checkLMB(sf::RenderWindow &window){
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
    if(mouseButtonReleased){
        if(scene == 0){
            if(worldPos.y > texts[0].getPosition().y - (characterSize/2 - 5) && worldPos.y < texts[0].getPosition().y + (characterSize/2 - 10)){
                texts[0].setFillColor(Touched);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    return 0;
                    mouseButtonReleased = false;
                }
            }
            else if(worldPos.y > texts[1].getPosition().y - (characterSize/2 - 5) && worldPos.y < texts[1].getPosition().y + (characterSize/2 - 10)){
                texts[1].setFillColor(Touched);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    return 1;
                    mouseButtonReleased = false;
                }
            }
            else if(worldPos.y > texts[2].getPosition().y - (characterSize/2 - 5) && worldPos.y < texts[2].getPosition().y + (characterSize/2 - 10)){
                texts[2].setFillColor(Touched);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    return 2;
                    mouseButtonReleased = false;
                }
            }
            else {
                for(int i = 0; i < (int)texts.size(); i++){
                     texts[i].setFillColor(unTouched);
                }
            }
        }
        else if(scene == 1){
            if(worldPos.y > texts[1].getPosition().y - (characterSize/4 - 5) && worldPos.y < texts[1].getPosition().y + (characterSize/4 - 5)){
                texts[1].setFillColor(Touched);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    resToSet = {800,600};
                    mouseButtonReleased = false;
                    return 3;
                }
            }
            else if(worldPos.y > texts[2].getPosition().y - (characterSize/4 - 5) && worldPos.y < texts[2].getPosition().y + (characterSize/4 - 5)){
                texts[2].setFillColor(Touched);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    resToSet = {1920,1080};
                    mouseButtonReleased = false;
                    return 4;
                }
            }
            else if(worldPos.y > texts[3].getPosition().y - (characterSize/4 - 5) && worldPos.y < texts[3].getPosition().y + (characterSize/4 - 5)){
                texts[3].setFillColor(Touched);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    resToSet = {2560,1440};
                    mouseButtonReleased = false;
                    return 5;
                }
            }
            else if(worldPos.y > texts[4].getPosition().y - (characterSize/4 - 5) && worldPos.y < texts[4].getPosition().y + (characterSize/4 - 5)){
                texts[4].setFillColor(Touched);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    mouseButtonReleased = false;
                    windowFullscreen = not windowFullscreen;
                    if(windowFullscreen == true)texts[4].setString("FULLSCREEN - ON");
                    else texts[4].setString("FULLSCREEN - OFF");
                    return 6;
                }
            }
            else if(worldPos.y > texts[5].getPosition().y - (characterSize/4 - 5) && worldPos.y < texts[5].getPosition().y + (characterSize/4 - 5)){
                texts[5].setFillColor(Touched);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    mouseButtonReleased = false;
                    resolution = resToSet;
                    return 7;
                }
            }
            else if(worldPos.y > texts[6].getPosition().y - (characterSize/4 - 5) && worldPos.y < texts[6].getPosition().y + (characterSize/4 - 5)){
                texts[6].setFillColor(Touched);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    mouseButtonReleased = false;
                    return 8;
                }
            }
            else{
                for(int i = 0; i < (int)texts.size(); i++){
                     texts[i].setFillColor(unTouched);
                }
            }
        }
    }
    else{
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) == false){
            mouseButtonReleased = true;
        }
    }

    std::cout << resolution.x << resolution.y << std::endl;

    return 100;
}

void GUIManager::draw(sf::RenderWindow &window){
    for(int i = 0; i < (int)texts.size(); i++){
        window.draw(texts[i]);
    }
}