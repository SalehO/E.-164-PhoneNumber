#include <iostream> 
#include <string>
using namespace std; 


string cell(string n);


int main() 
{ 
    string input;
    cout<<"\nPlease enter a Phone number: ";
    getline(cin,input);
    if(cell(input) != "\0")
    {
        cout<< endl<<"Phone number in E. 164 format: "<<cell(input)<<endl<<endl;
    }
    else
    {
        cout<<endl<<"Error: Invalid input! \n\n";
    }
    return 0; 
}




/**
 @param = string
 @return string in correct format or empty string  if input is not valid
*/
string cell(string n)
{
    char temp[n.length()];
    int h = 0;

     // delete white spaces
    for(int j =0 ; j <n.length() ; j++)
    {
       // remove pranthesis and dash if string is in this format (000)000-000 or (000) 000-000
        if(n[0] == '(' && n[4]== ')')
        {
            n[0] = ' ';
            n[4] = ' ';
            if(n[9]=='-')
            { 
                n[9] = ' ';
            }
            else if(n[8]=='-')
            { 
                n[8] = ' ';
            }
        }

        //check if input has any invalid values
        if(n[j] != '0' && n[j] != '1' && n[j] != '2' && n[j] != '3' && n[j] != '4' && n[j] != '5' && n[j] != '6' && n[j] != '7' && n[j] != '8' && n[j] != '9' && n[j] != ' '  )
        {
            return "\0"; //string contains invalid character
        }
        if(n[j] != ' ' )
        {
        temp[h] = n[j]; 
        h++;
        }
        
    }
    temp[h] = '\0'; // add end character to temp

    n = temp; //set n to temp which is the string witout spaces

    if(h != 10) // check for size of phone number
    {        
         return "\0";
    }

    n = "+1" + n; // adds +1 for the E. 164 format
    return n;

}