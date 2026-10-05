/* Including required headers. */

#include "../../../include/dfa/dfa_engine/dfa_stop_state_feed.h"

#include <stdio.h>              // To get access to basic I/O functions










/* Tells at which state the byte processor stopped. */

void dfa_stop_state_feed(int stop_state, char *filepath, int row, int column)
{
    switch (stop_state)
    {
        case -14:
            printf("ERROR (%s) :: %d:%d :: After transition declaration the line must be either closed or new transition must be declared!\n", filepath, row, column);
            break;


        case -13:
            printf("ERROR (%s) :: %d:%d :: Transitioning state must be declared immediately after symbols!\n", filepath, row, column);
            break;
        

        case -12:
            printf("ERROR (%s) :: %d:%d :: Either transition symbols or ELSE symbol only could be added when declaring transitions!\n", filepath, row, column);
            break;
        

        case -11:
            printf("ERROR (%s) :: %d:%d :: Either transition symbols or ELSE symbol only could be added when declaring transitions!\n", filepath, row, column);
            break;
        

        case -10:
            printf("ERROR (%s) :: %d:%d :: \n", filepath, row, column);
            break;
        

        case -9:
            printf("ERROR (%s) :: %d:%d :: Transition declaration must immediately follow transition field operator!\n", filepath, row, column);
            break;
        

        case -8:
            printf("ERROR (%s) :: %d:%d :: ELSE transitions must be closed without any other addition!\n", filepath, row, column);
            break;
        

        case -7:
            printf("ERROR (%s) :: %d:%d :: Only transition field operator can be added after state declaration!\n", filepath, row, column);
            break;
        

        case -6:
            printf("ERROR (%s) :: %d:%d :: Either a comma or closing of state type enclosures can follow state type declaration!\n", filepath, row, column);
            break;
        

        case -5:
            printf("ERROR (%s) :: %d:%d :: State type not mentioned in string enclosures!\n", filepath, row, column);
            break;
        

        case -4:
            printf("ERROR (%s) :: %d:%d :: Only state types can be mentioned within state type enclosures!\n", filepath, row, column);
            break;
        

        case -3:
            printf("ERROR (%s) :: %d:%d :: Only transition field operator can be added after state declaration!\n", filepath, row, column);
            break;
        

        case -2:
            printf("ERROR (%s) :: %d:%d :: State name not mentioned during declaration!\n", filepath, row, column);
            break;
        

        case -1:
            printf("ERROR (%s) :: %d:%d :: A line can start with either state declaration or comment!\n", filepath, row, column);
            break;


        case 0:
            printf("OK (%s) :: %d:%d :: This is an ACCEPT state.\n", filepath, row, column);
            break;
        

        case 1:
            printf("OK (%s) :: %d:%d :: This is an ACCEPT state.\n", filepath, row, column);
            break;
        

        case 2:
            printf("ERROR (%s) :: %d:%d :: State name enclosures left unclosed!\n", filepath, row, column);
            break;
        

        case 3:
            printf("ERROR (%s) :: %d:%d :: State name enclosures left unclosed!\n", filepath, row, column);
            break;
        

        case 4:
            printf("ERROR (%s) :: %d:%d :: State name enclosures left unclosed!\n", filepath, row, column);
            break;
        

        case 5:
            printf("ERROR (%s) :: %d:%d :: State left undefined!\n", filepath, row, column);
            break;
        

        case 6:
            printf("ERROR (%s) :: %d:%d :: State type declaration enclosures left unclosed!\n", filepath, row, column);
            break;
        

        case 7:
            printf("ERROR (%s) :: %d:%d :: State type is not mentioned during declaration!\n", filepath, row, column);
            break;
        

        case 8:
            printf("ERROR (%s) :: %d:%d :: String enclosures left unclosed during state type declaration!\n", filepath, row, column);
            break;

        
        case 9:
            printf("ERROR (%s) :: %d:%d :: String enclosures left unclosed during state type declaration!\n", filepath, row, column);
            break;
        

        case 10:
            printf("ERROR (%s) :: %d:%d :: State type declaration enclosures left unclosed!\n", filepath, row, column);
            break;
        

        case 11:
            printf("ERROR (%s) :: %d:%d :: State left undefined!\n", filepath, row, column);
            break;
        

        case 12:
            printf("ERROR (%s) :: %d:%d :: ELSE symbol declaration enclosures left unclosed!\n", filepath, row, column);
            break;
        

        case 13:
            printf("ERROR (%s) :: %d:%d :: State left undefined!\n", filepath, row, column);
            break;

        
        case 14:
            printf("ERROR (%s) :: %d:%d :: No symbols mentioned for transition!\n", filepath, row, column);
            break;
        

        case 15:
            printf("ERROR (%s) :: %d:%d :: String enclosures left unclosed during transitioning symbol declaration!\n", filepath, row, column);
            break;
        

        case 16:
            printf("ERROR (%s) :: %d:%d :: String enclosures left unclosed during transitioning symbol declaration!\n", filepath, row, column);
            break;
        

        case 17:
            printf("ERROR (%s) :: %d:%d :: String enclosures left unclosed during transitioning symbol declaration!\n", filepath, row, column);
            break;
        

        case 18:
            printf("ERROR (%s) :: %d:%d :: Transition symbol declaration enclosures left unclosed!\n", filepath, row, column);
            break;
        

        case 19:
            printf("ERROR (%s) :: %d:%d :: Comma appended to add symbols but no symbols were added!\n", filepath, row, column);
            break;
        

        case 20:
            printf("ERROR (%s) :: %d:%d :: Transitioning state name was never written!\n", filepath, row, column);
            break;
        

        case 21:
            printf("ERROR (%s) :: %d:%d :: Transitioning state name enclosures were not closed!\n", filepath, row, column);
            break;
        

        case 22:
            printf("ERROR (%s) :: %d:%d :: Transitioning state name enclosures were not closed!\n", filepath, row, column);
            break;
        

        case 23:
            printf("ERROR (%s) :: %d:%d :: Transitioning state name enclosures were not closed!\n", filepath, row, column);
            break;
        

        case 24:
            printf("ERROR (%s) :: %d:%d :: End of declaration punctuation wasn't added!\n", filepath, row, column);
            break;
        

        case 25:
            printf("ERROR (%s) :: %d:%d :: Transitioning state name was never written!\n", filepath, row, column);
            break;
        

        case 26:
            printf("ERROR (%s) :: %d:%d :: Transitioning state name enclosures were not closed!\n", filepath, row, column);
            break;
        

        case 27:
            printf("ERROR (%s) :: %d:%d :: Transitioning state name enclosures were not closed!\n", filepath, row, column);
            break;
        

        case 28:
            printf("ERROR (%s) :: %d:%d :: Transitioning state name enclosures were not closed!\n", filepath, row, column);
            break;
        

        case 29:
            printf("ERROR (%s) :: %d:%d :: End of declaration punctuation wasn't added!\n", filepath, row, column);
            break;
    }
}