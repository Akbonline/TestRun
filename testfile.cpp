#include<iostream>
#include <string> 
#include <vector>
#include <map>
#include "main.cpp"

using namespace std;

int main(){
    //======================="Test 1: EDGECASE: Output: Error since the current time and scheduled bits don't match up"=======================
    DataMapGroup d;
    DataMap a;
    cout<<"DataMapGroup = {{22:10,(uint8_t)01110100}, {01:10,(uint8_t)01010110}, {10:10,(uint8_t)01000100}, {12:10,(uint8_t)01010100}}"<<endl<<"Current Map = {01:10,(uint8_t)0}"<<endl;
    cout<<"Output should be an error since the current_time[dows] bits dont match the sceduled entry" << endl;
    a["local_time"]="22:10";
    a["dow"]="01110100";
    d.push_back(FillScheduleData("22:10",(uint8_t)01110100));
    d.push_back(FillScheduleData("01:10",(uint8_t)01010110));
    d.push_back(FillScheduleData("10:10",(uint8_t)01000100));
    d.push_back(FillScheduleData("12:10",(uint8_t)01010100)); 
    DataMap current_time;
    DataMap output;
    current_time["local_time"] = "01:10";
    current_time["dow"] = "0";
    output = GetNextScheduledMaintenanceTime(current_time,d);
    cout<<output["dow"];
    return 0;
}
