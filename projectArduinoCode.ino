int coffee = 2;
int milk = 3;
int water = 4;
int sweetener = 5;
int orangeJuice = 6;

//2000 => 50 ml

char SelectedDrink[6]; //SelectedDrink comes in form of an integer from the app
int i = 0;
int ok = 0;

int pourNextAfter = 500;

void setup() {
  
  Serial.begin(9600); //For the bluetooth

  //set the relay pins
  pinMode(coffee, OUTPUT);
  pinMode(milk, OUTPUT);
  pinMode(water, OUTPUT);
  pinMode(sweetener, OUTPUT);
  pinMode(orangeJuice, OUTPUT);
  
  //initialize them to "TURNED OFF"
  digitalWrite(coffee, HIGH);
  digitalWrite(milk, HIGH);
  digitalWrite(water, HIGH);
  digitalWrite(sweetener, HIGH);
  digitalWrite(orangeJuice, HIGH);

}

void loop() {

  while(Serial.available() > 0) {
    SelectedDrink[i++] = Serial.read();
  }
  
    prepareDrink(SelectedDrink);
  
  
  for(int j = 0; j < i; j++) {
    
  //Serial.write(SelectedDrink[j]);
    SelectedDrink[j] = ' ';
  }
  
  i = 0;

}

void prepareDrink(char drink[6]) {
  
  delay(800);

  //Simple coffee
  if(drink[5] == '1') {
    
    pour(coffee, 6000);
    
  } 
  //coffee with milk
  else if(drink[5] == '2') {
    pour(coffee, 4000);
    pour(milk, 2000);
    
  } 
  //coffee with milk and water
  else if(drink[5] == '3') {
    pour(coffee, 3000);
    pour(milk, 2000);
    pour(water, 1000);
    
  } 
  //coffee with water
  else if(drink[5] == '4') {
    pour(coffee, 5000);
    pour(water, 1000);
    
  } 
  //water
  else if(drink[5] == '5') {
    pour(water, 5000);
    
  } 
  //milk
  else if(drink[5] == '6') {
    pour(milk, 5000);
    
  } 
  //coffee with sweetener
  else if(drink[5] == '7') {
    pour(coffee, 4000);
    pour(sweetener, 1000);
    
  } 
  //coffee with milk and sweetener
  else if(drink[5] == '8') {
    pour(coffee, 2000);
    pour(milk, 1000);
    pour(sweetener, 500);
    
  } 
  //orangeJuice
  else if(drink[5] == '9') {
    pour(orangeJuice, 5000);
  }

  if(ok == 1) {
    Serial.write('g');
    Serial.write('o');
    ok = 0;
  }
  
}

void pour(int relay, int milisec) {
  digitalWrite(relay, LOW);
  delay(milisec);
  digitalWrite(relay, HIGH);
  delay(pourNextAfter);
  ok = 1;
}
