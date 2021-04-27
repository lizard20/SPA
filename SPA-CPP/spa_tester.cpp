

/////////////////////////////////////////////
//          SPA TESTER for SPA.cpp         //
//                                         //
//      Solar Position Algorithm (SPA)     //
//                   for                   //
//        Solar Radiation Application      //
//                                         //
//             August 12, 2004             //
//                                         //
//   Filename: spa_tester.cpp              //
//                                         //
//   Afshin Michael Andreas                //
//   afshin_andreas@nrel.gov (303)384-6383 //
//                                         //
//
//   Measurement & Instrumentation Team    //
//   Solar Radiation Research Laboratory   //
//   National Renewable Energy Laboratory  //
//   1617 Cole Blvd, Golden, CO 80401      //
//   									   //	
//   Modified by: Aldo Nunez			   //
/////////////////////////////////////////////

/////////////////////////////////////////////
// This sample program shows how to use    //
//    the SPA.C code.                      //
/////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include "spa.h"  //include the SPA header file
#include "local_data.h"  //include the SPA header file

using namespace std;

int 
main ()
{
    spa_data spa;  //declare the SPA structure
    int result;
    float min, sec;

	// time and date
	time_t t = time (NULL);
	struct tm tm = *localtime(&t);
	string months[13] = {"NULL", "Jan", "Feb", "Mar","Apr","May","Jun", "Jul", "Aug", "Sep", "Oct","Nov", "Dec"};
	
    //enter required input values into SPA structure

    spa.year          = tm.tm_year + YEAR_OFFSET;
    spa.month         = tm.tm_mon + MONTH_OFFSET;
    spa.day           = tm.tm_mday;
    spa.hour          = tm.tm_hour;
    spa.minute        = tm.tm_min;
    spa.second        = tm.tm_sec;
    spa.timezone      = TIMEZONE;
    spa.delta_ut1     = 0;
    spa.delta_t       = 67;
    spa.longitude     = LONGITUD;
    spa.latitude      = LATITUD;
    spa.elevation     = ELEVATION;
    spa.pressure      = PRESSURE;
    spa.temperature   = 11;
    spa.slope         = 30;
    spa.azm_rotation  = -10;
    spa.atmos_refract = 0.5667;
    spa.function      = SPA_ALL;

//    //call the SPA calculate function and pass the SPA structure
//
    result = spa_calculate(&spa);

    if (result == 0)  //check for SPA errors
    {
        //display the results inside the SPA structure

		cout << fixed << setprecision(6); // show 6 digits of precision
//		cout << setprecision(6); // show 6 digits of precision
        cout << "Julian Day:    " << spa.jd << endl;
        cout << "L:             " << spa.l  << " degrees" << endl;
        cout << "B:             " << spa.b  << " degress" << endl;
        cout << "R:             " << spa.r  << " AU" << endl;
        cout << "H:             " << spa.h  << " degrees" << endl;
        cout << "Delta Psi:     " << spa.del_psi << " degrees" << endl;
        cout << "Delta Epsilon: " << spa.del_epsilon << " degress" << endl;
        cout << "Epsilon:       " << spa.epsilon <<  " degrees" << endl;
        cout << "Zenith:        " << spa.zenith  << " degrees"  << endl;
        cout << "Azimuth:       " << spa.azimuth << " degrees" << endl;
        cout << "Incidence:     " << spa.incidence << " degrees" << endl;
//
        min = 60.0 * (spa.sunrise - (int)(spa.sunrise));
        sec = 60.0 * (min - (int)min);
        cout << "Sunrise:       " << setfill('0') << setw(2) <<  (int)(spa.sunrise) << ":" << setw(2) << (int)min << ":" << setw(2) << (int)sec << " Local Time" << endl;
//
        min = 60.0*(spa.sunset - (int)(spa.sunset));
        sec = 60.0*(min - (int)min);
        cout << "Sunset:        " <<  (int)(spa.sunset) << ":" << (int)min 
		<< ":" << (int)sec << " Local Time" << endl;
		cout << "********** El Alto neighborhood Sun Position  ***************" << endl;	
		cout <<  "Date:          " <<  setfill('0') << setw(2) << spa.day << "-" <<
		setw(2) << months[spa.month] << "-" <<  setw(2) <<  spa.year << endl;
		cout << "Current Time:  " <<  spa.hour << "h " << spa.minute <<"m " 
		<< (int)spa.second << "s" << endl;
		cout << "Elevation avg: " << spa.elevation << endl;
		cout << "Latitud:       " << spa.latitude << endl;
		cout << "Longitud:      " << spa.longitude << endl;
		cout << "Elevation:     " << 90.0 - spa.zenith << " degrees" << endl;
        cout << "Azimuth:       " << spa.azimuth << " degrees" << endl;
		cout << "*************************************************" << endl;	
    } 
	else 
	{
		cout << "SPA Error Code:" << result << endl;
 	}
    return 0;
}

/////////////////////////////////////////////
// The output of this program should be:
//
//Julian Day:    2452930.312847
//L:             2.401826e+01 degrees
//B:             -1.011219e-04 degrees
//R:             0.996542 AU
//H:             11.105902 degrees
//Delta Psi:     -3.998404e-03 degrees
//Delta Epsilon: 1.666568e-03 degrees
//Epsilon:       23.440465 degrees
//Zenith:        50.111622 degrees
//Azimuth:       194.340241 degrees
//Incidence:     25.187000 degrees
//Sunrise:       06:12:43 Local Time
//Sunset:        17:20:19 Local Time
//
/////////////////////////////////////////////

