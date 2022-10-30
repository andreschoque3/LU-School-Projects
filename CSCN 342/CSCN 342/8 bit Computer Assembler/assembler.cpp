// Andres Choque
// CSIS 342-001 8 Bit Computer Assembly

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream program_input(argv[1]); // creates the file and reads it
    ofstream program_output(argv[2]);

    string inputVal_bytes;  // setting the input byte values
    string outputVal_bytes; // output byte values

    program_output << "v2.0 raw\n4*0 "; // first line statement and second line statement

    while (program_input >> inputVal_bytes) // logic for each neumonic
    {
        printf("Input: %s\n", inputVal_bytes.c_str());

        if (inputVal_bytes.compare("LDA") == 0) // This layout makes the code more efficient with one if and else if clauses
        {
            outputVal_bytes = outputVal_bytes + "3 ";
        } // output the value 03

        else if (inputVal_bytes.compare("LDY") == 0) //output the value 02
        {
            outputVal_bytes = outputVal_bytes + "2 ";
        }

        else if (inputVal_bytes.compare("LDX") == 0) //output the value 01
        {
            outputVal_bytes = outputVal_bytes + "1 ";
        }

        else if (inputVal_bytes.compare("TAX") == 0) //output the value 09
        {
            outputVal_bytes = outputVal_bytes + "9 ";
        }

        else if (inputVal_bytes.compare("SEC") == 0) //output the value 05
        {
            outputVal_bytes = outputVal_bytes + "5 ";
        }

        else if (inputVal_bytes.compare("JMP") == 0) //output the value 0b
        {
            outputVal_bytes = outputVal_bytes + "b ";
        }

        else if (inputVal_bytes.compare("ADC") == 0) //output the value 04
        {
            outputVal_bytes = outputVal_bytes + "4 ";
        }

        else if (inputVal_bytes.compare("STA") == 0) //output the value 0c
        {
            outputVal_bytes = outputVal_bytes + "c ";
        }

        else if (inputVal_bytes.compare("CLC") == 0) //output the value 08
        {
            outputVal_bytes = outputVal_bytes + "8 ";
        }

        else if (inputVal_bytes.compare("BCS") == 0) //output the value 07
        {
            outputVal_bytes = outputVal_bytes + "7 ";
        }
        else
        {
            outputVal_bytes = outputVal_bytes + inputVal_bytes; //updating the bytes
            outputVal_bytes = outputVal_bytes + " ";
        }
    }

    program_output << outputVal_bytes; // closing the file once it is read
    program_input.close();
    program_output.close();
}

// for the prog.s file I will be using the following data:
// LDA 05 TAX 0 LDY 05 0 0 ADC 0 0 0 STA 05 JMP 03