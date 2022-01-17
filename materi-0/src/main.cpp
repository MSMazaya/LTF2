#include <Arduino.h>
#define BOBOT_UTS 0.4
#define BOBOT_UAS 0.6

const float bA = 85.0;
const float bB = 75.0;
const float bC = 60.0;
const float bD = 40.0;

long nim;
String nama;
float uts;
float uas;
float nilai_angka;
char nilai_huruf;

void tanya(char s[])
{
  while (Serial.available())
    Serial.read();

  Serial.print(s);
  Serial.print(": ");
  while (!Serial.available())
  {
  }
}
void inputData()
{
  Serial.println("Masukkan data");
  tanya("NIM");
  nim = Serial.parseInt();
  Serial.println(nim);

  tanya("Nama");
  nama = Serial.readStringUntil('\n');
  Serial.println(nama);
  tanya("UTS");
  uts = Serial.parseFloat();
  Serial.println(uts);

  tanya("UAS");
  uas = Serial.parseFloat();
  Serial.println(uas);
}

float nilaiAngka(float uts, float uas)
{
  return (BOBOT_UTS * uts) + (BOBOT_UAS * uas);
}

char nilaiHuruf(float angka)
{
  if (angka > bA)
  {
    return 'A';
  }
  else if (angka > bB)
  {
    return 'B';
  }
  else if (angka > bC)
  {
    return 'C';
  }
  else if (angka > bD)
  {
    return 'D';
  }
  return 'E';
}

void cetakData()
{
  char buffer[60];

  sprintf(buffer, "%8ul %-15s %6.2f %c",
          nim, nama.c_str(), nilai_angka, nilai_huruf);
  Serial.println(buffer);
  Serial.println("----------");
}

void setup()
{
  Serial.begin(9600);
  Serial.println();
  Serial.println("Pengolahan Nilai");
}

void loop()
{
  inputData();
  nilai_angka = nilaiAngka(uts, uas);
  nilai_huruf = nilaiHuruf(nilai_angka);
  cetakData();
}
