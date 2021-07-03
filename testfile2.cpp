#include<iostream>
#include <string> 
#include <vector>
#include <map>
#include "main.cpp"

using namespace std;

int main(){
    //======================="Test 2: Output runs well: 00001000"=======================
    DataMapGroup d;
    DataMap a;
    cout<<"DataMapGroup = {{22:10,(uint8_t)01110100}, {01:10,(uint8_t)01010110}, {10:10,(uint8_t)01000100}, {12:10,(uint8_t)01010100}}"<<endl<<"Current Map = {01:10,(uint8_t)64}"<<endl;
    cout<<"Output should be 8 which is 000001000(The next in the line)" << endl;
    a["local_time"]="22:10";
    a["dow"]="01110100";
    d.push_back(FillScheduleData("22:10",(uint8_t)01110100));
    d.push_back(FillScheduleData("01:10",(uint8_t)01010110));
    d.push_back(FillScheduleData("10:10",(uint8_t)01000100));
    d.push_back(FillScheduleData("12:10",(uint8_t)01010100)); 
    DataMap current_time;
    DataMap output;
    current_time["local_time"] = "01:10";
    current_time["dow"] = "64";
    output = GetNextScheduledMaintenanceTime(current_time,d);
    cout<<output["dow"];
    return 0;
}