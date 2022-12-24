void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // Initialize the LED_BUILTIN pin as an output
}

// 0 = LOW / 1 = HIGH

void loop() {
  digitalWrite(LED_BUILTIN, 0);  // Turn the BuiltIn LED on by making the voltage LOW
  delay(5000);                   // Wait 5000 miliseconds
  digitalWrite(LED_BUILTIN, 1);  // Turn the BuiltIn LED off by making the voltage HIGH
  delay(5000);                   // Wait 5000 miliseconds
}
