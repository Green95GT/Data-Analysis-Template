#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

int get_open( ifstream& file1, ifstream& file2, ifstream& file3 )
{
    const int MAXCHARS = 255; //max # of filename characters
    char name1[MAXCHARS], name2[MAXCHARS], name3[MAXCHARS];

    cout << "Please enter the name of the files you wish to open starting with the users, then purchases, and finally messages: ";
    cin >> name1 >> name2 >> name3; //user enters file names to open

    file1.open(name1); //opens users file
    file2.open(name2); //opens purchases file
    file3.open(name3); //opens messages file

    //Now to check for successful opening of these files    
    if ( file2.fail() || file2.fail() || file3.fail() )
    {
        cout << "\n One of the files was not successfully opened "
             << "\n Please check that the file currently exists." << endl;
        exit(1);
    }
    else
        return 0;
}     

void load_vectors( ifstream& file1, ifstream& file2, ifstream& file3 )
{
    //read users file
    
    const int YMAX = 5, M_MAX = 3, DMAX = 3;
    
    char sy[YMAX], sm[M_MAX], sd[DMAX];
    
    string u;
    vector<string> U;
    
    int ch, y, mo, d;
    vector<int> Y, Mo, D;
    

    while( ( ch = file1.peek() ) != EOF ) //check for end of file
    {
        if( getline( file1, u, ',' ) ) //inputs string until first comma. Uses getline( string )
        {
            U.push_back( u );
        }    
        
        if( file1.getline( sy, YMAX, '-' ) )  //here use getline( char ) to enter in the year which is before first hyphen
        {   
            y = atoi( sy ); //converts char into int.
            Y.push_back( y );
        }    
        
        if( file1.getline( sm, M_MAX, '-' ) ) //the rest below follows the conversion process above for the month and day
        {
            mo = atoi( sm );
                        
            switch( mo )
            {
                case 1:
                    mo = 0;
                    break;
                case 2:
                    mo = 31;
                    break;
                case 3:
                    mo = 59;
                    break;
                case 4:
                    mo = 90;
                    break;
                case 5:
                    mo = 120;
                    break;
                case 6:
                    mo = 151;
                    break;
                case 7:
                    mo = 181;
                    break;
                case 8:
                    mo = 212;
                    break;
                case 9:
                    mo = 243;
                    break;
                case 10:
                    mo = 273;
                    break;
                case 11:
                    mo = 304;
                    break;
                case 12:
                    mo = 334;
                    break;
            }
            Mo.push_back( mo );
        }
        
        if( file1.getline( sd, DMAX, '\n' ) )
        {
            d = atoi( sd );
            d = d + mo;
            D.push_back( d );
        }
    } //stores username and date of signup into vectors. First uses getline (for strings only) then converts numbers into ints
    
    file1.close();

   /*-------------------------------------------------------------------------------------------------------------------*/    
     
    //start of storing purchase data

    const int cMAX = 3;
    char py[YMAX], pm[M_MAX], pd[DMAX], pc[cMAX];     
    
    string pu;
    vector<string> Pu;
    
    int pY, pM, pD, pC;
    vector<int> PY, PM, PD, PC;
    
    while( ( ch = file2.peek() ) != EOF ) //check for end of file
    {
        if( getline( file2, pu, ',' ) )
        {
            Pu.push_back( pu );
        }
          
        if( file2.getline( py, YMAX, '-' ) )
        {
            pY = atoi( py );
            PY.push_back( pY );
        }
                
        if( file2.getline( pm, M_MAX, '-' ) )
        {
            pM = atoi( pm );
            
            switch( pM )
            {
                case 1:
                    pM = 0;
                    break;
                case 2:
                    pM = 31;
                    break;
                case 3:
                    pM = 59;
                    break;
                case 4:
                    pM = 90;
                    break;
                case 5:
                    pM = 120;
                    break;
                case 6:
                    pM = 151;
                    break;
                case 7:
                    pM = 181;
                    break;
                case 8:
                    pM = 212;
                    break;
                case 9:
                    pM = 243;
                    break;
                case 10:
                    pM = 273;
                    break;
                case 11:
                    pM = 304;
                    break;
                case 12:
                    pM = 334;
                    break;
            }
            PM.push_back( pM );
        }
                    
        if( file2.getline( pd, DMAX, ',' ) )
        {
            pD = atoi( pd );
            pD = pD + pM;
            PD.push_back( pD );
        }
                
        if( file2.getline( pc, cMAX, '\n' ) )
        {
            pC = atoi( pc );
            PC.push_back( pC );
        } 
        
    } //stores username, purchase date, and purchase amount info into vectors
    
    file2.close();
    

    /*-------------------------------------------------------------------------------------------------------------*/
    
    //start of storing message data    

    
    char my[YMAX], mm[M_MAX], md[DMAX], mc[cMAX];     

    string mu;
    vector<string> Mu;

    int mY, mM, mD, mC;
    vector<int> MY, MM, MD, MC;

    while( ( ch = file3.peek() ) != EOF ) //check for end of file
    {
        if( getline( file3, mu, ',' ) )
        {
            Mu.push_back( mu );
        }
          
        if( file3.getline( my, YMAX, '-' ) )
        {
            mY = atoi( my );
            MY.push_back( mY );
        }
                
        if( file3.getline( mm, M_MAX, '-' ) )
        {
            mM = atoi( mm );
            
            switch( mM )
            {
                case 1:
                    mM = 0;
                    break;
                case 2:
                    mM = 31;
                    break;
                case 3:
                    mM = 59;
                    break;
                case 4:
                    mM = 90;
                    break;
                case 5:
                    mM = 120;
                    break;
                case 6:
                    mM = 151;
                    break;
                case 7:
                    mM = 181;
                    break;
                case 8:
                    mM = 212;
                    break;
                case 9:
                    mM = 243;
                    break;
                case 10:
                    mM = 273;
                    break;
                case 11:
                    mM = 304;
                    break;
                case 12:
                    mM = 334;
                    break;
            }
            MM.push_back( mM );
        }
                    
        if( file3.getline( md, DMAX, ',' ) )
        {
            mD = atoi( md );
            mD = mD + mM;
            MD.push_back( mD );
        }
                
        if( file3.getline( mc, cMAX, '\n' ) )
        {
            mC = atoi( mc );
            MC.push_back( mC );
        } 
    } //stores username, message date, and message amount info into vectors
    
    file3.close();

   //calculations go here using stored info in vectors from above function
}

int main()
{
    
    ifstream infile_1, infile_2, infile_3;
    vector<string> inU, inPu, inMu;
    vector<int> iny, inm, ind, inpy, inpm, inpd, inpc, inmy, inmm, inmd, inmc;
    
    get_open( infile_1, infile_2, infile_3 );

    load_vectors( infile_1, infile_2, infile_3 );
}                
