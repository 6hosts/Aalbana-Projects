#include <iostream>
using namespace std;

class CallingCharge 
{
private:
    double startingTime;
    double callMin;
    int calcMin;
    bool crossPeriod;
    double totalCharge;

public:
    
    CallingCharge() : 
    startingTime(0.0),
    callMin(0.0),
    calcMin(0),
    crossPeriod(false),
    totalCharge(0.0) {}

    
    void userInput() 
    {
        cout << "Enter starting time (hh.mm): ";
        cin >> startingTime;
        cout << "Enter calling minutes: ";
        cin >> callMin;
    }

    
    void convertToMinutes() {
        int hours = int(startingTime);
        int minutes = (startingTime - hours) * 100;
        calcMin = hours * 60 + int (minutes);
    }

    
    void checkCrossingP() 
    {
        int endMin = calcMin + callMin;
        if ((endMin / 60) != (calcMin / 60)) 
        {
            crossPeriod = true;
        }
    }

   
    void Calculate() {
        double rate = 0.0;
        if (crossPeriod) 
        {
            if (calcMin % (60 * 24) >= 0 && calcMin % (60 * 24) < 420) 
            {
                rate += (420 - (calcMin % (60 * 24))) * 0.12; 
                rate += 780 * 0.55; 
                rate += (callMin - (420 - (calcMin % (60 * 24)))) * 0.35;
            }
            else if (calcMin % (60 * 24) >= 420 && calcMin % (60 * 24) < 1140) 
            {
                rate += (1140 - (calcMin % (60 * 24))) * 0.55; 
                rate += (callMin - (1140 - (calcMin % (60 * 24)))) * 0.35;
            }
            else 
            {
                rate += (callMin * 0.35); 
            }
        }
        else {
            if (calcMin >= 0 && calcMin < 420) 
            {
                rate += callMin * 0.12; 
            }
            else if (calcMin >= 420 && calcMin < 1140) 
            {
                rate += callMin * 0.55; 
            }
            else 
            {
                rate += callMin * 0.35; 
            }
        }
        totalCharge = rate;
    }

   
    void displayCharges() 
    {
        cout << "Total charge for the call: $" << totalCharge << endl;
    }
};

int main() {
    CallingCharge call;
    call.userInput();
    call.convertToMinutes();
    call.checkCrossingP();
    call.Calculate();
    call.displayCharges();

    return 0;
}
