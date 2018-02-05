int del = 60;
int i[] = {4,7,8};
int x[] = {0,0,0};
int len[] = {4,2,4};

long duration, cm, inches;
int trig = 9;
int echo = 10;

void setup() {
  pinMode(i[0], OUTPUT);
  pinMode(i[1], OUTPUT);
  pinMode(i[2], OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

int iter = 0;

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  pinMode(echo, INPUT);
  duration = pulseIn(echo, HIGH);
  cm = (duration/2) / 29.1;

  if (cm < 50) {
    while (x[iter] <= len[iter]) {
      x[iter]++;
      digitalWrite(i[iter], HIGH);
      delay(del);
    
      digitalWrite(i[iter], LOW);
      delay(del);
    }
    memset(x, 0, sizeof(x));
    iter++;
    iter %= 3;
  }
  else {
    iter = 0;
  }
}


