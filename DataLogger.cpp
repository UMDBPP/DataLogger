/*
 * DataLogger.cpp
 * Logs data to SD card or serial in CSV format
 */

/**
 * initialize data logging (SD card) and set up CSV structure
 * TODO: make this actually do that
 */
char DataLogger::begin(int baud_rate, String[] columns =
        {   "Timestamp", "Latitude", "Longitude", "Altitude", "Ascent Rate", "Ground Speed"})
{
    // add columns to schema enumeration
    schema = columns;

    Serial.begin(baud_rate);

    //Begin logging data to SD Card
    Serial.print("Initializing SD card...");

    if (!SD.begin(CHIP_SELECT))
    {    // see if the card is present and can be initialized:
        Serial.println("Card failed, or not present");
        // don't do anything more:
        return 1;
    }
    Serial.println("card initialized.");

    //Write "Starting" on the SD card
    File dataFile = SD.open("datalog.txt", FILE_WRITE);
    if (dataFile)
    {    // if the file is available, write to it:
        dataFile.println("Starting:");
        dataFile.println(HEADER_STRING);
        Serial.println("Starting:");
        Serial.println(HEADER_STRING);
        dataFile.close();
    }
    else
    {    // if the file isn't open, pop up an error:
        Serial.println("error opening datalog.txt");
        return 1;
    }

    return 0;
}

/**
 * Write data to the specified timestamp (row) and data series (column) of the CSV
 * TODO: make this actually do that
 */
void DataLogger::log(int timestamp, schema data_series, String dataString)
{
    // open the file. note that only one file can be open at a time
    File dataFile = SD.open("datalog.txt", FILE_WRITE);

    // if the file is available, write to it:
    if (dataFile)
    {
        dataFile.println(dataString);
        dataFile.close();
        // print to the serial port too:
        Serial.println(dataString);
    }
    else
    {    // if the file isn't open, pop up an error:
        Serial.println("error opening datalog.txt");
    }
}
