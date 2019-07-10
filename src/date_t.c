#include "../libs/date_t.h"

time_t Time_t( date_t date ) {  
  struct tm current_date = Struct_tm( date );
  return mktime(&current_date);  
}

struct tm Struct_tm( date_t date ) {
  time_t now = time(NULL);  
  struct tm current_date = *localtime(&now);

  current_date.tm_mday = date.day,    current_date.tm_mon = date.month - 1;   current_date.tm_year = date.year - 1900;
  current_date.tm_hour = date.hour;   current_date.tm_min = date.minute;      current_date.tm_sec = 0;

  return current_date;
}

date_t Date_t( int day, int month, int year, int hour, int minute ) {
  return (date_t) { .day=day,   .month=month,   .year=year, 
                    .hour=hour, .minute=minute, };
}

date_t convert_Struct_tm_to_Date_t( struct tm time_obj ) {
  return Date_t( time_obj.tm_mday, time_obj.tm_mon + 1, time_obj.tm_year + 1900, time_obj.tm_hour, time_obj.tm_min );
}

date_t copy_time_members_date_t( date_t *lhs, date_t *rhs ) {
  lhs->hour = rhs->hour;
  lhs->minute = rhs->minute;

  return *lhs;
}

date_t increment_date_t( int value, DATE_T_UNIT unit, date_t *date ) {      
  switch( unit ) {
    case YEAR:      
      date->year += value;      
      break;

    case MONTH:      
      date->month += value;      
      break;

    case DAY:      
      date->day += value;      
      break;
    
    case HOUR:      
      date->hour += value;      
      break;

    case MINUTE:
    default:      
      date->minute += value;      
      break;
  }

  time_t time_obj = Time_t(*date);
  if( time_obj == ((time_t) - 1)) {
    return *date;
  } 
  else {    
    struct tm *time_struct = localtime(&time_obj);            
    date_t new_date = convert_Struct_tm_to_Date_t(*time_struct);   
    
    copy_time_members_date_t( &new_date, date );    
    *date = new_date;        

    return new_date;
  }
}

int compare_date_t( const date_t *lhs, const date_t *rhs ) {
  time_t date_1 = Time_t(*lhs) , date_2 = Time_t(*rhs);
  double seconds = difftime( date_1, date_2 );

  if( seconds == 0 )
    return 0;
  else if( seconds > 0 )
    return 1;
  else if( seconds < 0 )
    return -1;
  else 
    return -2;
} 

bool is_equal_date_t(const date_t *lhs, const date_t *rhs) {  
  if( compare_date_t(lhs, rhs) == 0 )
    return true;
  else
    return false;
}

void print_date_t_t(date_t date) {
  char *format = "%d/%d/%d %d:%d\n";
  printf( format, date.day, date.month, date.year, date.hour, date.minute );  
}

void print_date(const date_t *date) {    
  char time_buffer[19];    
  struct tm time_struct = Struct_tm(*date);    
  strftime( time_buffer, 19, "%d/%b/%y %I:%M %p", &time_struct);
  printf( "Date: %s\n", time_buffer );

}

void print_date_range(const date_t *from_date, const date_t *to_date) {
  date_t current_date = *from_date;
  while( !is_equal_date_t(&current_date, to_date) ) {    
    print_date(&current_date);     
    increment_date_t( 1, DAY, &current_date );
  }
}