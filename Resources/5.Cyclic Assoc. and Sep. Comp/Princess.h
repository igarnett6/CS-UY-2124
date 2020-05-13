#ifndef PRINCESS_H
#define PRINCESS_H

#include <iostream>
#include <string>

namespace Fantasy {

    class FrogPrince;

    class Princess {
        friend std::ostream& operator<<(std::ostream& os, 
                                        const Princess& rhs);
    public:
        Princess(const std::string& name);
        void marries(FrogPrince& betrothed);
    private:
        std::string name;
        FrogPrince* spouse;
    };

}
#endif
