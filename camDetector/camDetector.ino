int sw = 2;       // 스위치(SW) 핀 설정
int led = 13;       // LED 핀 설정
 
int state = 0;      // LED 상태
int reading;          // SW 상태
int previous = LOW;   // SW 이전 상태
 
long time = 0;        // LED가 ON/OFF 토글된 마지막 시간
long debounce = 100;  // Debounce 타임 설정
 
void setup()
{
  pinMode(sw, INPUT_PULLUP); // SW 를 설정, 아두이노 풀업저항 사용
  pinMode(led, OUTPUT);      // LED 설정
}
 
void loop()
{
  reading = digitalRead(sw);  // SW 상태 읽음
 
  //SW 가 눌려졌고 스위치 토글 눌림 경과시간이 Debounce 시간보다 크면 실행
  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    state++;
    Serial.print("State Value");  
    Serial.print("\t");      
    Serial.println(state);
    time = millis();
  }
  switch(state%5){
    case 0: 
      digitalWrite(led,LOW);
      Serial.println(state);
      break;
    case 1: 
      digitalWrite(led, HIGH);
      Serial.println(state);
      delay(500);        
      digitalWrite(led,LOW);
      delay(500);
      break;
    case 2:
      digitalWrite(led, HIGH);
      Serial.println(state);
      delay(250);        
      digitalWrite(led,LOW);
      delay(250);
      break;
    case 3: 
      digitalWrite(led, HIGH);
      Serial.println(state);
      delay(125);        
      digitalWrite(led,LOW);
      delay(125);
      break;
    case 4: 
      digitalWrite(led, HIGH);
      Serial.println(state);
      delay(70);        
      digitalWrite(led,LOW);
      delay(70);
      break;
  }
  previous = reading;
}
