#include "LCD.h"
#include "Config.h"

extern Status currentStatus;
extern double waterDistance;
extern int valveOpening;

LCD::LCD ( unsigned long period ) : Task ( period ) {
    this -> lcd = new LiquidCrystal_I2C ( 0x27 , 20 , 4) ;

}

void LCD::toExecute() {
    switch (currentStatus)
    {
    case NORMAL:
        this->lcd->off();
        this->isOn = false;
        break;
    
    case PRE_ALARM:
        if (!this->isOn) {
            this->lcd->on();
            this->isOn = true;
        } 
        this->lcd->on();
        this->lcd->clear();
        this->lcd->setCursor(0,0);
        this->lcd->print("Status: PRE-ALARM");
        this->lcd->print("Water Level: ");
        this->lcd->print(waterDistance);
        this->lcd->setCursor(0,1);
        break;
    
    case ALARM:
        if (!this->isOn) {
            this->lcd->on();
            this->isOn = true;
        } 
        this->lcd->clear();
        this->lcd->setCursor(0,0);
        this->lcd->print("Status: ALARM");
        this->lcd->setCursor(0,1);
        this->lcd->print("Water Level: ");
        this->lcd->print(waterDistance);
        this->lcd->setCursor(0,2);
        this->lcd->print("Valve Opening: ");
        this->lcd->print(valveOpening);
        break;
    }

}

