#include "mbed.h"
#include <iostream>
 
// Initialize a pins to perform analog input and digital output fucntions
AnalogIn   ain(PA_0);
DigitalOut dout(PG_13);
uint32_t counter=0; 
int main(void)
{

  float prev{0};
  float curr{0};
    while (1) {
        // test the voltage on the initialized analog pin
        //  and if greater than 0.3 * VCC set the digital pin
        //  to a logic 1 otherwise a logic 0
        printf("normal %f", ain.read());
        float voltage = ain.read();
        curr=100*voltage;



        if(curr-prev < 2) {
            //
            counter++;
            if (counter >= 10){
              cout<<" no breathing "<<endl;
              dout=1; 
              //wait(2);

            }
        }
        else {
            cout<<" breathing "<<endl;
            counter=0;
        }

        cout<<"This is the counter: "<< counter<<endl;



        
        // print the percentage and 16 bit normalized values
        //printf("percentage: %3.3f%%\n", ain.read()*100.0f);
        cout<<endl;
        //printf("normalized: 0x%04X \n", ain.read_u16());
        thread_sleep_for(1000);
        prev=curr;


    }
}