// Подключаем библиотеку для работы с жидкокристаллическим
// экраном (англ. Liquid Crystal Display или просто LCD)
#include <LiquidCrystal.h>
// Объявляем объект, для управления дисплеем. Для его создания
// необходимо указать номера пинов, к которым он подключен в
// порядке: RS E DB5 DB6 DB7 DB8
#define DISP_LENGTH 16
int index = 0;

String FIO = "Бабарыкин Артём Дмитриевич ";
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
void setup() {
 // начинаем работу с экраном. Сообщаем объекту количество
 // строк и столбцов. Опять же, вызывать pinMode не требуется:
 // функция begin сделает всё за нас
 lcd.begin(16, 2);
 lcd.print("Student's FIO:");
}
void loop() {
  // устанавливаем курсор, колонку 0, строку 1. На деле — это
  // левый квадрат 2-й строки, т.к. нумерация начинается с нуля
  lcd.setCursor(0, 1);
  lcd.scrollDisplayLeft();
  for (int i; i < DISP_LENGTH; i++) {
    lcd.print(FIO[(index + i) % FIO.length()]);
  }
  
  index++;
  delay(200);
}
