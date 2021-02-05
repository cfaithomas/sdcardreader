#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
//#include <SdFat.h>
#include <Adafruit_ImageReader.h>
#include <ESP8266WiFi.h>

// Declare pins for the display:
#define TFT_CS     10 //CS du TFT
#define TFT_RST    9
#define TFT_DC     8
#define SD_CS   4   //CS de la SD
// les autres pins sont prédéfinies (SCK = 13 and SDA = 11)

// Creation de l'écran
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
SdFat SD;         // Gestion de la SD CARD
Adafruit_ImageReader reader(SD); //lecteur de fichier




void setup()
{


    initSDCard();

    tft.initR(INITR_BLACKTAB);  // intialisation du TFT

    tft.fillScreen(ST7735_BLACK);  // remplissage en noir du tft

    ImageReturnCode stat; //recupere l'état de chargement de l'image
    stat = reader.drawBMP("/marta.bmp", tft, 0, 0); //charge l'image en 0,0 et affecte le code
    reader.printStatus(stat); //affiche le code de réussite ou d'erreur dans le moniteur série


}  // End of setup



void initSDCard()
{
    if(!SD.begin(SD_CS, SD_SCK_MHZ(25))) {
        Serial.println("Echec initialisation de la SD Card");
        for(;;); //Boucle infinie
    }
}



void loop()
{




}