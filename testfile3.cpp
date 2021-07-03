#include<iostream>
#include <string> 
#include <vector>
#include <map>
#include "main.cpp"

using namespace std;

int main(){
    //======================="Test 1: EDGECASE : Output should be empty since current time not in scheduled "=======================
    DataMapGroup d;
    DataMap a;
    cout<<"DataMapGroup = {{22:10,(uint8_t)01110100}, {01:10,(uint8_t)01010110}, {10:10,(uint8_t)01000100}, {12:10,(uint8_t)01010100}}"<<endl<<"Current Map = {11:10,(uint8_t)64}"<<endl;
    cout<<"Output should be an empty since the current_time[local_time] doesnt exist in scheduled vector" << endl;
    a["local_time"]="22:10";
    a["dow"]="01110100";
    d.push_back(FillScheduleData("22:10",(uint8_t)01110100));
    d.push_back(FillScheduleData("01:10",(uint8_t)01010110));
    d.push_back(FillScheduleData("10:10",(uint8_t)01000100));
    d.push_back(FillScheduleData("12:10",(uint8_t)01010100)); 
    DataMap current_time;
    DataMap output;
    current_time["local_time"] = "11:10";
    current_time["dow"] = "64";
    output = GetNextScheduledMaintenanceTime(current_time,d);
    cout<<output["dow"];
    return 0;
}