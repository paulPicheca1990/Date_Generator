#include <stdio.h>
#include "./libs/date_t.h"

int main (int argc, char *argv[]) {    
  if( argc == 6 ) {    
    date_t date1 = Date_t( atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), 
                           atoi(argv[4]), atoi(argv[5]) );    
    print_date(&date1);
    return 0;
  } else if( argc == 11 ){
    date_t date1 = Date_t( atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), 
                           atoi(argv[4]), atoi(argv[5]) );    
    date_t date2 = Date_t( atoi(argv[6]), atoi(argv[7]), atoi(argv[8]), 
                           atoi(argv[9]), atoi(argv[10]) );    
    
    print_date_range( &date1, &date2 );    
  } else {
    char *HELP_MENU[] = {
      "Bad Input!\n\n",
      "date_generator.exe usage: \n\n",
      "    (1) Print a Date:\n",
      "        [Desc]:    Parse's arguments to the program and displays the date input\n",
      "        [Command]: date_generator.exe <DATE1>\n",
      "        [Example]: date_generator.exe 01 01 1990 11 59\n",
      "                   --> [<DATE1> SYNTAX]: [day{#}] [month{#}] [year{#}] [hour{#}] [minute{#}]\n\n",
      
      "    (2) Print Range of Dates:\n",
      "        [Desc]:    Parse's arguments to the program and displays the range of dates\n",
      "        [Command]: date_generator.exe <DATE1> <DATE2>\n",
      "        [Example]: date_generator.exe  01 01 1990 11 59  01 02 1990 11 59\n",
      "                   --> [<DATE1> SYNTAX]: [day{#}] [month{#}] [year{#}] [hour{#}] [minute{#}]\n",
      "                   --> [<DATE2> SYNTAX]: [day{#}] [month{#}] [year{#}] [hour{#}] [minute{#}]\n\n",
    };

    int index, size = sizeof(HELP_MENU) / sizeof(HELP_MENU[0]);    
    for( index = 0; index < size; index++) 
      printf("%s", HELP_MENU[index]);
    return 1;
  }
}