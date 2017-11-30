/** Operational Amplifier Circuits
 *  Computer Programming
 *  C00187998
 *  Gerard Murphy
 *  06/11/17
 */

#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdio>
#include <windows.h>/**< preprocessor directives */

using namespace std;

using namespace std;

    char displayMenu(void);
    void invVals (void);
    void noninvVals (void);

    void inverting(double *avPtr, double rf, double rin, double *voutPtr, double vin);
    void noninverting(double *avPtr, double r2, double r1, double *voutPtr, double vin);/**< function prototypes */



int main(void)
{

    cout << "Operational Amplifier Circuits" << endl;/**< Title */

    char choice;/**< variable declarations */


    do/**< Do while Loop */
    {
        choice = displayMenu();

        switch (choice)
        {
            case 'a':       invVals ();
                            break;

            case 'b':       noninvVals ();
                            break;

            case 'q':       system("cls");
                            cout <<"Goodbye...\n";
                            break;

            default:	    cout <<"\nInvalid input, press any key to continue..." ;
                            fflush(stdin);
                            getchar();
                            break;
    }
}
    while (choice != 'q' );

    return 0;
}


char displayMenu(void)
{
    char choice;/**< Variable Decalartion */

    system("cls");/**< Turns previous screen off */

    /**< Command choice */

    cout <<"Operational Amplifier Circuits" ;
    cout <<"\n\nPress 'a' for an inverting amplifier ...";
    cout <<"\nPress 'b' for a non-inverting amplifier ...";
    cout <<"\nPress 'q' to quit ...\n\nChoice: ";

    fflush(stdin);
    choice = getchar();
    return choice;
}

void invVals ()
{

    system("cls");

    double vcc = -1, vee = 1, vin, rin = 0, rf = 0, av, vout;
    double *avPtr = &av, *voutPtr = &vout;


    cout << "Inverting Amplifier Circuit\n\n" ;/**< Title */


    while (rin <= 0)/**< Ensures a positive value is read in */
    {
        cout << "\nRin :\t";
        cin >> rin;
    }

    while (rf <= 0)/**< Ensures a positive value is read in */
    {
        cout << "\nRf :\t";
        cin >> rf;
    }

    while (vcc <= 0)/**< Ensures a positive value is read in */
    {
        cout << "\nVcc :\t";
        cin >> vcc;
    }

    while (vee >= 0)/**< Ensures a positive value is read in */
    {
        cout << "\nVee :\t";
        cin >> vee;
    }

    cout << "\nVin :";
    cin >> vin;

    /**< Calling 'inverting' function */
    inverting (avPtr, rf, rin, voutPtr, vin);

    cout << "\nAv =\t" << av << "\n\nVout =\t" << vout;/**< displays values */

    /** if vout is outside of vcc or vcc, display correct vcc or vee value */
    if(vout >= vcc || vout <= vee)
    {
        if(vin <= 0)
        {
            cout << "\n\nAmplifier is in satutation \n\nVout =\t " << vcc ;
        }
        else
        {
            cout << "\n\nAmplifier is in satutation \n\nVout =\t " << vee ;
        }
    }

    cout << "\n\nPress enter to return to the main menu..." ;/**< returns to main screen */
    fflush(stdin);
    getchar();

    return ;
}
/**< function to calculate gain and vout */
void inverting(double *avPtr, double rf, double rin, double *voutPtr, double vin)
{
    *avPtr = -(rf/rin);

    *voutPtr = *avPtr * vin;

    return ;
}
 /**<  Sub function for non inverting amplifier */
void noninvVals ()
{

    system("cls");

    double vcc = -1, vee = 1, vin, r1 = 0, r2 = 0, av, vout;/**< variable decalarations */
    double *avPtr = &av, *voutPtr = &vout;


    cout << "Non - Inverting Amplifier Circuit\n\n" ;/**< displays title */


    while (r1 <= 0)/**< ensuring positive values are read in */
    {
        cout << "\nR1 :\t";
        cin >> r1;
    }

    while (r2 <= 0)
    {
        cout << "\nR2 :\t";
        cin >> r2;
    }

    while (vcc <= 0)
    {
        cout << "\nVcc :\t";
        cin >> vcc;
    }

    while (vee >= 0)/**< ensuring negative values */
    {
        cout << "\nVee :\t";
        cin >> vee;
    }

    cout << "\nVin :\t";
    cin >> vin;


    noninverting (avPtr, r2, r1, voutPtr, vin);/**< callin non-inverting function */


    cout << "\nAv =\t" << av << "\n\nVout =\t" << vout ;

    /** if vout is outside of vcc or vcc, display correct vcc or vee value */
    if(vout >= vcc || vout <= vee)
    {
        if(vin >= 0)
        {
            cout << "\n\nAmplifier is in satutation \n\nVout =\t " << vcc ;
        }
        else
        {
            cout << "\n\nAmplifier is in satutation \n\nVout =\t " << vee ;
        }
    }


    cout << "\n\nPress enter to return to the main menu..." ;/**< allows to retun to main screen */
    fflush(stdin);
    getchar();

    return ;
}
/**< function to calculate gain and vout */
void noninverting(double *avPtr, double r2, double r1, double *voutPtr, double vin)
{
    *avPtr = 1 + (r2 / r1);

    *voutPtr = *avPtr * vin;

    return ;
}
