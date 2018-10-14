
#include <stdio.h>
#include <wiringPi.h>

int main(int argc, char *argv[])
{
  int i;
  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);

  while(1) {
printf("Waiting for reset\n");
while(digitalRead(0) == 1){
printf("Got a 1\n");
digitalWrite(2,HIGH);
digitalWrite(1,LOW);
ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/123", "syy1997", "EECS2031", "LAB4");
}
    printf("Waiting for event\n");
    while(digitalRead(0) == 0){
printf("Got a 0\n");
digitalWrite(2,LOW);
digitalWrite(1,HIGH);
delay(300);
digitalWrite(1,LOW);

}
  printf("Alarm\n");
  }
  /*NOTREACHED*/
  return 0 ;
}
