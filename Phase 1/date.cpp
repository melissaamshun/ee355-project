
#include "date.h"

Date::Date(string inp){
    numericDate = inp;
    char* monthNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char* months[12] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};
    
    string temp = inp; //MM/DD/YYYY 
    int delIndex = temp.find('/');
    string month = temp.substr(0, delIndex+1);
    string monthName;
    if(month.length == 1){month = "0" + month}; //fix 1 or 01 issue
    for(int =  = 0; i < 12; i++){
        if(month == months[i]){
            monthName = monthNames[i];
            break;
        }
    }

    temp = temp.substr(selIndex+1); //DD/YYYY
    delIndex = temp.find('/');
    string day =  temp.substr(0, delIndex+1)
    if(day.length == 1){day = "0" + day};

    temp = temp.substr(selIndex+1); //YYYY
    string year = temp;

    date = monthName + " " + day + ", " + year;

}

Date::get_date(string style){
    if(style == "Month D, YYYY"){
        return date;
    }
    else{
        return numericDate;
    }
}

Date::print_date(string style){
    cout << get_date(style) << endl;
}