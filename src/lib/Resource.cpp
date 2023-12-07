#include "Resource.h"
#include <string>
#include <iostream>
std::map<Stage, std::vector<PlantSpecies> *> Resource::plantByStage = {

    {Stage::Desert,
     new std::vector<PlantSpecies>{
         PlantSpecies::Carrot,
         PlantSpecies::Millet,
         PlantSpecies::Oat,
         PlantSpecies::Yacon}},

    {Stage::Temperate,
     new std::vector<PlantSpecies>{
         PlantSpecies::Cabbage,
         PlantSpecies::Strawberry,
         PlantSpecies::Tomato,
         PlantSpecies::Watermelon}},

    {Stage::Tropical,
     new std::vector<PlantSpecies>{
         PlantSpecies::Corn,
         PlantSpecies::Pepper,
         PlantSpecies::Potato,
         PlantSpecies::Tropical_Flower}}};

std::map<PlantSpecies, int> Resource::bloomingDay = {
    {PlantSpecies::Carrot, 5},
    {PlantSpecies::Millet, 4},
    {PlantSpecies::Oat, 7},
    {PlantSpecies::Yacon, 8},
    {PlantSpecies::Cabbage, 9},
    {PlantSpecies::Strawberry, 8},
    {PlantSpecies::Tomato, 4},
    {PlantSpecies::Watermelon, 6},
    {PlantSpecies::Corn, 9},
    {PlantSpecies::Pepper, 10},
    {PlantSpecies::Potato, 7},
    {PlantSpecies::Tropical_Flower, 6}};

    // std::map<PlantSpecies, int> Resource::bloomingDay = {
    // {PlantSpecies::Carrot, 1},
    // {PlantSpecies::Millet, 1},
    // {PlantSpecies::Oat, 1},
    // {PlantSpecies::Yacon, 1},
    // {PlantSpecies::Cabbage, 1},
    // {PlantSpecies::Strawberry, 1},
    // {PlantSpecies::Tomato, 1},
    // {PlantSpecies::Watermelon,1},
    // {PlantSpecies::Corn, 1},
    // {PlantSpecies::Pepper, 1},
    // {PlantSpecies::Potato, 1},
    // {PlantSpecies::Tropical_Flower, 1}};

std::map<PlantSpecies, int> Resource::price = {
    {PlantSpecies::Carrot, 1000},
    {PlantSpecies::Millet, 1000},
    {PlantSpecies::Oat, 1000},
    {PlantSpecies::Yacon, 1000},
    {PlantSpecies::Cabbage, 1000},
    {PlantSpecies::Strawberry, 1000},
    {PlantSpecies::Tomato, 1000},
    {PlantSpecies::Watermelon,1000},
    {PlantSpecies::Corn, 1000},
    {PlantSpecies::Pepper, 1000},
    {PlantSpecies::Potato, 1000},
    {PlantSpecies::Tropical_Flower, 1000}};

std::map<PlantSpecies, std::string> Resource::speciesName = {
    {PlantSpecies::Carrot, "Carrot"},
    {PlantSpecies::Millet, "Millet"},
    {PlantSpecies::Oat, "Oat"},
    {PlantSpecies::Yacon, "Yacon"},
    {PlantSpecies::Cabbage, "Cabbage"},
    {PlantSpecies::Strawberry, "Strawberry"},
    {PlantSpecies::Tomato, "Tomato"},
    {PlantSpecies::Watermelon,"Watermelon"},
    {PlantSpecies::Corn, "Corn"},
    {PlantSpecies::Pepper, "Pepper"},
    {PlantSpecies::Potato, "Potato"},
    {PlantSpecies::Tropical_Flower, "Tropical_Flower"}
};

