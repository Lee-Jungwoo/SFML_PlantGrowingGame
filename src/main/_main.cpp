// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <string>
// #include "../lib/State.h"
// #include "../lib/Resource.h"
// #include "../lib/BackGround.h"

// using namespace sf;

// void day_stage(GameState &);
// void printVectors(std::vector<PlantSpecies>);

// int main()
// {

//     GameState state;
//     state.fillMoney();
//     for (int i = 0; i < 2; i++)
//     {
//         state.buyNewPlant(1);
//         state.buyNewPlant(1);
//         state.buyNewPlant(1);
//         state.buyNewPlant(1);

//         state.getPlantSlot(0)->getPlant()->bloom();
//         state.getPlantSlot(1)->getPlant()->bloom();
//         state.getPlantSlot(2)->getPlant()->bloom();
//         state.getPlantSlot(3)->getPlant()->bloom();
//         state.nextDay();

//     }

//     RenderWindow *window = new RenderWindow(VideoMode(540, 900), "game");

//     state.buyNewPlant(1);
//     state.buyNewPlant(1);
//     state.buyNewPlant(1);
//     state.buyNewPlant(1);
//     while (window->isOpen())
//     {

//         Event event;
//         window->clear(Color(220, 255, 191, 255));

//         while (window->pollEvent(event))
//         {
//             if (event.type == Event::Closed)
//                 window->close();
//             if (event.type == Event::MouseButtonPressed)
//             {

//                 switch (event.key.code)
//                 {
//                 case Mouse::Left:
//                 {

//                     day_stage(state);
//                     // state.make_next_available();
//                     for (int i = 0; i < 4; i++)
//                     {
//                         state.getPlantSlot(i)->getPlant()->skipThisTime();
//                     }
//                     state.nextDay();

//                     // printVectors(state.getA());
//                     // std::cout << "--------------------------------------------------------------------------------" << std::endl;
//                     // printVectors(state.getB());
//                     // std::cout << "--------------------------------------------------------------------------------" << std::endl;
//                     // printVectors(state.getC());
//                 }

//                 break;
//                 default:
//                     break;
//                 }
//             }
//         }
//         // window->draw(s);
//         window->draw(*state.getPlantSlot(3)->getSprite());
//         window->display();
//     }

//     return 0;
// }

// void day_stage(GameState &state)
// {
//     std::cout << state.getCurrentDay() << std::endl;
//     switch (state.getCurrentStage())
//     {
//     case Stage::Desert:
//         std::cout << "desert" << std::endl;
//         break;
//     case Stage::Temperate:
//         std::cout << "temperate" << std::endl;
//         break;

//     case Stage::Tropical:
//         std::cout << "Tropical" << std::endl;
//         break;
//     default:
//         break;
//     }
// }

// void printVectors(std::vector<PlantSpecies> v)
// {
//     for (int i = 0; i < v.size(); i++)
//     {
//         std::cout << Resource::getName(v[i]) << std::endl;
//     }
// }