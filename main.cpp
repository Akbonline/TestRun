
#include<iostream>
#include <string> 
#include <vector>
#include <map>
#include <bitset>

using namespace std;

typedef map<const char *, string> DataMap;
typedef vector<DataMap> DataMapGroup;

string IntToString(int8_t x){       // Integer to String
    return to_string(x);
}
int StringToInt(string x){          // String to Integer
    return stoi(x);
}

DataMap FillScheduleData(string time, int days_of_week)
{
    DataMap schedule_data;
    schedule_data["local_time"] = time;
    schedule_data["dow"] = IntToString(days_of_week);
    return schedule_data;
}
string findNext_helper(string num, string mask){        // Helper Function takes in the two strings and Finds the next schedule time.
    // cout<<num<<" "<<mask<<endl;
    num = bitset<8>(stoi(num)).to_string();
    mask = bitset<8>(stoi(mask)).to_string();
    // cout<<num<<" "<<mask<<endl;

    int pos = mask.find('1');
    if(num[pos]!='1'){      // Edge case check for a case like: num = 01010011 and mask = 00100000  (Mismatch of the set bit)
        return "Error";
    }

    string output="";       // Returns empty string if time not found in the scheduler.

    int flag = 1;

    for(int i = 0;i<8;i++){
        if(i<=pos){
            output = output+'0';
        }
        else{
            if(flag && num[i]=='1'){
                output = output+'1';
                flag = 0;
            }
            else{
                output = output+'0';
            }
        }
    }
    output = to_string(stoi(output, 0, 2));
    return output;
}
DataMap GetNextScheduledMaintenanceTime(DataMap current_time, DataMapGroup user_schedules){
    DataMap output;
    for (auto x : user_schedules) {
        if(x["local_time"]==current_time["local_time"]){
            output["local_time"]=current_time["local_time"];
            output["dow"]=findNext_helper(x["dow"],current_time["dow"]);

            break;
        }
    }  
    return output;
}