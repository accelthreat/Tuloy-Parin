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
double Stanza [] = {F4, E, F4, E, C5, E, D5, Q , F4, E, F4, E + TE , F4, E + TE, F4, E  , DS5, E, D5, E, D5, Q, D5, E, G5, E, F5, E, F5, E, F5, E, D5, E, C5, Q + E, C5, Q + E, R, H, END};
double Stanza2 [] = {AS4, TE + E, AS4, TE + E, AS4, TE + E, R , Q, AS4, E, D5, E, D5, E, D5, E, D5, E, C5, E, R, Q, F4, Q, F5, Q, D5, Q, C5, Q, AS4, E, G4, E, R, H, END};
double Stanza3 [] = {F4, TE + S, AS4, TE + S, AS4, TE + S, AS4, TE + S, R, E, F4, E, D5, E, DS5, E, D5, E, C5, E, R, Q, F4, E, G4, E, R, E, D5, E, R, E, D5, E, D5, E, C5, E, C5, Q + E, R, H + E, END};
double Chorus [] = {F4, E, G5, E, F5, E, F5, E, D5, E, G5, E, F5, E, F5, E + TE + S, F5, E + TE + S, F5, E + TE + S, R, Q, END};
double Chorus2 [] = {F4, E, G5, E, F5, E, F5, E, D5, E, DS5, E, D5, E, D5, E, C5, Q, D5,  Q, C5, E, AS4, E, R, Q , END};
double Chorus3 [] = {D5, E, D5, E, D5, E, D5, E, DS5, E, D5, Q, C5, Q, AS4, E + S, R, Q , END};


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
      piezzo.play(Stanza);
      piezzo.play(Stanza2);
      piezzo.play(Stanza3);
      piezzo.play(Chorus);
      piezzo.play(Chorus2);
      piezzo.play(Chorus);
      piezzo.play(Chorus3);
    }
  }


  delay(1000);
}
