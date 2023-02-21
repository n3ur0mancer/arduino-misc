// Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// create an RF24 object
RF24 radio(7, 8); // CE, CSN

// address through which two modules communicate.
const byte address[6] = "node1";

void setup()
{
  Serial.begin(9600);

  radio.begin();

  // Power Level (MIN, LOW, HIGH, MAX)
  // More Power = More Distance
  radio.setPALevel(RF24_PA_LOW);

  // Set Data Transmission Rate per Second (250KBPS, 1MPS,2MPS)
  // More Data = Less Distance
  radio.setDataRate(RF24_250KBPS);

  // Channels from 0 to 124
  radio.setChannel(124);

  // set the address
  radio.openReadingPipe(0, address);

  // Set module as receiver
  radio.startListening();
}

void loop()
{
  // Read the data if available in buffer
  if (radio.available())
  {
    char text[32] = {0};
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}
