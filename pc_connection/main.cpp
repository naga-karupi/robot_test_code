#include<libserial/SerialStream.h>
#include<libserial/SerialPortConstants.h>

#include<matplotlib-cpp/matplotlibcpp.h>

#include<stdbool.h>
#include<stdint.h>

#include<string>
#include<vector>
#include<iostream>

bool set_uart(LibSerial::SerialStream&);

int main(){
    char next;
    std::vector<char> x(100), y(100);


    LibSerial::SerialStream serial_test("/dev/ttyACM1");
    bool is_succes_set_config = set_uart(serial_test);

    if(!is_succes_set_config){
        std::cout<<"\nfinish to connect";
        serial_test.Close();

        return 0;
    }

    for(int i = 0; i < 100; i++){
        x.at(i) = i;
        serial_test.get(next);
        y.at(i) = next;
    }

    matplotlibcpp::plot(x, y);

    matplotlibcpp::show();

    return 0;
}

bool set_uart(LibSerial::SerialStream &serial_test){
    using namespace std;
    using namespace LibSerial;

    
    if(!serial_test.good()){
        std::cout << "could not open serial port";
        return false;
    }

    serial_test.SetBaudRate(BaudRate::BAUD_115200);
    if(!serial_test.good()){
        std::cout << "could not set baud rate";
        return false;
    }

    serial_test.SetCharacterSize(CharacterSize::CHAR_SIZE_8);
    if(!serial_test.good()){
        std::cout << "could not set character size";
        return false;
    }

    serial_test.SetFlowControl(FlowControl::FLOW_CONTROL_NONE);
    if(!serial_test.good()){
        std::cout << "could not set flow control";
        return false;
    }

    serial_test.SetParity(Parity::PARITY_NONE);
    if(!serial_test.good()){
        std::cout << "could not set parity bits";
        return false;
    }

    serial_test.SetStopBits(StopBits::STOP_BITS_1);
    if(!serial_test.good()){
        std::cout << "could not set stop bits";
        return false;
    }

    return true;
}