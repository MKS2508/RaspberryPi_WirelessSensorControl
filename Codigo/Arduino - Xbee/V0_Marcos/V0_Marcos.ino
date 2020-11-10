#include <DHT.h>  //Librería sensor
#include <Adafruit_Sensor.h> //Librería sensor
#define DHTTYPE DHT22 // AM2302
const int DHTPin = 5; // Pin digital al que esta conectado el sensor
DHT dht(DHTPin, DHTTYPE); // Config sensorç
#include <SoftwareSerial.h> 
SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
    mySerial.begin(9600);
    mySerial.println("DHT22 tomando medidas...");

    dht.begin();      // Inicialización sensor

}

void loop() {
 
  

    //LECTURAS

    float hum = dht.readHumidity(); // Leer Humedad
    float tmp = dht.readTemperature(); // Leer Temp
    

    //MOSTRAR DATOS SERIAL
    
    mySerial.print("Humedad: ");
    mySerial.print(hum);
    mySerial.print("%");
    mySerial.println( "");
    mySerial.print("Temperatura: ");
    mySerial.print(tmp);
    mySerial.print("*C");
    mySerial.println( "");

  delay(6000); // Tiempo entre medicion
    }

