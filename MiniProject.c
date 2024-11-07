#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>
#include <ctype.h>
#include <math.h>


struct RocketMeter 
{
    int time;       
    float pressure;   
    float velocity;   
    float altitude;   
    float acceleration;
};


void displayVals(struct RocketMeter rocket) 
{
    printf(" \n Time: %d sec \n Pressure: %0.2f bar \n Velocity: %0.2f m/s \n Altitude: %0.2f m\n Acceleration: %0.2f m/s^2 \n", 
                rocket.time, rocket.pressure, rocket.velocity, rocket.altitude, rocket.acceleration);
}


int main() 
{

    int burn;
    int i =0;
    int timeBtwData = 3;

    struct RocketMeter rocket = {0, 1.01325, 0, 0};          
    float thrust = 5700;   
    float mass = 32.21;        
    float g = 9.81;       

    int ts1, ts2;

    

    /*
    char mode;
    printf("User input (U) or simulated output (S)? : ");
    scanf("%c", &mode);

    mode = toupper(mode);

    switch(mode)
    {
        case 'S':
        */

            printf("Enter burn time: ");
            scanf("%d", &burn);

            float altitudes[burn]; 

            printf("Enter time difference between data calculated: ");
            scanf("%d", &timeBtwData);

            rocket.acceleration = 0;

            while (rocket.time <= burn) {
                
                rocket.velocity = (thrust / mass - g) * rocket.time;
                rocket.altitude += rocket.velocity * 1;  
                altitudes[i] = rocket.altitude;
                rocket.pressure = 1.01325 * pow((1 - (0.0000225577 * rocket.altitude)), 5.25588); 

                if(rocket.time > 0)
                {
                    rocket.acceleration = ((thrust/mass) - g);
                }
                
                if(rocket.time % timeBtwData == 0)
                {
                    displayVals(rocket);
                }
                i++;

            
                sleep(1);

            
                rocket.time += 1;
            }

            printf("Enter timestamps between 1s to %ds to check average altitude: ", burn);
            scanf("%d %d", &ts1, &ts2);

            printf("Average altitude between timestamps %d and %d is %0.2f: \n", ts1, ts2, (altitudes[ts2]- altitudes[ts1]));
    //}

    return 0;
}
