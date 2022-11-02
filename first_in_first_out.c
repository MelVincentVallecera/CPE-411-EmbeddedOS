// First In First Out Scheduling
// Mel Vincent Vallecera BSCPE-4B

int bt[] = {2, 8, 1, 3, 10, 5}; // Burst time inputs
int p[] = {8, 7, 6, 5, 4, 3}; // Processes pin inputs
int size = 6;
float AWT, wt;

void setup() {
  // LEDs Pin configuration
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for ( int i = 0; i < size; i++) {
    Arrive(p[i], bt[i]); // Task arrives to queue 
    
  	if (i < size - 1) {
      Wt(bt[i]); // Waiting time for task
  	}
  }
  
  Serial.println("Average Waiting Time : ");
  Serial.println(AWT/size); // Prints the average waiting time during process
  Serial.println("End of the Process. ");
  delay(10000);
}

void Arrive(int task, int burstTime) {
  digitalWrite(task, HIGH);
  delay(burstTime * 1000); // LEDs light up to burst time
  digitalWrite(task, LOW);
}

void Wt(int waitingTime) {
  wt = wt + waitingTime; 
  AWT = AWT + wt;
}