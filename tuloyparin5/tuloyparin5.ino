#include "pitchesx.h"
#include "Piezzo.h"

const int PiezzoPin = 8;      // PiezzoPin
const int BPM = 110;          // Beats per Minute
const int Q = 60000 / BPM;    // 1/4 Note
const int H = Q * 2;          // 1/2 Note
const int TF = Q * 3;         // 3/4 Note
const int W = Q * 4;          // 1 Note
const int E = Q / 2;          // 1/8 Note
const int TE = Q / 3;         // 1/12 Note
const int S = Q / 4;          // 1/16 Note


Piezzo piezzo (PiezzoPin); // Create a Piezzo object then assign to pin 8
//Format:  int MusicPiece [] = {NOTE,BEAT,NOTE,BEAT,NOTE,BEAT,............};
int Stanza [] = {F4, E, F4, E, C5, E, D5, Q , F4, E, F4, E + TE , F4, E + TE, F4, E  , DS5, E, D5, E, D5, Q, D5, E, G5, E, F5, E, F5, E, F5, E, D5, E, C5, Q + E, C5, Q + E, R, H};
int Stanza2 [] = {AS4, TE + E, AS4, TE + E, AS4, TE + E, R , Q, AS4, E, D5, E, D5, E, D5, E, D5, E, C5, E, R, Q, F4, Q, F5, Q, D5, Q, C5, Q, AS4, E, G4, E, R, H};
int Stanza3 [] = {F4, TE + S, AS4, TE + S, AS4, TE + S, AS4, TE + S, R, E, F4, E, D5, E, DS5, E, D5, E, C5, E, R, Q, F4, E, G4, E, R, E, D5, E, R, E, D5, E, D5, E, C5, E, C5, Q + E, R, H + E};
int Chorus [] = {F4, E, G5, E, F5, E, F5, E, D5, E, G5, E, F5, E, F5, E + TE + S, F5, E + TE + S, F5, E + TE + S, R, Q};
int Chorus2 [] = {F4, E, G5, E, F5, E, F5, E, D5, E, DS5, E, D5, E, D5, E, C5, Q, D5,  Q, C5, E, AS4, E, R, Q};
int Chorus3 [] = {D5, E, D5, E, D5, E, D5, E, DS5, E, D5, Q, C5, Q, AS4, E + S, R, Q};  

//Get the arrays' lengths
int Chorusl = sizeof(Chorus) / sizeof(int);  
int Chorus2l = sizeof(Chorus2) / sizeof(int);
int Chorus3l = sizeof(Chorus3) / sizeof(int);
int Stanzal = sizeof(Stanza) / sizeof(int);
int Stanza2l = sizeof(Stanza2) / sizeof(int);
int Stanza3l = sizeof(Stanza3) / sizeof(int);

int debug = 1; //Debug Mode 
char a;

void setup() {
  if (debug == 1)
  {
    Serial.begin(9600);
  }
}
void loop() {
  if (Serial.available())
  {
    a = Serial.read();
    if (a  == 'p') {
      piezzo.play(Stanza, Stanzal);
      piezzo.play(Stanza2, Stanza2l);
      piezzo.play(Stanza3, Stanza3l);
      piezzo.play(Chorus, Chorusl);
      piezzo.play(Chorus2, Chorus2l);
      piezzo.play(Chorus, Chorusl);
      piezzo.play(Chorus3, Chorus3l);
    }
  }


  delay(1000);
}
