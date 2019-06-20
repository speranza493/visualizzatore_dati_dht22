
#include <DHT.h>;  
#include <Wire.h>
#include <LiquidCrystal_I2C.h> //scarico questa livreria da questo link:
//https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads/

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  
//identifco lo schermo nella variabile lcd in modo tale da poterci scriverci sopra
//setto le impostazioni dello schermo per poterci scrivere sopra
//per trovare HEX_ADRESS uso lo skech i2cScanner

//Constants
#define DHTPIN 7// definisco i pin in cui si andra ha leggere le informazioni
#define DHTPIN2 2


#define DHTTYPE DHT22   // definisco il tipo di modello del sensore

DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino
DHT dht2(DHTPIN2, DHTTYPE);

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value
float hum2;  //Stores humidity value
float temp2; //Stores temperature value

void setup()
{
  Serial.begin(9600);
  
  dht.begin();//controllo e inizio ha predere i dati dal sensore
  dht2.begin();
  
  lcd.begin(20,4); //identifico quante colonne e righe possiede lo schermo 
  lcd.backlight();
  
  lcd.setCursor(0,2);//identifico dove mettere il cursore per iniziare ha scrivere
  //in questo caso prima colonna e 3 riga
  lcd.print("Serra1: ");//stampo il messaggio da scrivere
  lcd.setCursor(0,3);//resetta il cursore nella prima colonna e 4 riga per poter scrivere in questo punto
  lcd.print("Serra2: ");
  lcd.setCursor(8,1);
  lcd.print("Hum:");
  lcd.setCursor(15,1);
  lcd.print("Temp:");
}

void loop()
{
    delay(2000);
    
    //Read data and store it to variables hum,hum2 and temp,temp2
    hum = dht.readHumidity(); 
    temp= dht.readTemperature();
    hum2 = dht2.readHumidity();
    temp2= dht2.readTemperature();
    
    //Print temp and humidity values to serial monitor
    Serial.print("1.Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    Serial.print("2.Humidity: ");
    Serial.print(hum2);
    Serial.print(" %, Temp: ");
    Serial.print(temp2);
    Serial.println(" Celsius");
    
    //inizio ha stampare i valori dei sensori sullo schemo nelle giuste posizioni
    lcd.setCursor(8,2); 
    lcd.print(hum);

    lcd.setCursor(8,3);
    lcd.print(hum2);
    
    lcd.print("  ");
    lcd.print(temp2);
    
    lcd.setCursor(15,2);
    lcd.print(temp);

}
