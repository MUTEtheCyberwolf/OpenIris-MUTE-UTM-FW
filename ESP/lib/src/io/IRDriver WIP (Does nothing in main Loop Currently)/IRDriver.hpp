#include <vector>
#include <Arduino.h>
#include <data/StateManager/StateManager.hpp>
#include <unordered_map>

class IRDriver

{
public:
    int initialize();
    void brihtness_adj();
    void toggleIRState();
    int matchedValue();
private:


};

