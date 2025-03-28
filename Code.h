#include <Servo.h>

Servo melodyServo;  
Servo beatServo;    

const int melodyNotes[][2] = {
  {130, 150}, 
  {100, 150}, 
  {70, 150},  
  {130, 150}, 
  {100, 150}, 
  {180, 300}, 
  {90, 100},  
  {50, 100},  
  {90, 100}, 
  {50, 100},  
  {90, 100},  
  {130, 150}, 
  {100, 150}, 
  {180, 300}, 
  {120, 200},
  {180, 200}, 
  {100, 400}  
};

void setup() {
  melodyServo.attach(9);   // DF9GMS on pin 9
  // beatServo.attach(10); // Uncomment for percussion
  
  // Initialize positions
  melodyServo.write(90);
  // if using beat servo: beatServo.write(0);
}

void loop() {
  playMarioTheme();
  delay(2000); // Pause between plays
}

void playMarioTheme() {
  for (int i = 0; i < 17; i++) {
    // Play melody note
    melodyServo.write(melodyNotes[i][0]);
    
    // Add percussion on strong beats (optional)
    if (i == 0 || i == 5 || i == 13) {
      // beatServo.write(180); // Uncomment for kick
      // delay(20);
      // beatServo.write(0);
    }
    
   
    if (i != 5 && i != 13) { // Skip long notes
      delay(melodyNotes[i][1] - 30);
      melodyServo.write(melodyNotes[i][0] + 5); // Small bump
      delay(30);
    } else {
      delay(melodyNotes[i][1]);
    }
  }
}

// Optional coin sound effect
void coinSound() {
  for (int i = 0; i < 8; i++) {
    melodyServo.write(60 + (i%2)*60);
    delay(50);
  }
}
