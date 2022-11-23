#ifndef INC_2_1_DATE_H
#define INC_2_1_DATE_H

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

int cmpDates(Date left, Date right);

#endif //INC_2_1_DATE_H
