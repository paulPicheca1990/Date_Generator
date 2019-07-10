#ifndef __DATE_T_H__
#define __DATE_T_H__

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef enum _DATE_T_UNIT {
  DAY, MONTH, YEAR, HOUR, MINUTE
} DATE_T_UNIT;

typedef struct _date_t {
  int day;
  int month;
  int year;
  int hour;
  int minute;
} date_t;

time_t Time_t( date_t date );

struct tm Struct_tm( date_t date );

date_t Date_t( int day, int month, int year, int hour, int minute );

date_t convert_Struct_tm_to_Date_t( struct tm time_obj );

date_t increment_date_t( int value, DATE_T_UNIT unit, date_t *date );

date_t copy_time_members_date_t( date_t *lhs, date_t *rhs );

int compare_date_t( const date_t *lhs, const date_t *rhs );

bool is_equal_date_t(const date_t *lhs, const date_t *rhs);

void print_date_t(date_t date);

void print_date(const date_t *date);

void print_date_range(const date_t *from_date, const date_t *to_date);

#endif