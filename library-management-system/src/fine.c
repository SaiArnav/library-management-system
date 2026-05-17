#include <stdio.h>
#include "fine.h"

int calculateFine(int dueDay, int returnDay) {

    int lateDays;
    int fine;

    if(returnDay <= dueDay) {

        return 0;
    }

    lateDays = returnDay - dueDay;

    fine = lateDays * 2;

    return fine;
}