#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <./Constants.h>

sf::Vector2f getNextPosition(int currentStep, int stepsToMove)
{
    const int nextStep = currentStep + stepsToMove;
    sf::Vector2f returnValue;

    if (nextStep < 64)
    {
        returnValue.x = PADDING_LEFT + STEP_SIZE_X * POSITIONS[nextStep][0];
        returnValue.y = PADDING_TOP + STEP_SIZE_Y * POSITIONS[nextStep][1];
    }
    else
    {
        returnValue.x = -1;
        returnValue.y = -1;
    }

    return returnValue;
}

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(1100, 800), "Game", sf::Style::Close);
    sf::Font font;
    sf::Texture backgroundTexture;
    sf::Texture boardTexture;
    sf::Texture playerTexture;
    sf::Sprite background;
    sf::Sprite board;
    sf::Sprite player;
    sf::Vector2u textureSize;  //Added to store texture size.
    sf::Vector2u windowSize;   //Added to store window size.
    sf::Text text;
    sf::Clock clock;
    int currentStep = 0;

    bool allGood = backgroundTexture.loadFromFile("Images/background.jpg") && boardTexture.loadFromFile("Images/board.png") && playerTexture.loadFromFile("Images/player.png") && font.loadFromFile("Fonts/Gentle.otf");

    if (!allGood)
    {
        return -1;
    }
    else
    {
        text.setFont(font); // font is a sf::Font
        text.setCharacterSize(24); // in pixels, not points!
        text.setFillColor(sf::Color::White);

        char buffer[500];
        sprintf_s(buffer, "Welcome to the Game");
        text.setString(buffer);
        float textPositionX = GAME_MAX_WIDTH - text.getLocalBounds().width - 25;
        float textPositionY = text.getLocalBounds().height;
        text.setPosition(textPositionX, textPositionY);

        textureSize = backgroundTexture.getSize(); //Get size of texture.
        windowSize = window.getSize();            //Get size of window.

        float ScaleX = (float)windowSize.x / textureSize.x;
        float ScaleY = (float)windowSize.y / textureSize.y;     //Calculate scale.

        background.setTexture(backgroundTexture);
        background.setScale(ScaleX, ScaleY);

        board.setTexture(boardTexture);
        board.setScale(sf::Vector2f(0.39, 0.39));

        player.setTexture(playerTexture);
        player.setScale(PLAYER_SIZE_X, PLAYER_SIZE_Y);

        //set initial position
        player.setPosition(PADDING_LEFT + STEP_SIZE_X * 0, PADDING_TOP + STEP_SIZE_Y * 7);

        playerTexture.setSmooth(true);
        backgroundTexture.setSmooth(true);

        // run the program as long as the window is open
        while (window.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // clear the window with black color
            window.clear();
            window.draw(background);
            window.draw(board);
            window.draw(player);
            window.draw(text);

            float seconds = clock.getElapsedTime().asSeconds();
            if (seconds > 0.5)
            {
                sf::Vector2f nextPos = getNextPosition(currentStep++, 1);

                if (nextPos.x != -1)
                {
                    player.setPosition(nextPos);
                }

                clock.restart();
            }

            // end the current frame
            window.display();
        }
    }

    return 0;
}