/*
 * DataLogger.h
 * Logs data to SD card or serial in CSV format
 */

#include <SPI.h> //SD
#include <SD.h> //SD-> ~5250 bytes Storage and ~800 bytes global variables

enum schema = {};

class DataLogger
{
    public:
        char begin(int baud_rate, String[] columns =
                {   "Timestamp", "Latitude", "Longitude", "Altitude", "Ascent Rate", "Ground Speed"});
        void log(String dataString);
}
