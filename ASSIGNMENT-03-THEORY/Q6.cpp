#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char* name;           
    float waterRequirement; 
    float nutrientNeeds;   
    int growthStages;      
    float yieldPrediction;
} Crop;
typedef struct {
    char* location; 
    float size;     
    char* soilType; 
    Crop* crop;     
    float moistureLevel; 
} Field;


typedef struct {
    float temperature; 
    float humidity;    
    float precipitation; 
    char* forecastDate; 
} WeatherForecast;

typedef struct {
    char* hubName;         
    Field** fields;        
    int fieldCount;        
    WeatherForecast* weatherData; 
} RegionalHub;

Crop* createCrop(const char* name, float waterRequirement, float nutrientNeeds, int growthStages, float yieldPrediction) {
    Crop* newCrop = (Crop*)malloc(sizeof(Crop));
    newCrop->name = strdup(name);
    newCrop->waterRequirement = waterRequirement;
    newCrop->nutrientNeeds = nutrientNeeds;
    newCrop->growthStages = growthStages;
    newCrop->yieldPrediction = yieldPrediction; 
    return newCrop;
}

// Function to create a new field
Field* createField(const char* location, float size, const char* soilType, Crop* crop, float moistureLevel) {
    Field* newField = (Field*)malloc(sizeof(Field));
    newField->location = strdup(location);
    newField->size = size;
    newField->soilType = strdup(soilType);
    newField->crop = crop;
    newField->moistureLevel = moistureLevel; 
    return newField;
}

WeatherForecast* createWeatherForecast(float temperature, float humidity, float precipitation, const char* forecastDate) {
    WeatherForecast* weather = (WeatherForecast*)malloc(sizeof(WeatherForecast));
    weather->temperature = temperature;
    weather->humidity = humidity;
    weather->precipitation = precipitation;
    weather->forecastDate = strdup(forecastDate);
    return weather;
}


RegionalHub* createRegionalHub(const char* hubName) {
    RegionalHub* hub = (RegionalHub*)malloc(sizeof(RegionalHub));
    hub->hubName = strdup(hubName);
    hub->fields = NULL; 
    hub->fieldCount = 0;
    hub->weatherData = NULL;
    return hub;
}
void addFieldToHub(RegionalHub* hub, Field* field) {
    hub->fields = (Field**)realloc(hub->fields, (hub->fieldCount + 1) * sizeof(Field*));
    hub->fields[hub->fieldCount] = field;
    hub->fieldCount++;
}
void freeCrop(Crop* crop) {
    free(crop->name);
    free(crop);
}

void freeField(Field* field) {
    free(field->location);
    free(field->soilType);
    freeCrop(field->crop);
    free(field);
}

void freeWeatherForecast(WeatherForecast* weather) {
    free(weather->forecastDate);
    free(weather);
}

void freeRegionalHub(RegionalHub* hub) {
    for (int i = 0; i < hub->fieldCount; i++) {
        freeField(hub->fields[i]);
    }
    free(hub->fields);
    free(hub-> hubName);
    free(hub);
}

int main() {
	
    Crop* corn = createCrop("Corn", 600, 200, 5, 1000); 
    Crop* wheat = createCrop("Wheat", 500, 150, 4, 800); 
    Field* field1 = createField("Field A", 10.0, "Loamy", corn,  30.0); 
    Field* field2 = createField("Field B", 15.0, "Clay", wheat, 25.0); 
    WeatherForecast* weather = createWeatherForecast(25.0, 60.0, 5.0, "2023-10-01");
    RegionalHub* hub = createRegionalHub("North Region");
    addFieldToHub(hub, field1);
    addFieldToHub(hub, field2);
    hub->weatherData =  weather;
    printf("Regional Hub: %s\n", hub->hubName);
    for (int i = 0; i < hub->fieldCount; i++) {
        printf("Field Location: %s, Size: %.2f acres, Soil Type: %s, Crop: %s, Moisture Level: %.1f%%\n",
   	            hub->fields[i]->location, hub->fields[i]->size,
    	           hub->fields[i]->soilType, hub->fields[i]->crop->name, 
               hub->fields[i]->moistureLevel);
    }
    printf("Weather Forecast: %.1fC, %.1f%% humidity, %.1fmm precipitation on %s\n",
            hub->weatherData->temperature, hub->weatherData->humidity,
           hub->weatherData->precipitation, hub->weatherData->forecastDate);
    freeRegionalHub(hub);
     freeWeatherForecast(weather);
    freeCrop(corn);
    freeCrop(wheat);

    return 0;
}