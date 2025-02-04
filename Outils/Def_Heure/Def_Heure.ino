
// Pour horloge RTC
#include <DS3231.h>

DS3231 Clock;
bool Century = false;
bool h12;
bool PM;
byte ADay, AHour, AMinute, ASecond, ABits;
bool ADy, A12h, Apm;

byte year, month, date, DoW, hour, minute, second;
int state = 1; // 0 pour set time, 1 pour get time

int donnee; // données reçues sur la liaison série

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  //Initilisation wire pour rtc
  Wire.begin();

}

void loop() {
  Serial.println("presser entrer pour lancer la synchro");
  if (Serial.available() > 0) {
    // on lit la données reçue (dans la variable "donnee")
    donnee = Serial.read();
    // set time
    Clock.setSecond(00);//Set the second
    Clock.setMinute(44);//Set the minute
    Clock.setHour(15);  //Set the hour
    Clock.setDoW(07);    //Set the day of the week
    Clock.setDate(23);  //Set the date of the month
    Clock.setMonth(1);  //Set the month of the year
    Clock.setYear(22);  //Set the year (Last two digits of the year)
    Clock.setClockMode(false); // pour avoir le format 24h
    Serial.println("synchro ok");
  }
  else {
    int second, minute, hour, date, month, year;

    // lecture de l'horloge rtc
    second = Clock.getSecond();
    minute = Clock.getMinute();
    hour = Clock.getHour(h12, PM);
    date = Clock.getDate();
    month = Clock.getMonth(Century);
    year = Clock.getYear();
    Serial.println("");
    Serial.print(year); Serial.print("/"); Serial.print(month); Serial.print("/"); Serial.print(date); Serial.print(" ; ");
    Serial.print(hour); Serial.print(" : "); Serial.print(minute); Serial.print(" : "); Serial.println(second);
    delay(1000);
  }

}
