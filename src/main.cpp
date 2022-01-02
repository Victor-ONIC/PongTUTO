#include "main.h"

    // Création des variables
    sf::RenderWindow window;
    Input input;
    sf::Font font;
    sf::Text txt;

    float LPaddleX = 50;
    float LPaddleY = HEIGHT / 2;
    float RPaddleX = WIDTH - 70;
    float RPaddleY = LPaddleY;
    int PaddleHeight = 150;
    int PaddleWidth = 20;
    float PaddleSpeed = 0.26f;

    float BallX = WIDTH / 2;
    float BallY = HEIGHT / 2;
    float BallSpeed = 0.050f;
    sf::Vector2f BallDirection = sf::Vector2f(1.5f, 2.0f);

    int score1 = 0;
    int score2 = 0;


void PaddleIA() {
    RPaddleY = BallY;
}

void UpdateBall() {

    BallX += BallDirection.x * BallSpeed;
    BallY += BallDirection.y * BallSpeed;

    // Collision avec les raquettes
    if ((BallX < LPaddleX + PaddleWidth && BallX > LPaddleX &&
         BallY + 7 < LPaddleY + PaddleHeight && BallY + 7 > LPaddleY) ||
        (BallX > RPaddleX - PaddleWidth && BallX < RPaddleX &&
         BallY + 7 < RPaddleY + PaddleHeight && BallY + 7 > RPaddleY)) {
        BallDirection.x *= -1;
    }

    // Collision avec les murs
    if (BallX < 0) {
        score2++;
        BallX = WIDTH / 2;
        BallY = HEIGHT / 2;
        BallDirection.x = std::fabs(BallDirection.x);
        BallDirection.y *= -1;
        SetText(txt, std::to_string(score1) + " | " + std::to_string(score2));
    }

    if (BallX > WIDTH) {
        score1++;
        BallX = WIDTH / 2;
        BallY = HEIGHT / 2;
        BallDirection.x = -std::fabs(BallDirection.x);
        BallDirection.y *= -1;
        SetText(txt, std::to_string(score1) + " | " + std::to_string(score2));
    }

    if (BallY > HEIGHT || BallY < 0) {
        BallDirection.y *= -1;
    }
}

int main() {
    // Init
    window.create(sf::VideoMode(WIDTH, HEIGHT, 32), "PONGTUTO",
                  sf::Style::Default);
    font.loadFromFile("src/res/Roboto-Regular.ttf");
    SetText(txt, std::to_string(score1) + " | " + std::to_string(score2));

    // Formes
    sf::CircleShape Ball(15);
    Ball.setPosition(BallX, BallY);

    sf::RectangleShape LPaddle(sf::Vector2f(PaddleWidth, PaddleHeight));
    LPaddle.setPosition(LPaddleX, LPaddleY);
    sf::RectangleShape RPaddle(sf::Vector2f(PaddleWidth, PaddleHeight));
    RPaddle.setPosition(RPaddleX, RPaddleY);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            input.InputHandler(event, window);

        }

        CheckBtn();
        PaddleIA();  // 

        LPaddle.setPosition(LPaddleX, LPaddleY);
        RPaddle.setPosition(RPaddleX, RPaddleY);

        UpdateBall();

        Ball.setPosition(BallX, BallY);

        window.clear(sf::Color::Black);
        window.draw(txt);
        window.draw(Ball);
        window.draw(LPaddle);
        window.draw(RPaddle);
        window.display();

    }

    return 0;
}

void SetText(sf::Text &txt, sf::String str) {

    txt.setFont(font);
    txt.setString(str);
    txt.setCharacterSize(26);
    txt.setFillColor(sf::Color::White);
    txt.setPosition((WIDTH / 2) - 40, 10);

}

void CheckBtn() {

    // Raquette gauche
    if (input.GetButton().up == true) {

        LPaddleY -= PaddleSpeed;
        if (LPaddleY < 0) {
            LPaddleY = 0;
        }

    }

    if (input.GetButton().down == true) {

        LPaddleY += PaddleSpeed;
        if (LPaddleY + PaddleHeight > HEIGHT) {
            LPaddleY = HEIGHT - PaddleHeight;
        }

    }

    // Raquette droite
    if (input.GetButton().left == true) {

        RPaddleY += PaddleSpeed;
        if (RPaddleY + PaddleHeight > HEIGHT) {
            RPaddleY = HEIGHT - PaddleHeight;
        } 

    }

    if (input.GetButton().right == true) {

        RPaddleY -= PaddleSpeed;
        if (RPaddleY < 0) {
            RPaddleY = 0;
        }

    }

    if (input.GetButton().escape == true) {
        window.close();
    }

}