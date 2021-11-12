//
//  main.c
//  PhysicsLibrary
//
//  Created by Filip Vabroušek on 12.11.2021.
//

#include <stdio.h>
#include <string.h>

// Structs: Time, Distance = Speed
// Function speed(), v = s / t

typedef struct Time {
    double value; // 12
    char unit[5]; // s
} Time;

typedef struct Distance {
    double value; // 200
    char unit[5]; // m
} Distance;

double timeToCorrectUnit(struct Time t){
    double value = t.value;
    
    int isHour = strcmp(t.unit, "h"); // t.unit == "h"
    
    if (isHour == 0){
        value = value * 3600; // 2h = 7200s
    }
    
    return value;
}

double speed(struct Time t, struct Distance s){
    double time = timeToCorrectUnit(t);
    double speed = s.value / time;
    return speed;
}


int main(int argc, const char * argv[]) {
    Time time = {
        .value = 1,
        .unit = "h"
    };
    
    Distance distance = {
        .value = 200,
        .unit = "m"
    };
    
    double result = speed(time, distance);
    printf("Result is %f \n", result); // 0.0556 - za vteřinu urazíme jen 0.0556m
    
    
    
    
    // Get time from user input
    double seconds;
    printf("Enter time in seconds: \n");
    scanf("%lf", &seconds);
    
    printf("Entered value is %lf \n", seconds);
    time.value = seconds;
    strcpy(time.unit, "s");
    
    
    // Get distance from user input
    double idistance;
    printf("Enter distance in meters: \n");
    scanf("%lf", &idistance);
    
    printf("Entered value is %lf \n", idistance);
    distance.value = idistance;
    strcpy(distance.unit, "m");
    
    
    double finalResult = speed(time, distance); // 7200s, 200m 0.025 ms....
    printf("Should be 0.025ms: %f", finalResult);
    
    
    FILE * file;
    char url[] = "/Users/filipvabrousek/cfile/output.txt";
    
    file = fopen(url, "w");
    fprintf(file, "Result is %f", finalResult);
    fclose(file);
    
    
    
    return 0;
}

// Přečtení vstupu od uživatele
// Zápis do souboru
 
