#include <DHT.h>
#include <LiquidCrystal.h>

// Define DHT sensor type and pin
#define DHTTYPE DHT11 // Use DHT22 for DHT22 sensor
#define DHTPIN 2       // DHT sensor pin

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Initialize LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // Start serial communication
  Serial.begin(9600);
  Serial.println("DHT Sensor with LCD Display");

  // Initialize DHT sensor
  dht.begin();

  // Initialize LCD
  lcd.begin(16, 2); // 16x2 LCD
  lcd.print("Initializing...");
}

void loop() {
  // Wait a few seconds between measurements
  delay(2000);

  // Read humidity
  float humidity = dht.readHumidity();

  // Read temperature in Celsius
  float temperature = dht.readTemperature();

  // Check if readings failed
  if (isnan(humidity) || isnan(temperature)) {
    lcd.setCursor(0, 0);
    lcd.print("Read Error!");
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Clear the LCD and display data
  lcd.clear();

  // Display temperature
  lcd.setCursor(0, 0); // Set cursor to first row
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print((char)223); // Degree symbol
  lcd.print("C");

  // Display humidity
  lcd.setCursor(0, 1); // Set cursor to second row
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");

  // Print data to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C\t");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
}
