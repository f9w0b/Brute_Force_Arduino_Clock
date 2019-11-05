//was in the middle of hard-coding variables to create counters but I've realzed 
// i should be using Timers and counters to counts minutes, seconds and hours
//anyways the for -loop does work, changes made on the 5th,Nov-2019 
#include <Arduino.h>
#include <string.h>
#include <LiquidCrystal.h>
#define MAXLEN 999
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);
 //
typedef struct {
   char name1[MAXLEN];   //days.name1
   char name2[MAXLEN];   //days.name2
   char name3[MAXLEN];   //days.name3
   char name4[MAXLEN];   //days.name4
   char name5[MAXLEN];   //days.name5
   char name6[MAXLEN];   //days.name6
   char name7[MAXLEN];   //days.name7
} Week_struct;

Week_struct days  = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
 

void setup()
{
  lcd.begin(16, 2); 
  lcd.setCursor(0,0); 
  lcd.print("00:00.00 (  )");
  lcd.setCursor(0,1); 
  lcd.print("DAY:    ");
}



void loop() 
{
    for (int hour_counter = 1 ; (hour_counter < 13) ; ++hour_counter){        
         if (hour_counter == 1){ 
             lcd.setCursor(0,0);
             lcd.print("01");
        } else if (hour_counter < 10 && hour_counter > 0) {
                   lcd.setCursor(1,0);
                   lcd.print(hour_counter);
        } else if (hour_counter >= 10 && hour_counter < 13) { 
                   lcd.setCursor(0,0);
                   lcd.print(hour_counter);
        } //after 12 hours, it resets to 01 hours
        for (int min_counter = 0 ; (min_counter < 60) ; ++min_counter) {
             if (min_counter == 0) { 
                 lcd.setCursor(3,0);
                 lcd.print("00");
            } else if (min_counter < 10 && min_counter > 0) {
                       lcd.setCursor(4,0);
                       lcd.print(min_counter);
            } else if (min_counter >= 10 && min_counter < 60) { 
                       lcd.setCursor(3,0);
                       lcd.print(min_counter);
            } //after 59 mins, it resets to 00 ---------------------------------------------------------------- 
            for (int sec_counter = 0 ; (sec_counter < 60 ); ++sec_counter) {
                 if (sec_counter == 0) {
                     lcd.setCursor(6,0);
                     lcd.print("00");
                } else if(sec_counter < 10 && sec_counter > 0) { 
                          delay(1000);
                          lcd.setCursor(7,0);
                          lcd.print(sec_counter);
                } else if (sec_counter >= 10 && sec_counter < 60) { 
                           delay(1000);
                           lcd.setCursor(6,0);
                           lcd.print(sec_counter);
                  } 
            }//-------------------------------------------------------------
            delay(1000);
        }
    }
}
