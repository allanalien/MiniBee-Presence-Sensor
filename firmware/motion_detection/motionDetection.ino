#include <Arduino.h>
#include <bgt60-ino.hpp>
#include <bgt60-platf-ino.hpp>

#ifndef TD
#define TD 15
#endif

#ifndef PD
#define PD 16
#endif

Bgt60Ino radarShield(TD, PD);

unsigned long lastMotionTime = 0;
const unsigned long presenceTimeout = 15000; // 15 segundos
bool presence = false;

void setup() {
    Serial.begin(9600);
    Error_t init_status = radarShield.init();
    if (OK != init_status) {
        Serial.println("Init failed.");
    } else {
        Serial.println("Init successful.");
    }
}

void loop() {
    Bgt60::Motion_t motion = Bgt60::NO_MOTION;
    Error_t err = radarShield.getMotion(motion);

    if (err == OK) {
        if (motion == Bgt60::MOTION) {
            lastMotionTime = millis();
            if (!presence) {
                presence = true;
                Serial.println("1"); // Enviar lógica 1 (presencia activa)
            }
        }
    } else {
        Serial.println("Error occurred!");
    }

    // Verificar si ya pasó el tiempo sin movimiento
    if (presence && (millis() - lastMotionTime > presenceTimeout)) {
        presence = false;
        Serial.println("0"); // Enviar lógica 0 (sin presencia)
    }

    delay(200); // Reduce frecuencia de lectura
}
