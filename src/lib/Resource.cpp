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
    {PlantSpecies::Carrot, 1},
    {PlantSpecies::Millet, 1},
    {PlantSpecies::Oat, 1},
    {PlantSpecies::Yacon, 1},
    {PlantSpecies::Cabbage, 1},
    {PlantSpecies::Strawberry, 1},
    {PlantSpecies::Tomato, 1},
    {PlantSpecies::Watermelon,1},
    {PlantSpecies::Corn, 1},
    {PlantSpecies::Pepper, 1},
    {PlantSpecies::Potato, 1},
    {PlantSpecies::Tropical_Flower, 1}};

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
    {PlantSpecies::Carrot, "Cactus vegetables refer to edible parts derived from various types of cactus plants. These plants offer numerous health benefits and are known for being low in calories while providing ample hydration, making them a versatile and nutritious addition to various diets."},
    {PlantSpecies::Millet, "Millet is a small-seeded grain that is gluten-free and a good source of essential nutrients such as fiber, vitamins, and minerals. It is widely used in various cuisines and known for its versatility, contributing to a well-rounded and nutritious diet."},
    {PlantSpecies::Oat, "Oats are a highly nutritious grain, rich in dietary fiber and protein, making them a healthy food choice. They are versatile and commonly used in various diets, known to aid in weight management and blood sugar control."},
    {PlantSpecies::Yacon, "Yacon is a South American root vegetable known for its sweet taste and low-calorie content. It contains a type of soluble fiber called inulin, which may have prebiotic benefits and is often used as a natural sweetener or in dietary supplements."},
    {PlantSpecies::Cabbage, "Cabbage is a leafy green or purple vegetable with tightly packed leaves, belonging to the Brassica family. It is known for its versatility in culinary use, being used raw in salads, fermented as sauerkraut, or cooked in various dishes, and is recognized for its nutritional value, offering vitamins, minerals, and dietary fiber."},
    {PlantSpecies::Strawberry, "Strawberry is a sweet and juicy red fruit that belongs to the rose family, characterized by its small seeds on the outer surface. It is not only a popular and delicious addition to various dishes but also a rich source of vitamin C, antioxidants, and dietary fiber, contributing to its reputation as a healthful and flavorful berry."},
    {PlantSpecies::Tomato, "Tomato is a red or yellowish fruit with savory characteristics, commonly used as a vegetable in culinary contexts. Besides its versatile culinary applications, tomatoes are rich in vitamins, particularly vitamin C, and contain beneficial compounds like lycopene, known for their potential health benefits."},
    {PlantSpecies::Watermelon,"Watermelon is a large, juicy fruit with sweet, red or pink flesh and black seeds, known for its high water content that makes it a refreshing summer treat. In addition to its hydrating properties, watermelon is a good source of vitamins A and C, and it contains antioxidants like lycopene, contributing to its appeal as a tasty and nutritious fruit."},
    {PlantSpecies::Corn, "Corn, also known as maize, is a cereal grain that is widely consumed around the world. It is valued for its versatility, being used in various forms such as fresh, canned, or ground into flour, and serves as a staple food in many cultures, providing essential nutrients like carbohydrates and fiber."},
    {PlantSpecies::Pepper, "Pepper refers to a diverse group of plants known for producing spicy fruits used to flavor food. The most common types include black pepper, derived from dried unripe berries, and bell peppers, which are mild and come in various colors, both adding distinct tastes to culinary dishes."},
    {PlantSpecies::Potato, "Potato is a starchy tuberous vegetable that is a staple in many diets worldwide, available in various varieties such as russet, red, or sweet potatoes. It is a versatile ingredient, commonly prepared by boiling, baking, or frying, and is a good source of carbohydrates, vitamins, and minerals."},
    {PlantSpecies::Tropical_Flower, "Tropical flowers encompass a wide variety of vibrant and exotic blooms that thrive in warm and humid climates. Known for their bold colors and unique shapes, these flowers, such as orchids, hibiscus, and plumeria, contribute to the lush and diverse floral landscapes found in tropical regions around the world."}
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
