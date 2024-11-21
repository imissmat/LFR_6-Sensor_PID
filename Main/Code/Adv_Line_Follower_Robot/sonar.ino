void frontsonar() {
  f_sonar = front_sonar.ping_cm();
}

void sonar_test() {
  while (1) {
    f_sonar = front_sonar.ping_cm();
    Serial.print("f_sonar: ");
    Serial.print(f_sonar);
    if (2 < f_sonar && f_sonar < 25) {
      Serial.println("front Detected");
    } else {
      Serial.println("Not Detected");
    }
  }
}

void obstacle_avoid() { //execute this function for avoiding obstacle
  motor(turn_speed, -turn_speed);
  delay(300);
  motor(150, 150);
  delay(350);
  motor(-turn_speed, turn_speed);
  delay(300);
  motor(150, 150);
  delay(600);
  motor(-turn_speed, turn_speed);
  delay(400);
  motor(150, 150);
  delay(130);
  while(sensor[0] + sensor[1] + sensor[2] + sensor[3] + sensor[4] + sensor[5]) sensor_reading();
  motor(0,0);
  delay(130);
  motor(turn_speed, -turn_speed);
  delay(440);
}