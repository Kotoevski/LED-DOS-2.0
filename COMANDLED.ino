#define R 11 // pin for RED
#define G 10 // pin for GREEN
#define B 9 // pin for BLUE
#include <string.h> // NEED FOR THE COMMANDS


void anima(){ // BLINK LED 
  digitalWrite(R, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);
  delay(500);
  digitalWrite(G,HIGH);
  digitalWrite(R, LOW);
  digitalWrite(B, LOW);
  delay(500);
  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  digitalWrite(B, HIGH);
  delay(500);
  digitalWrite(R, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);
  delay(500);
  digitalWrite(G,HIGH);
  digitalWrite(R, LOW);
  digitalWrite(B, LOW);
  delay(500);
  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  digitalWrite(B, HIGH);
  delay(500);
}

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT); // PIN MODE OUTPUT
  pinMode(B, OUTPUT);
  Serial.begin(9600);
  Serial.println("LED-DOS 2.0, Русская версия для микроконтроллеров ATMEGA 328. Авторские права Cat Game Studio ");
  Serial.println(" 2024 - 2028 год");
  digitalWrite(R, HIGH); // TEST COLOR FOR WORKING OF THE MODULE
}

void loop() {
  String sim = Serial.readString(); // READ COMANDS ON THE COM PORT
  
  sim.trim();  // Удаляем пробелы в начале и конце строки

  if (sim.equalsIgnoreCase("/color red")) { // RED
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(B, LOW);
  } else if (sim.equalsIgnoreCase("/color green")) { // GREEN
    digitalWrite(G, HIGH);
    digitalWrite(R, LOW);
    digitalWrite(B, LOW);
  } else if (sim.equalsIgnoreCase("/color blue")) { // BLUE
    digitalWrite(B, HIGH);
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
  } else if(sim.equalsIgnoreCase("/color rainbow")){ // RAINBOW OR WHITE
    digitalWrite(B, HIGH);
    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
  }
     else if(sim.equalsIgnoreCase("/color violet")){ // VIOLET
    digitalWrite(B, HIGH);
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
  }
     else if(sim.equalsIgnoreCase("/color yellow")){ // YELLOW
    digitalWrite(B, LOW);
    digitalWrite(R, HIGH);
    digitalWrite(G, HIGH);
  }
     else if(sim.equalsIgnoreCase("/color indigo")){ // INDIGO OR GOLYBOI in Russian
    digitalWrite(B, HIGH);
    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
  }
     else if(sim.equalsIgnoreCase("/help")){ // COMANDS ON THE PROGRAMM
     Serial.println("Список команд: /color red ");
     Serial.println(" /color blue ");
     Serial.println(" /color green ");
     Serial.println(" /color yellow ");
     Serial.println(" /color indigo ");
     Serial.println(" /color rainbow ");
     Serial.println("/color violet");
     Serial.println(" /clear ");
     Serial.println("/animation");
     Serial.println(" /nocolor ");
     Serial.println("/reset");
  }

  
     else if(sim.equalsIgnoreCase("/clear")){ // CLEAR COM PORT
     Serial.println("");
     Serial.println("");
     Serial.println("");
     Serial.println("");
     Serial.println("");
     Serial.println("");
     Serial.println("");
     Serial.println("");
     Serial.println("");
     Serial.println("");
     Serial.println("");
     Serial.println("");
     Serial.println("");
     Serial.println("");
     Serial.println("");
     Serial.println("");
     Serial.println("");
     Serial.println("");
     Serial.println("");

  }
    else if(sim.equalsIgnoreCase("/nocolor")){ // SET NO COLORE TO THE LED
    digitalWrite(B, LOW);
    digitalWrite(R, LOW);
    digitalWrite(G, LOW);
  }
    else if(sim.equalsIgnoreCase("/reset")){ // RESET
    noInterrupts();
     asm volatile ("JMP 0x00");
  }
    else if(sim.equalsIgnoreCase("/animation")){ // ANIMATION!
    anima();

  }
    else if(sim.equalsIgnoreCase("/help more")){ // MORE HELPING
    Serial.println("LED-DOS: Простейшая Операционная Система (ОП), которая позволяет управлять РГБ светодиодом (RGB LED)");
    Serial.println("Для начала работы с ОП нужно подключить Микрокомпьютер Ардуино к другому компьютеру с Windows и через монитор порта в специальном приложении вводить команды");
    Serial.println("Для просмотра команд пишите /help");
    Serial.println("Спасибо за испльзование LED-DOS 2.0!");
  
}
}

