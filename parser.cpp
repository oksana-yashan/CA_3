#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <getopt.h>

using namespace std;

int main (int argc, char **argv)
{
  int curr;
  map <char, int> is_option;
  string list_op = "List of options:\n"
   "--help -h\n"
   "--list -l\n"
   "--version -v\n"
   "--int -I\n"
   "--decimal -D\n"
   "--char -C\n"
   "--string -S\n"; 

string help_op = "Help:\n"
   "make all \n"
   "make example\n"
   "============\n"; 

  while (1)
    {
      static struct option long_options[] =
        {
          {"help", no_argument,       0,  'h'},
          {"list",   no_argument,     0, 'l'},
          {"version", no_argument,  0, 'v'},

          {"int",     required_argument, 0, 'I'},
          {"decimal",  required_argument,0, 'D'},
          {"char", required_argument, 0, 'C'},
          {"string",  required_argument, 0, 'S'},
          {0, 0, 0, 0},
        };
      // getopt_long stores the option index here
      int index = 0;
      curr = getopt_long (argc, argv, "hlvI:D:C:S:",
                       long_options, &index);

      //Detect the end of the options
      if (curr == -1)
        break;

      switch (curr)
        {
        case 0:
          //If this option set a flag, do nothing else now
          if (long_options[index].flag != 0)
            break;
          printf ("option %s", long_options[index].name);
          if (optarg)
            printf (" with arg %s", optarg);
          printf ("\n");
          break;

        case 'h':
          if (is_option['h'] == 0){
            cout<< help_op<<endl; 
            is_option['h'] = 1;
            break;
          }
          break;

        case 'l':
          if (is_option['l'] == 0){
            cout << list_op <<endl;
            is_option['l'] = 1;
            break;
          }
          break;

        case 'v':
          if (is_option['v'] == 0){
            printf("Version: 1.0.0\n"); 
            is_option['v'] = 1;
            break;
          }
          break;



        case 'I':
          
          if (is_option['I'] == 0){
            printf ("option -I with value `%s'\n", optarg);
            is_option['I'] = 1;
            break;
          }
          break;

        case 'D':
          if (is_option['D'] == 0){
            printf ("option -D with value `%s'\n", optarg);
            is_option['D'] = 1;
            break;
          }
          break;

        case 'C':
          
          if (is_option['C'] == 0){

            printf ("option -C with value `%s'\n", optarg);
            is_option['C'] = 1;
            break;
          }
          break;
          
        case 'S':
          if (is_option['S'] == 0){
            printf ("option -S with value `%s'\n", optarg);
            is_option['S'] = 1;
            break;
          }
          break;
              
        case '?':
          break;

        default:
          abort ();
        }
    }

    /* Print any remaining command line arguments (not options). */
  if (optind < argc)
    {
      printf ("non-option element: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }

  exit (0);
}

