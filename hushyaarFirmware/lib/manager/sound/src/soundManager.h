#ifndef SOUND_MANAGRE_H
#define SOUND_MANAGRE_H

    #include "../../lib/provider/sound/buzzer/src/buzzerProvider.h"

    #define SIREN_PIN 13

    class SoundManager{
        private:
            BuzzerProvider buzzerProvider = BuzzerProvider(SIREN_PIN);
        public:
            SoundManager();
            void Beep();
            void Armed();
            void SirenOn();
            void BootSucceed();
            void Off();

    };
#endif 