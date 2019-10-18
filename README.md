# Arduino-Controller with automated turntable for 360° product photography

Knihovny:
           - První pokus - multiCameraIrControl (Seitz)
                         - Pomocí této knihovny se mi nepodařilo komunikovat s kamerou přes IR LED
                         - https://github.com/dharmapurikar/Arduino/tree/master/libraries/multiCameraIrControl
                      
           - Druhý pokus - IRremote arduino knihovna
                         - Tento pokus již byl úspěšný a podařilo se mi pomocí IR LED kontrolovat funkce fotoaparátu (spoušť, video,                                  pohybování se v menu apod.)
                         - Knihovna nabízí možnosti pro komunikaci s různými zařízeními
                         - https://www.arduinolibraries.info/libraries/i-rremote
                         - https://diydrones.com/forum/topics/sony-a7-infrared-codes // IR kódy pro fotoaparát, který používám při                                    komunikaci
                         
Obvodu:
           - Obvod by měl obsahovat IR LED (940nm) pro vysílání kódů, tlačítko (pro zapnutí) a LED pro mou orientaci (svítí ->                        připraveno k zapnutí, nesvítí -> cyklus je u konce)
           - Pro připojení jsem potřeboval 2 rezistory 220ohm (LED, IR LED), rezistor 10k ohm (tlačítko) a propojovací kabely (Male-                  Male, Male-Female)
           - Pro otáčení produktem na podložce použiji Stepper motor 28BYJ-48 s driverem pro krokový motor
                      - Napájen bude 5v z arduina (breadboard)
                      - https://navody.arduino-shop.cz/navody-k-produktum/krokovy-motor-a-driver.html
           - schéma:


Mikrokontroler:
           - Arduino UNO 
           - 


Controller - https://www.instructables.com/id/Arduino-Controller-for-Automated-360-Product-Photo/ 
           - https://github.com/FluxGarage/Controller-for-Steppermotor-Turntable-and-IR-Camera-Shutter/blob/master/Basic_ControllerForTurntableAndIRCamerashutter.ino
           - 

Automated turntable - https://www.instructables.com/id/Automated-Turntable-With-Steppermotor/  
360 degree photo - https://codyhouse.co/gem/360-degrees-product-viewer#
                 - https://www.youtube.com/watch?v=-9MXhM_HmxE
                 - https://opencv.org/opencv-4-0/

Harmonogram: 
           - Zapojení obvodu pro test fungování IR LED ve spojení s fotoaparátem
           - Zapojení krokového motoru s driverem
          





