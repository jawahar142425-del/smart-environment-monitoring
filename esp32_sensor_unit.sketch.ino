#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22

#define MQ135_PIN 34
#define MQ2_PIN 35

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  dht.begin();
  analogReadResolution(12);

  pinMode(MQ135_PIN, INPUT);
  pinMode(MQ2_PIN, INPUT);

  Serial.println();
  Serial.println("Smart Environmental Monitoring System");
  Serial.println("ESP32 Started Successfully");

  delay(2000);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int mq135Value = analogRead(MQ135_PIN);
  int mq2Value = analogRead(MQ2_PIN);

  Serial.println("\n------ Environmental Data ------");

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT22: Reading Failed");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature, 2);
    Serial.println(" C");

    Serial.print("Humidity: ");
    Serial.print(humidity, 2);
    Serial.println(" %");
  }

  Serial.print("MQ135 Raw: ");
  Serial.println(mq135Value);

  Serial.print("MQ2 Raw: ");
  Serial.println(mq2Value);

  if (!isnan(temperature) && temperature > 35.0) {
    Serial.println("ALERT: High Temperature!");
  }

  if (!isnan(humidity) && humidity > 70.0) {
    Serial.println("ALERT: High Humidity!");
  }

  if (mq135Value > 2500) {
    Serial.println("ALERT: High MQ135 Analog Reading!");
  }

  if (mq2Value > 2500) {
    Serial.println("ALERT: High MQ2 Analog Reading!");
  }

  Serial.println("--------------------------------");

  delay(2000);
}