std::map<PlantSpecies, std::string> Resource::speciesInfo = {
    {PlantSpecies::Carrot, "Cactus vegetables refer to edible parts\n derived from various types of cactus plants.\n These plants offer numerous health benefits \nand are known for being low in calories \nwhile providing ample hydration,\n making them a versatile and nutritious\n addition to various diets.\n"},
    {PlantSpecies::Millet, "Millet is a small-seeded\n grain that is gluten-free\n and a good source of \nessential nutrients such as \nfiber, vitamins, and minerals. \nIt is widely used in various cuisines \nand known for its versatility,\n contributing to a well-rounded\n and nutritious diet.\n"},
    {PlantSpecies::Oat, "Oats are a highly nutritious grain,\n rich in dietary fiber and protein,\n making them a healthy food choice. \nThey are versatile and commonly \nused in various diets, known to aid\n in weight management and blood sugar control.\n"},
    {PlantSpecies::Yacon, "Yacon is a South American root vegetable \nknown for its sweet taste and low-calorie content.\n It contains a type of soluble fiber called inulin,\n which may have prebiotic benefits \nand is often used as a natural sweetener\n or in dietary supplements.\n"},
    {PlantSpecies::Cabbage, "Cabbage is a leafy green\n or purple vegetable \nwith tightly packed leaves,\n belonging to the Brassica family.\n It is known for its versatility \nin culinary use, being used raw in salads,\n fermented as sauerkraut, or cooked in various dishes,\n and is recognized for its nutritional value, \noffering vitamins, minerals, and dietary fiber.\n"},
    {PlantSpecies::Strawberry, "Strawberry is a sweet and\n juicy red fruit that belongs to the\n rose family, characterized by its \n\nsmall seeds on the outer surface.\n It is not only a popular and\n delicious addition to various dishes\n but also a rich source of vitamin C, antioxidants,\n and dietary fiber, contributing to its reputation\n as a healthful and flavorful berry.\n"},
    {PlantSpecies::Tomato, "Tomato is a red or yellowish fruit\n with savory characteristics,\n commonly used as a vegetable in culinary contexts.\n Besides its versatile culinary applications, tomatoes are rich in vitamins,\n particularly vitamin C, and contain beneficial compounds like lycopene,\n known for their potential health benefits.\n"},
    {PlantSpecies::Watermelon,"Watermelon is a large, juicy fruit with sweet,\n red or pink flesh and black seeds, known for its high water content\n that makes it a refreshing summer treat.\n In addition to its hydrating properties, \nwatermelon is a good source of vitamins A and C,\n and it contains antioxidants like lycopene, \ncontributing to its appeal as a tasty and nutritious fruit.\n"},
    {PlantSpecies::Corn, "Corn, also known as maize, is a cereal grain \nthat is widely consumed around the world. \nIt is valued for its versatility,\n being used in various forms \nsuch as fresh, canned, or ground into flour,\n and serves as a staple food in many cultures,\n providing essential nutrients like carbohydrates and fiber.\n"},
    {PlantSpecies::Pepper, "Pepper refers to a diverse group of plants \nknown for producing spicy fruits used to flavor food.\n The most common types include black pepper, derived from dried unripe berries,\n and bell peppers, which are mild and come in various colors,\n both adding distinct tastes to culinary dishes.\n"},
    {PlantSpecies::Potato, "Potato is a starchy tuberous vegetable\n that is a staple in many diets worldwide,\n available in various varieties such as \nrusset, red, or sweet potatoes.\n It is a versatile ingredient, \ncommonly prepared by boiling, baking, or frying,\n and is a good source of \ncarbohydrates, vitamins, and minerals.\n"},
    {PlantSpecies::Tropical_Flower, "Tropical flowers encompass a wide variety\n of vibrant and exotic blooms\n that thrive in warm and humid climates.\n Known for their bold colors and unique shapes, \nthese flowers, such as orchids, hibiscus, and plumeria, \ncontribute to the lush and diverse floral landscapes \nfound in tropical regions around the world.\n"}
};

int Resource::getBloomingDay(PlantSpecies plantSpecies)
{
    return bloomingDay[plantSpecies];
}

std::vector<PlantSpecies> *Resource::getPlantsByStage(Stage stage)
{
    return plantByStage[stage];
}

std::string Resource::getName(PlantSpecies plantSpecies)
{
    return speciesName[plantSpecies];
}

std::string Resource::getStageByPlant(PlantSpecies s)
{
    std::vector<PlantSpecies> *v;

    v = plantByStage[Stage::Desert];
    for (std::vector<PlantSpecies>::iterator i = v->begin(); i != v->end(); i++)
    {
        if (s == *i)
        {
            return "Desert";
        }
    }

    v = plantByStage[Stage::Temperate];
    for (std::vector<PlantSpecies>::iterator i = v->begin(); i != v->end(); i++)
    {
        if (s == *i)
        {
            return "Temperate";
        }
    }

    v = plantByStage[Stage::Tropical];
    for (std::vector<PlantSpecies>::iterator i = v->begin(); i != v->end(); i++)
    {
        if (s == *i)
        {
            return "Tropical";
        }
    }

    return nullptr;
}

int Resource::getPrice(PlantSpecies s)
{
    return Resource::price[s];
}

sf::Texture * Resource::getTexture(PlantSpecies s, int level)
{
    std::string filePath = "../../assets/";
    std::string plantName = Resource::getName(s);
    std::string stageName = Resource::getStageByPlant(s);

    if (level > 0)
    {
        filePath = filePath + stageName + "/" + plantName + "/" + plantName + "_" + std::to_string(level);
    }
    else if (level == 0)
    {
        filePath = filePath + stageName + "/" + plantName + "/" + plantName + "_Dead";
    }
    else
    {
        std::cout << "ERROR: undefined argument value of 'level' in Resource::getTexture()" << std::endl;
    }
    filePath += ".png";
    sf::Texture * t = new sf::Texture();
    if (!t->loadFromFile(filePath))
    {
        std::cout << "ERROR While fetching images." << std::endl;
    }
    return t;
}

std::string Resource::getInfo(PlantSpecies s)
{
    return speciesInfo[s];
}

std::string Resource::getStageName(Stage s)
{
    switch (s)
    {
    case Stage::Desert:
        return "Desert";
        
    case Stage::Temperate:
        return "Temperate";

    case Stage::Tropical:
        return "Tropical";

    default:
        std::cout<<"ERROR while fetching stage name. Invalid argument.\n Resource::getStageName(Stage s)"<<std::endl;
        break;
    }
}
