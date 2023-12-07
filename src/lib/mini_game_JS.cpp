#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <cstdlib>

using namespace sf;
using namespace std;
class AvoidPoop
{

public:
    static bool startGame(RenderWindow *window)
    {

        // 난수 생성을 위한 초기화
        srand(time(NULL));

        // 물 텍스처 및 스프라이트 설정
        Texture waterTex;
        Sprite water;

        Texture fireTex;
        Sprite fire;

        // 물 텍스처 로드
        if (!waterTex.loadFromFile("../../assets/mini_game/water.png"))
        {
            throw "could not load water";
        }
        water.setTexture(waterTex);
        water.setScale(Vector2f(0.08f, 0.08f));

        if (!fireTex.loadFromFile("../../assets/mini_game/fire.png"))
        {
            throw "could not load fire";
        }
        fire.setTexture(fireTex);
        fire.setScale(Vector2f(0.08f, 0.08f));

        // 물 스프라이트를 저장하는 벡터 생성
        vector<Sprite> waters;
        waters.push_back(Sprite(water));

        vector<Sprite> fires;
        fires.push_back(Sprite(fire));

        // 물 생성 타이머 초기화
        int waterSpawnTimer = 15;

        int fireSpawnTimer = 30;

        // 양동이 텍스처 및 스프라이트 설정
        Texture bucketTex;
        Sprite bucket;

        // 양동이 텍스처 로드
        if (!bucketTex.loadFromFile("../../assets/mini_game/bucket.png"))
        {
            throw "could not load bucket";
        }

        // 양동이 스프라이트 초기화
        bucket.setTexture(bucketTex);
        bucket.setScale(Vector2f(0.5f, 0.5f));

        // 물량을 나타내는 직사각형 설정
        RectangleShape waterAmount;
        RectangleShape newWaterAmount;
        waterAmount.setSize(Vector2f(30, 30));
        waterAmount.setFillColor(Color::Blue);

        RectangleShape fireAmount;
        RectangleShape newFireAmount;
        fireAmount.setSize(Vector2f(30, 30));
        fireAmount.setFillColor(Color::Red);

        // 물량을 저장하는 벡터 생성
        vector<RectangleShape> waterAmounts;
        vector<RectangleShape> fireAmounts;

        // 게임 루프
        while (window->isOpen())
        {
            // 이벤트 처리
            Event event;
            while (window->pollEvent(event))
            {
                if (event.type == Event::Closed)
                {
                    window->close();
                }
                if (event.KeyPressed && event.key.code == Keyboard::Escape)
                {
                    return false;
                }
            }

            // 양동이 이동 처리
            if (waterAmounts.size() < 100 && fireAmounts.size() > 0)
            {
                float mouseX = Mouse::getPosition(*window).x;
                float bucketWidth = bucket.getLocalBounds().width * 0.15;

                // 마우스 위치를 벗어나지 않도록 좌우 제한 설정
                if (mouseX < bucketWidth)
                {
                    bucket.setPosition(0, window->getSize().y - bucket.getLocalBounds().height);
                }
                else if (mouseX > window->getSize().x - bucketWidth)
                {
                    bucket.setPosition(window->getSize().x - bucket.getLocalBounds().width, window->getSize().y - bucket.getLocalBounds().height);
                }
                else
                {
                    bucket.setPosition(mouseX - bucketWidth, window->getSize().y - bucket.getLocalBounds().height);
                }
            }
            if (waterAmounts.size() > 100)
            {
                // 물량이 100 이상이면 게임 종료
                sf::sleep(seconds(1));
                return true;
            }
            if (fireAmounts.size() > 100)
            {
                sf::sleep(seconds(1));
                return false;
            }

            // 물 스프라이트 이동 및 화면 벗어난 스프라이트 재설정
            for (size_t i = 0; i < waters.size(); i++)
            {
                waters[i].move(0, 8);
                if (waters[i].getPosition().y > window->getSize().y)
                {
                    waters[i].setPosition(rand() % int(window->getSize().x - (water.getLocalBounds().width * 0.1)), 0);
                }
            }

            // 물 생성 타이머 관리
            if (waterSpawnTimer < 17)
            {
                waterSpawnTimer++;
            }
            if (waterSpawnTimer >= 17)
            {
                water.setPosition(rand() % int(window->getSize().x - (water.getLocalBounds().width * 0.1)), 0);
                waters.push_back(Sprite(water));
                waterSpawnTimer = 0;
            }

            // 불 스프라이트 이동 및 화면 벗어난 스프라이트 재설정
            for (size_t i = 0; i < fires.size(); i++)
            {
                fires[i].move(0, 8);
                if (fires[i].getPosition().y > window->getSize().y)
                {
                    fires[i].setPosition(rand() % int(window->getSize().x - (fire.getLocalBounds().width * 0.1)), 0);
                }
            }

            // 불 생성 타이머 관리
            if (fireSpawnTimer < 30)
            {
                fireSpawnTimer++;
            }
            if (fireSpawnTimer >= 30)
            {
                fire.setPosition(rand() % int(window->getSize().x - (fire.getLocalBounds().width * 0.1)), 0);
                fires.push_back(Sprite(fire));
                fireSpawnTimer = 0;
            }

            // 물과 양동이의 충돌 검사 및 물량 증가 처리
            for (size_t i = 0; i < waters.size(); i++)
            {
                if (bucket.getGlobalBounds().intersects(waters[i].getGlobalBounds()))
                {
                    for (int j = 0; j < 5; j++)
                    {
                        newWaterAmount = waterAmount;
                        if (!waterAmounts.empty())
                        {
                            float currentX = waterAmounts.back().getPosition().x;
                            newWaterAmount.setPosition(Vector2f(currentX + (j * 5), 0));
                        }
                        else
                        {
                            newWaterAmount.setPosition(Vector2f((window->getSize().x - 540) + (j * 30), 0));
                        }
                        waterAmounts.push_back(newWaterAmount);
                    }
                    waters[i].setPosition(rand() % int(window->getSize().x - (water.getLocalBounds().width * 0.1)), 0);
                    break;
                }
            }

            for (size_t i = 0; i < fires.size(); i++)
            {
                if (bucket.getGlobalBounds().intersects(fires[i].getGlobalBounds()))
                {
                    for (int j = 0; j < 5; j++)
                    {
                        newFireAmount = fireAmount;
                        if (!fireAmounts.empty())
                        {
                            float currentX = fireAmounts.back().getPosition().x;
                            newFireAmount.setPosition(Vector2f(currentX + (j * 5), 30));
                        }
                        else
                        {
                            newFireAmount.setPosition(Vector2f((window->getSize().x - 540) + (j * 30), 30));
                        }
                        fireAmounts.push_back(newFireAmount);
                    }
                    fires[i].setPosition(rand() % int(window->getSize().x - (fire.getLocalBounds().width * 0.1)), 0);
                }
            }

            // 화면 지우고 그리기
            window->clear(Color::White);

            window->draw(bucket);
            for (size_t i = 0; i < waters.size(); i++)
            {
                window->draw(waters[i]);
            }
            for (size_t i = 0; i < fires.size(); i++)
            {
                window->draw(fires[i]);
            }

            // 모든 물량을 그림
            for (size_t i = 0; i < waterAmounts.size(); i++)
            {
                window->draw(waterAmounts[i]);
            
            }
            // 모든 불량을 그림
            for (size_t i = 0; i < fireAmounts.size(); i++)
            {
        
                window->draw(fireAmounts[i]);
            }

            window->display();
        }

        return true;
    }
};