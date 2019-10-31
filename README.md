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
                         
Zapojení:

           - Obvod by měl obsahovat IR LED (940nm) pro vysílání kódů, tlačítko (pro zapnutí) a LED pro mou orientaci (svítí                    -> připraveno k zapnutí, nesvítí -> cyklus je u konce)
           - Pro připojení jsem potřeboval 2 rezistory 220ohm (LED, IR LED), rezistor 10k ohm (tlačítko) a propojovací kabely              (Male - Male, Male - Female)
           - Pro otáčení produktem na podložce použiji Stepper motor 28BYJ-48 s driverem pro krokový motor
                      - Napájen bude 5V z arduina (breadboard)
                      - https://navody.arduino-shop.cz/navody-k-produktum/krokovy-motor-a-driver.html
                      
           - schéma:


Mikrokontroler:

           - Arduino UNO 
           - 

Krokový motor:

           - https://www.instructables.com/id/BYJ48-Stepper-Motor/
           - Krokový motor 28-BYJ48 s driverem ULN2003

Controller - https://www.instructables.com/id/Arduino-Controller-for-Automated-360-Product-Photo/ 
           - https://github.com/FluxGarage/Controller-for-Steppermotor-Turntable-and-IR-Camera-Shutter/blob/master/Basic_ControllerForTurntableAndIRCamerashutter.ino
           - 

Automated turntable - https://www.instructables.com/id/Automated-Turntable-With-Steppermotor/  
                    - https://www.banggood.com/cs/Full-Ball-Bearing-Swivel-Plate-Metal-Lazy-Susan-Turntable-4-inch-p-1043770.html?rmmds=detail-left-hotproducts__1&cur_warehouse=CN
                    
360 degree photo - https://codyhouse.co/gem/360-degrees-product-viewer#
                 - https://www.youtube.com/watch?v=-9MXhM_HmxE
                 - https://opencv.org/opencv-4-0/

Harmonogram: 

           - Září     - volba projektu
                      - Tento projekt jsem si zvolil, protože tím vytvořím něco užitečného pro tvorbu 360° fotek produktů na                         eshop, a zároveň se naučím ovládat zařízení pomocí IR, ovládání krokových motorů, něco nového v                               javascriptu (skládání z fotek 360° wiever)
                      - Nákup potřebných součástek
                      
           - Říjen    - Analýza projektu
                      - servo / krokový motor
                      - Knihovna
                      - IR LED
                      - Nastudování fungování IR pro potřebnou komunikaci mezi IR LED a fotoaparátem
                      - Ovládání motorku
                      - Programování 
                      - Dokončení - Po zmáčknutí tlačítka:
                                             - Kontroler vyšle IR kód (vzdálené zmáčknutí spouště) přes IR LED fotoaparátu
                                             - Fotoaparát pořídí fotku
                                             - Delay
                                             - Spuštění krokového motorku, který otočí produktem
                                             - Delay
                                             - Opakování od začátku   
                                             
           - Listopad - Konstrukce podložky pro produkt
                      - Tvorba 360° product viewer ze získaných fotek (Javascript)
                      - Tvorba dokumentace           
                      
           - Prosinec - Dokončení dokumentace
                      - Případné doladění projektu
