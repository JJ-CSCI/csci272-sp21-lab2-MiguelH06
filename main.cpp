//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Use this enum class for indicating the lat/long direction
enum class Compass {N, S, W, E};

// Write your code here
class GPS {
  private:
  double latitude;
  Compass latitudeDirection;
  double longitude;
  Compass longitudeDirection;

  public:
  GPS();
  GPS(double, double);
  GPS(double, Compass, double, Compass);
  double getLatitude();
  Compass getLatitudeDirection();
  double getLongitude();
  Compass getLongitudeDirection();
};

GPS::GPS()
{
  latitude = 0.0;
  longitude = 0.0;
  longitudeDirection = Compass::W;
  latitudeDirection = Compass::N;
}

GPS::GPS(double m, double n)
{
  if((m >= 0.0) && (m <= 90.0))
  {
    latitude = m;
    latitudeDirection = Compass::N;
  }
  else
  latitude = 0.0;
  latitudeDirection = Compass::N;

  if((n >= 0.0) && (n <= 180.0))
  {
    longitude = n;
    longitudeDirection = Compass::W;
  }
  else
  longitude = 0.0;
  longitudeDirection = Compass::W;
}

GPS::GPS(double lat, Compass latDir, double longid, Compass longidDir)
{
  latitude = lat;
  longitude = longid;
  latitudeDirection = latDir;
  longitudeDirection = longidDir;

  if(lat >= 0.0 && lat <= 90.0)
    lat = latitude;
  else
    latitude = 0.0;
  
  if(latDir == Compass::N || latDir == Compass::S)
    latitudeDirection = latDir;
  else
    latitudeDirection = Compass::N;

  if(longid >= 0.0 && longid <= 180.0)
    longitude = longid;
  else
    longitude = 0.0;
  
  if(longidDir == Compass::W || longidDir == Compass::E)
    longidDir = longitudeDirection;
  else
  longitudeDirection = Compass::W;
}


double GPS::getLatitude()
{
  return latitude;
}

Compass GPS::getLatitudeDirection()
{
  return latitudeDirection;
}

double GPS::getLongitude()
{
  return longitude;
}

Compass GPS::getLongitudeDirection()
{
  return longitudeDirection;
}
//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------

TEST_CASE( "GPS" ) {
    SECTION( "t1" ) {
        GPS c;
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t2" ) {
        GPS c{12.12, 50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t3" ) {
        GPS c{12.12, Compass::S, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::S );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t4" ) {
        GPS c{122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t5" ) {
        GPS c{122.12, 500.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t6" ) {
        GPS c{-122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t7" ) {
        GPS c{12.12, -50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t8" ) {
        GPS c{12.12, Compass::W, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t9" ) {
        GPS c{12.12, Compass::N, 50.34, Compass::N};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t10" ) {
        GPS c{-12.12, Compass::E, 540.34, Compass::N};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
}
//------------------------------
