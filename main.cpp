#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <./Constants.h>
#include <stdlib.h>
#include <time.h>

using namespace sf;
using namespace std;

Vector2f getNextPosition(int currentStep, int stepsToMove, int paddingLeft, int paddingTop)
{
	const int nextStep = currentStep + stepsToMove;
	Vector2f returnValue;

	if (nextStep < 100)
	{
		returnValue.x = paddingLeft + STEP_SIZE_X * POSITIONS[nextStep][0];
		returnValue.y = paddingTop + STEP_SIZE_Y * POSITIONS[nextStep][1];
	}
	else
	{
		returnValue.x = -1;
		returnValue.y = -1;
	}

	return returnValue;
}

int readInput()
{
	cout << "Welcome to the Game\n";
	cout << "Please Enter the Number of Players:\n";
	cout << "Valid numbers are 1, 2 and 3:\n";

	char stdin_c;

	do {
		cin >> stdin_c;
		if (stdin_c != '1' && stdin_c != '2' && stdin_c != '3')
		{
			cout << "Valid numbers are 1, 2 and 3:\n";
		}
	} while (stdin_c != '1' && stdin_c != '2' && stdin_c != '3');

	return stdin_c == '1' ? 1 : stdin_c == '2' ? 2 : 3;
}

int main()
{
	//Players
	Texture player1Texture;
	Texture player2Texture;
	Texture player3Texture;

	Sprite player1;
	Sprite player2;
	Sprite player3;
	Sprite currentPlayerSprite;

	//Dice
	Texture diceTexture1;
	Texture diceTexture2;
	Texture diceTexture3;
	Texture diceTexture4;
	Texture diceTexture5;
	Texture diceTexture6;
	Texture goTexture;
	Sprite dice;

	//Background
	Texture backgroundTexture;
	Sprite background;

	//Board
	Texture boardTexture;
	Sprite board;

	//Fonts
	Font titleFont;
	Font subTitleFont;
	Font stepFont;

	srand(time(NULL));
	int playerCount = readInput();

	int currentPlayer = 0;
	int playerProgress[3] = { 0, 0, 0 };
	bool someoneWon = false;

	// create the window
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(1100, 800), "Game", Style::Close, settings);

	bool allGood = backgroundTexture.loadFromFile("Images/background.jpg") &&
		boardTexture.loadFromFile("Images/board.png") &&
		diceTexture1.loadFromFile("Images/1.png") &&
		diceTexture2.loadFromFile("Images/2.png") &&
		diceTexture3.loadFromFile("Images/3.png") &&
		diceTexture4.loadFromFile("Images/4.png") &&
		diceTexture5.loadFromFile("Images/5.png") &&
		diceTexture6.loadFromFile("Images/6.png") &&
		goTexture.loadFromFile("Images/Go.png") &&
		player1Texture.loadFromFile("Images/Player1.png") &&
		player2Texture.loadFromFile("Images/Player2.png") &&
		player3Texture.loadFromFile("Images/Player3.png") &&
		titleFont.loadFromFile("Fonts/Gentle.otf") &&
		subTitleFont.loadFromFile("Fonts/Lulusma.otf") &&
		stepFont.loadFromFile("Fonts/Lulusma-Bold.otf");

	if (!allGood)
	{
		return -1;
	}
	else
	{
		player1.setTexture(player1Texture);
		player1.setScale(0.5, 0.5);
		player2.setTexture(player2Texture);
		player2.setScale(0.5, 0.5);
		player3.setTexture(player3Texture);
		player3.setScale(0.5, 0.5);
		//set initial position
		player1.setPosition(PLAYER_ONE_PADDING_LEFT + STEP_SIZE_X * 0, PLAYER_ONE_PADDING_TOP + STEP_SIZE_Y * 9);
		player2.setPosition(PLAYER_TWO_PADDING_LEFT + STEP_SIZE_X * 0, PLAYER_TWO_PADDING_TOP + STEP_SIZE_Y * 9);
		player3.setPosition(PLAYER_THREE_PADDING_LEFT + STEP_SIZE_X * 0, PLAYER_THREE_PADDING_TOP + STEP_SIZE_Y * 9);

		Sprite players[3] = { player1, player2, player3 };
		Texture playerTextures[3] = { player1Texture, player2Texture, player3Texture };

		diceTexture1.setSmooth(true);
		diceTexture2.setSmooth(true);
		diceTexture3.setSmooth(true);
		diceTexture4.setSmooth(true);
		diceTexture5.setSmooth(true);
		diceTexture6.setSmooth(true);
		player1Texture.setSmooth(true);
		playerTextures[0].setSmooth(true);
		playerTextures[1].setSmooth(true);
		playerTextures[2].setSmooth(true);
		player2Texture.setSmooth(true);
		player3Texture.setSmooth(true);
		backgroundTexture.setSmooth(true);
		boardTexture.setSmooth(true);
		goTexture.setSmooth(true);

		dice.setTexture(goTexture);
		currentPlayerSprite.setTexture(playerTextures[currentPlayer]);
		Texture textures[6] = { diceTexture1, diceTexture2, diceTexture3, diceTexture4, diceTexture5, diceTexture6 };

		float dicePositionX = (GAME_MAX_WIDTH - BOARD_MAX_WIDTH) / 2.0f + BOARD_MAX_WIDTH;
		float dicePositionY = 200;

		float currentPlayerPositionX = (GAME_MAX_WIDTH - BOARD_MAX_WIDTH) / 2.0f + BOARD_MAX_WIDTH;
		float currentPlayerPositionY = 75;

		FloatRect playerRect = currentPlayerSprite.getLocalBounds();
		currentPlayerSprite.setOrigin(playerRect.left + playerRect.width / 2.0f,
			playerRect.top + playerRect.height / 2.0f);

		currentPlayerSprite.setPosition(sf::Vector2f(currentPlayerPositionX, currentPlayerPositionY));

		FloatRect diceRect = dice.getLocalBounds();
		dice.setOrigin(diceRect.left + diceRect.width / 2.0f,
			diceRect.top + diceRect.height / 2.0f);

		dice.setPosition(sf::Vector2f(dicePositionX, dicePositionY));

		//Initial Text
		Text text;
		text.setFont(titleFont);
		text.setCharacterSize(20); // in pixels, not points!
		text.setFillColor(Color::White);

		char buffer[100];
		sprintf_s(buffer, "Click Go to Begin");
		text.setString(buffer);
		float textPositionX = (GAME_MAX_WIDTH - BOARD_MAX_WIDTH) / 2.0f + BOARD_MAX_WIDTH;
		float textPositionY = text.getLocalBounds().height;
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);
		text.setPosition(sf::Vector2f(textPositionX, textPositionY));

		float helperTextPositionX = BOARD_MAX_WIDTH + 10;
		float helperTextPositionY = GAME_MAX_HEIGHT - 60;
		Text helperText;
		helperText.setFont(subTitleFont);
		helperText.setCharacterSize(18); // in pixels, not points!
		helperText.setFillColor(Color::Yellow);
		helperText.setPosition(helperTextPositionX, helperTextPositionY);

		float helperText2PositionX = BOARD_MAX_WIDTH + 10;
		float helperText2PositionY = GAME_MAX_HEIGHT - 30;
		Text helperText2;
		helperText2.setFont(subTitleFont);
		helperText2.setCharacterSize(14); // in pixels, not points!
		helperText2.setFillColor(Color::White);
		helperText2.setPosition(helperText2PositionX, helperText2PositionY);

		background.setTexture(backgroundTexture);
		board.setTexture(boardTexture);

		Text numbering[100];
		int textCurrentPosition = -1;

		for (int i = 0; i < 100; i++)
		{
			char buffer[10];
			Vector2f currentPos = getNextPosition(textCurrentPosition++, 1, 0, 0);

			if (currentPos.x != -1)
			{
				sprintf_s(buffer, "%d", i + 1);
				numbering[i].setString(buffer);
				numbering[i].setFont(stepFont);
				numbering[i].setCharacterSize(10); // in pixels, not points!
				numbering[i].setFillColor(Color(0x0, 0x0, 0x0, 90));

				//Set the numbering and add padding of 2 pixels on left and top
				numbering[i].setPosition(currentPos.x + 2, currentPos.y + 2);
			}
		}

		Clock clock;
		// run the program as long as the window is open
		while (window.isOpen())
		{
			// check all the window's events that were triggered since the last iteration of the loop
			Event event;
			while (window.pollEvent(event))
			{
				// "close requested" event: we close the window
				if (event.type == Event::Closed)
					window.close();

				if (Mouse::isButtonPressed(Mouse::Left))
				{
					//Is Dice Clicked
					if (!someoneWon && event.mouseButton.x >= dicePositionX - 18 && event.mouseButton.x <= dicePositionX - 18 + diceTexture1.getSize().x && event.mouseButton.y >= dicePositionY - 18 && event.mouseButton.y <= dicePositionY - 18 + diceTexture1.getSize().y)
					{
						int number = rand() % 6;
						dice.setTexture(textures[number]);

						int stepsToMove = number + 1;
						Vector2f newPos = getNextPosition(playerProgress[currentPlayer], stepsToMove, paddings[currentPlayer][0], paddings[currentPlayer][1]);

						if (newPos.x != -1)
						{
							//We got a valid position
							playerProgress[currentPlayer] = playerProgress[currentPlayer] + stepsToMove;

							players[currentPlayer].setPosition(newPos);
							char buffer[100];
							sprintf_s(buffer, "Player %d rolled a %d", currentPlayer + 1, number + 1);
							helperText.setString(buffer);

							char buffer2[100];
							sprintf_s(buffer2, "Player %d new Position is %d", currentPlayer + 1, playerProgress[currentPlayer] + 1);
							helperText2.setString(buffer2);
						}
						else
						{
							//We got an in-valid position, the user cannot move
							char buffer[100];
							sprintf_s(buffer, "Player %d cannot move forward", currentPlayer + 1);
							helperText.setString(buffer);

							char buffer2[100];
							sprintf_s(buffer2, "since Player %d rolled a %d", currentPlayer + 1, number + 1);
							helperText2.setString(buffer2);
						}

						if (playerProgress[currentPlayer] < 99)
						{
							//Current Player has not Won
							switch (playerCount)
							{
							case 2:
								currentPlayer = currentPlayer == 0 ? 1 : 0;
								break;
							case 3:
								currentPlayer = currentPlayer == 0 ? 1 : currentPlayer == 1 ? 2 : 0;
								break;
							default:
								break;
							}

							sprintf_s(buffer, "Player %d Turn", currentPlayer + 1);
							text.setString(buffer);
							sf::FloatRect textRect = text.getLocalBounds();
							text.setOrigin(textRect.left + textRect.width / 2.0f,
								textRect.top + textRect.height / 2.0f);

							text.setPosition(sf::Vector2f(textPositionX, textPositionY));

							currentPlayerSprite.setTexture(playerTextures[currentPlayer]);
						}
						else
						{
							//Current Player has Won
							sprintf_s(buffer, "Player %d Won!", currentPlayer + 1);
							text.setString(buffer);
							text.setCharacterSize(20);
							text.setFillColor(Color::Yellow);
							sf::FloatRect textRect = text.getLocalBounds();
							text.setOrigin(textRect.left + textRect.width / 2.0f,
								textRect.top + textRect.height / 2.0f);

							text.setPosition(sf::Vector2f(textPositionX, textPositionY));
							someoneWon = true;
						}
					}
				}
			}

			// clear the window with black color
			window.clear();
			window.draw(background);
			window.draw(board);

			for (int i = 0; i < playerCount; i++)
			{
				window.draw(players[i]);
			}

			window.draw(text);
			window.draw(helperText2);
			window.draw(helperText);
			window.draw(dice);
			window.draw(currentPlayerSprite);

			for (int i = 0; i < 100; i++)
			{
				window.draw(numbering[i]);
			}

			if (someoneWon)
			{
				//If someone won, show a little animation
				float seconds = clock.getElapsedTime().asSeconds();
				if (seconds > 0.5)
				{
					Color color = text.getFillColor();
					Color newColor = color == Color::White ? Color::Yellow : Color::White;
					text.setFillColor(newColor);

					clock.restart();
				}
			}

			// end the current frame
			window.display();
		}
	}

	return 0;
}