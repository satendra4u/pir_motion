//macro definitions of PIR motion sensor pin and LED pin*/
#define PIR_MOTION_SENSOR D0//Use pin 2 to receive the signal from the module 
#define LED	D3//the Grove - LED is connected to D3 of Arduino
#define DEBOUNCE_SECONDS 1
int lastStateSwitchTime = 0;


int i = 0;
void setup()
{
     // Register a Spark variable here
    Spark.variable("i", &i, INT);
  
    pinsInit();
}

void loop() 
{
    
    
	
	 
	if(isPeopleDetected())//if it detects the moving people?
	{

        int now = Time.now(); 
        if (now - lastStateSwitchTime > DEBOUNCE_SECONDS)
        {
	            Spark.publish("move", "on", 60, PRIVATE);
		        turnOnLED();	
		        lastStateSwitchTime = now;
        }
	}
	    else{
	    
		    turnOffLED();
	   }
}

void pinsInit()
{
	pinMode(PIR_MOTION_SENSOR, INPUT);
	pinMode(LED,OUTPUT);
}

void turnOnLED()
{
      
	digitalWrite(LED,HIGH);
	//Spark.publish("spark-hq/motion", "Motion Detected");
	
}


void turnOffLED()
{
	digitalWrite(LED,LOW);
}


/***************************************************************/
/*Function: Detect whether anyone moves in it's detecting range*/
/*Return:-boolean, ture is someone detected.*/
boolean isPeopleDetected()
{
    //delay(500);
	
	
	int sensorValue = digitalRead(PIR_MOTION_SENSOR);
	

	
	i = sensorValue;
	
	//delay(500);
	if(sensorValue)//if the sensor value is HIGH?
	{
	  
		 return true;//yes,return ture
	}
	else
	{
	     
		 return false;//no,return false
	}
}